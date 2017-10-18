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

Node *createNode(char *Name);
Node *insert (Node* nNode, Node* head);
void displayTree(Node *head);

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
      printf("clean file\n");
    }
  }
  printf("thank you for choosing the personal management system 2017.\n");
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
  /* if(X){
    while(fgets(temp, sizeof(temp), X)){
      printf("%d%s%s",id, ". ", temp);
      ++id;
    }
   printf("\n");
  }
  rewind(X);*/
 
  Node *root;
  root = createNode(("d\n")); 
  Node *tempNode;
  /*while(fgets(temp, sizeof(temp), X)){
    //Node *tempNode;
    tempNode = createNode(temp);
    printf("%s", tempNode -> name);
    root = insert(tempNode, root);
    }
  */
  root = insert(createNode("a\n"), root);
  root = insert(createNode("b\n"), root);
  root = insert(createNode("c\n"), root);
  root = insert(createNode("d\n"), root);
  root = insert(createNode("e\n"), root);
  root = insert(createNode("a\n"), root);
  root = insert(createNode("a\n"), root);
  root = insert(createNode("y\n"), root);
  displayTree(root);

  free(root);
  fclose(X);
}
void displayTree(Node * head){
  if(head == NULL || head -> name == NULL){
    return;
  }
  displayTree(head -> left);
  printf("%s", head->name);
  displayTree(head -> right);
}
Node *insert(Node *nNode, Node *head){
  if(!head){
    head = nNode;
  }
  if(strcmp(nNode -> name, head -> name) < 0){
   if(head -> left){
     head -> left = insert(nNode, head -> left);
   }
   else{
     head -> left = nNode;
     return head;
   }
  }
  else if(strcmp(nNode -> name, head -> name) > 0){
    if(head -> right){
      head -> right = insert (nNode, head->right);
    }
    else{
      head -> right = nNode;
      return head;
    }
  }
  return head;
}
Node *createNode(char *Name){
  Node *newNode;
  newNode = malloc(sizeof(Node));
  newNode -> name = Name;
  newNode -> right = NULL;
  newNode -> left = NULL;
  return newNode;
}
