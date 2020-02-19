#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int row = 5, col = 5; int x, y, k;
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            cin >> k;
            if(k == 1)
            {
                x = i; y = j;
            }
        }
    }

    x = abs(x - 3);
    y = abs(y - 3);
    cout << x + y << endl;

    return 0;
}