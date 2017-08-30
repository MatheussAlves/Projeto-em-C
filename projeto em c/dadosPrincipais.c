// Alunos : Matheus Alves e Matheus Silva

/*
 Sintese
   Objetivo: Auxiliar no cadastros de cada aluno curso e matricula.
 
   Entrada : Informaçoes do aluno tais como (nome, CPF , idade,sexo,data de ingresso, matricula).

   Saida   :  informaçoes do aluno de determinada matricula.

*/

#include <stdio.h>
#include <conio.c>
#include <time.h>
#include "Menu.h"
#include "Cores.h"
#include "bibliotecaPrototipos.h"
#include "estruturas.h"
#include "windows.h"
#include "manipulaDados.h"
#include "apresentaMensagem.h"
#include "relatorios.h"
//#include "matheus.h"



//PROTOTIPOS
void menuAlteracao();
int leDadosCurso(int nroCurso, Cursos *curso);
void pesquisaCursos();
void apresentaCursos();
void apresentaAlunos();
int verificaMatriculaRepitido(int *matriculaAluno);
void tiraTerminador(char *string);
void leValidaTexto(char *titulo,char *texto,int tamanho,int linha, int coluna);
int validaInt(int numero,int limiteMinimo,int limiteMaximo);
int leInt(char *titulo,int limiteMinimo,int limiteMaximo,int coluna,int linha);
void cadastraAlunos(void);
void menuCadastramentos(int *qtdeAlunos);
int obtemMatriculaAluno(int matricula);
void gravaArquivo(Aluno aluno);
void obtemDataHoraAtual(int *dia,int *mes, int *ano);
char leValidaCaracter(char *titulo,char *opcoes,int linha,int coluna);
void cadastraCurso(void);
int leDadosAlunoPesquisado(int nroAluno, Aluno *dadosAlunos);
void apresentacoes();
void pesquisas();
FILE * abreArq(char *nomeArq, char *modoAbertura, char *mensErro);
int obtemMatriculaAluno(int codigo);
void menuExclusao();
int validaFloat(float numero,float limiteMinimo,float limiteMaximo);
float leFloat(char *titulo,float limiteMinimo,float limiteMaximo,int coluna,int linha);
void cadastraMatricula();
void gravaCurso(Cursos cursos);
void gravaMatricula(Matriculas matriculas);
void menuRelatorios();
int main(void)

