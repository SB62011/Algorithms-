// ### Problem: Remove Element
// Difficulty: Easy
// Link: https://leetcode.com/problems/remove-element/

// #### 1. Understanding
// - Input: nums = [3,2,2,3], val = 3
// - Output: 2, nums = [2,2,_,_]
// - Constraints: 0 <= nums.length <= 100
// 0 <= nums[i] <= 50
// 0 <= val <= 100
// - Edge cases: Not sure yet, maybe an empty array

// #### 2. Pattern Recognition
// - Category: Array
// - Similar problems: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/, 
// - Key patterns:  In-Place Array Modification

// #### 3. Approach 1
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Ideas:
// 1. Maintain two pointers, the first and the last element
// 2. Copy over array elements that do not match the value only using i
// 3. Do this till i <=j 

// #### 3. Approach 2
// Time Complexity: O(n)
// Space Complexity: O(1)
// Key Ideas:
// 1. Maintain two pointers, i for normal array traversal in the for loop and j to keep track of where the element that does not match the value needs to go
// 2. Copy over array elements that do not match the value to j's position and increment j
// 3. Do this till the whole array has been traversed


//Approach 1
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int j = 0; 

        for(int i = 0 ; i < nums.size(); i++)
        {

            if(nums[i] != val)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;



        
    }
    
};


//Solution 2
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

            int i = 0; 
            int j = nums.size() - 1; 

            while(i <= j)
            {
                if(nums[i] == val && nums[j] == val)
                {
                        j--;


                }
                else if(nums[i] == val && nums[j] != val)
                {
                    nums[i] = nums[j];
                    i++;
                    j--;
                }
                else if(nums[i] != val && nums[j] != val)
                {
                   
                    i++;
              


                }
                else {

                    i++;
                    j--;
                }





            }


return i;
        
    }
    
};


// ### Post-Solution 1 Analysis
// - What worked:
//   • Traversing the array in different ways and copying over elements that did NOT match the value in different ways
// - What didn't work:
//   • I had to make i <= j, i < j wasn't working in approach 1, also I had to add an extra condition,   else if(nums[i] != val && nums[j] != val)
                // {
                   
                //     i++;
              


                // }

                //to make this work, it was skipping over elements that needed to be copied over
// - Key lessons:
//   • Always check out of bounds conditions
// - Optimization opportunities:
//   • I tried to optimize using the while loop and dividing, but it was the same complexity in the end

// ### Common Patterns Used
// 1. [Pattern name]
//    - When to use
//    - Key implementation details
//    - Common pitfalls