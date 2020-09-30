#include "deps.h"

struct timeval start_time, end_time;

int main(int argc, char *argv[]) {
  int number_cap, print_numbers;

  printf("Peter Krause's \033[1;31mPrimeFinder\033[0m V1\n");

  if (argc > 1) {
    number_cap = atoi(argv[1]);
    print_numbers = 0; //atoi(argv[2]);
  } else {
    number_cap = 1000000;
    print_numbers = 0;
  }
  printf("\nSearching numbers from 0 to %d\n", number_cap);

  struct node *head = NULL;
  int prime_count = 0;
  push(&head, NULL);

  gettimeofday(&start_time, NULL);
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
  gettimeofday(&end_time, NULL);

  double time_spent = (end_time.tv_sec - start_time.tv_sec) + ((end_time.tv_usec - start_time.tv_usec)/1000000.0);

  printf("\n");
  printf("There are %d prime numbers in range [0, %d]:\n", prime_count, number_cap);
  if (print_numbers == 1) {
    sleep(1);
    printf("Here they are!");
    printf("\n\n");
    sleep(1);
    print_list_with_sections(head, 1);
  }
  printf("Time spent searching for primes: %f\n", time_spent);
  printf("Finished execution");
  return 0;
}
