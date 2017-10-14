#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addEmployee.h"

struct Node{
  char* name;
  struct Node *left;
  struct Node *right;
} BST;


int main(){
  FILE *test;
  char Fname[50];
  char Lname[50];
  int choice;
  printf("welcome to the personal management system 2017:\n\t");
  int status = 1;
  printf("look at me!");
  while(status){
    printf("1.add employee\n\t2.remove employee\n\t3.list all employee names\n\n\t");
    scanf("%d", choice);
    getchar();
    if(choice == 1){
      addEmployee(test);
      status =1;
    }
  }
  return 0;
}
 
void addEmployee(FILE *X){
  char in[50];
  X = fopen("test.txt", "a");
  printf("add new employee\n");
  //printf("nenter name of new employee\n");
  //scanf("%s", &in);
  if(fgets(in, sizeof(in), stdin)){
    fputs(in, X);
    fclose(X);
  }
}
//void listAllEmployees(){
//int c;
  //FILE *tes
    //test = fopen("test.txt", "r");
  //if(test){
  // while((c = getc(test)) != EOF)
  //  putchar(c);
  //  printf("\n");
  //}
//}
