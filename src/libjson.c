#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#include "..\\include\\libjson.h"

//Rewrite json -> libjson
//TODO : whitespace
//TODO: allocate memory from inputed json

int analyse_json_object(char **json, tree_data_json *object)
{
  int result;

  result = map_json_object(json, object);
  if(result != 0){
	fprintf(stderr, "Error: when map json: %s\n", strerror(errno));
	return 1;
  }else
	printf("Map success\n");

  result = loop_parser_json(json, object);
  if(result  != 0 ){
	fprintf(stderr, "Error: when parser json: %s\n", strerror(errno));
	return 1;
  }else
	printf("Parse success\n");

  return 0;
}

int whitspace_handler()
{

  return 0;
}
  

int map_json_object(char **json, tree_data_json *object)
{
  char *start_key,
	*end_key;
  int result,
	counter_caracters = 0,
	start,
	end;
  
  size_t lenght;
  lenght = strlen(*json);
  object->json_lenght = lenght;

  start_key = strchr(*json, '{');
  object->start = (int)(start_key - *json + 1);
  
  end_key =  strchr(*json, '}');
  object->end = (int)(end_key - *json + 1);
  
  return 0;
}

int loop_parser_json(char **json, tree_data_json *object)
{
  int flag = 1;
  int ret;
  while(*json != '}'){
	ret = parser_simple_json(json, object);
  }

  return 0;
}

int parser_simple_json(char **json, tree_data_json *object)
{
  switch(**json){
  case '{':
	++*json;
	break;
  case ':':
	break;
  case '"':
	printf("String\n");
	break;
  case '}':
	return 0;
	break;
  default:
	++*json;
	break;
  }
  
  return 1;
}
