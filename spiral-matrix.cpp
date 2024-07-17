class Solution {
public:
    const int INVALID = -101;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> solution;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int row, col, current;
        int rotations[4][2] = {{1, 0},{0, -1},{-1, 0},{0, 1}};
        int rotation = 3;
        row = col = current = 0;

        if(columns == 1)
            rotation = 0;
        
        current = matrix[row][col];
        solution.push_back(current);
        matrix[row][col] = INVALID;

        while(current != INVALID){ 
            //rotate
            if(row + rotations[rotation][0] >= rows || col + rotations[rotation][1] >= columns
            || row + rotations[rotation][0] < 0 || col + rotations[rotation][1] < 0
            || matrix[row + rotations[rotation][0]][col + rotations[rotation][1]] == INVALID){
                if(rows == 1 && columns == 1){
                    break;
                } else if (rows == 1 || columns == 1) {
                    rotation = (rotation + 2) % 4;
                } else {
                    rotation = (rotation + 1) % 4;
                }
            }

            //move forward
            row += rotations[rotation][0];
            col += rotations[rotation][1];

            //update current
            current = matrix[row][col];
            solution.push_back(current);
            matrix[row][col] = INVALID;
        }

        if(solution.back() == INVALID)
            solution.pop_back();
        return solution;
    }
};
