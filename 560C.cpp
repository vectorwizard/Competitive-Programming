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
    string ans = "";
    for(int i=0;i<n;i++){
        if(ans.size()%2==0){
            ans+=s[i];
        }
        else{
            if(ans.back()!=s[i]) ans+=s[i];
        }
    }
    if(ans.size()%2==1) ans.pop_back();
    cout<<(n-ans.size())<<endl;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}