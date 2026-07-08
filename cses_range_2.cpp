#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> segTree;
void build(vector<ll> &a,ll ind,ll l,ll r){
    if(l==r){
        segTree[ind] = a[l];
        return;
    }   
    ll mid = l+(r-l)/2;
    build(a,ind*2+1,l,mid);
    build(a,ind*2+2,mid+1,r);
    segTree[ind] = min(segTree[2*ind+1] , segTree[2*ind+2]);
}
ll query(ll start,ll end,ll ind,ll l,ll r){
    if(l>end || r<start) return INT_MAX;
    if(l>=start && r<=end) return segTree[ind];
    ll mid = l+(r-l)/2;
    ll left = query(start,end,ind*2+1,l,mid);
    ll right = query(start,end,ind*2+2,mid+1,r);
    return min(left,right);
}
void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    segTree.assign(4*n,0);
    build(a,0,0,n-1);
    while(q--){
        ll a,b;
        cin>>a>>b;
        ll x = query(a-1,b-1,0,0,n-1);
        cout<<x<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
