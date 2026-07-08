#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll ans = -1;
    set<ll> st;
    ll sum = 0;
    for(ll i=0;i<n;i++){
        sum+=a[i];
        if(sum%x!=0){
            ans = max(ans,i+1);
            st.insert(i);
        }
        else{
            if(st.size()==0) continue;
            else{
                ll x = *st.begin();
                ans = max(ans,(i-x));
            }
        }
    }
    cout<<ans<<endl;
}  

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
