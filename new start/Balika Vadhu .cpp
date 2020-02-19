#include <bits/stdc++.h>
using namespace std;

string ans = "";
string blessingHelper(string b1, string b2, int m, int n)
{
    if(m == 0 || n == 0)
    {
        return "";
    }
    
    if(b1[0] == b2[0])
    {
        ans += b1[0];
        ans2 += b1[0];
        blessingHelper(b1.substr(1), b2.substr(1), m - 1, n - 1);
    }
    else
    {
        string option1 = blessingHelper(b1.substr(1), b2, m - 1, n);
        string option2 = blessingHelper(b1, b2.substr(1), m, n - 1);
        ans = ans - option2;
        unsigned int maxi = max(option1.length(), option2.length());
        if(option1.length() == maxi)
        {
            ans += option1;
        }
        else if(option2.length() == maxi)
        {
            ans += option2;
        }
    }
    
    return ans;
}

int blessing(string b1, string b2, int k)
{
    int m = b1.length();
    int n = b2.length();
    int ** dp = new int * [m + 1];
    for(int i = 0; i <= m; i++)
    {
        dp[i] = new int[n + 1];
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    
    string s3 = blessingHelper(b1, b2, m, n);
    
    int size = s3.length();
    if(size < k)
    {
        return 0;
    }
    cout << s3 << endl;
    vector<int> dp2; int sum = 0; int max = INT_MIN;
    for(int x = 0; x <= k - 1; x++)
    {
        int z = s3[x];
        sum = sum + z;
    }
    if(sum > max)
    {
        max = sum;
    }
    
    for(int x = k, y = 0; x <= size - 1 && y <= size - 1 - k; x++, y++)
    {
        int z = s3[x];
        int z2 = s3[y];
        sum = sum + z - z2;
        if(sum > max)
        {
            max = sum;
        }
    }
    
    for(int i = 0; i <= m; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
    s3 = "";
    return max;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string b1, b2;
        cin >> b1 >> b2;
        int k;
        cin >> k;
        int ans = blessing(b1, b2, k);
        cout << ans << endl;
    }
    return 0;
}
