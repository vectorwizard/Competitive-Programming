#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int s,k,m;
    cin>>s>>k>>m;
    int timer;
    int steps=m/k;
    if(k>s){
        int rem = m%k;
        cout<<max(0,s-rem)<<endl;
    }
    else{        //odd-k even-s
        int step=m/k;
        if(step%2==0){
            int timer = s;
            int rem = m%k;
            cout<<max(0,timer-rem)<<endl;
        }
        else{
            int timer = k;
            int rem = m%k;
            cout<<max(0,timer-rem)<<endl;
        }
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
