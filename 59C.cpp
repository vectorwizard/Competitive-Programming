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
    string s;
    cin>>s;
    char last = 'A';
    ll ans = 0;
    priority_queue<ll> pq;
    for(ll i=0;i<n;i++){
        if(s[i]==last){
            pq.push(a[i]);
        }
        else{
            ll cnt=k;
            while(cnt>0 && !pq.empty()){
                ll x = pq.top();
                ans+=x;
                pq.pop();
                cnt--;
            }
            while(!pq.empty()) pq.pop();
            last = s[i];
            pq.push(a[i]);
        }
    }
    ll cnt = k;
    while(cnt>0 && !pq.empty()){
        ll x = pq.top();
        ans+=x;
        pq.pop();
        cnt--;
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