/*
 sieves.c
 Written By Niklas Bergdahl
 30/09-2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
        bool barray[n];
        for(int i = 0; i < n; i++){
            barray[i] = true;
        }
        for(int i = 0; i*i < n; i++){
            if(barray[i] == true){
                for(int j = 2i; j < n; j += i) {
                    barray[j] = false;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(barray[i] == true) {
                print_number(i);
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