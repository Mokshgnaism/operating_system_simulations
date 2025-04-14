#include <bits/stdc++.h>
using namespace std;
// #define int long long
bool ispossible_to_run(vector<int>&curr_avl,vector<vector<int>>&need,int idx){
    int n = curr_avl.size();
    for(int i=0;i<n;i++){
        if(need[idx][i]>curr_avl[i])return false;
    }
    return true;
}
bool bankers(vector<vector<int>>&alloc,vector<int>&max_avail,vector<vector<int>>&maxneed){
    int n = alloc.size();//no of processes
    int m = max_avail.size();//no of resources

    vector<vector<int>>need(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j] = maxneed[i][j] - alloc[i][j];
        }
    }
    vector<int>curr_avl(m);
    for(int i=0;i<m;i++){
        int used = 0;
        for(int j=0;j<n;j++){
            used += alloc[j][i];
        }
        curr_avl[i] = max_avail[i]-used;//assuming no error
    }
    int comp = 0;
    vector<int>sequence;
    vector<bool>done(n,false);
    while(sequence.size()<n){
        bool cant = true;
        for(int i=0;i<n;i++){
            if(!done[i]&&ispossible_to_run(curr_avl,need,i)){
                sequence.push_back(i);
                done[i] = true;
                cant = false;
                for(int k = 0;k<m;k++){
                    curr_avl[k] += alloc[i][k];
                }
                break;
            }
        }
        if(cant){
            cout<<"compulsory deadlock "<<endl;
            return false;
        }
    }
    for(auto s:sequence){
        cout<<s+1<<" ";
    }
    cout<<endl;
}
int32_t main() {
    vector<vector<int>> alloc = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    vector<vector<int>> maxneed = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    vector<int> max_avail = {10, 5, 7}; // total available resources in the system

    bankers(alloc, max_avail, maxneed);

    return 0;
}
