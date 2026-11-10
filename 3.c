#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    int i,pid,ppid;
    for(i=1;i<=5;i++){
        fflush(stdout);
        pid=fork();
        if(pid<0){
            printf("Error");
            return 1;

        }
        else if(pid==0){
            printf("Child %d with pid %d and parent id %d",i,getpid(),getppid());
            exit(0);
        }
        else{
            printf("child %d created with id %d",i,pid);
        }
    }
    for(i=1;i<=5;i++){
        wait(NULL);
    }
    printf("Parent%d terminated",getpid());
    return 0;
}

