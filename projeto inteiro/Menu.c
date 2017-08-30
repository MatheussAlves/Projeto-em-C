#include <stdio.h>
//#include <conio.c>
                               
 // Objetivos : limpa uma janela da tela                       
 // Parâmetros: linhaInicial - linha inicial da janela         
 //            colunaInicial - coluna inicial da janela       
 //             linhaFinal   - linha final da janela           
 //             colunaFinal - coluna final da janela           
 //             corFundo - cor do fundo da janela a ser limpa  
 // Retorno   : nenhum                                          
void limpaJanela(int linhaInicial,int colunaInicial,int linhaFinal, 
                     int colFinal,int corFundo)
{
int coluna=0,linha=0;

    for(coluna=colFinal;coluna>=colunaInicial;coluna--)
    {
        for(linha=linhaFinal;linha>=linhaInicial;linha--)        
        {
            textbackground(corFundo);
            gotoxy(coluna,linha);
            printf(" ");

        }
    }


}

                                    
//  Objetivos : retorna a cor de fundo e de texto              
//  Parâmetros: corFundo - cor de fundo                        
//             corTexto - cor do texto                        
// Retorno   : nenhum                                          
void      retornaCor(int corFundo,int corTexto)
{
    textbackground(corFundo);
    textcolor(corTexto);
}    
//Objetivos:Montar o menu vertical
//Parametros:quantidade de linhas quantidade de colunas, cor de fundo e cor da letra.
//Retorno: selecao
int menuVertical(int n,char *imenu[],int c1,int c2,int linha,int coluna,int ini,
                int moldura,int corFundoAtual, int corLetraAtual)
{
		int tecla;	// Recebe a tecla pressionada
		int sel_b;	// Selecao de backup do menu
		int sel;
		int i;  		
		int val;		// 1 = tecla valida encontrada
						// 0 = tecla valida nao encontrada
        int tamMaiorTexto;
       

        // verifica se desenha com moldura e menu comeca na linha 1
        if(linha ==1 && moldura)
           linha++;
        // verifica se desenha com moldura e menu comeca na coluna 1
        if(coluna== 1 && moldura)
           coluna++;
            
		textcolor(c1);	// Atributo da cor das letras
		if(ini < 1)
		    ini=1;
		else if(ini>n)
           ini=n;
               
		sel=ini-1; 	// Primeiro item selecionado 
		for (i=0;i<=n-1;i++)
			{
			  
				if (i==ini-1) textbackground(c2); // Escreve itens do menu
				else textbackground(corFundoAtual);           // e seleciona o item inicial
				gotoxy(coluna,linha+i);                    // setado no argumento passado
				printf(imenu[i]);
				if(i==0)
				  tamMaiorTexto = strlen(imenu[i]);
				else if(strlen(imenu[i]) > tamMaiorTexto)
				  tamMaiorTexto = strlen(imenu[i]);
                
			}
			// desenha a moldura
			
			if(moldura)
			{
	 
			    desenhaMoldura(linha-1,coluna-1,linha+n,coluna+tamMaiorTexto+2,
                     corFundoAtual, corLetraAtual);
			} 
			 
		do
			{
				do
					{

						tecla=toupper(getch()); 


						if (tecla==72||tecla==75||tecla==65) val=1;
						else 	if (tecla==77||tecla==80||tecla==90) val=1;
								else 	if (tecla==27||tecla==13) val=1;
										else val=0;

					} while (!val);
				sel_b=sel; 
				if (tecla==72||tecla==75||tecla==65) sel--; 
				if (tecla==80||tecla==77||tecla==90) sel++;
				if (tecla==27) sel_b=-1; 		  
				if (sel<=-1) sel=n-1; 
				if (sel>=n) sel=0; 
				textcolor(c1);
				if (tecla!=13&&tecla!=27)
					{
					
						gotoxy(coluna,sel_b+linha); textbackground(corFundoAtual); printf(imenu[sel_b]);
				
						gotoxy(coluna,sel+linha); textbackground(c2); printf(imenu[sel]);
					
						fflush(stdin);
					}
					
			} while (tecla!=13&&tecla!=27);

            
        if(moldura)
           	limpaJanela(linha-2,coluna-1,linha+n,coluna+tamMaiorTexto+2,corFundoAtual);
        else
           	limpaJanela(linha,coluna,linha+n,coluna+tamMaiorTexto,corFundoAtual);
   
		return(sel_b+1); 	
}
//Objetivos: Desenhar a moldura
//Parametros: Linha Inicial, coluna inicual linha final coluna final cor de fundo e cor da letra.
//Retorno: nenhum
void desenhaMoldura(int linhaInicial, int colunaInicial, int linhaFinal, int colunaFinal,
          int corFundoAtual, int corLetraAtual)
{
    int i=0,qtdeLinhas,qtdeColunas;
    
    qtdeLinhas  = linhaFinal - linhaInicial ;
    qtdeColunas = colunaFinal - colunaInicial ;
    textbackground('F');
    textcolor('F');
    // faz a borda superior
    gotoxy(colunaInicial,linhaInicial);
    for(i=0;i<=qtdeColunas;i++)
    {
        printf("\xCD");
    }

    // faz a borda inferior
    gotoxy(colunaInicial,linhaInicial+qtdeLinhas);
    for(i=0;i<=qtdeColunas;i++)
    {
        printf("\xCD");
    }

    // faz a lateral esquerda    
    for(i=0;i<=qtdeLinhas;i++)
    {
        gotoxy(colunaInicial,linhaInicial+i);
        printf("\xBA");
    }
    // faz a lateral direita
    for(i=0;i<=qtdeLinhas;i++)
    {
        gotoxy(colunaInicial+qtdeColunas,linhaInicial+i);
        printf("\xBA");
    }

    // fecha os cantos da moldura
    gotoxy(colunaInicial,linhaInicial);
    printf("\xC9");
    gotoxy(colunaInicial+qtdeColunas,linhaInicial);
    printf("\xBB");
    gotoxy(colunaInicial,linhaInicial+qtdeLinhas);
    printf("\xC8");
    gotoxy(colunaInicial+qtdeColunas,linhaInicial+qtdeLinhas);
    printf("\xBC");
    retornaCor(corFundoAtual, corLetraAtual);
}
