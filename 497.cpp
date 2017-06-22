#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> vec,dp,par;
int main()
{
	
	string str;
	int cases;
	cin>>cases;
	getline(cin,str);
	for(int i=0;i<cases;i++)
	{
		int size=0;
		while(true)
		{
			getline(cin,str);
			if(str.length() == 0 )
				break;
			int num=atoi(str.c_str());
			vec.insert(vec.end(),num);
			par.insert(par.end(),size++);
			dp.insert(dp.end(),1);
		}
		int max=1;
		for(int i=1;i<vec.size();i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(vec[j] < vec[i] && dp[j] > dp[i])
				{
					dp[i] = dp[j]+1;
				}
			}
			if(dp[i] > max)
				max=dp[i];
			
		}
		
		cout<<max<<endl;
		
		
		
		
		
		
		
		
		
		
		vec.clear();
		dp.clear();
		par.clear();
	}

}
