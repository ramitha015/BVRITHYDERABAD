#include<stdio.h>
 
 int main() {
 	
   int n,bt[20],wt[20],tat[20],i,j,p[20],pos,temp;
   float sum_wt=0,sum_tat=0,avwt=0,avtat=0;
    printf("Enter total number of processes:");
    scanf("%d",&n);
 
    printf("\nEnter the order of processes in terms of 1,2,3,4,....n: ");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&p[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of process %d:",p[i]);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++){
    	pos=i;
    	for(j=i+1;j<n;j++){
    		if(bt[j]<bt[pos])
    		    pos=j;
		}
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
 
    wt[0]=0;   
 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    printf("\nProcess no\tBurst Time\tWaiting Time\tTurnaround Time\n");
 
    for(i=0;i<n;i++){
	    tat[i]=bt[i]+wt[i];
        sum_wt+=wt[i];
        sum_tat+=tat[i];
        printf("\t%d\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
 
    avwt=sum_wt/n;
    avtat=sum_tat/n;
    printf("\nAverage Waiting Time:%.2f\n",avwt);
    printf("\nAverage Turnaround Time:%.2f\n",avtat);
 
    return 0;
}
