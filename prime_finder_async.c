#include "deps.h"

pthread_mutex_t lock;
void *find_primes_in_range();
struct timeval start_time, end_time;

int main(int argc, char *argv[]) {
  int number_cap, workers, thread_result, print_numbers;

  printf("Peter Krause's \033[1;31mPrimeFinder\033[0m V2\n");
  sleep(2);

  if (argc > 2) {
    number_cap = atoi(argv[1]);
    workers = atoi(argv[2]);
    print_numbers = 0; //atoi(argv[3]);
  } else {
    number_cap = 1000000;
    workers = 8;
    print_numbers = 0;
  }
  printf("\nSearching numbers from 0 to %d using %d worker threads\n", number_cap, workers);

  int range_length = number_cap / workers;
  int prime_count = 0;
  pthread_t worker_threads[workers];
  thread_arguments argument_array[workers];

  for (size_t i = 0; i < workers; i++) {
    argument_array[i] = malloc(sizeof(struct thread_arguments) * 1);
  }

  gettimeofday(&start_time, NULL);
  for (int index=0; index<workers; index++) {
    struct node *head = NULL;
    push(&head, NULL);
    argument_array[index]->head = *head;
    argument_array[index]->start_index = index * range_length + 1;
    argument_array[index]->end_index = (index * range_length + 1) + range_length;
    thread_result = pthread_create(&(worker_threads[index]), NULL, find_primes_in_range, argument_array[index]);
    if (thread_result == -1) {
      printf("Error creating thread %d\n", index + 1);
    }
  }

  for (int index=0; index<workers; index++) {
    thread_result = pthread_join(worker_threads[index], NULL);
    if (thread_result == 1) {
      printf("Failed to join thread %d\n", index + 1);
    }
  }
  gettimeofday(&end_time, NULL);

  double time_spent = (end_time.tv_sec - start_time.tv_sec) + ((end_time.tv_usec - start_time.tv_usec)/1000000.0);

  if (print_numbers == 1) {
    printf("Prime numbers are:\n");
    for (size_t i = 0; i < workers; i++) {
      print_list_with_sections(&argument_array[i]->head, i);
    }
  }
  printf("Time spent searching for primes: %f\n", time_spent);
  printf("Finished execution");
  return 0;
}

void *find_primes_in_range(void *arguments) {
  struct thread_arguments *args = arguments;
  struct node *head = &args->head;

  for (int k = args->start_index; k < args->end_index; k++) {
    int prime_if_zero = 0;
    for (int i = 2; i <= k / 2; ++i) {
        if (k % i == 0) {
            prime_if_zero = 1;
            break;
        }
    }
    if (prime_if_zero == 0) {
        push(&head, k);
    }
  }
}
