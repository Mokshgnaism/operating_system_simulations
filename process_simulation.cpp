#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

int main(){
    pid_t pid;
    pid = fork();
    if(pid<0){
        cout<<"FORK FAILED"<<endl;
        perror("error");
    }
    else if(pid==0){
        cout<<"child process executing with pid "<<getpid()<<endl;
        cout<<"child process terminating"<<endl;
        exit(0);
    }
    else{
        cout<<"parent process started with pid"<<getpid()<<endl;
        wait(NULL);
        cout<<"parent process terminating "<<endl;
        exit(1);
    }
    return 0;
}
