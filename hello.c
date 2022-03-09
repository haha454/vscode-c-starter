#include <stdio.h>

void haha(void) {
  printf("haha!\n");
}
int main(int argc, char **argv)
{
   printf("Hello, World!\n");
   while (argc--) {
     printf("%s\n", argv[argc]);
   }
   haha();
   return 0;
}
