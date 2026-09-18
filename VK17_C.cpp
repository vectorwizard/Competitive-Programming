#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>> grid(n,vector<ll>(m,0));
    ll x,y;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            char z;
            cin>>z;
            if(z=='X'){
                x = i;
                y = j;
            }
            else if(z=='*') grid[i][j] = 1;
        }
    }
    if(k%2==1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<ll> dr = {1,0,0,-1};
    vector<ll> dc = {0,-1,1,0};
    string s = "DLRU";
    queue<pair<ll,ll>> q;
    q.push({x,y});
    vector<vector<ll>> dist(n,vector<ll>(m,1e9));
    dist[x][y] = 0;
    ll cnt = 0;
    while(!q.empty()){
        ll siz = q.size();
        for(ll j=0;j<siz;j++){
            auto it = q.front();
            q.pop();
            ll r = it.first;
            ll c = it.second;
            for(ll i=0;i<4;i++){
                ll nrow = r+dr[i];
                ll ncol = c+dc[i];
                if(nrow>=n || nrow<0 || ncol>=m || ncol<0 || grid[nrow][ncol]==1 || dist[nrow][ncol]<=cnt+1){
                    continue;
                }
                dist[nrow][ncol] = cnt+1;
                q.push({nrow,ncol});
            }
        }
        cnt++;
    }
    string ans = "";
    ll x1 = x;
    ll y1 = y;
    while(k){
        bool fl = false;
        for(ll i=0;i<4;i++){
            ll nrow = x1+dr[i];
            ll ncol = y1+dc[i];
            if(nrow>=n || nrow<0 || ncol>=m || ncol<0 || grid[nrow][ncol]==1 || dist[nrow][ncol]>k-1){
                continue;
            }
            else{
                x1 = nrow;
                y1 = ncol;
                ans+=s[i];
                fl = true;
                break;
            }
        }
        if(!fl){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        k--;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}