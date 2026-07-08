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
    vector<int> a(2*n);
    for(int i=0;i<2*n;i++) cin>>a[i];
    int zero1 = -1;
    int zero2 = -1;
    for(int i=0;i<2*n;i++){
        if(a[i]==0){
            if(zero1==-1) zero1 = i;
            else zero2 = i;
        }
    }
    multiset<int> st;
    int ans = 0;
    for(int i=0;i<n;i++){
        st.insert(i);
        st.insert(i);
    }
    int l,r,mex1,mex2,mex3;
    int dist = zero2 - zero1;
    l = zero1 +dist / 2;
    r = zero1 +(dist + 1) / 2;
    if(l==r){
        st.erase(a[l]);
        l--;
        r++;
    }
    if(st.empty()) mex1 = n;
    else mex1 = *st.begin();
    ans = max(ans,mex1);
    while(l>=0 && r<2*n){
        if(a[l]!=a[r]){
            break;
        }
        else{
            st.erase(a[l]);
            if(st.empty()) mex1 = n;
            else mex1 = *st.begin();
            ans = max(ans,mex1);
        }
        l--;
        r++;
    }

    multiset<int> st1;
    for(int i=0;i<n;i++){
        st1.insert(i);
        st1.insert(i);
    }
    st1.erase(0);
    l = zero1-1;
    r = zero1+1;
    bool poss2 = true;
    if(st1.empty()) mex2 = n;
    else mex2 = *st1.begin();
    ans = max(ans,mex2);
    while(l>=0 && r<2*n){
        if(a[l]!=a[r]){
            poss2 = false;
            break;
        }
        else{
            st1.erase(a[l]);
            if(st1.empty()) mex2 = n;
            else mex2 = *st1.begin();
            ans = max(ans,mex2);
        }
        l--;
        r++;
    }
    l = zero2-1;
    r = zero2 + 1;
    multiset<int> st2;
    for(int i=0;i<n;i++){
        st2.insert(i);
        st2.insert(i);
    }
    st2.erase(0);
    bool poss3 = true;
    if(st2.empty()) mex3 = n;
    else mex3 = *st2.begin();
    ans = max(ans,mex3);
    while(l>=0 && r<2*n){
        if(a[l]!=a[r]){
            poss3 = false;
            break;
        }
        else{
            st2.erase(a[l]);
            if(st2.empty()) mex3 = n;
            else mex3 = *st2.begin();
            ans = max(ans,mex3);
        }
        l--;
        r++;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
