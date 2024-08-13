#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o
#include <locale.h> //biblioteca de aloca��es de texto
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio Cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//FInal Cria��o de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: \n\n"); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se � strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores de string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo - W significa escrever
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n\n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file =fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n\n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite seu cargo a ser cadastrado: \n\n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a lingu�gem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file== NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado\n\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}
int deletar()
{
	char cpf[40];
		
	printf("Digite o CPF a ser deletado: \n\n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
			
	if(file == NULL)
		{
			printf("O usu�rio n�o se encontra no sistema! \n");
			system("pause");
		}
	
	
}
int main() 
{
	int opcao=0; //Definindo Vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a lingu�gem
	
		printf("### Cart�rio EBAC ###\n\n"); //Inicio do menu
		printf("Escolha uma das op��es do menu:\n\n");
		printf("\t1- Cadastrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Apagar nomes\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando escolha do Usu�rio
	
		system("cls"); //Apagando tela ap�s a escolha
		
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
			printf("Essa op��o n�o est� dispon�vel!!!\n\n");
			system("pause");
			break;	
		}//Fim da sele��o	
	}
}
