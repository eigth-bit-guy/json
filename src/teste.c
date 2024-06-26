#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include "..\\include\\libjson.h"

int main(void)
{
  jstok_t tok;

  char *json = "{\"driver\":\"4\",\"prd\":\"ULTRA LAVAVEL PR FC - NOVO\",\"wgh\":\"0\",\"unt\":\"1.0000 1.0000\",\"clr\":\"218P-1 RUN 6\",\"bas\":\"BASE A\",\"can\":\"810\",\"frm\":\"1,0.0059,7,0.0345,9,0.0310 810\"}";

  int result;
  if((result = parser_json(json, & tok)) != 0){
	printf("Deu ruim meu bom...\n");
	return 1;
  }
  
  return 0;

}
