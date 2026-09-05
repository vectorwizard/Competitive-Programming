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
    ll sx,sy;
    cin>>sx>>sy;
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        vec[i] = {x,y};
    }
    vector<ll> dr = {-1,0,1,0};
    vector<ll> dc = {0,1,0,-1};
    ll ans = -1;
    ll ansx;
    ll ansy;
    for(ll i=0;i<4;i++){
        ll nx = sx + dr[i];
        ll ny = sy + dc[i];
        if(nx<0 || nx>1e9 || ny<0 || ny>1e9) continue;
        if(i==0){
            ll cnt = 0;
            for(ll j=0;j<n;j++){
                if(vec[j].first<sx) cnt++;
            }
            if(cnt>ans){
                ans = cnt;
                ansx = nx;
                ansy = ny;
            }
        }
        else if(i==1){
            ll cnt = 0;
            for(ll j=0;j<n;j++){
                if(vec[j].second>sy) cnt++;
            }
            if(cnt>ans){
                ans = cnt;
                ansx = nx;
                ansy = ny;
            }
        }
        else if(i==2){
            ll cnt = 0;
            for(ll j=0;j<n;j++){
                if(vec[j].first>sx) cnt++;
            }
            if(cnt>ans){
                ans = cnt;
                ansx = nx;
                ansy = ny;
            }
        }
        else{
            ll cnt = 0;
            for(ll j=0;j<n;j++){
                if(vec[j].second<sy) cnt++;
            }
            if(cnt>ans){
                ans = cnt;
                ansx = nx;
                ansy = ny;
            }
        }
    }
    cout<<ans<<endl;
    cout<<ansx<<" "<<ansy<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
