//Examen 2019 Partie A Enoncé :

//On souhaite écrire un programme C pour conjuguer au présent un verbe du premier groupe régulier (se termine avec er).
//Le programme devra afficher la conjugaison du verbe pour tous les pronoms personnels.
//Exemple, Verbe: chanter
//Conjugaison:
//je chante,tu chantes,il chante,nous chantons,ils chantent
//On dispose des deux chaines de caractères constantes définies comme suit:
//char pronom_perso[]= « je#tu#il#nous#vous#ils >>
//char terminaison[]= »e#es#e#ons#ez#ent >>


#include <string.h>
#include <stdio.h>
#include <ctype.h>

//la fonction Qui permet de placer dans la chaine initial le pronom personnel de la i ème personne.
void initial_pronom_perso(const char *pronom_perso, int i, char *initial) {
    switch (i) {
        case 0: strncpy(initial, pronom_perso, 2); initial[2] = '\0'; break;
        case 1: strncpy(initial, pronom_perso + 3, 2); initial[2] = '\0'; break;
        case 2: strncpy(initial, pronom_perso + 6, 2); initial[2] = '\0'; break;
        case 3: strncpy(initial, pronom_perso + 9, 4); initial[4] = '\0'; break;
        case 4: strncpy(initial, pronom_perso + 14, 4); initial[4] = '\0'; break;
        case 5: strncpy(initial, pronom_perso + 19, 3); initial[3] = '\0'; break;
    }
}

//la fonction Qui permet de placer dans la chaine t la terminaison relative à la i ème personne.
void terminaison_pronom_perso(char *terminaison,int i, char *t){
    switch (i){
        case 0: strncpy(t, terminaison, 1); t[1] = '\0'; break;
        case 1: strncpy(t, terminaison+2, 2); t[2] = '\0'; break;
        case 2: strncpy(t, terminaison+5, 1); t[1] = '\0'; break;
        case 3: strncpy(t, terminaison+7, 3); t[3] = '\0'; break;
        case 4: strncpy(t, terminaison+11, 2); t[2] = '\0'; break;
        case 5: strncpy(t, terminaison+14, 3); t[3] = '\0'; break;
    }
}

//la fonction Qui retourne 1 si le verbe se termine par << er >> et 0 sinon
int est_premier_groupe(char *verbe){
    if(verbe[strlen(verbe)-1]=='r' && verbe[strlen(verbe)-2]=='e'){
        return 1;
    }
    else{return 0;}
}

//la fonction Qui place dans t le verbe en éliminant la terminaison << er >>
void verbe_sans_er(char *verbe, char *t){
    int len= strlen(verbe);
    verbe[len-2]='\0';
    strcpy(t,verbe);
    t[len-2]='\0';
}

//La fonction main qui accepte un verbe, vérifie s'il est du premier groupe et affiche sa conjugaison.
int main() {
    char pronom_perso[] = "je#tu#il#nous#vous#ils";
    char terminaison[] = "e#es#e#ons#ez#ent";
    char initial[5]; char termn[4];
    char verbe[20];
    printf("Saisir votre verbe du 1er groupe: ");
    scanf("%s",verbe);
    if(!est_premier_groupe(verbe)){
        printf("Le verbe n'est pas du 1er groupe.");
        return 0;
    }
    else{
        char Verbe[20];
        printf("Conjugaison du verbe %s : \n",verbe);
        verbe_sans_er(verbe,Verbe);
        for(int i=0;i<6;i++){
            terminaison_pronom_perso(terminaison,i,termn);
            initial_pronom_perso(pronom_perso,i,initial);
            printf("%s %s%s.\n",initial,Verbe,termn);
        }
    }
    return 0;
}
