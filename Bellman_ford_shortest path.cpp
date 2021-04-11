#include <iostream>
#include<bits/stdc++.h>
using namespace std;

 #define INFINITY 9999
class bellman_ford
{
	int v,e;
	int *dist, *from;
	int **G;
	public:
		bellman_ford();
		void accept_graph();
		void display_graph();
		int Bellman_ford_algo();
};
bellman_ford::bellman_ford()
{
	cout<<"Enter no of vertices";
	cin>>v;
	dist = new int[v];
	from = new int[v];
	G = new int*[v];
	for(int i=0;i<v;i++)
	   G[i]=new int[v];
	
	for(int i=0; i<v; i++)
	{
		for(int j=0;j<v;j++)
		{
			G[i][j]=0;
		}
	}
}
void bellman_ford::accept_graph()
{
	int source,desti,weight;
	
	cout<<"\nEnter no of edges :  ";
	cin>>e;
	cout<<"\nEnter the edges\n";
	for(int i=0; i<e; i++)
	{
		cout<<"\nEnter the source  :  ";
		cin>>source;
		cout<<"\nEnter the desti   :  ";
		cin>>desti;
		cout<<"\nEnter the weight  :  ";
		cin>>weight;
		G[source][desti]=weight;
	}
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			if(G[i][j]==0 && i!=j)
			{
				G[i][j]= INFINITY;
			}
		}
		dist[i]= INFINITY;
	}
}
void bellman_ford::display_graph()
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<G[i][j]<<"\t";
		}
		cout<<endl;
	}	
}
int bellman_ford::Bellman_ford_algo()
{
    int infinite=INFINITY;
	int src;
	cout<<"Enter the source\n";
	cin>>src;
	for(int i=0;i<v;i++)
		from[i]=src;
	dist[src]=0;
	
	for(int i=1;i<v;i++)	//i:=1:vertices-1
	{
		for(int j=0;j<v;j++)	//select an edge
		{
			for(int k=0;k<v;k++)
			{
				if(G[j][k]!=infinite || j!=k)		//existing edge and no self loops
				{
					if(dist[k]>dist[j]+ G[j][k])		//relaxation
					{
						dist[k]=dist[j]+G[j][k];
						from[k]=j;
					}
				}
			}
		}
	}
		for(int j=0;j<v;j++)	//select an edge
		{
			for(int k=0;k<v && k!=j;k++)
			{
				if(G[j][k]!=infinite)
				{
					if(dist[k]>dist[j]+ G[j][k])		//negative cycle is detected
						return -1;
				}
			}
		}
		
		for(int i=0;i<v;i++)
		{
			cout<<"Distance of "<<i<<" is "<<dist[i]<<"\n";
			cout<<"Path is:";
			int k=i;
			do
			{
				int j=from[k];
				if(j==0)
				cout<<j<<endl;
				else
				cout<<j<<"<-";
				k=j;
			}while(k!=from[k]);
		}
	return 0;
}  
int main(int argc, char** argv) {
	bellman_ford bf;
	int choice;
	do
	 {
		cout<<"Enter your choice \n 1.Enter graph(adj matrix) \n 2.Display the graph(adj matrix) \n 3.Calculate shortest path using Bellman-Ford Algorithm\n 4.Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1: bf.accept_graph();
					break;
					
			case 2: bf.display_graph();
					break;
					
			case 3: bf.Bellman_ford_algo();
					break; 
	    }
	}while(choice !=4);
	return 0;
}

/*Enter no of vertices7
Enter your choice
 1.Enter graph(adj matrix)
 2.Display the graph(adj matrix)
 3.Calculate shortest path using Bellman-Ford Algorithm
 4.Exit
1

Enter no of edges :  10

Enter the edges

Enter the source  :  0

Enter the desti   :  1

Enter the weight  :  6

Enter the source  :  0

Enter the desti   :  2

Enter the weight  :  5

Enter the source  :  0

Enter the desti   :  3

Enter the weight  :  5

Enter the source  :  3

Enter the desti   :  2

Enter the weight  :  -2

Enter the source  :  2

Enter the desti   :  1

Enter the weight  :  -2

Enter the source  :  1

Enter the desti   :  4

Enter the weight  :  -1

Enter the source  :  2

Enter the desti   :  4

Enter the weight  :  1

Enter the source  :  3

Enter the desti   :  5

Enter the weight  :  -1

Enter the source  :  4

Enter the desti   :  6

Enter the weight  :  3

Enter the source  :  5

Enter the desti   :  6

Enter the weight  :  3
Enter your choice
 1.Enter graph(adj matrix)
 2.Display the graph(adj matrix)
 3.Calculate shortest path using Bellman-Ford Algorithm
 4.Exit
2
0       6       5       5       9999    9999    9999
9999    0       9999    9999    -1      9999    9999
9999    -2      0       9999    1       9999    9999
9999    9999    -2      0       9999    -1      9999
9999    9999    9999    9999    0       9999    3
9999    9999    9999    9999    9999    0       3
9999    9999    9999    9999    9999    9999    0
Enter your choice
 1.Enter graph(adj matrix)
 2.Display the graph(adj matrix)
 3.Calculate shortest path using Bellman-Ford Algorithm
 4.Exit
3
Enter the source
0
Distance of 0 is 0
Path is:0
Distance of 1 is 1
Path is:2<-3<-0
Distance of 2 is 3
Path is:3<-0
Distance of 3 is 5
Path is:0
Distance of 4 is 0
Path is:1<-2<-3<-0
Distance of 5 is 4
Path is:3<-0
Distance of 6 is 3
Path is:4<-1<-2<-3<-0
Enter your choice
 1.Enter graph(adj matrix)
 2.Display the graph(adj matrix)
 3.Calculate shortest path using Bellman-Ford Algorithm
 4.Exit
*/

