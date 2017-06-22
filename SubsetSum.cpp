#include<iostream>
#include<string>
using namespace std;
int value[100];
int w[100];
int size;
int tar;
int min_diff=100000000;
string best_path;
void SS(int curr_diff,int curr_index)
{
	if(curr_index == size)
	{
		if(curr_diff >=0  && curr_diff < min_diff)
			{
				min_diff = curr_diff;
			//	best_path = path;
			}
		
	}
	else
	{	
		if(curr_diff >=0  && curr_diff < min_diff)
			{
				min_diff = curr_diff;
				//best_path=path;
			}
		for(int i=curr_index;i<size;i++)
		{
			if(curr_diff - value[i]>=0)
			{
				SS(curr_diff-value[i],i+1);
			}
		}
	}
	
	
}
int main()
{
	cin>>size;
	for(int i=0;i<size;i++)
		cin>>value[i];
	cin>>tar;
	for(int i=0;i<size;i++)
		SS(tar,i,to_string(value[i]));
	cout<<min_diff<<endl;
}
