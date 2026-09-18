#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll n){
    return n*(n+1)/2;
}

void solve() {
    ll n,k;
    cin>>n>>k;
    string a,b;
    cin>>a>>b;
    ll ans = 0;
    set<char> st;
    for(ll i=0;i<n;i++) st.insert(a[i]);
    ll m = st.size();
    vector<ll> dist;
    for(auto it:st) dist.push_back(it);
    k = min(k,m);
    for(ll i=0;i<(1<<m);i++){
        if(__builtin_popcount(i)!=k) continue;
        vector<bool> allowed(26,0);
        for(ll j=0;j<=10;j++){
            if(i&(1<<j)){
                allowed[dist[j]-'a'] = 1;
            }
        }
        ll cnt = 0;
        ll patch = 0;
        for(ll j=0;j<n;j++){
            if(a[j]==b[j] || allowed[a[j]-'a']==1){
                patch++;
            }
            else{
                cnt+=func(patch);
                patch=0;
            }
        }
        cnt+=func(patch);
        ans = max(ans,cnt);
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