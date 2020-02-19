#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string> grid(10);
    for(int i = 0; i < 10; i++)
    {
        cin >> grid[i];
    }

    string w, s;
    vector<string> words;
    cin >> w;
    for(auto x : w)
    {
        if(x == ';')
        {
            words.push_back(s);
            s = "";
        }
        else
        {
            s = s + x;
        }   
    }
    words.push_back(s);

    return 0;
}