#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    vector<ll> ans;
    ll par = 0;
    for(ll i=n;i>=1;i--){
        if(a[i]>0 && par==0){
            ans.push_back(i);
            par = 1;
        }
        else if(a[i]<0 && par==1){
            ans.push_back(i);
            par = 0;
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}