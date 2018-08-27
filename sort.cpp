/*************************************************************************
    > File Name: src/sort.cpp
    > Author: sicaolong
    > Mail: sicaolong4@163.com 
    > Created Time: 2018年08月27日 星期一 11时33分28秒
 ************************************************************************/

//#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void BubbleSort(vector<int>&nums)
{
	int n=nums.size();
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(nums[j]>nums[j+1])
				swap(nums[j],nums[j+1]);
		}
	}
}

void SelectSort(vector<int>&nums)
{
	int n=nums.size();
	for(int i=0;i<n;i++)
	{
		int min_index=i;
		for(int j=i;j<n;j++)
		{
			if(nums[j]<nums[min_index])
				min_index=j;
		}
		swap(nums[i],nums[min_index]);
	}
}
void InsertionSort(vector<int>&nums)
{
	int n=nums.size();
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(nums[i]<nums[j])
			{
				int temp=nums[i];
				for(int k=i;k>j;k--)
					nums[k]=nums[k-1];
				nums[j]=temp;
				break;
			}
		}

	}
}
//4
//快速排序 三个函数；
//1、公共接口
//2、分治的思想
//求出每一个值应该处于第几个索引位置；
//找到pivot的索引位置；
int partition(vector<int>&nums,int left,int right)
{
	if(left>right)
		return left;
	int key=nums[left];
	while(left<right)
	{
		while(left<right&&nums[right]>=key)
			right--;
		swap(nums[right],nums[left]);
		while(left<right&&nums[left]<=key)
			left++;
		swap(nums[left],nums[right]);
	}
	return left;
}
//分治的思想；
void quick_sort(vector<int>&nums,int left,int right)
{
	if(left>=right)
		return ;
	int pivot=partition(nums,left,right);
	quick_sort(nums,left,pivot-1);
	quick_sort(nums,pivot+1,right);
}
void QuickSort(vector<int>&nums)//首先这个写成通用接口；
{
	int n=nums.size();
	int left=0;
	int right=n-1;
	quick_sort(nums,left,right);
}
//5 归并排序 3个函数 
//1、公共接口
//2、分制
//3、归并
void meger(vector<int>&nums,vector<int>&temp,int start1,int end1,int start2,int end2 )
{
	int left=start1;
	int right=start2;
	int index=0;
	while(left<=end1&&right<=end2)
	{
		if(nums[left]<=nums[right])
			temp[index++]=nums[left++];
		else 
			temp[index++]=nums[right++];
	}
	while(left<=end1)
			temp[index++]=nums[left++];
	while(right<=end2)
		temp[index++]=nums[right++];
	for(int i=0;i<index;i++)
		nums[start1+i]=temp[i];
}
void meger_sort(vector<int>&nums,vector<int>&temp,int left,int right)
{
	if(left>=right)
		return ;
	int mid=(right-left)/2+left;
	meger_sort(nums,temp,left,mid);
	meger_sort(nums,temp,mid+1,right);
	meger(nums,temp,left,mid,mid+1,right);
}
void MegerSort(vector<int>&nums)
{
	int n=nums.size();
	int left=0;
	int right=n-1;
	vector<int>temp(n);
	meger_sort(nums,temp,left,right);
}
//希尔排序
void shell_sort(vector<int>&nums)
{
	int n=nums.size();
	
	for(int gap=n/2;gap>0;gap/=2)
	{
		for(int i=gap;i<n;i++)
		{
			for(int j=i-gap;j>=0&&nums[j]>nums[j+gap];j-=gap)
				swap(nums[j],nums[j+gap]);
		}
	}

}
int main()
{
	vector<int>nums1={
		3,6,9,2,5,8,1,4,7
	};
	vector<int>nums2={
		3,6,9,2,5,8,1,4,7
	};
	vector<int>nums3={
		3,6,9,2,5,8,1,4,7
	};
	vector<int>nums4={
		3,6,9,2,5,8,1,4,7
	};
	vector<int>nums5={
		3,6,9,2,5,8,1,4,7
	};
	vector<int>nums6={
		3,6,9,2,5,8,1,4,7
	};
	BubbleSort(nums1);
	SelectSort(nums2);
	InsertionSort(nums3);
	QuickSort(nums4);
	MegerSort(nums5);
	shell_sort(nums6);
	cout<<"冒泡排序结果如下:";
	for(auto i:nums1)
		cout<<i<<" ";
	cout<<endl;
	cout<<"选择排序如下：";
	for(auto i:nums2)
		cout<<i<<" ";
	cout<<endl;
	cout<<"插入排序如下";
	for(auto i:nums3)
		cout<<i<<" ";
	cout<<endl;
	cout<<"快速排序如下";
	for(auto i:nums4)
		cout<<i<<" ";
	cout<<endl;
	cout<<"归并排序如下";
	for(auto i:nums5)
		cout<<i<<" ";
	cout<<endl;
	cout<<"希尔排序如下";
	for(auto i:nums6)
		cout<<i<<" ";
	cout<<endl;


}
