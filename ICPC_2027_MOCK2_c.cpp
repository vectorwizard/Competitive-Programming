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
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    ll extra = 0;
    ll ans = 0;
    ll lazy = 0;
    ll prev = -1;
    for(ll i=0;i<n;i++){
        if(a[i]!=prev){
            extra+=lazy;
            lazy = 0;
        }
        if(a[i]==b[i]) continue;
        else if(a[i]<b[i]){
            ll need = b[i] - a[i];
            if(need<=extra){
                extra-=need;
                ans+=(need);
            }
            else{
                cout<<-1<<endl;
                return;
            }
        }
        else{
            lazy+=(a[i]-b[i]);
        }
        prev = a[i];
    }
    extra+=lazy;
    if(extra>0){
        cout<<-1<<endl;
    }
    else cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}