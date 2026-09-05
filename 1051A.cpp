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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int i = 0;
    int j = n-1;
    int t = 1;
    while(i<=j){
        if(a[i]==t){
            i++;
        }
        else if(a[j]==t){
            j--;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
        t++;
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
