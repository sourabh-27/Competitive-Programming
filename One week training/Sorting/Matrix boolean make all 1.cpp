#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1][n + 1];
    unordered_map<ll, bool> umap1, umap2, majorDiagonal, minorDiagonal;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                umap1.insert({i, true});
                umap2.insert({j, true});
                majorDiagonal.insert({i - j, true});
                minorDiagonal.insert({i + j, true});
            }
        }
    }

    // for(ll i = 1; i <= n; i++){
    //     if(umap1[i] == true){
    //         for(ll j = 1; j <= n; j++){
    //             arr[i][j] = 1;
    //         }
    //     }

    //     if(umap2[i] == true){
    //         for(ll j = 1; j <= n; j++){
    //             arr[j][i] = 1;
    //         }
    //     }
    // }

    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            if(umap1.find(i) != umap1.end() || umap2.find(j) != umap2.end() || majorDiagonal.find(i - j) != majorDiagonal.end() || minorDiagonal.find(i + j) != minorDiagonal.end()){
                arr[i][j] = 1;
            }
        }
    }

    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}