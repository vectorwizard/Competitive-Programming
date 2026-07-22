#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<ll> b(n);
    vector<ll> g(m);
    for(ll i=0;i<n;i++) cin>>b[i];
    for(ll i=0;i<m;i++) cin>>g[i];
    sort(b.begin(),b.end());
    sort(g.begin(),g.end());
    if(b[n-1]>g[0]){
        cout<<-1<<endl;
        return;
    }
    ll total_b = accumulate(b.begin(),b.end(),0LL);
    ll total_g = accumulate(g.begin(),g.end(),0LL);
    ll ans = 0;
    for(ll i = 0;i<n;i++){
        ans+=(m*b[i]);
    }
    if(b[n-1]==g[0]){
        ans += (total_g - (m*b[n-1]));
        cout<<ans<<endl;
    }
    else{
        ans += (total_g - (m-1)*b[n-1] - (b[n-2]));
        cout<<ans<<endl;
    }
}   

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
