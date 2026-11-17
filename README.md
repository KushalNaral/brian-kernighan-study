# The C Programming Language

**By Brian W. Kernighan and Dennis M. Ritchie**

Published by **Prentice-Hall (1988)**

- **ISBN (Paperback):** 0-13-110362-8
- **ISBN:** 0-13-110370-9

---

## Exercise 1-9

**Problem:** Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

### My Solution

Basically i thought of counting the blank chars that we have from the std in and have a state that manages if its previous char is blank as well.
If the prev char is blank we increase the blank count.
If the line breaks we reset the blank count.
Then if we have a prev blank char and the blank count is greater or 1 we just add one single blank space.
and we add the space then we print the stdin and reset the prev char blank to no.

```c
// Exercise 1-9
#include <stdio.h>

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
```

---

## Exercise 1-10

**Problem:** Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b,
and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way. 

```c
// Exercise 1-10
#include <stdio.h>

int main() {

    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
    } else if (c == '\\') {
      putchar('\\');
      putchar('\\');
    } else {
      putchar(c);
    }
  }
}
```

---

## Exercise 1-12

**Problem:** Write a program that prints its input one word per line.

### My Solution
So basically we initally have a state that maanges the in and out by making sure we look at if the std in is either a line break, space or tab.
After this we basically have points in the sequence where words are in and out. so when we reach a new character we print the first letter, and then if we are still in the word
we basically print that as well, and once we are out we basically stop printing and then check this sequence again.
Initial solution was using another var like blanks_count but we really dont need that right now.
```c
#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        putchar('\n');
      }
      state = OUT;
    } else if (state == IN) {
      putchar(c);
    } else if (state == OUT) {
      putchar(c);
      state = IN;
    }
  }
}
```
