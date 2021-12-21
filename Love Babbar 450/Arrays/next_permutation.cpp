class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int index = -1;

        for (int i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                index = i - 1;
                break;
            }
        }

        if (index < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[index], nums[i]);
                reverse(nums.begin() + index + 1, nums.end());
                break;
            }
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
    }
};