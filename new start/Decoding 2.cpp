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
    string s;
    cin >> s;
    list<char> l;
    if(n % 2 == 0)
    {
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                l.push_back(s[i]);
            }
            else
            {
                l.push_front(s[i]);
            }    
        }
        l.reverse();
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                l.push_front(s[i]);
            }
            else
            {
                l.push_back(s[i]);
            } 
        }
        l.reverse();
    }

    list <char>::iterator itr = l.begin();
    for(itr; itr != l.end(); itr++)
    {
        cout << *itr;
    }
    cout << endl;
    

    return 0;
}