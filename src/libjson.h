/* Copyright (C) 2024  Samuel Henrique */

/* This program is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or */
/* (at your option) any later version. */

/* This program is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details. */

/* You should have received a copy of the GNU General Public License */
/* along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#ifndef JSON_H
#define JSON_H

#define SUCCESS 0
#define FAILURE 1

extern enum {
  JS_TYPE_KEY,
  JS_TYPE_VALUE,
  JS_TYPE_INT,
  JS_TYPE_MATRIX,
  JS_TYPE_STRING,
  JS_TYPE_NULL,
  JS_TYPE_ERROR
}JSTOK_TYPE;

/* typedef struct { */
/*   int capacity; */
/*   int token_count; */
/*   int type; */
/*   const char *start; */
/*   char *end; */
/*   size_t lenght; */
/* }TOK_OBJ_PARSE; */

typedef struct {
  int str_count;
  int type;
  int x;
  char **array;
}TOK_OBJ;

typedef struct {
  TOK_OBJ obj;
}TOK_OBJ_PARSE;

TOK_OBJ_PARSE *new_tok_obj();

TOK_OBJ_PARSE *alloc_string_array(TOK_OBJ_PARSE *tokens);

TOK_OBJ_PARSE *alloc_string(TOK_OBJ_PARSE *tokens, size_t lenght);

int parser_json(char *json, TOK_OBJ_PARSE *tokens);

TOK_OBJ_PARSE *resize_tok_obj(TOK_OBJ_PARSE *tokens, size_t diff);

char *string_hadller(char *json, TOK_OBJ_PARSE *tokens);

void destroy_strings(TOK_OBJ_PARSE *tokens);

void destroy_object(TOK_OBJ_PARSE *tokens);

#endif
