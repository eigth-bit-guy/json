#include <stdio.h>
#include <string.h>

int main()
{
  char string_list[100][100];

  char *string_one = "Testando";
  char *string_two = "Teste";
  
  strcpy(string_list[0], string_one);
  strcpy(string_list[1], string_two);

  printf("List: %s\n", string_list[0]);
  printf("List: %s\n", string_list[1]);

  return 0;
}
