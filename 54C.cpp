#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    double d;
    cin>>d;
    if(d>0 && d<4){
        cout<<"N"<<endl;
        return;
    }
    cout<<"Y"<<" ";
    double x = 1.0*d*d - 4*d;
    double y = sqrt(x);
    double a = (d + y)/2.0;
    double b = (d - y)/2.0;
    cout<<fixed << setprecision(9)<<a<<" "<<b<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
