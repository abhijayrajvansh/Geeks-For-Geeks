/*-------------------------------------------------
Job Sequencing Problem

Given a set of N jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit associated with job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).

Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).
--------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;


template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef ABHIJAY_DEBUG
#define deb(...) cerr << "["<< #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__);
#else
#define deb(...)
#endif


struct Jobs{

    int id;
    int dead;
    int profit;
};
/*-------------------------------------------------
ID    Deadline   Profit
````````````````````````
1       4         50
2       1         10
3       1         40
4       1         30

ps: each job requires 1 unit of time to complete and 
only one job can perform at a single time
--------------------------------------------------*/

// we sort them in a decending manner with max profit and
// pick up the 1 job - 2 job - 3job as per condition

// so we perform the maximum profit job on the last possible slot (on deadline)
// so that we can perform other jobs on their respective slots

bool compare(Jobs j1, Jobs j2){
    return j1.profit > j2.profit;
}

vector<int> JobScheduling(Jobs arr[], int n){
    int maxDead = arr[0].dead;
    for(int i = 1; i < n; i++){
        maxDead = max(arr[i].dead, maxDead);
    }
    
    vector<bool> deadline(maxDead, false);

    sort(arr, arr + n, compare);

    int pr = 0, maxjobs = 0;

    for(int i = 0; i < n; i++){
        for(int check = arr[i].dead - 1; check >= 0; check--){
            if(deadline[check] == false){
                deadline[check] = true;
                pr += arr[i].profit;
                maxjobs++;
                break;
            }
        }
    }

    vector<int> ans;
    ans.push_back(maxjobs);
    ans.push_back(pr);

    return ans; 
}


int main (){
    
    int n = 4;
    Jobs arr[] = {{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    cout << ans[0] << " " << ans[1] << '\n';

    return 0;
}

