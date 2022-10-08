#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr, int start, int mid, int end)
{
	int k=0;
	int i=start;
	int j=mid+1;
	int n=end-start+1;
	vector<int> temp(n);
	while(i<=mid && j<=end)
	{
		if(arr[i]<=arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=end)
	{
		temp[k++]=arr[j++];
	}
	for(int p=start; p<=end; p++)
	{
		arr[p]=temp[p-start];
	}
}
void merge_sort(vector<int>& nums, int start, int end)
{
	if(start>=end)
	{
		return;
	}
	int mid=(start+end)/2;
	merge_sort(nums,start,mid);
	merge_sort(nums,mid+1,end);
	merge(nums,start,mid,end);
}
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	merge_sort(arr,0,n-1);
	for(auto x: arr)
	{
		cout<<x<<" ";
	}



}
