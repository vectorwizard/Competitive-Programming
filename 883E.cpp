#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> isPoss;
ll power(ll n,ll x){
    if(x==0) return 1;
    ll temp = power(n,x/2);
    ll ans=(temp*temp);
    if(x%2==1) ans*=n;
    return ans;
}
ll cal(ll k,ll x){
    ll y = power(k,x);
    return ((y-1)/(k-1));
}
void precompute(){
    for(ll k=2;k<=1000000;k++){
        for(ll x = 3;x<=1000000;x++){
            ll y = cal(k,x);
            if(y>1000000) break;
            isPoss[y] = 1;
        }
    }
}
void solve() {
    ll n;
    cin>>n;
    if(isPoss[n]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    isPoss.assign(1e6+1,0);
    precompute();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}

