#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> segTree;
vector<ll> lazyset;
vector<ll> lazyinc;

void build(ll l,ll r,ll ind,vector<ll> &a){
    if(l==r){
        segTree[ind] = a[l];
        return;
    }
    ll mid = l+(r-l)/2;
    build(l,mid,ind*2+1,a);
    build(mid+1,r,ind*2+2,a);
    segTree[ind] = segTree[ind*2+1] + segTree[ind*2+2];
}

void op1(ll ind,ll l,ll r,ll start,ll end,ll val,vector<ll> &a){
    if(lazyset[ind]!=0){
        ll siz = r-l+1;
        segTree[ind] = siz*lazyset[ind];
        if(l!=r){
            lazyset[2*ind+1] = lazyset[ind];
            lazyset[2*ind+2] = lazyset[ind];
            lazyinc[2*ind+1] = 0;
            lazyinc[2*ind+2] = 0;
        }
        lazyset[ind] = 0;
    }
    if(lazyinc[ind]!=0){
        ll siz = r-l+1;
        segTree[ind] += siz*lazyinc[ind];
        if(l!=r){
            lazyinc[2*ind+1] += lazyinc[ind];
            lazyinc[2*ind+2] += lazyinc[ind];
        }
        lazyinc[ind] = 0;
    }
    if(l>end || r<start) return;
    else if(l>=start && r<=end){
        segTree[ind]+=((r-l+1)*val);
        if(l!=r){
            lazyinc[2*ind+1] += val;
            lazyinc[2*ind+2] += val;
        }
        return;
    }
    else{
        ll mid = l+(r-l)/2;
        op1(ind*2+1,l,mid,start,end,val,a);
        op1(ind*2+2,mid+1,r,start,end,val,a);
        segTree[ind] = segTree[ind*2+1] + segTree[ind*2+2];
        return;
    }
}

void op2(ll ind,ll l,ll r,ll start,ll end,ll val,vector<ll> &a){
    if(lazyset[ind]!=0){
        ll siz = r-l+1;
        segTree[ind] = siz*lazyset[ind];
        if(l!=r){
            lazyset[2*ind+1] = lazyset[ind];
            lazyset[2*ind+2] = lazyset[ind];
            lazyinc[2*ind+1] = 0;
            lazyinc[2*ind+2] = 0;
        }
        lazyset[ind] = 0;
    }
    if(lazyinc[ind]!=0){
        ll siz = r-l+1;
        segTree[ind] += siz*lazyinc[ind];
        if(l!=r){
            lazyinc[2*ind+1] += lazyinc[ind];
            lazyinc[2*ind+2] += lazyinc[ind];
        }
        lazyinc[ind] = 0;
    }
    if(l>end || r<start) return;
    else if(l>=start && r<=end){
        segTree[ind]=((r-l+1)*val);
        if(l!=r){
            lazyset[2*ind+1] = val;
            lazyset[2*ind+2] = val;
            lazyinc[2*ind+1] = 0;
            lazyinc[2*ind+2] = 0;
        }
        lazyinc[ind] = 0;
        return;
    }
    else{
        ll mid = l+(r-l)/2;
        op2(ind*2+1,l,mid,start,end,val,a);
        op2(ind*2+2,mid+1,r,start,end,val,a);
        segTree[ind] = segTree[ind*2+1] + segTree[ind*2+2];
        return;
    }
}

ll op3(ll ind,ll l,ll r,ll start,ll end,vector<ll> &a){
    if(lazyset[ind]!=0){
        ll siz = r-l+1;
        segTree[ind] = siz*lazyset[ind];
        if(l!=r){
            lazyset[2*ind+1] = lazyset[ind];
            lazyset[2*ind+2] = lazyset[ind];
            lazyinc[2*ind+1] = 0;
            lazyinc[2*ind+2] = 0;
        }
        lazyset[ind] = 0;
    }
    if(lazyinc[ind]!=0){
        ll siz = r-l+1;
        segTree[ind] += siz*lazyinc[ind];
        if(l!=r){
            lazyinc[2*ind+1] += lazyinc[ind];
            lazyinc[2*ind+2] += lazyinc[ind];
        }
        lazyinc[ind] = 0;
    }
    if(l>end || r<start) return 0;
    else if(l>=start && r<=end){
        return segTree[ind];
    }
    else{
        ll mid = l+(r-l)/2;
        ll ans = 0;
        ans+=op3(ind*2+1,l,mid,start,end,a);
        ans+=op3(ind*2+2,mid+1,r,start,end,a);
        segTree[ind] = segTree[ind*2+1] + segTree[ind*2+2];
        return ans;
    }
}

void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> vec(n);
    for(ll i=0;i<n;i++) cin>>vec[i];
    segTree.assign(4*n,0);
    lazyset.assign(4*n,0);
    lazyinc.assign(4*n,0);
    build(0,n-1,0,vec);
    while(q--){
        ll op;
        cin>>op;
        if(op==1){
            ll a,b,x;
            cin>>a>>b>>x;
            a--;b--;
            op1(0,0,n-1,a,b,x,vec);
        }
        else if(op==2){
            ll a,b,x;
            cin>>a>>b>>x;
            a--;b--;
            op2(0,0,n-1,a,b,x,vec);
        }
        else{
            ll a,b;
            cin>>a>>b;
            a--;b--;
            ll ans = op3(0,0,n-1,a,b,vec);
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