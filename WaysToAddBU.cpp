#include<iostream>
#include<string>
using namespace std;


int main()
{
	int dp[1000][100];
	int tar,k;
	cin>>tar;
	cin>>k;
	for(int i=0;i<=tar;i++)
	{
		for(int j=0;j<=k;j++)
		{
			dp[i][j] = 0;
		}
	}
	dp[0][0]=1;
	for(int i=0;i<=tar;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(dp[i][j] !=0)
			{
				for(int l=0;l<=tar;l++)
				{
					if(i+l <= tar&& j+1<=k)
						dp[i+l][j+1] += dp[i][j];
				
				}
			
			}
			
		}		
	}
	for(int i=0;i<=tar;i++)
	{
		for(int j=0;j<=k;j++)
		{
			cout<<dp[i][j]<<" ";
		}		
		cout<<endl;
	}
	cout<<dp[tar][k]<<endl;
}
