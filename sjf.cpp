#include <bits/stdc++.h>
using namespace std;
#define int long long
struct process{
    int id;
    int arrival;
    int burst;
    int completion = 0;
    int wait = 0;
    int turnaround = 0;
    bool completed = false;
};
void sjf(vector<process>&p){
    int curr = 0;
    int n = p.size();

    for(int i=0;i<n;i++){
        int min_time = INT_MAX;
        int min_idx = -1;
        for(int idx =0;idx<n;idx++){
            if(!p[i].completed&&p[i].arrival<=curr&&p[i].burst<min_time){
                min_time = p[i].burst;
                min_idx = i;
            }
        }

        if(min_idx==-1){
            curr++;
            continue;
        }
        p[i].wait = curr - p[i].arrival;
        int t = p[min_idx].burst;
        curr+=t;
        p[i].completion = curr;
        p[i].turnaround = curr - p[i].arrival;
        p[i].completed = true;
    }

}

int32_t main() {
    // Hardcoded input for testing
    int n = 4;
    vector<process> p(n);

    p[0] = {1, 0, 6};
    p[1] = {2, 1, 8};
    p[2] = {3, 2, 7};
    p[3] = {4, 3, 3};

    // Run Shortest Job First (SJF)
    sjf(p);

    // Output the results
    cout << "\nProcess ID\tArrival\tBurst\tCompletion\tWait\tTurnaround\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].id << "\t\t" << p[i].arrival << "\t" << p[i].burst << "\t"
             << p[i].completion << "\t\t" << p[i].wait << "\t" << p[i].turnaround << endl;
    }

    return 0;
}