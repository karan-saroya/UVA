#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int arr[20];
int rank[20];
vector<int> vec;
vector<int> lds;
int main()
{
	int n;
//	ofstream file;
//	file.open("output.txt");
	int cases=1;
	while(true)
	{
		cin>>n;
		if(n == -1)
			break;
		vec.insert(vec.end(),n);
		int test;
		while(true)
		{
			cin>>test;
			if(test == -1)
				break;
			vec.insert(vec.end(),test);
		}
		int vsize=vec.size();
		for(int i=0;i<vsize;i++)
		{
			lds.insert(lds.end(),1);
		}
		int mmax=0;
		for(int i=0;i<vsize;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				if( vec[i] <=vec[j] )
				{
					if(lds[j] +1 > lds[i])
						lds[i] = lds[j]+1;
				}
			}
			if(lds[i]>mmax)
				mmax=lds[i];
		}
		if(cases != 1)
			cout<<endl;
		cout<<"Test #"<<cases<<":"<<endl;
		cout<<"  maximum possible interceptions: "<<mmax<<endl;
////		if(cases != 1)
//			file<<endl;
//		file<<"Test #"<<cases<<":"<<endl;
//		file<<"  maximum possible interceptions: "<<mmax<<endl;
		
		lds.clear();
		vec.clear();
		cases++;
	}

}
