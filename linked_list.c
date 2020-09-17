#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node **next;
};

int push(struct node **h, int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    if (*h == NULL) {
        temp->next = *h;
        *h = temp;
    } else {
        struct node *tmp = *h;
        struct node *prev = NULL;
        while (1) {
            if (tmp == NULL || tmp->data >= temp->data)
                break;
            prev = tmp;
            tmp = tmp->next;
        }
        temp->next = tmp;
        if (prev != NULL) {
            prev->next = temp;
        } else {
            *h = temp;
        }
    }

    return 0;
}

void sort(struct node **h) {
    int i,j,a;

    struct node *previous_node;
    struct node *next_node;

    for(previous_node = *h; previous_node != NULL; previous_node = previous_node->next) {
        for(next_node = previous_node->next; next_node != NULL; next_node = next_node->next) {
            a = previous_node->data;
            previous_node->data = next_node->data;
            next_node->data = a;
        }
    }
}

/* parou de funfar e só larguei */
void print_list(struct node *head) {
    int column_counter = 1;
    struct node *current_node = head;
    while(current_node != NULL) {
        int number_length = floor(log10(abs(current_node->data))) + 1;
        usleep(5000);
        printf("number_length: %d\n", number_length);
        printf("current_node->data: %d\n", current_node->data);
        if (number_length == 1) {
          printf("\t\033%s||\033[0m    \033[1;35m%d\033[0m \033%s||\033[0m", current_node->data);
        } else if (number_length == 2) {
          printf("\t\033%s||\033[0m   \033[1;35m%d\033[0m \033%s||\033[0m", current_node->data);
        } else if (number_length == 3) {
          printf("\t\033%s||\033[0m  \033[1;35m%d\033[0m \033%s||\033[0m", current_node->data);
        } else if (number_length == 4) {
          printf("\t\033%s||\033[0m \033[1;35m%d\033[0m \033%s||\033[0m", current_node->data);
        }
        if (column_counter % 5 == 0) {
          printf("\n");
        }
        column_counter += 1;
        current_node = current_node->next;
    }
    printf("\n");
}

void print_list_with_sections(struct node *head, int section) {
    int column_counter = 0;
    int color_index = section % 5;
    struct node *current_node = head;

    while(current_node != NULL) {
        int number_length = floor(log10(abs(current_node->data))) + 1;
        usleep(5000);
        if (number_length == 1) {
          if (color_index == 0) {
            printf("\t\033[1;32m||\033[0m    \033[1;35m%d\033[0m \033[1;32m||\033[0m", current_node->data);
          } else if (color_index == 1) {
            printf("\t\033[1;33m||\033[0m    \033[1;35m%d\033[0m \033[1;33m||\033[0m", current_node->data);
          } else if (color_index == 2) {
            printf("\t\033[1;34m||\033[0m    \033[1;35m%d\033[0m \033[1;34m||\033[0m", current_node->data);
          } else if (color_index == 3) {
            printf("\t\033[1;36m||\033[0m    \033[1;35m%d\033[0m \033[1;36m||\033[0m", current_node->data);
          } else if (color_index == 4) {
            printf("\t\033[1;31m||\033[0m    \033[1;35m%d\033[0m \033[1;31m||\033[0m", current_node->data);
          }
        } else if (number_length == 2) {
          if (color_index == 0) {
            printf("\t\033[1;32m||\033[0m   \033[1;35m%d\033[0m \033[1;32m||\033[0m", current_node->data);
          } else if (color_index == 1) {
            printf("\t\033[1;33m||\033[0m   \033[1;35m%d\033[0m \033[1;33m||\033[0m", current_node->data);
          } else if (color_index == 2) {
            printf("\t\033[1;34m||\033[0m   \033[1;35m%d\033[0m \033[1;34m||\033[0m", current_node->data);
          } else if (color_index == 3) {
            printf("\t\033[1;36m||\033[0m   \033[1;35m%d\033[0m \033[1;36m||\033[0m", current_node->data);
          } else if (color_index == 4) {
            printf("\t\033[1;31m||\033[0m   \033[1;35m%d\033[0m \033[1;31m||\033[0m", current_node->data);
          }
        } else if (number_length == 3) {
          if (color_index == 0) {
            printf("\t\033[1;32m||\033[0m  \033[1;35m%d\033[0m \033[1;32m||\033[0m", current_node->data);
          } else if (color_index == 1) {
            printf("\t\033[1;33m||\033[0m  \033[1;35m%d\033[0m \033[1;33m||\033[0m", current_node->data);
          } else if (color_index == 2) {
            printf("\t\033[1;34m||\033[0m  \033[1;35m%d\033[0m \033[1;34m||\033[0m", current_node->data);
          } else if (color_index == 3) {
            printf("\t\033[1;36m||\033[0m  \033[1;35m%d\033[0m \033[1;36m||\033[0m", current_node->data);
          } else if (color_index == 4) {
            printf("\t\033[1;31m||\033[0m  \033[1;35m%d\033[0m \033[1;31m||\033[0m", current_node->data);
          }
        } else if (number_length == 4) {
          if (color_index == 0) {
            printf("\t\033[1;32m||\033[0m \033[1;35m%d\033[0m \033[1;32m||\033[0m", current_node->data);
          } else if (color_index == 1) {
            printf("\t\033[1;33m||\033[0m \033[1;35m%d\033[0m \033[1;33m||\033[0m", current_node->data);
          } else if (color_index == 2) {
            printf("\t\033[1;34m||\033[0m \033[1;35m%d\033[0m \033[1;34m||\033[0m", current_node->data);
          } else if (color_index == 3) {
            printf("\t\033[1;36m||\033[0m \033[1;35m%d\033[0m \033[1;36m||\033[0m", current_node->data);
          } else if (color_index == 4) {
            printf("\t\033[1;31m||\033[0m \033[1;35m%d\033[0m \033[1;31m||\033[0m", current_node->data);
          }
        }
        if (column_counter % 5 == 0) {
          printf("\n");
        }
        column_counter += 1;
        current_node = current_node->next;
    }
    printf("\n\n\n");
}
