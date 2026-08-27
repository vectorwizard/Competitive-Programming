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
    vector<ll> a(m);
    for(ll i=0;i<m;i++) cin>>a[i];
    vector<ll> ans(m);
    map<ll,ll> mpp;
    for(ll i=0;i<m;i++){
        mpp[a[i]]++;
        if(mpp.size()==n){
            ans[i] = 1;
            for(auto it=mpp.begin(); it!=mpp.end();){
                if(it->second>1) {
                    it->second--;
                    it++;
                }
                else it = mpp.erase(it);
            }
        }
        else ans[i] = 0;
    }
    for(auto it:ans) cout<<it;
    cout<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
