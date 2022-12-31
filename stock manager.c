#include <string.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
char cat[7][150]={"categorie","Produits pour bebes et enfants","Sante, beaute, cosmetiques bio","Articles pour animaux de compagnie","Produits et accessoires pour le sport","Appareils electroniques et accessoires connectes","Alimentation"};
typedef struct
{
    int jour;
    int mois;
    int annee;
} date;
typedef struct
{
char nomproduit[20];
char categorie[150];
date dateentree;
date datesortie;
char description[1000];
int quantite;
int prix;

} produit;
int current_date ()
{
time_t d=time(NULL);
struct tm * t= localtime(&d);
printf("%d/%d/%d",t->tm_year+1900,t->tm_mon+1,t->tm_mday);
return 0 ;
}

int checkString(char str1[])
{
    int i,p;
    p=strlen(str1);
    for (i = 0; i < p ; i++)
    {
        if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] == ' '))
        {
            continue;
        }
        else{ return 0; }
    }
    return 1;
}

int compdate(int a, int m, int j)
{
int test=0 ;
time_t d=time(NULL);
struct tm * t= localtime(&d);

            if (a<t->tm_year+1900)
        {
           test=1;
        }
        if (a==t->tm_year+1900)
            {
            if ( m<t->tm_mon+1)
            {
           test=1;
            }

        if ((m==t->tm_mon+1) && (j<t->tm_mday+1))
            {
            test=1;
            }
        }
return test;
}

int verif_date (int m,int j,int a)
{
int test=0;
 if ((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))
      if ((j<=31)&&(j>=1))
        test=1;
if ((m==4)||(m==6)||(m==9)||(m==11))
     if ((j<=30)&&(j>=1))
        test=1;
if (m==2)
{
    if (a%4==0)
    {
       if ((j<=29)&&(j>=1))
            test=1;
    }
    else
        if ((j<=28)&&(j>=1))
            test=1;
}
return(test);
}

