#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

#define LIMIT 100

/* User interface that tokenizes and keeps track of input */
int main()
{
  char str[LIMIT];
  List *history = init_history();
  int h_count = 0;
  printf("This is a tokenizer. Enter q to quit. Enter ![n] to view the nth item in history.\n");
  while (*str != 'q') {
    printf("$");
    int i = 0;
    for(int i = 0; i < LIMIT; i++){
      str[i] = '\0';
    }
    for (char input_char; (input_char = getchar())!='\n' && i < LIMIT; i++) {
      str[i] = input_char;
      putchar(input_char);      
    }
    printf("\n");
    if(*str != 'q' && *str != '!') {
      char **token = tokenize(str);
      printf("Tokenized string: \n");
      print_tokens(token);
      free_tokens(token);
      add_history(history, str);
      ++h_count;
    }
    if (*str == '!') {
      int index = (int)(str[1] - '0');
      if(index > h_count || index < 1){
	printf("The index is outside of the valid range, please try again.\n");
      }
      else {
	char *history_item = get_history(history, index);
	if (history_item != NULL) {
	  printf("The item in history is: \n");
	  printf(history_item);
	  printf("\n");
	}
      }
    }
  }
  printf("The complete history is: \n");
  print_history(history);
  free_history(history);
  printf("History cleaned.\nProgram exit.");
  return 0;
}
