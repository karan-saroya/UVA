#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int dp[10210][110];
int value[110];
int price[110];
int main()
{
//	ofstream file;
//	file.open("output.txt");
	int bal,valc;
	while(scanf("%d%d",&bal,&valc)!= EOF)
	{
		for(int i=0;i<=bal;i++)
		{
			for(int j=0;j<=valc;j++)
			{
				dp[i][j]=0;	
			}	
		}
		for(int i=1;i<=valc;i++)
		{
			cin>>price[i];
			cin>>value[i];
				
		}
		for(int i=1;i<=bal;i++)
		{
			for(int j=1;j<=valc;j++)
			{
				dp[i][j] = dp[i][j-1];
				if(i-price[j]>=0)
					dp[i][j] = (dp[i][j] > value[j] + dp[i-price[j]][j-1] ? dp[i][j] : value[j] + dp[i-price[j]][j-1] );
			}
			
		}
		int ans= dp[bal][valc];
		
			bal=bal+200;
			for(int i=0;i<=bal;i++)
			{
				for(int j=0;j<=valc;j++)
				{
					dp[i][j]=0;	
				}	
			}
			for(int i=1;i<=bal;i++)
			{
				for(int j=1;j<=valc;j++)
				{
					dp[i][j] = dp[i][j-1];
					if(i-price[j]>=0)
						dp[i][j] = (dp[i][j] > value[j] + dp[i-price[j]][j-1] ? dp[i][j] : value[j] + dp[i-price[j]][j-1] );
				}
			
			}
			int nans=dp[bal][valc];
			int index=bal;
			for(int i=bal;i>=0;i--)
			{
				if(dp[i][valc] < nans)
					{
						index = i;
						break;
					}
			}
			index++;
			if(index > 2000)
				{
					cout<<dp[bal][valc]<<endl;
				//	file<<dp[bal][valc]<<endl;
				}
			else 
			{
					cout<<ans<<endl;
					//file<<ans<<endl;
			}
		
		
		
	}	
}
