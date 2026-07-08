#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;
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
    ordered_set<pair<ll,ll>> st;
    ll cnt = 0;
    for(ll i=0;i<k;i++){
        st.insert({a[i],i});
        ll ind = st.order_of_key({a[i],i});
        cnt+=(i-ind);
    }
    cout<<cnt<<" ";
    ll l = 0;
    for(ll r = k;r<n;r++){
        ll ind = st.order_of_key({a[l],l});
        cnt-=ind;
        st.erase({a[l],l});
        st.insert({a[r],r});
        ind = st.order_of_key({a[r],r});
        cnt+=(k-1-ind);
        l++;
        cout<<cnt<<" ";
    }
    cout<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}