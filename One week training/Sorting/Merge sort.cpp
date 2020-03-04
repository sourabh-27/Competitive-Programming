#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

void merge(long long * arr, ll s1, ll e1, ll s2, ll e2){
    ll i = s1; ll j = s2;
    ll k = s1; long long temp[100000];
    while(i < e1 && j < e2){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i < e1){
        temp[k++] = arr[i++];
    }
    while(j < e2){
        temp[k++] = arr[j++];
    }
    for(ll i = s1; i < e2; i++){
        arr[i] = temp[i];
    }
}

void mergeSort(long long * arr, ll left, ll right){
    if(left == right){
        return;
    }

    ll mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, mid + 1, right);
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);
    for(ll i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}