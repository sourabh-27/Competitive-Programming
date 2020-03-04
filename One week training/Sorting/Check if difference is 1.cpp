#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];
    ll mini = INT_MAX;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        mini = min(arr[i], mini);
    }
    // cout << mini << endl;
    unordered_map<int, int> map;
    for(ll i = mini; i <= mini + n - 1; i++){
        map.insert({i, 1});
    }

    int flag = 0;
    for(ll i = 0; i < n; i++){
        if(map.find(arr[i]) == map.end()){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        cout << "The array is not of difference 1 after sorting"  << endl;
    }
    else{
        cout << "Oh!! yeah" << endl;
    }


    return 0;
}