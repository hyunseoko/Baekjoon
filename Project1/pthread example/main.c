#define HAVE_STRUCT_TIMESPEC
#include <stdio.h>
//#include <io.h>
//#include <stdlib.h>
#include <pthread.h>

int count = 0;

void* thread1Func(void* arg){
    while (1) {
        if (count % 2 == 0) {
            count += 1;
        }
        else if (count == 9) {
            break;
        }
    }
}

void* thread2Func(void* arg) {
    while (1) {
        if (count % 2 != 0) {
            count += 1;
        }
        else if (count == 10) {
            break;
        }
    }
    return count;
}

int main(int argc, char** argv)
{
    pthread_t thread1;
    pthread_t thread2;
    void* retval1;
    void* retval2;
    
    pthread_create(&thread1, NULL, thread1Func, NULL);
    pthread_create(&thread2, NULL, thread2Func, NULL);
    
    pthread_join(thread1, &retval1);
    pthread_join(thread2, &retval2);

    printf("count: %d\n", (int*)retval2);
    return 0;
}