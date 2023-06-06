#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct tree
{
    int data;
    struct tree * right;
    struct tree * left;
};
typedef struct tree * TREE;
FILE * fptr2;
FILE * fptr3;
FILE * fptr4;
TREE insert(TREE tree, int data);
TREE newNode(int n);
void inorder(TREE root);
void postorder(TREE root);
void preorder(TREE root);
TREE temp;
int main()
{
    int num,ch,random,upper,lower,read,n;
    TREE root = NULL;
    srand(time(NULL));
    FILE * fptr1;
    fptr1 = fopen("randomtext.txt","w");
    fclose(fptr1);
    printf("Enter number of random numbers needed\n");
    scanf("%d",&n);
    printf("Enter the range of random number\n");
    scanf("%d %d",&lower,&upper);
    fptr1 = fopen("randomtext.txt","a");
    for(int i=0;i<n;i++)
    {
        random = rand()%upper+lower;
        fprintf(fptr1,"%d ",random);
        printf("%d->",random);
    }
    fclose(fptr1);
    fptr1 = fopen("randomtext.txt","r");
    while(!feof(fptr1))
    {
        fscanf(fptr1,"%d",&read);
        if(root == NULL)
        {
            root = insert(root,read);
        }
        else
        {
            insert(root,read);
        }
    }
    fptr2 = fopen("inorder.txt","w");
    fptr3 = fopen("preorder.txt","w");
    fptr4 = fopen("postorder.txt","w");
    long start = clock();
    printf("\nInorder : \n");
          inorder(root);
     long stop = clock();
     long ticks = stop - start;
      double ellapsed_time = (double)ticks/CLOCKS_PER_SEC;
    printf("\Inorder ellapsed %lf\n",ellapsed_time);
     start = clock();
    printf("\nPreorder : \n");
          preorder(root);
    stop = clock();
    ticks = stop - start;
     ellapsed_time = (double)ticks/CLOCKS_PER_SEC;
    printf("\nPreorder ellapsed %lf\n",ellapsed_time);
     start = clock();
    printf("\nPostorder : \n");
    postorder(root);
    stop = clock();
    ticks = stop - start;
     ellapsed_time = (double)ticks/CLOCKS_PER_SEC;
    printf("\nPostorder ellapsed %lf\n",ellapsed_time);
    fclose(fptr2);
    fclose(fptr3);
    fclose(fptr4);
    return 0;

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
        fprintf(fptr2,"%d ",root->data);
        inorder(root->right);
    }

}
void preorder(TREE root)
{
    int d;

    if (root != NULL)
    {
        d = root->data;
        fprintf(fptr3,"%d ",root->data);
        printf("%d->", root->data);
        preorder(root->left);
        preorder(root->right);
    }


}
void postorder(TREE root)
{
    int d;
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d->", root->data);
        d = root->data;
        fprintf(fptr4,"%d ",d);
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

