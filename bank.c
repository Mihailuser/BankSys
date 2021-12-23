#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>  
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "fileio.h"

char *settime(struct tm *u)
{
  char s[40];
  char *tmp;
  for (int i = 0; i<40; i++) s[i] = 0;
  int length = strftime(s, 40, "%H:%M 		%d.%m.%Y", u);
  tmp = (char*)malloc(sizeof(s));
  strcpy(tmp, s);
  return(tmp);
}

int take_card();
int cr_card();
int change_money();

int main(int argc, char** argv) 
{
	//setlocale(LC_ALL,"Rus");
	system("chcp 1251 > nul");
	int num = 1;
	int user_id = 1;
	int comm = 0;
	printf("Нажмите любую клавишу для выдачи талона\n");
    while(1 == 1)
    {
		printf("Выберите услугу: забрать готовую - 1, заказать карту - 2, обменять валюту - 3\n");
  	scanf("%i", &comm);
  	printf("%i\n", comm);
		if(comm == 1)
		{
			take_card(num, user_id);
		}
		else if(comm == 2)
		{
			cr_card(num, user_id);
		}
		else if(comm == 3)
		{
			change_money(num, user_id);
		}
		++num;
		++user_id;
	}
	//system("prn 1.json"); не работает
	getchar();
  return 0;
}

int take_card(int num, int user_id)
{

			char *aphb[27] = {"А","Б","В","Г","Д","Е","Ж","З","И","К","Л","М","Н","О","П","Р","С","Т","У","Ф",
			"Х","Ч","Ц","Ш","Щ","Ю","Я"};
			srand ( time(NULL) );
	    char buff[100];
   		int letter = rand() % 27;
   		struct tm *u;
  		char *f;
  		const time_t timer = time(NULL);
  		u = localtime(&timer);
  		f = settime(u);
  		int len = 0;
  		for(int i = 0; i < user_id; ++i)
  		{
  			++len;
			}
    char *c = itoa(user_id, buff, 10);
		char *sp = strncat(c,".json",len+5);
  	create(sp);
    FILE *file = fopen(sp,"a");
		appendn(sp,"**********СБРБАНК*********");
  	fprintf(file,"*         %s%i                *\n",aphb[letter], num);
		appendn(sp,"*         Забрать готовую            *");
		appendn(sp,"*  Окна обслуживания        *");
		appendn(sp,"*         10, 11, 14-16     *");
		appendn(sp,"*                           *");
		appendn(sp,"*     Мы вам рады!          *");
		fprintf(file,"*%s  *\n",f);
		appendn(sp,"***************************");
		fclose(file);
		read(sp);
		return 0;
}
int cr_card(int num, int user_id)
{

			char *aphb[27] = {"А","Б","В","Г","Д","Е","Ж","З","И","К","Л","М","Н","О","П","Р","С","Т","У","Ф",
			"Х","Ч","Ц","Ш","Щ","Ю","Я"};
			srand ( time(NULL) );
	    char buff[100];
   		int letter = rand() % 27;
   		struct tm *u;
  		char *f;
  		const time_t timer = time(NULL);
  		u = localtime(&timer);
  		f = settime(u);
  		int len = 0;
  		for(int i = 0; i < user_id; ++i)
  		{
  			++len;
			}
    char *c = itoa(user_id, buff, 10);
		char *sp = strncat(c,".json",len+5);
  	create(sp);
    FILE *file = fopen(sp,"a");
		appendn(sp,"**********СБРБАНК*********");
  	fprintf(file,"*         %s%i                *\n",aphb[letter], num);
		appendn(sp,"*         Заказать карту            *");
		appendn(sp,"*  Окна обслуживания        *");
		appendn(sp,"*         12, 13, 1-3     *");
		appendn(sp,"*                           *");
		appendn(sp,"*     Мы вам рады!          *");
		fprintf(file,"*%s  *\n",f);
		appendn(sp,"***************************");
		fclose(file);
		read(sp);
		return 0;
}
int change_money(int num, int user_id)
{

			char *aphb[27] = {"А","Б","В","Г","Д","Е","Ж","З","И","К","Л","М","Н","О","П","Р","С","Т","У","Ф",
			"Х","Ч","Ц","Ш","Щ","Ю","Я"};
			srand ( time(NULL) );
	    char buff[100];
   		int letter = rand() % 27;
   		struct tm *u;
  		char *f;
  		const time_t timer = time(NULL);
  		u = localtime(&timer);
  		f = settime(u);
  		int len = 0;
  		for(int i = 0; i < user_id; ++i)
  		{
  			++len;
			}
    char *c = itoa(user_id, buff, 10);
		char *sp = strncat(c,".json",len+5);
  	create(sp);
    FILE *file = fopen(sp,"a");
		appendn(sp,"**********СБРБАНК*********");
  	fprintf(file,"*         %s%i                *\n",aphb[letter], num);
		appendn(sp,"*         Обменять валюту            *");
		appendn(sp,"*  Окна обслуживания        *");
		appendn(sp,"*         4, 5, 6-9     *");
		appendn(sp,"*                           *");
		appendn(sp,"*     Мы вам рады!          *");
		fprintf(file,"*%s  *\n",f);
		appendn(sp,"***************************");
		fclose(file);
		read(sp);
		return 0;
}
