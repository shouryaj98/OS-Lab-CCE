#include<stdio.h>
int available[10],max[10][10],allocation[10][10],need[20][20],n,r,work[10],finish[10],safe[10];
void safety()
{
int i,j;
}


int main(){
int i,j;
printf("Enter the number of processes : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    finish[i]=0;
}
/*for(i=0;i<n;i++)
{
    printf("Process %d is %d \n",i,finish[i]);
}*/
printf("Enter the number of resources : ");
scanf("%d",&r);
printf("Enter no. of available resources");
for(i=0;i<r;i++)
{
    scanf("%d",&available[i]);
}
//for(i=0;i<r;i++)
//{
  //  printf("%d",available[i]);
//}
printf("Enter allocation values row wise");
for(i=0;i<n;i++)
{
   for(j=0;j<r;j++)
        {
            scanf("%d",&allocation[i][j]);
            //printf("Allocation is %d \n",allocation[i][j]);
        }
}

printf("Enter maximum values row wise");
for(i=0;i<n;i++)
{
   for(j=0;j<r;j++)
        {
            scanf("%d",&max[i][j]);
            //printf("max is %d \n",max[i][j]);
        }
}

printf("Copying available into work");
for(i=0;i<r;i++)
{
    work[i]=available[i];
}

printf("The need matrix is: \n");
for(i=0;i<n;i++)
{
    for(j=0;j<r;j++)
    {
        need[i][j]=max[i][j]-allocation[i][j];
        printf("%d ",need[i][j]);
    }
    printf("\n");
}

//safety();


int pn,rr[10];
printf("Enter request\nProcess ID -");
scanf("%d",&pn);
printf("Enter the requests-\n");
for(i=0;i<r;i++)
{
    scanf("%d",&rr[i]);
}
int ff1=0,ff2=0,ff3=0;
for(i=0;i<r;i++)
{
    if(rr[i]>need[pn][i])
        ff1=1;
}
for(i=0;i<r;i++)
{
     if(rr[i]>need[pn][i])
        ff2=1;
}
if(ff1==1||ff2==1)
    printf("Request cannot be granted");
else
{
    for(i=0;i<r;i++)
        work[i]-=rr[i];
    for(i=0;i<r;i++)
        allocation[pn][i]+=rr[i];
    for(i=0;i<r;i++)
        need[pn][i]-=rr[i];
    ff3=1;
}

if(ff3==1){
int c=0,flag=0;
while(c<n)
{
    int temp=c;
    for(i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
            int f=1;
            for(j=0;j<r;j++)
            {
                if(need[i][j]>work[j])
                    f=0;
            }
            if(f==1)
            {
                for(j=0;j<r;j++)
                {
                    work[j]+=allocation[i][j];
                }
                printf("Finished Process %d\n",i);
                finish[i]=1;
                c++;
            }
        }
    }
    if(temp==c)
    {
        printf("\nNot safe state\n");
        flag=1;
        break;
    }
}
if(flag==0)
    printf("Safe state");
}
}