produit saisi()
{
    produit p;
    int i,k,choixC,choixC2;
    int n=0,choix;
    char C2[10],C[10],choixC3[10],choixj[10],choixm[10],choixa[10];
    FILE *fi;
    Color(13,0);
    printf("donner le nom du produit ");
    Color(15,0);
    fflush(stdin);
    gets(p.nomproduit);


    do
    {
    Color(13,0);
    printf("choisissez la categorie du produit \n ");
     Color(14,0);
    printf("\n\t | 1/Produits pour bebes et enfants  2/Sante, beaute, cosmetiques bio\n\t | 3/Articles pour animaux de compagnie         4/Produits et accessoires pour le sport\n\t | 5/Appareils electroniques et accessoires connectes    6/Alimentation\n");
    Color(15,0);
    scanf("%s",C);
    choixC=atoi(C);
        if(choixC==0)
            k=-1;
        else k=choixC;
    }while ((k<1)||(k>6));
    strcpy(p.categorie,cat[k]);
    Color(13,0);
    printf ("donner une description du produit ");
    Color(15,0);
    fflush(stdin);
    gets(p.description);

    do{
    Color(13,0);
    printf("donner la date d'entree \n");
    do{
    if (n==0){
    Color(8,0);
    printf("  jour:");
    Color(15,0);
    scanf("%s",choixj);
    }
    else
    {
    Color(4,0);
    printf("reecrire le jour:");
    Color(15,0);
    scanf("%s",choixj);
    }
    p.dateentree.jour=atoi(choixj);
    if(p.dateentree.jour==0)
    p.dateentree.jour=-1;
    n++;
    }while(p.dateentree.jour<1||p.dateentree.jour>31);
    n=0;
           do{
    if (n==0)
    {
    Color(8,0);
    printf("  mois:");
    Color(15,0);
    scanf("%s",choixm);
    }
    else
    {
    Color(4,0);
    printf("reecrire le mois: ");
    Color(15,0);
    scanf("%s",choixm);
    }
    p.dateentree.mois=atoi(choixm);
    if(p.dateentree.mois==0)
    p.dateentree.mois=-1;
    n++;
    }while(p.dateentree.mois<1||p.dateentree.mois>12);
    n=0;
    do{
      if (n==0)
      {
    Color(8,0);
    printf("  annee:");
    Color(15,0);
    scanf("%s",choixa);
    }
    else
    {Color(4,0);
    printf("reecrire l annee: ");
    Color(15,0);
    scanf("%s",choixa);
    }
    p.dateentree.annee=atoi(choixa);
    if(p.dateentree.annee==0)
    p.dateentree.annee=-1;
    n++;
    }while(p.dateentree.annee<1888);
    n=0;
    }while((verif_date(p.dateentree.mois,p.dateentree.jour,p.dateentree.annee)==0||(compdate(p.dateentree.annee,p.dateentree.mois,p.dateentree.jour)==0)));

 do{
    Color(13,0);
    printf("donner la date de sortie \n");
    do{
    if (n==0){
    Color(8,0);
    printf("  jour:");
    Color(15,0);
    scanf("%s",choixj);
    }
    else
    {
    Color(4,0);
    printf("reecrire le jour:");
    Color(15,0);
    scanf("%s",choixj);
    }
    p.datesortie.jour=atoi(choixj);
    if(p.datesortie.jour==0)
    p.datesortie.jour=-1;
    n++;
    }while(p.datesortie.jour<1||p.datesortie.jour>31);
    n=0;
           do{
    if (n==0)
    {
    Color(8,0);
    printf("  mois:");
    Color(15,0);
    scanf("%s",choixm);
    }
    else
    {
    Color(4,0);
    printf("reecrire le mois: ");
    Color(15,0);
    scanf("%s",choixm);
    }
    p.datesortie.mois=atoi(choixm);
    if(p.datesortie.mois==0)
    p.datesortie.mois=-1;
    n++;
    }while(p.datesortie.mois<1||p.datesortie.mois>12);
    n=0;
    do{
      if (n==0)
      {
    Color(8,0);
    printf("  annee:");
    Color(15,0);
    scanf("%s",choixa);
    }
    else
    {Color(4,0);
    printf("reecrire l annee: ");
    Color(15,0);
    scanf("%s",choixa);
    }
    p.datesortie.annee=atoi(choixa);
    if(p.datesortie.annee==0)
    p.datesortie.annee=-1;
    n++;
    }while(p.datesortie.annee<1888);
    n=0;
    }while((verif_date(p.datesortie.mois,p.datesortie.jour,p.datesortie.annee)==0)||(compdate(p.datesortie.annee,p.datesortie.mois,p.datesortie.jour)==0));


    Color(13,0);
    printf("donner la quantite du produit \n");
    Color(15,0);
    fflush(stdin);
    scanf("%d",&p.quantite);

    Color(13,0);
    printf("donner le prix \n");
    Color(15,0);
    fflush(stdin);
    scanf("%d",&p.prix);
    return(p);
}

void affiche (produit p)
{
    int i;
    Color(1,0);
    printf("\n");
    printf("\n le nom du produit est: ");
    Color(15,0);
    printf("%s ",p.nomproduit);
    Color(1,0);
    printf("\n la categorie est : ");
    Color(15,0);
    printf("%s ",p.categorie);
    Color(1,0);
    printf("\n date d'entree: ");
    Color(15,0);
    printf(" %d/%d/%d ",p.dateentree.jour,p.dateentree.mois,p.dateentree.annee);
    Color(1,0);
    printf("\n date de sortie : ");
    Color(15,0);
    printf(" %d/%d/%d ",p.datesortie.jour,p.datesortie.mois,p.datesortie.annee);
    Color(1,0);
    printf("\n description du produit:");
    Color(15,0);
    printf(" %s \n",p.description);
    Color(1,0);
    printf("\n quantite:");
    Color(15,0);
    printf(" %d \n",p.quantite);
    Color(1,0);
    printf("\n prix:");
    Color(15,0);
    printf(" %d \n",p.prix);
}
int saisirtab (produit tabproduit[],int n)
{
    int choixC,y;
    char choix[30];
    do
    {
        tabproduit[n]=saisi(n);
        n++;
         do {
            Color(14,0);
        printf("\t |1: ajouter un produit \n\t |2: Sortir\n ");
        Color(15,0);
        scanf ("%s",choix);
        choixC=atoi(choix);
        if(choixC==0)
            y=-1;
        else y=choixC;
        }while ((y<0)||(y>2));
    }while (y==1);

    return(n);
}

