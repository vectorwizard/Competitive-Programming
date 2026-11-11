#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> segTree;
void build(ll ind,ll l,ll r,vector<ll> &a){
    ll m = a.size();
    if(l==r){
        segTree[ind] = a[l];
        return;
    }   
    ll mid = l + (r-l)/2;
    build(ind*2+1,l,mid,a);
    build(ind*2+2,mid+1,r,a);
    segTree[ind] = max(segTree[ind*2+1],segTree[ind*2+2]);
}

ll query(ll ind,ll l,ll r,ll start,ll end){
    if(l>end || r<start) return 0;
    else if(l>=start && r<=end) return segTree[ind];
    else{
        ll mid = l + (r-l)/2;
        ll left = query(ind*2+1,l,mid,start,end);
        ll right = query(ind*2+2,mid+1,r,start,end);
        return max(left,right);
    }
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<ll> a(m);
    for(ll i=0;i<m;i++) cin>>a[i];
    ll q;
    cin>>q;
    segTree.assign(4*m,0);
    build(0,0,m-1,a);
    while(q--){
        ll xs,ys,xf,yf,k;
        cin>>xs>>ys>>xf>>yf>>k;
        ys--; yf--;
        if((abs(xs-xf))%k!=0){
            cout<<"NO"<<endl;
            continue;
        }
        else if((abs(ys-yf))%k!=0){
            cout<<"NO"<<endl;
            continue;
        }
        ll maxi = query(0,0,m-1,min(yf,ys),max(yf,ys));
        ll xmax = xs + ((n-xs)/k) * k;
        if(xmax<=maxi){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
}   

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}