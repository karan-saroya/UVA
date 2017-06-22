#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	int arr[110][110],sec_sum[110][110];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{
				cin>>arr[i][j];
				sec_sum[i][j]=arr[i][j];
			}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<j;k++)
			{
				sec_sum[i][j]+=arr[i][k];
			}
		}
			
	}
	int temp[110],dp[110];
	for(int i=0;i<n;i++)
	{
		temp[i]=0;
		dp[i]=0;
	}
	int max_max=-100000000;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(i != 0 )
			{
				for(int k=0;k<n;k++)
				{
					temp[k] = sec_sum[k][j]-sec_sum[k][i-1];
					dp[k]=temp[k];
				}
			}
			else
			{
				for(int k=0;k<n;k++)
				{
					temp[k] = sec_sum[k][j];
					dp[k]=temp[k];
				}
				
			}
			for(int k=1;k<n;k++)
			{
				if(dp[k]+dp[k-1]>dp[k])
					dp[k]+=dp[k-1];
				if(dp[k]>max_max)
					max_max=dp[k];
			}
			
		}
		
	}
	cout<<max_max<<endl;

	
}
