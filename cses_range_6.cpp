#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> segTree;
vector<ll> lazyTree;
void buildTree(vector<ll> &a,ll ind,ll l,ll r){
    if(l==r) {
        segTree[ind] = a[l];
        return;
    }
    ll mid = l+(r-l)/2;
    buildTree(a,ind*2+1,l,mid);
    buildTree(a,ind*2+2,mid+1,r);
    segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
}
void propagate(ll ind,ll l,ll r){
    if(lazyTree[ind]!=0){
        segTree[ind] += lazyTree[ind] * (r-l+1);
        if(l!=r){
            lazyTree[2*ind+1] += lazyTree[ind];
            lazyTree[2*ind+2] += lazyTree[ind];
        }
        lazyTree[ind] = 0;
    }
}
void func1(vector<ll> &a,ll start,ll end,ll val,ll ind,ll l,ll r){
    propagate(ind,l,r);
    if(l>end || r<start) return;
    if(l>=start && r<=end){
        lazyTree[ind] += val;
        propagate(ind,l,r);
        return;
    }
    ll mid = l+(r-l)/2;
    func1(a,start,end,val,ind*2+1,l,mid);
    func1(a,start,end,val,ind*2+2,mid+1,r);
    segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2]; 
}
ll func2(vector<ll> &a,ll ind,ll l,ll r,ll k){
    propagate(ind,l,r);
    ll mid = l+(r-l)/2;
    if(l==r) return segTree[ind];
    else if(k<=mid){
        return func2(a,ind*2+1,l,mid,k);
    }
    return func2(a,ind*2+2,mid+1,r,k);
}
void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    segTree.assign(4*n,0);
    lazyTree.assign(4*n,0);
    buildTree(a,0,0,n-1);
    while(q--){
        ll option;
        cin>>option;
        if(option==1){
            ll a2,b,u;
            cin>>a2>>b>>u;
            func1(a,a2-1,b-1,u,0,0,n-1);
        }
        else{
            ll k;
            cin>>k;
            cout<<func2(a,0,0,n-1,k-1)<<endl;
        }
    }
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}