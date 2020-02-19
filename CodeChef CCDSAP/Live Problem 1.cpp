#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

int main() {
    int n,m,x;
    cin>>n>>m;
    priority_queue<int> pq;
    //read n numbers
    // int a[n];
    for(int i=0;i<n;i++){          //nlogn
        cin>>x;
        pq.push(x);
    }
    ll q; ll temp = 0;
    for(int i=0;i<m;i++){          // M
        cin >> q;
        ll ans;
        while(temp != q)
        {
            ll x = pq.top();
            pq.pop();
            ans = x;
            x = x / 2;
            if(x > 0)
            {
                pq.push(x);
            }
            temp++;
        }
        cout << ans << endl;
    }
    // //pick largest and divide and conditionally push
    // int j = 0;// # of element popped
    // for(int i=0;i<m;){
    //     // if(!pq.empty()){
    //         x = pq.top();
    //         pq.pop();               //logN
    //         j++;
    //         if(q[i] == j){
    //             cout<<x<<endl;
    //             i++;
    //         }
    //         if(x/2 > 0 )
    //             pq.push(x/2);       //logN
    //     // }
    // }
    return 0;
}
