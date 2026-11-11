#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
struct Process{
    int pid, bt,wt,tat;
};
int main(){
    float awt,atat;
    int i,n;
    printf("Enter process no:");
    scanf("%d",&n);
    if(n<0){
        printf("process -ve");
        return 1;
    }
    struct Process P[n];
    
     for(i=0;i<n;i++){
        P[i].pid=i+1;
        printf("Enter burst time");
        scanf("%d",&P[i].bt);

    }   /* data */
    P[0].wt=0;
    P[0].tat=P[0].bt+P[0].wt;
    for(i=1;i<n;i++){
        P[i].wt=P[i-1].wt+P[i-1].bt;
        P[i].tat=P[i].wt+P[i].tat;
    }
    printf("Values");
    for(i=0;i<n;i++){
        printf("%d,%d,%d,%d",P[i].pid,P[i].bt,P[i].wt,P[i].tat);
    }
    for(i=0;i<n;i++){
        awt+=P[i].wt;
        atat+=P[i].tat;
    }
    printf("Total wt: %f",awt);
    printf("avg wt: %f",awt/n);
    printf("Tat:%f",atat);
    printf("ATAT:%f",atat/n);


    
    
    
}