#include<iostream>
using namespace std;
int dp[100010][4];

int main()
{
	int cases;
	cin>>cases;
	for(int l=0;l<cases;l++)
	{
		int n;
		for(int i=0;i<n;i++)
		{
			cin>>dp[n-i][1];	
		}
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=3;j++)
			{
				dp[i][2]=dp[i][1]+dp[i-1][1];
			}
		}
	}
}
