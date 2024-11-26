// ### Problem: Concatenation of Array
// Difficulty: Easy
// Link: https://leetcode.com/problems/concatenation-of-array/description/

// #### 1. Understanding
// - Input: nums = [1,2,1]
// - Output: [1,2,1,1,2,1]
// - Constraints: n == nums.length
// 1 <= n <= 1000
// 1 <= nums[i] <= 1000
// - Edge cases: Not sure yet

// #### 2. Pattern Recognition
// - Category: Array
// - Similar problems: Not sure yet
// - Key patterns: the modulus division class of problems

// #### 3. Approach
// Time Complexity: O(n)
// Space Complexity: O(?) (not sure, I think O(n) since we're allocating another array)
// Key Ideas:
// 1. Basically use the modulus, mod the index with the original array size at each step and it'll produce the index that needs to be copied over to the new array
// 2. Do step 1 till the end of the new array index (double the original array size)
// 3. Return the new array

//Solution
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        vector<int> ans; 
    //    ans.resize(2 * nums.size()); //Without this, we get this error: Char 9: runtime error: reference binding to null pointer of type 'int' (stl_vector.h)
        //if you wanna remove this, use push back
        for(int i = 0 ; i < 2*nums.size(); i++)
        {

            // ans[i] = nums[i % nums.size()];
             ans.push_back(nums[i % nums.size()]); 
            



        }

          return ans;  
    }

 
};


// ### Post-Solution Analysis
// - What worked:
//   • The modulus 
// - What didn't work:
//   • There are other ways of doing this but this one seems to be the smartest
// - Key lessons:
//   • The modulus is great for repetitions in arrays
// - Optimization opportunities:
//   • Not sure yet

// ### Common Patterns Used
// 1. The modulus division
//    - When to use, when you require some sort of numeric reptition, this might be good to use
//    - Key implementation details NA
//    - Common pitfalls NA