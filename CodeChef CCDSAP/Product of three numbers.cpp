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
        ll n;
        cin >> n;
        vector<ll> final;
        ll flag = 0;
        for(ll i = 2; i * 5 <= n; i++)
        {
            if(n % i == 0)
            {
                ll temp = n / i;
                for(ll j = 2; j * j <= temp; j++)
                {
                    if(temp % j == 0 && temp / j != temp)
                    {
                        ll temp2 = temp / j;
                        // cout << "temp : " << temp << " temp2: " << temp2 << endl;
                        if(n % (temp * temp2) == 0 && n / (temp * temp2) != temp && n / (temp * temp2) != temp2)
                        {
                            ll temp3 = n / (temp * temp2);
                            if(temp > 1 && temp2 > 1 && temp3 > 1)
                            {
                                flag = 1;
                                final.push_back(temp);
                                final.push_back(temp2);
                                final.push_back(temp3);
                                break;
                            }
                        }
                    }
                }
                if(flag == 1)
                {
                    break;
                }
            }
        }
        if(flag == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            sort(final.begin(), final.end());
            cout << final[0] << " " << final[1] << " " << final[2] << endl;
        }
    }

    return 0;
}