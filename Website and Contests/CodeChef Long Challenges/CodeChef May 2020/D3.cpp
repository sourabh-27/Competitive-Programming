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
#define print(v); for(auto x:v) cout<<x<<" "; cout<<endl;
typedef unsigned long long int ull;

ull power(ull a, ull b){
    ull start = 1;
    for(ull i = 0; i < b; i++){
        start = start * 2;
    }
    return start;
}

int main()
{
    fast;
    ull t;
    cin >> t;
    while(t--){
        ull x, y, l, r;
        cin >> x >> y >> l >> r;
        if(x == 0 || y == 0){
            cout << 0 << endl;
            continue;
        }
        unsigned long long int k = x | y;
        if(k <= r){
            cout << k << endl;
        }
        else{
            ull z = log2(r);
            // cout << "z: " << z << endl;
            ull pow = power(2, log2(r)) - 1;
            // cout << "pow: " << pow << endl;
            // cout << (k&pow) << endl;
            if((x&(k&pow)) == 0 || (y&(k&pow)) == 0){
                cout << 0 << endl;
            }
            else{
                cout << (k&pow) << endl;
            }
        }
    }


    return 0;
}