#include<iostream>
#include<vector>
using namespace std;
int curr[]={0,5,10,20,50,100,200,500,1000,2000,5000,10000};
long long dp[30100][13];
int main()
{
	for(int j=0;j<12;j++)	
		dp[0][j]=1;
	
	for(int i=1;i<=30000;i++)
	{
		for(int j=0;j<12;j++)
		{
			dp[i][j]=0;
		}
	}
	
	for(int i=1;i<=30000;i++)
	{
		for(int j=1;j<=11;j++)
		{
			long long x =0;
			if(i-curr[j] >= 0)
				 x = dp[i-curr[j]][j];
			long long y = dp[i][j-1];
			dp[i][j] = x+y;
		}
	}
	while(true)
	{
		double t;
		cin>>t;
		int bal=(int)(t*100+0.000001);
		if(bal == 0)
			break;
		else
		{
			printf("%6.2lf%17lld\n",t,dp[bal][11]);
		}
		
		
	}
	
	
}
