#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void build1(vector<ll> &a,ll ind,ll l,ll r,vector<ll> &segTree){
    if(l==r){
        segTree[ind] = a[l]+l;
        return;
    }
    ll mid = l+(r-l)/2;
    build1(a,ind*2+1,l,mid,segTree);
    build1(a,ind*2+2,mid+1,r,segTree);
    segTree[ind] = min(segTree[ind*2+1],segTree[ind*2+2]);
}

void build2(vector<ll> &a,ll ind,ll l,ll r,vector<ll> &segTree){
    if(l==r){
        segTree[ind] = a[l]-l;
        return;
    }
    ll mid = l+(r-l)/2;
    build2(a,ind*2+1,l,mid,segTree);
    build2(a,ind*2+2,mid+1,r,segTree);
    segTree[ind] = min(segTree[ind*2+1],segTree[ind*2+2]);
}

void update(vector<ll> &a,ll pos,ll val,ll ind,ll l,ll r,vector<ll> &segTree){
    if(l==r){
        segTree[ind]+=val;
        return;
    }
    ll mid=l+(r-l)/2;
    if(pos<=mid) update(a,pos,val,ind*2+1,l,mid,segTree);
    else update(a,pos,val,ind*2+2,mid+1,r,segTree);
    segTree[ind] = min(segTree[ind*2+1],segTree[ind*2+2]);
}

ll query(ll start,ll end,ll ind,ll l,ll r,vector<ll> &segTree){
    if(l>end || r<start) return LLONG_MAX;
    if(l>=start && r<=end) return segTree[ind];
    ll mid=l+(r-l)/2;
    return min(query(start,end,ind*2+1,l,mid,segTree),query(start,end,ind*2+2,mid+1,r,segTree));
}
void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> segTree1; // Pa + a
    vector<ll> segTree2; // Pa - a
    segTree1.assign(4*n,LLONG_MAX);
    segTree2.assign(4*n,LLONG_MAX);
    build1(a,0,0,n-1,segTree1);
    build2(a,0,0,n-1,segTree2);
    while(q--){
        ll option;
        cin>>option;
        if(option==1){
            ll k,u;
            cin>>k>>u;
            update(a,k-1,u-a[k-1],0,0,n-1,segTree1);
            update(a,k-1,u-a[k-1],0,0,n-1,segTree2);
            a[k-1] = u;
        }
        else{
            ll k;
            cin>>k;
            k--;
            ll ans = a[k],ans1=INT_MAX,ans2=INT_MAX;
            if(k-1>=0) ans1 = query(0,k-1,0,0,n-1,segTree2)+k;
            if(k+1<n) ans2 = query(k+1,n-1,0,0,n-1,segTree1)-k;
            ans = min(ans,min(ans1,ans2));
            cout<<ans<<endl;
        }
    }
}

int_least32_t main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
