/* This program aims to separate the values ​​of a json */

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

enum {
  JS_TYPE_KEY,
  JS_TYPE_VALUE,
  JS_TYPE_INT,
  JS_TYPE_MATRIX,
  JS_TYPE_STRING,
  JS_TYPE_NULL,
  JS_TYPE_ERROR
}JSTOK_TYPE;

typedef struct {
  int token_count;
  int type;
  const char *start;
  char *end;
  size_t lenght;
} JSTOK_PARSE;

typedef struct {
  int index_count;
  char **tokens;
}JSTOK_T;


<<<<<<< HEAD:include/libjson.h
int parser_simple_json(char **json, tree_data_json *object);
=======
JSTOK_T *new_jstok_t();

JSTOK_T *parser_json(char *json, JSTOK_PARSE *tok, JSTOK_T *tok_t);

char *string_hadller(char *js_ch, JSTOK_PARSE *tok, char *token_buffer, JSTOK_T *tok_t, int x);
>>>>>>> refatoracao_jsonlib:src/libjson.h

void init_array_of_tokens(char **tokens);

void insert_token_on_array(size_t token_lenght, char **tokens, char *token_buffer);

void array_push(char *string, char **array);

void destroy_array_of_tokens(char **array_of_tokens, int index);

void destroy_jstok_t(JSTOK_T *tok_t);

#endif
