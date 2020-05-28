#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

class value{
    public:
    ll arr, dep;
    value(){
        arr = dep = -1;
    }
};

bool compare(value v1, value v2){
    if(v1.arr == v2.arr){
        return v1.dep < v2.dep;
    }
    return v1.arr < v2.arr;
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    for(ll x = 1; x <= t; x++){
        ll n;
        cin >> n;
        struct value time[n + 1], original[n + 1];
        for(ll i = 0; i < n; i++){
            cin >> time[i].arr >> time[i].dep;
            original[i].arr = time[i].arr;
            original[i].dep = time[i].dep;
        }

        sort(time, time + n, compare);
        bool ** visited = new bool*[1444];
        for(ll i = 0; i <= 1443; i++){
            visited[i] = new bool[1444];
            for(ll j = 0; j <= 1443; j++){
                visited[i][j] = false;
            }
        }
        map<pair<ll, ll>, string> store;
        ll flag = 0;
        ll temp1 = time[0].dep; ll temp2 = time[1].dep;
        store[make_pair(time[0].arr, time[0].dep)] += 'C';
        store[make_pair(time[1].arr, time[1].dep)] += 'J';
        for(ll i = 2; i < n; i++){
            if(store[make_pair(time[i].arr, time[i].dep)].size() > 2){
                flag = 1;
                break;
            }
            if(time[i].arr >= temp1){
                temp2 = temp1;
                temp1 = time[i].dep;
                store[make_pair(time[i].arr, time[i].dep)] += 'C';
            }
            else if(time[i].arr >= temp2 && store[make_pair(time[i].arr, time[i].dep)].size() < 2){
                temp2 = time[i].dep;
                store[make_pair(time[i].arr, time[i].dep)] += 'J';
            }
            else{
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            cout << "Case #" << x << ": " << "IMPOSSIBLE" << endl;
        }
        else{
            // string ans = "";
            cout << "Case #" << x << ": ";
            for(ll i = 0; i < n; i++){
                if(visited[original[i].arr][original[i].dep]){
                    cout << store[make_pair(original[i].arr, original[i].dep)][1];
                    continue;
                }
                cout << store[make_pair(original[i].arr, original[i].dep)][0];
                visited[original[i].arr][original[i].dep] = true;
            }
            cout << endl;
            // cout << ans << endl;
        }

    }

    return 0;
}