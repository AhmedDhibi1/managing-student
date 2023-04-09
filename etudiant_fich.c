#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "etudiant_fich.h"

ETUDIANT Lire_etudiant()
{
    ETUDIANT E;
    float totcoef=0,totnotcoef=0;
    int i=0;
    printf("\n Intoduire le nom  ");
    scanf("%s",E.nom );
    printf ("\n Introduire le prenom  ");
    scanf("%s",E.prenom );
    printf("\n Introduire l'adresse  ");
    scanf ("%s %s %d",E.adresse.ville,E.adresse.rue,&E.adresse.codepostale);
    for (i=0;i<3;i++)
    {
        do{
            printf ("\n donner les notes des matieres :%d pour etudiant :  " ,i+1);
            scanf ("%s %f %d",E.tab_notes[i].matiere,&E.tab_notes[i].note,&E.tab_notes[i].coeff);
            if(0>E.tab_notes[i].note ||  20<E.tab_notes[i].note) printf(" \n ERREUR : valeur de la note inconvenable!! ");
        }while(E.tab_notes[i].note<0 || E.tab_notes[i].note>20);

    }
    for (i=0;i<3;i++)
    {
        totnotcoef+=E.tab_notes[i].note*E.tab_notes[i].coeff;
        totcoef+=E.tab_notes[i].coeff;
    }
    E.moyenne=totnotcoef/totcoef;
    return E ;
}
void Afficher_Etudiant(ETUDIANT E)
{
    printf("\n\n le nom est : %s",E.nom);
    printf("\n le prenom est : %s",E.prenom);
    printf("\n l'adresse est: %s  %s  %d",E.adresse.ville,E.adresse.rue,E.adresse.codepostale);
    printf("\n la moyenne est :%f",E.moyenne);
    for ( int i=0;i<3;i++)
    {
        printf("\n la matiere%d : %s %f %d",i+1,E.tab_notes[i].matiere,E.tab_notes[i].note,E.tab_notes[i].coeff);
    }
}

void modifier_etudiant(ETUDIANT *E)
{
    int choix ,n ,i ,totcoef=0;
    float totnotcoef=0;
    ETUDIANT Etd ;
    Etd=*E;
    printf("\n que voulez vous modifier :");
    printf("\n 1-nom et prenom ");
    printf("\n 2-adresse");
    printf("\n 3-la note");
    printf("\n 0-quitter");
    printf("introduit votre choix :");
    scanf("%d ",&choix);
    switch(choix)
    {
    case 1:
        {
            scanf("%s",Etd.nom);
            scanf("%s",Etd.prenom);
            break;
        }
    case 2:
        {
            printf("\n introduire l'adresse sous la forme : rue ville  code postale:");
            scanf("%s %s %d",Etd.adresse.rue,Etd.adresse.ville,&Etd.adresse.codepostale);

        }
    case 3:
        {
            do
            {


            printf("\n introduire l'indice de note a modifier(1..3)");
            scanf("%d",&n);
            }while(n<1||n>3);
            printf("\n %d : introduire matiere coef note",n);
            scanf("%s %d %f",Etd.tab_notes[n-1].matiere,Etd.tab_notes[n-1].coeff,Etd.tab_notes[n-1].note);
            for(i=0 ; i<3 ;i++)
            {
                totnotcoef+=Etd.tab_notes[i].note*Etd.tab_notes[i].coeff;
                totcoef+=Etd.tab_notes[i].coeff;
            }
            Etd.moyenne=totnotcoef/totcoef;
            break;
        }
    case 0:
        {
            break;
        }
    default:
        printf("\n choix erroné");
    }
    *E=Etd;
}

Liste Lire_Liste_etudiant(ETUDIANT ET, Liste Lst)
{
  struct cellule * Courrant;
  Courrant = (struct cellule *)malloc(sizeof(struct cellule));
  Courrant ->valeur = ET;
  Courrant ->suivant = Lst;
  return(Courrant);
}

void affiche_Liste_etd(Liste Lst)
{
   struct cellule* courrant;
   courrant =Lst;
   while (courrant!=NULL)
   {
     Afficher_Etudiant(courrant ->valeur);
     courrant=courrant->suivant;
   }
   printf("\n");
}

struct cellule*  recherche_Liste_etd(Liste Lst)
{
  char nomrech[25],prenomrech[25];
  printf("\n donner le nom");
  scanf("%s",nomrech);
  printf("\n donner le prenom");
  scanf("%s",prenomrech);

   struct cellule* courrant;
   courrant =Lst;
   while (courrant!=NULL)
    {
        if(strcmp(courrant->valeur.nom,nomrech)==0 && strcmp(courrant->valeur.prenom,prenomrech)==0){
            return courrant;
        }
        courrant=courrant->suivant;

    }
    return NULL;
}
struct cellule * supprimer_etudiant(Liste Lst){
    char nom_rech[25],prenom_rech[25];
    struct cellule *courrant;
    struct cellule *preds;
    courrant=Lst;
    preds=NULL;
    printf("donner le nom  : ");
    scanf("%s",nom_rech);
    printf("donner le prenom : ");
    scanf("%s",prenom_rech);
    while(courrant!=NULL){
        if((strcmp(courrant->valeur.nom,nom_rech)==0)&&(strcmp(courrant->valeur.prenom,prenom_rech)==0))
            break;
            preds=courrant;
            courrant=courrant->suivant;

    }
    if(courrant){
        if(preds){
            preds->suivant=courrant->suivant;
        }
        else
            Lst=courrant->suivant;
        free(courrant);

    }
    else
        printf("nom (ou prenom) erronee ou etudiant introuvable...! veuillez verifier le nom  (ou prenom)  ");
    return Lst;

}
