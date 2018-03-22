#include <stdlib.h>
#include <stdio.h>
struct process
{
    int pid;
    int size;
    int holeno;
};

struct holes
{
    int size;
};

int main()
{
    printf("Enter no. of processes -\n");
	int np,nh,i,j;
	scanf("%d",&np);
	//printf("n is %d \n",n);
	struct process *arr;
	arr=malloc(np*sizeof(struct process));
	for(i=1;i<=np;i++)
	{
        printf("Size of PID %d -",i);
        scanf("%d",&arr[i-1].size);
        arr[i-1].pid=i;
	}

	printf("Enter no. of holes -\n");
	scanf("%d",&nh);
	struct holes *arr2;
	arr2=malloc(nh*sizeof(struct holes));
	printf("Enter size of holes-\n");
	for(i=1;i<=nh;i++)
	{
	    printf("Hole no. %d -",i);
        scanf("%d",&arr2[i-1].size);
	}

	/*
	for(i=1;i<=nh;i++)
	{
        //printf("Size of PID %d -",i);
        printf("%d\n",arr2[i-1].size);
	}
*/

    int ch,flag;
    printf("\n1.First Fit\n2.Best Fit\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:

    for(i=0;i<np;i++)
    {
       j=0;flag=0;
       while(j<nh)
       {
           if(arr[i].size<=arr2[j].size)
            {
                //printf("  inside if  ");
                flag=1;
                arr[i].holeno=j+1;
                arr2[j].size-=arr[i].size;
                break;
            }
            j++;
       }
       if(flag==0)
          arr[i].holeno=0;//unallocated
    }
    break;

    case 2:

    for(i=0;i<np;i++)
    {
       //flag=0;
       int best=0;
       for(j=0;j<nh;j++)
       {
           if(arr2[j].size>=arr[i].size&&(best==0||arr2[j].size<arr2[best-1].size))
            best=j+1;
       }
        arr[i].holeno=best;
        arr2[best-1].size-=arr[i].size;
    }
    break;

    }

    printf("\n");
    for(i=0;i<np;i++)
    {
        if(arr[i].holeno!=0)
        printf("PID %d allocated to Hole No.- %d \n",arr[i].pid,arr[i].holeno);
        else
        printf("PID %d could not be allocated \n",arr[i].pid);
    }

    printf("\n");
    for(i=0;i<nh;i++)
    {
        printf("Current size of hole %d = %d\n",i+1,arr2[i].size);
    }
}
