#include<iostream>

using namespace std;
int bets[10010];
int dp[10010];
int main()
{
	while(true)
	{
	
		int n;
		cin>>n;
		if(n == 0)
			break;
		for(int i=0;i<n;i++)
		{
			cin>>bets[i];
			dp[i]=bets[i];
		}
		int max=-100000000;
		for(int i=1;i<n;i++)
		{
			if(dp[i]+dp[i-1]> dp[i])
				dp[i]+=dp[i-1];
			if(dp[i]> max)
				max= dp[i];
		}	
		if(max <= 0)
			cout<<"Losing streak."<<endl;
		else
			cout<<"The maximum winning streak is "<<max<<"."<<endl;
	}
}
