/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   order_struct.h
 * Author: Marta
 * Author: Mara
 * 
 * Created on 9 de janeiro de 2022, 21:56
 */

#define MAX_ARTIGOS_ENCOMENDA 50
#include "client_struct.h"
#include "article_struct.h"

//struct das encomendas

typedef struct {
    Cliente cliente;
    Artigo artigos[MAX_ARTIGOS_ENCOMENDA];
    int tamanhos[MAX_ARTIGOS_ENCOMENDA];
    double precoEncomenda;
    int contador;
} Encomenda;

//funções das encomendas

int inserirArtigoEncomenda(Encomenda *encomenda, Cliente *cliente, Artigo *artigo, Precos *precos);
int procurarArtigoEncomenda(Encomenda *encomenda, Artigo *artigo, int tam);
void listarArtigosEncomenda(Encomenda *encomenda);