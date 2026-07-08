#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k,x;
    cin>>n>>k>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<ll> gaps;
    for(ll i=1;i<n;i++){
        ll gap = a[i]-a[i-1];
        if(gap>x) gaps.push_back(gap);
    }
    sort(gaps.begin(),gaps.end());
    ll i;
    for(i=0;i<gaps.size();i++){
        if(k==0) break;
        if(((gaps[i]-1)/x)<=k){
            k-=((gaps[i]-1)/x);
        }
        else break;
    }
    if(i==gaps.size()){
        cout<<1<<endl;
        return;
    }
    cout<<(gaps.size()-i+1)<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
