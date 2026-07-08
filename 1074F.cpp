#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> segTree;
void buildTree(vector<ll> &skills,ll ind,ll l,ll r){
    if(l==r){
        segTree[ind] = skills[l];
        return;
    }
    ll mid = l+(r-l)/2;
    buildTree(skills,ind*2+1,l,mid);
    buildTree(skills,ind*2+2,mid+1,r);
    segTree[ind] = segTree[ind*2+1]^segTree[ind*2+2];
}
pair<ll,ll> find(vector<ll> &skills,ll ind,ll l,ll r,ll target,ll c){
    if(l==r){
        return {c,0};
    }
    ll mid = l+(r-l)/2;
    if(target<=mid){
        pair<ll,ll> left = find(skills,ind*2+1,l,mid,target,c);
        ll right_xor = segTree[ind*2+2];
        ll new_xor = left.first^right_xor;
        if(left.first>=right_xor){
            return {new_xor,left.second};
        }
        return {new_xor,left.second+(r-mid)};
    }
    else{
        pair<ll,ll> right = find(skills,ind*2+2,mid+1,r,target,c);
        ll left_xor = segTree[ind*2+1];
        ll new_xor = right.first^left_xor;
        if(left_xor>=right.first){
            return {new_xor,(mid-l+1)+right.second};
        }
        return {new_xor,right.second};
    }
}
void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> skills((1<<n)+1);
    for(ll i=1;i<=(1<<n);i++){
        cin>>skills[i];
    }
    segTree.assign(4*(1<<n),0);
    buildTree(skills,0,1,(1<<n));
    while(q--){
        ll b,c;
        cin>>b>>c;
        pair<ll,ll> pr = find(skills,0,1,(1<<n),b,c);  // {xor,cnt}
        cout<<pr.second<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}