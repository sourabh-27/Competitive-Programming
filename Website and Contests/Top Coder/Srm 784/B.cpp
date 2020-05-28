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

class MaximumBalances{
    public:
    int solve(string str){
        int len = str.length(); 
        int opening = 0, closing = 0;
        for(int i = 0; i < len; i++){
            if(str[i] == '('){
                opening++;
            }
            else{
                closing++;
            }
        }
        int ans = min(opening, closing);
        ans = pow(2, ans) - 1;
        return ans;
    }
};
int main()
{
    fast;
    string str;
    cin >> str;
    MaximumBalances obj;
    cout << obj.solve(str) << endl;


    return 0;
}