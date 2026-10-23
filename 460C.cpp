#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>> a(n,vector<ll>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    ll ans = 0;
    if(k==1){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(a[i][j]==0) ans++;
            }
        }
        cout<<ans<<endl;
        return;
    }
    for(ll i=0;i<n;i++){
        ll cnt = 0;
        for(ll j=0;j<m;j++){
            if(a[i][j]==0) cnt++;
            else{
                if(cnt>=k) ans+=(cnt-k+1);
                cnt = 0;
            }
        }
        if(cnt>=k) ans+=(cnt-k+1);
    }
    for(ll j=0;j<m;j++){
        ll cnt = 0;
        for(ll i=0;i<n;i++){
            if(a[i][j]==0) cnt++;
            else{
                if(cnt>=k) ans+=(cnt-k+1);
                cnt = 0;
            }
        }
        if(cnt>=k) ans+=(cnt-k+1);
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
