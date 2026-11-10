#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    char sname[100];
    printf("Enter filename:");
    scanf("%99s",sname);
    if(access(sname,R_OK)==-1){
        perror("Cant open file");
        return 1;
    }
    if(execl("/bin/sh","sh",sname,(char*)NULL)==-1)
        perror("Cant open file");
    return 0;
}