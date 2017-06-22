#include<iostream>
#include<vector>

using namespace std;
int dp[101][11];
int course[11][101];
int flag[101][11];
int main()
{
	int cases;
	cin>>cases;
	for(int z=1;z<=cases;z++)
	{
		for(int i=0;i<=100;i++)
		{
			for(int j=0;j<=10;j++)
			{
					flag[i][j]=dp[i][j]= 0;					
			}
		}
		int num_c,bal;
		cin>>num_c>>bal;
		
		for(int i=1;i<=num_c;i++)
		{
			for(int j=1;j<=bal;j++)
			{
					cin>>course[i][j];					
			}
		}
		
			for(int i=1;i<=bal;i++)
			{
				for(int j=1;j<=num_c;j++)
				{
					dp[i][j] = dp[i][j-1];
					cout<<" I" <<i<<" J"<<j;
					int max=0;
					for(int k=1;k<=bal;k++)
					{
						if(i-k >=0&& course[j][k] >=5)
						{
							if(course[j][k]+dp[i-k][j-1] > max)
								{
									max= course[j][k]+dp[i-k][j-1];		
									if(i!=k && dp[i-k][j-1] == 0)
										flag[i][j]	=1;
									else
										flag[i][j]	=0;					
								}
						}
					}	
					dp[i][j] = (dp[i][j] > max ? dp[i][j] : max);
					cout<<" "<<max<<" "<<endl;
				}
			}
			
			for(int i=1;i<=bal;i++)
			{
				cout<<"Balance "<<i<<endl;
				for(int j=0;j<=num_c;j++)
				{
					cout<<dp[i][j]<<" ";					
				}
				cout<<endl;
			}
			int ans=0;
			for(int i=2;i<=bal;i++)
			{
				for(int j=2;j<=num_c;j++)
				{
					if(flag[i][j] == 1)
						{
							ans=1;
							break;
						}
				}
			}
			if(ans)
				cout<<"0"<<endl;
			else
				cout<<dp[bal][num_c];
	}
	
	
	
}
