#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree * right;
    struct tree * left;
};
typedef struct tree * TREE;
TREE insert(TREE tree, int data);
TREE newNode(int n);
void inorder(TREE root);
TREE temp;
int main()
{
    int num,ch;
    TREE root = NULL;
    while(1)
    {
        printf("Enter a choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter a number\n");
            scanf("%d",&num);
            if(root == NULL)
        {
            root = insert(root,num);
        }
        else
        {
            insert(root,num);
        }
        break;
        case 2:
            inorder(root);
            break;
        case 3: exit(0);
        break;
    }
    }
}
TREE newNode(int n)
{
    temp = (TREE)malloc(sizeof(struct tree));
    temp->data = n;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(TREE root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}
TREE insert(TREE tree,int data)
{
    if(tree == NULL)
    {
        return newNode(data);
    }
  if(data < tree->data)
  {
      tree->left = insert(tree->left,data);
  }
  else if(data > tree->data)
  {
      tree->right = insert(tree->right,data);
  }
  return tree;

}