void affichetab (produit tabproduit[],int N)
{
    int i;
    for(i=0;i<N;i++)
        affiche(tabproduit[i]);
}

void recherchnom(produit tab[],int n)
{
    int i,b=0;
    char ti[30];
    Color(13,0);
    printf("donner le nom du produit: ");
    Color(15,0);
    gets(ti);
    gets(ti);
    for (i=0;i<n;i++)
       {

      if (strcmp(tab[i].nomproduit,ti)==0)
        {
            affiche(tab[i]);
            b=1;

        }
       }
        if (!b)
            printf("n'existe pas\n");

}

int rechnom(produit tab[], int n, char titre[30])
{ int i,k ;
    for (i=0;i<n;i++)
    {
        if (strcmp(tab[i].nomproduit,titre)==0)
            {k=i;
            break ;}
        else
            k=-1;
            }

    return (k);
}

void recherchecategorie(produit tab[],int n)   /***h*/
{
    int i,ca,g,b=0,choixC;
    char c[30];
    FILE *fi;
    do
    {
    printf("choisissez la catégorie du produit \n");
    Color(14,0);
    printf("\n\t | 1/Produits pour bebes et enfants  2/Sante, beaute, cosmetiques bio\n\t | 3/Articles pour animaux de compagnie        4/Produits et accessoires pour le sport\n\t | 5/Appareils electroniques et accessoires connectes   6/Alimentation \n");

    Color(15,0);
    scanf("%s",c);
    choixC=atoi(c);
        if(choixC==0)
            ca=-1;
        else ca=choixC;
    }while ((ca<1)||(ca>6));
    Color(15,0);
    for (i=0;i<n;i++)
    {
        if (strcmp(tab[i].categorie,cat[ca])==0)
        {

            affiche(tab[i]);
            b=1;
        }
    }
        if (!b)
            printf("n'existe pas\n");

}


