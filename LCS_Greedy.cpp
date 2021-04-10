/*4) Write a program to implement longest common subsequence (Dynamic Programming) */

#include <iostream>
#include<bits/stdc++.h> 
using namespace std;


int max(int a, int b);

int lcs(char *a, char *b, int m, int n)
{ 
   int arr[m+1][n+1];
   for(int i=0;i<=m;i++)
   {
   	  for(int j=0; j<=n;j++)
   	  {
   	    if( i==0 || j==0 )
	    {
		  arr[i][j]=0;
		}
		else if( a[i-1] == b[j-1])	
		{
			arr[i][j]=arr[i-1][j-1] + 1; 
		}
		else
		{
			arr[i][j]= max(arr[i-1][j],arr[i][j-1]);
		}
	  }
   }
   
   return arr[m][n];	
}

int max(int a, int b)
{
	if(a>b)
	  return a;
	else
	return b;
}

int main(int argc, char** argv) {
	char x[20], y[20];
	cout<<"\nEnter the first string  :";
	cin>>x;
	cout<<"\nEnter the second string  :";
	cin>>y;
	int p,q;
	p = strlen(x);
	q = strlen(y);
	
	cout<<"Lenth of LCS is : "<<lcs(x,y,p,q);
	return 0;
}
/*

Enter the first string  :abdace

Enter the second string  :babce
Lenth of LCS is : 4
*/
