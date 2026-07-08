#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> segTree;
void buildTree(vector<ll> &a,ll ind,ll l,ll r){
    if(l==r){
        segTree[ind] = a[l];
        return;
    }
    ll mid = l+(r-l)/2;
    buildTree(a,ind*2+1,l,mid);
    buildTree(a,ind*2+2,mid+1,r);
    segTree[ind] = max(segTree[ind*2+1],segTree[ind*2+2]);
}
ll query(ll val,ll ind,ll l,ll r){
    if(l==r){
        if(segTree[ind]>=val) {
            segTree[ind]-=val;
            return l;
        }
        else return -1;
    }
    ll ans = -1;
    ll mid = l+(r-l)/2;
    if(segTree[2*ind+1]>=val){
        ans =  query(val,ind*2+1,l,mid);
    }
    else if(segTree[2*ind+2]>=val){
        ans = query(val,ind*2+2,mid+1,r);
    }
    segTree[ind] = max(segTree[2*ind+1],segTree[2*ind+2]);
    return ans;
}
void solve() {
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    segTree.assign(4*n,0);
    buildTree(a,0,0,n-1);
    while(m--){
        ll b;
        cin>>b;
        ll ans = query(b,0,0,n-1);
        cout<< ans+1 <<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