void modifier(produit tab[],int n)
{   char mtitre[30],choixj[30],choixm[30],choixa[30];
    char ntitre[30],c[30],choix[30];
    int i,y=0,k,ca,g,choixC,t=0;
    FILE *fi;
    Color(14,0);

    do{
    if (y==0){
    Color(13,0);
    printf("entrez le nom du produit a modifier: ");
    Color(15,0);
    fflush(stdin);
    gets(mtitre);
    i=rechnom(tab, n, mtitre);
    }
    else
    {
    Color(4,0);
    printf("le titre est introuvable!\n recrire le titre:");
    Color(15,0);
    fflush(stdin);
    gets(mtitre);
    i=rechnom(tab, n, mtitre);
    }
    y++;
    }while(i==-1);
    do
    {
        Color(14,0);
        printf("\t |1:nom \n\t |2:categorie \n\t |3:date d'entree \n\t |4:date de sortie'\n ");
         Color(15,0);
        scanf ("%s",choix);
        choixC=atoi(choix);
        if(choixC==0)
        k=-1;
        else k=choixC;
    }while ((k<1)||(k>4));
     switch(k)
     {
         case(1):
             Color(13,0);
           printf("entrez le nouveau nom: ");
           Color(15,0);
           fflush(stdin);
           gets(ntitre);
           strcpy(tab[i].nomproduit,ntitre);
           affiche(tab[i]);
           break;
         case (2):
           do
           {
               Color(13,0);
               printf("choisissez la categorie du produit \n");
            Color(14,0);
            printf("\n\t | 1/Produits pour bebes et enfants  2/Sante, beaute, cosmetiques bio\n\t | 3/Articles pour animaux de compagnie        4/Produits et accessoires pour le sport\n\t | 5/Appareils electroniques et accessoires connectes   6/Alimentation\n");
           scanf("%s",c);
           choixC=atoi(c);
           if(choixC==0)
              ca=-1;
            else ca=choixC;
           }while ((ca<1)||(ca>6));
           /*fi=fopen("categorie.txt","rt");
           for (g=0;g<ca;g++)
           {
              fgets(tab[i].categorie,sizeof(tab[i].categorie),fi);
           }
           fclose(fi);*/
           strcpy(tab[i].categorie,cat[ca]);
           affiche(tab[i]);
           break;
         case(3):

            do{
            Color(14,0);
    printf("entrez la nouvelle date:\n");
    do{
    if (t==0){
            Color(8,0);
    printf("jour:");
    Color(15,0);
    scanf("%s",choixj);
    }
    else
    {
    Color(4,0);
    printf("reecrire le jour:");
    Color(15,0);
    scanf("%s",choixj);
    }
    tab[i].dateentree.jour=atoi(choixj);
    if(tab[i].dateentree.jour==0)
    tab[i].dateentree.jour=-1;
    t++;
    }while(tab[i].dateentree.jour<1||tab[i].dateentree.jour>31);
    t=0;
           do{
    if (t==0)
    {
        Color(8,0);
    printf("mois:");
    Color(15,0);
    scanf("%s",choixm);
    }
    else
    {
    Color(4,0);
    printf("reecrire le mois:");
    Color(15,0);
    scanf("%s",choixm);
    }
    tab[i].dateentree.mois=atoi(choixm);
    if(tab[i].dateentree.mois==0)
    tab[i].dateentree.mois=-1;
    t++;
    }while(tab[i].dateentree.mois<1||tab[i].dateentree.mois>12);
    t=0;
    do{
      if (t==0)
      {
          Color(8,0);
    printf("annee:");
    Color(15,0);
    scanf("%s",choixa);
    }
    else
    {Color(4,0);
    printf("reecrire l annee:");
    Color(15,0);
    scanf("%s",choixa);
    }
    tab[i].dateentree.annee=atoi(choixa);
    if(tab[i].dateentree.annee==0)
    tab[i].dateentree.annee=-1;
    t++;
    }while(tab[i].dateentree.annee<1888);
    t=0;
    }while((verif_date(tab[i].dateentree.mois,tab[i].dateentree.jour,tab[i].dateentree.annee)==0)||(compdate(tab[i].dateentree.annee,tab[i].dateentree.mois,tab[i].dateentree.jour)==0));
    affiche(tab[i]);
    break;

    case(4):

    do{
    Color(14,0);
    printf("entrez la nouvelle date:\n");
    do{
    if (t==0){
            Color(8,0);
    printf("jour:");
    Color(15,0);
    scanf("%s",choixj);
    }
    else
    {
    Color(4,0);
    printf("reecrire le jour:");
    Color(15,0);
    scanf("%s",choixj);
    }
    tab[i].datesortie.jour=atoi(choixj);
    if(tab[i].datesortie.jour==0)
    tab[i].datesortie.jour=-1;
    t++;
    }while(tab[i].datesortie.jour<1||tab[i].datesortie.jour>31);
    t=0;
           do{
    if (t==0)
    {
        Color(8,0);
    printf("mois:");
    Color(15,0);
    scanf("%s",choixm);
    }
    else
    {
    Color(4,0);
    printf("reecrire le mois:");
    Color(15,0);
    scanf("%s",choixm);
    }
    tab[i].datesortie.mois=atoi(choixm);
    if(tab[i].datesortie.mois==0)
    tab[i].datesortie.mois=-1;
    t++;
    }while(tab[i].datesortie.mois<1||tab[i].datesortie.mois>12);
    t=0;
    do{
      if (t==0)
      {
          Color(8,0);
    printf("annee:");
    Color(15,0);
    scanf("%s",choixa);
    }
    else
    {Color(4,0);
    printf("reecrire l annee:");
    Color(15,0);
    scanf("%s",choixa);
    }
    tab[i].datesortie.annee=atoi(choixa);
    if(tab[i].datesortie.annee==0)
    tab[i].datesortie.annee=-1;
    t++;
    }while(tab[i].datesortie.annee<1888);
    t=0;
    }while((verif_date(tab[i].datesortie.mois,tab[i].datesortie.jour,tab[i].datesortie.annee)==0)||(compdate(tab[i].datesortie.annee,tab[i].datesortie.mois,tab[i].datesortie.jour)==0));
    affiche(tab[i]);
    break;
}
};

