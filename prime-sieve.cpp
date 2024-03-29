#include <bits/stdc++.h>
using namespace std;

class sieve_eratosthenes
{
    int n;
    vector<int> prime;


public:
    sieve_eratosthenes(int n){
        prime.resize(n+1,1);
        this->n = n;
    }
    // time : O(log(log(n)))
    void create(){
        prime[0]=0,prime[1]=0;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
    }
    bool isPrime(int n){
        return prime[n];
    }
};

int main(){
    int n=100000;
    sieve_eratosthenes prime(n);
    prime.create();

    return 0;
}
