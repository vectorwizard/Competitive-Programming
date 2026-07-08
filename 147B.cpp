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
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int first = 0;
    int last = n-1;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            first = i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]!=b[i]){
            last = i;
            break;
        }
    }
    while(first>0 && b[first-1]<=b[first]){
        first--;
    }
    while(last<n-1 && b[last]<=b[last+1]){
        last++;
    }
    cout<<(first+1)<<" "<<(last+1)<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
