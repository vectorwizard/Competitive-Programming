#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    int n;
    cin>>n;
    set<int> st;
    for(int i=1;i<=3003;i++) st.insert(i);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        st.erase(a);
    }
    cout<<*st.begin()<<endl;
} 
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
