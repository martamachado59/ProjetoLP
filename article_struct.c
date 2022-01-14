/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

/**
 * @file article_struct.c
 * @brief Doxygen
 * @return 
 */

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "input.h"
#include "article_struct.h"

/**
 * inserirArtigos é a função que cria os artigos, pedindo ao utilizador os dados necessários
 * atualizarArtigos é a função que atualiza os dados de um determinado artigo
 * procurarArtigo é a função que procura os artigos através do código artigo
 * listarArtigos é a função que lista todos artigos inseridos
 * imprimirArtigo é a função que mostra todos os dados do artigo com um respetivo código
 * removerArtigos é a função que apaga os dados do artigo escolhido
 * @param funções para a gestão dos artigos
 */


void imprimirArtigo(Artigo artigo) {
    
    if( artigo.apagado==0)
    {
        printf("\n%d %s %d %d %d \n", artigo.cod_artigo, artigo.nome, artigo.tipo_artigo,
            artigo.tam_min, artigo.tam_max);
    }
}

int procurarArtigo(Artigos artigo, int cod_artigo) {
    int i;
    for (i = 0; i < artigo.contador; i++) {
        if (artigo.artigos[i].cod_artigo == cod_artigo) {
            return i;
        }
    }
    return -1;
}

int inserirArtigos(Artigos *artigos) {
    int cod_artigo = obterInt(MIN_NUM_ARTIGO, MAX_NUM_ARTIGO, MSG_OBTER_NUM_ARTIGO);
    if (procurarArtigo(*artigos, cod_artigo) == -1) {
        artigos->artigos[artigos->contador].cod_artigo = cod_artigo;
        lerString(artigos->artigos[artigos->contador].nome, MAX_NOME_ARTIGO, MSG_OBTER_NOME_ART);
        artigos->artigos[artigos->contador].tipo_artigo = obterInt(MIN_TIPO, MAX_TIPO, OBTER_TIPO);
        artigos->artigos[artigos->contador].tam_min = obterInt(MIN_TAM, MAX_TAM, OBTER_TAM_MIN);
        artigos->artigos[artigos->contador].tam_max = obterInt(MIN_TAM, MAX_TAM, OBTER_TAM_MAX);
        return artigos->contador++;
    }
    return -1;
}
void atualizarArtigo(Artigo *artigo) {
    lerString((*artigo).nome, MAX_NOME_ARTIGO, MSG_OBTER_NOME_ART);
    (*artigo).tipo_artigo =
            obterInt(MIN_TIPO, MAX_TIPO, OBTER_TIPO);
    (*artigo).tam_min =
            obterInt(MIN_TAM, MAX_TAM, OBTER_TAM_MIN);
    (*artigo).tam_max =
            obterInt(MIN_TAM, MAX_TAM, OBTER_TAM_MAX);
}

void atualizarArtigos(Artigos *artigos) {
    int numero = procurarArtigo(*artigos,
            obterInt(MIN_NUM_ARTIGO, MAX_NUM_ARTIGO, MSG_OBTER_NUM_ARTIGO));
    if (numero != -1) {
        atualizarArtigo(&(*artigos).artigos[numero]);
    } else {
        puts(ERRO_ARTIGO_NAO_EXISTE);
    }
}


void removerArtigos(Artigos *artigos) {
    int numero = procurarArtigo(*artigos,
            obterInt(MIN_NUM_ARTIGO, MAX_NUM_ARTIGO, MSG_OBTER_NUM_ARTIGO));
    if (numero != -1) {
        (*artigos).artigos[numero].apagado = true;
        printf("Artigo apagado!");
    } else {
        puts(ERRO_ARTIGO_NAO_EXISTE);
    }
}

void listarArtigos(Artigos artigos) {
    if (artigos.contador > 0) {
        int i;
        for (i = 0; i < artigos.contador; i++) {
            imprimirArtigo(artigos.artigos[i]);
        }
    } else {
        puts(ERRO_LISTA_ARTIGOS_VAZIA);
    }
}

/**
 * inserirPrecos é a função que cria os preços necessários
 * atualizarPrecos é a função que atualiza os preços
 * procurarPreco é a função que procura os preços de um determinado artigo de um respetivo tamanho
 * listarPrecos é a função que lista todos os precos inseridos
 * imprimirPreco é a função que mostra todos os preços 
 * removePrecos é a função que apaga o preço do artigo escolhido
 * apagarDadosPrecos é a função que põem todos os paramentros dos preços a 0
 * @param encomenda tem acesso aos valores inseridos nos artigos, clientes, preços
 */

void imprimirPreco(PrecoArtigo precoArtigo) {
    printf("\n%d %d %lf %lf %lf %lf\n", 
            precoArtigo.tipo_artigo, 
            precoArtigo.tam,
            precoArtigo.precoObra,
            precoArtigo.precoFixo,
            precoArtigo.precoTam,
            precoArtigo.margem);
}

int procurarPreco(Precos precos, enum tipo tipo_artigo, int tam) {
    int i;
    for (i = 0; i < precos.contador; i++) {
        if (precos.precos[i].tipo_artigo == tipo_artigo && precos.precos[i].tam == tam) {
            return i;
        }
    }
    return -1;
}

