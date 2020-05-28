#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

void getPath(long long ** graph, ll v, bool * visited, ll x, ll y, ll &flag, vector<ll> &vec, long long * arr)
{
    if(x == y)
    {
        // cout << "I have reached destination : " << x << endl;
        visited[x] = true;
        flag = 1;
        vec.push_back(arr[y]);
        return;
    }
    visited[x] = true;
    for(int i = 1; i <= v; i++)
    {
        if(i == x)
        {
            continue;
        }
        if(graph[x][i] == 1 && !visited[i] && flag != 1)
        {
            // cout << "I am currently going to visit : " << i << endl;
            getPath(graph, v, visited, i, y, flag, vec, arr);
            if(!vec.empty() && i != y)
            {
                vec.push_back(arr[i]);
                return;
            }
        }
    }
}

bool isPrime[1000004]; 
vector<ll> prime; 
void SieveOfEratosthenes() 
{
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i <= 1000000; i++){
        isPrime[i] = true;
    } 
  
    for (ll p=2; p*p<=1000001; p++) 
    {
        if(isPrime[p] == true) 
        {
            for(ll i=p*2; i<=1000001; i += p) 
                isPrime[i] = false; 
        } 
    }
    for (ll p=2; p<=1000001; p++) 
        if (isPrime[p]) 
            prime.push_back(p); 
}

ll countDivisors(vector<ll> vec, int n) 
{
    unordered_map<ll, ll> mp; 
    for (ll i=0; i<n; i++) 
    { 
        for (int j=0; j<prime.size(); j++) 
        { 
            while(vec[i] > 1 && vec[i]%prime[j] ==0 ) 
            { 
                vec[i] /= prime[j]; 
                mp[prime[j]]++; 
            } 
        } 
        if (vec[i] != 1) 
            mp[vec[i]]++;
    }
    long long int res = 1; 
    for (auto it : mp){ 
       res = ((res % mod) * ((it.second + 1LL) % mod)) % mod; 
    }
    return res; 
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    SieveOfEratosthenes();
    while(t--){
        ll n;
        cin >> n;
        long long ** graph = new long long * [n + 2];
        for(ll i = 0; i <= n; i++){
            graph[i] = new long long [n + 2];
            for(ll j = 0; j <= n; j++){
                graph[i][j] = 0;
            }
        }
        for(ll i = 0; i < n - 1; i++){
            ll x, y;
            cin >> x >> y;
            graph[x][y] = 1;
            graph[y][x] = 1;
        }

        long long * arr = new long long [n + 2];
        for(ll i = 1; i <= n; i++){
            cin >> arr[i];
        }

        ll q;
        cin >> q;
        while(q--){
            ll src, dest;
            cin >> src >> dest;
            vector<ll> vec;
            bool * visited = new bool[n + 1];
            memset(visited, false, sizeof(visited));
            ll flag = 0;
            visited[src] = true;

            if(src == dest){
                vec.push_back(arr[src]);
            }
            else if(graph[src][dest] == 1)
            {
                vec.push_back(arr[dest]);
                vec.push_back(arr[src]);
            }
            else
            {
                getPath(graph, n, visited, src, dest, flag, vec, arr);
                if(!vec.empty() && vec.size() != 1)
                {
                    vec.push_back(arr[src]);
                }
            }

            ll final = countDivisors(vec, vec.size());
            cout << final % mod << endl;
            // unordered_map<ll, ll> factorCount;
            // ll ans = 1;
            // for(ll i = 0; i < vec.size(); i++)
            // {
            //     cout << vec[i] << " ";
            //     // fillMap(factorCount, vec[i]);
            //     // ans = ans * vec[i];
            // }
            // cout << endl;

            // cout << "ans: " << ans << endl;
            // ll factorCount = 0;
            // fillMap(factorCount, ans);

            // cout << factorCount % mod << endl;

            // ll ans = 1;
            // for(auto x : factorCount){
            //     ans = ans * (x.second + 1);
            //     // cout << "first: " << x.first << " second: " << x.second << endl;
            // }
            // cout << ans % mod << endl;
        }
    }

    return 0;
}