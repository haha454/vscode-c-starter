#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define hashsize(n) ((unsigned long long)(1 << n))
#define hashmask(n) (hashsize(n) - 1)
#define n 20
#define N hashsize(n)


typedef struct hash_set_node
{
  int *val;
  int len;
  struct hash_set_node *next;
} hash_set_node;

typedef struct hash_set
{
  hash_set_node *nodes[N];
} hash_set;

  static hash_set hs={{NULL}};

unsigned long hash_code(int *val, int len)
{
  unsigned long result = 0;
  for (int i = 0; i < len; i++)
  {
    result += val[i];
    result += result << 10;
    result ^= result >> 6;
  }

  result += result << 3;
  result ^= result >> 11;
  result += result << 15;

  return result & hashmask(n);
}

int equal_node(int len_a, int val_a[], int len_b, int val_b[]) {
  if (len_a != len_b) {
    return 0;
  }

  for (int i = 0; i < len_a; i++) {
    if (val_a[i] != val_b[i]) {
      return 0;
    }
  }

  return 1;
}
int insert_to_hs(hash_set *hs, int *val, int len)
{
  unsigned long hc = hash_code(val, len);
  hash_set_node* cur = hs->nodes[hc];
  while (cur) {
    if (equal_node(cur->len, cur->val, len ,val)) {
      return 0;
    }
    cur = cur->next;
  }

  hash_set_node *node = malloc(sizeof(hash_set_node));
  node->len = len;
  node->val = malloc(sizeof(int) * len);
  memcpy(node->val, val, sizeof(int) * len);
  node->next = hs->nodes[hc];
  hs->nodes[hc] = node;

  return 1;
}

void go(int* val, int len) {
  int result = insert_to_hs(&hs, val, len);
  printf("inserting...");
  for (int i = 0; i < len; i++) {
    printf("%d ", val[i]);
  }

  printf("\n");
  printf("hash code: %ld\n", hash_code(val, len));
  printf("result: %d\n", result);
}

int main(int argc, char **argv)
{
  int val_a[] = {1,2,3};
  int len_a = 3;
  go(val_a, len_a);
  go(val_a, len_a);
  int val_b[] = {2,3,4};
  int len_b = 3;
  go(val_b, len_b);
  int val_c[] = {2,3,5};
  int len_c = 3;
  go(val_c, len_c);
  int val_d[] = {2,3,6};
  int len_d = 3;
  go(val_d, len_d);
}
