// Link: https://practice.geeksforgeeks.org/problems/prime-number2314/1

int isPrime(int N)
{
        if(N == 1) // For 1, we directly return false
            return 0 ;
            
        for(int i = 2 ; i * i <= N ; i++) // We go till Sqrt(N) to check if it's Prime or Not
        {
            if(N % i == 0)
                return 0 ;
        }
        
        return true ;
 }

// Time Complexity: O(Sqrt(N))
// Space Complexity: O(1)
