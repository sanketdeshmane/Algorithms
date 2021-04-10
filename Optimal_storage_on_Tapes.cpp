//3) Write a program to implement optimal storage tape using greedy approach.
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void findOrder(int l[], int n)
{
	sort(l,l+n);
	
	cout<<"\nOptimal order in which programs are stored is(according to size)  :";
	for(int i=0; i<n; i++)
	   cout<<l[i]<<"\t";
	
	int mrt=0;
	
	for(int i=0; i<n; i++)
	{
		int sum = 0;
		for(int j=0;j<=i;j++)
		{
			sum = sum + l[j];
			
		}
		mrt+= sum;
	}
	cout << "\nMean Retrieval Time of this order is " << mrt;
}
int main(int argc, char** argv) 
{
	int list[20],n;
	cout<<"Enter no of programmes";
	cin>>n;
	cout<<"Enter the prgram size of each programme\n";
	for(int i=0;i<n;i++)
	  cin>>list[i];
	
	findOrder(list,n);
	return 0;
}
/*
Enter no of programmes4
Enter the prgram size of each programme
2
3
5
6

Optimal order in which programs are stored is(according to size)  :2    3       5       6
Mean Retrieval Time of this order is 33
*/
