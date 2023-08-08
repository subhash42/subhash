#include<stdio.h>

void main()
{
 int pn[10];
 int arr[10],bur[10],star[10],finish[10],tat[10],wt[10],i,n;
 float totwt=0,tottat=0;

printf("Enter the number of process: ");
scanf("%d",&n);
printf("Enter the process name, Arrival time and Burst time: ");

for(i=0;i<n;i++)
{
 scanf("%d %d %d ",&pn[i],&arr[i],&bur[i]);
}
for(i=0;i<n;i++)
{
 if(i==0)
   {
     star[i]=arr[i];
     wt[i]=star[i]-arr[i];
     finish[i]=star[i]+bur[i];
     tat[i]=finish[i]-arr[i];
    }
else
{
  star[i]=finish[i-1];
  wt[i]=star[i]-arr[i];
  finish[i]=star[i]+bur[i];
  tat[i]=finish[i]-arr[i];
 }
}
printf("\nPname ArrTime  BustTime  StartTime  TotalTurn  FinishTime");
 for(i=0;i<n;i++)
{
 printf("\n%6d\t%6d\t%6d\t%6d\t%6d\t%6d",pn[i],arr[i],bur[i],star[i],tat[i],finish[i]);
 totwt +=wt[i];
 tottat +=tat[i];
}

printf("\nAverage waiting time :%f",(float)totwt/n);
printf("\nAverage turn around time: %f",(float)tottat/n);

}


