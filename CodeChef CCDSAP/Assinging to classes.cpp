#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

struct value{
    ll val, pos;
};

bool compare(value T1, value T2)
{
    if(T1.val <= T2.val)return true;
    else
    {
        return false;
    }
    
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll> front;
        vector<ll> back;
        struct value arr[n + 1]; struct value arr2[n + 1];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i].val;
        }
        for(ll i = 0; i < n; i++)
        {
            cin >> arr2[i].val;
        }
        sort(arr, arr + n, compare);
        sort(arr2, arr2 + n, compare);
        for(ll i = 0; i < n; i++)
        {
            cout << arr[i].val << " ";
        }
        for(ll i = 0; i < n; i++)
        {
            cout << arr2[i].val << " ";
        }
        cout << endl;
        ll t1 = 0; ll t2 = 0; ll k = 0;
        while(t1 < n && t2 < n)
        {
            cout << "t1: " << t1 << " t2: " << t2 << endl;
            if(arr[t1].val <= arr2[t2].val)
            {
                arr[t1].pos = k;
                if(k % 2 == 0)
                {
                    front.push_back(arr[t1].val);
                }
                else
                {
                    back.push_back(arr[t1].val);
                }
                t1++;
                k++;
            }
            else
            {
                arr2[t2].pos = k;
                if(k % 2 == 0)
                {
                    front.push_back(arr[t2].val);
                }
                else
                {
                    back.push_back(arr[t2].val);
                }
                t2++;
                k++;
            }  
        }
        while(t1 < n)
        {
            arr[t1].pos = k;
            t1++; k++;
        }
        while(t2 < n)
        {
            arr2[t2].pos = k;
            t2++; k++;
        }
        // ll first = n / 2; ll second = (n / 2) + n;
        // cout << "first : " << first  << " second: " << second << endl;
        // ll ans1, ans2;
        // for(ll i = 0; i < n; i++)
        // {
        //     if(arr[i].pos == first || arr[i].pos == second)
        //     {
        //         ans1 = arr[i].val;
        //     }
        // }
        // for(ll i = 0; i < n; i++)
        // {
        //     cout << "arr[i]: " << arr[i].val << " pos: " << arr[i].pos << endl;;
        // }
        // for(ll i = 0; i < n; i++)
        // {
        //     cout << "arr2[i]: " << arr2[i].val << " pos2: " << arr2[i].pos << endl;
        // }

        // for(ll i = 0; i < n; i++)
        // {
        //     if(arr[i].pos == first || arr[i].pos == second)
        //     {
        //         ans2 = arr2[i].val;
        //     }
        // }
        
        // ll ans = abs(ans1 - ans2);
        // cout << ans << endl;

        sort(front.begin(), front.end());
        sort(back.begin(), back.end());
        ll ans = abs(front[n / 2] - back[n / 2]);
        cout << ans << endl;
    }

    return 0;
}