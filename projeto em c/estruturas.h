#ifndef ESTRUTURAS
#define ESTRUTURAS
#define MAX_NOME 150
#define TAM_CPF 15
#define MIN_MATRICULA 999
#define MAX_MATRICULA 9999
#define NOME_CURSO 50
#define MAX_COD 9999
#define MIN_COD	1000
#define MAX_MENSALIDADE 3500
#define MIN_MENSALIDADE 100
#define MAX_CARGA_HORARIA 220
#define MIN_CARGA_HORARIA 10
#define TAM_SITUACAO 20
#define MAX_IDADE 80
#define MIN_IDADE 10


typedef struct Aluno
{
	char nomeAluno[MAX_NOME];
	char CPF[TAM_CPF];
	int idade;
	char sexo;
	int dataDia;
	int dataMes;
	int dataAno;
	int matricula;
}Aluno;
typedef struct Cursos
{
	char nomeCurso[MAX_NOME];
	int codCurso;
	int horarios;
	float mensalidade;
}Cursos;

typedef struct Matriculas
{
	int idAluno;
	int idCurso;
	char situacaoAluno;//C - cursando F - concluido
	char situacaoCurso; // R - regular - P pendente - F pago
	int mes,ano;
	
}Matriculas;
#endif
