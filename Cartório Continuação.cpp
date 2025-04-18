#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veos/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}
    
int consulta()
{
    setlocale(LC_ALL, "Portuguese");
    
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");		
}

int deletar()
{
    char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
		
}



int main()
    {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	    
        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	    printf("### Cartorio da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a opcao desejada no menu:\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n\n");
	    printf("opcao: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls");
	
	    switch(opcao)
	    {
	    	case 1:
	    	registro();
			break;
			
			case 2:
		    consulta();
			break;
			
			case 3:
			deletar();
			break;
					
			default:
			printf("Essa op��o n�o est� disponivel!\n");
	        system("pause");
			break;			
		}
	}
}
