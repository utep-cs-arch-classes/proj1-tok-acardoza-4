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

  printf("This is a tokenizer. Enter q to quit. Enter ![n] to view the nth item in history.\n");
  while (*str != 'q') {
    printf("$");
    int i = 0;
    for (char input_char; (input_char = getchar())!='\n' && i < LIMIT; i++) {
      str[i] = input_char;
      putchar(input_char);      
    }
    printf("\n");
    if(*str != 'q' && *str != '!') {
      char **token = tokenize(str);
      printf("String tokens:\n");
      print_tokens(token);
      free_tokens(token);

      add_history(history, str);
    }
    if (*str == '!') {
      int index = (int)(str[1] - '0');
      char *prev_str = get_history(history, index);
      if (prev_str != NULL) {
	printf("The item in history is:");
	printf(prev_str);
	printf("\n");
      }
    }
  }
  printf("The history is: ");
  print_history(history);
  printf("History cleaned");
  free_history(history);
  return 0;
}
