
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int main(){
    int buffersize, item=0, choice, in=0, out=0, produce, consume;

    printf("Enter the buffersize: ");
    scanf("%d",&buffersize);

    int buffer[buffersize];

    do{
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice){

        case 1:
            if(item==buffersize){
                printf("Buffer is full\n");
            }
            else{
                printf("Enter item to be produced: ");
                scanf("%d",&produce);

                buffer[in]=produce;
                in=(in+1)%buffersize;
                item++;
            }
            break;

        case 2:
            if(item==0){
                printf("Buffer is empty\n");
            }
            else{
                consume=buffer[out];
                printf("Consumed item is: %d\n",consume);

                out=(out+1)%buffersize;
                item--;
            }
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Wrong input\n");
        }

    }while(choice!=3);

    return 0;
}
