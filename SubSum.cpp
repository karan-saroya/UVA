#include<iostream>
using namespace std;
int values[1000];
int main()
{
		int n;
		cin>>n;
		
		bool dp[1000][100];
		for(int i=1;i<=n;i++)
		{
			cin>>values[i];
		}
		for(int i=0;i<1000;i++)
		{
			for(int j=0;j<100;j++)
			{
				dp[i][j]=false;
			}
		}
		for(int i=0;i<=n;i++)
		{
			dp[0][i]=true;
		}
		int bal;
		cin>>bal;
		for(int i=1;i<=bal;i++)
		{
			for(int j=1;j<=n;j++)
			{
				
				dp[i][j] = dp[i][j-1];
				if(i-values[j] >=0)
					dp[i][j] = dp[i][j] || dp[i-values[j]][j-1];
			}
		}
		for(int i=0;i<=bal;i++)
		{
			for(int j=0;j<=n;j++)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<dp[bal][n];
}
