#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
 
    bool * visited = new bool[n + 1];
    memset(visited, false, sizeof(visited));
 
    ll arr[n + 1] = {0};
    ll correct = 0, penalties = 0;
 
    for(ll i = 1; i <= m; i++)
    {
        ll k; string output;
        cin >> k >> output;
        if(visited[k])
        {
            continue;
        }
        else if(visited[k] == false && output[0] == 'A')
        {
            visited[k] = true;
            correct++; penalties += arr[k];
        }
        else if(visited[k] == false && output[0] == 'W')
        {
            arr[k]++;
        }
    }
 
    cout << correct << " " << penalties << endl;
 
 
    return 0;
}