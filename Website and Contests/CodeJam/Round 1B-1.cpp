#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;
#define maxii 100000000

long long preCompute[100];

void calculate(){
    ll count = 1;
    preCompute[0] = 1;
    for(ll i = 1; i <= 30; i++){
        count = count * 2;
        preCompute[i] = count;
        // cout << "i: " << i << " count: " << count << endl;
    }
}

vector<ll> possibilities;

void findAns(ll sum, ll index){
    if(index > 40){
        return;
    }
    possibilities.push_back(sum);
    findAns(sum + possibilities[index], index + 1);
    findAns(sum - possibilities[index], index + 1);
    return;
}

// vector<string> vec;
// void isPossible(ll start, ll end, ll x, ll y, string str, ll index){
//     // cout << "start: " << start << " end: " << end << endl;
//     if(start == x && end == y){
//         vec.push_back(str);
//         return;
//     }
//     if(index > 30){
//         return;
//     }
//     if(x >= 0 && (start > x || start < -x)){
//         // cout << "YO1" << endl;
//         return;
//     }
//     if(y >= 0 && (end > y || end < -y)){
//         // cout << "YO2" << endl;
//         return;
//     }
//     if(x < 0 && (start < x || start > abs(x))){
//         // cout << "YO3" << endl;
//         return;
//     }
//     if(y < 0 && (end < y || end > abs(y))){
//         // cout << "YO4" << endl;
//         return;
//     }
//     isPossible(start + preCompute[index], end, x, y, str + 'E', index + 1);
//     isPossible(start, preCompute[index] + end, x, y, str + 'N', index + 1);
//     isPossible(start - preCompute[index], end, x, y, str + 'W', index + 1);
//     isPossible(start, end - preCompute[index], x, y, str + 'S', index + 1);
//     return;
// }
 
int main()
{
    fast;
    ll t;
    cin >> t;
    calculate();
    for(ll xTe = 1; xTe <= t; xTe++){
        ll x, y;
        cin >> x >> y;
        findAns(0, 0);
        for(ll i = 0; i < possibilities.size(); i++){
            cout << possibilities[i] << " ";
        }
        cout << endl;
    }


    return 0;
}