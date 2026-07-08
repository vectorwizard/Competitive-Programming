#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,x;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    int global_xor =0;
    for(int i=0;i<n;i++){
        cin>>x;
        a[i] = x;
        global_xor = global_xor^x;
    }
    for(int i=0;i<n;i++){
        cin>>x;
        b[i] = x;
        global_xor = global_xor^x;
    }
    if(global_xor ==0){
        cout<<"Tie"<<endl;
        return;
    }
    int i;
    for(i=n-1;i>=0;i--){
        if(a[i]!=b[i]) break;
    }
    if((i+1)%2==0) cout<<"Mai";
    else cout<<"Ajisai";
    cout<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}