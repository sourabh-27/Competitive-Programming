#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define INF 0x3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
typedef long long int ll;

vector<string> possible = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
vector<string> given;

int main()
{
    fast;
    ll n, k;
    cin >> n >> k;
    for(ll i = 0; i < n; i++){
        string str;
        cin >> str;
        given.push_back(str);
    }
    findAns();


    return 0;
}