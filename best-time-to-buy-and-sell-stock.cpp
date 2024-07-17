class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int* window_start = &(*(prices.begin()));
        int* window_end = &(*(prices.begin()));
        int* begin = &(*(prices.begin()));
        int* start = &(*(prices.begin()));
        int* end = &(*(prices.end()));
        int* buy = nullptr;
        int* sell = nullptr;
        int record = 0;


        for(; start != end; ++start){
            buy = window_start;
            int offset = start - begin;
            int* current = begin + offset;

            if(window_end < window_start)
                    window_end = window_start;

            if(window_start != end+1 && *current < *window_start) {
                int new_record = *window_end - *window_start;
                if(record < new_record)
                    record = new_record;

                window_start = current;
                buy = window_start;
            }

            if(window_end != end+1 && *current > *window_end) {
                window_end = current;

                sell = window_end;

                int new_record = *window_end - *window_start;
                if(record < new_record)
                    record = new_record;
            }

            //cout << "WINDOW START: " << window_start - begin << "," << *window_start << "\n";
            //cout << "WINDOW END: " << window_end - begin << "," << *window_end << "\n\n";
        }
        return record;
    }
};
