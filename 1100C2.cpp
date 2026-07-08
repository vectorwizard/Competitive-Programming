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
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll sum = accumulate(a.begin(),a.end(),0LL);
    vector<ll> prefix(n);
    vector<ll> suffix(n);
    prefix[0] = abs(a[0]);
    suffix[n-1] = a[n-1];
    for(ll i=1;i<n;i++){
        prefix[i] = prefix[i-1] + abs(a[i]);
    }
    for(ll i=n-2;i>=0;i--){
        suffix[i] = suffix[i+1] + a[i];
    }
    ll ind = -1;
    for(ll i=0;i<n;i++){
        if(a[i]>0){
            if(i==0) continue;
            ll x = prefix[i-1] + suffix[i] - (2*a[i]);
            if(x>sum){
                ind = i;
                sum = x;
            }
        }
    }
    if(ind==-1){
        cout<<0<<endl;
        return;
    }
    ll par = 0;
    vector<ll> ans;
    for(ll i=ind-1;i>=0;i--){
        if(a[i]>0 && par==0){
            ans.push_back(i);
            par = 1;
        }
        else if(a[i]<0 && par==1){
            ans.push_back(i);
            par = 0;
        }
    }
    cout<<(ans.size()+1)<<endl;
    for(auto it:ans){
        cout<<it+1<<" ";
    }
    cout<<ind+1<<endl;
}
int main(){
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}