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
    int m=0;
    int c = 0;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(x>y) m++;
        else if(x<y) c++;
    }
    if(m>c) cout<<"Mishka"<<endl;
    else if(m<c) cout<<"Chris"<<endl;
    else cout<<"Friendship is magic!^^"<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}