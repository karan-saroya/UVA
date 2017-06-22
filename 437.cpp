#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
struct obj
{
	int l;
	int b;
	int h;
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
			if(o1.b<o2.b)
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
vector<obj> v,width;
vector<int> dp,dpd;
int main()
{
	//ofstream file;
	//file.open("output.txt");
	int cases=1;
	while(true)
	{
		
		int test,n;
		cin>>n;
		if(n == 0)
			break;
		int a,c,d;
		int l,b,h;
		for(int j=0;j<n;j++)
		{
			cin>>a>>c>>d;
			if(a<=c)
			{
				if(d>=c)
				{
					l=a;
					b=c;
					h=d;
				}
				else
				{
					if(a<=d)
					{
						l=a;
						b=d;
						h=c;
					}
					else
					{
						l=d;
						b=a;
						h=c;
					}
				}
			}
			else
			{
				if(d>=a)
				{
					l=c;
					b=a;
					h=d;
				}
				else
				{
					if(c<=d)
					{
						l=c;
						b=d;
						h=a;
					}
					else
					{
						l=d;
						b=c;
						h=a;
					}
				}
				
			}
			obj o;
			o.l=l;
			o.b=b;
			o.h=h;
			obj o2;
			o2.l=l;
			o2.b=h;
			o2.h=b;
			obj o3;
			o3.l=b;
			o3.b=h;
			o3.h=l;
			
			v.insert(v.end(),o);
			v.insert(v.end(),o2);
			v.insert(v.end(),o3);
					
			
		}
		quickl(0,v.size()-1,v);
		n=3*n;
		for(int j=0;j<n;j++)
		{
			dp.insert(dp.end(),v[j].h);
		}
		
		int max=v[0].h;
		for(int j=1;j<n;j++)
		{
			for(int k=j-1;k>=0;k--)
			{
				if(v[j].l>v[k].l &&v[j].b > v[k].b && dp[k] +v[j].h > dp[j] )
				{
					dp[j] = dp[k] +v[j].h;			
				}
			}
			if(dp[j] > max)
				max= dp[j];
		}
		
		cout<<"Case "<<cases<<": maximum height = "<<max<<endl;	
	//	file<<"Case "<<cases<<": maximum height = "<<max<<endl;	
		v.clear();
		dp.clear();
		dpd.clear();
		width.clear();
		cases++;
	}
}
