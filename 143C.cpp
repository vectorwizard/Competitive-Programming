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
    vector<ll> b(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    vector<ll> prefix(n,0);
    prefix[0] = b[0];
    for(ll i=1;i<n;i++){
        prefix[i] = prefix[i-1] + b[i];
    }
    vector<ll> ans(n,0);
    vector<ll> diff(n+1,0);
    for(ll i=0;i<n;i++){
        ll offset = 0;
        if(i>0) offset = prefix[i-1];
        ll ind = lower_bound(prefix.begin()+i,prefix.end(),a[i]+offset)-prefix.begin();
        diff[i]++;
        if(ind<n){
            if(prefix[ind]==a[i]){
                diff[ind+1]--;
            }
            else{
                diff[ind]--;
                ll x = 0,y=0;
                if(i>0) x = prefix[i-1];
                if(ind>0) y = prefix[ind-1];
                ans[ind]+=(a[i]-y+x);
            }
        }
    }
    for(ll i=1;i<n;i++){
        diff[i] = diff[i-1]+diff[i];
    }
    for(ll i=0;i<n;i++){
        ans[i] += b[i] * diff[i];
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
