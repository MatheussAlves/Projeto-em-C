#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "cores.h"
#include "apresentaMensagem.h"
#include "menu.h"
#include "manipulaDados.h"
#include "alteraAlunos.h"
#include "bibliotecaPrototipos.h"
#include "time.h"
#define TAM_TEXTO 60
//Objetivo: Apresentar os alunos cadastrados
//Parametros: nenhum
//Retorno: inteiro com o codigo unico do aluno
int apresentaAlunosV(void)
{
	FILE *arq;
	Aluno alunos;
	char **dados=NULL,**dadosAux, aux[7];
	static char cpfFormatado[15];
	int linha,cont=0,i,qtdeItens,itemSelecionado=0,matriculaSelecionada=0,qtdeAlocada=0,existeErro=0;
	limpaJanela(1,1,25,80,AZUL);
	arq = abreArquivo("dadosAlunos.txt","rb");
	if(arq != NULL)
	{
		gotoxy(5,3);
		fprintf(stdout,"%-s %-29s%-5s    %5s%5s %23s","MATRICULA","NOME","IDADE","SEXO","CPF","DATA INGRESSO");
		while(!feof(arq))
		{
			if(fread(&alunos,sizeof(Aluno),1,arq)==1)
			{
				dadosAux = (char**) realloc(dados,sizeof(char*)* (cont+1));
				if(dadosAux!=NULL)
				{
					dados = dadosAux;
					dados[cont]=(char*) malloc(sizeof(char)*(90+1));
					if(dados[cont]!=NULL)
					{
						sprintf(cpfFormatado,"%3.3s.%3.3s.%3.3s-%2.2s",
           				alunos.CPF,alunos.CPF+3,alunos.CPF+6,alunos.CPF+9);
           				strcpy(alunos.CPF,cpfFormatado);
						sprintf(dados[cont],"%-5i - %-30.30s - %-5i - %-5c %-16.16s %i/%i/%i \n",alunos.matricula,alunos.nomeAluno,alunos.idade,alunos.sexo,alunos.CPF,alunos.dataDia,alunos.dataMes,alunos.dataAno);
						cont++;
					}
				}
			}
		}
		if(cont!=0)
		{
			for(i=0;i<cont;i+=10)
			{
				qtdeItens = cont -i > 15 ? 15: cont-i;
				itemSelecionado = menuVertical(qtdeItens,&dados[i],BRANCO,AZULCLARO,5,5,1,
                1,AZUL,BRANCO);
                if(itemSelecionado!=0)
                {
                	strncpy(aux,dados[i+itemSelecionado-1],6);
                	aux[6]='\0';
                	matriculaSelecionada=atoi(aux);
                	break;
				}
				else
				{
					if(i+10<cont)
					{
						if(respostaSN("Deseja continuar = ")=='N')
						break;
					}
				}
			}
			for(i=0;i<cont;i++){
				free(dados[i]);
			}
			free(dados);
		}
		if(fclose(arq)!=0)
			apresentaMsgErro("Erro ao fechar o arquivo ","apresentaAlunos");
	    } 
		if(cont==0)
		{
			gotoxy(10,10);
			fprintf(stdout,"Nao existem alunos cadastrados ");
			getch();
		}
		return matriculaSelecionada;
		
	/*
	if((alunos = obtemDadosArquivoAluno(&cont))!=NULL)
	{
		if(cont!=0)
		{
			qsort(alunos,cont,sizeof(Aluno),comparaNomeAlunos); //ordena os alunos por nome
			//carrega o menu
			dados = (char**)malloc(sizeof(char*)* (cont+1)); 
			if(dados!=NULL)
			{
				for(i=0;i<cont;i++) // i = auxiliar
				{

					dados[i] = (char**) malloc(sizeof(char)*(TAM_TEXTO+1));
					if(dados[i]!=NULL)
					{
						sprintf(dados[i],"%i - %-30.30s - %-5i - %-5c %-12.12s\n",alunos[i].matricula,alunos[i].nomeAluno,alunos[i].idade,alunos[i].sexo,alunos[i].CPF);
						qtdeAlocada++;
					}
					else
					{
						apresentaMsgErro("Erro ao alocar a memoria ","ApresentaAlunos");
						existeErro=1; // <- flag
					}
				}
				
			}
			else
			{
				apresentaMsgErro("Erro ao alocar memoria","apresentaAlunos");
				existeErro=1;
			}
			free(alunos); //Libera a memoria alocada
			if(!existeErro)
			{
				for(i=0;i<cont;i+=10)
				{
					qtdeItens=cont -i > 10 ? 10: cont-i;
					itemSelecionado = menuVertical(qtdeItens,&dados[i],BRANCO,VERDE,5,5,1,1,AZUL,BRANCO);
					if(itemSelecionado!=0)
					{
						strncpy(aux,dados[i+itemSelecionado-1],6);
						aux[6] = '\0';
						matriculaSelecionada = atoi(aux);
						break;
					}
					else
					{
						if(i+10<cont)
						{
							if(respostaSN("Deseja continuar")=='N')
							break;
						}
					}
				}
			}
			if(dados!=NULL)
			{
				for(i=0;i<qtdeAlocada;i++)
					free(dados[i]);
				free(dados);
			}
		}
		else
		gotoxy(10,10);
		fprintf(stdout,"Nao existe nenhum aluno cadastrado ");
		getch();
	}
	*/
	//return matriculaSelecionada;
}

