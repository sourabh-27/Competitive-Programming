#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
  
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}
 
ll inv(ll base) {
    int g = MOD, r = base, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }
    return x < 0 ? x+MOD : x;
}
 
ll mul(ll A, ll B) {
	return (A*B)%MOD;
}
 
ll add(ll A, ll B) {
	return (A+B)%MOD;
}
 
ll dvd(ll A, ll B) {
    return mul(A, inv(B));
}
 
ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    int N; cin >> N; int P; cin >> P;
    string S; cin >> S;
    if (P == 5 || P == 2) {
        ll ans = 0;
        F0R(i, N) {
            if ((S[i] - '0') % P == 0) {
                ans += i+1;
            }
        }
        cout << ans << endl;
        return 0;
    }
 
    ll counts[P]; F0R(i, P) counts[i] = 0;
    counts[0] = 1;
    int cur = 0;
    MOD = P;
    F0R(i, N) {
        cout << "i: " << i << endl;
        cout << "curr Before: " << cur << " and S[i9k00-------oooooooooooo0o9oooooooiikr9kkiiiik9iiizz" << endl;
        cur *= 10; cur += S[i] - '0'; cur %= MOD;
        cout << "curr After: " << cur << endl;
        int val = modExp(10, N-1-i) * cur; val %= MOD;
        // cout << "val: " << val << endl;
        counts[val]++;
    }
 
    ll ans = 0;
    F0R(i, P) ans += (counts[i] * (counts[i] - 1)) / 2;
 
    cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343