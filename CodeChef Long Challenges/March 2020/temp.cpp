#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

string printBalances(vector<string> requests){
	ll len = requests.size();
	pair<long double, pair<long double, long double>> cred = {0, {0, 0}};
	pair<long double, pair<long double, long double>> ded = {0, {0, 0}};
	for(ll i = 0; i < len; i++){
		string str = requests[i];
		char curr;
		if(str[0] == 'D'){
			string k; int count = 0;
			// cout << "str:" << str << endl;
			for(ll j = 0; j < str.length(); j++){
				// cout << "str[i]: " << str[i] << endl;
				if(str[j] == 44){
					count++;
					continue;
				}
				if(count == 2){
					curr = str[j];
					// cout << "j: " << j << "curr: " << curr << endl;
					break;
				}
				else if(count == 0){
					continue;
				}
				else{
					k = k + str[j];
				}
			}
			// cout << "k: " << k << endl;
			if(curr == 'U'){
				cred.first += stold(k);
			}
			else if(curr == 'E'){
				cred.second.first += stold(k);
			}
			else{
				cred.second.second += stold(k);
			}
		}
		else if(str[0] == 'W'){
			string k; int count = 0;
			// cout << "str:" << str << endl;
			for(ll j = 0; j < str.length(); j++){
				// cout << "str[i]: " << str[i] << endl;
				if(str[j] == 44){
					count++;
					continue;
				}
				if(count == 2){
					curr = str[j + 1];
					break;
				}
				else if(count == 0){
					continue;
				}
				else{
					k = k + str[j];
				}
			}
			// cout << "k: " << k << endl;
			if(curr == 'U'){
				ded.first += stold(k);
			}
			else if(curr == 'E'){
				ded.second.first += stold(k);
			}
			else{
				ded.second.second += stold(k);
			}
		}
	}
	cout << "USD: " << cred.first << " EUR: " << cred.second.first << " GBP: "<< cred.second.second << endl;
	cout << "USD: " << ded.first << " EUR: " << ded.second.first << " GBP: "<< ded.second.second << endl;
	return "";
}
 
int main()
{
	fast;
	string str1 = "DEPOSIT,100.00,EUR";
	string str2 = "DEPOSIT,200.00,USD";
	string str3 = "DEPOSIT,300.00,GBP";
	string str4 = "WITHDRAW,200.00,USD";
	vector<string> requests;
	requests.push_back(str1);
	requests.push_back(str2);
	requests.push_back(str3);
	requests.push_back(str4);
	string str = printBalances(requests);

	return 0;
}