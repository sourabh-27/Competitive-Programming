#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll t;
    cin >> t;
    for(ll x = 1; x <= t; x++){
        cout << "Case #" << x << ": ";
        string str;
        cin >> str;
        ll len = str.length();
        //three cases next number big small or equal
        ll opening = str[0] - 48;
        char last = str[0];
        for(ll i = 0; i < opening; i++){
            cout << "(";
        }
        // cout << "YO";
        cout << str[0];
        for(ll i = 1; i < len; i++){
            if(last == '0'){
                opening = str[i] - 48;
                last = str[i];
                for(ll j = 0; j < opening; j++){
                    cout << "(";
                }
                cout << str[i];
            }
            else if(str[i] > last){
                // cout << ")";
                // opening--;
                ll curr = str[i] - 48 - opening;
                opening += curr;
                for(ll j = 0; j < curr; j++){
                    cout << "(";
                }
                cout << str[i];
                last = str[i];
            }
            else if(str[i] < last){
                ll curr = opening - str[i] + 48;
                opening -= curr;
                for(ll j = 0; j < curr; j++){
                    cout << ")";
                }
                cout << str[i];
                last = str[i];
            }
            else{
                cout << str[i];
                last = str[i];
            }
        }

        while(opening != 0){
            cout << ")";
            opening--;
        }
        cout << endl;
        // cout << "opening: " << opening << endl;
    }

    return 0;
}