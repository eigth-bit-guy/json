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

#define LINE 8
#define COLUMNS 30

enum json_values{
  LIB_JSON_TYPE_KEY,
  LIB_JSON_TYPE_VALUE,
  LIB_JSON_TYPE_COLON,
  LIB_END_JSON
};

typedef struct{
  char key[LINE][COLUMNS],
	value[LINE][COLUMNS];
  int k_idx, v_idx;
}json_tokens;

typedef struct{
  size_t json_lenght;
  int type;
  json_tokens tokens;
  int start, end;
}tree_data_json;

tree_data_json new_json();

int analyse_json_object(char **json, tree_data_json *object);

int map_json_object(char **json, tree_data_json *object);

int parser_simple_json(char **json, tree_data_json *object);

int get_json_lenght_from_file(FILE *file);

char *get_json_file(char *file_path);

void verify_value_position(char *new_value, tree_data_json *object);

void free_json(tree_data_json *json);

#endif
