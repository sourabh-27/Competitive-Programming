#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        ll cost;
        if(a > b)
        {
            cost = ((2 + n) * a) + ((n * 2) * b);
        }
        cout << cost << endl;
    }

    return 0;
}