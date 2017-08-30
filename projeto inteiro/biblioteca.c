#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "estruturas.h"
#include "bibliotecaPrototipos.h" 
#define ENTER      13
#define BACK_SPACE 8
#define CARACTER_EOL   0x0A
   

// Objetivo   : Converte uma string para maiuscula
// Parâmetros : str - endereço de memória da string a ser convertida para maiuscul
//Retorno   :  void
void strUpper(char * str)
{
int i;
  for (i=0;i<strlen(str);i++)
  {
      str[i] = (char) toupper(str[i]);
  }        
}        

// Objetivo   : lê uma string do teclado
// Parâmetros : nenhum
// Retorno   :  endereço de memória onde está a string lida

char * leStringTeclado(void)
{
char *texto=NULL, *textoAux=NULL, carac;    
int nroCarac=0,qtdeAlocada=0;
#ifndef TAM_BLOCO
#define  TAM_BLOCO  100
#endif

   do
   {
       carac = (char) getch(); // nao mostra caractere por causa dos caracteres especiais
       
       if(carac != ENTER)
       {
         if(carac > 0) // verifica se nao e caractere de controle (teclas especiais)
                       // del, setas de controle (esquerda, direita, baixo, cima)
         {
           // tratamento do back_space
           if(carac == BACK_SPACE)
           {
               if(nroCarac == 0)
                  printf(" ");
               else
               {   
                  printf("%c%c%c",BACK_SPACE,' ',BACK_SPACE);// retira o caractere e posiciona o
                                                          // cursor um caractere para trás
                  nroCarac--;
               }       
           }
           else
           {
             // verifica se existe necessidade de alocar memória  
             if(nroCarac == qtdeAlocada)
             {  
               // realocação da memória  
               textoAux = (char *)realloc(texto,(qtdeAlocada + TAM_BLOCO +1)*sizeof(char));
               if(textoAux != NULL)
               {
                 // atualização da qtdeAlocada e o ponteiro de texto  
                 qtdeAlocada += TAM_BLOCO;  
                 texto = textoAux;
               }      
               else
               {
                   printf(" Erro na realocacao de memoria na leitura do texto do teclado \n");
                   getch();
                   break;
               }        
             }      
             // guarda o caractere e apresenta na tela
             texto[nroCarac] = carac;
             nroCarac++;
             printf("%c",carac);//mostra caractere lido            
           }        
         }
         else
         {
             // le o segundo caractere de controle das teclas especiais desprezando-o
             getch();
         }   
       } 
       else
       {
          printf("\n"); // apos o enter muda de linha
       }                      
   }while(carac != ENTER);
   // verifica se não houve erro de alocação de memória
   if(textoAux == NULL)
   {
       // libera memória que estiver sido alocada anteriormente
       if(texto != NULL)
         free(texto);
       texto = NULL;
   }            
   else
   {
       // coloca o terminador de string
       texto[nroCarac] = '\0';
       // realoca o espaco necessario eliminando os excessos
       textoAux = (char *)realloc(texto,(strlen(texto)+1)*sizeof(char));
       if(textoAux != NULL)
       {
           texto = textoAux;
       }
       else
       {
           printf(" Erro na realocacao final de memoria na leitura do texto do teclado \n");
           getch();
           // libera memória que estiver sido alocada anteriormente
           if(texto != NULL)
              free(texto);
           texto = NULL ;  
       }          
   }
   // retorna o endereço de memória onde está o texto lido    
   return texto;
}
// Objetivo   : lê uma string de um arquivo
// Parâmetros : arq        - endereço de memória onde se encontra a estrutura FILE 
//                           do arquivo a ser lido
//              terminador - terminador da string gravada no arquivo que não será colocada na string
// Retorno   :  endereço de memória onde está a string lida do arquivo
char * leStringArquivo(FILE *arq, char terminador)
{
char *texto=NULL, *textoAux=NULL, carac;    
int nroCarac=0,qtdeAlocada=0;
#ifndef TAM_BLOCO
#define  TAM_BLOCO  100
#endif
   while(!feof(arq))
   {
       carac = fgetc(arq);

       if(carac == ENTER)
          continue;
//       printf(" caractere lido (%c - %d)\n",carac,carac);
//       getch();
       // verifica se foi lido o terminador da string
       if(carac == terminador || carac == CARACTER_EOL)
          break;
                    
       if(!feof(arq))
       {
         // verifica se existe necessidade de alocar memória  
         if(nroCarac == qtdeAlocada)
         {  
            // realocação da memória  
            textoAux = (char *)realloc(texto,(qtdeAlocada+TAM_BLOCO+1)*sizeof(char));
            if(textoAux != NULL)
            {
             // atualização da qtdeAlocada e o ponteiro de texto  
             qtdeAlocada += TAM_BLOCO;
             texto = textoAux;
            }
            else
            {
                printf(" Erro de realocacao de memoria na leitura do texto do arquivo \n");
                getch();
                break;
            }         
          }      
          // guarda o caractere lido
          texto[nroCarac] = carac;
          nroCarac++;
       }                       
   }
   // verifica se não houve erro de alocação de memória
   if(textoAux == NULL)
   {
       // libera memória que estiver sido alocada anteriormente
       if(texto != NULL)
         free(texto);
       texto = NULL;
   }            
   else
   {
       // coloca o  terminador de string
       texto[nroCarac] = '\0';
       // realoca o espaco necessario eliminando os excessos
       textoAux = (char *)realloc(texto,(strlen(texto)+1)*sizeof(char));
       if(textoAux != NULL)
       {
           texto = textoAux;
       }
       else
       {
           printf(" Erro na realocacao final de memoria na leitura do texto do arquivo \n");
           getch();
           // libera memória que estiver sido alocada anteriormente
           if(texto != NULL)
              free(texto);
           texto = NULL ;  
       }          
   }    
   // retorna o endereço de memória onde está o texto lido    
   return texto;
}
//Objetivo: validar o cpf
//Parametros: referencia ao cpf
//Retorno: 1 para valido, 0 para invalido 
int validaCPF (char *cpf)
{
		
       // cpfs inválidos        
       char *cpfInval[] = {"11111111111",
                         "22222222222",
                         "33333333333",
                         "44444444444",
                         "55555555555",
                         "66666666666",
                         "77777777777",
                         "88888888888",
                         "99999999999"}; 
		
		int cont,retorno =1,aux2,dig[11],soma=0,digVeri[2];
		FILE *arq;
		Aluno alunos;
		int aux=0,nroAluno=0;
		
		if((arq=fopen("dadosAlunos.txt","rb"))!=NULL)
		{
			while(!feof(arq))
			{
			if(fread(&alunos,sizeof(Aluno),1,arq)==1)
			{
				cont++;
				if(stricmp(cpf,alunos.CPF)==0){
					retorno=0;
					break;
					}
				}
			}
			fclose(arq);
		}
         
		if(strlen(cpf) > 11 || strlen(cpf) < 11)
		   return 0;
		   
	     for(cont=0;cont<9;cont++)
         {
               if(strcmp(cpfInval[cont],cpf)==0)
               {
                  retorno =0;
                  break;
            	}
         } 
        /*if((arq=fopen("dadosAlunos.txt","rb"))!=NULL)
		{
		while(!feof(arq))
		{
			if(fread(&alunos,sizeof(Aluno),1,arq)==1)
			{
				cont++;
				if(stricmp(cpf,alunos.CPF)==0){
					retorno=0;
					break;
				}
			}
		}
		fclose(arq);
	}
         */
         
         
         
         
         
         
	return retorno;
}
                                      
