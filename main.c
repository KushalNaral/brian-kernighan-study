/* count lines in input */
#include <stdio.h>

// Ex : 1 - 9
int main() {
  int c;
  int blank_count = 0;
  int prev_char_is_blank = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      prev_char_is_blank = 1;
      ++blank_count;
    } else if (c == '\n') {
      prev_char_is_blank = 0;
      blank_count = 0;
    } else {
      if ((prev_char_is_blank == 1) && blank_count >= 1) {
        printf(" ");
      }
      putchar(c);
      prev_char_is_blank = 0;
    }
  }
  printf("\nblank count : %d\n", blank_count);
}
