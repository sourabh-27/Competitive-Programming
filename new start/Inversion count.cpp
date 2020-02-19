#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

long long merge(int A[], int left, int mid, int right)
{
    int i = left, j = mid, k = 0;
    int temp[right - left + 1];
    ll count = 0;

    while(i < mid && j <= right)
    {
        if(A[i] <= A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
            count += mid - i;
        }
    }
    while(i < mid)
    {
        temp[k++] = A[i++];
    }
    while(j <= right)
    {
        temp[k++] = A[j++];
    }

    for(int i = left, k = 0; i <= right; i++, k++)
    {
        A[i] = temp[k];
    }
    return count;
}

long long merge_sort(int A[], int left, int right)
{
    long long count = 0;
    if(right > left)
    {
        int mid = (left + right) / 2;
        long long count_left = merge_sort(A, left, mid);
        long long count_right = merge_sort(A, mid + 1, right);
        long long myCount = merge(A, left, mid + 1, right);

        return (myCount + count_left + count_right);
    }
    return count;
}

long long solve(int A[], int n)
{
    long long answer = merge_sort(A, 0, n-1);
    return answer;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    return 0;
}