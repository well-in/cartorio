#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registrar() 
{
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consultar() 
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[100];
		
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	  	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, Não localizado!.\n");
		system("pause");
	}
		
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
}

int deletar() 
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	remove(cpf);
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, Não localizado!.\n");
		system("pause");
	}	
}

int main(){
	int option = 0;
	int restart = 1;
	
	for(restart=1;restart=1;){
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");
		
		printf("### Cartório da EBAC ###\n\n");
		
		printf("Escolha a opção desejada no menu:\n\n");	
		printf("\t 1 - Registrar Nomes: \n");
		printf("\t 2 - Consultar Nomes: \n");
		printf("\t 3 - Deletar Nomes: \n\n");
		
		printf("Opção: ");	
		scanf("%d", &option);
		
		system("cls");
		
		switch(option) 
		{
			case 1:
				registrar();
				break;
				
			case 2:
				consultar();
				break;
				
			case 3:
				deletar();
				break;
				
			default:
				printf("essa opção nao está disponível!");
				system("pause");
				break;
		}
		
		printf("\n\n ### Software de uso livre ### \n\n");
	}		
}
