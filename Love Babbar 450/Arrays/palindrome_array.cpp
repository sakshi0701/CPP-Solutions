#include<iostream>
#include<string.h>
using namespace std;

int PalinArray(int a[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}

int PalinArray(int a[], int n)
{  
    int flag = 1;
    for(int j = 0; j < n; j++)
    {
        int temp = a[j];
        int rem, sum = 0;
        while(temp > 0)
        {
            rem = temp % 10;
            sum = sum * 10 + rem;
            temp /= 10;
        }
        
        if(a[j] != sum)
        {
            flag = 0;
            break;
        }
        
        else flag = 1;
    }
    return flag;
}