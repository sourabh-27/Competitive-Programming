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
    int count = 0; int avai = 0;
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if(k > 0)
        {
            avai += k;
        }
        else if(k < 0 && avai != 0)
        {
            avai = avai + k;
            // cout << "i : " << i << " k : " << k << endl;
        }
        else if(k < 0 && avai == 0)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}