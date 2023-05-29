//ROSHITH R H (01FE21BEI036)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define SIZE 20
int main()
{
    int n,upper,lower,random,i,arr[SIZE],x=0;
    FILE *fptr;
    srand(time(NULL));
    fptr = fopen("randomnumgen.txt","w");//Clear previous file contents
    fclose(fptr);
    printf("Enter number of random numbers to be generated\n");
    scanf("%d",&n);
    printf("Enter the range in which random number needs to be generated\n");
    scanf("%d %d",&lower,&upper);
    for(int i = 0;i < n;i ++)  //Generate Random numbers and push them into a file
    {
         fptr = fopen("randomnumgen.txt","a");
         random = rand()%upper+lower;
         fprintf(fptr,"%d ",random);
         printf("%d -> ",random); //Prints random numbers into the file
         fclose(fptr);
    }
    fptr = fopen ("randomnumgen.txt", "r"); //Open file in read mode and read the contents of the file
    fscanf (fptr, "%d", &i);
    while (!feof (fptr)) //Read file until eof is reached
    {
        arr[x] = i; //Temporary store read numbers into an array
      printf ("%d ", i);
      fscanf (fptr, "%d", &i); //Reads file contents with integer type
      x++;
    }
    fclose (fptr);
    printf("\nARRAY:\n");
    for (int i=0;i<x;i++)
    {
        printf("%d ",arr[i]);
    }
}
