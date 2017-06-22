#include<iostream>
using namespace std;
int main()
{
	int arr[100];
	int sum[100];
	int size;
	scanf("%d",&size);\
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
		sum[i]=arr[i];
	}
	int max=sum[0];
	for(int i=1;i<size;i++)
	{
		if(sum[i-1]+ arr[i] >= arr[i])
			sum[i] = arr[i]+sum[i-1];
		if(sum[i]> max)
			max= sum[i];
	}
	cout<<max<<endl;
	return 0;
}
