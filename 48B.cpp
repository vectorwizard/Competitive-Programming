#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m,q;
    cin>>n>>m>>q;
    string s,t;
    cin>>s>>t;
    vector<vector<ll>> vec(n,vector<ll>(n,0));
    for(ll i=0;i<n;i++){
        
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<vec[l][r]<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
