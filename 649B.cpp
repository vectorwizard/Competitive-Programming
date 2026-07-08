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
    vector<ll> ans;
    ans.push_back(a[0]);
    for(ll i=1;i<=n-2;i++){
        if((a[i]>a[i-1]) && (a[i]>a[i+1])){
            ans.push_back(a[i]);
        }
        else if((a[i]<a[i-1]) && (a[i]<a[i+1])){
            ans.push_back(a[i]);
        }
    }
    ans.push_back(a[n-1]);
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
