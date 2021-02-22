#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


void *thread1(void *vargp);

int main() {
    // Write C code here
    pthread_t tid;
    int num;
    printf("enter how many threads: ");
    scanf("%d",&num);
    for(int i=0; i<=num; i++){
    pthread_create(&tid,NULL,thread1,NULL);
    pthread_join(tid,NULL);

    }
    exit(0);
}

void *thread1(void *vargp){

    printf("Hello world! \n");
    return NULL;


}
