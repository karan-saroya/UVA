#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
long long dp[7500][7];
int values[]={0,1,5,10,25,50};
int main()
{
	//ofstream file;
	//file.open("output.txt");
	for(int i=0;i<=7500;i++)
	{
		for(int j=0;j<6;j++)
			dp[i][j] =0;
	}
	for(int j=0;j<6;j++)
		dp[0][j]=1;
	for(int i=1;i<=7500;i++)
	{
		
		for(int j=1;j<6;j++)
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
		cout<<dp[bal][5]<<endl;
		//file<<dp[bal][5]<<endl;
	}
}
