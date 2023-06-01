#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define SIZE 100
struct stack
{
    int data[SIZE],top;
};
void push (struct stack * sptr,char color);
char pop (struct stack * sptr);
int main()
{
    int count,random_num,i;
    int money;
    char p,obt,confirm[5],opt,oc[3];
    int y=0,j=0;
    struct stack * sptr1,* sptr2,* sptr3;
    struct stack s1,s2,s3;
    sptr1 = &s1;
    sptr2 = &s2;
    sptr3 = &s3;
    sptr1->top = -1;
    sptr2->top = -1;
    sptr3->top = -1;
    while(1)
    {
    srand(time(0));
    i=3;
    y=0;
    printf("Press P key to play or E to exit the game\n");
    scanf(" %c",&opt);
    switch(opt)
    {
    case 'P':
        while(i!=0)
        {
        random_num = rand()%3+1;
        printf("Random number gen = %d\n",random_num);
        if(random_num == 1)
        {
        push(sptr1,'R');
        obt = pop(sptr1);
        i--;
        }
        else if(random_num == 2)
        {
           push(sptr2,'G');
           obt = pop(sptr2);
           i--;
        }
        else
        {
            push(sptr3,'Y');
            obt = pop(sptr3);
            i--;
        }
        printf("Outcomes : %c\n",obt);
        oc[y] = obt;
        y++;
        }
        if(oc[0] == oc[1] && oc[1] == oc[2] && oc[2] == oc[0])
        {
            printf("Jackpot\n");
        }
        break;
    case 'E':
        printf("Are you sure you want to quit the game?\nYes or No\n");
        scanf("%s",&confirm);
        if(strcmp(confirm,"Yes")==0)
        {
            printf("Game Over\n");
            exit(0);
        }
        break;
    }

    }
}
void push(struct stack * sptr,char color)
{
    if(sptr->top == SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top] = color;
    }
}
char pop (struct stack * sptr)
{
    char c;
    if(sptr->top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        c = sptr->data[sptr->top];
        sptr->top--;
        return c;
    }
}
