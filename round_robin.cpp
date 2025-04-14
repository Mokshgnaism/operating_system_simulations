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
    bool inqueue = false;
    int turnaround = 0;
    bool completed = false;   
};
void roundrobbin(vector<process>&p,int qnt){
    int n = p.size();
    int comp = 0;
    queue<process*>q;
    int curr = 0;
    while(comp < n){
        for(int i=0;i<n;i++){
            if(!p[i].completed&&!p[i].inqueue&&p[i].arrival<=curr){
                q.push(&p[i]);
                p[i].inqueue = true;
            }
        }
        if(q.empty()){
            curr++;
            continue;
        }
        process *p1 = q.front();
        q.pop();
        int t = min(qnt,p1->burst);
        p1->burst -= t;
        curr +=t;
        if(p1->burst==0){
            
            p1->wait = curr - p1->arrival-p1->burst_init;
            p1->completion = curr;
            p1->turnaround = p1->wait + p1->burst_init;
            p1->completed = true;

            comp++;
            for(int i=0;i<n;i++){
                if(!p[i].completed&&!p[i].inqueue&&p[i].arrival<=curr){
                    q.push(&p[i]);
                    p[i].inqueue = true;
                }
            }
        }else{
            for(int i=0;i<n;i++){
                if(!p[i].completed&&!p[i].inqueue&&p[i].arrival<=curr){
                    q.push(&p[i]);
                    p[i].inqueue = true;
                }
            }
            q.push(p1);
        }
    }
}
int32_t main() {
    vector<process> p(4);

    // Hardcoded input
    p[0] = {1, 0, 5, 5};  // {id, arrival, burst_init, burst}
    p[1] = {2, 1, 4, 4};
    p[2] = {3, 2, 2, 2};
    p[3] = {4, 4, 1, 1};

    int quantum = 2;

    roundrobbin(p, quantum);

    cout << "Process ID\tArrival\tBurst\tCompletion\tWait\tTurnaround\n";
    for (auto &pr : p) {
        cout << pr.id << "\t\t" << pr.arrival << "\t" << pr.burst_init << "\t"
             << pr.completion << "\t\t" << pr.wait << "\t" << pr.turnaround << "\n";
    }

    return 0;
}