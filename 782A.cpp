#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,r,b;
    cin>>n>>r>>b;
    string s = "";
    int p = (r/(b+1));
    int q = (r%(b+1));
    for(int i=0;i<=b;i++){
        for(int j=0;j<p;j++){
            s+='R';
        }
        if(q>0){
            s+='R';
            q--;
        }
        if(i!=b) s+='B';
    }
    cout<<s<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
