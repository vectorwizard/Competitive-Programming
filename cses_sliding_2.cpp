#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<ll> vec(n);
    vec[0] = x;
    for(ll i=1;i<n;i++){
        vec[i] = (vec[i-1]*a + b)%c;
    }
    ll ans = 0;
    deque<pair<ll,ll>> dq;  //{ind,value}
    for(int i=0;i<k;i++){
        while(!dq.empty() && dq.back().second>=vec[i]) dq.pop_back();
        dq.push_back({i,vec[i]});
        while(!dq.empty() && dq.front().first<=i-k) dq.pop_front();
    }
    ans = dq.front().second;
    int l = 0;
    for(int r = k;r<n;r++){
        while(!dq.empty() && dq.back().second>=vec[r]) dq.pop_back();
        dq.push_back({r,vec[r]});
        while(!dq.empty() && dq.front().first<=r-k) dq.pop_front();
        l++;
        ans ^= dq.front().second;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
