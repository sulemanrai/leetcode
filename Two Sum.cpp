class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> indices;
        bool flag = false;
        for(int i=0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target && i != j)
                {

                    flag = true;
                    indices.push_back(i);
                    indices.push_back(j);
                    break;

                }
            }
            if(flag == true)
                break;
        }

        return indices;
    }
};
