//Written by Niklas Kamateros 2016-11-30


#include <stdio.h>
#include <stdbool.h>

char* text1 = "This is a string."; //text1 is a pointer to "This is a string"
char* text2 = "Yet another thing."; //text2 is a pointer to "Yet another thing"
int count = 0;
int list1[20];
int list2[20];


void copycodes(char *text, int lst[], int count) {
        bool condition = true;
        while (condition) {
                if (text == 0)
                        condition = true;
                else {

                        lst = (int)text;
                        count++;
                        lst = lst+4;
                            ++*text;

                }

        }


}

void work() {
        copycodes(text1, list1, count);
        copycodes(text2, list2, count);

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
