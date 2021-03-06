/*
  Q1.Given order of n matrices, find the minimum multiplication operations required
    for multiplying n matrices.
*/

/*
    Complexity:
    Space Complexity: O(n^2)
    Time Complexity : O(n^3)
*/

#include <iostream>

using namespace std;

void parenthesis_OP(int **m, int i, int j)
{
    if(i==j)
        cout<<" A"<<i+1<<" ";
    else
    {
        cout<<"(";
        parenthesis_OP(m,i,m[j][i]);		//RECURSIVE CALL TO PARENTHESIS_OP FUNCTION 
        parenthesis_OP(m,m[j][i]+1,j);
        cout<<")";
    }
}

matrixChain(int *p, int num)
{
	int n=num, q;

    int **m = new int*[n];
	for(int i = 0; i < n; i++)
    	m[i] = new int[n];

    for(int i=0; i<n; i++)				//INITIALISING VALUES OF DIAGONAL VALUES
        m[i][i]=0;

    for(int chain=1; chain<n; chain++)
    {
        for(int i=0, j=chain; i<(n-chain), j<n; i++, j++)
        {
            m[i][j]=99999;
            for(int k=i; k<j; k++)
            {
                q=m[i][k]+m[k+1][j]+(p[i]*p[k+1]*p[j+1]);
                if(q<m[i][j])			//CHECK CONDITION FOR SUBSTITUTING APPROPRAIATE VALUES IN THE TABLE
                {
                   m[i][j]=q;
                   m[j][i]=k;
                }
            }
        }
    }

    cout<<"\nMIN COST OF MULTIPLICATION IS "<<m[0][n-1];
    cout<<"\nORDER OF PARENTHESIS IS ";
    parenthesis_OP(m,0,n-1);
    cout<<endl;
}

int main()
{
	int num, row, col, dcount=0;

	cout<<"NO. OF MATRICES YOU WANT TO MULTIPLY  ";	//FETCHING INPUT FROM USER
	cin>>num;

	int *p = new int[num+1];

	cout<<"DIMENSION OF MATRICES \n";

	do
	{

		cout<<"No of rows of matrix ";
		cin>>row;
		p[dcount++]=row;

		cout<<"No of columns of matrix ";
		cin>>col;

		for(int i=1; i<num ; i++)
		{
			cout<<"No of rows of matrix "<<i+1<<": ";
			cin>>row;

			if(row==col)
				p[dcount++]=row;
			else
			{
				cout<<"ERROR....WRONG INPUT!!!!!\n";
				dcount=0;
				break;
			}
			cout<<"No of columns of matrix "<<i+1<<": ";
			cin>>col;
		}
	}while(dcount==0);
	p[dcount++]=col;

    matrixChain(p,num);
}	
