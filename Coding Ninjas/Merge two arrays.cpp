#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

void merge(long long *arr, long long *arr2, ll n, long long *temp){
    // cout << "YO" << endl;
    ll i = 0, j = 0, k = 0;
    while(i < n && j < n){
        // cout << "i: " << i << " j: " << j << " k: " << k << endl;
        if(arr[i] <= arr2[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr2[j++];
        }
    }
    while(i < n){
        temp[k++] = arr[i++];
    }
    while(j < n){
        temp[k++] = arr2[j++];
    }
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1], arr2[n + 1];
    long long temp[2 * n + 10];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> arr2[i];
    }
    merge(arr, arr2, n, temp);
    for(ll i = 0; i < 2*n; i++){
        cout << temp[i] << " ";
    }
    return 0;
}