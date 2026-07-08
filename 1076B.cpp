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
    vector<int> b = a;
    sort(b.rbegin(),b.rend());
    bool found = false;
    int l = 0,r=0;
    int finding = 0,start = 0,end =0;
    while(l<n && r<n){
        if(found==false && a[l]!=b[r]){
            found = true;
            finding = b[r];
            start = l;
        }
        else if(found==true && a[l]==finding){
            end = l;
        }
        l++;
        r++;
    }
    if(found==false){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else{
        for(int i=0;i<start;i++){
            cout<<a[i]<<" ";
        }
        for(int i=end;i>=start;i--){
            cout<<a[i]<<" ";
        }
        for(int i=end+1;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}