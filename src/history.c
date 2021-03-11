#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

/* Initialize the linked list to keep the history. */

List* init_history()
{
  List *list = (List *)malloc(sizeof(List));
  list->root = NULL;
}

/* Add a history item to the end of the list.
       List* list - the linked list
       char* str - the string to store
*/
void add_history(List *list, char *str)
{
  short str_len;
  for(str_len = 0; str[str_len] != '\0'; str_len++){
    ;
  }
  int prev_id = 0;
  Item *new_history = (Item *)malloc(sizeof(Item));
  new_history->str  = copy_str(str, str_len);
  new_history->next = NULL;
  if (list->root == NULL) {
    list->root = new_history;
    new_history->id = 1;
    prev_id++;
  }
  else {
    Item *temp = (Item *)malloc(sizeof(Item));
    temp = list->root->next;
    prev_id = list->root->id;
    while(temp != NULL) {
      prev_id++;
      temp = temp->next;
    }
    temp = new_history;
    new_history->id = prev_id;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
       List* list - the linked list
       int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *current = list->root;
  while (current->id != id) {
    current = current->next;
  }
  return current->str;
}

/* Print the entire contents of the list. */
void print_history(List* list)
{
  Item *current = list->root;
  while(current != NULL) {
    printf(" %s ", current->str);
    current = current->next;
  }
  printf("\n");
}

/* Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *current = list->root;
  Item *next;
  while (current != NULL) {
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
}













