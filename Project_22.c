//Examen Janvier 2020 Partie C Enoncé :
//Ecrire un programme C qui permet de résoudre une équation de second degrés ax2 +bx+c.
//Le programme accepte les paramètres de l'équation a, b et c (des réels)
//Il doit afficher le nombre de solutions et les solutions possibles.

#include <stdio.h>
#include <math.h>

int main() {
    float a,b,c,D,x1,x2;
    //Saisie des parametres a , b et c.
    printf("Saisir les parametres a , b et c:\n");
    do{
        printf("a= ");scanf("%f",&a);
    }while(a<=0);
    printf("b= ");scanf("%f",&b);
    printf("c= ");scanf("%f",&c);

    //Calcul du delta D.
    D= pow(b,2) - (4*a*c);

    printf("Votre equation %fx^2 + %fx +%f = 0",a,b,c);
  
    //Cas ou D=0 , D<0 ou D>0.
    if(D<0){//Aucune solution
        printf(" n'admet aucune solution.");
    }
    else if(D==0){//Solution double
        x1=(-b)/2*a;
        printf(" admet une solution double x1=x2=%f",x1);
    }
    else{//2 Solutions
        float racine_D=sqrt(D);
        x1=(-b-racine_D)/(2*a);
        x2=(-b+racine_D)/(2*a);
        printf(" admet deux solution : x1=%f et x2=%f",x1,x2);
    }

    return 0;
}
