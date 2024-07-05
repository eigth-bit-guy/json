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


  /* char *json = "{\"driver\":\"4\",\"prd\":\"ULTRA LAVAVEL PR FC - NOVO\",\"wgh\":\"0\",\"unt\":\"1.0000 1.0000\",\"clr\":\"218P-1 RUN 6\",\"bas\":\"BASE A\",\"can\":\"810\",\"frm\":\"1,0.0059,7,0.0345,9,0.0310 810\"}"; */
  /* char *json = "{\"msg\":\"testando\",\"msg\":\"teste\",\"msg\":\"samuel\",\"msg\":\"token\"}"; */


#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "libjson.h"

int main(void)
{
  TOK_OBJ_PARSE *tokens = new_tok_obj();
  if(tokens == NULL) {
	fprintf(stderr, "error: initialize JSTOK_T\n");
	exit(1);
  }

  alloc_string_array(tokens);
  if(tokens->obj.array == NULL) {
    fprintf(stderr, "error: when allocate memory from json array\n");
    exit(1);
  }
  
  char *json = "{\"driver\":\"4\",\"prd\":\"FOSCO COMPLETO PR - NOVO\",\"wgh\":\"0\",\"unt\":\"1.0000 1.0000\",\"clr\":\"050N-5\",\"bas\":\"BASE C\",\"can\":\"150\",\"fmr\":\"11,0.5583334,12,1.22092593,3,5.101852,4,3.48944449 150\"}";
  
  int error = parser_json(json, tokens);
  if(error  == 1) {
    fprintf(stderr, "error: parse json\n");
    exit(1);
  }

  for(int i = 0; i < 8; i++) {
    printf("tokens: %s\n", tokens->obj.array[i]);
  }
  
  return 0;
}
