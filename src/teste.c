#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "..\\include\\libjson.h"

int main(int argc, char *argv[])
{
  int result;
  tree_data_json object;

  if(argc < 1){
	printf("Nenhum paramentro foi passado\n");
	return 1;
  }

  result = analyse_json_object(&argv[1], &object);
  if(result != 0){
	fprintf(stderr, "Error: error when analyse json: %s\n", strerror(errno));
  }else
	printf("Analyse success\n");

  printf("Lenght value: %d\nStart value: %d\nEnd value: %d\n", object.json_lenght, object.start, object.end);
  return 0;
}
