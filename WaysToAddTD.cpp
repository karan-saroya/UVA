#include<iostream>
#include<string>
using namespace std;
int tar,k;

	int dp[100][100];
int ways(int n, int k)
{
	
	if(dp[n][k] != 0)
	{
		return dp[n][k];	
	}
	else
	{
		int ans=0;
		for(int i=0;i<=tar;i++)
		{
			if(n-i >=0 && k-1 >=0)
			{
				ans+=ways(n-i,k-1);
			}
		}
		dp[n][k] = ans;
		return ans;
	}
	
}
int main()
{
	cout<<"Enter target"<<endl;
	cin>>tar;
	cout<<"Enter k"<<endl;
	cin>>k;
	cout<<tar<<k;
	for(int i=0;i<=tar;i++)
	{
		for(int j=0;j<=k;j++)
		{
			
			dp[i][j]=0;
		
		}
		cout<<endl;
	}
	
	for(int j=0;j<=k;j++)
	{
			
			dp[0][j]=1;
		
	}
	ways(tar,k);
	

	cout<<dp[tar][k]<<endl;
	
}
