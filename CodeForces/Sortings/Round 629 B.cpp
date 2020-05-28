#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

const int MAX_CHAR = 26; 
const int MAX_FACT = 20; 
ll fact[MAX_FACT]; 

void precomputeFactorials() 
{ 
    fact[0] = 1; 
    for (int i = 1; i < MAX_FACT; i++) 
        fact[i] = fact[i - 1] * i; 
} 
  
void nPermute(char str[], int n) 
{ 
    ll len = strlen(str); 
    long long freq[MAX_CHAR] = { 0 }; 
    for (ll i = 0; i < len; i++) 
        freq[str[i] - 'a']++; 
  
    char out[MAX_CHAR]; 
  
    ll sum = 0; 
    ll k = 0; 
   
    while (sum != n) { 
  
        sum = 0; 
        // check for characters present in freq[] 
        for (ll i = 0; i < MAX_CHAR; i++) { 
            if (freq[i] == 0) 
                continue; 
  
            freq[i]--; 

            ll xsum = fact[len - 1 - k]; 
            for (int j = 0; j < MAX_CHAR; j++) 
                xsum /= fact[freq[j]]; 
            sum += xsum; 
  
            if (sum >= n) { 
                out[k++] = i + 'a'; 
                n -= (sum - xsum); 
                break; 
            } 
  
            if (sum < n) 
                freq[i]++; 
        } 
    } 

    for (ll i=MAX_CHAR-1; k < len && i >= 0; i--) 
        if (freq[i]) { 
            out[k++] = i + 'a'; 
            freq[i++]--; 
        } 
  
    // append string termination 
    // character and print result 
    out[k] = '\0'; 
    cout << out; 
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    precomputeFactorials();
    // ll high = 100005;
    // for(ll i = 0; i <)
    while(t--){
        ll n, k;
        cin >> n >> k;
        char str[n + 2];
        for(ll i = 0; i < n - 2; i++){
            str[i] = 'a';
        }
        str[n - 2] = 'b'; str[n - 1] = 'b';
        str[n] = '\0';
        // cout << str << endl;
        nPermute(str, k);
    }


    return 0;
}