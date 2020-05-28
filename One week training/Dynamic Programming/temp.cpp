#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

void print(int input[],int ins,int output[],int ops)
{
    if(ins < ops){
        for(int i=0;i<ops;i++)
        {
            cout<<output[i]<<endl;
        }
        return;
    }
    if(ins==ops)
    {
        for(int i=0;i<ops;i++)
        {
            cout<<output[i]<<endl;
        }
        return;
    }
    int tmp[2000];
    for(int i=0;i<ops-1;i++)
    {
        tmp[i]=output[i];
    }
    print(input+1,ins-1,tmp,ops+1);
    print(input+1,ins-1,output,ops);
}


void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int m =0;
    int op[m];
    int ns=size;
    print(input,ns,op,m);
    
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}