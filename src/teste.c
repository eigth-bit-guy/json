#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include "..\\include\\libjson.h"

int main(void)
{
  int result;
  tree_data_json object;
  char *buffer;
  object.tokens.k_idx = 0;
  object.tokens.v_idx = 0;
  
  buffer = get_json_file("teste.json");
  if(buffer == NULL){
	fprintf(stderr, "Error: when get file json: error number: %d\nError message: %s\n", errno, strerror(errno));
	return 1;
  }
  
  result = parser_simple_json(&buffer, &object);
  if(result != 0){
	fprintf(stderr, "Error: error when analyse json: %s\n", strerror(errno));
  }else
	printf("Analyse success\n");

  printf("Lenght value: %d\nStart value: %d\nEnd value: %d\n",
		 object.json_lenght, object.start, object.end);

  printf("Tokens value:\n");
  for(int i = 0; i <= 7; i++) {
	printf(": %s \n", object.tokens.value[i]);
  }
  
  return 0;

}
