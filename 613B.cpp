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
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    ll y = accumulate(a.begin(),a.end(),0LL);
    ll mini = 0;
    ll min_ind=-1;
    ll sum = 0;
    ll ans = 0;
    for(ll i=0;i<n-1;i++){
        sum+=a[i];
        ans=max(ans,(sum-mini));
        if(sum<=mini){
            mini = min(mini,sum);
            min_ind = i;
        }
    }
    if(min_ind!=-1){
        sum+=a[n-1];
        ans = max(sum-mini,ans);
    }
    if(y>ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
