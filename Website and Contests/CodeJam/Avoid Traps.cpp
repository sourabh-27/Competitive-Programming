#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool prime[100005];
void SieveOfEratosthenes() 
{
    for(int p=2; p*p<=100005; p++){ 
        if(prime[p] == true){ 
            for (int i=p*p; i<=100005; i += p) 
                prime[i] = false; 
        } 
    } 
}

int findAns(string str, int n, int index, int r1, int r2, vector<ll> number, long long * dp){
    // cout << "index: " << index << endl;
    if(index >= n - 1){
        // cout << "index2: " << index << endl;
        return 0;
    }
    if(str[index] == '*'){
        return -1;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    long double A = (long double)(number[index]) / (long double)(index);
    int ans = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;
    if(A >= (long double)(r1) / (long double)(r2)){
       ans = 1 + findAns(str, n, index + number[index], r1, r2, number, dp);
    }
    ans2 = 1 + findAns(str, n, index + 1, r1, r2, number, dp);
    ans3 = 1 + findAns(str, n, index + 2, r1, r2, number, dp);
    dp[index] = min(ans, min(ans2, ans3));
    return dp[index];
}

int main(){
    int t;
    cin >> t;
    memset(prime, true, 1000000);
    SieveOfEratosthenes();
    prime[0] = prime[1] = false;
    vector<ll> number(100002);
    ll count = 0;
    for(ll i = 1; i <= 100005; i++){
        if(prime[i]){
            count++;
        }
        number[i - 1] = count;
        // cout << number[i] << " ";
    }
    while(t--){
        int r1, r2;
        cin >> r1 >> r2;
        int n;
        cin >> n;
        long  long * dp = new long long[n + 5];
        for(ll i = 0; i <= n + 2; i++){
            dp[i] = -1;
        }
        string str;
        cin >> str;
        int ans = findAns(str, n, 0, r1, r2, number, dp);
        if(ans <= 0){
            cout << "No way!" << endl;
            continue;
        }
        cout << ans << endl;
    }
}