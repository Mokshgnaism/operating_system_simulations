#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ispossible_to_run(vector<int>&avail,vector<vector<int>>&request,int idx){
    int m = avail.size();
    for(int i=0;i<m;i++){
        if(request[idx][i]>avail[i])return false;
    }
    return true;
}
bool deadlock(vector<vector<int>>&alloc,vector<int>&avail,vector<vector<int>>&request){
int n = alloc.size();//no of processes;
int m = alloc[0].size();
    int comp = 0;
    vector<int>done(n,false);
    while(comp<n){
        bool cant = true;
        for(int i=0;i<n;i++){
            if(!done[i]&&ispossible_to_run(avail,request,i)){
                comp++;
                done[i] = true;
                cant = false;
                for(int j = 0;j<m;j++){
                    avail[j] += alloc[i][j];
                    alloc[i][j] = 0;
                }
            }
        }
        if(cant){
            cout<<"in deadlock state"<<endl;
            return true;
        }
    }
    return false;
}

int32_t main() {
    // Example 1: No deadlock
    vector<vector<int>> alloc = {
        {0, 1, 0},  // P0
        {2, 0, 0},  // P1
        {3, 0, 2},  // P2
        {2, 1, 1},  // P3
        {0, 0, 2}   // P4
    };
    
    vector<int> avail = {3, 3, 2};  // Available resources
    
    vector<vector<int>> request = {
        {0, 0, 0},  // P0 needs nothing more
        {1, 0, 2},  // P1 requests 1A, 0B, 2C
        {1, 0, 0},  // P2 requests 1A
        {0, 1, 1},  // P3 requests 0A, 1B, 1C
        {0, 0, 0}   // P4 needs nothing more
    };

    cout << "Test Case 1: ";
    if (!deadlock(alloc, avail, request)) {
        cout << "No deadlock\n";
    }

    // Example 2: Deadlock
    vector<vector<int>> alloc2 = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 3},
        {2, 1, 1},
        {0, 0, 2}
    };

    vector<int> avail2 = {0, 0, 0};

    vector<vector<int>> request2 = {
        {0, 0, 0},
        {1, 0, 2},
        {6, 0, 0},
        {0, 1, 1},
        {4, 3, 1}
    };

    cout << "Test Case 2: ";
    if (!deadlock(alloc2, avail2, request2)) {
        cout << "No deadlock\n";
    }

    return 0;
}
