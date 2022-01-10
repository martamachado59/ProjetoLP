/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */
#include <stdio.h>
#include <stdbool.h>
#include "input.h"
#include "article_struct.h"

//funções dos artigos

void imprimirArtigo(Artigo artigo) {
    printf("\n%d %s %d %d %d \n", artigo.cod_artigo, artigo.nome, artigo.tipo_artigo,
            artigo.tam_min, artigo.tam_max);
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
        lerString(artigos->artigos[artigos->contador].nome, MAX_NOME_ARTIGO, MSG_OBTER_NOME);
        artigos->artigos[artigos->contador].tipo_artigo = obterInt(MIN_TIPO, MAX_TIPO, OBTER_TIPO);
        artigos->artigos[artigos->contador].tam_min = obterInt(MIN_TAM, MAX_TAM, OBTER_TAM_MIN);
        artigos->artigos[artigos->contador].tam_max = obterInt(MIN_TAM, MAX_TAM, OBTER_TAM_MAX);
        return artigos->contador++;
    }
    return -1;
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

void atualizarArtigo(Artigo *artigo) {
    lerString((*artigo).nome, MAX_NOME_ARTIGO, MSG_OBTER_NOME);
    (*artigo).tipo_artigo =
            obterInt(MIN_TIPO, MAX_TIPO, OBTER_TIPO);
    (*artigo).tam_min =
            obterInt(MIN_TAM, MAX_TAM, OBTER_TAM_MIN);
    (*artigo).tam_max =
            obterInt(MIN_TAM, MAX_TAM, OBTER_TAM_MAX);
}

void removerArtigos(Artigos *artigos) {
    int numero = procurarArtigo(*artigos,
            obterInt(MIN_NUM_ARTIGO, MAX_NUM_ARTIGO, MSG_OBTER_NUM_ARTIGO));
    if (numero != -1) {
        //Check de encomenda
        //(*artigos).artigos[numero].apagado = true;
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

//funções dos preços

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

void apagarDadosPreco(PrecoArtigo *preco){
    preco->tipo_artigo=0;
    preco->tam=0;
    preco->precoObra=0.0;
    preco->precoFixo=0.0;
    preco->precoTam=0.0;
    preco->margem=0.0;
}

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