#include<iostream>
#define INF 3000
using namespace std;
int values[100];
int weight[100];
int dp[1000][100];
int main()
{
		int n;
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
			cin>>values[i];
			cin>>weight[i];
		}
		for(int i=0;i<1000;i++)
		{
			for(int j=0;j<100;j++)
			{
				dp[i][j]=0;
			}
		}
		for(int i=0;i<=n;i++)
		{
			dp[0][i]=0;
		}
		
		int bal;
		cin>>bal;
		for(int i=0;i<=bal;i++)
		{
			dp[i][0]=0;
		}
		for(int i=1;i<=bal;i++)
		{
			for(int j=1;j<=n;j++)
			{
				
				dp[i][j] = dp[i][j-1];
				if(i-weight[j] >=0)
					dp[i][j] = dp[i][j] > values[j]+dp[i-weight[j]][j-1] ? dp[i][j] : values[j]+dp[i-weight[j]][j-1] ;
			}
		}
	/*	for(int i=0;i<=bal;i++)
		{
			for(int j=0;j<=n;j++)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	*/
		cout<<dp[bal][n];
}
