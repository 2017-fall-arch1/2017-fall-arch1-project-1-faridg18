#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Node{
  char* name;
  struct Node *left;
  struct Node *right;
} BST;

void listAllEmployees(){
  int c;
  FILE *test;
  test = fopen("test.txt", "r");
  if(test){
    while((c = getc(test)) != EOF)
      putchar(c);
    fclose(test);
    printf("\n"
	   );
  }
}
void addEmployee(char *newName){
  FILE *test = fopen("test.txt", "a");
  
  fputs(newName, test);
}

void deleteEmployee(){

}


void deleteAllEmployees(){

}

int main(){
  _Bool run = true;
  while(run){
    char Fname[50];
    char Lname[50];
  printf("welcome to the personal management system 2017:\n\t");
  printf("1.add employee\n\t2.remove employee\n\t3.list all employee names\n\n\t");
  int choice;
  scanf("%d", &choice);
  
  if(choice == 1){
    printf("add new employee\n\t");
    printf("nenter name of new employee\n");
    scanf("%s", &Fname);
    printf("%s", Fname);
    addEmployee(strcat(Fname, "\n"));
  }else if(choice == 2){
    printf("remove employee:\n\t");
    printf("neter name of employee to remove");
    scanf("%s", &Fname);
  }
  else if (choice == 3){
    printf("list of all the employees");
    listAllEmployees();
  }
  else if (choice > 3 || choice < 0){
    printf("choice out of bounds");
  }

  }
  
  
  return 0;
}
