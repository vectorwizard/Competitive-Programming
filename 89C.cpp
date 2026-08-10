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
    vector<vector<ll>> a(n,vector<ll>(m,0));
    vector<vector<ll>> vis(n,vector<ll>(m,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }   
    vector<ll> zeros(n+m-1,0);
    vector<ll> ones(n+m-1,0);
    queue<vector<ll>> q;
    q.push({0,0,0});  // {thnode,row,col}
    vis[0][0] = 1;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        ll thnode = it[0];
        ll row = it[1];
        ll col = it[2];
        if(a[row][col]==0) zeros[thnode]++;
        else ones[thnode]++;
        ll nrow = row+1;
        if(nrow<n && vis[nrow][col]==0){
            vis[nrow][col] = 1;
            q.push({thnode+1,nrow,col});
        }
        ll ncol = col + 1;
        if(ncol<m && vis[row][ncol]==0){
            vis[row][ncol] = 1;
            q.push({thnode+1,row,ncol});
        }
    }
    ll ans = 0;
    ll x = (n+m-1)/2-1;
    for(ll i=0;i<=x;i++){
        ll zero = zeros[i] + zeros[n+m-2-i];
        ll one = ones[i] + ones[n+m-2-i];
        ans+=min(zero,one);
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
