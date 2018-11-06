
/*
	Q3.	Implement N Queen's problem using Back Tracking.
*/

/*
	Time Complexity: O(n!)
*/
#include<iostream>
using namespace std;

#define N 8				//GLOBAL VARIABLE DEFINED WITH N=8

int board[N][N];
int colcheck[N];		//CHECK FOR COLUMN INTERSECTION BETWEEN QUEENS
int d1check[N+3];		//CHECK FOR PRINCIPAL INTERSECTION BETWEEN QUEENS
int d2check[N+3];   	//CHECK FOR SECONDARY INTERSECTION BETWEEN QUEENS

void print()
{
    cout<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<board[i][j]<<"\t";		//FINAL LAYOUT FOR QUEEN POSITIONS
        }
        cout<<endl;
    }
}

bool isSafe(int row, int col)		//SAFE CONDITION TO BE CHECKED FOR EACH QUEEN
{
    if(colcheck[col]!=0) return false;
    if (d1check[row+col]!=0)  return false;
    if(d2check[row-col+N-1]!=0)return false;
    return true;
}


void solve(int r)
{
    if(r==N)
   {    print();
        return ;
   }

    for(int c=0;c<N;c++)
    {
        if(isSafe(r,c))
            { board[r][c]= 1;

              colcheck[c]=1;
              d1check[r+c]=1;
              d2check[r-c+N-1]=1;

              solve(r+1);               //FUNCTION CALL TO PLACE QUEEN IN NEXT ROW

              board[r][c]=0;
              colcheck[c]=0;           //RETURN BACK IF NO SPACE IS AVAILABLE
              d1check[r+c]=0;
              d2check[r-c+N-1]=0;

            }

    }
}

int main()
{
    cout<<"INPUT VALUE OF N :"<<N<<endl;
    solve(0);
}


