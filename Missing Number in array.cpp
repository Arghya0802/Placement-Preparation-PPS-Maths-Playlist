// https://www.geeksforgeeks.org/find-the-missing-number/

int MissingNumber(vector<int>& array, int n) 
{
        int XOR = 0 ; // As the all the elements are distinct, we can use properties of XOR to find the Missing Number
        
        for(int nums : array) // First, we take XOR of all the elements present in array[]
            XOR ^= nums ;
            
        for(int i = 1 ; i <= n ; i++) // Next, we take XOR of all the numbers from i = 1 till <= N
            XOR ^= i ;
            
        return XOR ; // All the numbers present will cancel off each other and at the end we will be left with the Missing Number only
 }

// Time Complexity:  O(N)
// Space Complexity: O(1)
