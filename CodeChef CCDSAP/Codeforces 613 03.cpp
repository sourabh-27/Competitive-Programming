#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

ll lcm(ll m, ll n) {
   ll a;
   a = (m > n) ? m: n;
   while (true) {
      if (a % m == 0 && a % n == 0)
         return a;
         ++a;
   }
}

ll a, b, c, d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(ll x = 2; x <= 10000000; x++)
    {
        if(x == 1)
        {
            cout << 1 << " " << 1 << endl;
        }
        else
        {
            vector<ll> vec;
            for(ll i = 1; i <= sqrt(x); i++)
            {
                if(x % i == 0)
                {
                    // if(i * i == x)
                    // {
                    //     vec.push_back(i);
                    // }
                    if(x / i == i)
                    {
                        vec.push_back(i);
                    }
                    else
                    {
                        vec.push_back(i);
                        vec.push_back(x / i);
                    }
                }
            }

            // for(ll i = 0; i < vec.size(); i++)
            // {
            //     cout << vec[i] << " ";
            // }
            // cout << endl;

            ll mini = INT_MAX;
            for(ll i = 0; i < vec.size(); i++)
            {
                for(ll j = i + 1; j < vec.size(); j++)
                {
                    if(lcm(vec[i], vec[j]) == x)
                    {
                        if(max(vec[i], vec[j]) < mini)
                        {
                            mini = max(vec[i], vec[j]);
                            a = vec[i]; b = vec[j];
                        }
                    }
                }
            }
            cout << min(a, b) << " " << max(a, b) << endl;
        }

        if(x == 1)
        {
            cout << 1 << " " << 1 << endl;
        }
        else
        {
            ll mini = INT_MAX;
            for(ll i = 1; i <= sqrt(x); i++)
            {
                if(x % i == 0)
                {
                    // if(i * i == x)
                    // {
                    //     vec.push_back(i);
                    // }
                    // cout << "__gcd(i, x/i): " << __gcd(i, x / i) << endl;
                    if(x / i == i)
                    {
                        continue;
                    }
                    if(x % (x / i) == 0 && ((i * (x / i)) / __gcd(i, x / i)) == x)
                    {
                        if(max(i, x / i) < mini)
                        {
                            c = i;
                            d = x / i;
                            mini = max(c, d);
                        }
                    }
                }
            }

            if(a != c && b != d)
            {
                cout << "failure: " << x << endl;
                break;
            }

            // for(ll i = 0; i < vec.size(); i++)
            // {
            //     cout << vec[i] << " ";
            // }
            // cout << endl;

            
            // ll a, b;
            // for(ll i = 0; i < vec.size(); i++)
            // {
            //     for(ll j = i + 1; j < vec.size(); j++)
            //     {
            //         if(lcm(vec[i], vec[j]) == x)
            //         {
            //             if(max(vec[i], vec[j]) < mini)
            //             {
            //                 mini = max(vec[i], vec[j]);
            //                 a = vec[i]; b = vec[j];
            //             }
            //         }
            //     }
            // }
            cout << min(a, b) << " " << max(a, b) << endl;
        }
    }

    return 0;
}