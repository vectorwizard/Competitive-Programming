#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll n){
    return n*(n+1)/2;
}

void solve() {
    ll a,b,m;
    cin>>a>>b>>m;
    ll x = (b/m) - (a/m);
    if(x==0){
        ll next = b%m;
        ll prev = a%m;
        ll ans = 0;
        if(next>prev){
            ans=(func(next)-func(prev));
        }
        else{
            ans+=(func(m-1)-func(prev));
            ans+=(func(next));
        }
        cout<<ans<<endl;
    }
    else{
        ll ans = func(m-1) * (x-1);
        ll next = b%m;
        ll prev = a%m;
        ans+=(func(m-1)-func(prev));
        ans+=(func(next));
        cout<<ans<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}