#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
long long dp[10010][22];
int values[22];
int main()
{
	//ofstream file;
	//file.open("output.txt");
	
	for(int i=1;i<=21;i++)
	{
		values[i]=i*i*i;
	}
	
	for(int i=0;i<=10000;i++)
	{
		for(int j=0;j<22;j++)
			dp[i][j] =0;
	}
	for(int j=0;j<22;j++)
		dp[0][j]=1;
	for(int i=1;i<=10000;i++)
	{
		
		for(int j=1;j<22;j++)
			{
				
				long long x=0,y=0;
				if(i-values[j] >=0)
				{
					x = dp[i-values[j]][j];
				}
				y= dp[i][j-1];
				dp[i][j] = x+y;
			}
	}
	int bal;
	while(scanf("%d",&bal)!=EOF)
	{
		cout<<dp[bal][21]<<endl;
		//file<<dp[bal][5]<<endl;
	}
}
