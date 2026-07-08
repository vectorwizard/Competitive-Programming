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
    string s;
    cin>>s;
    int xorr1 = 0;
    int total = 0;
    vector<int> prefix(n,0);
    for(int i=0;i<n;i++){
        total^=a[i];
        if(s[i]=='1') xorr1^=a[i];
        prefix[i] = total;
    }
    int q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==2){
            int g;
            cin>>g;
            if(g==0){
                cout<<(total^xorr1)<<endl;
            }
            else cout<<xorr1<<endl;
        }
        else{
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            int pre = 0;
            if(l>0) pre = prefix[l-1];
            int xorr = (prefix[r])^pre;
            xorr1^=xorr;
        }
    }
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
