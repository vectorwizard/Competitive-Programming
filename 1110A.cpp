#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(k>(n/2)){
        cout<<-1<<endl;
        return;
    }
    int cnt = 0;
    for(int i=0;i<k;i++){
        if(s[i]=='L') cnt++;
        if(s[n-1-i]=='R') cnt++;
    }
    cout<<cnt<<endl;
} 

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
