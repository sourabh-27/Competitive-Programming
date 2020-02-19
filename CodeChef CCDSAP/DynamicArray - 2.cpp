#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    // cout << "n : " << n << " q : " << q << endl;
    ll lastAnswer = 0;
    vector<ll> vec[n + 1];
    while(q--)
    {
        // cout << "q: " << q << endl;
        ll k, x, y;
        cin >> k >> x >> y;
        ll seq = ((x ^ lastAnswer) % n);
        if(k == 1)
        {
            // cout << "k : " << k << endl;
            vec[seq].push_back(y);
        }
        else
        {
            // cout << "k : " << k << endl;
            lastAnswer =vec[seq][y % vec[seq].size()];
            cout << lastAnswer << endl;
        }
    }

    return 0;
}