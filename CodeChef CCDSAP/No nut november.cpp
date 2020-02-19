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
        ll k, n;
        cin >> k >> n;
        char arr[n + 1];
        for(ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        bool * visited = new bool[n + 1];
        memset(visited, false, sizeof(visited));

        ll count = 0, count2 = 0;
        for(ll i = 1; i <= n; i++)
        {
            if(arr[i] == 'N')
            {
                continue;
            }
            else
            {
                for(ll j = i - k; j < i; j++)
                {
                    if(j <= 0 || j > n)
                    {
                        continue;
                    }
                    else
                    {
                        if(arr[j] == 'N' && !visited[j])
                        {
                            visited[i] = true;
                            count++;
                            visited[j] = true;
                            // cout << "Count value: " << count << endl;
                            break;
                        }
                    }
                }
                if(!visited[i])
                {
                    for(ll j = i + k; j > i; j--)
                    {
                        if(j <= 0 || j > n)
                        {
                            continue;
                        }
                        else
                        {
                            if(arr[j] == 'N' && !visited[j])
                            {
                                visited[i] = true;
                                count++;
                                visited[j] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        for(ll i = 1; i <= n; i++)
        {
            if(arr[i] == 'N')
            {
                continue;
            }
            else
            {
                for(ll j = i + k; j > i; j--)
                {
                    if(j <= 0 || j > n)
                    {
                        continue;
                    }
                    else
                    {
                        if(arr[j] == 'N' && !visited[j])
                        {
                            visited[i] = true;
                            count2++;
                            visited[j] = true;
                            break;
                        }
                    }
                }
                
                if(!visited[i])
                {
                    for(ll j = i - k; j < i; j++)
                    {
                        if(j <= 0 || j > n)
                        {
                            continue;
                        }
                        else
                        {
                            if(arr[j] == 'N' && !visited[j])
                            {
                                visited[i] = true;
                                count2++;
                                visited[j] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        ll maxi = max(count, count2);
        cout << maxi << endl;
    }

    return 0;
}