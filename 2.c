#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    char fname[100];
    int fd,fsize;
    char buffer[100];

    printf("Enter file name");
    scanf("%s",fname);
    fd=open(fname,O_RDONLY);
    if(fd==-1){
        printf("Error");
        return 0;
    }
    else{
        fsize=read(fd,buffer,sizeof(buffer)-1);
        if(fsize==-1){
            printf("Error");
            close(fd);

        }
        else{
            buffer[fsize]='\0';
            printf("Contents of file: %s",buffer);
            close(fd);
        }
    }
    return 0;
}