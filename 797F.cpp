
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> temp;

void dfs(ll node,vector<vector<ll>> &adj,vector<ll> &vis){
    vis[node] = 1;
    temp.push_back(node);
    for(auto it:adj[node]){
        if(vis[it]==0){
            dfs(it,adj,vis);
        }
    }
}

ll func(string &s){
    ll n = s.size();
    string st = s;
    ll cnt = 1;
    rotate(s.begin(),s.begin()+1,s.end());
    while(s!=st){
        rotate(s.begin(),s.begin()+1,s.end());
        cnt++;
    }
    return cnt;
}

ll lcm(ll x,ll y){
    ll tem = x*y;
    return tem/__gcd(x,y);
}

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    vector<vector<ll>> adj(n+1);
    for(ll i=1;i<=n;i++){
        adj[a[i]].push_back(a[a[i]]);
    }
    vector<ll> vis(n+1,0);
    vector<vector<ll>> cycles;
    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            temp.clear();
            dfs(i,adj,vis);
            cycles.push_back(temp);
        }
    }
    ll ans = 1;
    for(auto it:cycles){
        string str = "";
        for(auto it1:it){
            str+=s[it1-1];
        }
        ll cnt = func(str);
        ans = lcm(ans,cnt);
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