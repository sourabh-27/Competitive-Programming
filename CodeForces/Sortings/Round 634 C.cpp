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
    while(t--){
        vector<string> vec;
        for(ll i = 0; i < 9; i++){
            string str;
            cin >> str;
            for(ll j = 0; j < 9; j++){
                if(str[j] == '9'){
                    str[j] = '1';
                }
            }
            vec.push_back(str);
        }
        for(ll i = 0; i < 9; i++){
            cout << vec[i] << endl;
        }
    }


    return 0;
}