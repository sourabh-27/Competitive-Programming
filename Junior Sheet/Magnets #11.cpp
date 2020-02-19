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
    int temp = -1; int count = 0; int k;
    while(n--)
    {
        cin >> k;
        if(k == temp)
        {
            continue;
        }
        else
        {
            count++;
            temp = k;
        }  
    }

    cout << count << endl;

    return 0;
}