//  Objetivos : Formata um CPF                                 
//  Parâmetros: endereço inicial da string cpf                 
//  Retorno   : endereço de memória onde comeca a string        
//               com CPF formatado ou NULL                     
char * formataCPF (char *cpf)
{
static char cpfFormatado[15];
  
        sprintf(cpfFormatado,"%3.3s.%3.3s.%3.3s-%2.2s",
           cpf,cpf+3,cpf+6,cpf+9);
        return cpfFormatado;    
     
    
}
                                    
// Objetivos : Excluir um registro de um arquivo                
//  Parâmetros: endereço inicial da string com o nome do arquivo 
//              tamanho de cada registro do arquivo(fixo)        
//              número do registro a excluir                     
//              endereço de memória onde será armazenado o erro  
//  Retorno   : mensagem de erro                                 
char * excluiRegArq(char *nomeArq, int tamReg, int regExcluir,int *existeErro)
{
FILE *arq, *arqTemp;
int cont=0;
char *dados;
static char mensagem[100];

      mensagem[0] = '\0'; 
      *existeErro =0;
      if((arq = fopen(nomeArq,"rb"))== NULL)
      {
           sprintf(mensagem," Erro ao abrir arquivo  para exclusao");    
           *existeErro  = 1;
      }
      else
      {       
        if((arqTemp = fopen("arqTemp.txt","wb")) ==NULL)
        {
           fclose(arq);
           sprintf(mensagem," Erro ao criar arquivo para exclusao");    
           *existeErro  = 2; 
        }
        else
        {
          if((dados = (char*)malloc(sizeof(char)*tamReg)) == NULL)
          {
             sprintf(mensagem," Erro ao alocar memoria para exclusao");            
             *existeErro  = 3;
          }
          else
          {
              while(!feof(arq))
              {
                if(fread(dados,tamReg,1,arq)==1)
                {
                    cont++;
                    if(cont != regExcluir)
                    {
                      if(fwrite(dados,tamReg,1,arqTemp)!=1)
                      {
                         sprintf(mensagem,"Erro ao gravar dados para copia ");
                         *existeErro = 4;
                      }
                    } 
                }
                else
                {
                  if(!feof(arq))
                  {
                     sprintf(mensagem,"Erro ao ler dados para copia");
                     *existeErro = 5;
                  }   
                }  
              }
              free(dados);
          }
          if(fclose(arq) != 0)
          {
                sprintf(mensagem,"Erro ao fechar arquivo para exclusao");
                *existeErro = 6;
          }      
          if(fclose(arqTemp) != 0)
          {
                sprintf(mensagem,"Erro ao fechar arquivo temporario exclusao");
                *existeErro = 7;
          }      
        }
      }
      
      if(!*existeErro)
      {
          if(remove(nomeArq) != 0)
          {
             sprintf(mensagem,"Erro ao remover aquivo original");
             *existeErro = 8;
          }   
          else
          {   
            if(rename("arqTemp.txt",nomeArq)!=0)
            {
               sprintf(mensagem,"erro ao renomear arquivo");
               *existeErro = 9;
            }   
          }  
      } 
      return mensagem;   
} 

