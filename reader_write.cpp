#include <bits/stdc++.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<sys/wait.h>
#include<unistd.h>
using namespace std;
int rc = 0;
int n;
sem_t mutex;
sem_t db;
void*reader(void*arg){
    for(int i=0;i<10;i++){
        sem_wait(&mutex)
        rc = rc+1;
        if(rc ==1){
            sem_wait(&db);
        }
        sem_post(&mutex);

        cout<<"Reading n:"<<n<<endl;

        sem_wait(&mutex);
        rc--;
        if(rc==0){
            sem_post(&db);
        }
        sem_post(&mutex);
        sleep(1);
    }
    return NULL;
}
void *writer(void *arg){
    for(int i=0;i<10;i++){
        sem_wait(&db);
        n = n+1;
        sem_post(&db);
        sleep(2);
    }
    return NULL;
}


int32_t main() {
    // Your code here
    pthread_t read,write;
    sem_init(&mutex,0,1);
    sem_init(&db,0,1);
    pthread_create(&read,NULL,reader,NULL);
    pthread_create(&write,NULL,writer,NULL);
    pthread_join(&read,NULL);
    pthread_join(&write,NULL);
    sem_destroy(&mutex);
    sem_destroy(&db);
    return 0;
}