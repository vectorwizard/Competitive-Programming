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
    int l = 0;
    int r = n-1;
    while(l<r){
        if(a[l]==a[r]){
            l++;
            r--;
        }
        else break;
    }
    if(l==r || l>r){
        cout<<"YES"<<endl;
        return;
    }
    int target = a[l];
    int l1 = l+1;
    int r1 = r;
    while(l1<r1){
        if(a[l1]==a[r1]){
            l1++;
            r1--;
        }
        else if(a[l1]==target) l1++;
        else if(a[r1]==target) r1--;
        else break;
    }
    if(l1==r1 || l1>r1){
        cout<<"YES"<<endl;
        return;
    }
    int l2 = l;
    int r2 = r-1;
    target = a[r];
    while(l2<r2){
        if(a[l2]==a[r2]){
            l2++;
            r2--;
        }
        else if(a[l2]==target) l2++;
        else if(a[r2]==target) r2--;
        else break;
    }
    if(l2==r2 || l2>r2){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
