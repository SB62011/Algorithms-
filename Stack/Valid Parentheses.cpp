// ### Problem: Valid Parentheses
// Difficulty: Easy
// Link: https://leetcode.com/problems/valid-parentheses/

// #### 1. Understanding
// - Input: s = "()[]{}"
// - Output: true
// - Constraints: 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.
// - Edge cases: Empty string maybe

// #### 2. Pattern Recognition
// - Category: Stack
// - Similar problems: Not sure yet
// - Key patterns: the condition is the same across different implementations, that is, the if conditions in the stack implementation

// #### 3. Approach 1
// Time Complexity: O(n)
// Space Complexity: O(?), not sure yet
// Key Ideas (Solution 1):
// 1. Run an outer loop that goes through the string "()[]{}" character by character
// 2. Run the inner loop that goes through all the possible mappings in the dict for that one character
// 3. if it matches the key in the dict (any of the open brackets) then push it in the stack, else, you would first check if the stack is empty on encountering a closed bracket, if it is then return false "(["
//    or if the top of the stack is not the value when the key c is used,then you'd return false, but if none of these are true, that is, if the stack is non-empty and the top is equal to the value that the key is mapped to in the dictionary ) -> parans[)] -> paran_stack.top() -> (, then you'd pop it
//      and in this way, if the elements are in the right order in the string, the stack should be empty in the end, if not then you'd return false.


// #### 3. Approach 2
// Time Complexity: O(n)
// Space Complexity: Not sure yet
// Key Ideas:
// 1. This is a very clever approach, it omits the inner loop in solution 1. We have the same outer loop, but inside the loop, we first check if our character from the string corresponds to any values as a key,
//     in other words, we're checking if c is a key or a value, or a closed bracket, or an open bracket
// 2. If this returns false, that is, if it is a value, then we'd just push it onto the stack, however, if it is a key, that is, if it is a closed bracket, then check if the stack is NOT empty and that the top element of the stack matches the value mapped with key c, this means that the order of the brackets in the string is correct
//      if this is the case, then we'd pop the top value or open bracket, else, if the stack is empty, that means we have encountered a closing bracket before any opening bracket, which makes the entire string wrong, so we return false, we also return false if the top bracket does not match the mapped value, that means the order is wrong, in both cases we return false
// 3.   Finally, we return whether the stack is empty or not, we'd just return true but that would take away the "(({[" case, if the stack is empty, that means everything is right and the order is right

// #### 3. Approach 3 (The brute force)
// Time Complexity: O(n)
// Space Complexity: Not sure yet
// Key Ideas:
// 1. "[{()}]", this solution follows a simple idea, it keeps the loop going while either (), [] or {} exists, if it exists remove it using erase and keep the loop going 
// 2. If it doesn't exist then break out of the loop and check whether the string still exists or if it's empty
// 3. If it is empty, then it was in the right order, if not, then the order is all messed up. Simple but effective. 
//solution 1
#include <stack>
#include <unordered_map>
class Solution {
public:
    bool isValid(string s) {

        stack<char> paran_stack;

        unordered_map<char, char> parans = {

            {')' , '('}, 
             {']' , '['}, 
              {'}' , '{'}

        };
for(char c : s)
    {

        for(const auto& paran: parans) 
        {

            if(paran.second == c)
            {
                paran_stack.push(c); 
       
            }

           else if(paran.first == c)
            {
              if(paran_stack.empty()) //combine this and
              {
        return false; 
              }
           
            if(paran_stack.top() != parans[c]) //this in or condition or dmouvres into and
            {    
                return false; 
            }else 
            {
                paran_stack.pop();
            }

           }
        }   
    }

    if(paran_stack.empty())
    {
        return true; 
    }

    return false;
        
    }
};


//solution 2
#include <stack>
#include <unordered_map>
class Solution {
public:
    bool isValid(string s) {

        stack<char> paran_stack;

        unordered_map<char, char> parans = {

            {')' , '('}, 
             {']' , '['}, 
              {'}' , '{'}

        };
for(char c : s)
    {
        if(parans.count(c))
        {
            if(!paran_stack.empty() && parans[c] == paran_stack.top())
            {
                paran_stack.pop(); 
            }else
            {
                return false; 
            }


        }else
        {
            paran_stack.push(c);
        }

    }

return paran_stack.empty();
        
    }
};

//Solution 3 (Brute force)
class Solution {
public:
    bool isValid(string s) {
        while (true) {
            size_t pos = string::npos;
            if ((pos = s.find("()")) != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            if ((pos = s.find("{}")) != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            if ((pos = s.find("[]")) != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            break;
        }
        return s.empty();
    }
};




// ### Post-Solution Analysis
// - What worked:
//   • The stack if condition was very specific but works beautifully, push the open brackets and check whether the stack is empty and the top of the stack matches the value the closed key maps to, pop based on this
// - What didn't work:
//   • It was just a series of trial and error
// - Key lessons:
//   • find will return an iterator but increases time complexity, and   if(parans.count(c)) can also be   if(parans.find(c) != parans.end())
//   • contains just returns whether the key exists
//   • count returns how many elements the key is mapped to
//   • Each of them could be used but count seems to be the fastest
//   • pop does NOT return anything
//   • Unordered maps are optimized for key lookups but not value lookups
//   • string::npos is used with string member functions like find(), while .end() is used with iterators.
// - Optimization opportunities:
//   • I feel that the second solution is more optimized than the first, also count() is the most efficient 

// ### Common Patterns Used
// 1. if(!paran_stack.empty() && parans[c] == paran_stack.top())
//    - When to use
//    - Key implementation details
//    - Common pitfalls