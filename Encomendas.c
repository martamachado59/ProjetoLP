/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   Encomendas.c
 * Author: marta
 * 
 * Created on 14 de janeiro de 2022, 01:38
 */

#include "Encomendas.h"
#include "client_struct.h"
#include "article_struct.h"

void CriarEncomenda(Encomendas *encomendas, Cliente cliente, Artigo artigo){
	int tamanho;
	printf("Insira o tamanho a encomendar:");
	scanf("%d",&tamanho);
    int idencomenda = encomendas->contador++;
    encomendas->Encomendas[idencomenda].artigo = artigo;
    encomendas->Encomendas[idencomenda].cliente = cliente;
    encomendas->Encomendas[idencomenda].tamanho = tamanho;
    encomendas->Encomendas[idencomenda].precoEncomenda = 1;
    //encomendas->contador++;
}
void listarEncomenda(Encomenda encomenda, int id){
    printf("--- Encomenda %d ---\n", id);
	printf("Cliente: %s\nArtigo: %s\nTamanho: %d\nPreço Total: %f\n\n",encomenda.cliente.nome,encomenda.artigo.nome,encomenda.tamanho,encomenda.precoEncomenda);
}
void listarEncomendas(Encomendas encomendas){
    int i = 0;
    for(i = 0; i < encomendas.contador; i++){
        listarEncomenda(encomendas.Encomendas[i], i);
    }
}


void GuardarEncomendasFicheiro(Encomendas encomendas){
    FILE *fp = fopen("Encomendas.txt", "w");
    if(fp == NULL){
        printf("Erro ao abrir ficheiro");
    }
    if (encomendas.contador > 0) {
        int i;
        for (i = 0; i < encomendas.contador; i++) {
            fprintf(fp,"\n%s-%s-%d-%f-\n", encomendas.Encomendas[i].artigo.nome, encomendas.Encomendas[i].cliente.nome, encomendas.Encomendas[i].tamanho,encomendas.Encomendas[i].precoEncomenda);
        }
    } else {
        puts("Lista vazia");
    }
    fclose(fp);
}
void LerEncomendasFicheiro(Encomendas *encomendas){
    FILE* fp = fopen("Encomendas.txt", "r");
    if(fp == NULL){
        printf("Erro ao abrir ficheiro de encomendas\n");
    }
    char linha[500] = "";
    int linhaN = 1;
    while(fgets(linha, sizeof(linha),fp)){
    	if(linhaN % 2 == 0){
    		char delim[] = "-";
			char *ptr = strtok(linha, delim);
			int dado = 0;
			while(ptr != NULL)
			{
				if(dado==0){
					strcpy(encomendas->Encomendas[encomendas->contador].artigo.nome, ptr);
				}
				if(dado == 1){
					strcpy(encomendas->Encomendas[encomendas->contador].cliente.nome, ptr);
				}
				if(dado == 2)
				{
					encomendas->Encomendas[encomendas->contador].tamanho = atoi(ptr);
				}
				if(dado == 3){
					encomendas->Encomendas[encomendas->contador].precoEncomenda = atof(ptr);
				}
				dado++;
				ptr = strtok(NULL, delim);
			}
			encomendas->contador++;	
					
		}
		
		linhaN++;
	}
}