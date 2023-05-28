#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 50
struct queue
{
    int data[SIZE];
    int front,rear;
};
FILE * fptr;
FILE * fptr3;
int main()
{
    FILE * fptr1;
    FILE * fptr2;
    struct queue * qptr;
    struct queue q;
    qptr = &q;
    qptr->front = -1;
    qptr->rear = -1;
    fptr3 = fopen("Qallops.txt","w");
    fclose(fptr3);
    fptr = fopen("enQ.txt","w");
    fclose(fptr);
    fptr1 = fopen("randomnumgen.txt","w");
    fclose(fptr1);
    fptr2 = fopen("DeQ.txt","w");
    fclose(fptr2);
    int n,lower,upper,random,i,num,ch;
    srand(time(NULL));
    printf("Enter number of random numbers to be generated\n");
    scanf("%d",&n);
    printf("Enter the range in which the random numbers must be generated\n");
    scanf("%d %d",&lower,&upper);
    printf("Generated Random numbers : \n");
    for(int i = 0;i < n;i++)
    {
        fptr1 = fopen("randomnumgen.txt","a");
        random = rand()%upper+lower;
        fprintf(fptr1,"%d ",random);
        printf("%d ",random);
        fclose(fptr1);
    }
    fptr1 = fopen("randomnumgen.txt","r");
    fscanf(fptr1,"%d",&i);
    printf("\nRead file:\n");
    while(!feof(fptr1))
    {
        enqueue(qptr,i);
        fscanf(fptr1,"%d",&i);

    }
    fclose(fptr1);
    while(1)
    {
        printf("Enter a choice\nChoice 1: Deq\nChoice 2 : Display updated Q\n Choice 3:Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:num = dequeue(qptr);
        if(num!=-999)
        {
            printf("Dequeue : %d",num);
            fptr2 = fopen("DeQ.txt","a");
            fptr3 = fopen("Qallops.txt","a");
            fprintf(fptr2,"Dequeue : %d\n",num);
            fprintf(fptr3,"Dequeue : %d\n",num);
            fclose(fptr2);
            fclose(fptr3);
        }
        break;
        case 2:display(qptr);
        break;
        case 3:exit(0);
        break;
        default:printf("Enter a valid choice\n");
        break;
        }
    }
}
void enqueue(struct queue *qptr,int num)
{
    if(qptr->rear==SIZE-1)
    {
        printf("Q Overflow\n");
    }
    else
    {
        fptr = fopen("enQ.txt","a");
        fptr3 = fopen("Qallops.txt","a");
        qptr->rear++;
        printf("Enqueue : %d",num);
        fprintf(fptr,"Enqueue : %d\n",num);
        fprintf(fptr3,"Enqueue : %d\n",num);
        qptr->data[qptr->rear] = num;
        fclose(fptr);
        fclose(fptr3);
    }
}
int dequeue (struct queue * qptr)
{
    int num;
    if(qptr->rear == qptr->front)
    {
        return -999;
    }
    else
    {
        qptr->front++;
        num = qptr->data[qptr->front];
        return num;
    }
}
void display(struct queue *qptr)
{
    int i;
   if(qptr->front == qptr->rear)
   {
       printf("Queue is empty\n");
   }
   else
   {
       for(i=qptr->front+1;i<=(qptr->rear);i++)
       {
           printf("%d -> ",qptr->data[i]);
       }
   }
}
