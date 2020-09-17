#include "deps.h"

int main(int argc, char *argv[]) {
  int number_cap;

  printf("Peter Krause's \033[1;31mPrimeFinder\033[0m V1\n");
  sleep(2);

  if (argc > 1) {
    number_cap = atoi(argv[1]);
    printf("\nSearching numbers from 0 to %d\n", number_cap);
  } else {
    printf("\nUsing 10000 as default number cap...\n");
    number_cap = 10000;
  }

  struct node *head = NULL;
  int prime_count = 0;
  push(&head, 1);

  for (int number = 1; number < number_cap; number++) {
    int prime_if_zero = 0;
    for (int i = 2; i <= number / 2; ++i) {
          if (number % i == 0) {
              prime_if_zero = 1;
              break;
          }
      }
      if (prime_if_zero == 0) {
        prime_count += 1;
        push(&head, number);
      }
  }

  sleep(2);

  printf("\n");
  printf("There are %d prime numbers in range [0, %d]:\n", prime_count, number_cap);
  sleep(1);
  printf("Here they are!");
  printf("\n\n");
  sleep(1);
  print_list_with_sections(head, 1);
  return 0;
}
