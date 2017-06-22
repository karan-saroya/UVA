#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

vector<int> v,width;
vector<int> dp,dpd;
int main()
{
	//ofstream file;
	//file.open("output.txt");
	int cases;
	cin>>cases;
	for(int i=0;i<cases;i++)
	{
		int n,test;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>test;
			v.insert(v.end(),test);
			
		}
		for(int j=0;j<n;j++)
		{
			cin>>test;
			width.insert(width.end(),test);
			dp.insert(dp.end(),test);
			dpd.insert(dpd.end(),test);
		}
		
		int max=width[0];
		for(int j=1;j<n;j++)
		{
			for(int k=j-1;k>=0;k--)
			{
				if(v[j] > v[k] && dp[k] +width[j] > dp[j] )
				{
					dp[j] = dp[k] +width[j];			
				}
			}
			if(dp[j] > max)
				max= dp[j];
		}
		
		int dec=width[0];
		for(int j=1;j<n;j++)
		{
			for(int k=j-1;k>=0;k--)
			{
				if(v[j] < v[k] && dpd[k] +width[j] > dpd[j] )
				{
					dpd[j] = dpd[k] +width[j];			
				}
			}
			if(dpd[j] > dec)
				dec= dpd[j];
		}
		
		if(max>=dec)
		{
			cout<<"Case "<<i+1<<". "<<"Increasing ("<<max<<"). Decreasing ("<<dec<<")."<<endl;
			//file<<"Case "<<i+1<<". "<<"Increasing ("<<max<<"). Decreasing ("<<dec<<")."<<endl;
		}
		else
		{
			cout<<"Case "<<i+1<<". "<<"Decreasing ("<<dec<<"). Increasing ("<<max<<")."<<endl;
			//file<<"Case "<<i+1<<". "<<"Decreasing ("<<dec<<"). Increasing ("<<max<<")."<<endl;
		}
		v.clear();
		dp.clear();
		dpd.clear();
		width.clear();
	}
}
