/*) Design a scheduler following non-preemptive scheduling approach to schedule the
processes that arrives at different units and having burst time double the arrival time.
Scheduler selects the process with largest burst time from the queue for the execution.
Process is not being preempted until it finishes its service time. Compute the average
waiting time and average turnaround time. What should be the average waiting time if
processes are executed according to Shortest Job First scheduling approach with the
same attribute values.*/
//p[]      -->  Process id
//brust[]  -->  Brust time for each process
//arr[]    -->  Arrival Time For Each Process
//w_time[] -->  Waiting time for each process
//t_time[] -->  turnarround time for each process
//twt      -->  total Waiting time
//ttat     -->  total turnarround time


#include <stdio.h>
#include <unistd.h>

int shortest_job(int arr[],int brust[],char p[],int n)
{
	int k=1,i,j,temp;
	int min,sum=0,bt,ta;
	int w_time[20],t_time[20];
	float SUM1=0,SUM2=0,a_w_t,a_t_t;
	//Executing Shotest Job First Scheduling
	for(j=0;j<n;j++)
    {
        bt=bt+brust[j];
        min=brust[k];
    for(i=k;i<n;i++)
    {
        if (bt>=arr[i] && brust[i]<min)
            {
                temp=p[k];
                p[k]=p[i];
                p[i]=temp;
                
                temp=arr[k];
                arr[k]=arr[i];
                arr[i]=temp;
                
                temp=brust[k];
                brust[k]=brust[i];
                brust[i]=temp;
            }
    }
    k++;
    }
w_time[0]=0;            //waiting time for process 1 is zero
    for(i=1;i<n;i++)
    {
        sum=sum+brust[i-1];
        w_time[i]=sum-arr[i];  
        SUM1=SUM1+w_time[i];
    }

a_w_t=(SUM1/n);
    for(i=0;i<n;i++)
    {
        	t_time[i]=brust[i]+w_time[i];
        	t_time[i] = t_time[i];
        	SUM2=SUM2+t_time[i];
    }

a_t_t=(SUM2/n);

printf("\nProcess Name\tBurst Time\t Arrival Time\t Waiting Time\t Turn Around Time" );
    for(i=0;i<n;i++)
    {
        printf("\n%c\t\t%d\t\t %d\t\t %d\t\t %d",p[i],brust[i],arr[i],w_time[i],t_time[i]);
    }
    
    printf("\n\nAVERAGE WAITING TIME : %f",a_w_t);
    printf("\nAVERAGE TURN AROUND TIME : %f\n",a_t_t);
    
}


int normal(int arr[],int brust[],char p[],int n)
{
		int k=1,i,j,temp;
	int max,sum=0,bt,ta;
	int w_time[20],t_time[20];
	float SUM1,SUM2,a_w_t,a_t_t;
	for(j=0;j<n;j++)
    {
        bt=bt+brust[j];
        max=brust[k];
    for(i=k;i<n;i++)
    {
        if (bt>=arr[i] && brust[i]>max)
            {
                temp=p[k];
                p[k]=p[i];
                p[i]=temp;
                
                temp=arr[k];
                arr[k]=arr[i];
                arr[i]=temp;
                
                temp=brust[k];
                brust[k]=brust[i];
                brust[i]=temp;
            }
    }
    k++;
    }
w_time[0]=0;
    for(i=1;i<n;i++)
    {
        sum=sum+brust[i-1];
        w_time[i]=sum-arr[i];  
        SUM1=SUM1+w_time[i];
    }

a_w_t=(SUM1/n);
    for(i=0;i<n;i++)
    {
        t_time[i]=brust[i]+w_time[i];
        t_time[i] = t_time[i];
        SUM2=SUM2+t_time[i];
    }

a_t_t=(SUM2/n);

printf("\nProcess Name\tBurst Time\t Arrival Time\t Waiting Time\t Turn Around Time" );
    for(i=0;i<n;i++)
    {
        printf("\n%c\t\t%d\t\t %d\t\t %d\t\t %d",p[i],brust[i],arr[i],w_time[i],t_time[i]);
    }
    
    printf("\n\nAVERAGE WAITING TIME : %f",a_w_t);
    printf("\nAVERAGE TURN AROUND TIME : %f\n",a_t_t);
printf("\n---------------------------------------------------------------------------------\n\n");
}

int main()
{
	char p[20],p1[20];
	int n,i,j,temp=65,pos,flag;
	int brust[20],arr[20];
	int brust1[20],arr1[20];
	printf("Enter Number Of Process: ");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("\n\n::::  Invalid Value Of Number Of Process  ::::");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		p[i] = temp;
		temp+=1;
	}
	for(i=0;i<n;i++)
	{
		printf("\n\nEnter The Arrival Time For Process %c: ",p[i]);
		scanf("%d",&arr[i]);
		brust[i] = 2*arr[i];
		printf("The Brust Time Of the Process Is: %d",brust[i]);
	}
	
	//sorting arrival time,and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[pos])
                pos=j;
        }
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
 
        temp=brust[i];
        brust[i]=brust[pos];
        brust[pos]=temp;
 
        temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
        
        if(brust[i]<0)
		{
			flag = 1;
		}
    }
    
    if(flag==1)
    {
    	printf("\n\n:::  Invalid Time Entered ::: \n");
    	exit(0);
	}
	
	 printf("\n\n |Arrival  |  Process   |  Brust |");
	
	for(i=0;i<n;i++)
	{
		printf("\n |   %d \t   |    %c    \t|   %d    |",arr[i],p[i],brust[i]);
	}
	
	for(i=0;i<n;i++)
	{
		arr1[i]=arr[i];
		p1[i] = p[i];
		brust1[i]=brust[i];
	}
	printf("\n---------------------------------------------------------------------------------");
	printf("\n\n<<<<<<<<<<<<<<<<<<<<<  In Logest Job First Schedulling  >>>>>>>>>>>>>>>>>>>>>>>>>>");
	normal(arr,brust,p,n);
	printf("<<<<<<<<<<<<<<<<<<<<<  In Shortest Job First Schedulling  >>>>>>>>>>>>>>>>>>>>>>>>>");
	shortest_job(arr1,brust1,p1,n);
}
