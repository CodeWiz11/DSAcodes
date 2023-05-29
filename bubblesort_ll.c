#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct node
{
    int data;
    struct node * link;
};
typedef struct node * NODE;
NODE temp,newnode;
NODE head=NULL;
NODE create_node(NODE newnode,int y);
NODE insert_end(NODE newnode,int t);
NODE insert_beg(NODE newnode);
NODE count(NODE head);
NODE front;
NODE back;
NODE sort(NODE head,int x);
void display(NODE head);
int main()
{

   int ch,c=0,t,read_num;
   int num,upper,lower,n;
   FILE * fptr;
   fptr = fopen("newevalfile.txt","w");
   if(fptr == NULL)
   {
       printf("Cannot open file\n");
   }
   else
   {
       printf("File opened\n");
    printf("Enter the LOWER and UPPER value of the interval\n");
    scanf("%d %d",&lower,&upper);
    srand(time(0));
    printf("Random Numbers generated are:\n");
    for (int i =0 ;i < upper;i++)
    {
        t=rand()%upper+lower;
        fprintf(fptr,"%d",t);
        printf("Pushed : %d in the file\n",t);
        read_num = getw(fptr);
        //printf("%d\n",read_num);
    head = insert_end(newnode,t);

    }
    printf("\n");
    display(head);
    long long start = clock();
    c = count(head);
    head = sort(head,c);
    long long stop = clock();
    printf("Sorted LL\n");
    display(head);
    fclose(fptr);
    printf("File closed\n");
    long long ticks = stop - start;
    double ellapsed_time = (double)ticks/CLOCKS_PER_SEC;
    printf("Ticks taken for execution : %d\n",ticks);
    printf("Time take for  %d numbers execution : %lf\n",upper,ellapsed_time);
   }

}
NODE getnode()
{
    newnode = (NODE)malloc(sizeof(struct node *));
    if(newnode==NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    return newnode;
}
NODE create_node(NODE newnode,int y)
{
    newnode = (NODE)malloc(sizeof(struct node *));
    if(newnode==NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }

    newnode->data = y;
    newnode->link=NULL;
    return newnode;
}
NODE insert_end(NODE newnode,int t)
{
    newnode=getnode();
    newnode=create_node(newnode,t);
    if(head==NULL)
    {
        return newnode;
    }
    else
    {
        temp=head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=newnode;
        return head;
    }
}

NODE count(NODE head)
{
    int count=0;
    if(head==NULL)
    {
        printf("No nodes present\n");
        printf("Node count = 0\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->link;
        }
        return count;
    }
}
void display(NODE head)
{
    if(head==NULL)
    {
        printf("SLL empty\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}
NODE sort(NODE head,int x)
{
    int i=1;
   for(i=1;i<=x;i++)
    {
        back=head;
        front=head->link;
        while(front!=NULL)
        {
            if(back->data>front->data)
            {

                temp=front->data;
                front->data = back->data;
                back->data = temp;
            }
            back=back->link;
            front=front->link;
        }
    }
    return head;
}
