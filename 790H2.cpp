#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> segTree;
ll query(ll ind,ll l,ll r,ll start,ll end){
    ll mid = l+(r-l)/2;
    if(l>end || r<start) return 0;
    else if(l>=start && r<=end) return segTree[ind];
    ll left = query(ind*2+1,l,mid,start,end);
    ll right = query(ind*2+2,mid+1,r,start,end);
    return left+right;
}
void update(ll ind,ll l,ll r,ll x){
    if(l==r){
        segTree[ind]++;
        return;
    }
    ll mid = l+(r-l)/2;
    if(x<=mid){
        update(ind*2+1,l,mid,x);
    }
    else update(ind*2+2,mid+1,r,x);
    segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    segTree.assign(4*n,0);
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        ll x = query(0,1,n,a[i],n);
        ans+=x;
        update(0,1,n,a[i]);
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
