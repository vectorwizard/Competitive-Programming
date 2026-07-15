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
    ll extra = a[1]-1;
    a[1] = 1;
    for(ll i=2;i<=n;i++){
        if(a[i]>a[i-1]+1){
            extra+=(a[i]-a[i-1]-1);
            a[i] = a[i-1] + 1;
        }
        else{
            ll need = a[i-1] + 1 - a[i];
            if(extra<need){
                cout<<"NO"<<endl;
                return;
            }
            else{
                extra-=need;
                a[i] = a[i-1] + 1;
            }
        }
    }
    cout<<"YES"<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
