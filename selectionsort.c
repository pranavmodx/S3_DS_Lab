#include <stdio.h>

int main()
{
int n,i,j,min,pos;
printf("Enter no of elements:");
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
printf("Elements are:\n");
for(i=0;i<n;i++)
{
	printf("%d\t",a[i]);
}
for (i=0;i<n-1;i++)
{
	//storing the ith element as min and its position as pos
	min=a[i];
	pos=i;
	for (j=i+1;j<n;j++)
	{
		if(min>a[j])
		{
			min=a[j];
			pos=j;
		}
	}
	a[pos]=a[i];
	a[i]=min;	
}
printf("\nSorted array is:\n");
for(i=0;i<n;i++)
{
	printf("%d\t",a[i]);
}
printf("\n");
return 0;
}
