#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k1,k2;
    cin>>n>>k1>>k2;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    ll k = k1+k2;
    ll total_gaps = 0;
    vector<ll> gaps;
    for(ll i=0;i<n;i++){
        total_gaps+=(abs(a[i]-b[i]));
        if(abs(a[i]-b[i])>0){
            gaps.push_back(abs(a[i]-b[i]));
        }
    }
    if(k>=total_gaps){
        ll rem = k-total_gaps;
        if(rem%2==0){
            cout<<0<<endl;
        }
        else cout<<1<<endl;
        return;
    }
    priority_queue<ll> pq;
    for(auto it:gaps) pq.push(it);
    while(k--){
        ll maxi = pq.top();
        pq.pop();
        maxi--;
        pq.push(maxi);
    }
    ll ans = 0;
    while(!pq.empty()){
        ll x = pq.top();
        pq.pop();
        ans+=(x*x);
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
