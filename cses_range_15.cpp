#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<vector<ll>> segTree; // total_sum,prefix_max,suffix_max,total_max
void buildTree(vector<ll> &a,ll ind,ll l,ll r){
    if(l==r){
        segTree[ind][0]=a[l];
        segTree[ind][1]=max(0LL,a[l]);
        segTree[ind][2]=max(0LL,a[l]);
        segTree[ind][3]=max(0LL,a[l]);
        return;
    }
    ll mid = l+(r-l)/2;
    buildTree(a,ind*2+1,l,mid);
    buildTree(a,ind*2+2,mid+1,r);
    ll left = ind*2+1;
    ll right = ind*2+2;
    segTree[ind][0] = segTree[left][0] + segTree[right][0];
    segTree[ind][1] = max(0LL,max(segTree[left][1],segTree[left][0]+segTree[right][1]));
    segTree[ind][2] = max(0LL,max(segTree[right][2],segTree[right][0]+segTree[left][2]));
    ll p = segTree[left][3];
    ll q = segTree[right][3];
    ll s = segTree[left][2]+segTree[right][1];
    segTree[ind][3] = max(0LL,max(p,max(q,s)));
}
void update(ll idx,ll val,ll ind,ll l,ll r){
    if(l==r){
        segTree[ind][0]=val;
        segTree[ind][1]=max(0LL,val);
        segTree[ind][2]=max(0LL,val);
        segTree[ind][3]=max(0LL,val);
        return;
    }
    ll mid = l+(r-l)/2;
    if(idx<=mid){
        update(idx,val,ind*2+1,l,mid);
    }
    else update(idx,val,ind*2+2,mid+1,r);
    ll left = ind*2+1;
    ll right = ind*2+2;
    segTree[ind][0] = segTree[left][0] + segTree[right][0];
    segTree[ind][1] = max(0LL,max(segTree[left][1],segTree[left][0]+segTree[right][1]));
    segTree[ind][2] = max(0LL,max(segTree[right][2],segTree[right][0]+segTree[left][2]));
    ll p = segTree[left][3];
    ll q = segTree[right][3];
    ll s = segTree[left][2]+segTree[right][1];
    segTree[ind][3] = max(0LL,max(p,max(q,s)));
}
void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    segTree.assign(4*n,vector<ll>(4,0));
    buildTree(a,0,0,n-1);
    while(q--){
        ll k,x;
        cin>>k>>x;
        update(k-1,x,0,0,n-1);
        cout<<segTree[0][3]<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}