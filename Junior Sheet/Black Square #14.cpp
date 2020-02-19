#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[5];
    for(int i = 1 ; i <= 4; i++)
    {
        cin >> arr[i];
    }
    string s;
    cin >> s;
    int m = s.length();
    int count = 0;
    for(int i = 0; i < m; i++)
    {
        count += arr[(int)(s[i]- 48)];
    }

    cout << count << endl;

    return 0;
}