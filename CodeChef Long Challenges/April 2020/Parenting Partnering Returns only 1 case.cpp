#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
typedef long long int ll;

struct value{
    ll arr, dep;
};

bool intersect(value v1, value v2){
    if(v2.arr >= v1.dep || v2.dep <= v1.arr){
        // cout << "Intersecition points" << endl;
        return false;
    }
    return true;
}
 
int main()
{
    // fast;
    ll t;
    cin >> t;
    for(ll x = 1; x <= t; x++){
        ll n;
        cin >> n;
        struct value time[n + 1];
        for(ll i = 0; i < n; i++){
            cin >> time[i].arr >> time[i].dep;
        }

        string ans = ""; bool poss = false;
        vector<value> vec1, vec2;
        for(ll i = 0; i < n; i++){
            value curr = time[i];
            ll flag = 0;
            for(ll j = 0; j < vec1.size(); j++){
                if(intersect(vec1[j], curr)){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                vec1.push_back(curr);
                ans = ans + 'C';
                continue;
            }
            ll flag2 = 0;
            for(ll j = 0; j < vec2.size(); j++){
                if(intersect(vec2[j], curr)){
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0){
                vec2.push_back(curr);
                ans = ans + 'J';
                continue;
            }
            if(flag == 1 && flag2 == 1){
                poss = true;
                break;
            }
        }
        if(poss){
            cout << "Case #" << x << ": IMPOSSIBLE" << endl; 
        }
        else{
            cout << "Case #" << x << ": " << ans << endl;
        }
    }

    return 0;
}