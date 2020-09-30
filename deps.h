
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/msg.h>
#include <sys/time.h>
#include "linked_list.c"

typedef struct thread_arguments {
  struct node head;
  int start_index;
  int end_index;
} *thread_arguments;
