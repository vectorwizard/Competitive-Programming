#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
ll diag[2024][2024];
ll ans[2024][2024];
map<ll,pair<ll,ll>> mpp;
void solve() {
    ll cnt = 1;
    memset(diag,0,sizeof(0));
    memset(ans,0,sizeof(0));
    diag[1][1] = 1;
    mpp[1] = {1,1};
    for(ll i=2;i<=2023;i++){
        for(ll j=1;j<=i;j++){
            cnt++;
            mpp[cnt] = {i,j};
            if(i==1) continue;
            ll x = 0;
            if(j!=1){
                x = diag[i-1][j-1];
            }
            diag[i][j] = (cnt*cnt) + x; 
        }
    }
    ans[1][1] = 1;
    for(ll i=2;i<=2023;i++){
        for(ll j=1;j<=i;j++){
            ll x = 0;
            ans[i][j] = diag[i][j];
            if(ans[i-1][j]!=0) x = ans[i-1][j];
            ans[i][j]+=x;
        }
    }
}
 
int main() {
    fastio();
    ll t=1;
    solve();
    cin>>t;
    while (t--) {
        ll x;
        cin>>x;
        auto it = mpp[x];
        cout<<ans[it.first][it.second]<<endl;
    }
    return 0;
}
