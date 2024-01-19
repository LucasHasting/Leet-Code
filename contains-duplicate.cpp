#include <set> 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //create set containing elements in nums
        set<int> nums_set(nums.begin(), nums.end()); 

        /*
          check to see if their length is the same, 
          if so, there are no duplicates.
        */
        return (nums_set.size() != nums.size());     
    }
};
