#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n,k;
		cin >> n >> k;
		int arr[n];
		int j=0;
		int p1,p2,p3;
		unordered_map<int,int> ab;
		for(j=0;j<n;j++){
			cin >> arr[j];
			ab[arr[j]]=j+1;
		}
		int flag=0;
		int count1=0;
		vector<int> v1;
 
		for(j=0;j<n;j++){
			if(arr[j]==j+1)
				continue;
			else{
				int p1=j+1;
				int p2 = ab.at(j+1);
				int p3 = arr[j];
				if(p2==p3){
					p3=p1+1;
					while(p3<n){
						if(arr[p3-1]!=p3){
							break;
						}
						p3++;
					}
				}
				if(p2>p3){
					int temp1 = p2;
					p2=p3;
					p3=temp1;
				}else{
					int temp2 = p3;
					p3=p2;
					p2=temp2;
 
				}
 
				//cout << p1 << " " << p2<< " " << p3 << "\n";
				if(p1==p2||p2==p3||p3==p1){
				 	flag=1;
				 	break;
				}
				v1.push_back(p1);
				v1.push_back(p2);
				v1.push_back(p3);
				//cout << p1 << " " << p2 << " " << p3 << " " << "\n";
				int temp = arr[p3-1];
				arr[p3-1] = arr[p2-1];
				arr[p2-1] = arr[p1-1];
				arr[p1-1] = temp;
				ab[arr[p3-1]] = p3;
				ab[arr[p2-1]] = p2;
				ab[arr[p1-1]] = p1;
				count1++;
				if(count1>k){
				    flag=1;
				    break;
				}
			}
		}
		if(flag==1){
			cout << -1 << "\n";
			continue;
		}
		cout << count1 << "\n";
		for(j=0;j<v1.size();j++){
			cout << v1[j] << " ";
			if((j+1)%3==0)
				cout << "\n";
		}
 
	}
}