{
// Declaracoes
	char opcaoMenu;
	int qtdeAlunos;
	int minutos,horas,diaAtual,anoAtual,mesAtual;
	char opcao;
// Instrucoes
system("mode con:cols=140 lines=30");
 
	limpaJanela(1,1,30,140,BLUE);
	apresentaMsgApresentacao("BEM VINDO AO PROJETO ! ");
	
	char *itensMenu[]={
    	               " -REALIZAR CADASTROS",
	                   " -APRESENTAR DADOS",
	                   " -PESQUISA",
	                   " -ALTERAR",
	                   " -EXCLUSAO",
	                   " -RELATORIOS",
	                   " -FECHAR PROGRAMA",
				   };
      do
      {
	   	  limpaJanela(1,1,25,80,BLUE);
	   	  gotoxy(16,8);
	   	  fprintf(stdout,"MENU");
	      opcao=menuVertical(7,itensMenu,WHITE,GREEN,10,10,1,1,BLUE,WHITE);
	      retornaCor(BLUE,WHITE);
      		  switch (opcao)
		  {
		  	  case 1:
                menuCadastramentos(&qtdeAlunos);
				break;
			  case 2:
				apresentacoes();
                break;
		  	  case 3:
				pesquisas();
			 	break;
		      case 4:
		        menuAlteracao();
			   break;	  
			   case 5:
			   	menuExclusao();
			   	break;
			   case 6:
			   	menuRelatorios();
			   	break;
			   case 7:
			   	return 0;
		  }
	  }while(opcao!=7);

  getch();
 // return 0;
}
//Objetivo: Apresentar o menu de relatorios
//Parametros: nenhum
//retorno:nenuhm
void menuRelatorios()
{
	char opcao;
	char *itensMenu[]={
    	               " RELATORIO 1 ",
	                   " RELATORIO 2",
	                   " RELATORIO 3",
	                   " RELATORIO 4",
	                   " RELATORIO 5",
	                   " RELATORIO 6",
	                   " VOLTAR",
				   };
	do
      {
	   	  limpaJanela(1,1,25,80,BLUE);
	      opcao=menuVertical(7,itensMenu,WHITE,GREEN,10,10,1,1,BLUE,WHITE);
	      retornaCor(BLUE,WHITE);
		switch(opcao)
		{
			case 1:
				relatorio1();
				break;
			case 2:
				relatorio2();
				break;
			case 3:
				relatorio3();
				break;
			case 4:
				relatorio4();
				break;
			case 5:
				relatorio5();
				break;
			case 6:
				relatorio6();
				break;
			case 7:
				return;
			
		}
	}while(opcao !=8);
	
				   
}
//Objetivo: Apresentar o menu de alteracao
//Parametros: nenhum
//retorno:nenuhm
void menuAlteracao()
{
	char opcao;
	char *itensMenu[]={
    	               " ALUNOS ",
	                   " CURSO",
	                   " MATRICULA",
	                   " VOLTAR",
				   };
	  do
      {
	   	  limpaJanela(1,1,25,80,BLUE);
	      opcao=menuVertical(4,itensMenu,WHITE,GREEN,10,10,1,1,BLUE,WHITE);
	      retornaCor(BLUE,WHITE);
		switch(opcao)
		{
			case 1:
				alteraAlunos();
				break;
			case 2:
				alteraCursos();
				break;
			case 3:
				alteraMatriculas();
				break;
			case 4:
				return;
			
		}
	}while(opcao !=5);
	
}
//Objetivo:Apresentar o menu para exclusao
//Parametros:nenhum
//retorno:nenhum
void menuExclusao()
{
	char opcao;
	char *itensMenu[]={
    	               " ALUNOS ",
	                   " CURSO",
	                   " MATRICULA",
	                   " VOLTAR",
				   };
	 do
      {
	   	  limpaJanela(1,1,25,80,BLUE);
	      opcao=menuVertical(4,itensMenu,WHITE,GREEN,10,10,1,1,BLUE,WHITE);
	      retornaCor(BLUE,WHITE);
		switch(opcao)
		{
			case 1:
				excluiAluno();
				break;
			case 2:
				excluiCursos();
				break;
			case 3:
				excluiMatriculas();
				break;
			case 4:
				return;
			
		}
	}while(opcao !=5);
				
}
//Objetivo: cadastra o menu de opcoes de cadastramento.
//Parametros: referencia ao dados dos alunos, referencia a quantidade de alunos.
//retorno:nenhum
void menuCadastramentos(int *qtdeAlunos)
{
	char opcao;
	    char *itensMenu[]={
	    	           
    	               " ALUNOS ",
	                   " CURSO",
	                   " MATRICULA",
	                   " VOLTAR",
				   };
      do
      {
	   	  limpaJanela(1,1,25,80,BLUE);
	      opcao=menuVertical(4,itensMenu,WHITE,GREEN,10,10,1,1,BLUE,WHITE);
	      retornaCor(BLUE,WHITE);
		switch(opcao)
		{
			case 1:
				cadastraAlunos();
				break;
			case 2:
				cadastraCurso();
				break;
			case 3:
				cadastraMatricula();
				break;
			case 4:
				return;
			
		}
	}while(opcao !=5);
	
}
//Objetivo:realizar cadastros dos cursos
//Parametros:
//Retorno:
void cadastraCurso(void)
{
	Cursos cursos;
	FILE *arqCursos;
	desenhaMoldura(10,10,20,70,AZUL,BRANCO);
    gotoxy(11,11);
    fflush(stdin);
    leValidaTexto("NOME - ",cursos.nomeCurso,NOME_CURSO,11,11);
    do
	{
   		cursos.codCurso=geraCodigoAleatorio();
    
		
	}while(obtemCodigoCurso(cursos.codCurso)!=0);
	
	
	gotoxy(11,12);
	cursos.mensalidade=leFloat("MENSALIDADE - ",MIN_MENSALIDADE,MAX_MENSALIDADE,11,12);
	gotoxy(11,13);	
	cursos.horarios=leInt("CARGA HORARIA - ",MIN_CARGA_HORARIA,MAX_CARGA_HORARIA,11,13);
	gotoxy(11,14);
	fprintf(stdout,"Codigo do curso gerado pelo sistema = %i ",cursos.codCurso);
    gravaCurso(cursos);

	system("cls");

}
// Objetivos : cadastra os dados de um aluno, gravando-o em um arquivo
// parâmetros : nenhum
// retorno : nenhum
void cadastraMatricula()
{
	Matriculas matricula;
	Matriculas *matriculaRepetida;
	Aluno *alunos;
	Cursos *curso;
	int qtdeAlunos,seq;
	int qtdeCursos,seq2;
	int qtdeMatriculas;	
	int nroAluno,nroCurso,cont;
	FILE *arq;
	char sitAluno,sitCurso;
	int *dia,*hora,*minuto;
	if((alunos = obtemDadosArquivoAluno(&qtdeAlunos))!=NULL )
	{
		desenhaMoldura(10,10,25,70,AZUL,BRANCO);
		gotoxy(11,11);
		fprintf(stdout,"SELECIONE O ALUNO ");
		getch();
		matricula.idAluno=apresentaAlunosV();
		seq=obtemMatriculaAluno(matricula.idAluno);
		strcpy(matricula.nomeMatriculado,alunos[seq-1].nomeAluno);
		
	}
	if((curso = obtemDadosArquivoCursos(&qtdeCursos))!=NULL)
	{
	
		desenhaMoldura(10,10,25,70,AZUL,BRANCO);
		gotoxy(11,12);
		fprintf(stdout,"SELECIONE O CURSO ");
		getch();
		matricula.idCurso=apresentaCursosV();
		fflush(stdin);
		desenhaMoldura(10,10,25,70,AZUL,BRANCO);
		seq2=obtemCodigoCurso(matricula.idCurso);
		//fprintf(stdout," seq %i id curso %i",seq2,matricula.idCurso);
		strcpy(matricula.nomeCursoMatriculado,curso[seq2-1].nomeCurso);
		//fprintf(stdout,"nome do cadastrado = %s ",matricula.nomeCursoMatriculado);
		
	}
		sitAluno=leValidaCaracter("Situacao do aluno ( C - cursando F - concluido)","CF",14,11);
		sitCurso=leValidaCaracter("Situacao do curso (R - regular - P pendente - F pago) ","RPF",15,11);
		if(sitAluno=='C')
		{
			strcpy(matricula.situacaoAluno,"CURSANDO");
		}else
		{
			strcpy(matricula.situacaoAluno,"CONCLUIDO");
		}
		if(sitCurso=='R')
		{
			strcpy(matricula.situacaoCurso,"REGULAR");
		}else
		{
			if(sitCurso=='P')
			{
				strcpy(matricula.situacaoCurso,"PENDENTE");
			}
			else
			{
				strcpy(matricula.situacaoCurso,"PAGO");
			}
		}
	
	if((matriculaRepetida = obtemDadosArquivoMatriculas(&qtdeMatriculas))!=NULL)
	{
		for(cont=0;cont<qtdeMatriculas;cont++)
		{
			if(matricula.idAluno==matriculaRepetida[cont].idAluno && (stricmp(matricula.situacaoAluno,"CURSANDO"))==0)
			{
				gotoxy(11,15);
				fprintf(stdout,"O aluno só pode estar cursando 1 curso por vez ");
				getch();
				return;
			}
		}
		free(matriculaRepetida);
	
	}
		matricula.mes=leInt("MES - ",1,12,11,16);
		matricula.ano=leInt("ANO - ",1900,2050,11,17);
		
		gotoxy(11,18);
		fprintf(stdout,"nome do cadastrado = %s ",matricula.nomeMatriculado);
		gotoxy(11,19);
		fprintf(stdout,"curso cadastrado = %s ",matricula.nomeCursoMatriculado);
		gotoxy(11,20);
		gravaMatricula(matricula);
		system("cls");
		free(alunos);
		free(curso);
}
	
