#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

void findAns(ll n, ll count, string ans){
    // cout << "ans: " << ans << endl;
    if(n  <= count || ans.length() > 3){
        return;
    }
    if(ans != ""){
        count++;
        for(ll i = 0; i < ans.length(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        // return;
    }
    findAns(n, count, ans + 'a');
    findAns(n, count, ans + 'b');
    findAns(n, count, ans + 'c');
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    findAns(n, 0, "");

    return 0;
}