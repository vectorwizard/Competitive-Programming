#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int MAXN = 200005; 
vector<int> segTree[4 * MAXN];
void buildTree(vector<int> &a,int ind,int l,int r){
    if(l==r){
        segTree[ind].push_back(a[l]);
        return;
    }
    int mid = l+(r-l)/2;
    buildTree(a,ind*2+1,l,mid);
    buildTree(a,ind*2+2,mid+1,r);
    const auto& left = segTree[ind*2+1];
    const auto& right = segTree[ind*2+2];
    segTree[ind].resize(left.size()+right.size());
    merge(left.begin(),left.end(),right.begin(),right.end(),segTree[ind].begin());
}
int query(int start,int end,int mini,int maxi,int ind,int l,int r){
    if(l>end || r<start) return 0;
    if(l>=start && r<=end){
        const auto& it = segTree[ind];
        return (upper_bound(it.begin(),it.end(),maxi) - lower_bound(it.begin(),it.end(),mini));
    }
    int mid = l+(r-l)/2;
    return query(start,end,mini,maxi,ind*2+1,l,mid)+query(start,end,mini,maxi,ind*2+2,mid+1,r);
}
void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    buildTree(a,0,0,n-1);
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int ans = query(a-1,b-1,c,d,0,0,n-1);
        cout<<ans<<'\n';
    }
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}