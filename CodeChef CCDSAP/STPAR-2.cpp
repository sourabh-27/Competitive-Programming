#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    while(n != 0)
    {
        ll arr[n];
        stack <ll> s;
        ll index = 1;
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            int flag = 0;
            if(arr[i] == index)
            {
                // cout << arr[i] << endl;
                index++;
                flag = 1;
            }
            if(!s.empty() && s.top() == index && flag == 1)
            {
                flag  = 0;
                while(!s.empty() && s.top() == index)
                {
                    // cout << index << endl;
                    index++;
                    s.pop();
                }
            }
            else if(flag == 0)
            {
                s.push(arr[i]);
                // cout << "pushed: " << arr[i] << endl;
            }
        }

        int flag2 = 0;
        while(!s.empty())
        {
            if(s.top() == index)
            {
                index++;
                // cout << s.top() << " ";
                s.pop();
            }
            else
            {
                flag2 = 1;
                break;
            }
        }
        if(flag2 == 0)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        cin >> n;
    }

    return 0;
}