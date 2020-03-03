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
    long long temp[n + 1];
    findAns(arr, n, 0, temp, 0);

    return 0;
}