int suprim (produit tab[], int n)
{    char ti[30], choix[5];
    int x,y,j,i,choixC,k=-1 ;
    produit t[100];

    Color(13,0);
    printf("donner le nom du produit a suprimer: ");
    Color(15,0);
    fflush(stdin);
    gets(ti);
     do {
        Color(14,0);
        printf("\t |1: Confirmez la supression de %s \n \t |2: Sortir \n ",ti);
        Color(15,0);
        scanf ("%s",choix);
        choixC=atoi(choix);
        if(choixC==0)
            y=-1;
        else y=choixC;
        }while ((y<0)||(y>2));
    switch(y)
    {
    case 1 :
    for (i=0;i<n-1;i++)
    {
        if (strcmp(tab[i].nomproduit,ti)!=0)
        {
            k++;
            t[i]=tab[k];
        }
        else
        {
            k=k+2;
            t[i]=tab[k];
        }
    }
    for (j=0;j<n-1;j++)
    {
        tab[j]=t[j];
    }

    affichetab(tab,n-1);
    x=n-1 ;

        break;
    case 0:
       break;
    }
    return(x);
}

void recherchetabproduit(produit tab[],int n)
{
    int y,choixC;
    char choix[20];
    do {
            Color(14,0);
        printf("\t |1:nom produit \n\t |2:categorie \n");
    Color(15,0);
        scanf ("%s",choix);
        choixC=atoi(choix);
        if(choixC==0)
            y=-1;
        else y=choixC;
        }while ((y<0)||(y>5));
    switch(y)
    {
    case(1):
         recherchnom(tab, n);
        break;
    case(2):
        recherchecategorie(tab,n);
        break;

    default:
        printf(" choix incorrect ");
    }
}
void Color(int couleurDuTexte,int couleurDeFond)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void save(produit tab[],int x)
{
    FILE *f;
    int i;
    f=fopen("produit.txt","a");
    if(f == NULL)
   {
      printf("Error!");
      exit(1);
   }
    for(i=0;i<x ;i++)
    {

        fprintf(f,"%s %s %d/%d/%d %d/%d/%d %s %d %d\n",tab[i].nomproduit,tab[i].categorie,tab[i].dateentree.jour,tab[i].dateentree.mois,tab[i].dateentree.annee
                ,tab[i].datesortie.jour,tab[i].datesortie.mois,tab[i].datesortie.annee, tab[i].description,tab[i].quantite,tab[i].prix);


    }

    fclose(f);


}


int main()
{
time_t d=time(NULL);
struct tm * t= localtime(&d);
   int i,x=0;
   int y;
   int n=0;
   char choix[10];
   int choixC;
    produit tab[30];
    produit donnee[100];
 FILE* f;
 Color(11,0);
printf("****************************************Bienvenue sur STOCK MANAGER****************************************************\n");
printf("******************************projet realise par Afef Abassi & Ichrak Bouafif******************************************\n");
sleep(1);



  while (1)
    {
        Color(10,0);

        printf("\tCurrent date: %d/%d/%d \n",t->tm_year+1900,t->tm_mon+1,t->tm_mday);
        printf("\tCurrent time: %d:%d \n",t->tm_hour,t->tm_min);
        Color(12,0);

        printf("\n                   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  ");
        printf("\n                  |1.Ajouter un produit                                |");
        printf("\n                  |2.Afficher le tableau des produits                  |");
        printf("\n                  |3.Rechercher un produit                             |");
        printf("\n                  |4.Modifier un produit                               |");
        printf("\n                  |5.Supprimer un produit                              |");
        printf("\n                  |6.Enregistrer les nouvelles donnees dans un fichier |");
        printf("\n                  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |");
        Color(4,0);

        do {
        printf("\n Votre choix est: ");
        Color(15,0);
        scanf ("%s",choix);
        choixC=atoi(choix);
        if(choixC==0)
            y=-1;
        else y=choixC;
        }while ((y<0)||(y>6));

        Color(15,0);
        switch(y)
        {

        case(1):
            {
            x=saisirtab (tab,x);
            } break;
        case(2):
            {
            Color(1,0);
            affichetab (tab,x);
            affichetab(donnee,i);}
            break ;
        case(3):
            {

           recherchetabproduit(tab,x);
            }break;
        case(4):
            {
            modifier( tab, x);
            } break ;
        case(5):
            {
             x=suprim (tab,  x);
            } break ;
        case(6):
            {
            save(tab, x);
            }



    }
    }
    return 0;
}
