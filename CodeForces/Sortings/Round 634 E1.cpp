#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll findAns(long long * arr, ll start, ll end, set<ll> s){
    if(start > end){
        return 0;
    }
    if(start == end){
        return 1;
    }
    if(s.size() > 2){
        for(auto x : s){
            cout << "x: " << x << endl;
        }
        return 0;
    }
    ll ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8, ans9, ans10;
    ans1 = ans2 = ans3 = ans4 = ans5 = ans6 = ans7 = ans8  = 0;
    if(arr[start] == arr[end]){
        s.insert(arr[start]);
        ans1 = findAns(arr, start + 1, end - 1, s);
        // s.erase(arr[start]);
        ans2 = findAns(arr, start + 1, end, s);
        ans3 = findAns(arr, start, end - 1, s);
        ans4 = findAns(arr, start + 1, end - 1, s);
    }
    else{
        ans5 = findAns(arr, start + 1, end, s);
        ans6 = findAns(arr, start, end - 1, s);
        ans7 = findAns(arr, start + 1, end - 1, s);
    }
    ll final = max(ans1, max(ans2, max(ans3, ans4)));
    ll final2 = max(ans5, max(ans6, ans7));
    return max(final, final2);
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
        set<ll> s;
        ll ans = findAns(arr, 0, n - 1, s);
        cout << ans << endl;
    }

    return 0;
}