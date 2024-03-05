#include <stdio.h>
#include <string.h>

int main(void)
{
  char value[] = "Hello World\n";
  char *pointer = &value;

  printf("pointer: %c\n", *pointer);
  ++pointer;
  printf("new value: %c\n", *pointer);
  ++pointer;
  printf("new value: %c\n", *pointer);
  ++pointer;
  printf("new value: %c\n", *pointer);
  ++pointer;
  printf("new valeu: %c\n", *pointer);
  ++pointer;
  printf("new valeu: %c\n", *pointer);
  ++pointer;
  printf("new valeu: %c\n", *pointer);
  ++pointer;
  printf("new valeu: %c\n", *pointer);
  ++pointer;
  printf("new valeu: %c\n", *pointer);
  ++pointer;
  printf("new valeu: %c\n", *pointer);
  ++pointer;
  printf("new valeu: %c\n", *pointer);
  ++pointer;


  return 0;
}
