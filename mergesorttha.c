#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct node
{
    int data;
    struct node * link;
};
typedef struct node * NODE; //Alias naming
NODE newnode;
NODE slow,fast;
NODE head=NULL,temp;
NODE insert_end(NODE newnode,int t);
NODE insert_beg(NODE newnode);
void display(NODE head);
NODE mergesort(NODE head); //Merge sort
NODE merge(NODE left,NODE right); //Merge
NODE tAh(NODE head); //function to cut the linked list into 2 parts and and get the middle index
int main()
{
     int ch;
     int upper,lower,t;
     printf("Enter LOWER and UPPER limits\n");
     scanf("%d %d",&lower,&upper);
     srand(time(0));
     for(int i=0;i<upper;i++)
     {
        t = rand()%upper+lower;
        printf("Random num gen = %d\n",t);
        head = insert_end(newnode,t);
     }
     long start = clock();
     display(head);
     printf("Sorted LL:\n");
     head = mergesort(head);
     long stop = clock();
     long ticks = stop - start;
     double time_ell = (double)ticks/CLOCKS_PER_SEC;
     printf("Number of ticks = %ld\n",ticks);
     printf("Time taken for sorting = %lf\n",time_ell);
     display(head);
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
NODE read(NODE newnode,int y)
{
    newnode->data = y;
    newnode->link=NULL;
    return newnode;
}

NODE insert_end(NODE newnode,int t)
{
    newnode=getnode();
    newnode=read(newnode,t);
    if(head == NULL)
    {
        return newnode;
    }
    else
    {
        temp = head;
        while(temp->link!=NULL)
        {
            temp = temp->link;
        }
        temp->link=newnode;
        return head;
    }
}
/*NODE insert_beg(NODE newnode)
{
    newnode=getnode();
    newnode=read(newnode);
    if(newnode==NULL)
    {
        return newnode;
    }
    else
    {
        newnode->link=head;
        head=newnode;
        return head;
    }
}*/
void display(NODE head)
{
    if(head==NULL)
    {
        printf("No SLL present\n");
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
NODE mergesort(NODE head)
{
    if(head->link == NULL)
    {
        return head;
    }
    else
    {
        NODE mid = tAh(head);
        NODE right_start = mid->link;
        mid->link = NULL;

         NODE left = mergesort(head);
         NODE right = mergesort(right_start);

         NODE new_head = merge(left,right);

         return new_head;
    }
}
NODE tAh(NODE head)
{
    NODE slow = head;
    NODE fast = head->link;
    while(fast!=NULL && fast->link!=NULL)
    {
        slow = slow->link;
        fast = (fast->link)->link;
    }
    return slow;
}
NODE merge(NODE left,NODE right)
{
    NODE aux_head = getnode();
    NODE current = aux_head;

    while(left!=NULL && right!=NULL)
    {
        if(left->data<=right->data)
        {
            current->link = left;
            left = left->link;
            current = current -> link;
        }
        else if(right->data < left->data)
        {
            current->link = right;
            right = right->link;
            current = current->link;
        }
    }
    while(left!= NULL)
    {
        current->link = left;
        left = left->link;
        current = current->link;
    }
    while(right!=NULL)
    {
        current->link = right;
        right = right->link;
        current = current->link;
    }
    return aux_head->link;
}
