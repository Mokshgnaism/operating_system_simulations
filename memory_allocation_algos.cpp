#include <bits/stdc++.h>
using namespace std;
// #define int long long
vector<int>best_fit(vector<int>&processes,vector<int>&blocks){
    int n = processes.size();
    int m = blocks.size();
    vector<bool>filled(m,false);
    vector<int>places(n);
    for(int i=0;i<n;i++){
        int best_block = -1;
        int best_size = INT_MAX;
        for(int j=0;j<m;j++){
            if(!filled[j]&&blocks[j]>=processes[i]&&blocks[j]<best_size){
                best_size = blocks[j];
                best_block = j;
                // filled[j] = true;
            }
        }
        if(best_block==-1){
            throw("cant fit into the capacity ");
        }
        filled[best_block]=true;
        places[i] = best_block;
    }
    for(int i =0;i<n;i++){
        cout<<processes[i]<<" -> "<<blocks[places[i]]<<endl;
    }
    return places;
}
vector<int>worst_fit(vector<int>&processes,vector<int>&blocks){
    sort(blocks.rbegin(),blocks.rend());
    int m = blocks.size();
    int n = processes.size();
    bool ok = true;
    if(n>m){
        throw("error");
    }
    for(int i=0;i<n;i++){
        if(processes[i]>blocks[i])ok =false;
    }
    if(!ok){
        throw("error");
    }
    for(int i=0;i<n;i++){
       cout<<processes[i]<<" -> "<<blocks[i]<<endl;
    }
    return {};
}
int search_next(vector<int>&blocks,int process,vector<bool>&filled,int prev){
    for(int i = prev;i<blocks.size();i++){
        if(!filled[i]&&process <= blocks[i]){
            return i;
        }
    }
    for(int i=0;i<prev;i++){
        if(!filled[i]&&process <= blocks[i]){
            return i;
        }
    }
    return -1;
}
void next_fit(vector<int>&processes,vector<int>&blocks){
    int n = processes.size();
    int m = blocks.size();
    vector<int>places(n);
    if(n>m){
        throw("we fked up");
    }
    int prev = 0;
    vector<bool>filled(m);
    for(int i=0;i<n;i++){
        int idx = search_next(blocks,processes[i],filled,prev);
        if(idx==-1){
            throw "error";
        }
        prev = idx+1;
        places[i] = idx;
    }
    for(int i =0;i<n;i++){
        cout<<processes[i]<<" -> "<<blocks[places[i]]<<endl;
    }
}
int32_t main() {
    // Hardcoded process sizes
    vector<int> processes = { 417, 112, 426};

    // Hardcoded memory block sizes
    vector<int> blocks = {100, 500, 200, 300, 600};

    try {
        next_fit(processes, blocks);
    } catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    return 0;
}
