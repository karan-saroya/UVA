#include<iostream>
#include<string>
#define MAX 100000000
using namespace std;
int main()
{
	int val[100];
	int dp[100000];
	int tar,numVal;
	cin>>tar;
	cin>>numVal;
	
	for(int i=0;i<=tar;i++)
		{
			dp[i]=MAX;		
		}
	for(int i=0;i<numVal;i++)
		{
			cin>>val[i]  ;
			dp[val[i]]=1;
		}
		dp[0]=0;
	for(int i=0;i<=tar;i++)
	{
		if(dp[i]!= MAX)
		{
			for(int j=0;j<numVal;j++)
			{
				if(dp[i] + 1< dp[i+val[j]])
					dp[i+val[j]] = dp[i] +1;
			}
		}
	}
	for(int i=0;i<=tar;i++)
		{
			cout<<i<<" "<<dp[i]<<endl;		
		}
	cout<<dp[tar]<<endl;
}
