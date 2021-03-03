CC=cc
INCLUDE_DIR:=   -I.
CFLAGS= $(INCLUDE_DIR) -Wall
SRCS=   $(wildcard *.c)
OBJS=   $(SRCS:.C=.o)
EXEF=   test
LIBS=   -lpthread
$(EXEF):$(OBJS)
        $(CC) $(CFLAGS) -lm -o $@ $^ $(LIBS)
clean:
        rm -f $(OBJS)
        rm $(EXEF)