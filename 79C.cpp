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
    vector<ll> a(n);
    vector<ll> b(m);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<m;i++) cin>>b[i];
    ll ans = 0;
    ll ind = 0;
    unordered_set<ll> seen;
    for(ll i=0;i<m;i++){
        ll target = b[i];
        if(seen.count(target)){
            ans++;
        }
        else{
            while(a[ind]!=target){
                seen.insert(a[ind]);
                ind++;
            }
            ans+=((ind-i)*2 + 1);
            ind++;
        }
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