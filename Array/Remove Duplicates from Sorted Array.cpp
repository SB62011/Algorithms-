// ### Problem: Remove Duplicates from Sorted Array
// Difficulty: Easy
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// #### 1. Understanding
// - Input: nums = [1,1,2]
// - Output: 2, nums = [1,2,_]
// - Constraints: 1 <= nums.length <= 3 * 104
// -100 <= nums[i] <= 100
// nums is sorted in non-decreasing order.
// - Edge cases: An empty array maybe

// #### 2. Pattern Recognition
// - Category: Array
// - Similar problems: https://leetcode.com/problems/remove-element/
// - Key patterns: In-Place Array Modification

// #### 3. Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Ideas:
// 1. Maintain i and j such that i is used to traverse and j points to the second duplicate and is replaced with the next unique element
// 2. Do step 1 in a for loop until the end of the array is reached
// 3. Return j, which will tell us the number of unique elements


//Solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j = 1; 

        for(int i = 1; i < nums.size() ; i++)
        {

                if(nums[i-1] != nums[i])
                {
                    nums[j] = nums[i];
                    j++;


                } // try not equal case instead of equal


        }

    return j; 
    }
};




// ### Post-Solution Analysis
// - What worked:
//   • The inequality approach 
// - What didn't work:
//   • I tried the other method where I maintained two pointers i and j in the beginning and end, that seemed to cause problems in terms of returning the number of unique elements, will revsisit
// - Key lessons:
//   • Try inequalities instead of straightforward equalities for problems like this too
// - Optimization opportunities:
//   • This is the best time complexity we can get

// ### Common Patterns Used
// 1. The inequality pattern
//    - When to use: Specifically try to use it in comparison problems
//    - Key implementation details NA
//    - Common pitfalls NA