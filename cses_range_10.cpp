#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> segTree;

void subtract(ll idx,ll ind,ll l,ll r){
    if(l==r){
        segTree[ind]--;
        return;
    }
    ll mid = l+(r-l)/2;
    if(idx<=mid){
        subtract(idx,ind*2+1,l,mid);
    }
    else subtract(idx,ind*2+2,mid+1,r);
    segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
}

void add(ll idx,ll ind,ll l,ll r){
    if(l==r){
        segTree[ind]++;
        return;
    }
    ll mid = l+(r-l)/2;
    if(idx<=mid){
        add(idx,ind*2+1,l,mid);
    }
    else add(idx,ind*2+2,mid+1,r);
    segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
}

ll query(ll start,ll end,ll ind,ll l,ll r){
    if(r<start || l>end) return 0;
    if(l>= start && r<=end) return segTree[ind];
    ll mid = l+(r-l)/2;
    return (query(start,end,ind*2+1,l,mid) + query(start,end,ind*2+2,mid+1,r));
}

void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        a.push_back(x);
    }
    vector<ll> arr = a;
    vector<vector<ll>> queries;
    while(q--){
        char ch;
        cin>>ch;
        if(ch=='!'){
            ll k,x;
            cin>>k>>x;
            queries.push_back({1,k,x});
            a.push_back(x);
        }
        else{
            ll x,y;
            cin>>x>>y;
            queries.push_back({2,x,y});
        }
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    ll m = a.size();
    segTree.assign(m*4,0);
    for(int i=0;i<n;i++){
        ll idx = lower_bound(a.begin(),a.end(),arr[i]) - a.begin();
        add(idx,0,0,m-1);
    }
    for(auto it:queries){
        if(it[0]==1){
            ll k = it[1];
            ll x = it[2];
            ll idx1 = lower_bound(a.begin(),a.end(),arr[k-1]) - a.begin();
            ll idx2 = lower_bound(a.begin(),a.end(),x) - a.begin();
            subtract(idx1,0,0,m-1);
            add(idx2,0,0,m-1);
            arr[k-1] = x;
        }
        else{
            ll x = it[1];
            ll y = it[2];
            ll start = lower_bound(a.begin(),a.end(),x) - a.begin();
            ll end = upper_bound(a.begin(),a.end(),y) - a.begin()-1;
            ll ans = 0;
            if(start<=end) ans = query(start,end,0,0,m-1);
            cout<<ans<<endl;
        }
    }
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}