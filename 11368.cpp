#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
struct obj
{
	int w;
	int h;	
};
int bsearch(vector<int> &v,int l, int r, int key)
{
	while(r-l>1)
	{
		int m =(r+l)/2;
		if(v[m] >=  key)
			r=m;
		else
			l=m;
	}
		return r;
}
bool is_less(obj o1,obj o2)
{
	int l1=o1.w;
	int l2=o2.w;
	if(l1<l2)
		return true;
	else
	{
		if(l1==l2)
		{
			if(o1.h<o2.h)
				return true;
			else
				return false;
		}
		else
			return false;
	}
}
int partl(int left,int right,vector<obj> &vec)
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
void quickl(int left, int right, vector<obj> &v)
{
	if(left<right)
	{
		int r = partl(left,right,v);
		quickl(left,r-1,v);
		quickl(r+1,right,v);
	}
}

vector<obj> v;
vector<int> par,lis,s,is;
int main()
{
	ofstream file;
	file.open("output.txt");
 		int t;
 		cin>>t;
 		for(int l=1;l<=t;l++)
 		{
 			int n;
 			cin>>n;
 			int w,h;
 			for(int i=0;i<n;i++)
			{
				obj o;
				cin>>w;
				cin>>h;
				o.h=h;
				o.w=w;
				v.insert(v.end(),o);
				par.insert(par.end(),i);	
				
				is.insert(is.end(),0);				
			}
			quickl(0,n-1,v);
			int dolls=0;
			do
			{
				lis.insert(lis.end(),v[0].h);
				s.insert(s.begin(),0);
				for(int i=1;i<n;i++)
				{
					if(is[i] == 0)
					{
						cout<<"Index "<<i<<endl;
						for(int i=0;i<s.size();i++)
						{
							cout<<s[i]<<" ";
						}
						cout<<endl;
						cout<<"Par"<<endl;
						for(int i=0;i<par.size();i++)
						{
							cout<<par[i]<<" ";
						}
						cout<<endl;
						cout<<"Lis"<<endl;
						for(int i=0;i<lis.size();i++)
						{
							cout<<lis[i]<<" ";
						}
						cout<<endl;
						
					
						if(v[i].h < lis[0] )
						{
							lis[0]=v[i].h;
							par[i]=i;
							s[0]=i;		
						}
						else if(v[i].h > lis[lis.size()-1])
						{
							
							lis.insert(lis.end(),v[i].h);
							s.insert(s.end(),i);
							par[i]=s[s.size()-2];
						}
						else
						{
							int ind = bsearch(lis,0,lis.size()-1,v[i].h);
							cout<<"Index is"<<ind<<endl;
							if(ind == 0)
								par[i]=s[ind];
							else
								par[i] = s[ind-1];
							s[ind]=i;
							lis[ind]=v[i].h;
						}
						for(int i=0;i<s.size();i++)
						{
							cout<<s[i]<<" ";
						}
						cout<<endl;
						cout<<"Par"<<endl;
						for(int i=0;i<par.size();i++)
						{
							cout<<par[i]<<" ";
						}
						cout<<endl;
						cout<<"Lis"<<endl;
						for(int i=0;i<lis.size();i++)
						{
							cout<<lis[i]<<" ";
						}
						cout<<endl;
						
					}
				}
				if(lis.size() == 1)
					{
						for(int i=0;i<n;i++)
						{
							if(is[i] == 0)
								dolls++;
						}
						break;
					}
				else
				{
					dolls++;
				
					int ind=s[s.size()-1];
				//	cout<<ind<<endl;
					while(true)
					{
						is[ind] =1;
						if(ind == par[ind])
							break;
						ind =par[ind];
					}
			
				}
				s.clear();
				lis.clear();		
			}while(true);
			
			cout<<dolls<<endl;
			file<<dolls<<endl;
			v.clear();
			s.clear();
			lis.clear();
			is.clear();
			par.clear();
 			
		}
}
