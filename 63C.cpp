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
    vector<ll> nums(n);
    vector<ll> p(m);
    for(ll i=0;i<n;i++) cin>>nums[i];
    for(ll i=0;i<m;i++) cin>>p[i];
    ll gcdd = nums[1]-nums[0];
    for(ll i=1;i<n;i++){
        gcdd = __gcd(gcdd,nums[i]-nums[i-1]);
    }
    for(ll i=0;i<m;i++){
        if(gcdd%p[i]==0){
            cout<<"YES"<<endl;
            cout<<nums[0]<<" "<<i+1<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}