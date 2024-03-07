#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <assert.h>
#include <stdlib.h>

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

  result = parser_simple_json(json, object);
  if(result  != 0 ){
	fprintf(stderr, "Error: when parser json: %s\n", strerror(errno));
	return 1;
  }else
	printf("Parse success\n");

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


int parser_simple_json(char **json, tree_data_json *object)
{
  for(size_t i = 0; i < object->json_lenght; i++) {
	switch(**json){
	case '{': 
	  object->type = LIB_JSON_TYPE_KEY;
	  break;
	case ':':
	  object->type = LIB_JSON_TYPE_VALUE;
	  break;
	case '"':
	  ++*json;
	  const char* start = *json;
	  char* end = strchr(*json, '"');
	  if (end) {
		size_t len = end - start;
		char *new_value = malloc((len + 1) * sizeof(char));
		memcpy(new_value, start, len);
		new_value[len] = '\0';
		assert(len == strlen(new_value));
		*json = end + 1;
		verify_value_position(new_value, object);
	  }
	  break;
	case ',':
	  object->type = LIB_JSON_TYPE_KEY;
	  break;
	case '}':
	  printf("Json final\n");
	  break;
	default:
	  break;
	}
	++*json;
  }
  return 0;
}

void verify_value_position(char *new_value, tree_data_json *object)
{
  if(object->type == LIB_JSON_TYPE_KEY){
	object->type = LIB_JSON_TYPE_VALUE;
    strcpy(object->tokens.key[object->tokens.k_idx], new_value);
	object->tokens.k_idx++;
  }
  else if(object->type == LIB_JSON_TYPE_VALUE){
	printf("new value: %s, address: %p\n", new_value, new_value);
	object->type = LIB_JSON_TYPE_KEY;
    strcpy(object->tokens.value[object->tokens.v_idx], new_value);
	object->tokens.v_idx++;
  }
}

int get_json_lenght_from_file(FILE *file)
{
  fseek(file, 0L, SEEK_END);
  int len =  ftell(file);
  fseek(file, 0L, SEEK_SET);
  rewind(file);
  return len;
}

char *get_json_file(char *file_path)
{
  FILE *file;
  if((file = fopen(file_path, "r")) == 0){
	fprintf(stderr, "Error: when open json file: error number: %d\nError message: %s\n", errno, strerror(errno));
  }
  int len = get_json_lenght_from_file(file);
  char *buffer = malloc(sizeof(char) * len);
  if((len = fread(buffer, sizeof(char), len, file)) == 0){
	fprintf(stderr, "Error: when read file: error number: %d\nError message: %s\n", errno, strerror(errno));
  }
  buffer[len] = '\0';
  fclose(file);
  return buffer;
}
