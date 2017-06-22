#include<iostream>
#include<string>
#define MAX 1000000
using namespace std;
int value[100];
int size;
int tar;
int min_diff=100000000;
int dp[1000][100];
string best_path;
int SS(int curr_diff,int curr_index)
{
	if(curr_index == size)
	{
		return curr_diff;
	}
	else if(curr_index >=0 &&dp[curr_diff][curr_index] != MAX)
	{
		return dp[curr_diff][curr_index];
	}
	else
	{
		int min_d=curr_diff;
		for(int i=curr_index+1;i<size;i++)
		{
			int ret;
			if(curr_diff-value[i]>=0)
			{
				ret = SS(curr_diff-value[i],i);
				if(ret < min_d)
					min_d=ret;
			}
			
		}
		dp[curr_diff][curr_index] = min_d;
		return dp[curr_diff][curr_index];
	}
}
int main()
{
	cin>>size;
	for(int i=0;i<size;i++)
		{
			cin>>value[i];
		}
	cin>>tar;
	for(int i=0;i<=tar;i++)
	{
		for(int j=0;j<=size;j++)
			dp[i][j]=MAX;
		
	}
	for(int i=0;i<=size;i++)
		dp[0][i]=0;
	
	
	int ret;
	cout<<SS(tar,-1)<<endl;	
    for(int i=0;i<=tar;i++)
	{
		for(int j=0;j<=size;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
