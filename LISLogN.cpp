#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<fstream>
using namespace std;
vector<int> v,bend,par,temp;
stack<int> st;
int bsearch(vector<int> &v, int l, int r, int key) {
    while(r-l>1)
    {
    	int m =l+(r-l)/2;
    	if(v[m]>=key)
    		r=m;
    	else
    		l=m;
    	
	}
	return r; 
}

int main()
{
//	ofstream file;
//	file.open("output.txt");
	int n,test;
	int counter=0;
	while(scanf("%d",&test)!=EOF)
	{
		v.insert(v.end(),test);
		par.insert(par.end(),counter++);
	}
	
	bend.insert(bend.begin(),v[0]);
	temp.insert(temp.end(),0);

	for(int i=1;i<v.size();i++)
	{
		if(v[i]<bend[0])
		{
			
			bend[0]=v[i];
			par[i]=i;
			temp[0]=i;
			
		}
		else if(v[i] > bend[bend.size()-1])
		{
			
			bend.insert(bend.end(),v[i]);
			temp.insert(temp.end(),i);
			par[i]=temp[temp.size()-2];
		
		}
		else
		{
				int ind=bsearch(bend,0,bend.size()-1,v[i]);
				
				temp[ind]=i;
				par[i]=temp[ind-1];
				bend[ind]=v[i];
						
		}
		
	}
	int ind= temp[temp.size()-1];
	while(true)
	{
		st.push(v[ind]);
		if(par[ind] == ind)
			break;
		ind= par[ind];
	}
	
	cout<<bend.size()<<endl;
	cout<<"-"<<endl;
//	file<<bend.size()<<endl;
//	file<<"-"<<endl;
	while(!st.empty())
		{
			printf("%d\n",st.top());
		//	file<<st.top()<<endl;
			st.pop();
		}	
}
