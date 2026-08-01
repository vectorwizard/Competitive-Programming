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
    string s1,s2;
    cin>>s1>>s2;
    int i = 0;
    while(i<n){
        if(s1[i]==s2[i]) i++;
        else if(s1[i]=='R' || s2[i]=='R'){
            cout<<"NO"<<endl;
            return;
        }
        else i++;
    }
    cout<<"YES"<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
