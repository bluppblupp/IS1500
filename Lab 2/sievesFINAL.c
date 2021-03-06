/*
 sieves.c
 Written By Niklas Bergdahl
 30/09-2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define COLUMNS 6
int printAmount = 0;

void print_number(int n) {
    if (printAmount % COLUMNS == 0){
        printf("\n");
    }
    printf("%10d ", n);
    printAmount++;
}

void print_sieves(int n){
    if(n < 2){
        printf("%s\n", "Error, number has to be greater than 1" );
    } else {
        bool barray[n-1]; //skapar en array som går från 0-(n-2)
        for(int i = 0; i < n-1; i++){
            barray[i] = true;
        }
        for(int i = 0; (i+2)*(i+2) <= n; i++){
            if(barray[i] == true){
                for(int j = (i+2)*(i+2); j <= n; j += (i+2)) {
                    barray[j-2] = false;
                }
            }
        }
        for(int i = 0; i < n-1; i++) {
            if(barray[i] == true) {
                print_number(i+2);
            }
        }
    }
}
// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}