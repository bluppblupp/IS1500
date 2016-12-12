//Written by Niklas Kamateros 2016-11-20


#include <stdio.h>
#include <stdbool.h>

char* text1 = "This is a string."; //text1 is a pointer to "This is a string"
char* text2 = "Yet another thing."; //text2 is a pointer to "Yet another thing"
int count = 0;  // .word 0 in assembly
int list1[20];  // .space 80 in assembly
int list2[20];  // .space 80 in assembly


void copycodes(char *text, int *lst, int *count) {
                              // assigns the value in lst(list1/list2) to the value in text.
        while (*text != 0) { // if the content of text is empty, we're done
                *lst = *text; // loop the function
                text++;      // go to the next place in text (1 byte since char type)
                lst++;       // go to the next place in the list (4 bytes since int type)
                *count +=1; // corresponds to addi	$t1,$t1,1, increase the memory-address of count


        }

}

void work() {
        copycodes(text1, list1, &count); //jal copycodes
        copycodes(text2, list2, &count); //jal copycodes

}


void printlist(const int* lst){
        printf("ASCII codes and corresponding characters.\n");
        while(*lst != 0) {
                printf("0x%03X '%c' ", *lst, (char)*lst);
                lst++;
        }
        printf("\n");
}

void endian_proof(const char* c){
        printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n",
               (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));

}

int main(void){
        work();

        printf("\nlist1: ");
        printlist(list1);
        printf("\nlist2: ");
        printlist(list2);
        printf("\nCount = %d\n", count);

        endian_proof((char*) &count);
}
