#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int count(int start, int end)
{
    int ans = 0;
    while(start != 0 && end != 0)
    {
        if(start > end)
        {
            start = start - end;
        }
        else
        {
            end = end - start;
        }
        ans = ans + 1;
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p, q, r, s;
    cin >> p >> q >> r >> s;
    int ans = 0;
    for(int i = p; i <= q; i++)
    {
        for(int j = r; j <= s; j++)
        {
            int option = count(i, j);
            ans += option;
        }
    }

    cout << ans;

    return 0;
}