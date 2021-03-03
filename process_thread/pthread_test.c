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