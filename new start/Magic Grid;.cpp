#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int r, c;
        cin >> r >> c;
        int input[r][c];
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                cin >> input[i][j];
            }
        }
        cout << r << c << endl;
        int ** dp = new int *[r];
        for(int i = 0; i < c; i++)
        {
            dp[i] = new int[c];
        }
        
        dp[r - 1][c -1] = 1;
        for(int i = r - 2; i >= 0; i--) //last column filled
        {
            dp[i][c - 1] = dp[i + 1][c - 1] - input[i][c - 1];
        }
        
        for(int i = c - 2; i >= 0; i--) // last row filled
        {
            dp[r - 1][i] = dp[r - 1][i + 1] - input[r - 1][i];
        }
        
        int k;
        for(int i = r - 2; i >= 0; i--) //matrix filled
        {
            for(int j = c - 2; j >= 0; j--)
            {
                k = min(dp[i + 1][j], dp[i][j + 1]) - input[i][j];
                if(k <= 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = k;
                }
            }
        }
        k = dp[0][0];
        for(int i = 0; i < r; i++)
        {
            delete [] dp[i];
        }
        delete [] dp;
        
        cout << k << endl;
    }
    return 0;
}
