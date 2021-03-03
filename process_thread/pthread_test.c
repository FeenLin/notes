#include <stdio.h>
#include <pthread.h>

void *busy(void *ptr) {
// ptr will point to "Hi"
    puts("Hello World");
    return NULL;     // pthread_exit(NULL);
}
int main() {
    void *result;
    pthread_t id;
    pthread_create(&id, NULL, busy, "Hi");  // int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                                            //                      void *(*start_routine) (void *), void *arg);
   
    pthread_join(id, &result);              // int pthread_join(pthread_t thread, void **retval);
}

/*
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);

    參數1. pthread_t *tid為pthread的指標，在使用Thread之前必須要先宣告一個pthread_t的變數。
    參數2. const pthread_attr_t *attr為該Thread的屬性，預設是NULL，如果沒有其他特殊的需求直接填入NULL即可。
    參數3. void *(*start_routine)(void *)為Function pointer，這邊要放入你要執行的Function。
    參數4. void *argument為Function pointer所要帶的參數。
    回傳值: 如果執行成功則回傳0，如果執行失敗則回傳錯誤代碼。

void pthread_exit (void *value_ptr)

此Function的作用是用來關閉一個Thread，附帶有1個參數。
    參數1: void *value_ptr用來設定執行成功時該Thread會回傳的值，這個值可由pthread_join()這個Function來取得。
    回傳值: 不會回傳任何值。

int pthread_cancel (pthread_t thread)

這個Function的作用是用來關閉一個指定的Thread，附帶有一個參數。
    參數1: pthread_t thread為要關閉的Thread。
    回傳值: 如果執行成功則回傳0，如果執行失敗則回傳錯誤代碼。

int pthread_join (pthread_t thread, void **value_ptr)

這個Function的作用會暫停目前執行pthread_join的Thread，等到目標Thread執行完畢之後目前執行pthread_join的Thread才會繼續執行，附帶有2個參數。
    參數1: pthread_t thread為要等待的目標Thread。
    參數2: void \*\*value_ptr用來取得目標Thread的回傳值。
    回傳值: 如果執行成功則回傳0，如果執行失敗則回傳錯誤代碼。

int pthread_kill (pthread_t thread , int sig)

這個Function的作用為傳送訊息給目標的Thread。
參數1: pthread_t thread為訊息要傳送到的目的地Thread。
參數2: int sig為要傳送的訊息。(當sig為0時為保留訊號，用來測試目標Thread是否還存活)
回傳值: 如果執行成功則回傳0，如果執行失敗則回傳錯誤代碼。(如果pthread_kill執行失敗則不會傳送任何的訊息(sig))該Thread不存在則回傳ESRCH，sig不合法則回傳EINVAL。
*/