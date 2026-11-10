
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int i,j,k,p,r,found,count=0;

    printf("Enter process:");
    scanf("%d",&p);

    printf("Enter resource:");
    scanf("%d",&r);

    int alloc[p][r],max[p][r],avail[r],need[p][r],safeseq[p],finish[p];

    printf("Enter alloc matrix\n");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter max matrix\n");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            scanf("%d",&max[i][j]);

    printf("Enter avail matrix\n");
    for(i=0;i<r;i++)
        scanf("%d",&avail[i]);

    printf("Need matrix:\n");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            need[i][j]=max[i][j]-alloc[i][j];

    for(i=0;i<p;i++){
        for(j=0;j<r;j++)
            printf("%d ",need[i][j]);
        printf("\n");
    }

    for(i=0;i<p;i++)
        finish[i]=0;

    while(count<p){
        found=0;

        for(i=0;i<p;i++){
            if(finish[i]==0){
                for(j=0;j<r;j++){
                    if(need[i][j]>avail[j])
                        break;
                }

                if(j==r){
                    for(k=0;k<i;k++)
                        avail[k]+=alloc[i][k];

                    safeseq[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }

        if(found==0)
            break;
    }

    if(count<p)
        printf("System in unsafe state");
    else{
        printf("System in safe state\n");
        for(k=0;k<p;k++)
            printf("System in safe sequence P%d\t",safeseq[k]+1);
    }

    return 0;
}
