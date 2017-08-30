#include <stdio.h>
#include "Menu.h"
#include "cores.h"
typedef struct Matriculas
{
	int idAluno;
	int idCurso;
	int situacaoAluno;//0 - cursando 1 - concluido
	int sisuacaoCurso; // 0 - regular - 1 pendente - 2 pago
	int mes,ano;
}Matriculas;
void cadastraMatricula()
{
	desenhaMoldura(10,10,20,70,AZUL,BRANCO);
    gotoxy(11,11);
    //idAluno=leInt("Informe o id do aluno = ");
}
