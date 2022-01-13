/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   input.h
 * Author: Marta
 * Author: Mara
 *
 * Created on 2 de janeiro de 2022, 17:11
 */

/**
 * Assinaturas das funções dos scanf
 */

int obterInt(int minValor, int maxValor, char *msg);
long obterLong(long minValor, long maxValor, char *msg);
float obterFloat(float minValor, float maxValor, char *msg);
double obterDouble(double minValor, double maxValor, char *msg);
char obterChar(char *msg);
void lerString(char *string, unsigned int tamanho, char *msg);

