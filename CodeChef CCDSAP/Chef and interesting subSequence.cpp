#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll combination(ll a, ll b)
{
	ll temp = 1;
    ll temp2 = 1;
	if (a - b < b)
    {
        b = a - b;
    }
	if (b != 0)
    {
		while(b)
        {
            temp2 = temp2 * b;
			temp = temp * a;
			ll m = __gcd(temp, temp2);
            temp2 = temp2 / m;
			temp = temp / m;
            b--;
			a--;
		}
	}
	else
    {
        temp = 1;
    }
	return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin>>T;
    while(T--)
    {
        ll n, k;
        cin >> n >> k;

        ll arr[n];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr+n);

        ll first = 0;
        ll last  = 0;

        for(int i = k; i < n; i++)
        {
            if(arr[i] == arr[k - 1])
            {
                last++;
            }
        }

        for(ll i = k - 1; i >= 0; i--)
        {
            if(arr[i] == arr[k - 1])
            {
                first = first + 1;
            }
        }

        if((first + last) == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << combination(first + last, first);
        }
    }
}