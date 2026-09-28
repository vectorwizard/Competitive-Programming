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
    vector<vector<ll>> vis(n,vector<ll>(m,0));
    vis[0][m-1] = 1;
    vis[n-1][0] = 1;
    vis[n-1][m-1] = 1;
    vis[0][0] = 1;
    queue<pair<ll,ll>> q;
    if(n==1 && m==1) q.push({0,0});
    else if(n==1){
        q.push({0,0});
        q.push({0,m-1});
    }
    else if(m==1){
        q.push({0,0});
        q.push({n-1,0});
    }
    else{
        q.push({0,0});
        q.push({0,m-1});
        q.push({n-1,0});
        q.push({n-1,m-1});
    }
    vector<ll> ans;
    vector<ll> dr = {-1,0,1,0};
    vector<ll> dc = {0,1,0,-1};
    ll cnt = n+m-2;
    while(!q.empty()){
        ll siz = q.size();
        for(ll i=0;i<siz;i++){
            auto it = q.front();
            q.pop();
            ll row = it.first;
            ll col = it.second;
            ans.push_back(cnt);
            for(ll j=0;j<4;j++){
                ll nrow = row + dr[j];
                ll ncol = col + dc[j];
                if(nrow<0 || nrow>=n || ncol<0 || ncol>=m) continue;
                if(vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        cnt--;
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}