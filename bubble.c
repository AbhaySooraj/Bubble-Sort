/*To implement Bubble sort*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float timedifference_msec(struct timeval t0,struct timeval t1)
{
	return(t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void display(int n,int arr[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d \t",arr[i]);
	}
}

void main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	int x,n,i,j=0,temp;
	
	printf("\n Enter number of elements ");
	scanf("%d",&n);
	int arr[n];
	
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%100;
	}
	
	printf("\n The unsorted elements are :");
	display(n,arr);
	
	gettimeofday(&t0, NULL);
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	printf("\n The sorted elements are :");
	display(n,arr);
	
	gettimeofday(&t1, NULL);
	elapsed=timedifference_msec(t0,t1);
	printf("\nCode executed in %f milliseconds.\n", elapsed);
}
