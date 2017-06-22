#include<iostream>
using namespace std;
int imax=1,size,arr[100];
void LIS(string path,int prev, int curr_index,int curr_size)
{
	if(curr_index == size)
	{
		if(curr_size>imax)
			imax = curr_size;
	}
	else
	{
		for(int i=curr_index+1;i<size;i++)
		{
			if(arr[i] >= prev)
			{
				curr_size++;
				if(curr_size > imax)
					imax = curr_size;
				LIS(path +" "+to_string(arr[i]),arr[i],i,curr_size);
			}
		}
	}
}
int main()
{
	cin>>size;
	for(int i=0;i<size;i++)
		cin>>arr[i];
	for(int i=0;i<size;i++)
		LIS(to_string(i)+"",arr[i],i,1);
	cout<<imax<<endl;
}
