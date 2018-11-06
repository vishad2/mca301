/*Q5.
Program to test whether sequence(of events) 1 is a subsequence of sequence(of events)2 
*/

#include<iostream>
#include<vector>
using namespace std;

bool isSubsequence(vector<string> s1, vector<string> s2){
	
	int j = 0;
	 
	for(int i=0; i<s2.size() && j<s1.size(); i++){	
		if(s1[j].compare(s2[i]) == 0)				//COMPARING S2 EVENTS WITH S1 EVENTS(UNMATCHED)
			j++;									
	}
	
	return ( j==s1.size() ); 			//RETURN TRUE IF EVENTS OF S1 ARE FOUND IN S2
}

int main(){
	
	vector<string>	s1, s2;
	cout<<"\nPATTERN RECOGNITION: SUBSEQUENCE PROBLEM\n";
	cout<<"\nSEQUENCE 1\n ";
	while(true){
		string event;
		cout<<"\N INPUT NEXT EVENT : ";
		cin>>event;
		if(event.compare("0") == 0)		//FETCHING IS STOPPED IN S1
			break;
		s1.push_back(event);
	}
	
	cout<<"\nSEQUENCE 2\n ";
	while(true){
		string event;
		cout<<"\N INPUT NEXT EVENT :";	
		cin>>event;
		if(event.compare("0") == 0)		//FETCHING IS STOPPED IN S2
			break;
		s2.push_back(event);
	}
	
	if( isSubsequence(s1, s2))							
		cout<<"\nTRUE.......S1 IS SUBSEQUENCE OF S2";
	else
		cout<<"\nFALSE.......S1 IS NOT A SUBSEQUENCE OF S2";
		
	return 0;
}
