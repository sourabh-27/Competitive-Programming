#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int arr[200] = {0}; int arr2[200] = {0};
        ll len = s.length();
        if(len % 2 == 0)
        {
            for(ll i = 0; i < len / 2; i++)
            {
                arr[s[i]]++;
            }
            for(ll i = len / 2; i < len; i++)
            {
                arr2[s[i]]++;
            }
        }
        else
        {
            for(ll i = 0; i < len / 2; i++)
            {
                arr[s[i]]++;   
            }
            for(ll i = (len / 2) + 1; i < len; i++)
            {
                arr2[s[i]]++;
            }
        }
        int flag = 0;
        for(ll i = 0; i < len / 2; i++)
        {
            if(arr[s[i]] == arr2[s[i]])
            {
                // cout << arr[s[i]] << "  YOO" << endl;
                continue;
            }
            else
            {
                flag = 1;
                break;
            }
            // cout << arr[s[i]] << " arr[s[i]] "  << arr2[s[i]] << " arr2[s[i]] " << endl;
        }
        if(flag == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}