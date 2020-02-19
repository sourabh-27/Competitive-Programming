#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
// 153
// 370
// 371
// 407

bool isPrime(ll n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        bool ans1 = false;
        bool ans2 = false;
        if(str[0] == str[3] && str[1] == str[2])
        {
            ans1 = true;
        }
        string s2 = str.substr(4, 3);
        if(str[4] == str[6])
        {
            ans2 = true;
        }
        bool ans3 = false;
        ll k = stoll(s2);
        bool ans4 = false;
        if(k == 153 || k == 370 || k == 371 || k == 407 || k == 0 || k == 1)
        {
            ans4 = true;
        }
        bool ans5 = false;
        string s3 = str.substr(0, 4);
        if(isPrime)
        {
            ans5 = true;
        }
        if(isPrime(k))
        {
            if(ans1 && ans2)
            {
                cout << "First Prize" << endl;
            }
        }
        else if(ans5 && ans4)
        {
            cout << "Second Prize" << endl;
        }
        else
        {
            cout << "Better Luck Next Time!!!" << endl;
        }
        
    }

    return 0;
}