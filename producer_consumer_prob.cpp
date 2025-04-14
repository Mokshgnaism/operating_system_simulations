#include<iostream>
#include<unistd.h>
#include <pthread.h>
#include<thread>
#include<semaphore.h>
#include<stdlib.h>
using namespace std;
#define BUFFER_SIZE 10
int buffer[BUFFER_SIZE];
int in=0;
int out =0;
sem_t empty;
sem_t full;
sem_t mutex;

void *producer(void *arg){
    int item;
    for(int i=0;i<10;i++){
        item = rand()%100;
        sem_wait(&empty);
        sem_wait(&mutex);
        buff[in] = item;
        in = (in+1)%BUFFER_SIZE;
        sem_post(&full);
        sem_post(&mutex);
        sleep(1);
    }
    return NULL;
}
void *consumer(void *arg){
    for(int i=0;i<10;i++){
        sem_wait(&full);
        sem_wait(&mutex);
        cout<<buffer[out]<<endl;
        out = (out+1)%BUFFER_SIZE;
        sem_post(&empty);
        sem_post(&mutex);
        sleep(2);
    }
    return NULL;
}

int main(){
    pthread_t prod,cons;
    sem_init(&empty,0,BUFFER_SIZE);
    sem_init(&full,0,0);
    sem_init(&mutex,0,1);
    pthread_create(&prod,NULL,producer,NULL);
    pthread_create(&cons,NULL,consumer,NULL);
    pthread_join(prod,NULL);
    pthread_join(prod,NULL);
    t1.join();
    t2.join();
    sem_destroy(&empty);
    sem_destroy(&mutex);
    sem_destroy(&full);
    return 0;
}

