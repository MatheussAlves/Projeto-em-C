#include <stdio.h>
#include "estruturas.h"

int apresentaAlunosV(void);
int apresentaCursosV(void);
Aluno * obtemDadosArquivoAluno(int *qtde);
int comparaNomeAlunos(const void * p1, const void *p2);
char respostaSN(char *perg);
FILE * abreArquivo(char *nomeArq,char *modo);
int obtemMatriculaAluno(int matricula);
int leDadosAlunoPesquisado(int nroAluno, Aluno *dadosAlunos);
int obtemCodigoCurso(int codigo);
char leValidaCaracter(char *titulo,char *opcoes,int linha,int coluna);
void alteraCursos(void);
int leDadosCurso(int nroCurso, Cursos *curso);
char * excluiRegArq(char *nomeArq, int tamReg, int regExcluir,int *existeErro);
void excluiCursos(void);
int apresentaMatriculasV(void);
void obtemData(int *mes, int *ano);
int geraCodigoAleatorio(void);
void pesquisaMatriculas();
int leMatriculaPesquisada(int seq, Matriculas *matriculas);
void excluiMatriculas();
void alteraMatriculas(void);
Cursos * obtemDadosArquivoCursos(int *qtde);
Matriculas * obtemDadosArquivoMatriculas(int *qtde);
void strToUpper(char * str);
char * strIstr(char *string1, char *string2);
int obtemCadastroMatricula(int cadastro);
void ordenaAlunos(int qtde, Aluno *alunos);
int comparaNomeCursos(const void * p1, const void *p2);
int comparaNomesMatricula(const void * p1, const void *p2);
void recuperaDescricao(char **nomesAlunos,char **nomesCurso);
int obtemNomeMatricula(char *texto);
Matriculas *obtemDadosSituacao(int *qtde, char opcao);
int obtemAlunoMatriculado(int matricula);
