#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> vec(n);
    for(ll i=0;i<n;i++){
        ll m;
        cin>>m;
        for(ll j=0;j<m;j++){
            ll x;
            cin>>x;
            vec[i].push_back(x);
        }
        sort(vec[i].begin(),vec[i].end());
    }
    ll min_second = 1e9;
    ll mini = 1e9;
    ll sum = 0;
    for(ll i=0;i<n;i++){
        sum+=vec[i][1];
        min_second = min(min_second,vec[i][1]);
        mini = min(vec[i][0],mini);
    }
    cout<<(sum-min_second+mini)<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
