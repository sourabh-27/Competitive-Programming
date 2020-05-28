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
typedef unsigned long long int ull;

ll x, y, l, r;
void oppositeFill(ll k, int * arr){
    int * temp = new int[64];
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i < 63; i++){
        temp[i] = k % 2;
        k /= 2;
        if(k == 0 || k == 0){
            temp[i + 1] = k;
            break;
        }
    }
    for(int i = 0; i < 63; i++){
        arr[i] = temp[62 - i];
    }
}

ull numConvert(int * arr){
    ull res = 0;
    int count = 1;
    for(int i = 62; i >= 0; i--){
        if(arr[i] == 0){
            continue;
        }
        else{
            res = res + arr[i] * count;
        }
        count = count * 2;
    }
    return res;
}

ull findMax(ull z){
    if(x == 0 || y == 0){
        return 0;
    }
    else{
        ull res = ((x & z) * (y & z));
        return res;
    }
}

bool comp(pair<ull, ull> &p1, pair<ull, ull> &p2){
    if(p2.second == p1.second){
        return p1.first < p2.first;
    }
    else{
        return p2.second < p1.second;
    }
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        cin >> x >> y >> l >> r;
        int xXORyArr[64], rightArr[64];
        memset(xXORyArr, 0, sizeof(xXORyArr));
        memset(rightArr, 0, sizeof(rightArr));
        ll k = x | y;
        oppositeFill(k, xXORyArr);
        oppositeFill(r, rightArr);

        int * possible = new int[64];
        memset(possible, 0, sizeof(possible));
        for(int i = 0; i < 63; i++){
            possible[i] = (xXORyArr[i] & rightArr[i]);
            // cout << "i: " << i << " possible[i]: " << possible[i] << endl;
        }

        vector<pair<ull, ull>> vec;
        ull p1 = numConvert(possible);
        // cout << "p1: " << p1 << endl;
        ull value = findMax(p1);
        vec.pb({p1, value});

        for(int i = 0; i < 63; i++){
            if(rightArr[i] == 1){
                int temp[64];
                memset(temp, 0, sizeof(temp));
                for(int j = i + 1; j < 63; j++){
                    temp[j] = xXORyArr[j];
                }
                for(int j = i - 1; j >= 0; j--){
                    temp[j] = possible[j];
                }
                ull p2 = numConvert(temp);
                ull value2 = findMax(p2);
                vec.pb({p2, value2});
            }
        }

        sort(all(vec), comp);
        // for(ll i = 0; i < vec.size(); i++){
        //     cout << "first: " << vec[i].first << " second: " << vec[i].second << endl;
        // }
        ull ans = vec[0].first; ull finalVal = vec[0].second;
        if(finalVal == 0){
            cout << 0 << endl;
        }
        else{
            cout << ans << endl;
        }
    }


    return 0;
}