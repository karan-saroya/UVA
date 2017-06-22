#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
struct obj
{
	int val;
	int index;
};
bool comp(obj a, obj b)
{
	return a.val>b.val;
}
vector<obj> v;
vector<int> dp;
int main()
{
	ofstream file;
	file.open("output.txt");
	int cases;
	cin>>cases;
	for(int i=0;i<cases;i++)
	{
		int n,test;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>test;
			obj o;
			o.index=j;
			o.val=test;
			v.insert(v.end(),o);
			dp.insert(dp.end(),1);
		}
		sort(v.begin(),v.end(),comp);
		int max=1;
		for(int j=1;j<n;j++)
		{
			for(int k=j-1;k>=0;k--)
			{
				if(v[j].index < v[k].index && dp[k] +1 > dp[j] )
				{
					dp[j] = dp[k] +1;			
				}
			}
			if(dp[j] > max)
				max= dp[j];
		}
		cout<<max<<endl;
		file<<max<<endl;
		
		v.clear();
		dp.clear();
	}
}
