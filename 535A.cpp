#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    if(l1!=l2){
        cout<<l1<<" "<<l2<<endl;
        return;
    }
    else if(l1+1<=r1){
        cout<<l1+1<<" "<<l2<<endl;
        return;
    }
    else{
        cout<<l1<<" "<<l2+1<<endl;
    }
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}