#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

// ll count;
void findAns(ll n, ll opening, ll closing, string ans){
    // cout << "ans: " << ans << endl;
    if(closing > opening || opening > (n / 2) || ans.length() > n || closing > (n / 2)){
        return;
    }
    // cout << "ans: " << ans << endl;
    if(ans != "" && opening == closing && opening + closing == n){
        // count++;
        for(ll i = 0; i < ans.length(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    findAns(n, opening + 1, closing, ans + '(');
    findAns(n, opening, closing + 1, ans + ')');

}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    // count = 0;
    findAns(2 * n, 0, 0, "");

    return 0;
}