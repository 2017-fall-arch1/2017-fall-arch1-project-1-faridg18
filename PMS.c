#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addEmployee.h"
#include "deleteEmployee.h"
struct Node{
  char* name;
  struct Node *left;
  struct Node *right;
} BST;


int main(){
  FILE *test;
  int choice;
  int status = 1;
  printf("welcome to the personal management system 2017:\n\t");
  while(status){
    printf("\n\t1.add employee\n\t2.remove employee\n\t3.list all employee names\n\n\t");
    scanf("%d", &choice);
    if(choice == 1){
      addEmployee(test);
      status = 1;
    }
    if(choice == 2){
      deleteEmployee(test);
      status = 1;
    }

    if(choice == 3){
      listAllEmployees(test);
    }
    
    if(choice == 0){
      status = 0;
    }
  }
  return 0;
}
 
void addEmployee(FILE *X){
  char in[50];
  X = fopen("test.txt", "a");
  printf("\tenter employee name\n");
  
  scanf("%s", &in);
  if(fgets(in, sizeof(in), stdin)){
    fputs(in, X);
    fclose(X);
  }
  
}

void deleteEmployee(FILE *X){
  printf("%s", "delete function");

}

void listAllEmployees(FILE *X){
  int c;
  X = fopen("test.txt", "r");
  if(X){
    while((c = getc(X)) != EOF)
     putchar(c);
   printf("\n");
  }
}
