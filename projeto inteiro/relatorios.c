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
	Matriculas *matricula;
	char nomeDesejado[TAM_TEXTO];
	char opcaoDesejada;
	int qtdeAlunos,qtdeCursos,qtdeMatriculas,cont=0,i,linha;
	int cont2,cont3;
	if((alunos=obtemDadosArquivoAluno(&qtdeAlunos))!=NULL && (curso=obtemDadosArquivoCursos(&qtdeCursos))!=NULL && (matricula=obtemDadosArquivoMatriculas(&qtdeMatriculas))!=NULL )
	{
		desenhaMoldura(1,1,20,80,AZUL,BRANCO);
		gotoxy(2,2);
		leValidaTexto("Informe o nome completo do curso = ",nomeDesejado,TAM_TEXTO,11,11);
		strToUpper(nomeDesejado);
		limpaJanela(2,2,19,79,AZUL);
		cont=0;
		linha =3;
		for(i=0;i<qtdeCursos;i++)
		{
			if(stricmp(curso[i].nomeCurso,nomeDesejado)==0)
			{
				gotoxy(3,2);
				fprintf(stdout,"Mostranto resultados para %s ",nomeDesejado);
				fprintf(stdout,"Encontrado %s ",curso[i].nomeCurso);
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
					fprintf(stdout,"%-12.12s-%-21.21s -%-15.15s-%-10.10s ","CPF","NOME ALUNO","SITUACAO","CODIGO CURSO");
					for(cont2=0;cont2<qtdeMatriculas;cont2++){
						if(strcmp("CURSANDO",matricula[cont2].situacaoAluno)==0)
						{
							for(cont3=0;cont3<qtdeAlunos;cont3++){
					
								if(matricula[cont2].idAluno==alunos[cont3].matricula && matricula[cont2].idCurso==curso[i].codCurso)
								{
									gotoxy(3,linha);
									linha++;
									fprintf(stdout,"%-12.12s-%-21.21s %-15s-%-10i ",alunos[cont3].CPF,alunos[cont3].nomeAluno,
									matricula[cont2].situacaoAluno,curso[i].codCurso);
									cont++;
								}
							}
						}
					}
					break;
					case 'B':
					desenhaMoldura(2,2,20,79,AZUL,BRANCO);
					gotoxy(3,1);
					fprintf(stdout,"%-12.12s-%-21.21s -%-15.15s-%-10.10s ","CPF","NOME ALUNO","SITUACAO","CODIGO CURSO");
					for(cont2=0;cont2<qtdeMatriculas;cont2++){
						if(strcmp("CONCLUIDO",matricula[cont2].situacaoAluno)==0)
						{
							for(cont3=0;cont3<qtdeAlunos;cont3++){
					
								if(matricula[cont2].idAluno==alunos[cont3].matricula && matricula[cont2].idCurso==curso[i].codCurso)
								{
									gotoxy(3,linha);
									linha++;
									fprintf(stdout,"%-12.12s-%-21.21s %-15s-%-10i ",alunos[cont3].CPF,alunos[cont3].nomeAluno,
									matricula[cont2].situacaoAluno,curso[i].codCurso);
									cont++;
							 	}
							 	
							}
						}
					}
					break;
			    	case 'C':
			    	
			    	desenhaMoldura(2,2,20,79,AZUL,BRANCO);
			    	gotoxy(3,1);
			    	fprintf(stdout,"%-12.12s-%-21.21s -%-15.15s-%-10.10s ","CPF","NOME ALUNO","SITUACAO","CODIGO CURSO");
			    	for(cont2=0;cont2<qtdeMatriculas;cont2++)
					{
							for(cont3=0;cont3<qtdeAlunos;cont3++){
								if(matricula[cont2].idAluno==alunos[cont3].matricula && matricula[cont2].idCurso==curso[i].codCurso)
								{
									gotoxy(3,linha);
									linha++;
									fprintf(stdout,"%-12.12s-%-21.21s %-15s-%-10i ",alunos[cont3].CPF,alunos[cont3].nomeAluno,
									matricula[cont2].situacaoAluno,curso[i].codCurso);
									cont++;
							 	}
							}
							
					}

				
					break;		
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
int cont=0,qtdeCursos,i,linha;
Cursos *curso;
char pesquisaCurso[NOME_CURSO];
    if((curso = obtemDadosArquivoCursos(&qtdeCursos))!=NULL){
    	desenhaMoldura(10,10,14,70,AZUL,BRANCO);
    	gotoxy(11,11);

		leValidaTexto("Trecho que deseja procurar - ",pesquisaCurso,NOME_CURSO,11,12);
		//strToUpper(pesquisaCurso);
		limpaJanela(10,10,14,70,AZUL);
		gotoxy(2,2);
		//fprintf(stdout,"Cursos com o nome = %s \n",pesquisaCurso);
		cont=0;
		linha =3;
    	fprintf(stdout,"%s %-29s%-5s %5s\n","CODIGO","NOME DO CURSO","CARGA HORARIA","MENSALIDADE");
    	
		for(i=0;i<qtdeCursos;i++){
			qsort(curso,qtdeCursos,sizeof(Cursos),comparaNomeCursos);
		
			if(strIstr(curso[i].nomeCurso,pesquisaCurso)!= NULL)	
			{   
				
				/*if(linha>=18)
				{
					gotoxy(2,linha);
					fprintf(stdout,"Tecle para avancar \n");
					getch();
					limpaJanela(3,2,19,79,AZUL);
					linha=3;
				}
				*/
				desenhaMoldura(1,1,20,70,AZUL,BRANCO);
				gotoxy(2,linha);
				linha++;				
				fprintf(stdout,"%5i - %-30.30s - %-5i - %-5.2f \n",curso[i].codCurso,curso[i].nomeCurso,curso[i].horarios,curso[i].mensalidade);
				cont++;
			}
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
// Objetivo: pesquisar anos que concluiram o curso em determinadoa ano 
// Parâmetros: nenhum
// Retorno: nenhum
void relatorio6()
{
	int escolheCurso,escolheAno;
	Matriculas *matricula;
    FILE *arqBin;
    int cont=0,aux, nroAluno=0;	
	int linha,qtdeMatriculas;
	escolheCurso=apresentaCursosV();
	desenhaMoldura(10,10,20,90,AZUL,BRANCO);
	
	escolheAno=leInt("INFORME O ANO QUE CONCLUIU O CURSO- ",2000,2016,11,11);
	system("cls");
	if((matricula = obtemDadosArquivoMatriculas(&qtdeMatriculas))!=NULL)
	{
		
		linha=11;
		for(aux=0;aux<qtdeMatriculas;aux++)
		{
			//qsort(matricula,qtdeMatriculas,sizeof(Matriculas),comparaNomesMatricula);
			if(escolheCurso==matricula[aux].idCurso && escolheAno==matricula[aux].ano)
			{
				
				if(stricmp(matricula[aux].situacaoAluno,"CONCLUIDO")==0)
				{
					
					//fprintf(stdout,"entrou %i %i ",escolheCurso,escolheAno);
					//printf("%5i - %-6i - %-5s - %-8s %i/%i \n",matricula[aux].idAluno,matricula[aux].idCurso,matricula[aux].situacaoAluno,matricula[aux].situacaoCurso,matricula[aux].mes,matricula[aux].ano);
				
					//fprintf(stdout,"entrou %i %i ",escolheCurso,escolheAno);
	    	  		//system("cls");
			 		desenhaMoldura(10,10,20,120,AZUL,BRANCO);                                                                          
			   		gotoxy(11,9);
					fprintf(stdout,"%-9.9s %-25.25s%-18.18s %-10.10s %-15.15s %-15.15s %s","MATRICULA","NOME ALUNO ","NOME CURSO","ID CURSO","SITUACAO ALUNO ","SITUACAO CURSO","DATA");
					gotoxy(11,linha);
					linha++;
	    	   		fprintf(stdout,"%-9i%-25.25s %-18.18s %-10i %-15s %-15s  %i/%i \n",matricula[aux].idAluno,matricula[aux].nomeMatriculado,matricula[aux].nomeCursoMatriculado,matricula[aux].idCurso,matricula[aux].situacaoAluno,matricula[aux].situacaoCurso,matricula[aux].mes,matricula[aux].ano);
					cont++;
					
				}
			}
			
		}
		if(cont==0)
		{
			gotoxy(5,5);
			fprintf(stdout,"Nao foi encontrado resultados  \n");	
		}	
		free(matricula);
		
	
	}else
	{
		desenhaMoldura(10,10,14,70,AZUL,BRANCO);
		gotoxy(20,12);
		fprintf(stdout,"Nao foi possivel carregar dados do arquivo ");
	}
	
	
	
	getch();
	system("cls");
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
// Objetivo: monstra apenas os alunos que estao na situaçao PENDENDE
// Parâmetros: nenhum
// Retorno: nenhum
void opcaoPendente()
{
FILE *arqBin;
Matriculas *matricula;
int cont=0, nroAluno=0;
int aux,linha;
int qtdeMatriculas;
	system("cls");
	if((matricula = obtemDadosArquivoMatriculas(&qtdeMatriculas))!=NULL)
	{
		linha=11;
		for(aux=0;aux<qtdeMatriculas;aux++)
		{
			qsort(matricula,qtdeMatriculas,sizeof(Matriculas),comparaNomesMatricula);
			if(stricmp(matricula[aux].situacaoCurso,"PENDENTE")==0)
			{    
			//	qsort(matricula,qtdeMatriculas,sizeof(Matriculas),comparaNomesMatricula);
			//system("cls");
				desenhaMoldura(10,10,20,90,AZUL,BRANCO);
	        	
	        	gotoxy(11,9);
				fprintf(stdout,"%-18s %-6s %-5s %5s %s","NOME","ID CURSO","SITUACAO ALUNO ","SITUACAO CURSO","DATA");
				gotoxy(11,linha);
				linha++;
            	printf("%-18.18s - %-6i - %-5s - %-8s %i/%i \n",matricula[aux].nomeMatriculado,matricula[aux].idCurso,matricula[aux].situacaoAluno,matricula[aux].situacaoCurso,matricula[aux].mes,matricula[aux].ano);
				cont++;
			}
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
int cont=0, nroAluno=0;
int aux,linha;
int qtdeMatriculas;
	system("cls");
	if((matricula = obtemDadosArquivoMatriculas(&qtdeMatriculas))!=NULL)
	{
		linha=11;
		for(aux=0;aux<qtdeMatriculas;aux++)
		{
			qsort(matricula,qtdeMatriculas,sizeof(Matriculas),comparaNomesMatricula);
			if(stricmp(matricula[aux].situacaoCurso,"PAGO")==0)
			{    
			//	qsort(matricula,qtdeMatriculas,sizeof(Matriculas),comparaNomesMatricula);
			//system("cls");
				desenhaMoldura(10,10,20,90,AZUL,BRANCO);
	        	
	        	gotoxy(11,9);
				fprintf(stdout,"%-18s %-6s %-5s %5s %s","NOME","ID CURSO","SITUACAO ALUNO ","SITUACAO CURSO","DATA");
				gotoxy(11,linha);
				linha++;
            	printf("%-18.18s - %-6i - %-5s - %-8s %i/%i \n",matricula[aux].nomeMatriculado,matricula[aux].idCurso,matricula[aux].situacaoAluno,matricula[aux].situacaoCurso,matricula[aux].mes,matricula[aux].ano);
				cont++;
			}
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
int cont=0, nroAluno=0;
int aux,linha;
int qtdeMatriculas;
	system("cls");
	if((matricula = obtemDadosArquivoMatriculas(&qtdeMatriculas))!=NULL)
	{
		linha=11;
		for(aux=0;aux<qtdeMatriculas;aux++)
		{
			qsort(matricula,qtdeMatriculas,sizeof(Matriculas),comparaNomesMatricula);
			if(stricmp(matricula[aux].situacaoCurso,"REGULAR")==0)
			{    
			//	qsort(matricula,qtdeMatriculas,sizeof(Matriculas),comparaNomesMatricula);
			//system("cls");
				desenhaMoldura(10,10,20,90,AZUL,BRANCO);
	        	
	        	gotoxy(11,9);
				fprintf(stdout,"%-18s %-6s %-5s %5s %s","NOME","ID CURSO","SITUACAO ALUNO ","SITUACAO CURSO","DATA");
				gotoxy(11,linha);
				linha++;
            	printf("%-18.18s - %-6i - %-5s - %-8s %i/%i \n",matricula[aux].nomeMatriculado,matricula[aux].idCurso,matricula[aux].situacaoAluno,matricula[aux].situacaoCurso,matricula[aux].mes,matricula[aux].ano);
				cont++;
			}
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
	getch();
	system("cls");
}
//Objetivo: Apresentar os dados presentes em Todos os arquivos.
//Parametros:
//Retorno:
void relatorio1(void)
{
	Cursos *curso;
	Aluno *alunos;
	Matriculas *matricula;
	int cont,linha;
	int qtdeAlunos,qtdeCursos,qtdeMatriculas;
	gotoxy(4,2);
	fprintf(stdout,"DADOS DE ALUNOS ");
	gotoxy(4,3);
	fprintf(stdout,"%-s %-29s%-5s    %5s%5s","MATRICULA","NOME","IDADE","SEXO","CPF");
	desenhaMoldura(4,3,25,79,AZUL,BRANCO);
	if((alunos = obtemDadosArquivoAluno(&qtdeAlunos))!=NULL )
	{
		linha=5;
		for(cont=0;cont<qtdeAlunos;cont++)
		{
			qsort(alunos,qtdeAlunos,sizeof(Aluno),comparaNomeAlunos);
			gotoxy(4,linha);
			fprintf(stdout,"%5i - %-30.30s - %-5i - %-5c %-12.12s\n",alunos[cont].matricula,alunos[cont].nomeAluno,alunos[cont].idade,alunos[cont].sexo,alunos[cont].CPF);
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
		linha=5;
		for(cont=0;cont<qtdeCursos;cont++)
		{
			qsort(curso,qtdeCursos,sizeof(Cursos),comparaNomeCursos);
			gotoxy(4,linha);
			fprintf(stdout,"%5i - %-30.30s - %-5i - %-5.2f \n",curso[cont].codCurso,curso[cont].nomeCurso,curso[cont].horarios,curso[cont].mensalidade);
			linha++;
		}
		free(curso);	
	}
	getch();
	limpaJanela(2,2,25,79,AZUL);
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
			qsort(matricula,qtdeMatriculas,sizeof(Matriculas),comparaNomesMatricula);
			fprintf(stdout,"%-9i%-25.25s %-18.18s %-10i %-15s %-15s  %i/%i \n",matricula[cont].idAluno,matricula[cont].nomeMatriculado,matricula[cont].nomeCursoMatriculado,matricula[cont].idCurso,matricula[cont].situacaoAluno,matricula[cont].situacaoCurso,matricula[cont].mes,matricula[cont].ano);
			linha++;
		}
		free(matricula);
	}

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
	int qtdeAlunos,cont,linha;
	int verificador,aux=0;
	if((alunos = obtemDadosArquivoAluno(&qtdeAlunos))!=NULL)
	{
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
		if((diaDesejado>diaDesejado2) && (mesDesejado>=mesDesejado2) && (anoDesejado>=anoDesejado2) || (diaDesejado<diaDesejado2) && (mesDesejado>=mesDesejado2) && (anoDesejado>=anoDesejado2) 
		|| (diaDesejado>diaDesejado2) && (mesDesejado<=mesDesejado2) && (anoDesejado>=anoDesejado2))
		{
			gotoxy(11,15);
			fprintf(stdout,"A DATA INICIAL DEVE SER MENOR QUE A INICIAL \n");
			getch();
			return;
		}
		verificador=verificaData(diaDesejado2,mesDesejado2,anoDesejado2);
		if(verificador==1)
		{
			gotoxy(11,15);
			apresentaMsgErro("Data Invalida, verifique corretamente ","");
			return;
		}
		linha=4;
		system("cls");
		gotoxy(1,1);
		fprintf(stdout,"PERIODO = %i/%i/%i ate %i/%i/%i ",diaDesejado,mesDesejado,anoDesejado,diaDesejado2,mesDesejado2,anoDesejado2);
		gotoxy(2,2);
		fprintf(stdout,"%-29s%-5s    %5s%5s%23s","NOME","IDADE","SEXO","CPF","DATA INGRESSO");
		desenhaMoldura(3,1,25,90,AZUL,BRANCO);
		for(cont=0;cont<qtdeAlunos;cont++)
		{
			qsort(alunos,qtdeAlunos,sizeof(Aluno),comparaNomeAlunos);
			if((diaDesejado<=alunos[cont].dataDia && diaDesejado2>=alunos[cont].dataDia) && (mesDesejado<=alunos[cont].dataMes && mesDesejado2>=alunos[cont].dataMes) 
			&& (anoDesejado<=alunos[cont].dataAno && anoDesejado2>=alunos[cont].dataAno))
			{
				
				if(alunos[cont].sexo=='F')
				{
					gotoxy(2,linha);
					linha++;
					fprintf(stdout,"%-30.30s - %-4i - FEMININO %-12.12s %i/%i/%i \n",alunos[cont].nomeAluno,alunos[cont].idade,
					alunos[cont].CPF,alunos[cont].dataDia,alunos[cont].dataMes,alunos[cont].dataAno);	
					aux++;
				}else{
					gotoxy(2,linha);
					linha++;
					fprintf(stdout,"%-30.30s - %-4i - MASCULINO %-12.12s %i/%i/%i \n",alunos[cont].nomeAluno,alunos[cont].idade,
					alunos[cont].CPF,alunos[cont].dataDia,alunos[cont].dataMes,alunos[cont].dataAno);
					aux++;
				}
				
				
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
