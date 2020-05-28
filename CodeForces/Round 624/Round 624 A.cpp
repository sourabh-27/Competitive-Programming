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
    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a == b){
            cout << 0 << endl;
        }
        else{
            if(a > b){
                if(abs(a - b) % 2 == 0){
                    cout << 1 << endl;
                }
                else{
                    cout << 2 << endl;
                }
            }
            else{
                if(abs(a - b) % 2 != 0){
                    cout << 1 << endl;
                }
                else{
                    cout << 2 << endl;
                }
            }
        }
    }


    return 0;
}