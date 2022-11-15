// LeetCode: https://leetcode.com/problems/factorial-trailing-zeroes/description/
// GFG: https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial5134/1

class Solution {
public:
    int trailingZeroes(int n) 
    {
        if(n <= 4) // If N is <= 4, we won't have any trailing zeros
            return 0 ;

        int ans = 0 ; // Ans will keep count of the Number Of 0s we encounter in N!

        for(int i = 5 ; i <= n ; i *= 5) // We start from 5 and keep incrementing to the next powers of 5 till N / i becomes equal to 0
        {
            int countOf5 = n / i ; // We check the number of 5s present

            ans += countOf5 ; // We add the count into our ans variable
        }

        return ans ;
    }
};

// Time Complexity:  O(Log N) [Base 5]
// Space Complexity: O(1)
