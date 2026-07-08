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
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<ll> vec(n+1);
    vec[1] = x;
    for(ll i=2;i<=n;i++){
        vec[i] = (vec[i-1]*a + b)%c;
    }
    ll ans = 0;
    vector<ll> prefix(n+1,0);
    vector<ll> suffix(n+1,0);
    int cnt = 1;
    prefix[1] = vec[1];
    for(int i=2;i<=n;i++){
        if(cnt==k){
            cnt = 1;
            prefix[i] = vec[i];
        }
        else{
            prefix[i] = prefix[i-1] | vec[i];
            cnt++;
        }
    }
    suffix[n] = vec[n];
    cnt = 1;
    for(int i=n-1;i>=1;i--){
        if(i%k==0){
            cnt = 1;
            suffix[i] = vec[i];
        }
        else{
            suffix[i] = suffix[i+1] | vec[i];
            cnt++;
        }
    }
    for(int i=k;i<=n;i++){
        ll x = prefix[i];
        if(i%k!=0) x = x | suffix[i-k+1];
        ans^=x;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
