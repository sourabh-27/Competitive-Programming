#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        string s1;
        cin >> s1;
        ll len = s1.length();
        stack <char> st;
        for(ll i = 0; i < len; i++)
        {
            if(s1[i] == '(' || s1[i] == ')' || s1[i] == '+' || s1[i] == '-' || s1[i] == '*' || s1[i] == '/' || s1[i] == '^')
            {
                if(s1[i] == ')')
                {
                    cout << st.top();
                    st.pop();
                    st.pop();
                }
                else
                {
                    st.push(s1[i]);
                } 
            }
            else
            {
                cout << s1[i];
            }
        }
        cout << endl;
    }
    return 0;
}