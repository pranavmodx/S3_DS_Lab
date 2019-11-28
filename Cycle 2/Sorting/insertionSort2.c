// Author - Lakshmi Sunil

#include <stdio.h>

int main()
{
	int n,i,j,temp;
	printf("Enter no: of elements:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(a[j]>temp && j>=0)
		{
			a[j+1] = a[j];
			j=j-1;
		}
		a[j+1] = temp;
	}
	printf("\nSorted array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}
