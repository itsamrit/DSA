// NO of primes till n 
int countPrimes(int n) {
    if(n <= 0)
        return 0;
    
    vector<bool>prime(n,true);
    prime[1]=false;
    int count=0;
    
    for(int i=2;i<n;i++){
        if(prime[i])
            count++;
        
        for(int j=2*i;j<n;j=j+i)
            prime[j]=false;
    }
    return count;
}
