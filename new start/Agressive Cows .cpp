#include<bits/stdc++.h>
using namespace std;

bool check(int cows, long long position[], int n, long long distance)
{
    int count = 1;
    long long last_position = position[0];
    for(int i = 1; i < n; i++)
    {
        if(position[i] - last_position >= distance)
        {
            last_position = position[i];
            count++;
        }
        if(count == cows)
        {
            return true;
        }
    }
    return false;
}

int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, c;
        cin >> n >> c;
        long long arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        long long start = 0;
        long long end = arr[n - 1] - arr[0];
        
        long long ans = -1;
        
        while(start <= end)
        {
            long long mid = start + (end - start) / 2;
            if(check(c, arr, n, mid))
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        cout << ans << endl;
        
    }
}