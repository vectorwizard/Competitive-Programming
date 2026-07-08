#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    vector<ll> b(m);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<m;i++) cin>>b[i];
    map<ll,ll> mpp1;
    map<ll,ll> mpp2;
    ll len = 0;
    for(ll i=0;i<n;i++){
        if(a[i]==1){
            len++;
        }
        else{
            for(ll j=1;j<=len;j++){
                mpp1[j]+=(len-j+1);
            }
            len=0;
        }    
    }
    for(ll j=1;j<=len;j++){
        mpp1[j]+=(len-j+1);
    }
    len = 0;
    for(ll i=0;i<m;i++){
        if(b[i]==1){
            len++;
        }
        else{
            for(ll j=1;j<=len;j++){
                mpp2[j]+=(len-j+1);
            }
            len=0;
        }    
    }
    for(ll j=1;j<=len;j++){
        mpp2[j]+=(len-j+1);
    }
    ll ans = 0;
    for(auto it:mpp1){
        ll x = it.first;
        if(k%x!=0) continue;
        ll y = k/x;
        if(y>m) continue;
        if(mpp2.find(y)!=mpp2.end()){
            ans+=(mpp1[x]*mpp2[y]);
        }
    }
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}