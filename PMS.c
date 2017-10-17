#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "addEmployee.h"
#include "deleteEmployee.h"
#include "listAllEmployees.h"

typedef struct Node{
  char *name;
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
  return 0;
} 
void addEmployee(FILE *X){
  char in[50];
  X = fopen("test.txt", "a");
  printf("\tenter employee name\n");  
  scanf("%s", &in);
  fputs(strcat(in, "\n"), X);
  fclose(X);
  printf("%s", "do you want to add another one?(1, 0)\n");
  int choice;
  scanf("%d", &choice);
  if(choice){
    addEmployee(X);
  }
  
}
void deleteEmployee(FILE *X){
  char temp[50];
  X = fopen("test.txt","r");
  printf("%s","enter name of employee to be deleted from the system.\n");
  char search_name[50];
  FILE *Y;
  Y = fopen("test2.txt", "a");
  scanf("%s", &search_name);
  strcat(search_name, "\n");
 
  while(fgets(temp, sizeof(temp), X)){
    if(strcmp(temp, search_name) != 0){
      fputs(temp, Y);
    }
  }
  fclose(X);
  fclose(Y);
  remove("test.txt");
  
  rename("test2.txt", "test.txt");
}

void listAllEmployees(FILE *X){
  char temp[50];
  int id = 1;
  X = fopen("test.txt", "r");
  if(X){
    while(fgets(temp, sizeof(temp), X)){
      printf("%d%s%s",id, ". ", temp);
      ++id;
    }
   printf("\n");
  }
  fclose(X);
  Node * root;
  root = malloc(sizeof(Node));
  char * n = "toby";
  root -> name = "toby";
  root-> left = NULL;
  root -> right = NULL;

  free(root);
}

