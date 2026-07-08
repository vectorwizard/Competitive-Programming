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
    int a = 1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            a = (n/i);
            break;
        }
    }
    int b = n-a;
    cout<<a<<" "<<b<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
