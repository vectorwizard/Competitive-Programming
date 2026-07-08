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
    vector<vector<ll>> a(n,vector<ll>(n,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<ll>> rotated(n,vector<ll>(n,0));
    for(ll i=n-1;i>=0;i--){
        vector<ll> temp = a[i];
        reverse(temp.begin(),temp.end());
        rotated[n-1-i] = temp;
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(a[i][j]!=rotated[i][j]) ans++;
        }
    }
    ans = ans/2;
    if(k<ans){
        cout<<"NO"<<endl;
        return;
    }
    ll rem = k-ans;
    if(rem%2==0){
        cout<<"YES"<<endl;
        return;
    }
    else if(n%2==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
