#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Punkt {
    int p, q;
};

struct FunkcjaKwadratowa {
    int a, b, c;
    int delta;
    float x1, x2;
    struct Punkt wierzcholek;
};

void WczytajParametry(struct FunkcjaKwadratowa *parametr) {
    printf("Wprowadź a, b ,c\n");
    scanf("%d %d %d", &parametr->a, &parametr->b, &parametr->c);
    printf("f(x) = %dx^2 + %dx + %d\n", parametr->a, parametr->b, parametr->c);
}

void PoliczDelte (struct FunkcjaKwadratowa *parametr) {
    parametr->delta = parametr->b * parametr->b - 4 * parametr->a * parametr->c;
    printf("delta = %d\n", parametr->delta);
}

void WyznaczMiejscaZerowe (struct FunkcjaKwadratowa *parametr) {
    if (parametr->delta > 0) {
        parametr->x1 = -parametr->b - sqrtf(parametr->delta) / 2 * parametr->a;
        parametr->x2 = -parametr->b + sqrtf(parametr->delta) / 2 * parametr->a;
        printf("x1 = %.2f, x2 = %.2f \n", parametr->x1, parametr->x2);
    }
    else if (parametr->delta == 0) {
        parametr->x1 = -parametr->b / 2 * parametr->a;
        printf("x0 = %.2f\n", parametr->x1);
    }
    else {
        printf("brak miejsc zerowych\n");
    }
}

void PoliczWierzcholek(struct FunkcjaKwadratowa *parametr) {
    if (parametr->delta > 0) {
        parametr->wierzcholek.p = -parametr->b / 2 * parametr->a;
        parametr->wierzcholek.q = -parametr->delta / 4 * parametr->a;
        printf("p = %d; q = %d ", parametr->wierzcholek.p, parametr->wierzcholek.q);
    }
    else if (parametr->delta ==0) {
        parametr->wierzcholek.p = parametr->x1;
        parametr->wierzcholek.q = 0;
        printf("p = %d; q = %d ", parametr->wierzcholek.p, parametr->wierzcholek.q);
    }
}

int main() {
    struct FunkcjaKwadratowa *funkcjaKwadratowa=malloc(sizeof(struct FunkcjaKwadratowa));
    WczytajParametry(funkcjaKwadratowa);
    PoliczDelte(funkcjaKwadratowa);
    WyznaczMiejscaZerowe(funkcjaKwadratowa);
    PoliczWierzcholek(funkcjaKwadratowa);
    free(funkcjaKwadratowa);
    return 0;
 }