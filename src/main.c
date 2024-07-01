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


#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include "libjson.h"

int main(void)
{
  JSTOK_PARSE tok_parse_obj;
  JSTOK_T tok_t;

  /* char *json = "{\"driver\":\"4\",\"prd\":\"ULTRA LAVAVEL PR FC - NOVO\",\"wgh\":\"0\",\"unt\":\"1.0000 1.0000\",\"clr\":\"218P-1 RUN 6\",\"bas\":\"BASE A\",\"can\":\"810\",\"frm\":\"1,0.0059,7,0.0345,9,0.0310 810\"}"; */

  char *json = "{\"msg\":\"testando\",\"msg\":\"teste\",\"msg\":\"samuel\"}";

  int result;
  if((result = parser_json(json, &tok_parse_obj, &tok_t)) != 0){
	printf("Deu ruim meu bom...\n");
	return 1;
  }
  
  return 0;

}
