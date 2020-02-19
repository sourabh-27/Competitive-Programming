#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
void printArray(int A[], int size) 
{ 
    for (int i = 0; i < size; i++) 
        cout << A[i] << " "; 
    cout << endl; 
} 
  
// Function to Rearrange positive and negative 
// numbers in a array 
void RearrangePosNeg(int arr[], int l, int r) 
  
{ 
    while (l < r) { 
  
        // find element that is negative 
        while (l < r && arr[l] < 0) 
            l++; 
  
        // find element that is positive 
        while (r >= l && arr[r] > 0) 
            r--; 
  
        // swap elements. 
        if (l < r) { 
            swap(arr[l], arr[r]); 
            l++; 
            r--; 
        } 
    } 
} 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    RearrangePosNeg(arr, 0, n - 1);
    printArray(arr, n); 

    return 0;
}