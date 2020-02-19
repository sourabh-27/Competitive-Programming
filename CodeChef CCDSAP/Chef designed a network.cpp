#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin >> T;
    while(T--)
    {
        ll n, m;
        cin>>n>>m;
        if(n==1&&m==1){
            cout<<1<<endl;
        }
        else if(n==2&&m==1){
            cout<<1<<endl;
        }
        else if(n==1&&m==0){
            cout<<0<<endl;
        }
        else if(m<n-1){
            cout<<-1<<endl;
        }
        else if(m>n+((n*(n-1))/2)){
            cout<<-1<<endl;
        }
        else if(m<n+2&&m>=n-1){
            cout << 2 << endl;
        }
        else if(m<(2*n+1)&&m>=n+2){
            cout<<3<<endl;
        }
        else{
            if(n%2==0){
                ll a=3;
                ll b=abs((2*n)-m);
                if(b%(n/2)==0){
                    cout<<(b/(n/2))+a<<endl;
                }
                else{
                    cout<<(b/(n/2))+a+1<<endl;
                }
            }
            else{
                ll a=3;
                ll b=abs(m-(2*n));
                ll c=n/2;
                if(b%n==0){
                    cout <<a+(b/n) * 2 << endl;
                }
                else{
                    if(b%n<=c){
                        cout<<a+((b/n)*2)+1<<endl;
                    }
                    else{
                        cout <<a+((b/n)*2)+2<<endl; 
                    }  
                }  
            }
        }
    }
    return 0;
}