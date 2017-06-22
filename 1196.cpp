#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
struct obj
{
	int l;
	int m;
};

bool is_less(obj o1,obj o2)
{
	int l1=o1.l;
	int l2=o2.l;
	if(l1<l2)
		return true;
	else
	{
		if(l1==l2)
		{
			if(o1.m<o2.m)
				return true;
			else
				return false;
		}
		else
			return false;
	}
}

int part(int left,int right,vector<obj> &vec)
{
	obj pivot = vec[right];
	int index=left;
	for(int i=left;i<right;i++)
	{
		if(is_less(vec[i],pivot))
		{
			obj temp=vec[i];
			vec[i]=vec[index];
			vec[index]=temp;
			index++;
			
		}
	}
			obj temp=vec[right];
			vec[right]=vec[index];
			vec[index]=temp;
			
	return index;
	
}
void quick(int left, int right, vector<obj> &v)
{
	if(left<right)
	{
		int r = part(left,right,v);
		quick(left,r-1,v);
		quick(r+1,right,v);
	}
}
int bsearch(vector<int> &v, int l, int r, int key) {
    while(r-l>1)
    {
    	int m =(r+l)/2;
    	if(v[m]>=key)
    		r=m;
    	else
    		l=m;
    	
	}
	return r; 
}
vector<obj> vec;
vector<int> v,lis;
int main()
{
	int n;
//	ofstream file;
//	file.open("output.txt");
	while(true)
	{
		cin>>n;
		if(n == 0)
		{
			cout<<"*"<<endl;
			//file<<"*"<<endl;
			break;
		}	
		int l,m;
		for(int i=0;i<n;i++)
		{
			cin>>l;
			cin>>m;
			obj o;
			o.l=l;
			o.m=m;
			vec.insert(vec.end(),o);
		}
		quick(0,vec.size()-1,vec);
		for(int i=0;i<vec.size();i++)
		{
			v.insert(v.end(),vec[i].m);
		}
		for(int i=0;i<vec.size();i++)
		{
			v.insert(v.end(),vec[i].m);
		}
		lis.insert(lis.begin(),v[0]);
		for(int i=1;i<n;i++)
		{
			/*cout<<"Index is : "<<i<<endl;
			for(int j=0;j<lis.size();j++)
				cout<<lis[j]<<" ";
			cout<<endl;
			*/
			if(v[i] <= lis[0])
			{
				if(v[i] == lis[0])
				{
					int ind=bsearch(lis,-1,lis.size(),v[i]+1);
					if(ind >= lis.size())
					{
						lis.insert(lis.end(),v[i]);
					}
					else
						lis[ind]=v[i];
				}
				else
					lis[0] =v[i];
			}
			else if(v[i] >= lis[lis.size()-1])
			{
				
				lis.insert(lis.end(),v[i]);
			}
			else
			{
				int ind=bsearch(lis,-1,lis.size(),v[i]);
				if(lis[ind] == v[i])
				{
					int ind2=	bsearch(lis,-1,lis.size(),v[i]+1);
					lis[ind2]=v[i];
				}
				else
					lis[ind]=v[i];
				
			}
		/*	for(int j=0;j<lis.size();j++)
				cout<<lis[j]<<" ";
			cout<<endl;
		*/
		}
	
		cout<<lis.size()<<endl;
	//	file<<lis.size()<<endl;
		
		v.clear();
		lis.clear();
		vec.clear();
	}
	
}
