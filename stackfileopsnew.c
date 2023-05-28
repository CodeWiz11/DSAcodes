//01FE21BEI036
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 150
struct stack
{
    int data[SIZE],top;
};
FILE * fptr1;
FILE * fptr3;
int main()
{
    int n,upper,lower,random,i,ch,popped;
    FILE * fptr;
    FILE * fptr2;
    struct stack * sptr;
    struct stack s;
    sptr = &s;
    sptr->top = -1;
    fptr = fopen("randomnumgen.txt","w");
    fclose(fptr);
    fptr3 = fopen("AllOpn.txt","w");
    fclose(fptr3);
    fptr2 = fopen("Stackpopped.txt","w");
    fclose(fptr2);
    fptr1 = fopen("StackPushed.txt","w");
    fclose(fptr1);
    srand(time(NULL));
    printf("Enter number of random numbers to be generated\n");
    scanf("%d",&n);
    printf("Enter the range in which random numbers are to be generated\n");
    scanf("%d %d",&lower,&upper);
    for (int i=0;i<n;i++)
    {
        fptr = fopen("randomnumgen.txt","a");
        random = rand()%upper+lower;
        fprintf(fptr,"%d ",random);
        printf("%d ",random);
         fclose(fptr);
    }
    fptr = fopen("randomnumgen.txt","r");
    printf("\nFILE READ : \n");
    //fscanf(fptr,"%d",&i);
    while(!feof(fptr))
    {
        fscanf(fptr,"%d",&i);
        push(sptr,i);
         printf("%d -> ",i);
    }
    fclose(fptr);
    display(sptr);
    while(1)
    {
        printf("\nEnter a choice whether to pop or to end the program\n");
        printf("Choice 1 : pop\nChoice 2 : Display Updated stack\nChoice 3 : Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : popped = pop(sptr);
            printf("Popped : %d\n",popped);
            if(popped != -999)
            {
                fptr2 = fopen("Stackpopped.txt","a");
                fprintf(fptr2,"Popped : %d\n",popped);
                fptr3 = fopen("AllOpn.txt","a");
                fprintf(fptr3,"Popped: %d\n",popped);
                fclose(fptr2);
                fclose(fptr3);
            }
            break;
            case 2:
                printf("Updated Stack\n");
                display(sptr);
            case 3 : exit(0);
            break;
            default : printf("Enter a valid choice\n");
            break;
        }
    }
}
void push(struct stack * sptr,int num)
{
    if(sptr->top == SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        fptr1 = fopen("StackPushed.txt","a");
        fprintf(fptr1,"Pushed : %d\n",num);
        fptr3 = fopen("AllOpn.txt","a");
        fprintf(fptr3,"Pushed : %d\n",num);
        sptr->top++;
        sptr->data[sptr->top] = num;
        fclose(fptr1);
        fclose(fptr3);
    }
}
int pop(struct stack * sptr)
{
    int number;
    if(sptr->top == -1)
    {
        printf("Stack Underflow");
        return -999;
    }
    else
    {
        number = sptr->data[sptr->top];
        sptr->top--;
        return number;
    }
}
void display(struct stack * sptr)
{
    int j;
    printf("\nStack : \n");
    for(j = sptr->top; j > -1; j--)
    {
        printf("%d -> ",sptr->data[j]);
    }
}
