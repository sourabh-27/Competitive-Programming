#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    while(n != 0)
    {
        ll arr[n];
        ll index = 1;
        stack<ll> s;
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i] == index)
            {
                cout << "1st: " << arr[i] << endl;
                cout << index << " " << endl;
                index++;
            }
            if(!s.empty() && s.top() == index && arr[i] == index)
            {
                cout << "2nd: " << arr[i] << endl;
                cout << "index: " << index << endl;
                while(!s.empty() && s.top() == index)
                {
                    cout << "index: " << index << endl;
                    index++;
                    cout << s.top() << " " << endl;
                    s.pop();
                }
            }
            else
            {
                s.push(arr[i]);
                cout << "pushed : " << arr[i] << endl;
            }      
        }

        int flag = 0;
        while(!s.empty())
        {
            if(s.top() == index)
            {
                index++;
                cout << s.top() << " ";
                s.pop();
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
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