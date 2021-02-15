#include "tokenizer.h"
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  if (c == ' ' || c == '\t'){
    return 0;
  }
  else{
    return 1;
  }
}
