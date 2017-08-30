#include <stdio.h>
//#include <conio.c>
//#include "Jair_MatheusAlves_uc15102526_MatheusSilva_UC15101619_PFbackup.c"
#include "Menu.h"
#include "estruturas.h"
#define MAX_NOME 150
#define MIN_MATRICULA 999
#define MAX_MATRICULA 9999

/*
//objetivo:excluir os dados de um aluno a partir da matricula
//parametro:void
//retorno:nenhum
void excluiAluno(void)
{
	Aluno alunos;
	int contaPosicao=0,flag, auxAluno, erro = 0;
	FILE *arqTemp,*arqAux,*arqAluno;
	int nroAluno,matriculaPesquisada;
	

	matriculaPesquisada=leValidaInt("Informe a matricula : ","Erro, informe um numero valido !!! ",MIN_MATRICULA,MAX_MATRICULA);
    if((nroAluno = obtemMatriculaAluno(matriculaPesquisada))==0)
	{
		apresentaMsgErro("Matricula nao encontrada ! ","excluiAluno");
		return;
	}


    arqAux = fopen("temp.txt","wb"); 
    if(arqAux == NULL)
    {
       	printf("erro ao criar  o arquivo temporario.\n");
		getch();
	}
	else
	{
	   arqAluno=fopen("dadosAlunos.txt","rb");
	   if(arqAluno==NULL)
	   {
		 printf("erro ao abrir o arquivo dos alunos.\n");
		 getch();
	   }
	   else
	   {
		   	while(!feof(arqAluno))
		   	{
				if(fread(&alunos,sizeof(Aluno),1,arqAluno) == 1)
				{			
							
					if(alunos.matricula != auxAluno)
					{		
						if(fwrite(&alunos,sizeof(Aluno),1,arqAux) != 1)
						{
							printf("Nao foi possivel alterados os dados !\n");
							erro = 1;
							break;
						}
				   }
	
		    	
		   		} 
	   	}
	   	
	   	fclose(arqAluno);  	
      }   
      
   	 fclose(arqAux);
	}
	
	if(erro != 1)
	{
		if(remove("arquivoAlunos.txt") != 0)
		{
			printf("Erro ao remover arquivo!\n"); getch();
		}
	
		else
		{
			if(rename("temp.txt", "dadosAlunos.txt") != 0)
			{
				getch();
			}
			else
			{
				printf("Exclusao realizada com sucesso!\n"); 
                getch();	
			}
		}
	}
	
}
*/
//objetivo:alterar informacao de um aluno
//parametro:dados 
//retorno:nenhum
void alteraAluno(void)
{
	Aluno aluno;
	int contaPosicao=0,flag;
	FILE *arqAluno;
	int nroAluno,matriculaPesquisada;
	
	
	printf("Digite a matricula para identificar o aluno:");
	matriculaPesquisada=leValidaInt("Informe a matricula : ","Erro, informe um numero valido",MIN_MATRICULA,MAX_MATRICULA);
    if((nroAluno = obtemMatriculaAluno(matriculaPesquisada))==0)
	{
		apresentaMsgErro("MATRICULA NAO ENCONTRADA","alteraAluno");
		return;
	}


	leValidaTexto("digite o novo nome do aluno : ",aluno.nomeAluno,MAX_NOME);
	aluno.idade=leInt("Informe a idade do aluno : ",10,90);
	aluno.sexo=leValidaCaracter("Informe o sexo do aluno (M/F) ","MF");
	obtemDataHoraAtual(aluno.dataDia,aluno.dataMes,aluno.dataAno);
	printf("Nova Data obtida \n");

    
	arqAluno=fopen("dadosAlunos.txt","r+b");
	if(arqAluno==NULL)
	{
		printf("erro ao ler o arquivo \n");
		getch();
	}
	else
	{
			if(fseek(arqAluno,(nroAluno-1)*sizeof(Aluno),SEEK_SET)==0)
			{
				if(fwrite(&aluno,sizeof(Aluno),1,arqAluno)==1)
				{
					printf("dados alterados com sucesso !\n");
				}
			}

	    	fclose(arqAluno);
	}
}
//Objetivo: ler e validar inteiro 
//Parametros: endereco de titulo, endereco de mensagem de erro , valorMin e valorMax
//Retorno: inteiro validado
int leValidaInt(char *titulo, char *msgErro, int tamMin, int tamMax)
{
	int ret = 0;
	int flag;
	int nro;
	do
	{
		flag = 0;
		printf("%s\n",titulo);
		fflush(stdin);
		ret = scanf("%d",&nro);
		fflush(stdin);
		if(ret == 0 || nro < tamMin || nro > tamMax)
		{
			flag = 1;
			printf("%s\n",msgErro);
			getch();
		}
		clrscr();
	}while(flag == 1);
	return nro;
}	

