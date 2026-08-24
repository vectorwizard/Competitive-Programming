#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> segTree;
void build(ll ind,ll l,ll r,vector<ll> &a){
    if(l==r){
        segTree[ind] = a[l];
        return;
    }
    ll mid = l+(r-l)/2;
    build(ind*2+1,l,mid,a);
    build(ind*2+2,mid+1,r,a);
    segTree[ind] = min(segTree[ind*2+1],segTree[ind*2+2]);
}
ll query(ll ind,ll l,ll r,ll left,ll right){
    if(l> right || r<left) return 1e18;
    else if(l>=left && r<=right) return segTree[ind];
    ll mid = l+(r-l)/2;
    return min(query(ind*2+1,l,mid,left,right) , query(ind*2+2,mid+1,r,left,right)); 
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    segTree.assign(4*n,0);
    build(0,0,n-1,a);
    vector<ll> suffix(n);
    suffix[n-1] = a[n-1];
    for(ll i=n-2;i>=0;i--){
        suffix[i] = max(suffix[i+1],a[i]);
    }
    ll maxi = 0;
    for(ll i=0;i<n;i++){
        maxi = max(maxi,a[i]);
        ll low = i+2;
        ll high = n-1;
        while(low<=high){
            ll mid = low+(high-low)/2;
            if(suffix[mid]>maxi){
                low = mid+1;
            }
            else if(suffix[mid]<maxi){
                high = mid-1;
            }
            else{
                ll mini = query(0,0,n-1,i+1,mid-1);
                if(mini==maxi){
                    cout<<"YES"<<endl;
                    cout<<i+1<<" "<<mid-1-i<<" "<<(n-mid)<<endl;
                    return;
                }
                else if(mini<maxi){
                    high = mid-1;
                }
                else low = mid+1;
            }
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}