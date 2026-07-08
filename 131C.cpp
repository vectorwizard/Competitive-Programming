#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,vector<ll> &a,ll n,ll m){
    vector<ll> have(n+1,mid);
    vector<ll> b(n+1);
    for(ll i=0;i<m;i++){
        b[a[i]]++;
    }
    for(ll i=1;i<n+1;i++){
        ll x = min(b[i],mid);
        have[i] -= x;
        b[i]-=x; 
    }
    ll rem_jobs = 0;
    for(ll i=1;i<n+1;i++){
        rem_jobs += b[i];
    }
    for(ll i=1;i<=n;i++){
        ll x = (have[i]/2);
        rem_jobs-=x;
    }
    if(rem_jobs<=0) return true;
    return false;
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<ll> a(m);
    for(ll i=0;i<m;i++) cin>>a[i];
    ll low = 1;
    ll high = 2*m;
    ll ans = high;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,a,n,m)){
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
    cin>>t;
    while (t--) solve();
    return 0;
}
