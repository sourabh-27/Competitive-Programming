#include<bits/stdc++.h>
using namespace std;

void findAns(string str, int curr, int len, int flag, string &s)
    // cout << "curr: " << curr << " s: " << s << endl;
	if(str[curr] == ')'){
        cout << s << endl;
		return;
	}
    // cout << "YO" << endl;
    if(flag == 1){
		s = s + str[curr];
		findAns(str, curr + 1, len, flag, s);
	}
	else if(str[curr] == '('){
		flag = 1;
		findAns(str, curr + 1, len, flag, s);
	}
    else{
        findAns(str, curr + 1, len, flag, s);
    }
}

int main(){
	string str;
	cin >> str;
	string s = "";
	findAns(str, 0, str.length() - 1, 0, s);
	// cout << s << endl;
}