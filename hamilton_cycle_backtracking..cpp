#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class hamilton_cycle{
	int v,e;                           //vertices,edges
	int **G;                            //adjacency matrix
	int *x;                             //array
	bool next_node(int,int);
	
	public : 
	hamilton_cycle();
	void accept();
	void display();
	void hamilton_path();
};
hamilton_cycle::hamilton_cycle()
{
	cout<<"Enter no of vertices in graph";
	cin>>v;
	G= new int* [v];
	x = new int [v];
	for(int i=0;i<v;i++)             //allocating space to adj matrix and array    
	    G[i]=new int [v];
	
	for(int i=0; i<v; i++)
	{
		x[i]= -1;
		for(int j=0; j<v; j++)                    
		   G[i][j]=0;
	}
}
void hamilton_cycle::accept()
{
	int src,des;
	cout<<"Enter the number of edges\n";
	cin>>e;
	cout<<"Enter the edges\n";
	for(int i=0;i<e;i++)
	{
		cout<<"Enter the source\n";
		cin>>src;
		cout<<"Enter the destination\n";
		cin>>des;
		G[src][des]=1;                                  //accept adj matrix
		G[des][src]=1;		
	}
}
void hamilton_cycle::display()
{
	for(int i=0; i<v;i++)
	{
		for(int j=0; j<v; j++)
		{
			cout<<G[i][j]<<"\t";
		}
		cout<<endl;
	}
}
bool hamilton_cycle::next_node(int k, int i)
{
	for(int m=0; m<k ; m++)
	{
		if(x[m]==i)
		{
			return false;                      //check that vertice appeared before or not, if yes then return false
		}
	}
	if(k>0)
	{
		if(G[x[k-1]][i] != 1)             //check if there is edge from  previous vertex and next vertex to be added
		  return false;
	}
	if(k== v-1 && G[i][x[0]] != 1)        //if its last vertex then check weather there is edge from last vertex to start vertex
	   return false;
	return true;
}
void hamilton_cycle::hamilton_path()
{
int i,k=0;	//i represent the vertex appearing in the kth position in the path
	while(k>=0)
	{
		i=x[k]+1;		//cycle starts from 0
		while(i<v)
		{
			if (next_node(k,i))
			{
				x[k]=i;
				k++;
				if(k==v)	//if all vertices are visited
				{
					cout<<"Hamilton Cycle exits:"<<endl;
					for(int r=0;r<v;r++)
						cout<<x[r]<<"->";
					cout<<x[0]<<endl;
					return;
				}
				break;
			}
			i++;
		}
		if(i==v)		//no path found
		{
			x[k]=-1;
			k--;
		}
	}
	if(k<0)
	{
		cout<<"No cycle exists\n";
	}

}
int main(int argc, char** argv) {
	int choice;
	hamilton_cycle hc;
	do{
		cout<<"\nEmter your choice\n 1. Enter Graph(Adj. Matrix)\n 2.Display Graph\n 3.Check for Hamiltonian cycle\n 4.Exit";
		cin>>choice;
		switch(choice)
		{
		  case 1 : hc.accept();
		           break;
		  case 2 : hc.display();
		           break;
		  case 3 : hc.hamilton_path();
		           break;	
		}
	}while(choice!=4);
	return 0;
}
/*
Enter no of vertices in graph5

Emter your choice
 1. Enter Graph(Adj. Matrix)
 2.Display Graph
 3.Check for Hamiltonian cycle
 4.Exit1
Enter the number of edges
8
Enter the edges
Enter the source
0
Enter the destination
1
Enter the source
0
Enter the destination
4
Enter the source
1
Enter the destination
2
Enter the source
1
Enter the destination
3
Enter the source
1
Enter the destination
4
Enter the source
3
Enter the destination
4
Enter the source
0
Enter the destination
2
Enter the source
2
Enter the destination
3

Emter your choice
 1. Enter Graph(Adj. Matrix)
 2.Display Graph
 3.Check for Hamiltonian cycle
 4.Exit2
0       1       1       0       1
1       0       1       1       1
1       1       0       1       0
0       1       1       0       1
1       1       0       1       0

Emter your choice
 1. Enter Graph(Adj. Matrix)
 2.Display Graph
 3.Check for Hamiltonian cycle
 4.Exit3
Hamilton Cycle exits:
0->1->2->3->4->0

Emter your choice
 1. Enter Graph(Adj. Matrix)
 2.Display Graph
 3.Check for Hamiltonian cycle
 4.Exit
 */
