// Link: https://practice.geeksforgeeks.org/problems/primes-sum5827/1

// Same isPrime() function we have discussed earlier
bool isPrime(int x)
{
    if(x == 1)
        return false ;
        
    for(int i = 2 ; i * i <= x ; i++)
    {
        if(x % i == 0)
            return false ;
    }
    
    return true ;
}

    string isSumOfTwo(int N)
    {
        // For Odd Numbers only One Possibility is there - 2 and Another Prime
        // (N - 2) should also be a Prime for the Pair to be feasible
        
        if(N % 2 == 1)
        {
            if(isPrime(N - 2) == true)
                return "Yes" ;
                
            else
                return "No" ;
        }
        
        // For Even Numbers we have to deal seperately
        // Even + Even --> Possible for Only 4
        // Otherwise we have to check for only Odd + Odd
        // Loop should run till N / 2. After that, pairs repeat
        
        if(N == 4)
            return "Yes" ;
            
        for(int i = 3 ; i <= N / 2 ; i += 2)
        {
            if(isPrime(i) == false)
                continue ;
                
            if(isPrime(N - i) == true)
                return "Yes" ;
        }
        
        return "No" ;
        
    }

// Time Complexity: O(N * Sqrt(N))
// Space Complexity: O(1)
