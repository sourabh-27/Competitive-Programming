#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;
typedef unsigned long long int ull;

ull power_of_2_mod(ull n) {
    ull result = 1;
    if (n <= 63) {
        result <<= n;
        result = result % 1000000007;
    }
    else {
        ull one = 1;
        one <<= 63;
        while (n > 63) {
            result = ((result % 1000000007) * (one % 1000000007)) % 1000000007;
            n -= 63;
        }

        for (int i = 1; i <= n; ++i) {
            result = (result * 2) % 1000000007;
        }

    }

    return result;
}

int main()
{
    fast;
    ll x, y;
    cin >> x >> y;

    cout << power_of_2_mod(x + 1) - 1 - power_of_2_mod(y) << endl;
    cout << 5037840283 % mod << endl;

    return 0;
}