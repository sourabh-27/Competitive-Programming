#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int m = s.length();
    int arr[m];
    for(int i = 0; i < m - 1; i++)
    {
        arr[i] = abs((int)(s[i] - 48) - (int)(s[i + 1] - 48));
    }
    int sum = 0;
    arr[m - 1] = abs((int)(s[0] - 48) - (int)('a' - 48));
    for(int i = 0; i < m ; i++)
    {
        if(arr[i] > 13)
        {
            sum += 26 - arr[i];
        }
        else
        {
            sum += arr[i];
        }
    }

    cout << sum << endl;

    return 0;
}