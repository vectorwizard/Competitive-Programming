#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<pair<ll,ll>> segTree;  // {total-sum,max_prefix-sum}
void build(vector<ll> &a,ll ind,ll l,ll r){
    if(l==r){
        segTree[ind].first = a[l];
        segTree[ind].second = max(0LL,a[l]);
        return;
    }
    ll mid = l+(r-l)/2;
    build(a,ind*2+1,l,mid);
    build(a,ind*2+2,mid+1,r);
    segTree[ind].first = segTree[ind*2+1].first + segTree[ind*2+2].first;
    segTree[ind].second = max(0LL,max(segTree[ind*2+1].second,segTree[ind*2+1].first+segTree[ind*2+2].second));
}
void update(ll k,ll u,ll ind,ll l,ll r){
    if(l==r){
        segTree[ind].first = u;
        segTree[ind].second = max(0LL,u);
        return;
    }
    ll mid = l+(r-l)/2;
    if(k<=mid) update(k,u,ind*2+1,l,mid);
    else update(k,u,ind*2+2,mid+1,r);
    segTree[ind].first = segTree[ind*2+1].first + segTree[ind*2+2].first;
    segTree[ind].second = max(0LL,max(segTree[ind*2+1].second,segTree[ind*2+1].first+segTree[ind*2+2].second));
}
pair<ll,ll> query(ll start,ll end,ll ind,ll l,ll r){
    if(l>end || r<start) return {0,0};
    if(l>=start && r<=end) return segTree[ind];
    ll mid = l+(r-l)/2;
    auto left = query(start,end,ind*2+1,l,mid); 
    auto right = query(start,end,ind*2+2,mid+1,r);
    return {left.first+right.first,max(0LL,max(left.second,left.first+right.second))};
}
void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    segTree.assign(4*n,{0,0});
    build(a,0,0,n-1);
    while(q--){
        ll option;
        cin>>option;
        if(option==1){
            ll k,u;
            cin>>k>>u;
            update(k-1,u,0,0,n-1);
        }
        else{
            ll a,b;
            cin>>a>>b;
            auto it = query(a-1,b-1,0,0,n-1);
            cout<<it.second<<endl;
        }
    }
}

int_least32_t main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
