#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n,vector<ll>(m,0));
    ll sum = 0;
    ll neg = 0;
    ll mini = 1e9;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
            sum+=abs(a[i][j]);
            if(a[i][j]<0) neg++;
            mini = min(mini,abs(a[i][j]));
        }
    }
    if(neg%2==0) cout<<sum<<endl;
    else cout<<(sum-2*mini)<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
