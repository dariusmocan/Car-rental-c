#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct masini{
    char nume[20];
    char model[20];
    char locuri[5];
    char disp[5];
}masina[100];

void afisare(char path[])
{
    system("cls");
    printf("\033[1;31m");
    printf("    -AUTOTURISME-\n");

    FILE *filep;
    filep=fopen(path,"r");
    int nr,i=0;

    if(filep==NULL)
    {
        printf("Fisierul nu poate fi accesat");
    }
    else
    {
    while(fgets(masina[i].nume,20,filep)!=NULL)
    {
        fgets(masina[i].nume,20,filep);
        //fgets(masina[i].nume,20,filep);
        fgets(masina[i].model,20,filep);
        fgets(masina[i].locuri,5,filep);
        fgets(masina[i].disp,5,filep);
        i=i+1;
    }
    }
    nr=i;
    for(i=0;i<nr;i++)
    {
        printf("%d.%s %s locuri:%s disponibilitate:%s\n",i+1,masina[i].nume,masina[i].model,masina[i].locuri,masina[i].disp);
    }
    fclose(filep);
    printf("\033[0m");
    system("pause");
}

void adaugare(char path[])
{
    system("cls");
    printf("\033[1;32m");
    printf("    -ADAUGATI UN AUTOMOBIL-\n");

    FILE *filep;
    filep=fopen(path,"a");
    char nume[20],model[20];
    int loc,disp;
    printf("Introduceti marca masinii\n");
    scanf("%s",nume);
    getchar();
    printf("Introduceti modelul masinii\n");
    scanf("%[^\n]",model);
    getchar();
    printf("Introduceti locurile libere\n");
    scanf("%d",&loc);
    printf("Introduceti disponibilitatea masinii\n");
    scanf("%d",&disp);

    if(filep==NULL)
    {
        printf("Fisierul nu poate fi accesat\n");
    }
    else
    {
        fprintf(filep,"\n%s\n%s\n%d\n%d\n", nume, model, loc,disp);
        fclose(filep);
        printf("Masina dumneavoastra a fost inregistrata\n");
    }
    printf("\033[0m");
    system("pause");
}

void rezervare(char path[])
{
    system("cls");
    printf("\033[0;33m");
    printf("    -REZERVATI UN AUTOMOBIL-\n");
    FILE *filep;
    filep=fopen(path,"r");
    int nr,i=0;
    int choice=0;

    if(filep==NULL)
    {
        printf("Fisierul nu poate fi accesat");
    }
    else
    {
    while(fgets(masina[i].nume,20,filep)!=NULL)
    {
        fgets(masina[i].nume,20,filep);
        fgets(masina[i].model,20,filep);
        fgets(masina[i].locuri,5,filep);
        fgets(masina[i].disp,5,filep);
        i=i+1;
    }
    nr=i;
    for(i=0;i<nr;i++)
    {
        if(strchr(masina[i].disp,'1'))
            printf("%d.%s %s locuri:%s disponibilitate:%s\n",i+1,masina[i].nume,masina[i].model,masina[i].locuri,masina[i].disp);
    }
    fclose(filep);
    choice=getch();
    //char nume[]="auxiliar.TXT";
    FILE *fp;
    fp=fopen(path,"w");
    for(i=0;i<nr;i++)
    {
        if(i==choice-49)
            fprintf(fp,"\n%s%s%s%s\n", masina[i].nume, masina[i].model,masina[i].locuri,"0");
        else
            fprintf(fp,"\n%s%s%s%s", masina[i].nume, masina[i].model,masina[i].locuri,masina[i].disp);
    }
    fclose(fp);
    printf("\033[0m");
    system("pause");
    }
}

void anulare(char path[])
{
    system("cls");
    printf("\033[1;34m");
    printf("    -ANULATI REZERVAREA UNUI AUTOMOBIL-\n");
    FILE *filep;
    filep=fopen(path,"r");
    int nr,i=0;
    int choice=0;

    if(filep==NULL)
    {
        printf("Fisierul nu poate fi accesat");
    }
    else
    {
    while(fgets(masina[i].nume,20,filep)!=NULL)
    {
        fgets(masina[i].nume,20,filep);
        fgets(masina[i].model,20,filep);
        fgets(masina[i].locuri,5,filep);
        fgets(masina[i].disp,5,filep);
        i=i+1;
    }
    nr=i;
    for(i=0;i<nr;i++)
    {
        if(strchr(masina[i].disp,'0'))
            printf("%d.%s %s locuri:%s disponibilitate:%s\n",i+1,masina[i].nume,masina[i].model,masina[i].locuri,masina[i].disp);
    }
    fclose(filep);
    choice=getch();
    //char nume[]="auxiliar.TXT";
    FILE *fp;
    fp=fopen(path,"w");
    for(i=0;i<nr;i++)
    {
        if(i==choice-49)
            fprintf(fp,"\n%s%s%s%s\n", masina[i].nume, masina[i].model,masina[i].locuri,"1");
        else
            fprintf(fp,"\n%s%s%s%s", masina[i].nume, masina[i].model,masina[i].locuri,masina[i].disp);
    }
    fclose(fp);
    printf("\033[0m");
    system("pause");
    }
}

