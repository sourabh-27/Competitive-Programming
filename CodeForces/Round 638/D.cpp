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
typedef long long int ll;

vector<ll> vec; int flag = 0;
bool findAns(long double n){
    cout << "n: " << n << endl;
    if(n < 1){
        return false;
    }
    if(flag == 1){
        return false;
    }
    if(n == 1 && flag == 0){
        flag = 1;
        return true;
    }
    bool ans1 = false;
    bool ans2 = false;
    if(flag != 1){
        ans1 = findAns((long double)((long double)(n / 2) - 1));
    }
    if(flag != 1){
        ans2 = findAns((long double)(n - 1));
    }
    if(ans1){
        if(flag == 1){
            if(vec.empty()){
                vec.pb(1);
            }
            else{
                vec.pb(vec[vec.size() - 1] * 2);
            }
        }
        return true;
    }
    else if(ans2){
        if(flag == 1){
            vec.pb(0);
        }
        return true;
    }
    else{
        vec.clear();
        return false;
    }
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        long double n;
        cin >> n;
        bool ans = findAns(n);
        if(ans){
            // cout << "YES" << endl;
            cout << vec.size() << endl;
            for(ll i = 0; i < vec.size(); i++){
                cout << vec[i] << " ";
            }
            cout << endl;
        }
        else{
            cout << -1 << endl;
        }
    }


    return 0;
}