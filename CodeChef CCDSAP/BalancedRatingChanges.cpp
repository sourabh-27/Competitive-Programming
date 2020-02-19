#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll temp = 0;
    ll sum = 0;
    while(n--)
    {
        ll a;
        cin >> a;
        if(a % 2 == 0)
        {
            temp = 0;
            cout << a / 2 << endl;
            sum += a / 2;
        }
        else
        {
            if(n == 1)
            {
                if(a > 0)
                {
                    int x = a / 2;
                    int y = (a / 2) + 1;
                    if(sum + x == 0)
                    {
                        cout << x << endl;
                    }
                    else
                    {
                        cout << y << endl;
                    }
                }  
                else
                {
                    int x = a / 2;
                    int y = (a / 2) - 1;
                    if(sum + x == 0)
                    {
                        cout << x << endl;
                    }
                    else
                    {
                        cout << y << endl;
                    }
                    
                }
            }
            else if(a > 0 && temp == 0)
            {
                cout << (a / 2) << endl;
                sum += a / 2;
                temp--;
            }
            else if(a < 0 && temp == 0)
            {
                cout << (a / 2) << endl;
                sum += a / 2;
                temp++;
            }
            else if(temp != 0)
            {
                cout << (a / 2) - temp << endl;
                sum += (a / 2) - temp;
                temp = 0;
            }
        }
    }
 
    return 0;
}