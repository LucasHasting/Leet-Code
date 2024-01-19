#include <vector>
#include <stack>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //declare output and stack
        vector<int> output(temperatures.size(),0);
        stack<vector<int>::iterator> stac;
        int days = 0;
        int index = 0;

        //loop for every tempature
        for (auto i = temperatures.begin(); i < temperatures.end()-1; ++i){

            //insert into stack
            stac.push(i);

            //while end of stack < future value
            while(!stac.empty() && *(stac.top()) < *(i+1)){
                //get days and index
                days = &(*i) - &(*(stac.top())) + 1;
                index = &(*(stac.top())) - &(*temperatures.begin());

                //update
                output[index] = days;

                //pop from stack
                stac.pop();
            }
        }

        return output;
    }
};
