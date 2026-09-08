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
    ll maxi = 0;
    ll first = -1;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1) first = i;
        maxi = max(maxi,a[i]);
    }
    set<ll> st;
    for(ll i=2;i<=maxi+1;i++) st.insert(i);
    ll l = first-1;
    ll r = first+1;
    maxi = 1;
    set<ll> ans;
    ans.insert(1);
    while(l>=0 && r<n){
        if(a[l]<a[r]){
            st.erase(a[l]);
            maxi = max(maxi,a[l]);
            ll top = *st.begin();
            if(top == (maxi+1)){
                ans.insert(maxi);
            }
            l--;
        }
        else{
            st.erase(a[r]);
            maxi = max(maxi,a[r]);
            ll top = *st.begin();
            if(top == (maxi+1)){
                ans.insert(maxi);
            }
            r++;
        }
    }
    while(l>=0){
        st.erase(a[l]);
        maxi = max(maxi,a[l]);
        ll top = *st.begin();
        if(top == (maxi+1)){
            ans.insert(maxi);
        }
        l--;
    }
    while(r<n){
        st.erase(a[r]);
        maxi = max(maxi,a[r]);
        ll top = *st.begin();
        if(top == (maxi+1)){
            ans.insert(maxi);
        }
        r++;
    }
    for(ll i=1;i<=maxi;i++){
        if(ans.count(i)>0) cout<<1;
        else cout<<0;
    }
    cout<<endl;
} 
 
int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
