#include<stdio.h>
#include<stdlib.h>


struct arvbin{
	char info;
	struct arvbin*esq;
	struct arvbin*dir;
};
typedef struct arvbin Arv;

Arv*arv_criavazia(void)
{
	return NULL;
}
Arv*cria_no_raiz(char c,Arv* sae,Arv* sad)
{
	Arv*novo=(Arv*)malloc(sizeof(Arv));
	novo->info=c;
	novo->esq=sae;
	novo->dir=sad;
	
	return novo;
}

void pre_ordem(Arv*a)
{
	if(a!=NULL){
	
	printf("%c",a->info);
	
	pre_ordem(a->esq);
	
	pre_ordem(a->dir);
				}
				
}
void pos_ordem(Arv*a)
{
	if(a!=NULL){
	
	pos_ordem(a->esq);
	
	pos_ordem(a->dir);
	printf("%c",a->info);
		}
}
void ordem_simetrica(Arv*a)
{
	if(a!=NULL){
	
	ordem_simetrica(a->esq);
	printf("%c",a->info);

	ordem_simetrica(a->dir);
			}
}
int main(){	
	Arv*a,*b,*e,*k,*l,*f,*c,*g,*d,*h,*m,*i,*j;
	
	j=cria_no_raiz('J',arv_criavazia(),arv_criavazia());
	i=cria_no_raiz('I',arv_criavazia(),j);
	m=cria_no_raiz('M',arv_criavazia(),arv_criavazia());
	h=cria_no_raiz('H',m,i);
	d=cria_no_raiz('D',h,arv_criavazia());
	g=cria_no_raiz('G',arv_criavazia(),arv_criavazia());
	c=cria_no_raiz('C',g,d);
	l=cria_no_raiz('L',arv_criavazia(),arv_criavazia());
	k=cria_no_raiz('K',arv_criavazia(),l);
	f=cria_no_raiz('F',arv_criavazia(),arv_criavazia());
	e=cria_no_raiz('E',k,f);
	b=cria_no_raiz('B',e,c);
	a=cria_no_raiz('A',b,arv_criavazia());
/*	a->esq=b;
	a->dir=NULL;
	
	b->esq=e;
	b->dir=c;
	
	
	e->esq=k;
	e->dir=f;
	
	
	k->esq=NULL;
	k->dir=l;
	
	
	l->esq=NULL;
	l->dir=NULL;
	
	
	
	f->esq=NULL;
	f->dir=NULL;

	
	c->esq=g;
	c->dir=d;
	
	
	g->esq=NULL;
	g->dir=NULL;
	
	
	d->esq=h;
	d->dir=NULL;
	
	
	h->esq=m;
	h->dir=i;
	
	
	
	m->esq=NULL;
	m->dir=NULL;
	
	
	i->esq=NULL;
	i->dir=j;
	
	
	j->esq=NULL;
	j->dir=NULL;*/
	

	
	

	
	pre_ordem(a);
	printf("\n");
	ordem_simetrica(a);
	printf("\n");
	pos_ordem(a);
	printf("\n");
	//Sucesso
	return 0;
}
