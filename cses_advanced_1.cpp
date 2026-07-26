#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> ssa;
    vector<ll> ssb;
    ll n1 = n/2;
    ll n2 = n-n1;
    for(ll mask = 0;mask<(1<<n1);mask++){
        ll sum = 0;
        for(ll i=0;i<n1;i++){
            if(mask&(1<<i)){
                sum+=a[i];
            }
        }
        ssa.push_back(sum);
    }
    for(ll mask = 0;mask<(1<<n2);mask++){
        ll sum = 0;
        for(ll i=0;i<n2;i++){
            if(mask&(1<<i)){
                sum+=a[n1+i];
            }
        }
        ssb.push_back(sum);
    }
    sort(ssb.begin(),ssb.end());
    ll ans = 0;
    for(ll i=0;i<ssa.size();i++){
        ll req = x - ssa[i];
        ll ub = upper_bound(ssb.begin(),ssb.end(),req)-ssb.begin();
        ll lb = lower_bound(ssb.begin(),ssb.end(),req)-ssb.begin();
        ans+=(ub-lb);
    }
    cout<<ans<<endl;
} 

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
