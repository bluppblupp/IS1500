/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15 by Niklas Kamateros
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6
int printAmount = 0;

void print_numbers (int n) {


  if (printAmount % 6 == 0){
    printf("\n");

  }

  printf("%10d ", n);
  printAmount++;
}



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

void print_primes(int n){
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS
for (int i = 2; i++; i <= n){
  if (is_prime (n)){
      print_numbers(n);

  }
}

}
// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}
