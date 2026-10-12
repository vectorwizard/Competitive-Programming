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
    vector<ll> a(2*n);
    for(ll i=0;i<2*n;i++) cin>>a[i];
    ll mini = 1e9;
    n = 2*n;
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i==j) continue;
            vector<ll> temp;
            for(ll k=0;k<n;k++){
                if(k!=i && k!=j) temp.push_back(a[k]);
            }
            ll cnt = 0;
            for(ll k=1;k<(n-2);k+=2){
                cnt+=(temp[k] - temp[k-1]);
            }
            mini = min(mini,cnt);
        }
    }
    cout<<mini<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
