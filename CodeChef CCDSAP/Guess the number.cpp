#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    ll start = 1;
    ll end = 1000000;
    while(start != end)
    {
        ll mid = (start + end + 1) / 2;
        printf("%lld\n", mid);
        fflush(stdout);
        char str[3];
        scanf("%s", str);
        int ans = strcmp(str, "<");
        if(ans == 0)
        {
            end = mid - 1;
        }
        else
        {
            start = mid;
        }
    }

    printf("! %lld\n", end);
    fflush(stdout);

    return 0;
}