#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
  
// A job has a start time, finish time and profit. 
struct Activitiy 
{ 
    int start, finish; 
}; 

bool activityCompare(Activitiy s1, Activitiy s2) 
{ 
    return (s1.finish < s2.finish); 
} 
 
ll printMaxActivities(Activitiy arr[], int n) 
{ 
    sort(arr, arr+n, activityCompare); 
    ll count = 0; ll maxi = 0;
    for(ll i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j].start == arr[i].finish) 
            { 
                count++;
                maxi = max(maxi, count);
                i = j;
            } 
        } 
        count = 0;
    }
    return maxi;
} 

int main() 
{ 
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    struct Activitiy arr[n + 1];
    for(ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        arr[i].start = x;
        arr[i].finish = y;
    }
    ll ans = printMaxActivities(arr, n); 
    cout << ans * k << endl;
    return 0; 
} 