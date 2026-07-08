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
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int x = a[i];
        while(x%2==0){
            x/=2;
        }
        int ind = i;
        while(ind%2==0){
            ind/=2;
        }
        if(ind!=x){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}  

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}
