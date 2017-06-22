#include<iostream>
#include<string>
using namespace std;
int numC,tar;
int dp[100][100];
int val[100];
int ways(int bal, int index)
{
	if(index == numC)
	{
		if(bal == 0)
			return 1;
		else
			return 0;
	}
	else if(dp[bal][index] != -1)
		return dp[bal][index];
	 else
	 {
	 	int ans=0;
	 	for(int i=index;i<numC;i++)
	 	{
	 		if(bal-val[i]>=0)
	 		{
	 			ans+=ways(bal-val[i], i);
			 }
		 }
		 dp[bal][index]=ans;
		 return dp[bal][index];
	 }
}
int main()
{
	cin>>tar;
	cin>>numC;
	for(int i=0;i<=tar;i++)
	{
		for(int j=0;j<numC;j++)
			dp[i][j] = -1;
	}
	
	for(int i=0;i<numC;i++)
		{
			cin>>val[i];
			dp[val[i]][i] = 1;
			dp[0][i]=1;
		}
	cout<<ways(tar,0);
}
