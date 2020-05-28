#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll findMaxLength(long long * arr, ll start, ll end, unordered_set<ll> &s){
    if(start > end){
        return 0;
    }
    

    if(start == end){
        s.insert(arr[start]);
        if(s.size() > 2){
            s.erase(arr[start]);
            return 0;
        }
        else{
            s.erase(arr[start]);
            return 1;
        }
    }

    if(s.size() > 2){
        return 0;
    }

    ll ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8;
    ans1 = ans2 = ans3 = ans4 = ans5 = ans6 = ans7 = ans8 = 0;
    if(arr[start] == arr[end]){
        ans4 = findMaxLength(arr, start + 1, end - 1, s);
        ans5 = findMaxLength(arr, start + 1, end, s);
        ans6 = findMaxLength(arr, start, end - 1, s);
        s.insert(arr[start]);
        ans1 = 2 + findMaxLength(arr, start + 1, end - 1, s);
        s.erase(arr[start]);
    }
    else{
        ans2 = findMaxLength(arr, start + 1, end, s);
        ans3 = findMaxLength(arr, start, end - 1, s);
        ans7 = findMaxLength(arr, start + 1, end - 1, s);
    }

    ll final = max(ans1, max(ans2, max(ans3, max(ans4, max(ans5, max(ans6, ans7))))));
    return final;
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        long long arr[n + 1];
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        unordered_set<ll> s;
        ll ans = findMaxLength(arr, 0, n - 1, s);
        cout << ans << endl;
    }

    return 0;
}