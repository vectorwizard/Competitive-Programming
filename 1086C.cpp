#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> c;
vector<int> p;
void solve() {
    int n;
    cin>>n;
    c.assign(n,0);
    p.assign(n,0);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        c[i] = a;
        p[i] = b;
    }
    double best = 0.0;
    for(int i=n-1;i>=0;i--){
        double nottake = best;
        double x = ((100.0-p[i])/100.0);
        double take = c[i] + (best*x);
        best = max(take,nottake);
    }
    cout<<fixed<<setprecision(10)<<best<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}