#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

ll dp[100000];
long long int solve(ll n, ll m, bool * visited)
{
    // cout << "My value of n is: " << n << endl;
    if(n >= m)
    {
        // cout << "I am equal now" << endl;
        return n - m;
    }
    if(n <= 0 || n >= 100000)
    {
        // cout << "I am at min and value of n is: " << n << " " << endl;
        return 100000;
    }
    if(dp[n])
    {
        return dp[n];
    }
    if(visited[n])
    {
        // cout << "I have already visited: " << n << endl;
        return 100000;
    }
    visited[n] = true;
    long long int ans1 = solve(n - 1, m, visited) + 1; 
    long long int ans2 = solve(n * 2, m, visited) + 1;
    // cout << "ans1: " << ans1 << endl;
    // cout << "ans2: " << ans2 << endl;
    ll ans = min(ans1, ans2);
    dp[n] = ans;
    return dp[n];
    // int ans2 = solve(n * 2, m) + 1;
    // cout << "ans2: " << ans2 << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;

    bool * visited = new bool[100000];
    for(int i = 0; i < 100000; i++)
    {
        visited[i] = false;
    }  
    if(n >= m)
    {
        cout << n - m << endl;
    }
    else
    {
        cout << solve(n, m, visited) << endl;
    }

    return 0;
}