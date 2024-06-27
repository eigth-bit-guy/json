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

enum {
  JS_TYPE_KEY,
  JS_TYPE_VALUE,
  JS_TYPE_INT,
  JS_TYPE_MATRIX,
  JS_TYPE_STRING,
  JS_TYPE_NULL,
  JS_TYPE_ERROR
}jstok_type;

typedef struct jstok {
  int type;
  char *tokens[16];
}jstok_t;


int parser_json(char *json, jstok_t *tok);

int string_hadller(char *js_ch, jstok_t *tok);

int get_string_from_json(jstok_t *tok, char *json, size_t len, int i);

#endif
