#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addEmployee.h"
#include "deleteEmployee.h"
#include "listAllEmployees.h"

typeodef struct Node{
  char* name;
  struct Node *left;
  struct Node *right;
} BST;

BST *head;

int main(){
  FILE *test;
  int choice;
  int status = 1;
 
  printf("welcome to the personal management system 2017:\n\t");
  while(status){
    printf("\n\t1.add employee\n\t2.remove employee\n\t3.list all employee names\n\n\t");
    scanf("%d", &choice);
    if(choice == 1){
      addEmployee(test, head);
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
    if(choice == 42){
      printf("clean file");
    }
  }
  return 0;
}
 
void addEmployee(FILE *X){
  char in[50];
  char in2[50];
  X = fopen("test.txt", "a");
  printf("\tenter employee name\n");
  
  scanf("%s %s", &in, &in2);
  printf("%s %s", in, in2);
  printf("%s",strcat(in, in2));

  if(fgets(strcat(in, in2), sizeof(strcat(in, in2)), stdin)){
    fputs(strcat(in, in2), X);
    fclose(X);
  }

  if(head == NULL){
    printf("%s", "empty head");
    
  }
  
}

void deleteEmployee(FILE *X){
  printf("%s", "enter the name of the employee to delete:\n\t");
  char name[50];
  scanf("%s", &name);
  X = fopen("test.txt", "rw");
  
  fclose(X);

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
