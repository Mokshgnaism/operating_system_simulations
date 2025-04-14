#include <bits/stdc++.h>
using namespace std;
#define int long long

struct process{
    int id;
    int arrival;
    int burst_init;
    int burst;
    int completion = 0;
    int wait = 0;
    int turnaround = 0;
    bool completed = false;
};

void srtf(vector<process>&p){
    int n = p.size();
    int comp = 0 ;
    int curr = 0;
    while(comp<n){

        int min_time = INT_MAX;
        int min_idx = -1;

        for(int i =0;i<n;i++){
            if(!p[i].completed&&p[i].arrival<=curr&&p[i].burst<min_time){
                min_time = p[i].burst;
                min_idx = i;
            }
        }

        if(min_idx==-1){
            curr++;
            continue;
        }

        int i = min_idx;

        p[i].burst--;
        curr++;
        if(p[i].burst==0){

            p[i].wait = curr - p[i].arrival-p[i].burst_init;
            p[i].completion = curr;
            p[i].turnaround = p[i].wait + p[i].burst_init;
            p[i].completed = true;

            comp++;
        }
    }
}
int32_t main() {
    // Hardcoded input for testing
    int n = 4;
    vector<process> p(n);

    // Hardcoding the processes' data
    p[0] = {1, 0, 6, 6};  // Process 1: Arrival 0, Burst 6
    p[1] = {2, 1, 8, 8};  // Process 2: Arrival 1, Burst 8
    p[2] = {3, 2, 7, 7};  // Process 3: Arrival 2, Burst 7
    p[3] = {4, 3, 3, 3};  // Process 4: Arrival 3, Burst 3

    // Run Shortest Remaining Time First (SRTF) scheduling algorithm
    srtf(p);

    // Output the results
    cout << "\nProcess ID\tArrival\tBurst\tCompletion\tWait\tTurnaround\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].id << "\t\t" << p[i].arrival << "\t" << p[i].burst_init << "\t"
             << p[i].completion << "\t\t" << p[i].wait << "\t" << p[i].turnaround << endl;
    }

    return 0;
}