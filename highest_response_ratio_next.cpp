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

void hrrn(vector<process>&p){
    int n = p.size();
    int curr = 0;
    for(int i=0;i<n;i++){
        int max_idx = -1;
        double max_r = INT_MIN*1.0;
        for(int idx = 0;idx<n;idx++){
            if(!p[idx].completed&&p[idx].arrival<=curr){
                int curr_wait = curr - p[idx].arrival;
                int curr_burst = p[idx].burst;
                double rn = 1 + (curr_wait/(curr_burst));
                if(rn>max_r){
                    max_r = rn;
                    max_idx = idx;
                }
            }
        }
        if(max_idx==-1){
            curr++;
            continue;
        }
        p[max_idx].wait = curr - p[max_idx].arrival;
        int t = p[max_idx].burst;
        curr+=t;
        p[max_idx].completion = curr;
        p[max_idx].turnaround = curr - p[i].arrival;
        p[max_idx].completed = true;
    }
}
int32_t main() {
    vector<process> p(4);

    // Hardcoded input: {id, arrival, burst}
    p[0] = {1, 0, 3};
    p[1] = {2, 2, 6};
    p[2] = {3, 4, 4};
    p[3] = {4, 6, 5};

    hrrn(p);

    cout << "Process ID\tArrival\tBurst\tCompletion\tWait\tTurnaround\n";
    for (auto &pr : p) {
        cout << pr.id << "\t\t" << pr.arrival << "\t" << pr.burst << "\t"
             << pr.completion << "\t\t" << pr.wait << "\t" << pr.turnaround << "\n";
    }

    return 0;
}
