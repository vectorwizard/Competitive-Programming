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
    vector<vector<ll>> vec(n,vector<ll>(m,0));
    map<ll,vector<ll>> rows;
    map<ll,vector<ll>> cols;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>vec[i][j];
            ll x = vec[i][j];
            rows[x].push_back(i);
        }
    }
    for(ll j=0;j<m;j++){
        for(ll i=0;i<n;i++){
            ll x = vec[i][j];
            cols[x].push_back(j);
        }
    }
    ll ans = 0;
    for(auto it:rows){
        vector<ll> temp = it.second;
        ll siz = temp.size();
        ll x = 0;
        ll y = 0;
        for(ll i=1;i<siz;i++){
            x += (i*temp[i]);
            y += (i*temp[siz-1-i]);
        }
        ans += (x-y);
    }
    for(auto it:cols){
        vector<ll> temp = it.second;
        ll siz = temp.size();
        ll x = 0;
        ll y = 0;
        for(ll i=1;i<siz;i++){
            x += (i*temp[i]);
            y += (i*temp[siz-1-i]);
        }
        ans += (x-y);
    }
    cout<<ans<<endl;
}   

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
