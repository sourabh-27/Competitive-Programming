#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k, r;
    cin >> k >> r;
    int i = 2; int temp = k;
    while(true)
    {
        if(temp % 10 == 0 || temp % 10 == r)
        {
            break;
        }
        temp = k * i;
        // cout << "i: " << i << " temp: " << temp << endl;
        i++;
    }
    cout << i - 1 << endl;

    return 0;
}