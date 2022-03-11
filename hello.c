#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct hash_set_node {
  int *val;
  int len;
  struct hash_set_node* next;
} hash_set_node;

void haha(unsigned char *a, int len)
{
  printf("size of a: %ld, strlen of a: %ld\n",sizeof(a), strlen(a));
  for (int i = 0; i < len; i++)
  {
    printf("%X ", a[i]);
  }
}

int isBigEndian (void)
{
    union foo {
        size_t i;
        char cp[sizeof(size_t)];
    } u;

    u.i = 1;
    return *u.cp != 1;
}

int main(int argc, char **argv)
{
  hash_set_node *node;
  printf("before: sizeof: %ld\n", sizeof(hash_set_node));
  node = malloc(sizeof(hash_set_node));
  printf("after: size of val: %ld\n", sizeof(node->val));
  printf("after: size of len: %ld\n", sizeof(node->len));
  printf("after: size of next: %ld\n", sizeof(node->next));
  printf("after: sizeof: %ld\n", sizeof(hash_set_node));
  return 0;
}
