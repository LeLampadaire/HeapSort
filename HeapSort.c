#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

void SAISIE_VEC(int *, short);
void AFFICHE_VEC(int *, short);
void HEAPSORT(int *, short);
void PATERNER(int *, int, short);
void ECHANGE(int *, int *);

int main(){
    int vec[MAX];
    short n=0;
    srand(time(NULL));

    do{
        printf("Encodez la longueur du vecteur : ");
        fflush(stdin);
        scanf("%hd",&n);
    }while(n <= 0 || n > MAX);

    SAISIE_VEC(&vec[0], n);

    printf("Avant l'execution du tri : \n");
    AFFICHE_VEC(&vec[0], n);
    HEAPSORT(&vec[0], n);
    printf("\nApres l'execution du tri : \n");
    AFFICHE_VEC(&vec[0], n);

    return 0;
}

/*****************************************************************************/
/* INPUT : Récupère l'adresse de départ du vecteur et sa taille              */
/* PROCESS : Rempli le vecteur aléatoirement avec des nombres de 1 à 20      */
/* OUTPUT :                                                                  */
/*****************************************************************************/
void SAISIE_VEC(int *p, short n){
    short i=0, choix=0;

    do{
        printf("\nChoisir la methode de remplissage : ");
        printf("\n1: Remplissage aleatoire");
        printf("\n2: Remplissage manuel");
        printf("\nVotre choix : ");
        fflush(stdin);
        scanf("%hd",&choix);

        if(choix == 1){
            for(i=0;i<n;i++,p++){
                *p = rand() % 21;
            }
        }else if(choix == 2){
            printf("\n");
            for(i=0;i<n;i++,p++){
                do{
                    printf("Encodez un nombre [%hd] : ",i+1);
                    fflush(stdin);
                    scanf("%d",p);
                }while(*p < 0 || *p > 20);
            }
        }

    }while(choix != 1 && choix != 2);

}

/*****************************************************************************/
/* INPUT : Récupère l'adresse de départ du vecteur et sa taille              */
/* PROCESS : Affiche le vecteur                                              */
/* OUTPUT :                                                                  */
/*****************************************************************************/
void AFFICHE_VEC(int *p, short n){
    short i=0;

    printf("\n");
    for(i=0;i<n;i++,p++){
        printf("%d\t", *p);
    }
    printf("\n");
}

/*****************************************************************************/
/* INPUT : Récupère le pointeur du père et du fils                           */
/* PROCESS : Echange le contenu des deux variables                           */
/* OUTPUT :                                                                  */
/*****************************************************************************/
void ECHANGE(int *Pere, int *Fils){
    int tempo=0;

    tempo = *Pere;
    *Pere = *Fils;
    *Fils = tempo;
}

/*****************************************************************************/
/* INPUT : Récupère l'adresse de départ du vecteur et sa taille              */
/* PROCESS : Trie le vecteur                                                 */
/* OUTPUT :                                                                  */
/*****************************************************************************/
void HEAPSORT(int *p, short n){
    short iPere=0;
    iPere = ((n+1)/2)-1;

    while(iPere>=0){
        PATERNER(p, iPere, n);
        iPere--;
    }

    iPere = n-1;
    while(iPere >= 0){
        ECHANGE((p+iPere), p);
        PATERNER(p, 0, iPere);
        iPere--;
    }
}

/****************************************************************************************************************************************************************/
/* INPUT : Récupère l'adresse de départ du vecteur, l'indice du premier père et la taille du vecteur                                                            */
/* PROCESS : Vérifie qui est le plus grand des 2 fils du père, puis si le plus grand des fils est plus grand que le père on fait appel à la fonction ECHANGER   */
/* OUTPUT :                                                                                                                                                     */
/****************************************************************************************************************************************************************/
void PATERNER(int *p, int iPere, short n){
    int *Pere, *Fils;
    short iFils1=0, iFils2=0;

    // Indices
    iFils1 = (iPere*2)+1;
    iFils2 = iFils1+1;

    // Pointeurs
    Pere = p + iPere;
    Fils = p + iFils1;

    if(iFils2<n && *(Fils+1)>*Fils){
        if(*(Fils+1)>*Pere){
            ECHANGE(Pere, Fils+1);
            PATERNER(p,iFils2,n);
        }
    }else{
        if(iFils1<n && *Fils>*Pere){
            ECHANGE(Pere, Fils);
            PATERNER(p,iFils1,n);
        }
    }
}
