#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED

#define ETUDIANT_H_INCLUDED
#include "structure_fich.h"

typedef struct etd{
    char nom[25];
    char prenom[25];
    ADRESSE adresse;
    NOTE tab_notes[5] ;
    float moyenne;
}ETUDIANT;
struct cellule
{
ETUDIANT valeur;
struct cellule *suivant;
};
typedef struct cellule *Liste;
ETUDIANT Lire_etudiant();
void Afficher_Etudiant(ETUDIANT E);
Liste Lire_Liste_etudiant(ETUDIANT ET, Liste Lst);
void affiche_Liste_etd(Liste Lst);
struct cellule*  recherche_Liste_etd(Liste Lst);
void modifier_etudiant(ETUDIANT *E);
struct cellule * supprimer_etudiant(Liste Lst);


#endif // ETUDIANT_H_INCLUDED
