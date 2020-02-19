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
    int count = 0, count2 = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'A')
        {
            count++;
        }
        else
        {
            count2++;
        }
    }
    if(count > count2)
    {
        cout << "Anton" << endl;
    }
    else if(count == count2)
    {
        cout << "Friendship" << endl;
    }
    else
    {
        cout << "Danik" << endl;
    }
    


    return 0;
}