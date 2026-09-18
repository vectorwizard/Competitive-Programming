#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 998244353;
vector<ll> fact(1e6,0);
void cal(){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<1e6;i++){
        fact[i] = (fact[i-1] * i)%mod;
    }
}

ll power(ll a, ll b){
    if(b==0) return 1;
    ll ans = power(a,b/2);
    ans = (ans*ans)%mod;
    if(b%2==1){
        ans = (ans*a)%mod;
    }
    return ans%mod;
}

ll ncr(ll n,ll r){
    ll x = fact[n];
    ll y = fact[r];
    y = (y*fact[n-r])%mod;
    ll ans = (x * power(y,mod-2))%mod;
    return ans;
}

bool func(ll mid,vector<ll> &a){
    ll n = a.size();
    ll cnt = n*mid;
    for(ll i=0;i<n;i++){
        if((a[i]-cnt)<=0) return true;
        cnt++;
    }
    return false;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll low = 0;
    ll high = 1e9;
    ll turn = 1e9;
    while(low<=high){
        ll mid = low + (high-low)/2;
        if(func(mid,a)){
            turn = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    ll cnt = turn*n;
    for(ll i=0;i<n;i++){
        if((a[i]-(cnt))<=0){
            cout<<i+1<<endl;
            return;
        }
        cnt++;
    }
}

int main() {
    fastio();
    ll t=1;
    // cal();
    // cin>>t;
    while (t--) solve();
    return 0;
}
