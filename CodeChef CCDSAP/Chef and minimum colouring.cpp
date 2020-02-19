#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> vec[50002];
        ll count = 0;
        for(ll i = 1; i <= n; i++)
        {
            ll k;
            cin >> k;
            if(i % m == 1 && i != 1)
            {
                count++;
            }
            vec[count].push_back(k);
        }

        ll mini = INT_MAX;
        ll row, col;
        col = m;
        if(n % m != 0)
        {
            row = (n / m) + 1;
        }
        else
        {
            row = (n / m);
        }
        for(ll i = 0; i < row; i++)
        {
            for(ll j = 0; j < col; j++)
            {
                for(ll k = i + 1; k < row; k++)
                {
                    for(ll l = 0; l < col; l++)
                    {
                        if(i == k)
                        {
                            continue;
                        }
                        // cout << "I am comparing: " << vec[i][j] << " with " << vec[k][l] << endl;
                        if(abs(vec[i][j] - vec[k][l]) < mini)
                        {
                            mini = abs(vec[i][j] - vec[k][l]);
                        }
                    }
                }
            }
        }
        cout << mini << endl;
    }

    return 0;
}