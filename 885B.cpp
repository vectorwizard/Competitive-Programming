#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
bool func(ll mid,vector<ll> &c,int k){
    ll n = c.size()-1;
    vector<ll> prev(n+1,0);
    vector<ll> bad(k+1,0);
    vector<ll> max_bad(k+1,0);
    for(ll i=1;i<=n;i++){
        ll dist =  i - prev[c[i]] -1;
        prev[c[i]] = i;
        if(dist>mid){
            bad[c[i]]++;
            max_bad[c[i]] = max(max_bad[c[i]],dist);
        } 
    }
    for(int i=1;i<=k;i++){
        ll dist = n - prev[i];
        if(dist>mid) {
            bad[i]++;
            max_bad[i] = max(max_bad[i],dist);
        }
    }
    for(ll i=1;i<=k;i++){
        if(bad[i]== 0) return true;
        if((bad[i]==1) && ((max_bad[i]/2)<=mid)) return true;
    }
    return false;
}
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> c(n+1);
    for(ll i=1;i<=n;i++) cin>>c[i];
    ll low = 0;
    ll high = n;
    ll ans = n;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,c,k)){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
