// Link: https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/

long long smallestpositive(vector<long long> &arr, int n)
{ 
        sort(arr.begin() , arr.end()) ; // We first sort the array so that we can go sequentially
        
        long long int ans = 1 ; // Intially, our ans is 1
        
        for(int i = 0 ; i < n ; i++)
        {
            if(arr[i] <= ans) // If arr[i] is less than or equal to number, it means we can make this number
                ans += arr[i] ; // Next possible number we should check is equal to ans = ans + arr[i]
                
            else // Else we have go the smallest missing positive number
                return ans ;
        }
        
        return ans ; // At the end, if we traverse all the array elements, then (sum of array elements + 1) is the smallest positive number missing
 }

// Time Complexity:  O(N * LogN)
// Space Complexity: O(1)
