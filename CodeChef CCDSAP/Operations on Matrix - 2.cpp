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
        ll n, m, q;
        cin >> n >> m >> q;
        ll row[n + 1] = {0}, col[m + 1] = {0}; 
        ll rowCount = 0; ll colCount = 0;
        while(q--)
        {
            ll x, y;
            cin >> x >> y;
            row[x]++;
            col[y]++;
            if(row[x] % 2 == 0)
            {
                row[x] = 0;
                rowCount--;
            }
            else
            {
                rowCount++;
            }
            if(col[y] % 2 == 0)
            {
                col[y] = 0;
                colCount--;
            }
            else
            {
                colCount++;
            }
        }
        // cout << "rowCount : " << rowCount << " colCount: " << colCount << endl;
        ll answer;
        answer = rowCount * m + colCount * n - colCount * rowCount * 2;
        cout << answer << endl;
    }

    return 0;
}