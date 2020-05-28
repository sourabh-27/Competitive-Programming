#include <bits/stdc++.h>
using namespace std;
int bitx[60];
int bity[60];
int bitxy[60];
int bitr[60];
int bitl[60];
int number[60];

void bitform(int a[],long long int x)
{
    for(long long int i=0; i<60; i++)
    {
        a[i]=x&1;
        x=x>>1;
        //cout<<a[i];
    }
    //cout<<'\n';
}
void solve()
{
    long long int x,y,l,r;
    cin>>x>>y>>l>>r;//cout<<(x|y)<<'\n';

    for(long long int i=0; i<60; i++)
    {
        bitx[i]=0;
        bity[i]=0;
        bitxy[i]=0;
        bitr[i]=0;
        bitl[i]=0;
        number[i]=0;
    }
    bitform(bitx,x);
    bitform(bity,y);
    bitform(bitxy,(x|y));
    bitform(bitr,r);
    bitform(bitl,l);
    long long int num1=0,num2=0,num=0,maximum=0,ans=r+1;int k=0;


    if(x==0 || y==0)cout<<0<<'\n';
    else
    {
        for(int i=59; i>=0; i--)
        {

            if(bitr[i]==1)
            {
                k=1;
            }
            if((bitxy[i]==1) && k==1 )
            {
                // cout << "i: " << i << endl;
                num=num+(long long int)(pow(2,i));
            }
             if((bitr[i]==1 && bitxy[i]==1) && k==1 )
            {
                number[i]=1;num2=num2+(long long int)(pow(2,i));
            }
        }
        // cout << "num: " << num << " num2: " << num2 << endl;


        if(num<=r)
        {maximum=max(maximum,(x&num)*(y&num));
        ans=num;}
        // cout << "ans: " << ans << endl;
        // cout << "maximum: " << maximum << endl;
        if(maximum<=(x&num2)*(y&num2))
        {
          if(maximum==(x&num2)*(y&num2))ans=min(ans,num2);
          else ans=num2;
          maximum=(x&num2)*(y&num2);//cout<<maximum<<'\n';
        }
        // cout << "ans: " << ans << endl;
        // cout << "maximum: " << maximum << endl;
        // cout << "ans: " << ans << endl;
        for(int i=59; i>=0; i--)
        {
            if(bitr[i]==1)
            {   num1=(r&(long long int)(pow(2,60)-pow(2,i+1)))|(num&((long long int)(pow(2,i))-1));
                //cout<<num1<<'\n';
                if(num1<=r)
                {
                    if(maximum<=(x&num1)*(y&num1))
                    {
                        if(maximum==(x&num1)*(y&num1))ans=min(ans,num1);
                        else ans=num1;
                        maximum=(x&num1)*(y&num1);

                    }
                }
            }
        }
        if(maximum==0)ans=0;
        cout<<ans<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }

}
