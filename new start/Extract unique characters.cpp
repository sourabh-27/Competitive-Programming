#include<bits/stdc++.h>
using namespace std;
string uniqueChar(char *str){
    // Write your code here
    set<char> unique;
    for(int i = 0; i < strlen(str); i++)
    {
        unique.insert(str[i]);
    }
    set<char>::iterator itr;
    string s2 = "";
    for(int i = 0; i < strlen(str); i++)
    {
        if(unique.find(str[i]) != unique.end())
        {
            s2 = s2 + str[i];
            unique.erase(unique.find(str[i]));
        }
    }
    return s2;
}


int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
