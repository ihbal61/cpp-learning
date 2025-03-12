#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int find(vector<int>& nums, int k) {
    int n = nums.size();
    if (k <= 0 || k > n) return -1;
    
    // 最小堆：值小的排后面，堆顶为当前k个元素中的最小值
    // 值相同时，下标大的排后面，堆顶为下标小的
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second; // 下标大的后移
        return a.first > b.first; // 值小的后移
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    
    for (int i = 0; i < n; ++i) {
        if (pq.size() < k) {
            pq.push({nums[i], i});
        } else {
            // 当前元素比堆顶大，或值相等但下标更小，则替换
            if (nums[i] > pq.top().first || 
               (nums[i] == pq.top().first && i < pq.top().second)) {
                pq.pop();
                pq.push({nums[i], i});
            }
        }
    }
    
    return pq.top().second;
}
int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    int res = find(nums, k);
    cout << res << endl;
    return 0;
}