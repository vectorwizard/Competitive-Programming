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
    vector<ll> till(n,-1);
    while(m--){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        ll maxi = max(x,y);
        ll mini = min(x,y);
        till[maxi] = max(till[maxi],mini);
    }
    ll l = 0;
    ll cnt = 0;
    ll maxi = -1;
    for(ll r=0;r<n;r++){
        maxi = max(maxi,till[r]);
        cnt+=(r-maxi);
    }
    cout<<cnt<<endl;
}   


int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
