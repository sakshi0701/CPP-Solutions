class Solution
{
public:

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if ((matrix.size() == 0) || (matrix[0].size() == 0))
            return false;

        int row = 0;

        while ((row < matrix.size()) && (matrix[row].back() < target))
            row++;

        if (row >= matrix.size())
            return false;

        // found the right row, loop through it to find target
        for (auto a : matrix[row])
            if (a == target)
                return true;

        return false;
    }
};