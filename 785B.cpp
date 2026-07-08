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
    set<char> st;
    int n = s.size();
    string temp = "";
    for(int i=0;i<n;i++){
        if(st.count(s[i])==1) break;
        else {
            temp+=s[i];
            st.insert(s[i]);
        }
    }
    int m = temp.size();
    for(int i=m;i<n;i+=m){
        for(int j=0;j<m;j++){
            if((i+j)==n) break;
            if(temp[j]!=s[i+j]){
                cout<<"NO"<<endl;
                return;
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