// Objetivos  : cadastra os dados de um aluno, gravando-o em um arquivo
// parâmetros : nenhum
// retorno : nenhum
void cadastraAlunos(void)
{
Aluno aluno;
int flag;
int verificador;
  desenhaMoldura(10,10,20,70,AZUL,BRANCO);
  aluno.matricula=leInt("MATRICULA - ",MIN_MATRICULA,MAX_MATRICULA,11,11);
  if(obtemMatriculaAluno(aluno.matricula)!=0)
	{
		gotoxy(11,12);
		fprintf(stdout,"Matricula repetida \n ");
		getche();
		return;
	}
  fflush(stdin);
  leValidaTexto("NOME - ",aluno.nomeAluno,MAX_NOME,11,12);
  fflush(stdin);
  do{
  	verificador=1;
	leValidaTexto("CPF - ",aluno.CPF,TAM_CPF,11,13);
	verificador=validaCPF(aluno.CPF);
	if(verificador==0)
	{
		apresentaMsgErro("CPF INVALIDO E/OU REPETIDO INFORME NOVAMENTE ","ERRO");
	}
}while(verificador==0);
formataCPF(aluno.CPF);
  gotoxy(11,14);
  aluno.idade=leInt("IDADE - ",MIN_IDADE,MAX_IDADE,11,14);
  gotoxy(11,15);
  aluno.sexo=leValidaCaracter("SEXO -","MF",15,11);
  gotoxy(11,16);
  obtemDataHoraAtual(&aluno.dataDia,&aluno.dataMes,&aluno.dataAno);
  fprintf(stdout,"Data da matricula = %i/%i/%i ",aluno.dataDia,aluno.dataMes,aluno.dataAno);
  gravaArquivo(aluno);  
}
//objetivo:ler um numero inteiro
//parametro:titulo,limiteMinimo,limiteMaximo
//retorno:numero
int leInt(char *titulo,int limiteMinimo,int limiteMaximo,int coluna,int linha)
{
	int ret=0,numero;
	
	do
	{
		do
		{	
			fflush(stdin);
			gotoxy(coluna,linha);
			clreol();
			fflush(stdin);
			gotoxy(coluna,linha);
			printf("%s",titulo);
			fflush(stdin);
			ret=scanf("%i",&numero);
			fflush(stdin);
			if(ret==0)
			{
				apresentaMsgErro("Informe um numero correto ","inteiro");
				
			}			
		}while(ret==0);
	}while(validaInt(numero,limiteMinimo,limiteMaximo)==0);

	return numero;

}
//objetivo: validar um numero inteiro
//parametro: numero,limiteMinimo,limiteMaximo
//retorno: de acordo com a validacao (0 ou 1)
int validaInt(int numero,int limiteMinimo,int limiteMaximo)
{
	if(numero<limiteMinimo || numero>limiteMaximo){
		apresentaMsgErro("numero invalido informe novamente ! ","validacao");
		return 0;
	}
	else
			return 1;
	
}
//objetivo:ler um numero real
//parametro:titulo,limiteMinimo,limiteMaximo
//retorno:numero
float leFloat(char *titulo,float limiteMinimo,float limiteMaximo,int coluna,int linha)
{
	float ret=0,numero;
	
	do
	{
		do
		{	
			fflush(stdin);
			gotoxy(coluna,linha);
			clreol();
			fflush(stdin);
			gotoxy(coluna,linha);
			printf("%s",titulo);
			fflush(stdin);
			ret=scanf("%f",&numero);
			fflush(stdin);
			if(ret==0)
			{
				apresentaMsgErro("Informe um numero correto ","inteiro");
				
			}			
		}while(ret==0);
	}while(validaInt(numero,limiteMinimo,limiteMaximo)==0);

	return numero;

}
//objetivo:validar um numero inteiro
//parametro:numero,limiteMinimo,limiteMaximo
//retorno: de acordo com a validacao (0 ou 1)
int validaFloat(float numero,float limiteMinimo,float limiteMaximo)
{
	if(numero<limiteMinimo || numero>limiteMaximo){
		apresentaMsgErro("numero invalido informe novamente ! ","validacao");
		return 0;
	}
	else
			return 1;
	
}
//objetivo: ler uma string
//parametro: endereço inicial do titulo,endereço inicial da string,tamanho
//retorno:nenhum
void leValidaTexto(char *titulo,char *texto,int tamanho,int coluna,int linha)
{
	do
	{
		fflush(stdin);
    	gotoxy(coluna,linha);
    	clreol();
    	fflush(stdin);
    	gotoxy(coluna,linha);
		printf("%s",titulo);
		fflush(stdin);
		fgets(texto,tamanho,stdin);
		fflush(stdin);
		tiraTerminador(texto);
	}while(strlen(texto)<1);
}//objetivo:verificar se existe DDD repitido
//parametro:DDD da cidade
//retorno: 0 - nao existe , 1- n - posicao da cidade no arquivo
int verificaMatriculaRepitido(int *matriculaAluno)
{
	FILE *arqAlunos;
	Aluno aluno;
	int flag=0,contadorPosicao=0;
	
	arqAlunos = fopen("alunos.txt","rb");
	if(arqAlunos==NULL)
	{
		getch();
	}
	else
	{
		while(!feof(arqAlunos))
		{
			if(fread(&aluno,sizeof(Aluno),1,arqAlunos)==1)
			{
				contadorPosicao ++;
				if(*matriculaAluno==aluno.matricula)
				{
                    flag=contadorPosicao;
					break;
				}
			}
			
		}
		fclose(arqAlunos);
	}
	return flag;
}

