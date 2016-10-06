/*
 prime.c
 Written By Niklas Bergdahl
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
//#include <stdbool.h>

int is_prime(int n){
    if(n <= 1){
        return 0;
    }
    int i = 3;
    if(n % 2 == 0){//checks if n is even
        if(n == 2){//checks if n 2, which is the only even prime
            return 1;
        } else {
            return 0;
        }
    }
    while(i*i<=n){//if i is greater than the root of n
        if(n % i == 0){
            return 0;
        }
        i += 2;
    }
    return 1;
}

int main(void){
  printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
}
