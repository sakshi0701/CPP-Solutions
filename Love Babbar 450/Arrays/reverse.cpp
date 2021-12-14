#include <bits/stdc++.h>
using namespace std;

string reverseWord(string str){
    
  int n = str.size();
  int start = 0;
  int end = n-1;
  while(start<end)
  {
        int temp = str[start];
    	  str[start] = str[end];
        str[end] = temp;
        start++;
        end--; 
  }
    return str;
}

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}