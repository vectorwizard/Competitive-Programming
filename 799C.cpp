
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    vector<vector<int>> a(8,vector<int>(8,0));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            char ch;
            cin>>ch;
            if(ch=='#') a[i][j] = 1;
        }
    } 
    int l,r;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(a[i][j]==1){
                int nrow = i-1;
                int ncol = j+1;
                if(nrow>=0 && nrow<8 && ncol>=0 && ncol<8 && a[nrow][ncol]==1){
                    r = nrow+ncol;
                }
            }
        }
    } 
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(a[i][j]==1){
                int nrow = i+1;
                int ncol = j+1;
                if(nrow>=0 && nrow<8 && ncol>=0 && ncol<8 && a[nrow][ncol]==1){
                    l = nrow-ncol;
                }
            }
        }
    } 
    int ansx,ansy;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(a[i][j]==1){
                int ab = i+j;
                int bc = i-j;
                if(ab==r && bc==l){
                    ansx = i;
                    ansy = j;
                    break;
                }
            }
        }
    } 
    cout<<ansx+1<<" "<<ansy+1<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}