#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<pair<ll,ll>> segTree;  //cnt,sum
void buildTree(ll l,ll r,ll ind,ll x){
    if(l==r){
        segTree[ind].first++;
        segTree[ind].second = segTree[ind].second+x;
        return;
    }
    ll mid = l+(r-l)/2;
    if(x<=mid){
        buildTree(l,mid,ind*2+1,x);
    }
    else buildTree(mid+1,r,ind*2+2,x);
    segTree[ind].first = segTree[ind*2+1].first + segTree[ind*2+2].first;
    segTree[ind].second = segTree[ind*2+1].second + segTree[ind*2+2].second;
}
ll query(ll ind,ll l,ll r,ll sum){
    if(l==r){
        ll take = min(segTree[ind].first,sum/l);
        return take;
    }
    ll mid = l+(r-l)/2;
    ll ans = 0;
    if(segTree[ind*2+1].second>=sum){
        ans = query(ind*2+1,l,mid,sum);
    }
    else{
        ans+=segTree[ind*2+1].first;
        ans+=query(ind*2+2,mid+1,r,sum-segTree[ind*2+1].second);
    }
    return ans;
}
void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    vector<vector<ll>> queries;
    for(ll i=0;i<q;i++){
        ll x,y;
        cin>>x>>y;
        queries.push_back({x,y,i});
    }
    sort(queries.begin(),queries.end());
    segTree.assign(4*(n+1),{0,0});
    ll ptr = 0;
    vector<pair<ll,ll>> vec;
    for(ll i=1;i<=n;i++){
        buildTree(1,n,0,a[i]);
        while(ptr<q && i==queries[ptr][0]){
            ll y = queries[ptr][1];
            ll ans = query(0,1,n,y);
            vec.push_back({queries[ptr][2],ans});
            ptr++;
            if(ptr==q) break;
        }
    }
    sort(vec.begin(),vec.end());
    for(auto it:vec){
        cout<<it.second<<endl;
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}