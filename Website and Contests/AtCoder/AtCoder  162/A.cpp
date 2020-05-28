#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;
 
int main()
{
    fast;
    // ll t;
    // cin >> t;
    // while(t--){
        ll n;
        cin >> n;
        string str = to_string(n);
        if(str[0] == '7' || str[1] == '7'  || str[2] == '7'){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    // }


    return 0;
}