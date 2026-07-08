#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
unordered_map<ll,ll> prefix;
bool func(ll mid,vector<ll> &a,ll k){
    ll n = a.size();
    if(prefix[mid]<=k) return true;
    return false;
}
void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    unordered_map<ll,ll> total(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll maxi = 0;
    prefix[-1] = 0;
    ll tot = 0;
    total[-1] = 0;
    for(ll i=0;i<n;i++){
        maxi = max(a[i],maxi);
        prefix[i] = maxi;
        total[i] = tot + a[i];
        tot = total[i];
    }
    for(ll i=0;i<q;i++){
        ll k;
        cin>>k;
        ll low = 0;
        ll high = n-1;
        ll ans = -1;
        while(low<=high){
            ll mid = low+(high-low)/2;
            if(func(mid,a,k)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        cout<<total[ans]<<" ";
    }
    cout<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
