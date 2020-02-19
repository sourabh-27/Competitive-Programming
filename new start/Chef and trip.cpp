#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll temp, temp2, temp3, temp4;
        int flag = 0; int flag2 = 0;
        for(ll i = 1; i < n - 1; i++)
        {
            temp = arr[i - 1] - 1;
            temp2 = arr[i + 1] - 1;
            temp3 = arr[i - 1] + 1;
            temp4 = arr[i + 1] + 1;
            if(temp >= 1 && temp <= k && temp != arr[i + 1] && arr[i] == -1)
            {
                arr[i] = temp;
            }
            else if(temp2 >= 1 && temp2 <= k && temp2 != arr[i - 1] && arr[i] == -1)
            {
                arr[i] = temp2;
            }
            else if(temp3 >= 1 && temp3 <= k && temp3 != arr[i + 1] && arr[i] == -1)
            {
                arr[i] = temp3;
            }
            else if(temp4 >= 1 && temp4 <= k && temp4 != arr[i - 1] && arr[i] == -1)
            {
                arr[i] = temp4;
            }
            else if(arr[i - 1] == -1 && arr[i + 1] == -1 && arr[i] == -1)
            {
                arr[i] = 1;
            }
            else if(arr[i] != -1 && arr[i - 1] != arr[i] && arr[i + 1] != arr[i])
            {
                continue;
            }
            else
            {
                flag2 = 1;
            }
        }

        // cout << "flag : " << flag2 << endl;

        temp = arr[1] + 1;
        temp2 = arr[1] - 1;
        if(temp >= 1 && temp <= k && arr[0] == -1)
        {
            arr[0] = temp;
        }
        else if(temp2 >= 1 && temp2 <= k && arr[0] == -1)
        {
            arr[0] = temp2;
        }
        else
        {
            flag = 1;
        }

        if(arr[0] != -1 && arr[0] != arr[1])
        {
            flag = 0;
        }
        

        temp3 = arr[n - 2] - 1;
        temp4 = arr[n - 2] + 1;
        if(temp3 >= 1 && temp3 <= k && arr[n - 1] == -1)
        {
            arr[n - 1] = temp3;
        }
        else if(temp4 >= 1 && temp4 <= k && arr[n - 1] == -1)
        {
            arr[n - 1] = temp4;
        }
        else
        {
            flag = 1;
        }

        if(arr[n - 1] != -1 && arr[n - 1] != arr[n - 2])
        {
            flag = 0;
        }    

        if(n == 1 && arr[0] == -1)
        {
            flag = 0;
            flag2 = 0;
            arr[0] = 1;
        }    

        if(flag == 1 || flag2 == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for(ll i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        
    }

    return 0;
}