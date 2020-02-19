#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
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

    int left[n], right[n];
    left[0] = 0; right[n - 1] = 0; int count = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] >= arr[i - 1])
        {
            count++;
            left[i] = count;
        }
        else
        {
            count = 0;
            left[i] = count;
        }
        // cout << count << " ";
    }

    count = 0;
    for(int i = n - 2; i >= 0; i--)
    {
        if(arr[i + 1] <= arr[i])
        {
            count++;
            right[i] = count;
        }
        else
        {
            count = 0;
            right[i] = count;
        }
        // cout << count << " "; 
    }
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        maxi = max(maxi, left[i] + right[i] + 1);
    }
    cout << maxi << endl;

    return 0;
}