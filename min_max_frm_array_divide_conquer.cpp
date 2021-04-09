
#include<iostream>
#include<bits/stdc++.h>>
using namespace std;

class xyz
{
    private: 
    int Arr[30]; 

    public: 
    void accept(int);
    void minmax(int i,int j, int &max, int &min);
};
void xyz::accept(int n)
{
        for(int i=0;i<n;i++)
        {
            cin>>Arr[i];
        }
}
void xyz::minmax(int i, int j, int &max, int &min)
{
	if(i==j)  // single number in array
        {
            max=min=Arr[i];
            return ;
        }
 
        else if(i==j-1) // two number in array
        {
            if(Arr[i]>=Arr[j])
            {
                max=Arr[i];
                min=Arr[j];
            }
            else 
            {
                min=Arr[i];
                max=Arr[j];
            }
            return ;
        }
        else
        {
            int mid,max1= INT_MIN, min1= INT_MAX;
            mid=(i+j)/2;
            minmax(i, mid, max, min); 
            minmax(mid+1,j,max1,min1);

            if(max<max1)
            {
               max=max1; // Implicit de-referencing (without '*')
            }
            if(min>min1)
            {
               min=min1; 
            }
            
        }
        return;
}


int main()
{
    class xyz x;
    int size, max=INT_MIN, min=INT_MAX ; 

    cout<<"Enter size of array - ";
    cin>>size;
    cout<<endl;

    cout<<"Enter Array \n"<<endl;
    x.accept(size);

    
    x.minmax(0,size-1,max,min);

    cout<<"\nMaximum value is - "<<max<<endl;
    cout<<"Minimum value is - "<<min<<endl;

    return 0;
}

/*
Enter size of array - 4

Enter Array

156
2
6
78

Maximum value is - 156
Minimum value is - 2


*/

