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
    string temp = "";
    temp+=s[0];
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]) temp+=s[i];
    }
    if(temp.size()==2){
        cout<<2<<endl;
    }
    else cout<<1<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
