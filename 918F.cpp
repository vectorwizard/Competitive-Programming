#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
 
typedef tree<
    ll,
    null_type,
    less<ll>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void solve() {
    ll n;
    cin>>n;
    ordered_set st;
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++) {
        ll x,y;
        cin>>x>>y;
        vec[i] = {x,y};
        st.insert(y);
    }
    sort(vec.begin(),vec.end());
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll ending = vec[i].second;
        ll noofel = st.order_of_key(ending);
        ans+=noofel;
        st.erase(ending);
    }
    cout<<ans<<endl;
}
int main(){
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}