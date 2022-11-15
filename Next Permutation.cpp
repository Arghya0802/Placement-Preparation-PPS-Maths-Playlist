// LeetCode: https://leetcode.com/problems/next-permutation/description/
// GFG: https://practice.geeksforgeeks.org/problems/next-permutation5226/1
// InterviewBit: https://www.interviewbit.com/problems/next-similar-number/

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size() ;

        int k = n - 1 ;

        while(k > 0) // We check for the element from which the array nums[] becomes unsorted
        {
            if(nums[k] > nums[k - 1]) // If nums[k] (current Element) is greater than nums[k - 1] (Element in front), then we need to break
                break ;

            k -= 1 ;
        }    

        if(k == 0) // If K reaches the beginning, that is, 0th Index, then we just sort nums[] vector and return as the largest possible permutation is already present
        {
            sort(nums.begin() , nums.end() ) ;
            return ; 
        }
        
        // If not, we have found our Inflex Point and now we need to calculate the element just greater than it and store it's Index
        int inflexPoint = nums[k] ;
        int swappedEle = INT_MAX ;
        int ind = k + 1 ;

        for(int i = k + 1 ; i < n ; i++)
        {
            if(nums[i] > inflexPoint) // We are looking for strictly increasing only
            {
                if(swappedEle > nums[i]) // If we have found any element, we will store it's index and update swappedElement variable
                {
                    swappedEle = nums[i] ;
                    ind = i ;
                }
            }
        }

        if(swappedEle != INT_MAX) // If we have found the Next Greater Element, we will just swap(nums[k] , nums[ind]) and sort nums[] from (k + 1)th Index
        {
            swap(nums[ind] , nums[k]) ;
            sort(nums.begin() + k + 1 , nums.end() ) ;
            return ;
        }
        
        // If we haven't found the next greater element, then we need to update our Inflex Point to (k - 1)th Index and repeat the same process
        inflexPoint = nums[k - 1] ;
        swappedEle = INT_MAX ;
        ind = k ;

        for(int i = k ; i < n ; i++)
        {
            if(nums[i] > inflexPoint)
            {
                if(swappedEle > nums[i])
                {
                    swappedEle = nums[i] ;
                    ind = i ;
                }
            }
        }
        
        // Now, we just need to swap(nums[k - 1] , nums[ind) and sort nums from kth Index only
        swap(nums[ind] , nums[k - 1]) ;

        sort(nums.begin() + k , nums.end() ) ;

        return ;

    }
};

// Time Complexity: O(N Log N)
// Space Complexity: O(1)
