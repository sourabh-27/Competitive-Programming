#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
char arr[100001];
ll multi[100001][4];

void apply(vector<ll> list[], ll node, ll parent)
{    //cout << node << '\n';
    //cout<<"i am in node "<<node<<" "<<endl;

    //handling the base case
    if(list[node].size() == 1){
        ll val = arr[node] - 65;//getting val
        multi[node][val]++;
    }
    else{
        for (ll i = 0; i < list[node].size(); i++) {
        if (list[node][i] != parent)
            {
                 apply(list,list[node][i], node);
                 for(int col = 0; col<4; col++){
                     ll child  = list[node][i];
                     multi[node][col] += multi[child][col];
                 }
			}
        }
        ll val = arr[node] - 65;//getting val
        multi[node][val]++;
    }
}
void addEdge(vector<ll> adj[], ll u, ll v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void process(vector<ll> adj[]){
    apply(adj, 1, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(multi, 0, sizeof(multi));
    ll n;
    cin>>n;
    vector<ll> tree[n+1];
    tree[1].push_back(0);
    //storing the value in character array
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }
    
    ll temp1, temp2;
    for(int i = 0; i< (n-1) ; i++){
            cin>>temp1>>temp2;
            addEdge(tree, temp1 , temp2);
        }//adding edges in tree
    
    process(tree);// calling the dfs

    //queries ahead
    for(int i = 1; i<=n; i++){
        char c;
        cin>>c;
        ll val = c - 65;//getting val
        cout<<multi[i][val]<<" ";
    }
    cout<<endl;
    // for(int i = 1; i<=n; i++){
    //     for(int j = 0; j<4; j++){
    //         cout<<multi[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}
// 14
// D A C B C D A B D A D C A B
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 5 10
// 5 11
// 3 7
// 3 8
// 3 9
// 7 12
// 8 13
// 9 14
// A C D C A D B A C D B B C C