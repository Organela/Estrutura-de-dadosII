
#include<stdlib.h>
#include<stdio.h>
#include<locale.h>

struct arv {
  int info;
  struct arv* esq;
  struct arv* dir;
};
typedef struct arv Arv;


Arv* arv_criavazia (void){
     return NULL;
}

int arv_vazia (Arv* a){
    return a==NULL;
}


Arv* arv_libera (Arv* a){
     if (!arv_vazia(a)){
        arv_libera(a->esq); /* libera sae */
        arv_libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
     }
     return NULL;
}
Arv*abb_insere(Arv*a,int v)
{
	if (a==NULL) { 
		a = (Arv*)malloc(sizeof(Arv)); 
		a->info= v; 
		a->esq = a->dir = NULL; 
		} 
		else if (v < a->info)
	 		a->esq = abb_insere(a->esq,v);
	 	else/* v < a->info*/ 
			a->dir = abb_insere(a->dir,v); 
		return a;
}
	/*{if(arv_vazia(a)){
		Arv*novo=(Arv*)malloc(sizeof(Arv));
		a->info=v;
		a->esq=NULL;
		a->dir=NULL;
	}else
		Arv*novo=(Arv*)malloc(sizeof(Arv));
		while(novo!=NULL){
		
		if(v<a->info){
			a->esq=novo;
			novo->esq=arv_criavazia();
			novo->dir=arv_cria_vazia();
		}else
			if(v>a->info){
				a->dir=novo;	
				novo->esq=arv_criavazia();
				novo->dir=arv_cria_vazia();
			}
			
	}
		return a;}*/

void imprime_crescente(Arv*a)
{
	if(arv_vazia(a))return ;
	else{
	
		imprime_crescente(a->esq);
		printf(" %d ",a->info);
		imprime_crescente(a->dir);
	}
}
Arv*abb_busca(Arv*r,int v)
{
	if(arv_vazia(r))return NULL;
	
	
	
		if(v < r->info)return abb_busca(r->esq,v);
		if(v > r->info)return abb_busca(r->dir,v);
	
	else return r;
}
void showmenor(Arv* a, int x)
{
	if(arv_vazia(a))return ;
	
	showmenor(a->esq,x);
	
	if(a->info<x){
		printf("%d\n",a->info);
		showmenor(a->dir,x);
	}
}
Arv* menor (Arv* a)
{
	Arv*menor;
	Arv*aux;
	menor=a;
	
	while(menor!=NULL)
	{	
		aux=menor;
		menor=menor->esq;
	}
	menor=aux;
	return menor;
} 
Arv* busca_no (Arv* a)
{	
	Arv*aux=a->esq;
	while(aux->dir!=NULL)aux=aux->dir;
	return aux;
	
	/*Arv*z=a;
	int aux=a->info;
	while(z!=NULL)
	{
		if(z->info==aux)return z;
		else
		if(aux < a->info)z=z->dir;
		else
		z=z->dir;
	}
	return NULL;*/
}
int main(){
	setlocale(LC_ALL,"portuguese");
    
    Arv*a;
    a = arv_criavazia();

    /*Vai inserir, recursivamente, valores na árvore - implementar "Arv* abb_insere (Arv* a, int v)" */
    a = abb_insere (a,6);
    a = abb_insere (a,2);
    a = abb_insere (a,8);
    a = abb_insere (a,1);
    a = abb_insere (a,4);
    a = abb_insere (a,3);

    /* Vai imprimir, recursivamente, todos os elementos em ordem crescente - implementar "void imprime_crescente(Arv *a)"*/
    imprime_crescente(a); 
    printf("\n");

    /*Vai buscar, recursivamente, um valor na árvore - implementar "Arv* abb_busca (Arv* r, int v)"*/
    Arv*k = abb_busca(a,1);
    if (k!=NULL) printf(" info = %d\n", k->info);
    printf("\n");

    /*imprime, recursivamente, todos os valores nos nós da árvore que sejam menores que x, em ordem
crescente - implementar "void showmenor(Arv* a, int x)".*/
    showmenor(a,5);
    printf("\n");

    /* Encontra, iterativamente, um ponteiro para o menor valor da árvore - implementar "Arv* menor (Arv* a)"*/
    k = menor(a);
    if (k!=NULL) printf(" A menor informacao = %d\n", k->info);

   /* Encontra, iterativamente, o valor que antecede a raiz - implementar "Arv* busca_no (Arv* a)"*/
    printf("\n");
    k = busca_no(a);
    if (k!=NULL) printf(" Valor que antecede a raiz = %d\n", k->info);
	else printf("Não ha valor!");

    arv_libera(a);
    system("pause");
    return 0; 
	
}




