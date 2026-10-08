
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
    if(n%3==0){
        cout<<(n/3)<<" "<<(n/3)<<endl;
    }
    else if(n%3==1){
        cout<<(n/3)+1<<" "<<(n/3)<<endl;
    }
    else{
        cout<<(n/3)<<" "<<(n/3)+1<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}