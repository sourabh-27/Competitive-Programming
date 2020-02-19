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
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if((x == 1 && y == 1) || (x == 1 && z == 1) || (y == 1 && z == 1))
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}