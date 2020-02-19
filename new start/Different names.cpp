#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    vector<string> arr;
    map<string, int> ans;
    string word = "";
    for(auto x : s)
    {
        if(x == ' ')
        {
            arr.push_back(word);
            ans[word]++;
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    arr.push_back(word);
    vector<string>::iterator it;
    map<string, int>::iterator it2;
    for(it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl << "YOO" << endl;
    for(it2 = ans.begin(); it2 != ans.end(); it2++)
    {
        cout << *it2 << " ";
    }

    
	return 0;
}
