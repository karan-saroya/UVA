#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>
using namespace std;
vector<int> values;
int dp[101][21];
int main()
{
//	ofstream file;
//	file.open("output.txt");
	int m;
	string s;
	getline(cin,s);
	m=atoi(s.c_str());
	for(int i=0;i<m;i++)
	{
		string str;
		getline(cin,str);
		istringstream iss(str);
		
		while(iss)
		{
			string sub;
			iss>>sub;
			values.insert(values.end(),atoi(sub.c_str()));	
		}
		values.erase(values.end()-1);
		values.insert(values.begin(),0);
		int bal=0;
		for(int j=1;j<values.size();j++)
			bal+=values[j];
		if(bal%2 == 1)
			{
				cout<<"NO"<<endl;
	//			file<<"NO"<<endl;	
			}
		else
		{
			bal=bal/2;
			for(int j=0;j<=bal;j++)
			{
				for(int k=0;k<values.size();k++)
					dp[j][k] =0;
			}
				for(int k=0;k<values.size();k++)
					dp[0][k] =1;
			
			for(int j=1;j<=bal;j++)
			{
				for(int k=1;k<values.size();k++)
					{
						dp[j][k] = dp[j][k-1];
						if(j - values[k] >=0 )
							dp[j][k] = dp[j][k] + dp[j-values[k]][k-1];
					}
			}
			if(dp[bal][values.size()-1])
				{
					cout<<"YES"<<endl;
	//				file<<"YES"<<endl;
				}
			else
			{
				cout<<"NO"<<endl;
	//			file<<"NO"<<endl;
			}
				
		
		}
		values.clear();	
	}
}
