#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,q;
    cin>>n>>q;
    vector<vector<ll>> grid(n+1,vector<ll>(n+1,0));
    vector<vector<ll>> prefix(n+1,vector<ll>(n+1,0));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            char ch;
            cin>>ch;
            if(ch=='*') grid[i][j] = 1;
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + grid[i][j];
        }
    }
    while(q--){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ll ans = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];
        cout<<ans<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
