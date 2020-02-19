#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    getline(cin, s);
    ll len = s.length();
    // ll blue = 0, orange = 0;
    for(ll i = 0; i < len - 2; i++)
    {
        if(s[i] == ' ')
        {
            continue;
        }
        else
        {
            ll temp = s[i] - 48, temp2 = s[i + 2] - 48;
            ll t = 360;
            ll k1 = t / temp, k2 = t / temp2;
            ll ans1 = (90 / k1) * k1 + 90;
            ll ans2 = ans1 + k1;
            ll ans3 = (90 / k2) * k2 + 90;
            ll ans4 = ans3 + k2;
            cout << "ans1 : " << ans1 << " " << " ans2 : " << ans2 << endl;
            cout << "ans3 : " << ans3 << " " << " ans4 : " << ans4 << endl;
            ll moveForward = 180 - ans1;
            // ll moveBackward = ans2 - 180;
            ll tem1 = abs(180 - (ans3 - moveForward));
            ll tem2 = abs(180 - (ans4 - moveForward));
            ll clockWise = min(tem1, tem2) + moveForward;
            cout << "moveForward: " << moveForward << endl;
            cout << "temp1: " << tem1 << " " << "temp2: " << tem2 << endl;
            
        }
    }

    return 0;
}