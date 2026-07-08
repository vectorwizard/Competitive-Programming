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
    for(ll i=0;i<n;i++) cin>>a[i];
    ll mini = *min_element(a.begin(),a.end());
    vector<ll> gaps;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            mini = min(mini,abs(a[i]-a[j]));
            gaps.push_back(abs(a[i]-a[j]));
        }
    }
    if(k>=3){
        cout<<0<<endl;
        return;
    }
    else if(k==1){
        cout<<mini<<endl;
        return;
    }
    else{
        sort(a.begin(),a.end());
        for(ll i=0;i<gaps.size();i++){
            ll gap = gaps[i];
            ll ind_r = lower_bound(a.begin(),a.end(),gap) - a.begin();
            if(ind_r==n) continue;
            mini = min(mini,abs(a[ind_r]-gap));
            if(ind_r>0){
                ll ind_l = ind_r - 1;
                mini = min(mini,abs(a[ind_l]-gap));
            }
        } 
        cout<<mini<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
