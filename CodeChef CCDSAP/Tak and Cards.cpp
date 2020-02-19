#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void tries(long long * arr, ll n, ll sum, ll currIndex, vector<pair<ll, ll>> &pVec, ll count)
{
    if(currIndex > n)
    {
        return;
    }
    if(currIndex == n)
    {
        pair<ll, ll> temp;
        temp.first = sum;
        temp.second = count;
        pVec.push_back(temp);
    }
    tries(arr, n, sum + arr[currIndex], currIndex + 1, pVec, count + 1);
    tries(arr, n, sum, currIndex + 1, pVec, count);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, a;
    cin >> n >> a;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<pair<ll, ll>> pVec;
    tries(arr, n, 0, 0, pVec, 0);
    ll count2 = 0;
    for(ll i = 0; i < pVec.size() - 1; i++)
    {
        // if((pVec[i].first / pVec[i].second) == a && (pVec[i].first % pVec[i].second == 0))
        // {
        //     count2++;
        // }
        if(pVec[i].first % pVec[i].second == 0)
        {
            if(pVec[i].first / pVec[i].second == a)
            {
                count2++;
            }   
        }
    }
    cout << count2 << endl;

    return 0;
}