#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

bool isPrime(ll num)
{
   ll root = sqrt(num);
   if(num == 1)
   {
       return false;
   }
   for(ll i = 2; i <= root; i++) 
   {
      if(num % i == 0)
          return false;
   } 
   return true;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    ll a = 2;
    ll b = a + n;
    while(true)
    {
        if(!isPrime(a) && !isPrime(b))
        {
            break;
        }
        else
        {
            a = a + 1;
            b = b + 1;
        }
    }
    cout << b << " " << a << endl;
    return 0;
}