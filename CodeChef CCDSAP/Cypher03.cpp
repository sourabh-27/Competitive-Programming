#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll modi = 1000000007;
int main(){
    ll n, k;
    cin>>n>>k;
    ll arr[n+1];
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }
    if(k>n){
        cout << "-1 -1" << endl;
    }
    else{
    ll cou[100001];
    memset(cou, 0, sizeof(cou));   
    ll l = 1, r = k;
    set<int> myset;
    for(ll i = 1; i<=k; i++){
        myset.insert(arr[i]);
        cou[arr[i]]++;
    }
    int flag = 0;
    if(myset.size() == k){cout<<l<<" "<<r << endl;
    flag = 1; }
    else{
        for(ll i = k+1; i<=n; i++){
            if(cou[arr[l]] == 1){
                set<int>::iterator itr = myset.find(arr[l]);
                myset.erase(itr);
                cou[arr[l]]--;
            }
            else{
                cou[arr[l]]--;
            }
            l++;
            myset.insert(arr[i]);
            cou[arr[i]]++;
            if(myset.size() == k){
                cout<<l<<" "<<i<<endl;
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0)cout << "-1 -1" << endl;
    }
}