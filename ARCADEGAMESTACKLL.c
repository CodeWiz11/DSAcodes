#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100

struct node //Structure defined

{

char data; //Character data

struct node *link; //Next pointer contains index of next node

};

typedef struct node * NODE;

NODE head;

NODE cur,prev;

NODE newnode;

NODE create_node(NODE newnode,char c);

NODE push(NODE newnode,char c);

char pop(NODE head);

int main()

{

int random;

int amount,money;

int y;

FILE *fptr;

fptr = fopen("Choice.txt","w");

fclose(fptr);

char option,res;

char r[3];

printf("Enter the amount you want to insert.\nNote: Each chance costs Rs.5\n");

scanf("%d",&money);

printf("Welcome to the game!\nPress P to play or E to exit\n");

while(1)

{

if(money <= 4)

{

printf("You have exhausted your chances\n");
if(money > 0)
{

printf("Please take your balance amount: %d",money);
}

exit(0);

}

srand(time(NULL));

scanf(" %c",&option);

fptr = fopen("Choice.txt","w");

fprintf(fptr,"%c",option);

fclose(fptr);

fptr = fopen("Choice.txt","w");

fscanf(fptr,"%c",&option);

fptr++;

fclose(fptr);

switch(option)

{

case 'P' :

y = 0;

for(int i = 3;i > 0;i --)

{

random = rand()%3+1;

if(random == 1)

{

head = push(newnode,'R');

res = pop(head);

}

else if(random == 2)

{

head = push(newnode,'Y');

res = pop(head);

}

else if(random == 3)

{

head = push(newnode,'G');

res = pop(head);

}

r[y] = res;

y++;

printf("Res = %c\n",res);

}

if(r[0] == r[1] && r[1] == r[2] && r[2]==r[1])

{

printf("Congratulations! You have won the game!");
if(money!=0)
{
    printf("\nPlease take your balance amount : %d\n",money);
}
exit(0);

}

money = money - 5;

if(money >= 5)

{

printf("Enter P to play again or E to exit\n");

}

break;

case 'E' :

printf("You have quit the game\n");

exit(0);

break;

}

}

}

NODE create_node(NODE newnode,char c)

{

newnode = (NODE)malloc(sizeof(struct node));

if(newnode == NULL)

{

printf("Memory allocation failed\n");

exit(0);

}

newnode->data = c;

newnode->link = NULL;

return newnode;

}

NODE push(NODE newnode,char c)

{

newnode = create_node(newnode,c);

if(head == NULL)

{

return newnode;

}

else

{

cur = head;

while(cur->link!=NULL)

{

cur = cur->link;

}

cur->link = newnode;

return head;

}

}

char pop(NODE head)

{

char val;

if(head == NULL)

{

printf("No nodes to pop\n");

}

else

{

prev = head;

cur = prev->link;

while(cur!=NULL)

{

prev = prev->link;

cur = cur->link;

}

val = prev->data;

prev->link = NULL;

free(cur);

return val;

}

}
