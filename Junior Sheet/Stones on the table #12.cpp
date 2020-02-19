#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    int m = s.length();
    for(int i = 0; i < m - 1; i++)
    {
        if(s[i] == s[i + 1])
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}