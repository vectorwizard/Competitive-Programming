#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,vector<ll> &prefix,ll x){
    ll n = prefix.size();
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(prefix[i]>x) break;
        ans+= (((x-prefix[i])/(i+1))+1);
    }
    if(ans>=mid) return true;
    return false;
}

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll low = 1;
    ll mini = *min_element(a.begin(),a.end());
    if(mini>x){
        cout<<0<<endl;
        return;
    }
    sort(a.begin(),a.end());
    vector<ll> prefix(n,0);
    prefix[0] = a[0];
    for(ll i=1;i<n;i++){
        prefix[i] = prefix[i-1] + a[i];
    }
    ll high = n*x;
    ll ans = 1;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,prefix,x)){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
