#include <stdio.h>
#include <stdlib.h>

struct Poly {
    int coeff;
    int degree;
    struct Poly *next;
};

typedef struct Poly Poly;


void displayPoly(Poly *p);

Poly* createTerm(int coeff, int degree);
void insertTerm(Poly **p, int coeff, int degree);

void inputPoly(Poly **p);

Poly* multPoly(Poly **p1, Poly **p2);


int main() {
    Poly *p1 = NULL, *p2 = NULL;

    inputPoly(&p1);
    inputPoly(&p2);

    printf("\nPolynomial 1 : ");
    displayPoly(p1);
    printf("\nPolynomial 2 : ");
    displayPoly(p2);

    Poly *p3 = multPoly(&p1, &p2);
    printf("\nResult : ");
    displayPoly(p3);

    return 0;
}


Poly* createTerm(int coeff, int degree) {
    Poly *t = malloc(sizeof(Poly));
    t->coeff = coeff;
    t->degree = degree;
    t->next = NULL;
    
    return t;
}

void insertTerm(Poly **p, int coeff, int degree) {
    Poly *t = *p, *n;

    if (*p == NULL) {
        *p = createTerm(coeff, degree);
        return;
    }

    n = createTerm(coeff, degree);
    
    while ((*p)->next != NULL)
        *p = (*p)->next;

    (*p)->next = n;

    *p = t;
}

void displayPoly(Poly *p) {
    while (p != NULL) {
        printf("%d x^%d + ", p->coeff, p->degree);
        p = p->next;
    }
    printf("c\n");
}

void inputPoly(Poly **p) {
    static int j=1;
    int n;
    int coeff, degree;

    printf("\nEnter number of terms in polynomial %d : ", j);
    scanf("%d", &n);
    printf("Enter the terms in descending order of power\n");
    int i;
    for (i=0; i<n; i++) {
        printf("Coefficient of term : ");
        scanf("%d", &coeff);
        printf("Degree/Power of term : ");
        scanf("%d", &degree);

        insertTerm(p, coeff, degree);
    }

    j++;
}

Poly* multPoly(Poly **p1, Poly **p2) {
    Poly *t1 = *p1, *t2 = *p2;

    if ((*p1)->degree >= (*p2)->degree) {
        while ((*p1)->degree != (*p2)->degree) 
            *p1 = (*p1)->next;

        while ((*p2) != NULL) {
            (*p1)->coeff *= (*p2)->coeff;
            *p1 = (*p1)->next;
            *p2 = (*p2)->next;
        }

        *p1 = t1;
        return *p1;
    }
    else {
        while ((*p2)->degree != (*p1)->degree) 
            *p2 = (*p2)->next;

        while ((*p1) != NULL) {
            (*p2)->coeff *= (*p1)->coeff;
            *p1 = (*p1)->next;
            *p2 = (*p2)->next;
        }

        *p2 = t2;
        return *p2;
    }
}