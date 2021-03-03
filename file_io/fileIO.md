Linux 檔案I/O    unbuffered I/O  低階磁碟I/O      使用 File Descriptor (檔案描述器、簡稱 fd)

#include <sys/types.h>      #include <sys/stat.h>       #include <fcntl.h>

# int open(const char *name, int flags);  /  int open(const char *name, int flags, mode_t mode);
成功回傳: 正整數fd  失敗回傳: -1

必要旗標:
O_RDONLY: 以唯讀模式開啟    O_WRONLY: 以唯寫模式開啟    O_RDWR: 以讀寫模式開啟

行為操作旗標:
O_APPEND: 以附加模式開啟                            O_CLOEXEC: 在執行 execl 後自動關閉該fd      
O_NOATIME: 進行讀取操作時不更新檔案的存取時間          O_TRUNC: 若開啟的檔案存在且是一般檔案，開啟後就將其截短成長度為 0

同步、非同步旗標:
O_SYNC: 以 SYNC 模式開啟檔案 (之後會再補充同步 IO)
O_ASYNC: 如果指定的檔案變成可讀或可寫的狀態，就產生一個 Signal (預設為 SIGIO)
O_NONBLOCK: 以 non-blocking IO 模式開啟
O_DIRECT: 以 Direct IO 模式開啟檔案

建檔相關旗標:
O_CREAT: 如果指定的檔案不存在，就建立一個
O_EXCL: 有指定 O_CREAT 時才有效。如果開檔時檔案已經存在，就回傳失敗，可以避免兩個行程想同時建檔的競爭情況

新檔案的使用權限: 有 O_CREAT 旗標但卻沒有指定 mode 的話，行為會是不明確的
S_IRUSR: User 擁有 r 權限               S_IRGRP: Group 擁有 r 權限              S_IROTH: Other 擁有 r 權限
S_IWUSR: User 擁有 w 權限               S_IWGRP: Group 擁有 w 權限              S_IWOTH: Other 擁有 w 權限
S_IXUSR: User 擁有 x 權限               S_IXGRP: Group 擁有 x 權限              S_IXOTH: Other 擁有 x 權限
S_IRWXU: S_IRUSR | S_IWUSR | S_IXUSR    

# int creat(const char *name, mode_t mode);
等於 open(name, O_WRONLY | O_CREAT | O_TRUNC, mode)

# int close(int fd) 
　　應用程式使用完 fd 後，可以用 close() 系統呼叫將 fd 從檔案表中移出，核心主要的實作函式為 fs/file.c 內的 __close_fd()。另外，在 fd 回收完成後，核心也會呼叫檔案的 flush()。

# ssize_t read(int fd, void *buf, size_t len);
read() 系統呼叫會從 fd 所參照檔案的當前位置讀取 len 個位元組到 buf，執行成功時會回傳寫進 buf 的位元組數，同時檔案位置也會前進所讀取的位元組數，執行失敗時會回傳 -1 並設定 errno。

回傳值等於 len: 這是預期的正確結果
回傳值等於 0: 表示到了檔案末端 (EOF)，沒有資料可以讀取
回傳值小於 0: 一般代表發生錯誤，有以下幾種可能:
            errno = EINTR。表示在讀取過程中收到的信號，可以嘗試再讀取一次
            errno = EAGAIN。在 O_NONBLOCK 模式下才會有的情況，表示還沒有資料可以讀取，可以等候一段時間後再嘗試一次
            其他的 errno。可能是嚴重的錯誤，重試不一定有用
回傳值大於 0 但小於 len: 可能是以下三種情況之一，再嘗試讀取一次通常就可以找到真正原因:
            讀取過程中收到信號中斷
            讀取過程中發生錯誤
            可讀取的大小不足 len 或以到達 EOF

# ssize_t write(int fd, const void *buf, size_t count);
write() 系統呼叫會從 buf 中把 count 位元組的資料寫入 fd 所參照檔案的當前位置，執行成功時會回傳寫進入檔案的位元組數，檔案位置也會前進寫入的位元組數，執行失敗時會回傳 -1 並設定 errno

# off_t lseek(int fd, off_t pos, int origin);
SEEK_CUR: 位置設定為當前位置加上 pos
            pos 是零時可以用來查詢目前檔案位置
SEEK_END: 位置設定為當前的長度再加上 pos，也就是從結尾開始算的意思
            pos 是零時可以把當前位置設為檔案結尾
SEEK_SET: 位置設定為 pos，也就是從開頭開始算的意思
            pos 是零時可以把當前位置設為檔案開頭

