#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    cout << log(n) / log(2) << endl;
    cout << pow(2, 17) - 1 << endl;

    return 0;
}