int inserirPrecos(Precos *precos) {
    precos->precos[precos->contador].tipo_artigo = obterInt(MIN_TIPO, MAX_TIPO, OBTER_TIPO);
    precos->precos[precos->contador].tam = obterInt(MIN_TAM, MAX_TAM, MSG_OBTER_NUM_PRECO_TAM);
    if (procurarPreco(*precos, precos->precos[precos->contador].tipo_artigo, precos->precos[precos->contador].tam ) == -1) { 
        precos->precos[precos->contador].precoObra = obterDouble(MIN_PRECO, MAX_PRECO, OBTER_PRECO_OBRA);
        precos->precos[precos->contador].precoFixo = obterDouble(MIN_PRECO, MAX_PRECO, OBTER_PRECO_FIXO);
        precos->precos[precos->contador].precoTam = obterDouble(MIN_PRECO, MAX_PRECO, OBTER_PRECO);
        precos->precos[precos->contador].margem = obterDouble(MIN_MARGEM, MAX_MARGEM, OBTER_MARGEM);
        return precos->contador++;
    }
    return -1;
}
void atualizarPreco(PrecoArtigo *preco) {
    (*preco).precoObra =
            obterDouble(MIN_PRECO, MAX_PRECO, OBTER_PRECO_OBRA);
    (*preco).precoFixo =
            obterDouble(MIN_PRECO, MAX_PRECO, OBTER_PRECO_FIXO);
    (*preco).precoTam =
            obterDouble(MIN_PRECO, MAX_PRECO, OBTER_PRECO);
    (*preco).margem = 
            obterDouble(MIN_MARGEM, MAX_MARGEM, OBTER_MARGEM);
}
void atualizarPrecos(Precos *precos) {
    precos->precos[precos->contador].tipo_artigo = obterInt(MIN_TIPO, MAX_TIPO, OBTER_TIPO);
    precos->precos[precos->contador].tam = obterInt(MIN_TAM, MAX_TAM, MSG_OBTER_NUM_PRECO_TAM);
    int numero = procurarPreco(*precos, precos->precos[precos->contador].tipo_artigo, precos->precos[precos->contador].tam );
    if (numero == -1) {
        atualizarPreco(&(*precos).precos[numero]);
    } else {
        puts(ERRO_PRECO_NAO_EXISTE);
    }
}


void apagarDadosPreco(PrecoArtigo *preco){
    preco->tipo_artigo=0;
    preco->tam=0;
    preco->precoObra=0.0;
    preco->precoFixo=0.0;
    preco->precoTam=0.0;
    preco->margem=0.0;
}

void removerPrecos(Precos *precos) {
    precos->precos[precos->contador].tipo_artigo = obterInt(MIN_TIPO, MAX_TIPO, OBTER_TIPO);
    precos->precos[precos->contador].tam = obterInt(MIN_TAM, MAX_TAM, MSG_OBTER_NUM_PRECO_TAM);
    int numero = procurarPreco(*precos, precos->precos[precos->contador].tipo_artigo, precos->precos[precos->contador].tam );
    if (numero != -1) {
        int i;
        for (i = numero; i < precos->contador - 1; i++) {
            precos->precos[i] = precos->precos[i + 1];
        }
        apagarDadosPreco(&precos->precos[i]);
        precos->contador--;
    } else {
        puts(ERRO_PRECO_NAO_EXISTE);
    }
}

//voltar preços a zero



//mostrar preços
void listarPrecos(Precos precos) {
    if (precos.contador > 0) {
        int i;
        for (i = 0; i < precos.contador; i++) {
            imprimirPreco(precos.precos[i]);
        }
    } else {
        puts(ERRO_LISTA_PRECOS_VAZIA);
    }
}


void GuardarArtigosFicheiro(Artigos artigos){
    FILE *fp = fopen("Artigos.txt", "w");
    if(fp == NULL){
        printf("Erro ao abrir ficheiro");
    }
    if (artigos.contador > 0) {
        int i;
        for (i = 0; i < artigos.contador; i++) {
            fprintf(fp,"\n%d-%s-%d-%d-%d-\n", artigos.artigos[i].cod_artigo, artigos.artigos[i].nome, artigos.artigos[i].tam_min,
            artigos.artigos[i].tam_max,artigos.artigos[i].apagado);
        }
    } else {
        puts(ERRO_LISTA_ARTIGOS_VAZIA);
    }
    fclose(fp);
}
void LerArtigosFicheiro(Artigos *artigos){
    FILE* fp = fopen("Artigos.txt", "r");
    if(fp == NULL){
        printf("Erro ao abrir ficheiro de artigos\n");
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
					artigos->artigos[artigos->contador].cod_artigo = atoi(ptr);
				}
				if(dado == 1){
					strcpy(artigos->artigos[artigos->contador].nome, ptr);
				}
				if(dado == 2)
				{
					artigos->artigos[artigos->contador].tam_min = atoi(ptr);
				}
				if(dado == 3){
					artigos->artigos[artigos->contador].tam_max = atoi(ptr);
				}
				if(dado == 4){
					artigos->artigos[artigos->contador].apagado = atoi(ptr);
				}
				dado++;
				ptr = strtok(NULL, delim);
			}
			artigos->contador++;	
					
		}
		
		linhaN++;
	}
}