#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long int ll;

bool Prime(ll n)
{
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for(ll i = 5; i * i <= n; i = i + 6)
    {
        if(n % i == 0 || n%(i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

ll Divisors(ll n) 
{ 
    ll count = 0;
	for (ll i=1; i<=sqrt(n); i++) 
	{ 
		if (n%i == 0) 
		{ 
			if (n/i == i) 
				count++;
			else 
                count += 2;
		} 
	} 
    return count;
} 

int main() {
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        // vector<ll> divisors;
        ll count = 0;
        for(ll i = 1; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                count++;
            }
        }
        if(Prime(count))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }    
    return 0;
}