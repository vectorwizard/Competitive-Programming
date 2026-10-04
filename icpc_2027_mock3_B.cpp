#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 1e9 + 7;
vector<ll> fact;

ll power(ll a,ll b){
    if(b==0) return 1;
    ll ans = power(a,b/2);
    ans = (ans*ans)%mod;
    if(b%2==1) ans = (ans*a)%mod;
    return ans;
}

ll ncr(ll n,ll r){
    ll num = fact[n];
    ll dem1 = fact[r];
    ll dem2 = fact[n-r];
    ll dem = (dem1 * dem2)%mod;
    dem = (power(dem,mod-2))%mod;
    num = (num * dem)%mod;
    return num;
}

vector<ll> poss;

void dfs(ll node,vector<vector<ll>> &adj){
    poss[node] = 1;
    for(auto it:adj[node]){
        if(poss[it]==0){
            dfs(it,adj);
        }
    }
}

void solve() {  
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    vector<vector<ll>> adj(n+1);
    vector<vector<ll>> rev(n+1);
    for(ll i=1;i<=n;i++){
        adj[i].push_back(a[i]);
        rev[a[i]].push_back(i);
    }
    poss.assign(n+1,0);
    vector<ll> sizes;
    poss[1] = 1;
    dfs(1,rev);
    ll good = 0;
    for(ll i=1;i<=n;i++){
        if(poss[i]) good++;
    }
    vector<ll> vis(n+1,0);
    for(ll i=1;i<=n;i++){
        if(vis[i]==0 && poss[i]==0){
            queue<ll> q;
            q.push(i);
            vis[i] = 1;
            ll siz = 1;
            while(!q.empty()){
                ll node = q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(vis[it]==0 && poss[it]==0){
                        vis[it] = 1;
                        siz++;
                        q.push(it);
                    }
                }
                for(auto it:rev[node]){
                    if(vis[it]==0 && poss[it]==0){
                        vis[it] = 1;
                        siz++;
                        q.push(it);
                    }
                }
            }
            sizes.push_back(siz);
        }
    }
    sort(sizes.rbegin(),sizes.rend());
    for(ll i=0;i<min((ll)sizes.size(),k);i++){
        good+=sizes[i];
    }
    cout<<good<<endl;
} 
 
int main() {
    fastio();
    // fact.assign(100001,0);
    // fact[0] = 1;
    // fact[1] = 1;
    // for(ll i=2;i<=1e5;i++){
    //     fact[i] = (fact[i-1]*i)%mod;
    // }
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
