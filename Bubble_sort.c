#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{


    int n,temp;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    int a[n];
    for(int k = 0;k < n; k++)
    {
        printf("Enter the element % d of array\n",k+1);
        scanf("%d",&a[k]);
    }
    printf("Array : \n");
    for(int k = 0;k < n; k++)
    {
        printf("%d ",a[k]);
    }
    //Bubble sorting Algorithm.
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }

        }
    }
    printf("\nSorted Array according to ascending order : \n");
    for(int p=0;p<n;p++)
    {
        printf("%d ",a[p]);

    }
    printf("\nSorted Array according to descending order : \n");
    for(int p=n-1;p>=0;p--)
    {
        printf("%d ",a[p]);
    }

}
