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
    int zeros = 0;
    int ones = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') ones++;
        else zeros++;
    }
    int i = 0;
    for(i=0;i<n;i++){
        if(s[i]=='1'){
            if(zeros==0) break;
            else zeros--;
        }
        else {
            if(ones==0) break;
            else ones--;
        }
    }
    cout<<(n-i)<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
