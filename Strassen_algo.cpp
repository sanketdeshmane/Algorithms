#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void accept(int**, int);
void display(int**, int);
int** add(int**, int**, int);
int** sub(int**, int**, int);
int** strassen(int**,int**,int);
void accept(int**A,int size1)
{
	for(int i=0;i<size1;i++)
	{
		for(int j=0;j<size1;j++)
		{
			cin>>A[i][j];                                //Accepting matrix from user
		}
	}
}
void display(int**A, int size1)
{
    for(int i=0;i<size1;i++)
	{
		for(int j=0;j<size1;j++)
		{
			cout<<A[i][j]<<"\t";                               //Displaying matrix on screen
		}
		cout<<"\n";
	}
}
int** add(int**A, int**B, int size1)
{
	int**c = new int*[size1];
	for(int i=0; i<size1;i++)
	c[i]= new int[size1];
	for(int i=0;i<size1;i++)
	{
		for(int j=0;j<size1;j++)
		{
			c[i][j] = A[i][j] + B[i][j];                               //adding two matrices
		}
	}
	return c;
}
int** sub(int**A, int**B, int size1)
{
    int**c = new int*[size1];
	for(int i=0; i<size1;i++)
	c[i]= new int[size1];
	for(int i=0;i<size1;i++)
	{
		for(int j=0;j<size1;j++)
		{
			c[i][j] = A[i][j] - B[i][j];                               //substracting two matrices
		}
	}
	return c;	
}
int** strassen(int**A, int**B, int size1)
{
	if(size1==2)
	{
		int**c = new int*[size1];
		for(int i=0;i<size1;i++)
		    c[i]=new int[size1];
		int p,q,r,s,t,u,v;
	    p=(A[0][0]+A[1][1])*(B[0][0]+B[1][1]);
		q=(A[1][0]+A[1][1])* B[0][0];
		r=(B[0][1]-B[1][1])* A[0][0];
		s= (B[1][0]-B[0][0])*A[1][1];
		t= (A[0][0]+A[0][1])* B[1][1];
		u= (A[1][0]-A[0][0])*(B[0][0]+B[0][1]);
		v=(A[0][1]-A[1][1])*(B[1][0]+B[1][1]);
		
		c[0][0] = p+s-t+v;
		c[0][1] = r+t;
		c[1][0] = q+s;
		c[1][1] = p+r-q+u;
		
		return c;
	}
	else{
	
	int**C = new int*[size1];
	for(int i=0;i<size1;i++)       //result will be stored in C matrix
		C[i]=new int[size1];
	
	int**A11 = new int*[size1/2];
	int**A12 = new int*[size1/2];     //A sub matrices ie. dividing A matrix into 4 matrices
	int**A21 = new int*[size1/2];
	int**A22 = new int*[size1/2];
	
	int**B11 = new int*[size1/2];
	int**B12 = new int*[size1/2];     //B sub matrices ie. dividing B matrix into 4 matrices
	int**B21 = new int*[size1/2]; 
	int**B22 = new int*[size1/2];
	
	int**C11 = new int*[size1/2];
	int**C12 = new int*[size1/2];     //C sub matrices ie. dividing C matrix into 4 matrices
	int**C21 = new int*[size1/2]; 
	int**C22 = new int*[size1/2];
	
	int**P1 = new int*[size1/2];
	int**P2 = new int*[size1/2];
	int**P3 = new int*[size1/2];
	int**P4 = new int*[size1/2];
	int**P5 = new int*[size1/2];
	int**P6 = new int*[size1/2];
	int**P7 = new int*[size1/2];
	
	for(int i =0 ; i< (size1/2)	; i++)
	{
	    A11[i] = new int[size1/2];
	    A12[i] = new int[size1/2];
	    A21[i] = new int[size1/2];
	    A22[i] = new int[size1/2];
	    
	    B11[i] = new int[size1/2];
	    B12[i] = new int[size1/2];
	    B21[i] = new int[size1/2];
	    B22[i] = new int[size1/2];
	    
	    C11[i] = new int[size1/2];
	    C12[i] = new int[size1/2];
	    C21[i] = new int[size1/2];
	    C22[i] = new int[size1/2];
	    
	    P1[i] = new int[size1/2];
	    P2[i] = new int[size1/2];
	    P3[i] = new int[size1/2];
	    P4[i] = new int[size1/2];
	    P5[i] = new int[size1/2];
	    P6[i] = new int[size1/2];
	    P7[i] = new int[size1/2];
   }
	  for(int i=0;i<(size1/2); i++)
	  {
	     for(int j=0;j<(size1/2); j++)
		 {
		 	A11[i][j]=A[i][j];
		 	A12[i][j]=A[i][j+size1/2];
		 	A21[i][j]=A[i+size1/2][j];
		 	A22[i][j]=A[i+size1/2][j+size1/2];
		 	
		 	B11[i][j]=A[i][j];
		 	B12[i][j]=A[i][j+size1/2];
		 	B21[i][j]=A[i+size1/2][j];
		 	B22[i][j]=A[i+size1/2][j+size1/2];
		 	
	     }	
	  } 
	  P1 = strassen(add(A11,A22,size1/2),add(B11,B22,size1/2),size1/2);                              //P1 = (A11+A22)*(B11+B22)
	  P2 = strassen(add(A21,A22,size1/2),B11,size1/2);                                       //Q= (A21,A22)*B11
	  P3 = strassen(sub(B12,B22,size1/2),A11,size1/2);                                        //R = A11*(B12-B22)
	  P4 = strassen(sub(B21,B11,size1/2),A22,size1/2);                                                //S = A22(B21-B11)
	  P5 = strassen(add(A11,A12,size1/2),B22,size1/2);                                        //T = (A11+A12)*B22
	  P6 = strassen(sub(A21,A11,size1/2),add(B11,B12,size1/2),size1/2);                       //U = (A21-A11)*(B11+B12)
	  P7 = strassen(sub(A12,A22,size1/2),add(B21,B22,size1/2),size1/2);                       //V = (A12-A22)*(B21+B22)
	  
	  C11= add(P1,add(P4,sub(P7,P5,size1/2),size1/2),size1/2);		//C1= P1 + P4 - P5 + P7
	  C12= add(P4,P5,size1/2);		                                //C2= P3 + P5
	  C21= add(P2,P4,size1/2);		                                //C3= P2 +P4
	  C22= add(P1,add(P3,sub(P6,P2,size1/2),size1/2),size1/2);		//C4 = P1 + P3 - P2 + P6
	  
	  for(int i=0;i<size1/2;i++)
	  {
	  	for(int j=0;j<size1/2;j++)
	  	{
	  		C[i][j]= C11[i][j];
		    C[i][j+size1/2]=C12[i][j];
			C[i+size1/2][j]=C21[i][j];
			C[i+size1/2][j+size1/2]=C22[i][j];
		}
	  }
	  return C;
	}
}
int main(int argc, char** argv) {
	int **A, **B, **C, size1, x;
	do{
		cout<<"Enter your choice\n 1.Accept matrices \n 2.Display matrices \n 3.Strassens Multiplication \n 4.Exit";
		cin>>x;
		switch(x)
		{
			case 1 : cout<<"Enter size of matrix  :";
			         cin>>size1;
			         A = new int*[size1];
			         B = new int*[size1];
			         C = new int*[size1];
			         for(int i=0; i<size1; i++)
			         {
			         	A[i]=new int[size1];
			         	B[i]=new int[size1];
			         	C[i]=new int[size1];
					 }
					 cout<<"\nEnter values in 1st matrix\n";
					 accept(A,size1);
					 cout<<"\nEnter values in 2nd matrix\n";
					 accept(B,size1);
			         break;
			case 2 : cout<<"1st matrix is\n";
			         display(A,size1);
			         cout<<"\n2nd matrix is\n";
			         display(B,size1);
				     break;
			case 3 : C = strassen(A,B,size1);
			         cout<<"\nMultiplication of two matrices is : \n";
			         display(C,size1);
				     break;
		}
	}while(x!=4);
	return 0;
}

