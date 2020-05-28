#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;
 
bool prime[1000005];
void SieveOfEratosthenes() 
{
    for(int p=2; p*p<=100005; p++){ 
        if(prime[p] == true){ 
            for (int i=p*p; i<=100005; i += p) 
                prime[i] = false; 
        } 
    } 
}

int main(){
    memset(prime, true, 1000000);
    SieveOfEratosthenes();
    prime[0] = prime[1] = false;
    //to count prime no.'s till n ---------------below---------------
    vector<ll> number(100002);
    ll count = 0;
    for(ll i = 1; i <= 100005; i++){
        if(prime[i]){
            count++;
        }
        number[i - 1] = count;
        // cout << number[i] << " ";
    
}