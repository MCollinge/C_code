#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node;

Node *head = NULL;

void insert_head(int x){
  Node *newNode = (Node*)malloc(sizeof(Node));
  
  printf("%s: Inserting head node with data %d\n", __FUNCTION__, x);
  
  /* Setup new node */
  newNode->data=x;
  newNode->next=head;
  
  /* Set the hea pointer to new node */
  head = newNode;
}

void insert_tail(int x){
  Node *newNode = (Node*)malloc(sizeof(Node));
  Node *countNode = head;
  
  printf("%s: Inserting tail node with data %d\n", __FUNCTION__, x);
  /* Setup new node */
  newNode->data=x;
  newNode->next=NULL;
  
  /* Find current tail node */
  while(countNode->next != NULL){
    countNode = countNode->next;  
  }
  /* Point the current tail node at the new node */
  countNode->next = newNode;
}

void node_print(int x){
  Node *countNode = head;
  int count;
  
  printf("%s: ", __FUNCTION__);
  for(count=0;count<x;count++){
    printf("%d ", countNode->data);
    countNode = countNode->next;
    if(countNode == NULL){
      break;
    }
  }
  printf("\n");
}

void main(void) {
  int data[10]={ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int i=0;
  
  for(i=0;i<(sizeof(data)/sizeof(int));i++){
    insert_head(data[i]);
    insert_tail(data[i]);
  }
  
  node_print(20);
  
  return 0;
}
