#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

// long double(ll x1, ll y1, ll x2, ll y2)
// {
//     return sqrt(powl())
// }
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        ll x, y;
        cin >> x >> y;
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> nx, ny, mx, my, kx, ky;
        for(ll i = 0; i < n; i++)
        {
            ll x1, y1;
            cin >> x1 >> y1;
            nx.push_back(x1);
            ny.push_back(y1);
        }
        for(ll i = 0; i < m; i++)
        {
            ll x1, y1;
            cin >> x1 >> y1;
            mx.push_back(x1);
            my.push_back(y1);
        }
        for(ll i = 0; i < k; i++)
        {
            ll x1, y1;
            cin >> x1 >> y1;
            kx.push_back(x1);
            ky.push_back(y1);
        }

        long long int ans, ans1, ans2, ans3, ans4;
        long double an, an1, an2, an3, an4;

        long double final = 1.0 * __LONG_LONG_MAX__;
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                for(ll k1 = 0; k1 < k; k1++)
                {
                    //to find distance between nx ny, mx my and kx ky
                    ans = ((x - nx[i]) * (x - nx[i]) + (y - ny[i]) * (y - ny[i]));
                    an = sqrtl(ans);
                    // cout << "The distance between: " << x << " " << nx[i] << " and " << y << " " << ny[i] << " is: " << sqrtl(ans) << endl;
                    ans1 = ((mx[j] - nx[i]) * (mx[j] - nx[i]) + (my[j] - ny[i]) * (my[j] - ny[i]));
                    an1 = sqrtl(ans1);
                    // cout << "The distance between: " << mx[j] << " " << nx[i] << " and " << my[j] << " " << ny[i] << " is: " << ans1 << " " << fixed << setprecision(12) << an1 << endl;
                    ans2 = ((kx[k1] - mx[j]) * (kx[k1] - mx[j]) + (ky[k1] - my[j]) * (ky[k1] - my[j]));
                    an2 = sqrtl(ans2);
                    // cout << "The distance between: " << kx[k1] << " " << mx[j] << " and " << ky[k1] << " " << my[j] << " is: " << fixed << setprecision(12) << an2 << endl;
                    ans3 = ((x - mx[i]) * (x - mx[i]) + (y - my[i]) * (y - my[i]));
                    an3 = sqrtl(ans3);
                    ans4 = ((kx[k1] - nx[j]) * (kx[k1] - nx[j]) + (ky[k1] - ny[j]) * (ky[k1] - ny[j]));
                    an4 = sqrtl(ans4);
                    // final = 1.0 * fmin(final, ans + ans1 + ans2);
                    if((1.0 * (an + an1 + an2)) < (1.0 * final))
                    {
                        final = 1.0 * (an + an1 + an2);
                        // cout << "ans: " << ans << endl;
                        // cout << "ans1: " << ans1 << endl;
                        // cout << "ans2: " << ans2 << endl;
                    }
                    // final = 1.0 * fmin(final, ans3 + ans1 + ans4);
                    if(1.0 * (an1 + an3 + an4) < (1.0 * final))
                    {
                        final = 1.0 * (an3 + an1 + an4);
                        // cout << "final2: " << final << endl;
                    }
                    // cout << "This is the distance between point (" << nx[i] << "," << ny[i] << ") and (" << mx[j] << "," << my[j] << ") and (" << kx[k1] << "," << ky[k1] << ")" << endl;
                    // cout << fixed << setprecision(10) << final << endl;
                    // cout << "final : " << final << endl;
                }
            }
        }
        cout << fixed << setprecision(12) << final << endl;
        // printf("%Ld\n", final);
        // printf("%Le\n", final);
        // cout << floor(final) - final << endl;
        // if(floor(final) - final == 0)
        // {
        //     cout << (long long)final << endl;
        // }
        // else
        // {
        //     cout << fixed << setprecision(12) << final << endl;   
        // }
    }

    return 0;
    // 1                                                                                                               
    // 1000000000 1000000000
    // 1 1 1
    // 1000000000 0
    // 0 1
    // 0 1000000000
}