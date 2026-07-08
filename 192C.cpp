#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    if(k==0){
        cout<<1<<endl;
        return;
    }
    vector<ll> hash;
    ll cnt =1;
    for(ll i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            hash.push_back(cnt);
            cnt = 1;
        }
        else cnt++;
    }
    hash.push_back(cnt);
    sort(hash.rbegin(),hash.rend());
    ll ans = 0;
    ll sum = 0;
    for(ll i=1;i<=hash.size();i++){
        sum+=hash[i-1];
        ll rem = k - sum;
        if(rem%i!=0) continue;
        ll x = rem/i;
        if(hash[i-1]+x<1) continue;
        if(i<hash.size() && hash[i-1]==hash[i]) continue;
        ans++;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
