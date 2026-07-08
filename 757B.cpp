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
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    vector<pair<ll,ll>> vec;
    for(ll i=1;i<=n;i++){
        vec.push_back({a[i],i});
    }
    sort(vec.rbegin(),vec.rend());
    vector<ll> ans(n+1,0);
    ll cnt1 = 1;
    ll cnt2 = -1;
    ll total = 0;
    for(ll i=0;i<n;i++){
        if(i%2==1){
            total+=(vec[i].first*cnt1);
            ans[vec[i].second] = cnt1;
            cnt1++;
        }
        else{
            total+=(vec[i].first*abs(cnt2));
            ans[vec[i].second] = cnt2;
            cnt2--;
        }
    }
    cout<<(total*2)<<endl;
    for(ll i=0;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
