// Link: https://practice.geeksforgeeks.org/problems/primes-sum5827/1

string isSumOfTwo(int N)
{
        vector<bool> Primes(N , true) ; // In this approach, we calculate all the Prime Factors of N using Seive of Erathosthenes
        
        Primes[0] = false ;
        Primes[1] = false ;
        
        for(int i = 2 ; i * i <= N ; i++)
        {
            if(Primes[i] == false)
                continue ;
                
            for(int j = 2 * i ; j <= N ; j = j + i)
            {
                Primes[j] = false ;
            }
        }
        
        vector<int> nums ; // We store all the Prime Factors into a vector nums[]
        
        for(int i = 2 ; i <= N ; i++)
        {
            if(Primes[i] == true)
                nums.push_back(i) ;
        }
        
        // We use Two-Sum technique using HashMap to check if we can make any such Pair or Not
        unordered_map<int , int> map ;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int val = nums[i] ;
            
            if(val * val == N) // We need to handle the case of Perfect Square Numbers seperately
                return "Yes" ;
                
            int key = N - val;
            
            if(map.find(key) != map.end() )
                return "Yes" ;
                
            map[val] += 1 ;
        }
        
        return "No" ;
  }

// Time Complexity: O(N * Sqrt(N))
// Space Complexity: O(N)


