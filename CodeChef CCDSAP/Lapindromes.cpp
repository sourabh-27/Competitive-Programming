#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

// bool isEqual(int arr1[], int arr2[], int n, int m)
// {
//     if(n != m)
//     {
//         return false;
//     }
//     unordered_map<int, int>mp;
//     for(int i = 0; i < n; i++)
//     {
//         mp[arr1[i]]++;
//     }

//     for(int i = 0; i < n; i++)
//     {
//         if(mp.find(arr2[i]) == mp.end())
//         {
//             return false;
//         } 
//         if(mp[arr2[i]] == 0)
//         {
//             return false;
//         }
//         mp[arr2[i]]--;
//     }
//     return true;
// }
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int len = s.length();
        int arr[27] = {0}; int arr2[27] = {0};
        if(len % 2 == 0)
        {
            for(int i = 0; i < len / 2; i++)
            {
                arr[s[i] - 'a']++;
            }
            for(int i = len / 2; i < len; i++)
            {
                arr2[s[i] - 'a']++;
            }
        }
        else
        {
            for(int i = 0; i < len / 2; i++)
            {
                arr[s[i] - 'a']++;
            }
            for(int i = (len / 2) + 1; i < len; i++)
            {
                arr2[s[i] - 'a']++;
            }
        }
        // cout << arr[0] << " " << arr2[0] << endl;
        // cout << arr[1] << " " << arr2[1] << endl;
        // cout << len / 2 << endl;
        // bool ans = isEqual(arr, arr2, len / 2, len / 2);
        
        bool ans = true;
        for(int i = 0; i < 26; i++)
        {
            if(arr[i] != arr2[i])
            {
                ans = false;
            }
        }

        if(ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
        // else
        // {
        //     first = s.substr(0, len / 2);
        //     sec = s.substr(len / 2, len / 2);
        // }
    }

    return 0;
}