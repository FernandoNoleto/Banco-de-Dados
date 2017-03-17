/*
 * Aluno: Fernando Barroso Noleto
 * Disciplina: Banco de Dados
 * Trabalho: Criando código a partir da álgebra relacional
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct c{
	char nome_cliente [20];
	char rua_cliente [20];
	char cidade_cliente [20];
};

typedef struct c cliente;

void pegar_valor(cliente);

int comparar_string(const char* str1, const char* str2);

void comparar_tuplas(cliente, cliente);

int main(){

	cliente cl;
	cliente res;

	pegar_valor(cl);

	comparar_tuplas(cl, res);
	return 0;
}

void pegar_valor(cliente cl){
	FILE* cliente = fopen("cliente.txt", "r");
	FILE* resultado = fopen("resultado.txt", "w");

	while(!feof(cliente)){
		fscanf(cliente, "%[^;]s", cl.nome_cliente);
		fscanf(cliente, ";%[^;]s", cl.rua_cliente);
		fscanf(cliente, ";%[^\n]s",cl.cidade_cliente);
		fgetc(cliente);

		int i = comparar_string(cl.nome_cliente, "Rodrigo Alves");

		if(i == 1){
			fprintf(resultado, "%s;%s", cl.rua_cliente, cl.cidade_cliente);
		}

	}


	fclose(cliente);
	fclose(resultado);
}

int comparar_string(const char* str1, const char* str2){

	if(strlen(str1) == strlen(str2)){
		for(int i = 0; i < strlen(str2); i++){

			if(str1[i] != str2[i])
				return -1;

		}
	}
	else
		return -1;

	return 1;
}

void comparar_tuplas(cliente cl, cliente res){

	FILE* cliente = fopen("cliente.txt", "r");
	FILE* resultado = fopen("resultado.txt", "r");
	FILE* resultado_comparacao = fopen("resultado_comparacao", "w");

	fscanf(resultado, "%[^;]s", res.rua_cliente);
	fscanf(resultado, ";%[^\n]s",res.cidade_cliente);
	fgetc(resultado);

	int t = 0;

	while(!feof(cliente)){
		t++;

		fscanf(cliente, "%[^;]s", cl.nome_cliente);
		fscanf(cliente, ";%[^;]s", cl.rua_cliente);
		fscanf(cliente, ";%[^\n]s",cl.cidade_cliente);
		fgetc(cliente);

		int i = comparar_string(cl.cidade_cliente, res.cidade_cliente);
		int j = comparar_string(cl.rua_cliente, res.rua_cliente);
		int k = comparar_string(cl.nome_cliente, "Rodrigo Alves");

		if((i == 1 && j == 1) && k != 1){
			printf("%s;%s;%s\n",cl.nome_cliente, cl.rua_cliente, cl.cidade_cliente);
			fprintf(resultado_comparacao, "%s;%s;%s\n",cl.nome_cliente, cl.rua_cliente, cl.cidade_cliente);
		}

	}

	fclose(cliente);
	fclose(resultado);
	fclose(resultado_comparacao);
}
