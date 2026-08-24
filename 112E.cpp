#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> segTree,lazy;
void update(ll ind,ll l,ll r,ll start,ll end,ll op){
    if(lazy[ind]!=0){
        segTree[ind] = segTree[ind] + lazy[ind];
        if(l!=r){
            lazy[ind*2+1] += lazy[ind];
            lazy[ind*2+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(r<start || l>end) return;
    else if(l>=start && r<=end){
        segTree[ind] = segTree[ind] + op;
        if(l!=r){
            lazy[ind*2+1] += op; 
            lazy[ind*2+2] += op; 
        }
    }
    else{
        ll mid = l+(r-l)/2;
        update(ind*2+1,l,mid,start,end,op);
        update(ind*2+2,mid+1,r,start,end,op);
        segTree[ind] = min(segTree[ind*2+1],segTree[ind*2+2]);
    }
}
void solve() {
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n,vector<ll>(3));
    for(ll i=0;i<n;i++){
        ll l,r,w;
        cin>>l>>r>>w;
        a[i] = {w,l,r};
    }
    sort(a.begin(),a.end());
    segTree.assign(4*m,0);
    lazy.assign(4*m,0);
    ll l = 0;
    ll ans = 1e9;
    for(ll r=0;r<n;r++){
        if(a[r][2]==1) continue;
        update(0,1,m-1,a[r][1],a[r][2]-1,1);
        while(l<=r && segTree[0]>0){
            if(a[l][2]==1){
                l++;
                continue;
            }
            update(0,1,m-1,a[l][1],a[l][2]-1,-1);
            ans = min(ans,a[r][0]-a[l][0]);
            l++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}