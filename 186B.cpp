#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int a,b;
    cin>>a;cin>>b;
    int ans1,ans2;
    long long x = 1;
    int i;
    int a1=a,b1=b;
    for(i=1;i<=21;i++){
        if(i%2==1){
            if(x<=a1) a1=a1-x;
            else break;
        }
        else{
            if(x<=b1) b1=b1-x;
            else break;
        }
        x=x*2;
    }
    ans1 = i-1;
    x=1;
    for(i=1;i<=21;i++){
        if(i%2==1){
            if(x<=b) b=b-x;
            else break;
        }
        else{
            if(x<=a) a=a-x;
            else break;
        }
        x=x*2;
    }
    ans2 = i-1;
    int ans = max(ans1,ans2);
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
