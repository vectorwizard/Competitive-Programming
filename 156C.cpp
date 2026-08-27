#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    string s;
    cin>>s;
    ll pos;
    cin>>pos;
    stack<char> st;
    ll n = s.size();
    int len = n;
    ll i = 1;
    st.push(s[0]);
    while(i<n && s[i]>=st.top()){
        st.push(s[i]);
        i++;
    }
    while(i<len){
        while(pos>n && st.size()>0 &&  s[i]<st.top()){
            st.pop();
            pos-=n;
            n--;
        } 
        st.push(s[i]);
        i++;
    }
    while(pos>n){
        st.pop();
        pos-=n;
        n--;
    }
    ll cnt = 1;
    ll target = st.size() - (pos-1);
    while(cnt!=target){
        st.pop();
        cnt++;
    }
    cout<<st.top();
}
 
int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
