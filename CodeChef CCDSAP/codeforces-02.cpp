#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> vec1, vec2, vec3, vec4;
    for(ll i = 0; i < n; i++)
    {
        ll k;
        cin >> k;
        vec1.push_back(k);
    }
    for(ll i = 0; i < n; i++)   
    {
        ll k;
        cin >> k;
        vec2.push_back(k);
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    for(ll i = 0; i < n; i++)
    {
        if(vec1[i] > vec2[0])
        {
            vec3.push_back(m + vec2[0] - vec1[i]);
        }
        else
        {
            vec3.push_back((vec2[0] - vec1[i]));
        }
        // cout << vec3[i] << " ";
    }
    // cout << endl;
    sort(vec3.begin(), vec3.end());
    vec4 = vec1;
    ll temp = 0;
    while(vec4 != vec2)
    {
        if(vec4 != vec2)
        {
            vec4 = vec1;
            for(ll i = 0; i < n; i++)
            {
                vec4[i] = (vec4[i] + vec3[temp]) % m;
            }
        }
        sort(vec4.begin(), vec4.end());
        temp++;
    }
    if(temp == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << vec3[temp - 1] << endl;   
    }

    return 0;
}