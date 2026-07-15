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
    vector<ll> a;
    for(ll i=0;i<k;i++){
        ll x;
        cin>>x;
        a.push_back(n-x);
    }
    sort(a.begin(),a.end());
    ll target = n;
    ll cnt = 0;
    for(ll i=0;i<a.size();i++){
        if(target<=a[i]) break;
        else{
            target-=a[i];
            cnt++;
        }
    }
    cout<<cnt<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
