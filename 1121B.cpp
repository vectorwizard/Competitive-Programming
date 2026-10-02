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
    vector<ll> a(n+1,0);
    for(ll i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        ll ans = -1e18;
        for(int i=1;i<=n;i++) ans = max(ans,a[i]);
        cout<<ans<<endl;
        return;
    }
    ll sum = a[1];
    priority_queue<ll> pq;
    ll maxi = -1e18;
    pq.push(a[1]);
    for(ll i=2;i<=n;i++){
        if(pq.size()==m-1){
            ll x = m*a[i] - sum;
            maxi = max(maxi,x);
        }
        pq.push(a[i]);
        sum+=a[i];
        if(pq.size()>m-1){
            sum-=pq.top();
            pq.pop();
        }
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}