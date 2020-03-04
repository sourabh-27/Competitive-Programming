#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

void findPermutation(string str, ll n, ll index, string ans){
    if(index > n){
        return;
    }
    if(ans != ""){
        cout << ans << endl;
    }
    for(ll i = index; i < n; i++){
        ans = ans + str[i];
        findPermutation(str, n, i + 1, ans);
        ans = ans.erase(ans.size() - 1);
    }
    return;
}
 
int main()
{
    fast;
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    findPermutation(str, str.length(), 0, "");

    return 0;
}