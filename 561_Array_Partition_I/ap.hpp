#include <vector>
#include <algorithm>

class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) 
    {
        std::sort(nums.begin(),nums.end());
        int32_t sum=0;
        for(std::vector<int>::size_type i=0; i!=nums.size();i+=2)
            sum+=nums[i];
        
        return sum;
            
    }
};