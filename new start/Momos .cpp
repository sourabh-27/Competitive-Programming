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
    long long arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll q;
    cin >> q;
    long long arr2[q];
    ll temp = 0, j = 0, momos = 0, money_left = 0, sum = 0;
    for(int i = 0; i < q; i++)
    {
        cin >> arr2[i];
        while(temp <= arr2[i])
        {
            temp = temp + arr[j++];
        }
        temp = temp - arr[j - 1];
        momos = momos + j - 1;
        money_left = money_left + arr2[i] - temp;
        j = 0;
    } 
    cout << momos << " " << money_left << endl;
    return 0;
}