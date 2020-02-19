#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int mini(int ** arr, int pos, int k, int row, int col)
{
    k++;
    if(k == row - 1)
    {
        return 0;
    }

    int ans = 0;
    if(pos == 0)
    {
        ans =  ans + min(mini(arr, pos, k, row, col) + arr[k][pos], mini(arr, pos + 1, k, row, col) + arr[k][pos + 1]);
    }

    if(pos == m - 1)
    {
        ans = ans + min(mini(arr, pos, k, row, col) + arr[k][pos], mini(arr, pos - 1, k, row, col), arr[k][pos - 1]);
    }

    else
    {
        ans = ans + min(mini(arr, pos, k, row, col) + arr[k][pos], min(mini(arr, pos + 1, k, row, col) + arr[k][pos + 1], mini(arr, pos - 1, k, row, col), arr[k][pos - 1]));
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int k = 0;
    int ans = mini(arr, 0, k, n, m)
    cout << ans << endl;

    return 0;
}