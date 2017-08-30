#include <stdio.h>
#include "cores.h"
#include "time.h"
//Objetivo: Apresentar uma mensagem de erro 
//Parametros: referencia a string de mensagem, e a identificacao da funcao
//Retorno: nenhum
void apresentaMsgErro( char *msg, char * idFuncao)
{
  desenhaMoldura(22,5,24,75,AZUL,BRANCO);
  gotoxy(6,23);
  fprintf(stdout,"(%s) %s",idFuncao,msg);
  getch();
  limpaJanela(22,5,24,75,AZUL);
  //desenhaMoldura(10,10,20,70,AZUL,BRANCO);

}
//Objetivo: Apresentar uma mensagem de apresentacao
//Parametros: nenhum
//Retorno: nenhum
void apresentaMsgApresentacao()
{
	int *dia,*mes,*ano,*hora,*minuto;
	obtemDataHora(&dia,&mes,&ano,&hora,&minuto);
  desenhaMoldura(6,5,16,75,AZUL,BRANCO);
  gotoxy(8,9);
  fprintf(stdout,"BEM VINDO AO PROJETO 1");
  gotoxy(8,10);
  fprintf(stdout,"DATA = %i / %i / %i",dia,mes,ano,hora,minuto);
  gotoxy(8,11);
  fprintf(stdout,"HORA = %i : %i",hora,minuto);
  gotoxy(17,9);
  getch();
  limpaJanela(14,5,20,75,BRANCO);
  
}
//Objetivo: Obter a hora e a data Atual
//Parametros: referencia a hora,minutos,dia,mes,ano.
//Retorno: horarios resgatados do sistema
void obtemDataHora(int *dia,int *mes, int *ano,int *hora,int *minuto)
{
   time_t t;
   struct tm *dataAtual;
   t = time(NULL);
   dataAtual = localtime(&t);
   *dia    =dataAtual->tm_mday;
   *mes    =dataAtual->tm_mon+1;
   *ano    =1900+dataAtual->tm_year;
   *hora   =dataAtual->tm_hour;
   *minuto =dataAtual->tm_min;
}
