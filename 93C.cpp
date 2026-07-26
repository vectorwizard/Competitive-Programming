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
    string s;
    vector<ll> a(n+1);
    cin>>s;
    for(ll i=1;i<=n;i++){
        a[i] = s[i-1]-'0';
    }
    map<ll,ll> mpp;
    mpp[0] = 1;
    ll sum = 0;
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        sum+=a[i];
        if(mpp.find(i-sum)!=mpp.end()) ans+=mpp[i-sum];
        mpp[i-sum]++;
    }
    cout<<ans<<endl;
} 

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
