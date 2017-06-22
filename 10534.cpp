#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
vector<int> dp,vec,rdp;
int main()
{
///	ofstream file;
	//file.open("output.txt");
	int n;
	while(scanf("%d",&n)!= EOF)
	{
		int test;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&test);
			vec.insert(vec.end(),test);
			dp.insert(dp.end(),1);
			rdp.insert(rdp.end(),1);
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(vec[j] <vec[i] && dp[j]+1> dp[i])
				{
					dp[i]=dp[j]+1;
				}
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			for(int j=i+1;j<n;j++)
			{
				if(vec[j] <vec[i] && rdp[j]+1> rdp[i])
				{
					rdp[i]=rdp[j]+1;
				}
			}
		}
		int max=1;
		
		for(int i=0;i<n;i++)
		{
			int temp=(dp[i]<=rdp[i] ? 2*dp[i]-1 :2*rdp[i]-1);
			if(max < temp)
				max=temp;
		}
		cout<<max<<endl;
	//	file<<max<<endl;
		vec.clear();
		dp.clear();
		rdp.clear();
	}
	
}
