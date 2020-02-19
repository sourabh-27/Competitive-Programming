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
    ll q;
    cin >> q;
    ll arr[n + 1][n + 1];
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    ll count = 0; ll flag = 0; ll temp; ll temp2;
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            if(arr[i][j] == 0)
            {
                break;
            }
            else
            {
                count++;
                if(count == n)
                {
                    flag = 1;
                    temp = i;
                    break;
                }
            }
        }
        if(flag == 1)
        {
            break;
        }
        else
        {
            count = 0;
        }
    }
    flag = 0; count = 0;
    // cout << temp << "temp" << endl;
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            if(arr[j][i] == 0)
            {
                break;
            }
            else
            {
                count++;
                if(count == n)
                {
                    flag = 1;
                    temp2 = i;
                    break;
                }
            }
        }
        if(flag == 1)
        {
            break;
        }
        else
        {
            count = 0;
        }
    }
    // cout << temp2 << " temp2 " << endl;
    while(q--)
    {
        string x; ll y;
        cin >> x;
        cin >> y;
        if(x == "up")
        {
            cout << arr[0][temp2] << endl;
            for(ll i = 0; i < n - 1; i++)
            {
                arr[i][temp2] = arr[i + 1][temp2];
            }
            if(temp == 0)
            {
                for(ll i = 0; i < n; i++)
                {
                    arr[n - 1][i] = y;
                }
                temp = n - 1;
            }
            else
            {
                // cout << "YPPPP" << temp << endl;
                for(ll i = 0; i < n; i++)
                {
                    if(i == temp2)
                    {
                        continue;
                    }
                    arr[temp - 1][i] = arr[temp][i];
                }
                temp = temp - 1;
            }
            for(ll i = 0; i < n; i++)
            {
                if(i == temp2)
                {
                    continue;
                }
                if(temp == n - 1)
                {
                    arr[0][i] = 0;
                }
                else
                {
                    arr[temp + 1][i] = 0;
                }
            }
            arr[n - 1][temp2] = y;
            // for(ll i = 0; i < n; i++)
            // {
            //     for(ll j = 0; j < n; j++)
            //     {
            //         cout << arr[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        }
        else if(x == "down")
        {
            cout << arr[n - 1][temp2] << endl;
            for(ll i = n - 1; i >= 1; i--)
            {
                arr[i][temp2] = arr[i - 1][temp2];
            }
            if(temp == n - 1)
            {
                for(ll i = 0; i < n; i++)
                {
                    arr[0][i] = y;
                }
                temp = 0;
            }
            else
            {
                // cout << "YPPPP" << temp << endl;
                for(ll i = 0; i < n; i++)
                {
                    if(i == temp2)
                    {
                        continue;
                    }
                    arr[temp + 1][i] = arr[temp][i];
                }
                temp = temp + 1;
            }
            for(ll i = 0; i < n; i++)
            {
                if(i == temp2)
                {
                    continue;
                }
                if(temp == 0)
                {
                    arr[n - 1][i] = 0;
                }
                else
                {
                    arr[temp - 1][i] = 0;
                }
            }
            arr[0][temp2] = y;
            // for(ll i = 0; i < n; i++)
            // {
            //     for(ll j = 0; j < n; j++)
            //     {
            //         cout << arr[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        }
        else if(x == "left")
        {
            cout << arr[temp][0] << endl;
            for(ll i = 0; i < n - 1; i++)
            {
                arr[temp][i] = arr[temp][i + 1];
            }
            if(temp2 == 0)
            {
                for(ll i = 0; i < n; i++)
                {
                    arr[i][n - 1] = y;
                }
                temp2 = n - 1;
            }
            else
            {
                // cout << "YPPPP" << temp << endl;
                for(ll i = 0; i < n; i++)
                {
                    if(i == temp)
                    {
                        continue;
                    }
                    arr[i][temp2 - 1] = arr[i][temp2];
                }
                temp2 = temp2 - 1;
            }
            for(ll i = 0; i < n; i++)
            {
                if(i == temp)
                {
                    continue;
                }
                if(temp2 == n - 1)
                {c
                    arr[i][0] = 0;
                }
                else
                {
                    arr[i][temp2 + 1] = 0;
                }
            }
            arr[temp][n - 1] = y;
        }
        else if(x == "right")
        {
            cout << arr[temp][n - 1] << endl;
            for(ll i = n - 1; i >= 1; i--)
            {
                arr[temp][i] = arr[temp][i - 1];
            }
            if(temp2 == n - 1)
            {
                for(ll i = 0; i < n; i++)
                {
                    arr[i][0] = y;
                }
                temp2 = 0;
            }
            else
            {
                // cout << "YPPPP" << temp << endl;
                for(ll i = 0; i < n; i++)
                {
                    if(i == temp)
                    {
                        continue;
                    }
                    arr[i][temp2 + 1] = arr[i][temp2];
                }
                temp2 = temp2 + 1;
            }
            for(ll i = 0; i < n; i++)
            {
                if(i == temp)
                {
                    continue;
                }
                if(temp2 == 0)
                {
                    arr[i][n - 1] = 0;
                }
                else
                {
                    arr[i][temp2 - 1] = 0;
                }
            }
            arr[temp][0] = y;
            // for(ll i = 0; i < n; i++)
            // {
            //     for(ll j = 0; j < n; j++)
            //     {
            //         cout << arr[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        }
    }

    return 0;
}