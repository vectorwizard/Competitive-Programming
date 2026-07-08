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
    int k = n/2;
    if(n%2==0){
        cout<<((k+1)*(k+1))<<endl;
    }
    else{
        cout<<(2*(k+2)*(k+1))<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
