#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

void findAns(long long * arr, ll count, ll index, long long * temp, ll n){
    for(ll i = 0; i < count; i++){
        cout << temp[i] << " ";
    }
    cout << endl;
    if(index == n){
        return;
    }
    for(ll j = index; j < n; j++){
        temp[count] = arr[j];
        findAns(arr, count + 1, j + 1, temp, n);
    }
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
    long long temp[n + 1];
    findAns(arr, 0, 0, temp, n);

    return 0;
}