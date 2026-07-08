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
    string s;
    cin>>s;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    else if(n==2){
        if(s[0]==s[1]){
            cout<<2<<endl;
            return;
        }
        else {
            cout<<3<<endl;
            return;
        }
    }
    set<char> st;
    st.insert(s[0]);
    st.insert(s[1]);
    int cnt = 0;
    for(int i=2;i<n;i++){
        cnt+=st.size();
        st.insert(s[i]);
    }
    cnt++;
    cnt+=st.size();
    cout<<cnt<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
