#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll curr = 0;
    string ans="";
    for(ll i=n-1;i>=0;i--){
        if(a[i]<=curr){
            ans+='1';
        }
        else if(curr==q){
            ans+='0';
        }
        else{
            ans+='1';
            curr++;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans) cout<<it;
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
