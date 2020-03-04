#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;


void findAns(long long * arr, ll n, ll count, long long * temp, ll i){
    if(i == n){
        for(ll i = 0; i < count; i++){
            cout << temp[i] << " ";
        }
        cout << endl;
        return;
    }
    temp[count] = arr[i];
    findAns(arr, n, count + 1, temp, i + 1);
    findAns(arr, n, count, temp, i + 1);
}

void findAns2(long long * arr, ll n, ll i, vector<int> ans){
    if(i == n){
        for(ll i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        ans.clear();
        return;
    }
    findAns2(arr, n, i + 1, ans);
    ans.push_back(arr[i]);
    findAns2(arr, n, i + 1, ans);
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    findAns2(arr, n, 0, ans);

    return 0;
}