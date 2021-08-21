#include <bits/stdc++.h>
using namespace std;

// UNION
void getUnion(int a[], int n, int b[], int m)
{
	
	// Defining set container s
	set<int> s;

	// Inserting array elements in s
	for (int i = 0; i < n; i++)
	s.insert(a[i]);

	for (int i = 0; i < m; i++)
		s.insert(b[i]);
	cout << "Number of elements after union operation: " << s.size() << endl;
	cout << "The union set of both arrays is :" << endl;
	for (auto itr = s.begin(); itr != s.end(); itr++)
		cout << *itr
			<< " "; // s will contain only distinct
					// elements from array a and b
}

// INTERSECTION:
// 1.Initialize intersection I as empty.
// 2.Find smaller of m and n and sort the smaller array.
// 3.For every element x of larger array, do the following
//      1.Binary Search x in the smaller array. If x is present, then copy it to I.
// 4.Return I.
void printIntersection(int arr1[], int arr2[], int m, int n)
{
    // Before finding intersection, make sure arr1[0..m-1]
    // is smaller
    if (m > n) {
        int* tempp = arr1;
        arr1 = arr2;
        arr2 = tempp;
 
        int temp = m;
        m = n;
        n = temp;
    }
 
    // Now arr1[] is smaller
 
    // Sort smaller array arr1[0..m-1]
    sort(arr1, arr1 + m);
 
    // Search every element of bigger array in smaller
    // array and print the element if found
    for (int i = 0; i < n; i++)
        if (binarySearch(arr1, 0, m - 1, arr2[i]) != -1)
            cout << arr2[i] << " ";
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        
        int n = nums1.size();
        int m = nums2.size();
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int i=0,j=0;
            
            while(i<n && j<m)
            {
                if(nums1[i]<nums2[j])
                    i++;
                
                else if(nums1[i]>nums2[j])
                    j++;
                else
                {
                    ans.push_back(nums1[i]);
                    i++;
                    j++;
                }
            }
        
        return ans;
    }

// Driver Code
int main()
{
	int a[9] = { 1, 2, 5, 6, 2, 3, 5, 7, 3 };
	int b[10] = { 2, 4, 5, 6, 8, 9, 4, 6, 5, 4 };

	getUnion(a, 9, b, 10);
}

// contributed by Anirban Chand
