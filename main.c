#include <stdio.h>
#include <stdlib.h>
#include "etudiant_fich.h"

int main()
    {


    int   choix=0 ;
    struct cellule *courrant;
    FILE *fichier;
    ETUDIANT etd ;
    char rep[3];
    Liste Lst=NULL;
    struct cellule* rech=NULL;
    while(1){
    printf("**********************\n");
    printf("          MENU        \n");
    printf("**********************\n");
    printf("1-saisir un etudiant :\n");
    printf("2-saisir un ensemble d'etudiant :\n" );
    printf("3-afficher un ensemble d'etudiant :\n");
    printf("4-Rechercher un etudiant:\n");
    printf("5-Modifier un etudiant:\n");
    printf("6-Supprimer un etudiant:\n");
    printf("0_quitter:\n");
    printf("introduire votre choix choix :");
    scanf("%d",&choix);
    int n;
    switch (choix)
    {
    case 1:{
        fichier=fopen("notes.txt","rt");
        if(fichier==NULL){
            printf("\n fichier erronee");
        }
        else{
            while(!feof(fichier)){
                fscanf(fichier , "%s %s %s %s %d %s %d %f %s %d %f %s %d %f %f \n",
                       etd.nom,
                       etd.prenom,
                       etd.adresse.ville,
                       etd.adresse.rue,
                       &etd.adresse.codepostale,
                       etd.tab_notes[0].matiere,
                       &etd.tab_notes[0].coeff,
                       &etd.tab_notes[0].note,
                       etd.tab_notes[1].matiere,
                       &etd.tab_notes[1].coeff,
                       &etd.tab_notes[1].note,
                       etd.tab_notes[2].matiere,
                       &etd.tab_notes[2].coeff,
                       &etd.tab_notes[2].note,
                       &etd.moyenne);
                Lst=Lire_Liste_etudiant(etd,Lst);
            }
        }



    }



        break;
    case 2:
        do{
                etd=Lire_etudiant();
                Lst=Lire_Liste_etudiant(etd,Lst);
                printf("\n voulez vous ajoutez un nouveau etudiant \n");
                scanf("%s",rep);

        }while (strcmp(rep,"oui")==0);


        break;
    case 3:
        affiche_Liste_etd( Lst);


        break;
    case 4:
        rech=recherche_Liste_etd(Lst);
        if(rech==NULL)
        {
            printf("etudiant introuvable \n");

        }
        else{
            Afficher_Etudiant(rech->valeur);
        }
            break;
    case 5:
       rech=recherche_Liste_etd(Lst);
        if(rech==NULL)
        {
            printf("etudiant introuvable \n");

        }
        else{
            Afficher_Etudiant(rech->valeur);
            printf("\n vous etes sure de vouloire modifier cet etudiant \n ");
            scanf("%s",rep);
            if (strcmp(rep,"oui")==0)
                    {
                        modifier_etudiant(&(rech->valeur));
                    }
            }
            break;
    case 6:
            Lst=supprimer_etudiant(Lst);
            break;
    case 0:
        fichier=fopen("notes.txt","w");
        if (fichier==NULL){
            printf("\n erreur d'ouverture de fichier");
        }
        else{
            courrant=Lst;
            while(courrant!=NULL){
                fprintf(fichier , "%s %s %s %s %d %s %d %f %s %d %f %s %d %f %f \n",
                        courrant->valeur.nom,
                        courrant->valeur.prenom,
                        courrant->valeur.adresse.rue,
                        courrant->valeur.adresse.ville,
                        courrant->valeur.adresse.codepostale,
                        courrant->valeur.tab_notes[0].matiere,
                        courrant->valeur.tab_notes[0].coeff,
                        courrant->valeur.tab_notes[0].note,
                        courrant->valeur.tab_notes[1].matiere,
                        courrant->valeur.tab_notes[1].coeff,
                        courrant->valeur.tab_notes[1].note,
                        courrant->valeur.tab_notes[2].matiere,
                        courrant->valeur.tab_notes[2].coeff,
                        courrant->valeur.tab_notes[2].note,
                        courrant->valeur.moyenne
                        );
                courrant=courrant->suivant;
            }

        }


        exit(0);
    default:
        printf("selectionner un choix :%d",choix);


    }
    }


}