void stergere(char path[])
{
    system("cls");
    printf("\033[1;35m");
    printf("    -STERGETI UN AUTOMOBIL-\n");

    FILE *filep;
    filep=fopen(path,"r");
    int nr,i=0;

    if(filep==NULL)
    {
        printf("Fisierul nu poate fi accesat");
    }
    else
    {
    while(fgets(masina[i].nume,20,filep)!=NULL)
    {
        fgets(masina[i].nume,20,filep);
        fgets(masina[i].model,20,filep);
        fgets(masina[i].locuri,5,filep);
        fgets(masina[i].disp,5,filep);
        i=i+1;
    }
    }
    nr=i;
    for(i=0;i<nr;i++)
    {
        printf("%d.%s %s locuri:%s disponibilitate:%s\n",i+1,masina[i].nume,masina[i].model,masina[i].locuri,masina[i].disp);
    }
    fclose(filep);
    FILE *fp;
    //char nume[]="auxiliar.TXT";
    fp=fopen(path,"w");
    int choice=0;
    choice=getch();
    for(i=0;i<nr;i++)
    {
        if(i!=choice-49)
            fprintf(fp,"\n%s%s%s%s", masina[i].nume, masina[i].model,masina[i].locuri,masina[i].disp);
    }
    fclose(fp);
    printf("\033[0m");
    system("pause");
}

void actualizare(char path[])
{
    system("cls");
    printf("\033[0;35m");
    printf("    -ACTUALIZATI NUMARUL DE LOCURI-");
    FILE *filep;
    filep=fopen(path,"r");
    int nr,i=0;

    if(filep==NULL)
    {
        printf("Fisierul nu poate fi accesat");
    }
    else
    {
    while(fgets(masina[i].nume,20,filep)!=NULL)
    {
        fgets(masina[i].nume,20,filep);
        fgets(masina[i].model,20,filep);
        fgets(masina[i].locuri,5,filep);
        fgets(masina[i].disp,5,filep);
        i=i+1;
    }
    }
    nr=i;
    for(i=0;i<nr;i++)
    {
        printf("%d.%s %s locuri:%s disponibilitate:%s\n",i+1,masina[i].nume,masina[i].model,masina[i].locuri,masina[i].disp);
    }
    fclose(filep);
    FILE *fp;
    //char nume[]="auxiliar.TXT";
    fp=fopen(path,"w");
    int numar;
    char loc[5];

    printf("Alegeti masina dorita\n");
    scanf("%d",&numar);
    numar--;
    printf("Introduceti numarul de locuri disponibile\n");
    scanf("%s",&loc);
    for(i=0;i<nr;i++)
    {
        if(i==numar)
        {
            fprintf(fp,"\n%s%s%s\n%s", masina[i].nume, masina[i].model,loc,masina[i].disp);
        }
        else
            fprintf(fp,"\n%s%s%s%s", masina[i].nume, masina[i].model,masina[i].locuri,masina[i].disp);
    }
    fclose(fp);
    printf("\033[0m");
    system("pause");
}

void meniu(char path[]){
    int choice = 0;
    while(1){
        system("cls");
        printf("\033[1;33m");
        printf("     ---------------MENIU---------------\n");
        printf("\033[1;31m");
        printf("    (1) Afisare autoturisme\n");
        printf("\033[1;32m");
        printf("    (2) Adaugare autoturism\n");
        printf("\033[0;33m");
        printf("    (3) Rezervare autoturisme\n");
        printf("\033[1;34m");
        printf("    (4) Anulare rezervare autoturisme\n");
        printf("\033[1;35m");
        printf("    (5) Stergere autoturism\n");
        printf("\033[0;35m");
        printf("    (6) Actualizare autoturism\n");
        printf("\033[1;36m");
        printf("    (esc) Iesiti din meniu\n");
        printf("\033[0;34m");
            printf("Introduceti varianta corecta\n");
        printf("\033[0m");
        if(kbhit)
            choice=getch();
        if (choice=='1')
            afisare(path);

        if (choice=='2')
            adaugare(path);

        if (choice=='3')
            rezervare(path);

        if (choice=='4')
            anulare(path);

        if (choice=='5')
            stergere(path);

        if (choice=='6')
            actualizare(path);

        if (choice==27)
            return 0;
        }
}

int main()
{
    char path[]="fisier.txt";

    meniu(path);
    return 0;
}
