#include <stdio.h>
#include <stdlib.h>

struct foo1 {
    char *p;			// 8 bytes
    char c;			// 1 byte
} __attribute__((packed));
//9

struct foo2 {
    short s;			// 2 bytes
    char c;			// 1 byte
}__attribute__((packed));
//3

struct foo3 {
  struct foo3inner {
      char *p;		// 8 bytes
      short s;		// 2 bytes
  } inner;
    char c;			// 1 byte
};
//11
//
struct foo4 {
    char *p1;		// 8 bytes
    char *p2;		// 8 bytes
    char c1;		// 1 byte
    char c2;		// 1 byte
};

int main(int argc, char** argv)
{
    printf("normal (9): %lu\n",sizeof(struct foo1));
    printf("normal (3): %lu\n",sizeof(struct foo2));
    printf("normal (10): %lu\n",sizeof(struct foo3));
    printf("normal (18): %lu\n",sizeof(struct foo4));
   return 0;
}
