#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<pair<ll,ll>> segTree; // {max_val , ans}

ll visible(ll ind,ll l,ll r,ll maxi){
    if(l==r){
        if(segTree[ind].first>maxi) return 1;
        return 0;
    }
    if(segTree[ind].first<=maxi) return 0;
    ll left = 2*ind+1;
    ll right = 2*ind+2;
    ll mid = l+(r-l)/2;
    if(segTree[left].first<=maxi) return visible(right,mid+1,r,maxi);
    else return visible(left,l,mid,maxi) + segTree[ind].second - segTree[left].second;
}

ll query(ll start,ll end,ll ind,ll l,ll r,ll &curr_max){
    if(l>end || r<start) return 0;
    if(l>=start && r<=end){
        ll res = visible(ind,l,r,curr_max);
        curr_max = max(curr_max,segTree[ind].first);
        return res;
    }
    ll mid = l+(r-l)/2;
    ll left = 0,right = 0;
    left = query(start,end,2*ind+1,l,mid,curr_max);
    right =  query(start,end,2*ind+2,mid+1,r,curr_max);
    return left + right;
}
void buildTree(vector<ll> &a,ll ind,ll l,ll r){
    if(l==r){
        segTree[ind] = {a[l],1};
        return;
    }
    ll mid = l+(r-l)/2;
    buildTree(a,ind*2+1,l,mid);
    buildTree(a,ind*2+2,mid+1,r);
    segTree[ind].first = max(segTree[ind*2+1].first,segTree[ind*2+2].first);
    segTree[ind].second = segTree[ind*2+1].second + visible(ind*2+2,mid+1,r,segTree[ind*2+1].first);
}
void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    segTree.assign(4*n,{0,0});
    buildTree(a,0,0,n-1);
    while(q--){
        ll a,b;
        cin>>a>>b;
        ll curr_max = 0;
        ll ans = query(a-1,b-1,0,0,n-1,curr_max);
        cout<<ans<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}