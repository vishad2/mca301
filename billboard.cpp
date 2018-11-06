
/*
	Q4.Suppose you are managing the construction of billboards on the university road,
	a heavily travelled stretch of road that runs west-east for M miles. The possible 
	sites for billboards are given by numbers ?x1,x2,...xn each in the interval [0, ?M]
	(specifying their position along the roads, measured in miles from its western end). 
	If you place billboard at location ?xi , you receive revenue of ?ri > 0.
	Regulations imposed by the Delhi road authority require that no two billboards be
	within less than or equal to 5 miles of each other. You had like to place billboards at
	a subset of the sites so as to maximize your total revenue, subject to this restriction.
	Example: Suppose M=20, n=4
	{x1, x2, x3, x4} = {6, 7, 12, 14} and {r1, r2, r3, r4} = {5, 6, 5, 1}
	Then the optimal solution would be to place billboards at ?x1 and x3 for total revenue
	of 10.
	Give an algorithm that takes an instance of this problem as input and returns the
	maximum total revenue that can be obtained from any valid subsets of sites.
*/

/*
	Space Complexity: O(M).
	Time Complexity : O(M)
*/

#include<iostream>
#include<math.h>

using namespace std;

void printRes(int *mr, int *x, int m, int n)
{
    int *res=new int[n];
    int cnt=0;

    for(int i=m; i>=0; i--)
    {
        if(mr[i]!=mr[i-1])
        {
           res[cnt++]=i;
           i=i-5;
        }
    }

    cout<<"\n\nBILLBOARDS PLACED AT : ";		//OPTIMIZED POSITON FOR EACH BILLBOARD 
    for(int i=cnt-2; i>0; i--)
        cout<<res[i]<<", ";
    cout<<res[0]<<endl;
}

void buildBillBoard(int *mr, int *x, int *r, int m, int n)
{
    int next=0;
    for(int i=1; i<=m; i++)
    {
        if(x[next]==i)
        {
            mr[i]=max(mr[i-1], mr[i-6]+r[next]);
            next++;
        }
        else
            mr[i]=mr[i-1];
    }

    cout<<"\n\nREPRESENTION OF MILES ARRAY IS :\n";
    for(int i=0; i<=m; i++)
        cout<<mr[i]<<"  ";

    cout<<"\n\nOPTIMIZED SOLUTION COMPUTED IS : "<<mr[m];

    printRes(mr, x, m, n);   
}

int main()
{
    int m, n, flag;

    cout<<"LENGTH OF ROAD IN MILES : ";
    cin>>m;

    int *mr = new int[m+1];
    for(int i=0; i<=m; i++)
        mr[i]=0;

    cout<<"\nAVAILABLE BILLBOARDS : ";
    cin>>n;

    int *x = new int[n];
    int *r = new int[n];

    do
    {
        flag=0;
        cout<<"\nPOSITION AND REVENUE FOR EACH BILLBOARD\n";
        for(int i=0; i<n; i++)
        {
            cout<<"\nPOSITION INSERTED : ";
            cin>>x[i];
            if(x[i]<x[i-1] && i>0)			//TO CHECK WHETHER POSITION ARRAY INSERTED IS SORTED OR NOT?
            {
               cout<<"\nSORRY....TRY AGAIN...";  
               flag=1;
               break;
            }

            cout<<"VALUE OF REVENUE :";
            cin>>r[i];
        }
    }while(flag==1);
/*
    cout<<"\nPOSITION IS :\t";				//DISPLAYING EACH BILLBOARD  POSITION AND ITS RESPECTIVE REVENUE
    for(int i=0; i<n; i++)
    {
        cout<<x[i]<<"\t";
    }

    cout<<"\nREVENUE IS :\t";
    for(int i=0; i<n; i++)
    {
        cout<<r[i]<<"\t";
    }
*/
    buildBillBoard(mr, x, r, m, n);  

    return 0;
}
