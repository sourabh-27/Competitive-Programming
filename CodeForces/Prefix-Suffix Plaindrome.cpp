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
        string s;
        cin >> s;
        ll n = s.length();
        vector<string> vec;
        for(ll i = 0; i < n; i++){
            string k = s.substr(n - i - 1, i + 1);
            // cout << "k: " << k << endl;
            vec.push_back(k);
        }

        string str = s.substr(0, 1); string ans = ""; ll len = 0;
        for(ll i = 1; i < n; i++){
            string rev = str;
            // cout << rev << endl;
            reverse(rev.begin(), rev.end());
            cout << "reverse: " << rev << endl;
            if(find(vec.begin(), vec.end(), rev) != vec.end()){
                if((str + rev).length() > len){
                    ans = str + rev;
                }
            }
            str = str + s[i];
            rev = str;
            reverse(rev.begin(), rev.end());
            if(find(vec.begin(), vec.end(), rev) != vec.end()){
                if((str + rev).length() > len){
                    ans = str + rev;
                }
            }
        }
        cout << "ans: " << ans << endl;
    }

    return 0;
}