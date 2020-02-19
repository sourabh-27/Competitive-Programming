#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

long long merge(int* A, int left, int mid, int right)
{
    int i = left, j = mid, k = 0;
    int temp[right - left + 1];
    ll count = 0;
    
    while(i < mid && j <= right)
    {
        if(A[i] < A[j])
        {
            count = count + A[i];
            j++;
        }
    }
}

long long merge_sort(int A[], int left, int right)
{
    ll count = 0;
    if(right > left)
    {
        int mid = (left + right) / 2;
        long long count_left = merge_sort(A, left, mid);
        long long count_right = merge_sort(A, mid + 1, right);
        long long myCount = merge(A, left, mid + 1, right);
        
        return (count_left + count_right + myCount);
    }
    return count;
}

long long solve(int* A, int n)
{
    long long answer = merge_sort(A, 0, n-1);
    return answer;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        cout << solve(A, n) << endl;
    }

    return 0;
}