/*
A menu driven program to show 1.Preemptive Shortest Job First Scheduling 2.Round Robin Scheduling 3.Non-preemptive Priority Scheduling
*/

#include <stdlib.h>
#include <stdio.h>
#define INT_MAX 9999
struct process
{
    int bt;//Burst time
    int pr;//Priority
    int btc;//Copy of Burst time (unaltered)
    int at;//Arrival time
    int no;//Process no/ID
    int et;//Execution time
    int conttime;//For RR Scheduling
};

//Used by Priority Scheduling
int sort(struct process **arr,int n,int t)
{
    int i,j;
    for(i=0;i<n-1;i++)
	{
            for(j=i+1;j<n;j++)
            {
                    if(arr[i]->pr>arr[j]->pr)
                    {
                        struct process* t=arr[i];
                        arr[i]=arr[j];
                        arr[j]=t;
                    }
            }
	}

    int	pos=-1,cnt=0;
	for(i=0;i<n;i++)
    {
        if(arr[i]->at<=t)
            {
                cnt++;
                if(arr[i]->bt>0)
                    {
                        pos=i;
                        return pos;
                    }
            }
    }
    if(cnt==n)
        pos=-2;
    return pos;
}

int main()
{
	printf("Enter no. of processes -\n");
	int n,i,j;
	scanf("%d",&n);
	struct process **arr;
	arr=malloc(n*sizeof(struct process*));

	for(i=0;i<n;i++)
	{
	    arr[i]=malloc(sizeof(struct process));
        printf("Burst time %d-\n",i+1);
        scanf("%d",&arr[i]->bt);
        printf("Priority %d-\n",i+1);
        scanf("%d",&arr[i]->pr);
        printf("Arrival time %d-\n",i+1);
        scanf("%d",&arr[i]->at);
        arr[i]->no=i+1;
        arr[i]->conttime=0;
        arr[i]->btc=arr[i]->bt;
	}
/*
	for(i=0;i<n;i++)
	{
        printf("Burst time - %d - ",arr[i]->no);
        printf("%d\n",arr[i]->bt);
        printf("Priority -  %d - ",arr[i]->no);
        printf("%d\n",arr[i]->pr);
        printf("Arrival time - %d - ",arr[i]->no);
        printf("%d\n",arr[i]->at);
	}
*/
    printf("1.Preemptive SJF\n2.Round Robin\n3.Non-preemptive Priority\n");
    int sw;//Switch
    scanf("%d",&sw);

    int t=0,c=0,pos;//c = no. of completed processes, n = total processes
    int s,si;//s = smallest number, si = index corresponding to smallest number

    switch(sw)
    {
    case 1:
        while(c<n)
    {
        s=INT_MAX;
        si=-1;

        for(i=0;i<n;i++)
        {
            if(arr[i]->at<=t&&arr[i]->bt>0)
            {
                if(arr[i]->bt<s)
                    {
                        si=i;
                        s=arr[i]->bt;
                    }
            }
        }

        if(si!=-1)
        {
            arr[si]->bt--;
            printf(" P%d ",arr[si]->no);
            t++;
            if(arr[si]->bt==0)
                {
                arr[si]->et=t;
                c++;
                }
        }
        else
           {
               t++;
               printf(" - ");
           }
    }
        break;
    case 2:

        while(c<n)
    {
        int f=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]->at<=t&&arr[i]->bt>0)
            {
                    f=1;//flag
                    arr[i]->bt--;
                    t++;

                    printf(" P%d ",arr[i]->no);
                    if(arr[i]->bt==0)
                        {
                            arr[i]->et=t;
                            c++;
                            continue;
                        }

                    arr[i]->conttime++;
                    if(arr[i]->conttime==3)
                        {
                            arr[i]->conttime=0;
                            i++;
                        }
                    i--;
            }
        }
        if(f!=1)
        {
            t++;
            printf("-");
        }
    }
        break;
    case 3:
        while(1)
        {
            pos = sort(arr,n,t);
            if(pos==-1)
            {
                printf(" - ");
                t++;
                continue;
            }
            else if(pos==-2)
                break;
            else
            {
                t+=arr[pos]->bt;
                for(i=0;i<arr[pos]->bt;i++)
                    printf(" P%d ",arr[pos]->no);
                arr[pos]->bt=0;
                arr[pos]->et=t;
                arr[pos]->pr=INT_MAX;
            }
        }

        break;
    }
        float awt = 0;//Average waiting time
        int temp;
        printf("\nWaiting time-\n");
		for(i=0;i<n;i++)
	{
        temp = arr[i]->et-arr[i]->btc-arr[i]->at;
        printf("Wait time for process %d - ",arr[i]->no);
        printf("%d\n",(temp));
        awt=awt+temp;
	}
	awt/=n*1.0;
	printf("\nAverage waiting time- %f",awt);
	return 0;
}
