#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int palin(string str) 
{ 
    int n = str.length(); 
    int i, j, k; 
    int dp[n][n];
    string new = "";
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < n; i++) 
    {
        dp[i][i] = 1;
    }
	for(k = 2; k <= n; k++) 
	{ 
		for(i = 0; i < n - k + 1; i++) 
		{ 
			j = i + k - 1; 
			if (str[i] == str[j] && k == 2) 
			dp[i][j] = 2; 
			else if (str[i] == str[j] && str[i] != str[i + 1] && str[j] != str[j - 1]) 
			dp[i][j] = dp[i + 1][j - 1] + 2; 
			else
			dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]); 
		} 
	} 

    return dp[0][n - 1];
} 

int main() 
{ 
	string str;
    cin >> str;
	ll ans = palin(str);
    if(ans % 2 == 0)
    {
        cout << ans << endl;
    }
    else
    {
        cout << ans - 1 << endl;
    }
	return 0; 
} 
