#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

ll longestPathUtil(char ** arr, ll i, ll j, ll h, ll w, bool ** visited)
{
    if(i == h - 1&& j == w - 1)
    {
        return 0;
    }

    if(i >= h || i < 0 || j >= w || j < 0 || arr[i][j] == '#' || visited[i][j])
    {
        return 0;
    }

    visited[i][j] = true;
    ll ans = INT_MIN;

    ll ans1 = longestPathUtil(arr, i - 1, j, h, w, visited) + 1;
    ll ans2 = longestPathUtil(arr, i, j - 1, h, w, visited) + 1;
    ll ans3 = longestPathUtil(arr, i + 1, j, h, w, visited) + 1;
    ll ans4 = longestPathUtil(arr, i, j + 1, h, w, visited) + 1;

    ans = max(ans, max(ans1, max(ans2, max(ans3, ans4))));
    if(ans != INT_MIN)
    {
        return ans + 1;
    }
    else
    {
        return INT_MAX;
    }
}

ll findLongestPath(char ** arr, ll i, ll j, ll h, ll w)
{
    bool ** visited = new bool * [h + 1];
    for(ll i = 0; i <= h; i++)
    {
        visited[i] = new bool[w + 1];
    }
    memset(visited, false, sizeof(visited));

    return longestPathUtil(arr, i, j, h, w, visited);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll h, w;
    cin >> h >> w;
    char ** arr = new char*[h + 1];
    for(ll i = 0; i <= h; i++)
    {
        arr[i] = new char[w + 1];
    }
    for(ll i = 0; i < h; i++)
    {
        for(ll j = 0; j < w; j++)
        {
            cin >> arr[i][j];
        }
    }

    // ll maxi = INT_MIN;
    for(ll i = 0; i < h; i++)
    {
        for(ll j = 0; j < w; j++)
        {
            if(arr[i][j] == '.')
            {
                ll ans = findLongestPath(arr, i, j, h, w);
                cout << "ans: " << ans << endl;
            }
        }
    }

    // cout << maxi << endl;

    return 0;
}