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
    vector<ll> vec;
    ll arr[n + 1]; ll arr2[n + 1];
    vector<ll> idx;
    for(ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr2[i] = arr[i];
        if(arr[i] == 0)
        {
            idx.push_back(i);
        }
    }
    sort(arr, arr + n + 1, greater<int>());
    // for(ll i = 1; i <= n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    ll end = n;
    for(ll i = 1; i <= n; i++)
    {
        if(end < 1)
        {
            break;
        }
        if(arr[i] == end)
        {
            end--;
            continue;
        }
        else
        {
            // cout << "end: " << end << endl;
            vec.push_back(end);
            end--;
            i--;
        }
    }
    // cout << "I am right now her" << endl;

    vector<ll> similar;
    vector<ll> index2;
    for(ll i = 0; i < idx.size(); i++)
    {
        if(idx[i] == vec[i])
        {
            similar.push_back(vec[i]);
            index2.push_back(idx[i]);
        }
    }

    cout << "I am right now here" << endl;
    for(ll i = 0; i < similar.size(); i++)
    {
        cout << similar[i] << " ";
    }
    cout << endl;
    // similar[similar.size() - 1] = similar[0];

    for(ll i = 0; i < idx.size(); i++)
    {
        arr2[idx[i]] = vec[i];
    }

    // for(ll i = 0; i < index2.size(); i++)
    // {
    //     arr2[index2[i]] = similar[i];
    // }

    // for(ll i = 0; i < idx.size(); i++)
    // {
    //     cout << idx[i] << " ";
    // }
    // cout << endl;

    // for(ll i = 0; i < vec.size(); i++)
    // {
    //     cout << vec[i] << " ";
    // }
    // cout << endl;

    for(ll i = 1; i <= n; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}