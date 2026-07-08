#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> h(n);
    vector<int> t(m);
    for(int i=0;i<n;i++) cin>>h[i];
    for(int i=0;i<m;i++) cin>>t[i];
    multiset<int> st;
    for(int i=0;i<n;i++){
        st.insert(h[i]);
    }
    vector<int> ans(m);
    for(int i=0;i<m;i++){
        auto it = st.upper_bound(t[i]);
        if(it == st.begin()) ans[i] = -1;
        else {
            ans[i] = *(--it);
            st.erase(it);
        }
    }
    for(auto it:ans) cout<<it<<endl;
}  

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
