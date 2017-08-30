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
#include "relatorios.h"
#define TAM_TEXTO 60
/*(R2) - Relacionar todos os alunos de um curso específico fornecido pelo usuário. O usuário
poderá ainda informar se deseja obter este relatório somente para os alunos que estão
cursando ou os que já o concluíram ou ambas as situações. Este relatório deverá mostrar o
CPF, nome, situação do aluno no curso por extenso, além do próprio código do curso
consultado.
*/

//Objetivos: Apresentar o relatorio 2 ( apresntar alunos que estao cursando ou que foram concluidos ou ambos)
//Parametros:
//Retorno:
void relatorio2(void)
{
	Aluno *alunos;
	Cursos *curso;
	static char cpfFormatado[15];
	Matriculas *matricula;
	char nomeDesejado[TAM_TEXTO];
	char opcaoDesejada;
	int qtdeAlunos=0,qtdeCursos=0,qtdeMatriculas=0,cont=0,i,linha;
	int cont2,cont3;
	int codCurso;
	int seq;
	
	if((alunos=obtemDadosArquivoAluno(&qtdeAlunos))!=NULL && (curso=obtemDadosArquivoCursos(&qtdeCursos))!=NULL && (matricula=obtemDadosArquivoMatriculas(&qtdeMatriculas))!=NULL )
	{
		desenhaMoldura(1,1,20,80,AZUL,BRANCO);
		gotoxy(2,2);
		qsort(alunos,qtdeAlunos,sizeof(Aluno),comparaNomeAlunos);
		//leValidaTexto("Informe o nome completo do curso = ",nomeDesejado,TAM_TEXTO,11,11);
		//strToUpper(nomeDesejado);
		//limpaJanela(2,2,19,79,AZUL);
		fprintf(stdout,"SELECIONE O CURSO \n");
		codCurso=apresentaCursosV();
		seq = obtemCodigoCurso(codCurso);
		if(seq!=0)
		{
		
			cont=0;
			linha =3;
			for(i=0;i<qtdeCursos;i++)
			{
				if(codCurso==curso[i].codCurso)
				{
				
					desenhaMoldura(1,1,20,80,AZUL,BRANCO);
					//fprintf(stdout,"Mostranto resultados para %s ",nomeDesejado);
					gotoxy(3,2);
					fprintf(stdout,"Curso escolhido (%s) ",curso[i].nomeCurso);
					opcaoDesejada=leValidaCaracter("A - CURSANDO B - CONCLUIDO OU C - AMBOS ","ABC",3,2);
					system("cls");
					if(linha >= 18)
					{
						gotoxy(2,linha);
						fprintf(stdout,"Pressione alguma tecla para continuar \n");
						getch();
						limpaJanela(3,2,19,79,AZUL);
						linha =3;
					}
					switch(opcaoDesejada)
					{
						case 'A':
						
						desenhaMoldura(2,2,29,79,AZUL,BRANCO);
						
						gotoxy(3,1);
						fprintf(stdout,"%-15.15s-%-21.21s -%-15.15s-%-14.14s ","CPF","NOME ALUNO","SITUACAO","CODIGO CURSO");
						for(cont2=0;cont2<qtdeMatriculas;cont2++){
							if(matricula[cont2].situacaoAluno=='C')
							{
								for(cont3=0;cont3<qtdeAlunos;cont3++){
									
									if(matricula[cont2].idAluno==alunos[cont3].matricula && matricula[cont2].idCurso==curso[i].codCurso)
									{
										sprintf(cpfFormatado,"%3.3s.%3.3s.%3.3s-%2.2s",
       									alunos[cont3].CPF,alunos[cont3].CPF+3,alunos[cont3].CPF+6,alunos[cont3].CPF+9);
										strcpy(alunos[cont3].CPF,cpfFormatado);
								   	
										gotoxy(3,linha);
										linha++;
										fprintf(stdout,"%-15.15s-%-21.21s %-15s-%-14i ",alunos[cont3].CPF,alunos[cont3].nomeAluno,
										"CURSANDO",curso[i].codCurso);
										cont++;
									}
								}
							}
						}
						break;
						case 'B':
						desenhaMoldura(2,2,20,79,AZUL,BRANCO);
						
						gotoxy(3,1);
						fprintf(stdout,"%-15.15s-%-21.21s -%-15.15s-%-14.14s ","CPF","NOME ALUNO","SITUACAO","CODIGO CURSO");
						for(cont2=0;cont2<qtdeMatriculas;cont2++){
							if(matricula[cont2].situacaoAluno=='F')
							{
								for(cont3=0;cont3<qtdeAlunos;cont3++){
								
									if(matricula[cont2].idAluno==alunos[cont3].matricula && matricula[cont2].idCurso==curso[i].codCurso)
									{
										sprintf(cpfFormatado,"%3.3s.%3.3s.%3.3s-%2.2s",
       									alunos[cont3].CPF,alunos[cont3].CPF+3,alunos[cont3].CPF+6,alunos[cont3].CPF+9);
										strcpy(alunos[cont3].CPF,cpfFormatado);
										gotoxy(3,linha);
										linha++;
										fprintf(stdout,"%-15.15s-%-21.21s %-15s-%-14i ",alunos[cont3].CPF,alunos[cont3].nomeAluno,
										"CONCLUIDO",curso[i].codCurso);
										cont++;
								 	}
								 	
								}
							}
						}
						break;
				    	case 'C':
				    	
				    	desenhaMoldura(2,2,20,79,AZUL,BRANCO);
				    
				    	gotoxy(3,1);
				    	fprintf(stdout,"%-15.15s-%-21.21s -%-15.15s-%-14.14s ","CPF","NOME ALUNO","SITUACAO","CODIGO CURSO");
				    	for(cont2=0;cont2<qtdeMatriculas;cont2++)
						{
								for(cont3=0;cont3<qtdeAlunos;cont3++){
									
									if(matricula[cont2].idAluno==alunos[cont3].matricula && matricula[cont2].idCurso==curso[i].codCurso)
									{
										if(matricula[cont2].situacaoAluno=='C')
										{
											sprintf(cpfFormatado,"%3.3s.%3.3s.%3.3s-%2.2s",
       										alunos[cont3].CPF,alunos[cont3].CPF+3,alunos[cont3].CPF+6,alunos[cont3].CPF+9);
											strcpy(alunos[cont3].CPF,cpfFormatado);											
											gotoxy(3,linha);
											linha++;
											fprintf(stdout,"%-15.15s-%-21.21s %-15s-%-14i ",alunos[cont3].CPF,alunos[cont3].nomeAluno,
											"CURSANDO",curso[i].codCurso);
											cont++;
										}else
										{
											sprintf(cpfFormatado,"%3.3s.%3.3s.%3.3s-%2.2s",
       										alunos[cont3].CPF,alunos[cont3].CPF+3,alunos[cont3].CPF+6,alunos[cont3].CPF+9);
											strcpy(alunos[cont3].CPF,cpfFormatado);											
											gotoxy(3,linha);
											linha++;
											fprintf(stdout,"%-15.15s-%-21.21s %-15s-%-14i ",alunos[cont3].CPF,alunos[cont3].nomeAluno,
											"CONCLUIDO",curso[i].codCurso);
											cont++;
										}
								 	}
								}
								
						}
	
					
						break;		
					}
				}
			}
		}
		if(cont==0)
		{
			gotoxy(5,5);
			fprintf(stdout,"Nao foi encontrado nenhum curso \n");
			getch();
			return;
		}
		free(alunos);
		free(curso);
		free(matricula);
	}
	else
	{
		desenhaMoldura(10,10,14,70,AZUL,BRANCO);
		gotoxy(20,12);
		fprintf(stdout,"Nao foi possivel carregar os dados \n");	
		getch();
	}
	getch();
	system("cls");
}
// Objetivo: comparar o nome de um curso com uma palavra informada pelo usuario
// Parâmetros: nenhum
// Retorno: nenhum
void relatorio3(void)
{
FILE *arqBin;
int cont=0,qtdeCursos=0,i,linha;
Cursos *curso;
char pesquisaCurso[NOME_CURSO];

	desenhaMoldura(10,10,14,70,AZUL,BRANCO);
	gotoxy(11,11);

	leValidaTexto("Trecho que deseja procurar - ",pesquisaCurso,NOME_CURSO,11,12);
	//strToUpper(pesquisaCurso);
	limpaJanela(10,10,14,70,AZUL);
	gotoxy(2,2);
	//fprintf(stdout,"Cursos com o nome = %s \n",pesquisaCurso);
	if((curso = obtemDadosPorNome(&qtdeCursos,pesquisaCurso))!=NULL)
	{
	
		cont=0;
		linha =3;
    	fprintf(stdout,"%-10.10s-%-30.30s-%-13.13s-%-13.13s\n","CODIGO","NOME DO CURSO","CARGA HORARIA","MENSALIDADE");
    	qsort(curso,qtdeCursos,sizeof(Cursos),comparaNomeCursos);
		for(i=0;i<qtdeCursos;i++){
			
	
				
				/*if(linha>=18)
				{
					gotoxy(2,linha);
					fprintf(stdout,"Tecle para avancar \n");
					getch();
					limpaJanela(3,2,19,79,AZUL);
					linha=3;
				}
				*/
			desenhaMoldura(1,1,linha+1,72,AZUL,BRANCO);
			gotoxy(2,linha);
			linha++;				
			fprintf(stdout,"%-10i-%-30.30s-%-13i-%-13.2f \n",curso[i].codCurso,curso[i].nomeCurso,curso[i].horarios,curso[i].mensalidade);
			cont++;
		}
		if(cont==0)
		{
			gotoxy(5,5);
			fprintf(stdout,"Nao foi encontrado cursos  \n");
		}
		
		free(curso);
	}else
	{
		desenhaMoldura(10,10,14,70,AZUL,BRANCO);
		gotoxy(20,12);
		fprintf(stdout,"Nao foi possivel carregar dados do arquivo ");
	
	}
	getch();
}
//Objetivo: Obtem os dados necessarios, a partir de parte do nome desejado
//Parametros: referencia a quantidade e ao nome desejado.
//Retorno: endereço da estrutura com os dados necessarios.
Cursos *obtemDadosPorNome(int *qtde,char *nomeDesejado)
{
	FILE *arqCurso=NULL;
	Cursos *curso=NULL,*cursoAux=NULL;
	if((arqCurso=abreArquivo("dadosCursos.txt","rb"))!=NULL)
	{
		while(!feof(arqCurso))
		{
			curso=(Cursos*)realloc(cursoAux,sizeof(Cursos)*((*qtde)+1));
			if(curso!=NULL)
			{
				cursoAux=curso;
				if(fread(&cursoAux[*qtde],sizeof(Cursos),1,arqCurso)==1)
				{
					if(strIstr(cursoAux[*qtde].nomeCurso,nomeDesejado)!=NULL)
					{
						(*qtde)++;	
					}	
				}
				
			}else
			{
				printf("Erro de alocacao de memoria ");
			}
		}
		fclose(arqCurso);
	}
	return cursoAux;
	
}
// Objetivo: pesquisar anos que concluiram o curso em determinadoa ano 
// Parâmetros: nenhum
// Retorno: nenhum
void relatorio6()
{
	int escolheCurso,escolheAno;
	Matriculas *matricula;
	/*----------------------------PARA DADOS DOS NOMES-----------------------------------------------*/
	Aluno alunos;
	Cursos curso;
	FILE *arqAlunos;
	FILE *arqCursos;
    FILE *arqBin;
    char **nomesAlunos=NULL;
	char **nomesAlunosAux;
	char **nomesCursoAux;
	char **nomesCurso=NULL;
	char **sitCurso=NULL;
	char **sitAluno=NULL;
	char **sitCursoAux;
	char **sitAlunoAux;
	/*-----------------------------PARA DADOS DOS NOMES----------------------------------------------*/
    int cont=0,aux, nroAluno=0;	
    int cont2=0;  //nomeAluno
    int cont3=0; //nomeCurso
    int cont4=0; //sitCurso
    int cont1=0; //sit aluno
	int linha,qtdeMatriculas=0;
	escolheCurso=apresentaCursosV();

	desenhaMoldura(10,10,20,90,AZUL,BRANCO);
	escolheAno=leInt("INFORME O ANO QUE CONCLUIU O CURSO- ",2016,2050,11,11);
	system("cls");
	if((matricula = obtemCursosFinalizados(&qtdeMatriculas,escolheCurso,escolheAno,'F'))!=NULL)
	{
		
		linha=11;
		//qsort(matricula,qtdeMatriculas,sizeof(Matriculas),comparaNomesMatricula);
		
		for(aux=0;aux<qtdeMatriculas;aux++)
		{
			nomesAlunosAux=(char**) realloc(nomesAlunos,sizeof(char*)*(cont2+1));
			if(nomesAlunosAux!=NULL)
			{
				nomesAlunos=nomesAlunosAux;
				nomesAlunos[cont2]=(char*)malloc(sizeof(char)*(MAX_NOME+1));
				if(nomesAlunos[cont2]!=NULL)
				{
					if((arqAlunos = abreArquivo("dadosAlunos.txt","rb"))!=NULL)          
					{
																								
						while(!feof(arqAlunos))
						{
							if(fread(&alunos,sizeof(Aluno),1,arqAlunos)==1)
							{
								//printf("%i %i ",matricula.idAluno,alunos.matricula);
								
								if(matricula[aux].idAluno==alunos.matricula)
								{
									strcpy(nomesAlunos[cont2],alunos.nomeAluno);
									
									cont2++;
								}
							
								//printf("%s ",nomesAlunos[contador]);
							}
						}
						fclose(arqAlunos);
					}
					
				}
			}
			nomesCursoAux=(char**) realloc(nomesCurso,sizeof(char*)*(cont3+1));
			if(nomesCursoAux!=NULL)
			{
				nomesCurso=nomesCursoAux;
				nomesCurso[cont3]=(char*)malloc(sizeof(char)*(MAX_NOME+1));
				if(nomesCurso[cont3]!=NULL)
				{
					if((arqCursos = abreArquivo("dadosCursos.txt","rb"))!=NULL)
					{
						while(!feof(arqCursos))
						{
							if(fread(&curso,sizeof(Cursos),1,arqCursos)==1)
							{
								if(matricula[aux].idCurso==curso.codCurso)
								{
									strcpy(nomesCurso[cont3],curso.nomeCurso);
									cont3++;
								}
							}
						}
						fclose(arqCursos);
					}
				}
			}
			sitCursoAux=(char**) realloc(sitCurso,sizeof(char*)*(cont4+1));
			if(sitCursoAux!=NULL)
			{
				sitCurso=sitCursoAux;
				sitCurso[cont4]=(char*)malloc(sizeof(char)*(TAM_SITUACAO+1));
				if(sitCurso[cont4]!=NULL)
				{
					
						
			
					if(matricula[aux].situacaoCurso=='R')
					{
						strcpy(sitCurso[cont4],"REGULAR");
					}else
					{
						if(matricula[aux].situacaoCurso=='P')
						{
							strcpy(sitCurso[cont4],"PENDENTE");
						}else{
							strcpy(sitCurso[cont4],"PAGO");
						}
					}
					cont4++;
							
						
				
					
				}
			}
			sitAlunoAux=(char**) realloc(sitAluno,sizeof(char*)*(cont1+1));
			if(sitAlunoAux!=NULL)
			{
				sitAluno=sitAlunoAux;
				sitAluno[cont1]=(char*)malloc(sizeof(char)*(TAM_SITUACAO+1));
				if(sitAluno[cont1]!=NULL)
				{
						
					if(matricula[aux].situacaoAluno=='F')
					{
						strcpy(sitAluno[cont1],"CONCLUIDO");
					}else
					{
						strcpy(sitAluno[cont1],"CURSANDO");
					}
					cont1++;
					
				}
			}
			//qsort(matricula,qtdeMatriculas,sizeof(Matriculas),comparaMatriculas);
			desenhaMoldura(10,10,linha+1,120,AZUL,BRANCO);                                                            
		   	gotoxy(11,9);
			fprintf(stdout,"%-9.9s %-25.25s%-18.18s %-10.10s %-15.15s %-15.15s %5.5s","MATRICULA","NOME ALUNO ","NOME CURSO","ID CURSO","SITUACAO ALUNO ","SITUACAO CURSO","DATA");
			gotoxy(11,linha);
			linha++;	
    	   	fprintf(stdout,"%-9i %-25.25s %-18.18s %-10i %-15.15s %-15.15s  %i/%i    \n",matricula[aux].idAluno,nomesAlunos[aux],nomesCurso[aux],matricula[aux].idCurso,sitAluno[aux],sitCurso[aux],matricula[aux].mes,matricula[aux].ano);
			cont++;
					
		}
		if(cont==0)
		{	
			desenhaMoldura(10,10,20,90,AZUL,BRANCO);
			gotoxy(11,11);
			fprintf(stdout,"Nao foi encontrado resultados  \n");	
		}	
		free(matricula);
	
		
	
	}else
	{
		desenhaMoldura(10,10,14,70,AZUL,BRANCO);
		gotoxy(20,12);
		fprintf(stdout,"Nao foi possivel carregar dados do arquivo ");
	}
	free(sitAluno);
	free(sitCurso);
	free(nomesAlunos);
	free(nomesCurso);
	
	
	getch();
	system("cls");
}
//Objetivo: Verificar o curso e o ano desejado pelo usuario, para resgatar os alunos finalizados.
//Parametros: referencia a quantidade de matriculas, id do curso, e ano desejado
//Retorno: endereço da estrutura com os dados necessarios.
Matriculas *obtemCursosFinalizados(int *qtde, int escolheCurso, int escolheAno, char escolheSituacao)
{
	FILE *arq=NULL;
	Matriculas *matricula=NULL,*matriculaAux=NULL;
	if((arq=abreArquivo("dadosMatriculas.txt","rb"))!=NULL)
	{
		while(!feof(arq))
		{
			matricula=(Matriculas*)realloc(matriculaAux,sizeof(Matriculas)*((*qtde)+1));
			if(matricula!=NULL)
			{
				matriculaAux=matricula;
				if(fread(&matriculaAux[*qtde],sizeof(Matriculas),1,arq)==1)
				{
					if(escolheCurso==matriculaAux[*qtde].idCurso && escolheAno==matriculaAux[*qtde].ano && escolheSituacao==matriculaAux[*qtde].situacaoAluno)
					{
						(*qtde)++;
					}
				}
			}else
			{
				printf("Erro ao alocar memoria \n");
			}
		}
		fclose(arq);
	}
	
	return matriculaAux;
}
// Objetivo: menu com as opçoes do relatorio 5(sobre a situaçao do aluno) 
// Parâmetros: nenhum
// Retorno: nenhum
void relatorio5(void)
{
	char opcao;
	char *itensMenu[]={
	                   " REGULAR",
	                   " PENDENDE",
	                   " PAGA",
	                   " VOLTAR",
				   };
	do
      {
	   	  limpaJanela(1,1,25,80,AZUL);
	   	  gotoxy(9,8);
	   	  fprintf(stdout,"INFORME A SITUACAO DO ALUNO");
	      opcao=menuVertical(4,itensMenu,BRANCO,VERDE,10,10,1,1,AZUL,BRANCO);
	      retornaCor(AZUL,BRANCO);
		switch(opcao)
		{
			case 1:
				opcaoRegular();
				break;
			case 2:
				opcaoPendente();
				break;
			case 3:
				opcaoPago();
				break;
			case 4:
				return;
			
		}
	}while(opcao !=4);
	
				   
}
// Objetivo: monstra apenas os alunos que estao na situaçao PENDENTE
// Parâmetros: nenhum
// Retorno: nenhum
void opcaoPendente()
{
	FILE *arqBin;
	Matriculas *matricula;
	Matriculas matriculaAux;
	char **dadosSit=NULL,**dadosSitAux;
	char **dadosSitCurso=NULL,**dadosSitCursoAux;
	FILE *arqMatricula;
	char **nomesAlunos=NULL;
	char **nomesAlunosAux;	
	Aluno alunos;
	FILE *arqAlunos;	
	int cont=0, nroAluno=0;
	int cont2=0;
	int cont3=0;
	int cont4=0;
	int aux,linha;
	int qtdeMatriculas=0;
	system("cls");
	if((matricula = obtemDadosSituacao(&qtdeMatriculas,'P'))!=NULL)
	{
		linha=11;

		desenhaMoldura(10,10,20,90,AZUL,BRANCO);
	    for(aux=0;aux<qtdeMatriculas;aux++){
	    	
			nomesAlunosAux=(char**) realloc(nomesAlunos,sizeof(char*)*(cont4+1));
				if(nomesAlunosAux!=NULL)
				{
					nomesAlunos=nomesAlunosAux;
					nomesAlunos[cont4]=(char*)malloc(sizeof(char)*(MAX_NOME+1));
					if(nomesAlunos[cont4]!=NULL)
					{
						if((arqAlunos = abreArquivo("dadosAlunos.txt","rb"))!=NULL)          
						{
																									
							while(!feof(arqAlunos))
							{
								if(fread(&alunos,sizeof(Aluno),1,arqAlunos)==1)
								{
									//printf("%i %i ",matricula.idAluno,alunos.matricula);
									
									if(matricula[aux].idAluno==alunos.matricula)
									{
										strcpy(nomesAlunos[cont4],alunos.nomeAluno);
										cont4++;
									}
									//printf("%s ",nomesAlunos[contador]);
								}
							}
							fclose(arqAlunos);
						}
						
					}
				}
				dadosSitAux=(char**) realloc(dadosSit,sizeof(char*)*(cont2+1));
				if(dadosSitAux!=NULL)
				{
					dadosSit=dadosSitAux;
					dadosSit[cont2]=(char*)malloc(sizeof(char)*(TAM_SITUACAO+1));
					if(dadosSit[cont2]!=NULL)
					{
						//printf("%c ",matricula.situacaoAluno);
						if(matricula[aux].situacaoAluno=='C')
						{
							strcpy(dadosSit[cont2],"CURSANDO");
						}else{
							strcpy(dadosSit[cont2],"CONCLUIDO");
						
						}
						//printf("%s ",dadosSit[cont2]);
						cont2++;
					}
				}
				//printf("%s %c \n",dadosSit[cont2],matricula.situacaoAluno);
				dadosSitCursoAux=(char**) realloc(dadosSitCurso,sizeof(char*)*(cont3+1));
				if(dadosSitCursoAux!=NULL)
				{
					dadosSitCurso=dadosSitCursoAux;
					dadosSitCurso[cont3]=(char*) malloc(sizeof(char)*(TAM_SITUACAO+1));
					if(dadosSitCurso[cont3]!=NULL)
					{
					
					
						if(matricula[aux].situacaoCurso=='R')
						{
							strcpy(dadosSitCurso[cont3],"REGULAR");
						}else
						{
							if(matricula[aux].situacaoCurso=='P')
							{
								strcpy(dadosSitCurso[cont3],"PENDENTE");
							}else
							{
								strcpy(dadosSitCurso[cont3],"PAGO");
							}
						}
						cont3++;
					}
				}
				
	       	gotoxy(11,9);
			fprintf(stdout,"%-18s %-6s %-5s %5s %s","NOME","ID CURSO","SITUACAO ALUNO ","SITUACAO CURSO","DATA");
			gotoxy(11,linha);
			linha++;
           	printf("%-18.18s - %-6i - %-5s - %-8s %i/%i \n",nomesAlunos[aux],matricula[aux].idCurso,dadosSit[aux],dadosSitCurso[aux],matricula[aux].mes,matricula[aux].ano);
			cont++;
			
		}
		if(cont==0)
		{
			gotoxy(5,5);
			fprintf(stdout,"Nao foi encontrado cursos  \n");	
		}
		free(matricula);
	}
	else
	{
		desenhaMoldura(10,10,14,70,AZUL,BRANCO);
		gotoxy(20,12);
		fprintf(stdout,"Nao foi possivel carregar dados do arquivo ");
	}
	free(dadosSit);
	free(dadosSitCurso);
	free(nomesAlunos);
	getch();
	system("cls");
}
// Objetivo: monstra apenas os alunos que estao na situaçao regular
// Parâmetros: nenhum
// Retorno: nenhum
void opcaoPago()
{
		FILE *arqBin;
	Matriculas *matricula;
	Matriculas matriculaAux;
	char **dadosSit=NULL,**dadosSitAux;
	char **dadosSitCurso=NULL,**dadosSitCursoAux;
	FILE *arqMatricula;
	char **nomesAlunos=NULL;
	char **nomesAlunosAux;	
	Aluno alunos;
	FILE *arqAlunos;	
	int cont=0, nroAluno=0;
	int cont2=0;
	int cont3=0;
	int cont4=0;
	int aux,linha;
	int qtdeMatriculas=0;
	system("cls");
	if((matricula = obtemDadosSituacao(&qtdeMatriculas,'F'))!=NULL)
	{
		linha=11;

		desenhaMoldura(10,10,20,90,AZUL,BRANCO);
	    for(aux=0;aux<qtdeMatriculas;aux++){
	    	
			nomesAlunosAux=(char**) realloc(nomesAlunos,sizeof(char*)*(cont4+1));
				if(nomesAlunosAux!=NULL)
				{
					nomesAlunos=nomesAlunosAux;
					nomesAlunos[cont4]=(char*)malloc(sizeof(char)*(MAX_NOME+1));
					if(nomesAlunos[cont4]!=NULL)
					{
						if((arqAlunos = abreArquivo("dadosAlunos.txt","rb"))!=NULL)          
						{
																									
							while(!feof(arqAlunos))
							{
								if(fread(&alunos,sizeof(Aluno),1,arqAlunos)==1)
								{
									//printf("%i %i ",matricula.idAluno,alunos.matricula);
									
									if(matricula[aux].idAluno==alunos.matricula)
									{
										strcpy(nomesAlunos[cont4],alunos.nomeAluno);
										//printf("%s ",nomesAlunos[contador]);
										cont4++;
									}
									//printf("%s ",nomesAlunos[contador]);
								}
							}
							fclose(arqAlunos);
						}
						
					}
				}
				dadosSitAux=(char**) realloc(dadosSit,sizeof(char*)*(cont2+1));
				if(dadosSitAux!=NULL)
				{
					dadosSit=dadosSitAux;
					dadosSit[cont2]=(char*)malloc(sizeof(char)*(TAM_SITUACAO+1));
					if(dadosSit[cont2]!=NULL)
					{
						//printf("%c ",matricula.situacaoAluno);
						if(matricula[aux].situacaoAluno=='C')
						{
							strcpy(dadosSit[cont2],"CURSANDO");
						}else{
							strcpy(dadosSit[cont2],"CONCLUIDO");
						
						}
						//printf("%s ",dadosSit[cont2]);
						cont2++;
					}
				}
				//printf("%s %c \n",dadosSit[cont2],matricula.situacaoAluno);
				dadosSitCursoAux=(char**) realloc(dadosSitCurso,sizeof(char*)*(cont3+1));
				if(dadosSitCursoAux!=NULL)
				{
					dadosSitCurso=dadosSitCursoAux;
					dadosSitCurso[cont3]=(char*) malloc(sizeof(char)*(TAM_SITUACAO+1));
					if(dadosSitCurso[cont3]!=NULL)
					{
					
					
						if(matricula[aux].situacaoCurso=='R')
						{
							strcpy(dadosSitCurso[cont3],"REGULAR");
						}else
						{
							if(matricula[aux].situacaoCurso=='P')
							{
								strcpy(dadosSitCurso[cont3],"PENDENTE");
							}else
							{
								strcpy(dadosSitCurso[cont3],"PAGO");
							}
						}
						cont3++;
					}
				}
				
	       	gotoxy(11,9);
			fprintf(stdout,"%-18s %-6s %-5s %5s %s","NOME","ID CURSO","SITUACAO ALUNO ","SITUACAO CURSO","DATA");
			gotoxy(11,linha);
			linha++;
           	printf("%-18.18s - %-6i - %-5s - %-8s %i/%i \n",nomesAlunos[aux],matricula[aux].idCurso,dadosSit[aux],dadosSitCurso[aux],matricula[aux].mes,matricula[aux].ano);
			cont++;
			
		}
		if(cont==0)
		{
			gotoxy(5,5);
			fprintf(stdout,"Nao foi encontrado cursos  \n");	
		}
		free(matricula);
	}
	else
	{
		desenhaMoldura(10,10,14,70,AZUL,BRANCO);
		gotoxy(20,12);
		fprintf(stdout,"Nao foi possivel carregar dados do arquivo ");
	}
	free(dadosSit);
	free(dadosSitCurso);
	free(nomesAlunos);
	getch();
	system("cls");
}
// Objetivo: monstra apenas os alunos que estao na situaçao regular
// Parâmetros: nenhum
// Retorno: nenhum
void opcaoRegular()
{
	FILE *arqBin;
	Matriculas *matricula;
	Matriculas matriculaAux;
	char **dadosSit=NULL,**dadosSitAux;
	char **dadosSitCurso=NULL,**dadosSitCursoAux;
	FILE *arqMatricula;
	char **nomesAlunos=NULL;
	char **nomesAlunosAux;	
	Aluno alunos;
	FILE *arqAlunos;	
	int cont=0, nroAluno=0;
	int cont2=0;
	int cont3=0;
	int cont4=0;
	int aux,linha;
	int qtdeMatriculas=0;
	system("cls");
	if((matricula = obtemDadosSituacao(&qtdeMatriculas,'R'))!=NULL)
	{
		linha=11;

		desenhaMoldura(10,10,20,90,AZUL,BRANCO);
	    for(aux=0;aux<qtdeMatriculas;aux++){
	    	
			nomesAlunosAux=(char**) realloc(nomesAlunos,sizeof(char*)*(cont4+1));
				if(nomesAlunosAux!=NULL)
				{
					nomesAlunos=nomesAlunosAux;
					nomesAlunos[cont4]=(char*)malloc(sizeof(char)*(MAX_NOME+1));
					if(nomesAlunos[cont4]!=NULL)
					{
						if((arqAlunos = abreArquivo("dadosAlunos.txt","rb"))!=NULL)          
						{
																									
							while(!feof(arqAlunos))
							{
								if(fread(&alunos,sizeof(Aluno),1,arqAlunos)==1)
								{
									//printf("%i %i ",matricula.idAluno,alunos.matricula);
									
									if(matricula[aux].idAluno==alunos.matricula)
									{
										strcpy(nomesAlunos[cont4],alunos.nomeAluno);
										//printf("%s ",nomesAlunos[contador]);
										cont4++;
									}
									//printf("%s ",nomesAlunos[contador]);
								}
							}
							fclose(arqAlunos);
						}
						
					}
				}
				dadosSitAux=(char**) realloc(dadosSit,sizeof(char*)*(cont2+1));
				if(dadosSitAux!=NULL)
				{
					dadosSit=dadosSitAux;
					dadosSit[cont2]=(char*)malloc(sizeof(char)*(TAM_SITUACAO+1));
					if(dadosSit[cont2]!=NULL)
					{
						//printf("%c ",matricula.situacaoAluno);
						if(matricula[aux].situacaoAluno=='C')
						{
							strcpy(dadosSit[cont2],"CURSANDO");
						}else{
							strcpy(dadosSit[cont2],"CONCLUIDO");
						
						}
						//printf("%s ",dadosSit[cont2]);
						cont2++;
					}
				}
				//printf("%s %c \n",dadosSit[cont2],matricula.situacaoAluno);
				dadosSitCursoAux=(char**) realloc(dadosSitCurso,sizeof(char*)*(cont3+1));
				if(dadosSitCursoAux!=NULL)
				{
					dadosSitCurso=dadosSitCursoAux;
					dadosSitCurso[cont3]=(char*) malloc(sizeof(char)*(TAM_SITUACAO+1));
					if(dadosSitCurso[cont3]!=NULL)
					{
					
					
						if(matricula[aux].situacaoCurso=='R')
						{
							strcpy(dadosSitCurso[cont3],"REGULAR");
						}else
						{
							if(matricula[aux].situacaoCurso=='P')
							{
								strcpy(dadosSitCurso[cont3],"PENDENTE");
							}else
							{
								strcpy(dadosSitCurso[cont3],"PAGO");
							}
						}
						cont3++;
					}
				}
				
	       	gotoxy(11,9);
			fprintf(stdout,"%-18s %-6s %-5s %5s %s","NOME","ID CURSO","SITUACAO ALUNO ","SITUACAO CURSO","DATA");
			gotoxy(11,linha);
			linha++;
           	printf("%-18.18s - %-6i - %-5s - %-8s %i/%i \n",nomesAlunos[aux],matricula[aux].idCurso,dadosSit[aux],dadosSitCurso[aux],matricula[aux].mes,matricula[aux].ano);
			cont++;
			
		}
		if(cont==0)
		{
			gotoxy(5,5);
			fprintf(stdout,"Nao foi encontrado cursos  \n");	
		}
		free(matricula);
	}
	else
	{
		desenhaMoldura(10,10,14,70,AZUL,BRANCO);
		gotoxy(20,12);
		fprintf(stdout,"Nao foi possivel carregar dados do arquivo ");
	}
	free(dadosSit);
	free(dadosSitCurso);
	free(nomesAlunos);
	getch();
	system("cls");
}
//Objetivo: Obtem os dados necessarios a partir de uma situacao
//Parametros: referencia a quantidade, e opcao desejada
//Retorno: endereço da estruct com os dados.
Matriculas *obtemDadosSituacao(int *qtde, char opcao)
{
	FILE *arq=NULL;
	Matriculas *matricula=NULL,*matriculaAux=NULL;
	
	if((arq=abreArquivo("dadosMatriculas.txt","rb"))!=NULL)
	{
		while(!feof(arq))
		{
			matricula=(Matriculas*)realloc(matriculaAux,sizeof(Matriculas)*((*qtde)+1));
			if(matricula!=NULL)
			{
				matriculaAux=matricula;
				if(fread(&matriculaAux[*qtde],sizeof(Matriculas),1,arq)==1)
				{
					if(matriculaAux[*qtde].situacaoCurso==opcao)
					{
						
						(*qtde)++;
					}
				}
			}else{
				printf("Erro ao alocar memoria \n");
			}
		}
		fclose(arq);
	}
	return matriculaAux;
}
//Objetivo: Apresentar os dados presentes em Todos os arquivos.
//Parametros:
//Retorno:
void relatorio1(void)
{
	Cursos *curso;
	Aluno *alunos;
	Cursos cursoAux;
	Aluno alunosAux;
	FILE *arqAlunos;
	FILE *arqCursos;
	FILE *arqMatricula;
	char **nomeAluno=NULL;
	char **nomeCurso=NULL;
	char **nomeAlunoAux;
	char **nomeCursoAux;
	char **dadosSit=NULL,**dadosSitAux;
	char **dadosSitCurso=NULL,**dadosSitCursoAux;
	static char cpfFormatado[15];
	Matriculas *matricula;
	Matriculas matriculaAux;
	int cont,linha;
	int cont2=0;
	int cont3=0;
	int qtdeAlunos,qtdeCursos,qtdeMatriculas;
	gotoxy(4,2);
	fprintf(stdout,"DADOS DE ALUNOS ");
	gotoxy(4,3);
	fprintf(stdout,"%-s %-29s%-5s    %5s%5s","MATRICULA","NOME","IDADE","SEXO","CPF");
	desenhaMoldura(4,3,25,79,AZUL,BRANCO);
	if((alunos = obtemDadosArquivoAluno(&qtdeAlunos))!=NULL )
	{
		linha=5;
		
		qsort(alunos,qtdeAlunos,sizeof(Aluno),comparaNomeAlunos);
		for(cont=0;cont<qtdeAlunos;cont++)
		{
			sprintf(cpfFormatado,"%3.3s.%3.3s.%3.3s-%2.2s",
       		alunos[cont].CPF,alunos[cont].CPF+3,alunos[cont].CPF+6,alunos[cont].CPF+9);
			strcpy(alunos[cont].CPF,cpfFormatado);
			gotoxy(4,linha);
			fprintf(stdout,"%5i - %-30.30s - %-5i - %-5c %-15.15s\n",alunos[cont].matricula,alunos[cont].nomeAluno,alunos[cont].idade,alunos[cont].sexo,alunos[cont].CPF);
			linha++;
		}	
		free(alunos);
	}
	getch();
	limpaJanela(2,2,25,79,AZUL);
	gotoxy(4,2);
	fprintf(stdout,"DADOS DE CURSOS ");
	gotoxy(4,3);
	fprintf(stdout,"%s %-29s%-5s %5s","CODIGO","NOME DO CURSO","CARGA HORARIA","MENSALIDADE");
	desenhaMoldura(4,3,25,79,AZUL,BRANCO);
	if((curso = obtemDadosArquivoCursos(&qtdeCursos))!=NULL )
	{
		qsort(curso,qtdeCursos,sizeof(Cursos),comparaNomeCursos);
		linha=5;
		for(cont=0;cont<qtdeCursos;cont++)
		{
			//qsort(curso,qtdeCursos,sizeof(Cursos),comparaNomeCursos);
			gotoxy(4,linha);
			fprintf(stdout,"%5i - %-30.30s - %-5i - %-5.2f \n",curso[cont].codCurso,curso[cont].nomeCurso,curso[cont].horarios,curso[cont].mensalidade);
			linha++;
		}
		free(curso);	
	}
	getch();
	limpaJanela(2,2,25,79,AZUL);

	if((arqMatricula=abreArquivo("dadosMatriculas.txt","rb"))!=NULL)
	{
		while(!feof(arqMatricula))
		{
			if(fread(&matriculaAux,sizeof(Matriculas),1,arqMatricula)==1)
			{
				nomeAlunoAux=(char**)realloc(nomeAluno,sizeof(char*)*(cont2+1));
				if(nomeAlunoAux!=NULL)
				{
					nomeAluno=nomeAlunoAux;
					nomeAluno[cont2]=(char*)malloc(sizeof(char)*(MAX_NOME+1));
					if(nomeAluno[cont2]!=NULL)
					{
						if((arqAlunos=abreArquivo("dadosAlunos.txt","rb"))!=NULL)
						{
							while(!feof(arqAlunos))
							{
								if(fread(&alunosAux,sizeof(Aluno),1,arqAlunos)==1)
								{
									if(matriculaAux.idAluno==alunosAux.matricula)
									{
										strcpy(nomeAluno[cont2],alunosAux.nomeAluno);
										//printf("%s",nomeAluno[cont2]);
										cont2++;
										//printf("%i",cont2);
									}
	
								}
							}
							fclose(arqAlunos);
						}
					}
				}
			}
		}
		fclose(arqMatricula);
			
	}
	if((arqMatricula=abreArquivo("dadosMatriculas.txt","rb"))!=NULL)
	{
		while(!feof(arqMatricula))
		{
			if(fread(&matriculaAux,sizeof(Matriculas),1,arqMatricula)==1)
			{
				nomeCursoAux=(char**)realloc(nomeCurso,sizeof(char*)*(cont3+1));
				if(nomeCursoAux!=NULL)
				{
					nomeCurso=nomeCursoAux;
					nomeCurso[cont3]=(char*)malloc(sizeof(char)*(MAX_NOME+1));
					if(nomeCurso[cont3]!=NULL)
					{
			
						if((arqCursos=abreArquivo("dadosCursos.txt","rb"))!=NULL)
						{
							while(!feof(arqCursos))
							{
								if(fread(&cursoAux,sizeof(Cursos),1,arqCursos)==1)
								{
									if(matriculaAux.idCurso==cursoAux.codCurso)
									{
										strcpy(nomeCurso[cont3],cursoAux.nomeCurso);
										//printf("%s",nomeCurso[cont3]);
										
										//printf("%i",cont3);
										cont3++;
									}
								}
							}
							fclose(arqCursos);
						}
					}
				}
				
			}	
		}
		fclose(arqMatricula);
	}
	arqMatricula = abreArquivo("dadosMatriculas.txt","rb");
	if(arqMatricula!=NULL)
	{
		cont2=0;
		cont3=0;
		while(!feof(arqMatricula))
		{
			if(fread(&matriculaAux,sizeof(Matriculas),1,arqMatricula)==1)
			{
					dadosSitAux=(char**) realloc(dadosSit,sizeof(char*)*(cont2+1));
					if(dadosSitAux!=NULL)
					{
						dadosSit=dadosSitAux;
						dadosSit[cont2]=(char*)malloc(sizeof(char)*(TAM_SITUACAO+1));
						if(dadosSit[cont2]!=NULL)
						{
							//printf("%c ",matricula.situacaoAluno);
							if(matriculaAux.situacaoAluno=='C')
							{
								strcpy(dadosSit[cont2],"CURSANDO");
							}else{
								strcpy(dadosSit[cont2],"CONCLUIDO");
							
							}
							//printf("%s ",dadosSit[cont2]);
							cont2++;
						}
					}
					//printf("%s %c \n",dadosSit[cont2],matricula.situacaoAluno);
					dadosSitCursoAux=(char**) realloc(dadosSitCurso,sizeof(char*)*(cont2+1));
					if(dadosSitCursoAux!=NULL)
					{
						dadosSitCurso=dadosSitCursoAux;
						dadosSitCurso[cont3]=(char*) malloc(sizeof(char)*(TAM_SITUACAO+1));
						if(dadosSitCurso[cont3]!=NULL)
						{
						
						
							if(matriculaAux.situacaoCurso=='R')
							{
								strcpy(dadosSitCurso[cont3],"REGULAR");
							}else
							{
								if(matriculaAux.situacaoCurso=='P')
								{
									strcpy(dadosSitCurso[cont3],"PENDENTE");
								}else
								{
									strcpy(dadosSitCurso[cont3],"PAGO");
								}
							}
							cont3++;
						}
					}
				
					
			}
		}
		fclose(arqMatricula);
		
	}
	gotoxy(4,2);
	fprintf(stdout,"DADOS DE MATRICULAS");
	gotoxy(4,3);
	fprintf(stdout,"%-9.9s %-25.25s%-18.18s %-10.10s %-15.15s %-15.15s %s","MATRICULA","NOME ALUNO ","NOME CURSO","ID CURSO","SITUACAO ALUNO ","SITUACAO CURSO","DATA");
	desenhaMoldura(4,3,25,110,AZUL,BRANCO);
	if((matricula=obtemDadosArquivoMatriculas(&qtdeMatriculas))!=NULL)
	{
		
		linha=5;
		for(cont=0;cont<qtdeMatriculas;cont++)
		{
			gotoxy(4,linha);
			//qsort(matricula,qtdeMatriculas,sizeof(Matriculas),comparaNomesMatricula);
			fprintf(stdout,"%-9i%-25.25s %-18.18s %-10i %-15s %-15s  %i/%i \n",matricula[cont].idAluno,nomeAluno[cont],nomeCurso[cont],matricula[cont].idCurso,dadosSit[cont],dadosSitCurso[cont],matricula[cont].mes,matricula[cont].ano);
			linha++;
		}
		
	}
	free(nomeCurso);
	free(nomeAluno);
	free(matricula);
	getch();
	system("cls");	
}
//Objetivos: Apresentar os dados dos alunos matriculados em um periodo (data)
//Parametros:
//Retorno:
void relatorio4(void)
{
	int diaDesejado,mesDesejado,anoDesejado;
	int diaDesejado2,mesDesejado2,anoDesejado2;
	Aluno *alunos;
	int qtdeAlunos=0,cont,linha;
	int verificador,aux=0;
	int dataInicial,dataFinal;
	static char cpfFormatado[15];
	
	desenhaMoldura(10,10,20,50,AZUL,BRANCO);
	gotoxy(11,11);
	fprintf(stdout,"De....");
	diaDesejado = leInt("DIA = ",1,31,11,12);
	gotoxy(11,12);
	mesDesejado = leInt("MES = ",1,12,11,13);
	gotoxy(11,13);
	anoDesejado = leInt("ANO = ",1950,2050,11,14);
	verificador=verificaData(diaDesejado,mesDesejado,anoDesejado);
	if(verificador==1)
	{
		gotoxy(11,15);
		apresentaMsgErro("Data Invalida, verifique corretamente ","");
		return;
	}
	limpaJanela(10,10,20,50,AZUL);
	desenhaMoldura(10,10,20,70,AZUL,BRANCO);
	gotoxy(11,11);
	fprintf(stdout,"Ate....");
	diaDesejado2 = leInt("DIA = ",1,31,11,12);
	gotoxy(11,12);
	mesDesejado2 = leInt("MES = ",1,12,11,13);
	gotoxy(11,13);
	anoDesejado2 = leInt("ANO = ",1950,2050,11,14);
	gotoxy(11,14);
	verificador=verificaData(diaDesejado2,mesDesejado2,anoDesejado2);
	if(verificador==1)
	{
		gotoxy(11,15);
		apresentaMsgErro("Data Invalida, verifique corretamente ","");
		return;
	}
	linha=4;
	system("cls");
	gotoxy(3,1);
	fprintf(stdout,"PERIODO = %i/%i/%i ate %i/%i/%i ",diaDesejado,mesDesejado,anoDesejado,diaDesejado2,mesDesejado2,anoDesejado2);
	gotoxy(2,2);
	dataInicial=transformaData(diaDesejado,mesDesejado,anoDesejado);
	dataFinal=transformaData(diaDesejado2,mesDesejado2,anoDesejado2);
	if(dataInicial > dataFinal)
	{
		gotoxy(3,3);
		fprintf(stdout,"Data INICIAL Maior que a FINAL !!! ");
		getch();
		system("cls");
		return;
		
	}
	if((alunos = obtemAlunosPeriodo(&qtdeAlunos,dataInicial,dataFinal))!=NULL)
	{
	
		fprintf(stdout,"%-30.30s%-5.5s %-16.16s%-15.15s%s","NOME","IDADE","SEXO","CPF","DATA INGRESSO");
		desenhaMoldura(3,1,25,90,AZUL,BRANCO);
		qsort(alunos,qtdeAlunos,sizeof(Aluno),comparaNomeAlunos);
		for(cont=0;cont<qtdeAlunos;cont++)
		{
			//qsort(alunos,qtdeAlunos,sizeof(Aluno),comparaNomeAlunos);
				sprintf(cpfFormatado,"%3.3s.%3.3s.%3.3s-%2.2s",
           		alunos[cont].CPF,alunos[cont].CPF+3,alunos[cont].CPF+6,alunos[cont].CPF+9);
           		strcpy(alunos[cont].CPF,cpfFormatado);	
			if(alunos[cont].sexo=='F')
			{
				gotoxy(2,linha);
				linha++;
				fprintf(stdout,"%-30.30s-%-5i-%-16.16s%-15.15s %i/%i/%i \n",alunos[cont].nomeAluno,alunos[cont].idade,"FEMININO",
				alunos[cont].CPF,alunos[cont].dataDia,alunos[cont].dataMes,alunos[cont].dataAno);	
				aux++;
			}else{
				gotoxy(2,linha);
				linha++;
				fprintf(stdout,"%-30.30s-%-5i-%-16.16s%-15.15s %i/%i/%i \n",alunos[cont].nomeAluno,alunos[cont].idade,"MASCULINO",
				alunos[cont].CPF,alunos[cont].dataDia,alunos[cont].dataMes,alunos[cont].dataAno);
				aux++;
			}
				
			
		}
		if(aux==0)
		{
			gotoxy(5,5);
			fprintf(stdout,"Nao foram encontrados resultados \n");
		}
		free(alunos);
		
	}else
	{
		desenhaMoldura(10,10,14,70,AZUL,BRANCO);
		gotoxy(20,12);
		fprintf(stdout,"Nao foi possivel carregar dados do arquivo ");
	}
	getch();
	system("cls");
	
	
	
}
//Objetivo: Transformar uma data para um numero Unico
//Parametros: dia , mes e ano
//Retorno: numero unico da data
int transformaData(int dia,int mes,int ano)
{
	int numero=0;
	int numeroAux=0;
	
	numeroAux = (ano*1000)+(mes*100)+dia;	
	numero = numeroAux;

		
}
//Objetivo: Trazer para a memoria os alunos matriculados em um periodo.
//Parametros: dia, mes e ano iniciais, e dia, mes e ano finais , referencia a quantidade de alunos.
//Retorno: endereco de memoria da estruct com os dados
Aluno *obtemAlunosPeriodo(int *qtdeAlunos,int dataInicial,int dataFinal)
{
	FILE *arqAlunos=NULL;
	Aluno *alunos=NULL,*alunosAux=NULL;
	int dataAlunos=0;
	

	
	if((arqAlunos = abreArquivo("dadosAlunos.txt","rb"))!=NULL)
	{
		while(!feof(arqAlunos))
		{
			alunos=(Aluno*) realloc(alunosAux,sizeof(Aluno)*((*qtdeAlunos)+1));
			if(alunos!=NULL)
			{
				alunosAux=alunos;
				if(fread(&alunosAux[*qtdeAlunos],sizeof(Aluno),1,arqAlunos)==1)
				{
					dataAlunos=transformaData(alunos[*qtdeAlunos].dataDia,alunos[*qtdeAlunos].dataMes,alunos[*qtdeAlunos].dataAno);
					if(dataInicial<=dataAlunos && dataAlunos<=dataFinal)
					{
						(*qtdeAlunos)++;
					}
				}
			}
		}
	}
	return alunosAux;
	
	
	
	
	
}
//Objetivos: verificar se o ano é ou nao bissexto
//Parametros:ano, mes  e o dia
//retorno: 1 bissexto 0 nao-bissexto
int verificaBissexto(int ano,int mes,int dia)
{
	int flag=0;
	
	if(ano % 400==0){
		flag=1;
	}else if((ano % 4 == 0)&&(ano%100 != 0))
	{
		flag=1;
	}
	else{
		flag=0;
	}
	return flag;
}
//Objetivo:Verificar se uma data esta correta
//Paraemtros: dia, mes e ano
//retorno: 1 correta 0 errada.
int verificaData(int dia,int mes,int ano)
{
	int flag=0;
	int bissexto;
	bissexto=verificaBissexto(ano,mes,dia);
	if((bissexto==1) && (mes == 2) && (dia > 29) )
	{
		flag=1;
	}
	if(mes==4 && dia > 30)
	{
		flag=1;
	}
	if(mes==6 && dia>30)
	{
		flag=1;
	}
	if(mes==9 && dia>30)
	{
		flag=1;
	}
	if(mes==1 && dia>11)
	{
		flag=1;
	}
	
	return flag;
	
}
//Objetivo: compara os dados para serem ordenados pela qsort
//Parametros: endereços dos elementos que serao ordenados
// retorno : =0 --> dados iguais
//           >0 --> dados desordenados
//           <0 --> dados ordenados
int comparaMatriculas(const void *p1,const void *p2)
{
	Matriculas *matricula1,*matricula2;
	
	matricula1=(Matriculas*)p1;
	matricula2=(Matriculas*)p2;
	
	return (*matricula1).idAluno-(*matricula2).idAluno;
}
