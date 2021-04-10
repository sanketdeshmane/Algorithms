#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool place_queen(int x[], int k, int col);
void display_board(int x[], int size);
void Nqueen_r(int x[],int size, int k)     //you can assume k as row no also
{
	for(int col=0;col<size;col++)
	{
		if(place_queen(x,k,col))
		{
			x[k]=col;
			if(k==size-1)
			{
				display_board(x,size);
				return;	
			}
			Nqueen_r(x,size,k+1);
		}
	}
}

void display_board(int x[], int size)
{
	cout<<"Chess board \n";
	for(int i=0; i<size; i++)
	{
		int col = x[i];
		for(int j=0; j<size; j++)
		{
			if(j==col)
			{
				cout<<"Q\t";
			}
			else
			{
				cout<<"-\t";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}
bool place_queen(int x[], int k, int col)
{
	for(int i=0;i<k;i++)
	{
		if(x[i]==col || abs(k-i)==abs(x[i]-col))
			return false;
	}
	return true;
}

int main(int argc, char** argv) {
	int choice,size,ar[80];
	do{
	  cout<<"Enter your choice\n";
	  cout<<"1.Enter the size of chessboard\n";
	  cout<<"2.Display the resulting chessboard(Backtracking)\n";
	  cout<<"3.Exit programme";
	  cin>>choice;
	  switch(choice)
	  {
	  	case 1 :  cout<<"Enter size\n";
		          cin>>size;
	  	          break;
	  	case 2  : Nqueen_r(ar,size,0);
	  	          break;
	    }	
	}while(choice!=3);
	return 0;
}
