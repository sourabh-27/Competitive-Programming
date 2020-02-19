#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, h;
    cin >> n >> h;
    int k; int count = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> k;
        if(k > h)
        {
            count = count + 2;
        }
        else
        {
            count += 1;
        }
        
    }

    cout << count << endl;

    return 0;
}