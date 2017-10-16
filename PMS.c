#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addEmployee.h"
#include "deleteEmployee.h"
#include "listAllEmployees.h"

typedef struct Node{
  char *name[50];
  struct Node *left;
  struct Node *right;
} Node;

int main(){
  FILE *test;
  int choice;
  int status = 1;
 
  printf("welcome to the personal management system 2017:\n\n");
  while(status){
    printf("\n1.add employee\n2.remove employee\n3.list all employee names\n\n\t");
    scanf("%d", &choice);
    if(choice == 1){
      addEmployee(test);
    }
    if(choice == 2){
      deleteEmployee(test);
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

  //createTree();
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

  
}

void deleteEmployee(FILE *X){
  char c;
  printf("%s", "enter the name of the employee to delete:\n\t");
  char name[50];
  scanf("%s", &name);
  X = fopen("test.txt", "rw");
  if(fgets(name, sizeof(X), X) != NULL){
    puts(name);
  }else{
    printf("%s", "name not found.\n");
  }
  
  fclose(X);

}

void listAllEmployees(FILE *X){
  short c;
  X = fopen("test.txt", "r");
  if(X){
    while(c != EOF){
     c = getc(X);
     putchar(c);
    }
   printf("\n");
  }
}

/*
void createTree(FILE *X){
  X = fopen("test.txt", "r");
  Node *temp;
  temp = insert(temp, "juan");
  fclose(X);
}


Node *insert(Node *head, char *name){
  if (head == NULL){
    Node *temp;
    temp = malloc(sizeof(Node));
    temp -> name = ;
    temp -> left = temp -> right = NULL;
    return temp;
  }
  return NULL;
  
}
*/
