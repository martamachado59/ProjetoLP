/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   article_struct.h
 * Author: Marta
 * Author: Mara
 * Created on 2 de janeiro de 2022, 18:53
 */

#define MAX_ARTIGOS 50
#define ERRO_ARTIGO_NAO_EXISTE "O artigo não existe na lista."
#define ERRO_LISTA_ARTIGOS_VAZIA "A lista de artigos está vazia."
#define ERRO_LISTA_ARTIGOS_CHEIA "A lista de artigos está cheia."
#define ERRO_ARTIGO_EXISTE "O número de artigo já se encontra atribuído."

#define MAX_NOME_ARTIGO 50
#define MSG_OBTER_NOME "Insira o nome do artigo: "

#define MIN_NUM_ARTIGO 0
#define MAX_NUM_ARTIGO 1000
#define MSG_OBTER_NUM_ARTIGO "Insira um número de artigo [0-1000]: "

#define MIN_TAM 34
#define MAX_TAM 48
#define OBTER_TAM_MIN "Insira o tamanho minimo: "
#define OBTER_TAM_MAX "Insira o tamanho maximo: "

#define ERRO_LISTA_PRECOS_VAZIA "A lista de preços está vazia."
#define ERRO_PRECO_NAO_EXISTE "O preço não existe na lista."

#define MSG_OBTER_NUM_PRECO_TAM "Insira o tamanho para o preço [34-48]: "
#define MIN_PRECO 0.1
#define MAX_PRECO 1000.0
#define OBTER_PRECO_OBRA "Insira o preco obra especificado: "
#define OBTER_PRECO_FIXO "Insira o preco fixo especificado: "
#define OBTER_PRECO "Insira o preco para o tamanho especificado: "

#define MIN_MARGEM 0.1
#define MAX_MARGEM 1.0
#define OBTER_MARGEM "Insira a margem especificada: "

#define MIN_TIPO 1
#define MAX_TIPO 3
#define OBTER_TIPO "Insira o tipo [1-Botas; 2-Sapatos; 3-Sandalia]: "

enum tipo {
    Bota, Sapato, Sandalia
};

// struct dos artigos
typedef struct {
    int cod_artigo;
    char nome[MAX_NOME_ARTIGO];
    enum tipo tipo_artigo;
    int tam_min;
    int tam_max;
} Artigo;

typedef struct {
    int contador;
    Artigo artigos[MAX_ARTIGOS];
} Artigos;

//funções dos artigos

int inserirArtigos(Artigos *artigos);
int procurarArtigo(Artigos artigos, int cod_artigo);
void atualizarArtigos(Artigos *artigos);
void removerArtigos(Artigos *artigos);
void listarArtigos(Artigos artigos);

#define MAX_PRECOS 50

//struct para preços dos artigos
typedef struct {
    enum tipo tipo_artigo;
    int tam;
    double precoObra;
    double precoFixo;
    double precoTam;
    double margem;
} PrecoArtigo;

typedef struct {
    int contador;
    PrecoArtigo precos[MAX_PRECOS];
} Precos;

//funções de preços
int inserirPrecos(Precos *precos);
int procurarPreco(Precos precos, enum tipo tipo_artigo, int tam);
void atualizarPrecos(Precos *precos);
void removerPrecos(Precos *precos);
void listarPrecos(Precos precos);