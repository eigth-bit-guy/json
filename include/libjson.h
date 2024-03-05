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

enum json_values{
  LIB_JSON_TYPE_STRING,
  LIB_JSON_TYPE_CHAR,
  LIB_JSON_TYPE_INT,
  LIB_JSON_TYPE_BOOL,
  LIB_JSON_TYPE_DOUBLE,
  LIB_JSON_TYPE_KEY
};

typedef struct{
  size_t json_lenght;
  int type;
  char *string;
  char ch;
  int num;
  int bool;
  float flt;
  int start;
  int end;
}tree_data_json;

int analyse_json_object(char **json, tree_data_json *object);

int map_json_object(char **json, tree_data_json *object);

int parser_simple_json(char **json, tree_data_json *object);

#endif
