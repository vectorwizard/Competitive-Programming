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
    ll ans = 0;
    ll exc = 0;
    for(ll i=0;i<n;i++){
        if(b[i]>a[i]){
            ll need = b[i] - a[i];
            if(need>exc){
                cout<<-1<<endl;
                return;
            }
            else{
                exc-=need;
                ans+=exc;
                exc*=2;
                if(exc>=2e14){
                    cout<<-1<<endl;
                    return;
                }
            }
        }
        else{
            ll more = a[i] - b[i];
            ans+=(more+exc);
            exc+=more;
            exc*=2;
            if(exc>=2e14){
                cout<<-1<<endl;
                return;
            }
        }
    }
    if(exc==0){
        cout<<ans<<endl;
    }
    else cout<<-1<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}