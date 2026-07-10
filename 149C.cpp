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
    int n = s.size();
    string ans = "";
    char prev = 'a';
    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            if(prev=='a'){
                ans+='0';
            }
            else{
                ans+=prev;
            }
        }
        else{
            prev = s[i];
            ans+=s[i];
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
