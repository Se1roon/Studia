#include <stdio.h>
#include <stdlib.h>


typedef struct el_listy {
	int klucz;
	struct el_listy *nast;
} LISTA, *LISTAWSK;


int przegladanie(LISTA* p) {
	int licznik=0;
	while (p != NULL) {
		p=p->nast;
       
		if(p!=NULL) {
			licznik++;
            printf("klucz=%d licznik=%d\n", p->klucz, licznik);
		}          
	}     

	return licznik;
}

void dodaj_za(LISTA* p, int k) {
	LISTA *pom;
	pom=(LISTAWSK)malloc(sizeof(LISTA));
	pom->klucz=k;
	pom->nast=p->nast;
	p->nast=pom;
} 

void dodaj_przed(LISTA* p, int k) {
    LISTA *pom;
    pom=(LISTAWSK)malloc(sizeof(LISTA));
    pom->klucz=p->klucz;
    pom->nast=p->nast;
    p->klucz=k;
    p->nast=pom;
}

void usun_nast(LISTA* p) {
	LISTA *pom;
	if(p->nast!=NULL) {
		pom=p->nast;
		p->nast=pom->nast;
    } else
		printf("nie ma nastepnego\n"); 
} 

void usun(LISTA* glowa, LISTA* p) {
	LISTA *pom;
	pom=p->nast;
    if(pom==NULL) {
		pom=glowa;
		p=pom->nast;
		while (p->nast != NULL) {
			p=p->nast; pom=pom->nast;
		}     
		pom->nast=NULL;
    } else {
		/*
		 * p->klucz=pom->klucz;
		 * p->nast=pom->nast;
		*/
		*p=*pom; 
    }
}

LISTA *szukaj(LISTA* p, int k) { 
	while (p != NULL) {
		if(p->nast==NULL) return NULL;
        else {
			p=p->nast; //printf("---%d\n",p->klucz);
			if(p->klucz==k)return p;
        }
	}  

	return NULL;   
}


int liczrek(LISTA* p){
	//printf("%d\n",p->klucz);
	if (p->nast==NULL) return 0;

	return 1+liczrek(p->nast);
}

void przeglrewrek(LISTA* p) {
	if (p != NULL) {
		przeglrewrek(p->nast);
		printf("%d  \n",p->klucz); 
	}     
}

void przeglrek(LISTA* p) {
	if (p != NULL) {
		printf("%d  \n",p->klucz);
		przeglrek(p->nast); 
	}     
}

int maxrek(LISTA* p) {
	int max;
	if(p == NULL)
		return 0;

    if (p->nast == NULL)
        return p->klucz;

    max=maxrek(p->nast);
    if (p->klucz > max)
		return p->klucz;

	return max; 
}

LISTAWSK odwroc(LISTA* p) {
	LISTAWSK w3, w2=p, w1=NULL;
	while(w2!=NULL) { w3 = w2->nast; w2->nast=w1; w1=w2; w2=w3; }   

	return w1;     
}


//funkcja iteracyjna - znajdz element o kluczu x w posortowanej malejaco liscie i zamien go na y z zachowaniem kolejnosci
void zamien(int x, int y, LISTA *glowa) {
	LISTA* e = szukaj(glowa, x);

	if (e) {
		usun(glowa, e);

		LISTA* c = glowa->nast;
		while (c->klucz > y)
			c = c->nast;

		dodaj_przed(c, y);
	}
}

//funkcja rekurencyjna -- usun element o kluczu x z listy posortowanej rosnaco
int usunx(LISTA *p, int x) {
	if (p == NULL || p->nast == NULL) // koniec listy
		return 0;

	if (p->nast->klucz == x) { // znaleziono
		usun_nast(p);
		return 1;
	}
	
	if (p->nast->klucz > x) // nastepne elementy sa wieksze wiec sie juz nie znajdzie
		return 0;

	return usunx(p->nast, x);
}


//funkcja rekurencyjna -- usun element o kluczu x z listy posortowanej malejaco
int usun2x(LISTA *p, int x) {
	if (p == NULL || p->nast == NULL)  // koniec listy
		return 0;

	if (p->nast->klucz == x) { // znaleziono
		usun_nast(p);
		return 1;
	}
	
	if (p->nast->klucz < x) // juz sie nie znajdzie
	
	return usun2x(p->nast, x);
}

//funkcja iteracyjna - dodaj elemet o kluczu x do listy posortowanej rosnaco z zachowaniem kolejnosci
void dodaj_sort(int x, LISTA* g) {
	LISTA* c = g;
	while (c->klucz < x) 
		c = c->nast;

	dodaj_przed(c, x);
}


int main(int argc, char *argv[])
{
  int k, szk;
  int x,y;
  LISTA *glowa,*ost,*znal; 
  LISTA *pom;
  glowa=NULL;
  pom=(LISTA *)malloc(sizeof(LISTA));
  pom->klucz=0;
  pom->nast=NULL;
  glowa=pom;
  printf("podaj klucz kolejnego elementu listy 0 - koniec:\n");
  scanf("%d",&k);
  ost=glowa;
  while (k)
   {
    dodaj_za(ost, k);
    ost=ost->nast;
    printf("podaj klucz kolejnego elementu listy 0 - koniec listy:\n");
    scanf("%d",&k);
  }
  printf("przegladanie listy:  - %d\n", przegladanie(glowa));
  printf("dlugosc listy=%d\n",liczrek(glowa));

  glowa->nast=odwroc(glowa->nast);
  przegladanie(glowa);

  system("PAUSE");	
  return 0;
}

