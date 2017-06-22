#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<stack>
using namespace std;
struct obj
{
	int l;
	int m;
	int index;
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
bool is_great(obj o1,obj o2)
{
	int l1=o1.l;
	int l2=o2.l;
	if(l1>l2)
		return true;
	else
	{
		if(l1==l2)
		{
			if(o1.m>o2.m)
				return true;
			else
				return false;
		}
		else
			return false;
	}
}

int partg(int left,int right,vector<obj> &vec)
{
	obj pivot = vec[right];
	int index=left;
	for(int i=left;i<right;i++)
	{
		if(is_great(vec[i],pivot))
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

void quickg(int left, int right, vector<obj> &v)
{
	if(left<right)
	{
		int r = partg(left,right,v);
		quickg(left,r-1,v);
		quickg(r+1,right,v);
	}
}
vector<obj> vec,vec2;
vector<int> dp1,dp2,par1,par2,index;

int main()
{
//	ofstream file;
//	file.open("output.txt");
	int w,q;
	int n=0;
	while(scanf("%d%d",&w,&q)!= EOF)
	{
		obj o;
		o.l=w;
		o.m=q;
		o.index=n;
		vec.insert(vec.end(),o);
		obj o2;
		o2.l=q;
		o2.m=w;
		
		o2.index=n;
		vec2.insert(vec2.end(),o2);
		dp1.insert(dp1.end(),1);
		dp2.insert(dp2.end(),1);
		par1.insert(par1.end(),n);
		par2.insert(par2.end(),n);
		n++;
		
	}
	
	quickl(0,vec.size()-1,vec);
	quickg(0,vec2.size()-1,vec2);
/*	for(int i=0;i<n;i++)
	{
		cout<<vec[i].l<<" "<<vec[i].m<<"   ";
	}
	cout<<endl;
	
	for(int i=0;i<n;i++)
	{
		cout<<vec2[i].l<<" "<<vec2[i].m<<"   ";
	}
	cout<<endl;
*/	
	int max=1;
	int ind=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(vec[j].m >vec[i].m && dp1[j] +1 > dp1[i])
			{
				dp1[i]=dp1[j]+1;
				par1[i]=j;
			}
		}
		if(dp1[i] > max)
			{
				max= dp1[i];
				ind=i;
			}
	}
	int max2=1;
	int ind2=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(vec2[j].m < vec2[i].m && dp2[j] +1 > dp2[i])
			{
				dp2[i]=dp2[j]+1;
				par2[i]=j;
			}
		}
		if(dp2[i] > max2)
			{
				max2= dp2[i];
				ind2=i;
			}
	}
	stack<int> st;
//		file<<((max>max2)?max2:max)<<endl;
	cout<<((max>max2)?max2:max)<<endl;
	if(max < max2)
	{
		while(true)
		{
			st.push(vec[ind].index+1);
			if(ind == par1[ind])
				break;
			ind = par1[ind];
		}
	}
	else
	{
		while(true)
		{
			st.push(vec2[ind2].index+1);
			if(ind2 == par2[ind2])
				break;
			ind2 = par2[ind2];
		}
	}
	while(!st.empty())
	{
		cout<<st.top()<<endl;
	//	file<<st.top()<<endl;
		st.pop();
	}

	
}
