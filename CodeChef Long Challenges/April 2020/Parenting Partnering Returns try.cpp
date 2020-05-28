#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

struct value{
    ll start, end, idx;
};

bool compare(value v1, value v2)
{
    return v1.start < v2.start;
}

void findAns(string &final, value array[], ll idx, ll startJ, ll endJ, ll startI, ll endI, ll n, string str){
    if(idx == n){
        final = str;
    }
    
    if(array[idx].start >= endJ)
    {
        ll newStart = array[idx].start;
        ll newEnd = array[idx].end;
        findAns(final, array, idx + 1, newStart, newEnd, startI, endI, n, str + 'J');
    }

    if(array[idx].start >= endI)
    {
        ll newStart2 = array[idx].start;
        ll newEnd2 = array[idx].end;
        findAns(final, array, idx + 1, startJ, endJ, newStart2, newEnd2, n, str + 'C');
    }
}

int main(){
    ll t;
    cin >> t;
    for(ll x = 1; x <= t; x++){
        ll n;
        cin >> n;
        value array[n + 1];
        for(ll i = 0; i < n; i++){
            ll x, y;
            cin >> x >> y;
            array[i].start = x;
            array[i].end = y;
            array[i].idx = i;
        }

        sort(array, array+n, compare);

        string final = ""; ll idx = 0;
        findAns(final, array, idx, 0, 0, 0, 0, n, "");

        if(final.empty()){
            cout << "CASE #" << x << ": IMPOSSIBLE" << endl;
        }
        else{
            cout << "CASE #" << x << ": ";
            for(ll i = 0; i < n; i++){
                for(ll j = 0; j < n; j++){
                    if(array[j].idx == i){
                        cout << final[j];
                    }
                }
            }
            cout << endl;
        }
    }
}