//objetivo:validar uma string
//parametro:referencia ao vetor de nomes
//retorno:nenhum
void tiraTerminador(char *string)
{
	if(string[strlen(string)-1]=='\n')
		string[strlen(string)-1]='\0';
}
//objetivo:gravar dados da Cidade no arquivo
//parametro:estrutura de dados da Cidade,endereco de memoria da somaCidades
//retorno:nenhum
void gravaArquivo(Aluno aluno)
{
	FILE *arqAlunos;

	arqAlunos = fopen("dadosAlunos.txt","ab");
	if(arqAlunos==NULL)
	{
		printf("Erro ao abrir o arquivo \n");
	}
	else
	{
		if(fwrite(&aluno,sizeof(Aluno),1,arqAlunos)==1)
		{
			MessageBox(0,"DADOS GRAVADOS COM SUCESSO","ATENCAO",0);
			fclose(arqAlunos);
    	}
		
	}
	getch();
}
//objetivo:gravar dados da Cidade no arquivo
//parametro:estrutura de dados da Cidade,endereco de memoria da somaCidades
//retorno:nenhum

void gravaMatricula(Matriculas matriculas)
{
	FILE *arq;

	arq = fopen("dadosMatriculas.txt","ab");
	if(arq==NULL)
	{
		printf("Erro ao abrir o arquivo \n");
	}
	else
	{
		if(fwrite(&matriculas,sizeof(Matriculas),1,arq)==1)
		{
			MessageBox(0,"DADOS GRAVADOS COM SUCESSO","ATENCAO",0);
			fclose(arq);
    	}
		
	}
	getch();
}
//objetivo:gravar dados da Cidade no arquivo
//parametro:estrutura de dados da Cidade,endereco de memoria da somaCidades
//retorno:nenhum
void gravaCurso(Cursos cursos)
{
	FILE *arqCursos;

	arqCursos = fopen("dadosCursos.txt","ab");
	if(arqCursos==NULL)
	{
		printf("Erro ao abrir o arquivo \n");
	}
	else
	{
		if(fwrite(&cursos,sizeof(Cursos),1,arqCursos)==1)
		{
			MessageBox(0,"DADOS GRAVADOS COM SUCESSO","ATENCAO",0);
			fclose(arqCursos);
    	}
		
	}
	getch();
}
//Objetivo: Obter a hora e a data Atual
//Parametros: referencia a hora,minutos,dia,mes,ano.
//Retorno: horarios resgatados do sistema
void obtemDataHoraAtual(int *dia,int *mes, int *ano)
{
   time_t t;
   struct tm *dataAtual;
   t = time(NULL);
   dataAtual = localtime(&t);
   *dia    =dataAtual->tm_mday;
   *mes    =dataAtual->tm_mon+1;
   *ano    =1900+dataAtual->tm_year;
}
//Objetivo:Pesquisar um aluno a partir de sua matricula.
//Parametros:nenhum.
//Retorno: dados do aluno pesquisado.
void pesquisaAlunos()
{
	FILE *arqAlunos;
	Aluno alunos;
	int matriculaPesquisada;
	int flag=0;
	int nroAluno;
	
	desenhaMoldura(10,10,20,70,AZUL,BRANCO);
	gotoxy(11,11);
	matriculaPesquisada=leInt("Informe a matricula que deseja pesquisar : ",MIN_MATRICULA,MAX_MATRICULA,11,11);
	if((nroAluno = obtemMatriculaAluno(matriculaPesquisada))==0)
	{
		gotoxy(11,12);
		printf("Essa matricula nao foi encontrada \n ");
	}
	else
	{
		if(leDadosAlunoPesquisado(nroAluno,&alunos)==1)
		{
			gotoxy(11,11);
			printf("       NOME     - IDADE - SEXO - MATRICULA - CPF \n");
			gotoxy(11,12);
			printf("%-16.16s-%-8i-%-7c-%-9i-%-11i \n",alunos.nomeAluno,alunos.idade,alunos.sexo,alunos.matricula,alunos.CPF);
			gotoxy(11,13);
			printf("data de ingresso = %i/%i/%i \n",alunos.dataDia,alunos.dataMes,alunos.dataAno);
			gotoxy(11,14);
			printf("____________________________________\n");
			getch();

		}
		else
		{
			printf("Erro ao ler os dados do arquivo ! \n");
			getch();
		}
	}
}
//Objetivos:Pesquisar um curso
//Parametros:nenhum
//Retorno: curso pesquisado
void pesquisaCursos()
{
	FILE *arqAlunos;
	Cursos cursos;
	int codCurso;
	int flag=0;
	int nroCurso;
	
	desenhaMoldura(10,10,20,70,AZUL,BRANCO);
	gotoxy(11,11);
	codCurso=leInt("Informe o codigodo curso deseja pesquisar : ",MIN_COD,MAX_COD,11,11);
	if((nroCurso = obtemCodigoCurso(codCurso))==0)
	{
		gotoxy(11,12);
		printf("Esse codigho nao foi encontrado. \n ");
	}
	else
	{
		if(leDadosCurso(nroCurso,&cursos)==1)
		{
			gotoxy(11,11);
			printf("    NOME CURSO   - CODIGO - MENSALIDADE - HORARIOS  \n");
			gotoxy(11,12);
			printf("%-17.17s-%-8i-%-13.2f-%-9i \n",cursos.nomeCurso,cursos.codCurso,cursos.mensalidade,cursos.horarios);
			gotoxy(11,13);
			printf("____________________________________\n");
			getch();

		}
		else
		{
			printf("Erro ao ler os dados do arquivo ! \n");
			getch();
		}
	}
}
//Objetivo: Apresentar o menu de opcoes de pesquisa.
//Parametros:nenhum.
//Retorno:nenhum.
void pesquisas()
{
		char opcao;
		    char *itensMenu[]={
	    	           
    	               " ALUNOS",
	                   " CURSO",
	                   " MATRICULAS",
	                   " VOLTAR",
				   };
      do
      {
	   	  limpaJanela(1,1,25,80,BLUE);
	      opcao=menuVertical(4,itensMenu,WHITE,GREEN,10,10,1,1,BLUE,WHITE);
	      retornaCor(WHITE,BRANCO);

		switch(opcao)
		{
			case 1:
				
				pesquisaAlunos();
				break;
			case 2:
				pesquisaCursos();
				break;
			case 3:
				pesquisaMatriculas();
				break;
			case 4:
				return;
				
			
		}
	}while(opcao!=3);
}
//Objetivo: apresentar o menu de opcoes de listagem.
//Parametros: nenhum
//retorno:nenhum
void apresentacoes()
{
	char opcao;
	
		    char *itensMenu[]={
	    	  
    	               " APRESENTAR ALUNOS ",
	                   " APRESENTAR CURSO",
	                   " APRESENTAR MATRICULAS",
	                   " VOLTAR",
				   };
      do
      {
	   	  limpaJanela(1,1,25,80,BLUE);
	      opcao=menuVertical(4,itensMenu,WHITE,GREEN,10,10,1,1,BLUE,WHITE);
	      retornaCor(BLUE,WHITE);
		switch(opcao)
		{
			case 1:
				apresentaAlunosV();
				break;
			case 2:
				apresentaCursosV();
				break;
			case 3:
				apresentaMatriculasV();
				break;
			case 4:
				return;
				break;
				
			
		}
	}while(opcao!=4);

}
// Objetivo: Abrir/criar um arquivo
// Parãmetros: endereço de memória com nome do arquivo,endereço com o modo de abertura
//              endereço da mensagem de erro
// Retorno : endereço para a stream
FILE * abreArq(char *nomeArq, char *modoAbertura, char *mensErro)
{
FILE *arq;
    if((arq = fopen(nomeArq,modoAbertura)) == NULL)
	{
		if(strlen(mensErro))
		{
		   printf("%s\n",mensErro);
		   getch();
	    }
    }
    return arq;
}
