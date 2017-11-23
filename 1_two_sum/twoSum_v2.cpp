#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> mapping;
        vector<int> index;

        for (int i = 0; i < nums.size(); i++)
        {
            mapping[nums[i]] = i;
        }

        for(int i = 0; i< nums.size(); i++)
        {
            const int gap  = target = nums[i];

            if(mapping.find(gap) != mapping.end() && mapping[gap] > i)
            {
                index.push_back(i+1);
                index.push_back(mapping[gap]+1);
                break;
            }            
        }
        return index;
    }
};