/* 
Enter your choice
 1.Accept matrices
 2.Display matrices
 3.Strassens Multiplication
 4.Exit1
Enter size of matrix  :4

Enter values in 1st matrix
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1

Enter values in 2nd matrix
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
Enter your choice
 1.Accept matrices
 2.Display matrices
 3.Strassens Multiplication
 4.Exit2
1st matrix is
1       1       1       1
1       1       1       1
1       1       1       1
1       1       1       1

2nd matrix is
1       1       1       1
1       1       1       1
1       1       1       1
1       1       1       1
Enter your choice
 1.Accept matrices
 2.Display matrices
 3.Strassens Multiplication
 4.Exit3

Multiplication of two matrices is :
4       4       4       4
4       4       4       4
4       4       4       4
4       4       4       4
Enter your choice
 1.Accept matrices
 2.Display matrices
 3.Strassens Multiplication
 4.Exit1
Enter size of matrix  :2

Enter values in 1st matrix
1
2
3
4

Enter values in 2nd matrix
1
2
3
4
Enter your choice
 1.Accept matrices
 2.Display matrices
 3.Strassens Multiplication
 4.Exit2
1st matrix is
1       2
3       4

2nd matrix is
1       2
3       4
Enter your choice
 1.Accept matrices
 2.Display matrices
 3.Strassens Multiplication
 4.Exit3

Multiplication of two matrices is :
7       10
15      22
Enter your choice
 1.Accept matrices
 2.Display matrices
 3.Strassens Multiplication
 4.Exit
 */
