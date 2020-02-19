#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

bool PrimeCheck(ll n)
{
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
    string n;
    cin >> n;
    ll size = n.length();

    ll a = 0; ll b = 1;
    for(ll i = 0; i < size; i++)
    {
        if(i % 2 == 0)
        {
            a += n[i] - 48;
        }
        else
        {
            b *= n[i] - 48;
        }
    }

    if(a - b < 0)
    {
        if(PrimeCheck(b -a))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        if(PrimeCheck(a - b))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}