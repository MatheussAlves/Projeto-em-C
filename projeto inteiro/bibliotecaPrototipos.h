char * leStringTeclado(void);
char * leStringArquivo(FILE *arq, char terminador);
void strUpper(char * str);
int validaCPF (char *cpf);     
char * formataCPF (char *cpf);
char * novaFgets(char *texto, int tamanho);
char * strIstr(char *str1, char *str2);      
char * excluiRegArq(char *nomeArq, int tamReg, int regExcluir,int *existeErro); 
int strIncmp(char *str1, char *str2,int tam);

