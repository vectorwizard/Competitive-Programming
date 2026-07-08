#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> segTree;
unordered_map<ll,ll> mpp;
void buildTree(vector<ll> &a,ll ind,ll l,ll r){
    if(l==r){
        segTree[ind] = 1;
        return;
    }
    ll mid = l+(r-l)/2;
    buildTree(a,ind*2+1,l,mid);
    buildTree(a,ind*2+2,mid+1,r);
    segTree[ind] = segTree[ind*2+1]+segTree[2*ind+2];
}
ll query(ll noOfEle,ll ind,ll l,ll r){
    if(l==r){
        segTree[ind] = 0;
        return l;
    }
    ll mid = l+(r-l)/2;
    ll ans = -1;
    if(noOfEle<=segTree[2*ind+1]){
        ans = query(noOfEle,ind*2+1,l,mid);
    }
    else {
        ans = query(noOfEle-segTree[2*ind+1],ind*2+2,mid+1,r);
    }
    segTree[ind] = segTree[ind*2+1]+segTree[2*ind+2];
    return ans;
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    segTree.assign(4*n,0);
    buildTree(a,0,0,n-1);
    for(ll i=0;i<n;i++){
        mpp[i] = a[i];
    }
    ll m = n;
    while(m--){
        ll pos;
        cin>>pos;
        ll ans = query(pos,0,0,n-1);
        cout<<mpp[ans]<<" ";
    }
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}