//Objetivo: Apresentar os cursos cadastrados
//Parametros: nenhum
//Retorno: nenhum
int apresentaCursosV(void)
{
	FILE *arq;
	Cursos curso;
	char **dados=NULL,**dadosAux, aux[7];
	int linha,cont=0,i,qtdeItens,itemSelecionado=0,codigoSelecionado=0,qtdeAlocada=0,existeErro=0;
	limpaJanela(1,1,25,80,AZUL);
	
	
	arq = abreArquivo("dadosCursos.txt","rb");
	if(arq != NULL)
	{
		gotoxy(5,3);
		fprintf(stdout,"%-5.5s %-23.23s %-13.13s %-11.11s","CODIGO","NOME DO CURSO","CARGA HORARIA","MENSALIDADE");
		while(!feof(arq))
		{
			if(fread(&curso,sizeof(Cursos),1,arq)==1)
			{
				dadosAux = (char**) realloc(dados,sizeof(char*)* (cont+1));
				if(dadosAux!=NULL)
				{
					dados = dadosAux;
					dados[cont]=(char*) malloc(sizeof(char)*(TAM_TEXTO+1));
					if(dados[cont]!=NULL)
					{
						sprintf(dados[cont],"%-5i%-23.23s %-13i %-10.2f \n",curso.codCurso,curso.nomeCurso,curso.horarios,curso.mensalidade);
						cont++;
					}
				}
			}
		}
		if(cont!=0)
		{
			for(i=0;i<cont;i+=10)
			{
				qtdeItens = cont -i > 15 ? 15: cont-i;
				itemSelecionado = menuVertical(qtdeItens,&dados[i],BRANCO,AZULCLARO,5,5,1,
                1,AZUL,BRANCO);
                if(itemSelecionado!=0)
                {
                	strncpy(aux,dados[i+itemSelecionado-1],6);
                	aux[6]='\0';
                	codigoSelecionado=atoi(aux);
                	break;
				}
				else
				{
					if(i+10<cont)
					{
						if(respostaSN("Deseja continuar = ")=='N')
						break;
					}
				}
			}
			for(i=0;i<cont;i++){
				free(dados[i]);
			}
			free(dados);
		}
		if(fclose(arq)!=0)
			apresentaMsgErro("Erro ao fechar o arquivo ","apresentaCursos");
	    } 
		if(cont==0)
		{
			gotoxy(10,10);
			fprintf(stdout,"Nao existem cursos cadastrados ! ");
			getch();
		}
		
		
		return codigoSelecionado;
}
//
//
//
void apresentaMatriculas(void)
{
	FILE *arq;
	Matriculas matricula;
	
	arq = fopen("dadosMatriculas.txt","rb");
	if(arq!=NULL)
	{
		while(!feof(arq))
		{
			if(fread(&matricula,sizeof(Matriculas),1,arq)==1)
			{
				printf("%i %i %c %c %i \n ",matricula.idAluno,matricula.idCurso,matricula.situacaoAluno,matricula.situacaoCurso,matricula.mes);
				getch();
			}
		}
		fclose(arq);
	}
}
//Objetivo: Apresentar as matriculas cadastradas
//Parametros: nenhum
//Retorno: nenhum
int apresentaMatriculasV(void)
{
	FILE *arqMatricula;
	FILE *arqCursos;
	FILE *arqAlunos;
	Matriculas matricula;
	Aluno alunos;
	Cursos curso;
	char **nomesAlunosAux;
	char **nomesCursosAux;
	char **dados=NULL,**dadosAux, aux[7];
	char **dadosSit=NULL,**dadosSitAux;
	char **dadosSitCurso=NULL,**dadosSitCursoAux;
	char **nomesCurso=NULL;
	char **nomesAlunos=NULL;
	int linha,cont=0,i,qtdeItens,itemSelecionado=0,codigoSelecionado=0,qtdeAlocada=0,existeErro=0;
	int qtdeAlunos;
	int cont2=0;
	int cont3=0;
	int contadorAux=0;
	int contador=0;
	char *sitAluno,*sitCurso;
	limpaJanela(1,1,25,80,AZUL);
	if((arqMatricula = abreArquivo("dadosMatriculas.txt","rb"))!=NULL){
		while(!feof(arqMatricula))
		{
			if(fread(&matricula,sizeof(Matriculas),1,arqMatricula)==1)
			{
				nomesAlunosAux=(char**) realloc(nomesAlunos,sizeof(char*)*(contador+1));
				if(nomesAlunosAux!=NULL)
				{
					nomesAlunos=nomesAlunosAux;
					nomesAlunos[contador]=(char*)malloc(sizeof(char)*(MAX_NOME+1));
					if(nomesAlunos[contador]!=NULL)
					{
						if((arqAlunos = abreArquivo("dadosAlunos.txt","rb"))!=NULL)          
						{
																									
							while(!feof(arqAlunos))
							{
								if(fread(&alunos,sizeof(Aluno),1,arqAlunos)==1)
								{
									//printf("%i %i ",matricula.idAluno,alunos.matricula);
									
									if(matricula.idAluno==alunos.matricula)
									{
										strcpy(nomesAlunos[contador],alunos.nomeAluno);
										//printf("%s ",nomesAlunos[contador]);
										contador++;
									}
									//printf("%s ",nomesAlunos[contador]);
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
			if(fread(&matricula,sizeof(Matriculas),1,arqMatricula)==1)
			{
				nomesCursosAux=(char**) realloc(nomesCurso,sizeof(char*)*(contadorAux+1));
				if(nomesCursosAux!=NULL)
				{
					nomesCurso=nomesCursosAux;
					nomesCurso[contadorAux]=(char*)malloc(sizeof(char)*(MAX_NOME+1));
					if(nomesCurso[contadorAux]!=NULL)
					{
						if((arqCursos=abreArquivo("dadosCursos.txt","rb"))!=NULL)
						{
							while(!feof(arqCursos))
							{
								if(fread(&curso,sizeof(Cursos),1,arqCursos)==1)
								{
									if(matricula.idCurso==curso.codCurso)
									{
										strcpy(nomesCurso[contadorAux],curso.nomeCurso);
										//printf("%s ",nomesCurso[contadorAux]);
										contadorAux++;
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
		while(!feof(arqMatricula))
		{
			if(fread(&matricula,sizeof(Matriculas),1,arqMatricula)==1)
			{
					dadosSitAux=(char**) realloc(dadosSit,sizeof(char*)*(cont2+1));
					if(dadosSitAux!=NULL)
					{
						dadosSit=dadosSitAux;
						dadosSit[cont2]=(char*)malloc(sizeof(char)*(TAM_SITUACAO+1));
						if(dadosSit[cont2]!=NULL)
						{
							//printf("%c ",matricula.situacaoAluno);
							if(matricula.situacaoAluno=='C')
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
						
						
							if(matricula.situacaoCurso=='R')
							{
								strcpy(dadosSitCurso[cont3],"REGULAR");
							}else
							{
								if(matricula.situacaoCurso=='P')
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

	
	arqMatricula = abreArquivo("dadosMatriculas.txt","rb");
	if(arqMatricula != NULL)
	{
		cont2=0;
	
		gotoxy(5,3);
		fprintf(stdout,"%-9.9s %-25.25s%-18.18s %-10.10s %-15.15s %-15.15s %s","ID CURSO","NOME CURSO","NOME ALUNO","MATRICULA","MATRICULA","SITUACAO CURSO","DATA");
		while(!feof(arqMatricula))
		{
			
			if(fread(&matricula,sizeof(Matriculas),1,arqMatricula)==1)
			{
				//printf("Entrou ! \n");
				dadosAux = (char**) realloc(dados,sizeof(char*)* (cont+1));
				if(dadosAux!=NULL)
				{
					dados = dadosAux;
					dados[cont]=(char*) malloc(sizeof(char)*(110+1));
					if(dados[cont]!=NULL)
					{
						sprintf(dados[cont],"%-9i%-25.25s %-18.18s %-10i %-15s %-15s   %i/%i \n",matricula.idCurso,nomesCurso[cont2],nomesAlunos[cont2],matricula.idAluno,dadosSit[cont2],dadosSitCurso[cont2],matricula.mes,matricula.ano);
						cont++;
						cont2++;
					}
				}
			}
		}
		if(cont!=0)
		{
			for(i=0;i<cont;i+=10)
			{
				qtdeItens = cont -i > 25 ? 25: cont-i;
				itemSelecionado = menuVertical(qtdeItens,&dados[i],BRANCO,AZULCLARO,5,5,1,
                1,AZUL,BRANCO);
                if(itemSelecionado!=0)
                {
                	strncpy(aux,dados[i+itemSelecionado-1],6); //Pega o codigo do curso ou aluno
                	aux[6]='\0';
                	codigoSelecionado=atoi(aux); //transforma o codigo em Inteiro
                	break;
				}
				else
				{
					if(i+10<cont)
					{
						if(respostaSN("Deseja continuar = ")=='N')
						break;
					}
				}
			}
			for(i=0;i<cont;i++){
				free(dados[i]);
			}
			free(dados);
		
		}
		if(fclose(arqMatricula)!=0)
			apresentaMsgErro("Erro ao fechar o arquivo ","apresentaMatriculas");
	    } 
		if(cont==0)
		{
			gotoxy(10,10);
			fprintf(stdout,"Nao existem matriculas cadastradas ! ");
			getch();
		}
		free(nomesAlunos);
		free(nomesCurso);
		free(dadosSit);
		free(dadosSitCurso);
		return codigoSelecionado;
}
//
//
//
void recuperaDescricao(char **nomesAlunos,char **nomesCurso)
{
	FILE *arqMatricula;
	FILE *arqCursos;
	FILE *arqAlunos;
	int cont=0;
	int aux=0;
	Matriculas matricula;
	Aluno alunos;
	Cursos curso;
	char **nomesAlunosAux;
	char **nomesCursosAux;
	
	if((arqMatricula = abreArquivo("dadosMatriculas.txt","rb"))!=NULL){
		while(!feof(arqMatricula))
		{
			if(fread(&matricula,sizeof(Matriculas),1,arqMatricula)==0)
			{
				nomesAlunosAux=(char**) realloc(nomesAlunos,sizeof(char*)*(cont+1));
				if(nomesAlunosAux!=NULL)
				{
					nomesAlunos=nomesAlunosAux;
					nomesAlunos[cont]=(char*)malloc(sizeof(char)*MAX_NOME+1);
					if(nomesAlunos[cont]!=NULL)
					{
						if((arqAlunos = abreArquivo("dadosAlunos.txt","rb"))!=NULL)           //<<<<- pega  o numero do aluno e compara com o ID da mattricula
						{																	//<<<<<- se forem iguais ele copia o nome do aluno., para o ponteiro.			
							while(!feof(arqAlunos))
							{
								if(fread(&alunos,sizeof(Aluno),1,arqAlunos)==1)
								{
									if(matricula.idAluno==alunos.matricula)
									{
										strcpy(nomesAlunos[cont],alunos.nomeAluno);
									}
									cont++;
								}
							}
							fclose(arqAlunos);
						}
					}
				}
				nomesCursosAux=(char**) realloc(nomesCurso,sizeof(char*)*(aux+1));
				if(nomesCursosAux!=NULL)
				{
					nomesCurso=nomesCursosAux;
					nomesCurso[aux]=(char*)malloc(sizeof(char)*MAX_NOME+1);
					if(nomesCurso[aux]!=NULL)
					{
						if((arqCursos=abreArquivo("dadosCursos.txt","rb"))!=NULL)
						{
							while(!feof(arqCursos))
							{
								if(fread(&curso,sizeof(Aluno),1,arqCursos)==1)
								{
									if(matricula.idCurso==curso.codCurso)
									{
										strcpy(nomesCurso[aux],curso.nomeCurso);
									}
									aux++;
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
}
// Objetivos:  le os dados dos alunos existentes colocando na memória com alocação dinâmica
// parâmetros:  endereço de memória para guardar a qtde de alunos recuperada
// retorno:  endereço de memória onde localiza-se os dados recuperados ou NULL
Aluno * obtemDadosArquivoAluno(int *qtde)
{
FILE *arq;
Aluno *alunos=NULL;
int i;

    if((arq = abreArquivo("dadosAlunos.txt","rb")) != NULL)
    {
        if(fseek(arq,0,SEEK_END)==0)
        {
           *qtde= ftell(arq)/sizeof(Aluno);
           alunos = (Aluno*) malloc(*qtde * sizeof(Aluno));
           if(alunos == NULL)
           {
               apresentaMsgErro("Erro de alocacao","memoria");
           }                      
           else
           {
             rewind(arq);           
             if(fread(alunos,sizeof(Aluno),*qtde,arq)!=*qtde)
             {
                 apresentaMsgErro("Erro de leitura","LEITURA");
                 free(alunos);
                 alunos = NULL;
             }             
           }           
        }
       if(fclose(arq) != 0)
       {
           apresentaMsgErro("Erro ao fechar arquivo","obtemDadosArquivoAluno");
        }    
                
    }
    return alunos;
}
//Objetivos: le os dados dos cursos cadastrados e coloca na memoria por meio da alocaçao dinamica
//Parametros: endereco de memoria da quantidade de cursos recuperada
//Retorno: endereco de memoria onde localiza-se os dados ou NULL
Cursos * obtemDadosArquivoCursos(int *qtde)
{
FILE *arq;
Cursos *curso=NULL;
int i; //<- CONTADOR

    if((arq = abreArquivo("dadosCursos.txt","rb")) != NULL)
    {
        if(fseek(arq,0,SEEK_END)==0)
        {
           *qtde= ftell(arq)/sizeof(Cursos);
           curso = (Cursos*) malloc(*qtde * sizeof(Cursos));
           if(curso == NULL)
           {
               apresentaMsgErro("Erro de alocacao","memoria");
           }                      
           else
           {
             rewind(arq);           
             if(fread(curso,sizeof(Cursos),*qtde,arq)!=*qtde)
             {
                 apresentaMsgErro("Erro de leitura","LEITURA");
                 free(curso);
                 curso = NULL;
             }             
           }           
        }
       if(fclose(arq) != 0)
       {
           apresentaMsgErro("Erro ao fechar arquivo","Cursos");
        }    
                
    }
    return curso;
}
//Objetivos: le os dados das matriculas cadastrados e coloca na memoria por meio da alocaçao dinamica
//Parametros: endereco de memoria da quantidade de matriculas recuperada
//Retorno: endereco de memoria onde localiza-se os dados ou NULL
Matriculas * obtemDadosArquivoMatriculas(int *qtde)
{
FILE *arq;
Matriculas *matricula=NULL;
int i; //<- CONTADOR

    if((arq = abreArquivo("dadosMatriculas.txt","rb")) != NULL)
    {
        if(fseek(arq,0,SEEK_END)==0)
        {
           *qtde= ftell(arq)/sizeof(Matriculas);
           matricula = (Matriculas*) malloc(*qtde * sizeof(Matriculas));
           if(matricula == NULL)
           {
               apresentaMsgErro("Erro de alocacao","memoria");
           }                      
           else
           {
             rewind(arq);           
             if(fread(matricula,sizeof(Matriculas),*qtde,arq)!=*qtde)
             {
                 apresentaMsgErro("Erro de leitura","LEITURA");
                 free(matricula);
                 matricula = NULL;
             }             
           }           
        }
       if(fclose(arq) != 0)
       {
           apresentaMsgErro("Erro ao fechar arquivo","Matriculas");
        }    
                
    }
    return matricula;
}
//Objetivos: exclui os dados de um aluno do arquivo
//parâmetros : nenhum
//retorno : nenhum
void excluiAluno()
{
	Aluno alunos;
	int seq,seq2,existeErro;
	char *msg;
	
	alunos.matricula=apresentaAlunosV();
	desenhaMoldura(10,10,18,70,AZUL,BRANCO);
	if(alunos.matricula<=0)
		return;
		
	seq = obtemMatriculaAluno(alunos.matricula);
	seq2=obtemAlunoMatriculado(alunos.matricula);
	if(seq2!=0)
	{
		gotoxy(11,12);
		fprintf(stdout,"ALUNO JA ESTA MATRICULADO, PORTANTO NAO PODE SER EXCLUIDO");
		getch();
		return;
	}
	if(seq!=0)
	{
		if(leDadosAlunoPesquisado(seq,&alunos))
		{
			gotoxy(11,12);
			fprintf(stdout,"%i - %s - %c - %i - %s\n",alunos.matricula,alunos.nomeAluno,alunos.sexo,alunos.idade,alunos.CPF);
			gotoxy(11,13);
			if(respostaSN("Confirma ")=='S')
			{
				msg=excluiRegArq("dadosAlunos.txt",sizeof(Aluno),seq,&existeErro);
				if(!existeErro)
				{
					gotoxy(11,14);
					fprintf(stdout,"Exclusao realizada com sucesso");
				}
				else
				{
					apresentaMsgErro(msg,"Exclui aluno");
				}
			}
		}
	}
	else
	{
		gotoxy(11,13);
		fprintf(stdout,"Aluno nao cadastrado \n");
	}
	getch();
	
	
	
	
}
//
//
//
int obtemAlunoMatriculado(int cadastro)
{

FILE *arqBin;
Matriculas matricula;
int seq=0, cont=0;
	if((arqBin=fopen("dadosMatriculas.txt","rb"))!=NULL){
		while(!feof(arqBin)){
			if(fread(&matricula,sizeof(Matriculas),1,arqBin)==1){
				cont++;
				if(cadastro==matricula.idAluno){
                    seq = cont;
					break;
				}
			}
		}
		fclose(arqBin);
	}else
	{
		printf("Arquivo nao encontrado...");
	}
	return seq;

}
//Objetivos: exclui os dados de um aluno do arquivo
//parâmetros : nenhum
//retorno : nenhum
void excluiCursos(void)
{
	Cursos curso;
	int seq,existeErro;
	char *msg;
	
	curso.codCurso=apresentaCursosV();
	desenhaMoldura(10,10,18,70,AZUL,BRANCO);
	if(curso.codCurso<=0)
		return;
		
	seq = obtemCodigoCurso(curso.codCurso);
	if(seq!=0)
	{
		if(leDadosCurso(seq,&curso))
		{
			gotoxy(11,12);
			fprintf(stdout,"%i - %s - %i - %.2f \n",curso.codCurso,curso.nomeCurso,curso.horarios,curso.mensalidade);
			gotoxy(11,13);
			if(respostaSN("Confirma ")=='S')
			{
				msg=excluiRegArq("dadosCursos.txt",sizeof(Cursos),seq,&existeErro);
				if(!existeErro)
				{
					gotoxy(11,14);
					fprintf(stdout,"Exclusao realizada com sucesso");
				}
				else
				{
					apresentaMsgErro(msg,"Exclui curso");
				}
			}
		}
	}
	else
	{
		gotoxy(11,13);
		fprintf(stdout,"Curso nao foi cadastrado \n");
	}
	getch();
}
// Objetivos - abre um arquivo qualquer
// parâmetros - endereço de memória onde localiza-se o nome do arquivo e  endereço de memória do modo de abertura do arquivo
// retorno - endereço de memória onde localiza-se a estrutura  ou NULL 
FILE * abreArquivo(char *nomeArq,char *modo)
{
FILE *arq;
   arq = fopen(nomeArq,modo);
   if(arq == NULL)
   {
      fprintf(stdout,"Erro ao abrir o arquivo \n");
   }
   return arq;
}
// Objetivos : compara os dados a serem ordenados pela qsort
// parâmetros : endereço para os elementos a serem pesquisados na ordenação
// retorno : =0 --> dados iguais
//           >0 --> dados desordenados
//           <0 --> dados ordenados 
int comparaNomeAlunos(const void * p1, const void *p2)
{
Aluno *aluno1,*aluno2;

  aluno1 = (Aluno*)p1;
  aluno2 = (Aluno*) p2;
  return stricmp((*aluno1).nomeAluno,(*aluno2).nomeAluno); 
}
// Objetivos : compara os dados a serem ordenados pela qsort
// parâmetros : endereço para os elementos a serem pesquisados na ordenação
// retorno : =0 --> dados iguais
//           >0 --> dados desordenados
//           <0 --> dados ordenados
int comparaNomeCursos(const void * p1, const void *p2)
{
Cursos *curso1,*curso2;

  curso1 = (Cursos*)p1;
  curso2 = (Cursos*) p2;
  return stricmp((*curso1).nomeCurso,(*curso2).nomeCurso); 
}
// Objetivos : compara os dados a serem ordenados pela qsort
// parâmetros : endereço para os elementos a serem pesquisados na ordenação
// retorno : =0 --> dados iguais
//           >0 --> dados desordenados
//           <0 --> dados ordenados
/*int comparaNomesMatricula(const void * p1, const void *p2)
{
Matriculas *matricula1,*matricula2;

  matricula1 = (Matriculas*)p1;
  matricula2 = (Matriculas*)p2;
  return stricmp((*matricula1).nomeMatriculado,(*matricula2).nomeMatriculado); 
}*/

//objetivo: verificar se uma resposta foi S ou N
//parametros: referencia a string de pergunta.
//retorno:
char respostaSN(char *perg)
{
char resp;
   do
   {
      fprintf(stdout," %s S/N?",perg);
      resp = toupper(getch());
   }while(resp != 'S' && resp != 'N');
   return resp;
}
//Objetivo: alterar dados de um aluno em um arquivo
//Parametros:nenuhm
//retorno:nenhum
void alteraAlunos(void)
{
	FILE *arq;
	Aluno alunos;
	int seq,verificador;
	char opcao;
	alunos.matricula=apresentaAlunosV();
	system("cls");
	desenhaMoldura(10,10,18,70,AZUL,BRANCO);
	if(alunos.matricula <=0 )
	{
		return;
	}
	seq = obtemMatriculaAluno(alunos.matricula);

	if(seq != 0)
	{
		if(leDadosAlunoPesquisado(seq,&alunos))
		{
			arq = abreArquivo("dadosAlunos.txt","r+b");
			if(arq!=NULL)
			{
				gotoxy(11,12);
				fprintf(stdout,"%i - %s - %c - %i - %s\n",alunos.matricula,alunos.nomeAluno,alunos.sexo,alunos.idade,alunos.CPF);
				gotoxy(11,13);
				if(respostaSN("Confirma ")=='S')
				{
					gotoxy(11,13);
					opcao=leValidaCaracter("A - Altera nome  S - altera sexo C - altera CPF ","ASC",13,11);
					gotoxy(11,14);
					//limpaJanela(11,13,18,70,AZUL);
					fprintf(stdout,"Informe os novos dados \n");
					gotoxy(11,15);
					if(opcao=='A')
					{
						leValidaTexto("NOME - ",alunos.nomeAluno,MAX_NOME,11,15);
					}else{
						if(opcao=='S')
						{
							alunos.sexo=leValidaCaracter("SEXO - ","MF",15,11);
						}else{
							 do{
  								verificador=1;
								leValidaTexto("CPF - ",alunos.CPF,TAM_CPF,11,13);
								verificador=validaCPF(alunos.CPF);
								if(verificador==0)
								{
									apresentaMsgErro("CPF INVALIDO INFORME NOVAMENTE ","ERRO");
								}
							}while(verificador==0);
							formataCPF(alunos.CPF);
						}
						
						
					}
					if(fseek(arq,(seq-1)*sizeof(Aluno),SEEK_SET)==0)
					{
						if(fwrite(&alunos,sizeof(Aluno),1,arq)==1)
						{
							gotoxy(11,16);
							fprintf(stdout,"Alteracao realizada com sucesso \n");
							getch();
						}
						else{
							apresentaMsgErro("Erro ao gravar os dados ","Alteracao");
						}	
					}
					else{
						apresentaMsgErro("Erro ao posicionar o arquivo ","altera");
					}
					
				}
			}
			if(fclose(arq)!=0)
			{
				apresentaMsgErro("Erro ao fechar o arquivo","Altera Aluno");
			}
		}
		
		
	}
	else
	{
		gotoxy(11,13);
		fprintf(stdout,"Aluno nao cadastrado ");
		getch();
	}
	
		
	
	
	
	
}
//Objetivo: alterar dados de um curso em um arquivo
//Parametros:nenuhm
//retorno: nenhum
void alteraCursos(void)
{
	FILE *arq;
	Cursos curso;
	int seq;
	char opcao;
	curso.codCurso=apresentaCursosV();
	desenhaMoldura(10,10,18,80,AZUL,BRANCO);
	if(curso.codCurso <=0 )
	{
		return;
	}
	seq = obtemCodigoCurso(curso.codCurso);

	if(seq != 0)
	{
		if(leDadosCurso(seq,&curso))
		{
			arq = abreArquivo("dadosCursos.txt","r+b");
			if(arq!=NULL)
			{
				
				gotoxy(11,12);
				fprintf(stdout,"%i - %s - %i - %.2f \n",curso.codCurso,curso.nomeCurso,curso.horarios,curso.mensalidade);
				gotoxy(11,13);
				if(respostaSN("Confirma ")=='S')
				{
					gotoxy(11,13);
					opcao=leValidaCaracter("N - Alterar nome  H - altera altera horario M - altera mensalidade ","NHM",13,11);
					gotoxy(11,14);
					fprintf(stdout,"Informe os novos dados \n");
					gotoxy(11,15);
					if(opcao=='N')
					{
						leValidaTexto("NOME - ",curso.nomeCurso,MAX_NOME,11,15);
					}else{
						if(opcao=='H')
						{
							curso.horarios=leInt("HORARIO - ",20,220,11,15);
						}else{
							curso.mensalidade=leFloat("MENSALIDADE - ",50,9999,11,15);
						}
					}
					if(fseek(arq,(seq-1)*sizeof(Cursos),SEEK_SET)==0)
					{
						if(fwrite(&curso,sizeof(Cursos),1,arq)==1)
						{
							gotoxy(11,16);
							fprintf(stdout,"Alteracao realizada com sucesso \n");
							getch();
						}
						else{
							apresentaMsgErro("Erro ao gravar os dados ","Alteracao");
						}	
					}
					else{
						apresentaMsgErro("Erro ao posicionar o arquivo ","altera");
					}
					
				}
			}
			if(fclose(arq)!=0)
			{
				apresentaMsgErro("Erro ao fechar o arquivo","Altera Curso");
			}
		}
		
		
	}
	else
	{
		gotoxy(11,13);
		fprintf(stdout,"Curso nao cadastrado ");
		getch();
	}
	
		
	
	
	
	
}
// Objetivo: ler os dados de um curso a partir de um numero obtido.
// Parâmetros: número do curso, endereço de uma estrutura
// Retorno : 0 - erro ou 1 ok 
int leDadosCurso(int nroCurso, Cursos *curso)
{
FILE *arqBin;
int flag=0;

	if((arqBin=fopen("dadosCursos.txt","rb"))!=NULL){	
        if(fseek(arqBin,sizeof(Cursos)*(nroCurso-1),SEEK_SET) ==0)
        {
        	if(fread(curso,sizeof(Cursos),1,arqBin) ==1)
        	{
                flag=1;
            }
        }
        fclose(arqBin);
    }
    return flag;
}
// Objetivo: recuperar o número de um aluno pela matrícula
// Parâmetros: matricula
// Retorno: 0 - nao existe ou 1..n - número do aluno
int obtemMatriculaAluno(int matricula)
{

FILE *arqBin;
Aluno dadosAlunos;
int cont=0, nroFunc=0;
	if((arqBin=fopen("dadosAlunos.txt","rb"))!=NULL){
		while(!feof(arqBin)){
			if(fread(&dadosAlunos,sizeof(Aluno),1,arqBin)==1){
				cont++;
				if(matricula==dadosAlunos.matricula){
                    nroFunc=cont;
					break;
				}
			}
		}
		fclose(arqBin);
	}
	return nroFunc;
}
// Objetivo: recuperar o número de um aluno pela matrícula
// Parâmetros: matricula
// Retorno: 0 - nao existe ou 1..n - número do aluno
int obtemCadastroMatricula(int cadastro)
{

FILE *arqBin;
Matriculas matricula;
int seq=0, cont=0;
	if((arqBin=fopen("dadosMatriculas.txt","rb"))!=NULL){
		while(!feof(arqBin)){
			if(fread(&matricula,sizeof(Matriculas),1,arqBin)==1){
				cont++;
				if(cadastro==matricula.idCurso){
                    seq = cont;
					break;
				}
			}
		}
		fclose(arqBin);
	}else
	{
		printf("Arquivo nao encontrado...");
	}
	return seq;
}
//Objetivo: Recuperar o codigo do aluno , a partir do seu nome.
//Parametros: nome.
//Retorno: 0 se nao exisitr, ou o numero do aluno.
int obtemNomeMatricula(char *texto)
{
	FILE *arqBin;
	Matriculas matricula;
	Aluno alunos;
	int cont=0,aux=0;
	int seq=0;
	int idAluno=0;
	if((arqBin=fopen("dadosAlunos.txt","rb"))!=NULL)
	{
		while(!feof(arqBin))
		{
			if(fread(&alunos,sizeof(Aluno),1,arqBin)==1)
			{
				if(stricmp(texto,alunos.nomeAluno)==1)
				{
					printf("%s ",alunos.nomeAluno);
					idAluno = alunos.matricula;
					
				}
			}	
		}
		fclose(arqBin);
	}
	if((arqBin=fopen("dadosMatriculas.txt","rb"))!=NULL)
	{
		while(!feof(arqBin))
		{
			if(fread(&matricula,sizeof(Matriculas),1,arqBin)==1)
			{
				aux++;
				if(idAluno==matricula.idAluno){
					seq = aux;
					break;
				}
			}
		}
		fclose(arqBin);
	}
	printf("%i ",seq);
	return seq;
}
// Objetivo: recuperar o numero de um curso pelo codigo
// Parâmetros: codigo
// Retorno: 0 - nao existe ou 1..n - número do aluno
int obtemCodigoCurso(int codigo)
{

FILE *arqBin;
Cursos curso;

int cont=0, nroFunc=0;

	if((arqBin=fopen("dadosCursos.txt","rb"))!=NULL){
		while(!feof(arqBin)){
			if(fread(&curso,sizeof(Cursos),1,arqBin)==1){
				cont++;
				if(codigo==curso.codCurso){
                    nroFunc=cont;
					break;
				}
			}
		}
		fclose(arqBin);
	}
	return nroFunc;
}
// Objetivo: ler os dados de um aluno a partir de um numero obtido.
// Parâmetros: número do aluno, endereço de uma estrutura
// Retorno : 0 - erro ou 1 ok 
int leDadosAlunoPesquisado(int nroAluno, Aluno *dadosAlunos)
{
FILE *arqBin;
int flag=0;

	if((arqBin=fopen("dadosAlunos.txt","rb"))!=NULL){	
        if(fseek(arqBin,sizeof(Aluno)*(nroAluno-1),SEEK_SET) ==0)
        {
        	if(fread(dadosAlunos,sizeof(Aluno),1,arqBin) ==1)
        	{
                flag=1;
            }
        }
        fclose(arqBin);
    }
    return flag;
}
//Objetivo:le e validar um caracter
//Parametros:referencia ao titulo, referencia as opcoes,linha e coluna 
//Retorno:letra
char leValidaCaracter(char *titulo,char *opcoes,int linha,int coluna)
{
	
	char letra;
	int flag;
	
	do
	{
		flag=0;
		fflush(stdin);
        gotoxy(coluna,linha);
        clreol();
        fflush(stdin);
        gotoxy(coluna,linha);
		printf("%s",titulo);
		fflush(stdin);
		letra=getch();
		letra=toupper(letra);
		fflush(stdin);
		
		if(strchr(opcoes,letra)==NULL)
		{
			
			flag=1;
			apresentaMsgErro("CARACTER INVALIDO ! ","ERRO");
			
		}
	}while(flag);
	
	
	return letra;
}

//Objetivo: Obter a hora e a data Atual
//Parametros: referencia a hora,minutos,dia,mes,ano.
//Retorno: horarios resgatados do sistema
void obtemData(int *mes, int *ano)
{
   time_t t;
   struct tm *dataAtual;
   t = time(NULL);
   dataAtual = localtime(&t);
   *mes    =dataAtual->tm_mon+1;
   *ano    =1900+dataAtual->tm_year;
   
}
// Objetivo : gerar um nhumero de codigo para o curso aleatorio
// parâmetros : nenhum
// retorno : nenhum
int geraCodigoAleatorio(void)
{
   int codigoCurso;
   int flag;
   do{
   	flag=0;
   		codigoCurso = (rand());
   		if(codigoCurso<MIN_COD || codigoCurso>MAX_COD)
   		{
   			codigoCurso = (rand());	
   		}else
		{
   			flag = 1; 
		}
	}while(flag==0);
 	 //printf(" Numero do codigo do curso : %i",codigoCurso);
 	 return codigoCurso;
}
//Objetivo:Pesquisar matriculas dos alunos 
//Parametros:nenhum.
//Retorno: 
void pesquisaMatriculas()
{
	FILE *arqMatriculas;
	Matriculas matriculas;
	Aluno alunos;
	Cursos curso;
	FILE *arqAlunos; 
	FILE *arqCursos;
	int matriculaPesquisada;
	int flag=0;
	int contMatriculas;
	char nomeAluno[MAX_NOME];
	char nomeCurso[MAX_NOME];
	char sitAluno[TAM_SITUACAO];
	char sitCurso[TAM_SITUACAO];
	desenhaMoldura(8,10,20,120,AZUL,BRANCO);
	gotoxy(11,11);
	matriculaPesquisada = leInt("informe a matricula desejada = ",MIN_MATRICULA,MAX_MATRICULA,11,11);
	if((contMatriculas = obtemCadastroMatricula(matriculaPesquisada))==0)
	{
		gotoxy(11,12);
		fprintf(stdout,"Essa matricula nao foi encontrada \n ");
		getch();
		system("cls");
		return;
	}
	else
	{
		if(leMatriculaPesquisada(contMatriculas,&matriculas)==1)
		{
			if((arqAlunos=abreArquivo("dadosAlunos.txt","rb"))!=NULL)
			{
				while(!feof(arqAlunos))
				{
					if(fread(&alunos,sizeof(Aluno),1,arqAlunos)==1)
					{
						if(matriculas.idAluno==alunos.matricula)
						{
							strcpy(nomeAluno,alunos.nomeAluno);
						}
					}
				}
				fclose(arqAlunos);
			}
			if((arqCursos=abreArquivo("dadosCursos.txt","rb"))!=NULL)
			{
				while(!feof(arqCursos))
				{
					if(fread(&curso,sizeof(Cursos),1,arqCursos)==1)
					{
						if(matriculas.idCurso==curso.codCurso)
						{
							strcpy(nomeCurso,curso.nomeCurso);
						}
					}
				}
				fclose(arqCursos);
			}
			if(matriculas.situacaoAluno=='C')
			{
				strcpy(sitAluno,"CURSANDO");
			}else
			{
				strcpy(sitAluno,"CONCLUIDO");
			}
			if(matriculas.situacaoCurso=='F')
			{
				strcpy(sitCurso,"PAGO");
			}else
			{
				if(matriculas.situacaoCurso=='P')
				{
					strcpy(sitCurso,"PENDENTE");
				}else{
					strcpy(sitCurso,"REGULAR");
				}
			}
			gotoxy(11,11);
			fprintf(stdout,"%-9.9s %-25.25s%-18.18s %-10.10s %-15.15s %-15.15s %s","MATRICULA","NOME ALUNO ","NOME CURSO","ID CURSO","SITUACAO ALUNO ","SITUACAO CURSO","DATA");
			gotoxy(11,12);
			fprintf(stdout,"%-9i%-25.25s %-18.18s %-10i %-15s %-15s  %i/%i \n",matriculas.idAluno,nomeAluno,nomeCurso,matriculas.idCurso,sitAluno,sitCurso,matriculas.mes,matriculas.ano);
			gotoxy(11,13);
			printf("  data de ingresso = %i/%i \n",matriculas.mes,matriculas.ano);
			gotoxy(11,14);
			printf("____________________________________________________________\n");
			getch();

		}
		else
		{
			printf("Erro ao ler os dados do arquivo ! \n");
			getch();
		}
	}
	system("cls");
}
// Objetivo: ler os dados de uma matricula 
// Parâmetros: número do aluno, endereço de uma estrutura
// Retorno : 0 - erro ou 1 ok 
int leMatriculaPesquisada(int seq, Matriculas *matriculas)
{
FILE *arq;
int retorno=1;
	
	if((arq = abreArquivo("dadosMatriculas.txt","rb"))!=NULL)
	{
		if(fseek(arq,(seq-1)*sizeof(Matriculas),SEEK_SET) == 0)
		{
			if(fread(matriculas,sizeof(Matriculas),1,arq)!=1)
			{
				apresentaMsgErro("Erro na leitura de uma das matriculas","matriculas");
				retorno=0;
			}
		}
		else
		{
			apresentaMsgErro("Erro no posicionamento do arquivo para leitura ","matriculas");
			retorno =0;
		}
		if(fclose(arq)!=0)
		{
			apresentaMsgErro("Erro ao fechar o arquivo para leitura","matriculas");
		}
	}
	return retorno;
}
//Objetivo: Alterar uma matricula selecionada pelo usuario
//Parametros: nenhum
//retorno: nenhum
void alteraMatriculas(void)
{
	
	FILE *arq;
	Matriculas matricula;
	Matriculas *matriculaRepetida;
	int qtdeMatriculas;
	int seq,verificador,cont;
	char opcao;
	char sitAluno[TAM_SITUACAO];
	char sitCurso[TAM_SITUACAO];
	matricula.idCurso=apresentaMatriculasV();
	desenhaMoldura(10,10,18,80,AZUL,BRANCO);
	if(matricula.idAluno <=0 )
	{
		return;
	}
	seq = obtemCadastroMatricula(matricula.idCurso);
	if(seq != 0)
	{
		if(leMatriculaPesquisada(seq,&matricula))
		{
			arq = abreArquivo("dadosMatriculas.txt","r+b");
			if(arq!=NULL)
			{
				if(matricula.situacaoAluno=='C')
				{
					strcpy(sitAluno,"CURSANDO");
				}else
				{
					strcpy(sitAluno,"CONCLUIDO");
				}
				if(matricula.situacaoCurso=='F')
				{
					strcpy(sitCurso,"PAGO");
				}else
				{
					if(matricula.situacaoCurso=='P')
					{
						strcpy(sitCurso,"PENDENTE");
					}else{
						strcpy(sitCurso,"REGULAR");
					}
				}
				gotoxy(11,12);
				fprintf(stdout,"%i - %i - %s -  %s - %i/%i \n",matricula.idAluno,matricula.idCurso,sitAluno,sitCurso,matricula.mes,matricula.ano);
				gotoxy(11,13);
				if(respostaSN("Confirma ")=='S')
				{
					gotoxy(11,13);
					opcao=leValidaCaracter("A - Altera situacao Aluno  S - Altera situacao curso = ","ASC",13,11);
					gotoxy(11,14);
					fprintf(stdout,"Informe os novos dados \n");
					gotoxy(11,15);
					if(opcao=='A')
					{
						matricula.situacaoAluno=leValidaCaracter("Situacao do aluno ( C - cursando F - concluido)","CF",15,11);
						
					
						if((matriculaRepetida = obtemDadosArquivoMatriculas(&qtdeMatriculas))!=NULL)
						{
							for(cont=0;cont<qtdeMatriculas;cont++)
							{
								if(matricula.idAluno==matriculaRepetida[cont].idAluno && matriculaRepetida[cont].situacaoAluno=='C' && matricula.situacaoAluno=='C' )
								{
									gotoxy(11,16);
									fprintf(stdout,"O aluno so pode estar cursando 1 curso por vez ");
									getch();
									return;
								}
							}
							free(matriculaRepetida);
						
						}	
					}else{
						if(opcao=='S')
						{
							matricula.situacaoCurso=leValidaCaracter("Situacao do curso (R - regular - P pendente - F pago) ","RPF",15,11);
								
						}
					}
					if(fseek(arq,(seq-1)*sizeof(Matriculas),SEEK_SET)==0)
					{
						if(fwrite(&matricula,sizeof(Matriculas),1,arq)==1)
						{
							gotoxy(11,16);
							fprintf(stdout,"Alteracao realizada com sucesso \n");
							getch();
						}
						else{
							apresentaMsgErro("Erro ao gravar os dados ","Alteracao");
						}	
					}
					else{
						apresentaMsgErro("Erro ao posicionar o arquivo ","altera");
					}
					
				}
			}
			if(fclose(arq)!=0)
			{
				apresentaMsgErro("Erro ao fechar o arquivo","Altera matricula");
			}
		}
		
		
	}
	else
	{
		gotoxy(11,13);
		fprintf(stdout,"matricula nao cadastrada ");
		getch();
	}
	/*
	matricula.idAluno=apresentaMatriculasV();
	desenhaMoldura(10,10,18,80,AZUL,BRANCO);
	if(matricula.idAluno <=0 )
	{
		return;
	}
	
	seq = obtemCadastroMatricula(matricula.idAluno);
	if(seq != 0)
	{
		//fprintf(stdout,"ENTROU %i \n",seq);
		//	getch();
		if(leMatriculaPesquisada(seq,&matricula))
		{
			
			arqMatricula = abreArquivo("dadosMatriculas.txt","r+b");
			//printf("%s",arq);
			if(arqMatricula!=NULL)
			{
				gotoxy(11,12);
				fprintf(stdout,"%i - %i - %s -  %s - %i/%i \n",matricula.idAluno,matricula.idCurso,matricula.situacaoAluno,matricula.situacaoCurso,matricula.mes,matricula.ano);
				gotoxy(11,13);
				if(respostaSN("Confirma ")=='S')
				{
					gotoxy(11,13);
					opcao=leValidaCaracter("A - Altera situacao Aluno  S - Altera situacao curso = ","ASC",13,11);
					gotoxy(11,14);
					fprintf(stdout,"Informe os novos dados \n");
					gotoxy(11,15);
					if(opcao=='A')
					{
						sitAluno=leValidaCaracter("Situacao do aluno ( C - cursando F - concluido)","CF",15,11);
						if(sitAluno=='C')
						{
							strcpy(matricula.situacaoAluno,"CURSANDO");
						}else
						{
							strcpy(matricula.situacaoAluno,"CONCLUIDO");
						}
					}else{
						if(opcao=='S')
						{
							sitCurso=leValidaCaracter("Situacao do curso (R - regular - P pendente - F pago) ","RPF",15,11);
								switch(sitCurso)
								{
									case 'R':
									strcpy(matricula.situacaoCurso,"REGULAR");
									break;
									case 'P':
									break;
									strcpy(matricula.situacaoCurso,"PENDENTE");
									case 'F':
									strcpy(matricula.situacaoCurso,"PAGO");
									//printf("%s %s \n",matricula.situacaoAluno,matricula.situacaoCurso);
									getch();
									break;
								}
						}
					}
						
					if(fseek(arqMatricula,(seq-1)*sizeof(Matriculas),SEEK_SET)==0)
					{
						if(fwrite(&matricula,sizeof(Matriculas),1,arqMatricula)==1)
						{
							gotoxy(11,16);
							fprintf(stdout,"Alteracao realizada com sucesso \n");
							//printf("%s %s \n",matricula.situacaoAluno,matricula.situacaoCurso);
							getch();
						}
						else{
							apresentaMsgErro("Erro ao gravar os dados ","Alteracao");
						}	
					}
					else{
						apresentaMsgErro("Erro ao posicionar o arquivo ","altera");
					}
					
				}
			}
			if(fclose(arqMatricula)!=0)
			{
				apresentaMsgErro("Erro ao fechar o arquivo"," dadosMatriculas");
			}
		}
		
		
	}
	else
	{
		gotoxy(11,13);
		fprintf(stdout,"matricula nao cadastrada ");
		getch();
	}
	
		
	
	
	
	
	
	*/
	
}
//Objetivos: Excluir matricula selecionada pelo aluno
//Parametros: nenhum
//Retorno: nenhum
void excluiMatriculas()
{
	Matriculas matricula;
	Aluno alunos;
	Cursos curso;
	FILE *arqAlunos; 
	FILE *arqCursos;
	int seq,existeErro;
	char *msg;
	char sitAluno[TAM_SITUACAO];
	char sitCurso[TAM_SITUACAO];
	char nomeAluno[MAX_NOME];
	char nomeCurso[MAX_NOME];
	matricula.idCurso=apresentaMatriculasV();
//	limpaJanela(1,1,70,70,AZUL);
    system("cls");
	desenhaMoldura(10,10,18,70,AZUL,BRANCO);
	if(matricula.idAluno<=0)
		return;
		
	seq = obtemCadastroMatricula(matricula.idCurso);
	if(seq!=0)
	{
		if(leMatriculaPesquisada(seq,&matricula))
		{
			if(matricula.situacaoAluno=='C')
			{
					strcpy(sitAluno,"CURSANDO");
			}else
			{
				strcpy(sitAluno,"CONCLUIDO");
			}
			if(matricula.situacaoCurso=='F')
			{
				strcpy(sitCurso,"PAGO");
			}else
			{
				if(matricula.situacaoCurso=='P')
				{
					strcpy(sitCurso,"PENDENTE");
				}else{
					strcpy(sitCurso,"REGULAR");
				}
			}
			if((arqAlunos=abreArquivo("dadosAlunos.txt","rb"))!=NULL)
			{
				while(!feof(arqAlunos))
				{
					if(fread(&alunos,sizeof(Aluno),1,arqAlunos)==1)
					{
						if(matricula.idAluno==alunos.matricula)
						{
							strcpy(nomeAluno,alunos.nomeAluno);
						}
					}
				}
				fclose(arqAlunos);
			}
			if((arqCursos=abreArquivo("dadosCursos.txt","rb"))!=NULL)
			{
				while(!feof(arqCursos))
				{
					if(fread(&curso,sizeof(Cursos),1,arqCursos)==1)
					{
						if(matricula.idCurso==curso.codCurso)
						{
							strcpy(nomeCurso,curso.nomeCurso);
						}
					}
				}
				fclose(arqCursos);
			}
			gotoxy(11,12);
			fprintf(stdout,"%s - %s - %s - %s - %i/%i \n",nomeAluno,nomeCurso,sitAluno,sitCurso,matricula.mes,matricula.ano);
			gotoxy(11,13);
			
			if(respostaSN("Confirma ")=='S')
			{
				msg=excluiRegArq("dadosMatriculas.txt",sizeof(Matriculas),seq,&existeErro);
				if(!existeErro)
				{
					gotoxy(11,14);
					fprintf(stdout,"Exclusao realizada com sucesso");
				}
				else 
				{
					apresentaMsgErro("Houve um erro e nao foi possivel excluir ","Matriculas ");
				}
			}
		}
	}
	else
	{
		gotoxy(11,13);
		fprintf(stdout,"Nenhuma matricula disponivel \n");
	}
	getch();
	
}
//Objetivos: transforma uma string para maiusculo
//parametros: referencia a string
//retorno: string em maiusculo.
void strToUpper(char * str)
{
int i;
  for (i=0;i<strlen(str);i++)
  {
      str[i] = (char) toupper(str[i]);
  }        
}        
// Descricao : compara duas strings mesmo se com caracter minusculo     
//  Parâmetros: duas strings                                 
//  Retorno   : endereço foi encontrada a string ou NULL    
char * strIstr(char *str1, char *str2)
{
char*pStr1,*pStr2;
char *retorno=NULL;
   pStr1 = (char*) malloc(sizeof(char) * (strlen(str1)+1));
   if(pStr1 != NULL)
   {
        strcpy(pStr1,str1);
        strUpper(pStr1);
        pStr2 = (char*) malloc(sizeof(char) * (strlen(str2)+1));
        if(pStr2 != NULL)
        {
           strcpy(pStr2,str2);
           strUpper(pStr2);
           retorno = strstr(pStr1,pStr2);
           free(pStr1);
           free(pStr2);
        }  
        else
        {
            free(pStr1);
        }     
   }  
   return retorno;  
}
// Objetivos : ordena os dados dos dos alunos existentes na memória
// parâmetros : qtde de alunos
//               endereço de memória com os dados dos alunos
// retorno : nenhum
void ordenaAlunos(int qtde, Aluno *alunos)
{

 qsort(alunos,qtde,sizeof(Aluno),comparaNomeAlunos);

}

