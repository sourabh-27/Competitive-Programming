#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int count(int start, int end)
{
    int ans = 0;
    while(start != 0 || end != 0)
    {
        if(start >= end)
        {
            start -= end;
        }
        else
        {
            end -= start;
        }
        ans++;
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = 0;
    int start = 5; int end = 3;
    while(start != 0 && end != 0)
    {
        cout << start << " " << end << endl;
        if(start >= end)
        {
            start -= end;
        }
        else
        {
            end -= start;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}