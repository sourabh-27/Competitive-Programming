#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define INF 0x3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define print(v); for(auto x:v) cout<<x<<" "; cout<<endl;
typedef long long int ll;
#define N 1000

int bitx[60];
int bity[60];
int bitxy[60];
int bitr[60];
int bitl[60];
int number[60];

ll x, y, l, r;
ll powFunc(ll a, ll b){
    ll res = 1;
    for(ll i = 0; i < b; i++){
        res = res * 2;
    }
    return res;
}

void calcFunc(ll &maxi, ll &ans, ll pwr){
    ll possibility = (x & pwr) * (y & pwr);
    if(possibility > maxi){
        maxi = possibility;
        ans = pwr;
    }
    else if(possibility == maxi){
        ans = min(ans, pwr);
    }
}

ll func3()
{
    if(x == 0 || y == 0){
        return 0;
    }
    ll a = x; ll b = y; ll c = l; ll d = r; ll e = x | y;
    long long arr3[64], arr5[64];
    for(ll i = 0; i < 63; i++){
        arr3[i] = e & 1; e = e >> 1;
        arr5[i] = d & 1; d = d >> 1;
    }
    ll power = 0; ll index = 0; ll power2 = 0;
    for(ll i = 62; i >= 0; i--){
        if(arr3[i] == 1){
            // cout << "i: " << i << endl;
            index = i;
            break;
        }
    }
    for(ll i = index; i >= 0; i--){
        if(arr3[i] == 1){
            power += powFunc(2, i);
        }
    }
    for(ll i = index; i >= 0; i--){
        if(arr3[i] == 1 && arr5[i] == 1){
            power2 += powFunc(2, i);
        }
    }
    // cout << "power: " << power << endl;
    ll ans1 = 10e12 + 10; ll maxi = 0;
    if(power >= l && power <= r){
        calcFunc(maxi, ans1, power);
    }  
    // cout << "maxi: " << maxi << " ans1: " << ans1 << endl;

    if(power2 >= l && power2 <= r){
        calcFunc(maxi, ans1, power2);
    }
    // cout << "maxi: " << maxi << " ans11: " << ans1 << endl;

    for(ll i = 62; i >= 0; i--){
        if(arr5[i] == 1){
            ll pow1 = powFunc(2, 62) - powFunc(2, i + 1); pow1 = pow1 & r;
            ll pow2 = powFunc(2, i) - 1; pow2 = (pow2 & power);
            ll poss = pow1 | pow2;
            if(poss >= l && poss <= r){
                calcFunc(maxi, ans1, poss);
            }
        }
    }
    if(maxi != 0){
        return ans1;
    }
    else{
        return 0;
    }
}

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

ll solve(ll x, ll y, ll l, ll r)
{
    // long long int x,y,l,r;
    // cin>>x>>y>>l>>r;//cout<<(x|y)<<'\n';

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


    if(x==0 || y==0){
        return 0;
    }
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
        if(maximum<=(x&num2)*(y&num2))
        {
          if(maximum==(x&num2)*(y&num2))ans=min(ans,num2);
          else ans=num2;
          maximum=(x&num2)*(y&num2);//cout<<maximum<<'\n';
        }
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
        return ans;
    }
}

ll bruteForce(ll x, ll y, ll l, ll r){
    ll maxi = INT_MIN; ll z;
    for(ll i = l; i <= r; i++){
        ll k = (x & i) * (y & i);
        if(k > maxi){
            maxi = k;
            z = i;
        }
    }
    return z;
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        // cin >> x >> y >> l >> r;
        ll mini = 10e12 + 10; ll maxi = -1;
        for(ll x1 = 0; x1 <= N; x1++){
            cout << "x1: " << x1 << endl;
            for(ll y1 = 0; y1 <= N; y1++){
                // for(ll l1 = 0; l1 <= N; l1++){
                    for(ll r1 = 2 * max(x1, y1); r1 <= N; r1++){
                        x = x1; y = y1; l = 0; r = r1;
                        ll ans1 = bruteForce(x, y, l, r); ll ans2 = solve(x, y, l, r); ll ans3 = func3();
                        if(ans1 != ans2 || ans2 != ans3 || ans3 != ans1){
                            cout << "x: " << x << " y: " << y << " l: " << l << " r: " << r << endl;
                            cout << "ans1: " << ans1 << " ans2: " << ans2 << endl;
                            // break;
                            return 0;
                        }
                    }
                // }
            }
        }

    }


    return 0;
}