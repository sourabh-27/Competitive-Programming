#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    string str;
    cin >> str;
    ll len = str.length();
    ll start = 0, end = 0;
    ll ans = 1;
    int arr[26] = {-1};
    arr[str[0] - 'a'] = 0; ll j = 1;
    while(j < len){
        if(arr[str[j] - 'a'] == -1){
            end++;
            arr[str[j] - 'a'] = j;
        }
        else{
            ll k = arr[str[j] - 'a']; ll i;
            for(i = start; i <= k; i++){
                arr[str[i] - 'a'] = -1;
            }
            start = i; end++;
            arr[str[j] - 'a'] = j;
        }
        j++;
    }
    cout << 


    return 0;
}