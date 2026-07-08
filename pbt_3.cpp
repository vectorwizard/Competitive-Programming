#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const ll mod = 1e9 + 7;
vector<ll> a;
vector<ll> segTree1;
vector<ll> segTree2;
void build1(vector<ll> &a,ll ind,ll l,ll r){
    if(l==r){
        segTree1[ind] = a[l];
        return;
    }   
    ll mid = l+(r-l)/2;
    build1(a,ind*2+1,l,mid);
    build1(a,ind*2+2,mid+1,r);
    segTree1[ind] = ((segTree1[2*ind+1] + segTree1[2*ind+2])%mod+(segTree1[2*ind+1] * segTree1[2*ind+2])%mod)%mod;
}

ll query1(ll start,ll end,ll ind,ll l,ll r){
    if(l>end || r<start) return 0;
    if(l>=start && r<=end) return segTree1[ind];
    ll mid = l+(r-l)/2;
    ll left = query1(start,end,ind*2+1,l,mid);
    ll right = query1(start,end,ind*2+2,mid+1,r);
    return (left*right)%mod + (left+right)%mod;
}

void solve() {
    ll n;
    cin>>n;
    a.assign(n,0);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    segTree1.assign(4*n,0);
    segTree2.assign(4*n,0);
    build1(a,0,0,n-1);
    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        l--; r--;
        ll x = query1(l,r,0,0,n-1);
        cout<<(x%mod)<<endl;
    }
}  

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
