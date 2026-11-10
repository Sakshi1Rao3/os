#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void signalhandler(int sig){
    if(sig==SIGINT){
        printf("Caught an interrupt signal");
    }
    if(sig==SIGTERM){
        printf("Caught an terminate signal");
        exit(0);
    }
    if(sig==SIGHUP){
        printf("Caught an HANGUP signal");
    }
    if(sig==SIGALRM){
        printf("Caught an alarm signal");
    }
    if(sig==SIGUSR1){
        printf("Caught an user signal");
    }

}
int main(){
    signal(SIGINT,signalhandler);
    signal(SIGTERM,signalhandler);
    signal(SIGHUP,signalhandler);
    signal(SIGALRM,signalhandler);
    signal(SIGUSR1,signalhandler);
    alarm(20);
    printf("Process started with id %d",getpid());
    while(1){
        printf("Waiting for signal");
        sleep(5);
    }
    return 0;
}