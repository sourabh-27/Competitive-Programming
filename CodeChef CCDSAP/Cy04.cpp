#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

bool PrimeCheck(ll n)
{
    if(n == 1)
    {
        return false;
    }
  for(int i = 2; i <= n/2; ++i)
  {
      if(n % i == 0)
      {
          return false;
      }
  }
  return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    ll arr[n + 1] = {0};
    for(ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    while(q--)
    {
        ll l, r, p;
        cin >> l >> r >> p;
        if(PrimeCheck(p))
        {
            arr[l] += p;
            arr[r] += p;
        }
    }

    for(ll i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}