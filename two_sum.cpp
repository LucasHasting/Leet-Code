#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> solution;
        int index = 0;
        int special_index = -1;

        for (auto i = nums.begin(); i < nums.end(); ++i, ++index) {
            if (m.find(*i) != m.end()) {
                special_index = index;
                continue;
            }
            m[*i] = index;
        }

        for (auto i = nums.begin(); i < nums.end(); ++i) {
            if (m.find(target - *i) != m.end()) {
                if (m[target - *i] == m[*i]) {
                    if (special_index == -1)
                        continue;    
                    solution.push_back(m[*i]);                
                    solution.push_back(special_index);
                } else {
                    solution.push_back(m[*i]);
                    solution.push_back(m[target - *i]);
                }
                sort(solution.begin(), solution.end());
                return solution; 
            }
        }

        return solution;
    }
};
