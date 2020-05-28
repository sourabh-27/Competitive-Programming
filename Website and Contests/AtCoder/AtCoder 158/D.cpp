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
int main()
{
    string str;
    cin >> str;
    ll q;
    cin >> q;
    deque<char> deq;
    for(ll i = 0; i < str.length(); i++){
        deq.pb(str[i]);
    }
    ll flag = 0;
    while(q--){
        ll t; cin >> t;
        // cout << "flag: " << flag << endl;
        if(t == 1){
            // cout << "before flag: " << flag << endl;
            flag = flag ^ 1;
            // cout << "after flag: " << flag << endl;
            continue;
        }
        ll f; char c;
        cin >> f >> c;
        if(flag == 0){
            if(f == 1){
                deq.push_front(c);
            }
            else{
                deq.pb(c);
            }
        }
        else if(flag == 1){
            if(f == 1){
                deq.pb(c);
            }
            else{
                deq.push_front(c);
            }
        }
    }
    if(flag == 0){
        while(!deq.empty()){
            char x = deq.front();
            deq.pop_front();
            cout << x;
        }
    }
    if(flag == 1){
        while(!deq.empty()){
            char x = deq.back();
            deq.pop_back();
            cout << x;
        }
    }

    return 0;
}