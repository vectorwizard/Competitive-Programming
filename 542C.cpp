#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> dr = {-1,0,1,0};
vector<ll> dc = {0,1,0,-1};

void dfs(ll i,ll j,vector<vector<ll>> &a,vector<vector<ll>> &vis){
    ll n = a.size();
    vis[i][j] = 1;
    for(ll k=0;k<4;k++){
        ll nrow = i + dr[k];
        ll ncol = j + dc[k];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && a[nrow][ncol]==0){
            dfs(nrow,ncol,a,vis);
        }
    }
}

void dfs1(ll i,ll j,vector<vector<ll>> &a,vector<vector<ll>> &vis){
    ll n = a.size();
    vis[i][j] = 2;
    for(ll k=0;k<4;k++){
        ll nrow = i + dr[k];
        ll ncol = j + dc[k];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && a[nrow][ncol]==0){
            dfs1(nrow,ncol,a,vis);
        }
    }
}

void solve() {
    ll n;
    cin>>n;
    ll r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    r1--;r2--;
    c1--;c2--;
    vector<vector<ll>> a(n,vector<ll>(n));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            char ch;
            cin>>ch;
            a[i][j] = ch-'0';
        }
    }
    vector<vector<ll>> vis(n,vector<ll>(n,0));
    dfs(r1,c1,a,vis);
    if(vis[r2][c2]){
        cout<<0<<endl;
        return;
    }
    dfs1(r2,c2,a,vis);
    vector<pair<ll,ll>> vec1;
    vector<pair<ll,ll>> vec2;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(vis[i][j]==1) vec1.push_back({i,j});
            else if(vis[i][j]==2) vec2.push_back({i,j});
        }
    }
    ll mini = 1e18;
    for(ll i=0;i<vec1.size();i++){
        for(ll j = 0;j<vec2.size();j++){
            ll r = abs(vec1[i].first-vec2[j].first);
            ll c = abs(vec1[i].second-vec2[j].second);
            ll cost = (r*r) + (c*c);
            mini = min(mini,cost);
        }
    }
    cout<<mini<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}