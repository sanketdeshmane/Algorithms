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
