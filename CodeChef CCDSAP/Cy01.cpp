#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q;
    cin >> q;
    set<ll> s;
    set<ll>::iterator itr;
    while(q--)
    {
        ll x;
        cin >> x;
        if(x == 1)
        {
            ll y;
            cin >> y;
            s.insert(y);
        }
        else if(x == 2)
        {
            ll y;
            cin >> y;
            itr = s.find(y);
            s.erase(y);
        }
        else
        {
            if(s.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                itr = s.begin();
                cout << *itr << endl;   
            }
        }
    }

    return 0;
}