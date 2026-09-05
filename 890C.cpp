#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,vector<ll> &a,ll k){
    ll n = a.size();
    for(ll i=0;i<n;i++){
        bool fl = false;
        if(a[i]>=mid) return true;
        ll cnt = max(0LL,mid-a[i]);
        ll prev = mid;
        for(ll j = i+1;j<n;j++){
            if(a[j]>=(prev-1)){
                fl = true;
                break;
            }
            if(j==n-1) break;
            cnt+=max(0LL,prev-1-a[j]);
            prev = prev-1;
        }
        if(cnt<=k && fl){
            return true;
        }
    }
    return false;
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll high = 1e9;
    ll low = *min_element(a.begin(),a.end());
    ll ans = low;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,a,k)){
             low = mid+1;
             ans = mid;
        }
        else high = mid-1;
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
