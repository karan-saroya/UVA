#include<iostream>
using namespace std;
int arr[100];
int LIS[100];
int main()
{
	int size;
	cin>>size;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
		LIS[i]=1;
	}
	int ans=1;
	for(int i=1;i<size;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(arr[j] <= arr[i] && LIS[i]< LIS[j]+1)
				LIS[i] = LIS[j]+1;
		}
		if(LIS[i] > ans)
			ans=LIS[i];
	}
	cout<<ans<<endl;
	
	
	
}
