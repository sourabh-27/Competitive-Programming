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

class ValueDivision{
    public:
    vector<int> getArray(vector<int> vec){
        int size = vec.size();
        map<ll, ll> umap;
        for(int i = 0; i < size; i++){
            umap[vec[i]]++;
        }
        map<ll, ll>::reverse_iterator itr;
        ll count = 0;
        for(itr = umap.rbegin(); itr != umap.rend(); itr++){
            if(itr->second == 1){
                continue;
            }
            itr->second = itr->second + count;
            count = itr->second;
        }
        for(auto x: umap){
            cout << "x.first: " << x.first << " second: " << x.second << endl;
        }
        for(int i = 0; i < size; i++){
            if(vec[i] == 1 || umap[vec[i]] <= 1){
                continue;
            }
            else{
                ll k = vec[i];
                vec[i] = vec[i] - umap[vec[i]] + 1;
                umap[k]--;
            }
        }
        // int count = umap[num] / 2;
        // for(int i = 0; i < size; i++){
        //     if(vec[i] == num && count > 0){
        //         vec[i] = num - 1;
        //         count--;
        //     }
        // }
        return vec;
    }
};
int main()
{
    fast;
    int n;
    cin >> n;
    vector<int> vec;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        vec.pb(k);
    }
    ValueDivision obj;
    vector<int> ans = obj.getArray(vec);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}