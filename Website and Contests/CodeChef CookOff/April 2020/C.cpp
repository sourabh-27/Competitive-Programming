#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;

ll findAns(string s, string r, ll len, ll curr, ll store){
    if(curr >= len){
        return 0;
    }
    if(s[curr] != r[curr]){
        ll ans1 = (store - curr + 1) * 1 + findAns(s, r, len, curr, curr);
    }
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        string s, r;
        cin >> s >> r;
        ll i;
        for(i = 0; i < s.length(); i++){
            if(s[i] != r[i]){
                break;
            }   
        }
        s = s.substr(i); r = r.substr(i);
        cout << "s: " << s << " r: " << r << endl;
        cout << findAns(s, r, s.length(), 0, 0) << endl;
    }


    return 0;
}