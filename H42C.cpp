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
    vector<ll> ans(n+1);
    set<ll> st;
    for(ll i=1;i<=n;i++) st.insert(i);
    while(st.size()>2){
        ll a = *st.begin();
        st.erase(a);
        ll b = *st.begin();
        st.erase(b);
        ll c = *st.begin();
        st.erase(c);
        ll x,y;
        cout<<"?"<<" "<<"1"<<" "<<a<<" "<<b<<endl;
        cin>>x;
        cout<<"?"<<" "<<"1"<<" "<<b<<" "<<c<<endl;
        cin>>y;
        if(x==y){
            ans[b] = y;
            st.insert(a);
            st.insert(c);
        }
        else{
            if(x<y){
                ans[a] = x;
                st.insert(b);
                st.insert(c);
            }
            else{
                ans[c] = y;
                st.insert(a);
                st.insert(b);
            }
        }
    }
    ll s_last = *st.begin();
    st.erase(s_last);
    ll last = *st.begin();
    ll x;
    cout<<"?"<<" "<<"2"<<" "<<s_last<<endl;
    cin>>x;
    ans[s_last] = x;
    set<ll> st1;
    for(ll i=1;i<=n;i++) st1.insert(i);
    for(ll i=1;i<=n;i++){
        st1.erase(ans[i]);
    }
    ll last_ele = *st1.begin();
    ans[last] = last_ele;
    cout<<"!"<<" ";
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}  

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
