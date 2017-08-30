#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "Cores.h"
#include "bibliotecaPrototipos.h"
#include "estruturas.h"
#include "windows.h"
#include "manipulaDados.h"
#include "apresentaMensagem.h"
void relatorio2(void);
void relatorio3(void);
void relatorio6();
void relatorio5(void);
void relatorio1(void);
void opcaoPendente();
void opcaoPago();
void opcaoRegular();
int verificaBissexto(int ano,int mes,int dia);
int verificaData(int dia,int mes,int ano);
Matriculas *obtemCursosFinalizados(int *qtde, int escolheCurso, int escolheAno, char escolheSituacao);
Cursos *obtemDadosPorNome(int *qtde,char *nomeDesejado);
Aluno *obtemAlunosPeriodo(int *qtdeAlunos,int dataInicial,int dataFinal);
int transformaData(int dia,int mes,int ano);
int comparaMatriculas(const void *p1,const void *p2);

