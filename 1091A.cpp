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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int total = accumulate(a.begin(),a.end(),0);
    if(total%2==1){
        cout<<"YES"<<endl;
        return;
    }
    else if((n*k)%2==0){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
