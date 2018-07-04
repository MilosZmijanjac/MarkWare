#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <direct.h>
#include <ctype.h>
#include <time.h>
#define ANS 15
#define ACS 4
 COORD coord={0,0}; //kordinata na konzoli
double suma=0.0;
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

typedef struct { int sifra; char naziv[21]; double kol, cijena; } ARTIKAL;
typedef struct cvor { ARTIKAL art; struct cvor *lijevi, *desni; } CVOR;
typedef struct korisnik { char ime[21], prezime[21], k_ime[21], sifra[21];int uloga; } KORISNIK;
typedef struct cvork { KORISNIK kor; struct cvork *lijevi, *desni; } CVOR_K;
char*sat()
{
    time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  return asctime (timeinfo) ;
}

void pass(char*str) {
	char c = ' ';
	int i = 0;
	while (1) {
		c = getch();

		if (c == 13) break;
		else if (c == 8)
		{
			printf("\b \b");

			str[--i] = '\0';

		}
		else if (c != ' '&&c != '\b') {
			putchar('*');
			str[i++] = c;
		}

	}
	str[i] = '\0';
	system("cls");
}
void admin()
{
	FILE*dat = fopen("C:\\Program Files\\MarkWare\\admini.dat", "a+b");
	KORISNIK k;
	printf("Unesite ime: "); scanf("%s", k.k_ime);
	printf("Unesite prezime: "); scanf("%s", k.prezime);
	labela:
	printf("Unesite korisnicko ime: "); scanf("%s", k.k_ime);
	FILE*pom=fopen("C:\\Program Files\\MarkWare\\korisnici.dat","rb");
		FILE*pom1=fopen("C:\\Program Files\\MarkWare\\admini.dat","rb");
		KORISNIK kpom;
		while(fread(&kpom,sizeof(KORISNIK), 1, pom))
            if(!strcmp(kpom.k_ime,k.k_ime))
        {
            printf("\nKorisnicko ime je vec u upotrebi\n\n");
            fclose(pom);
            goto labela;
        }
        while(fread(&kpom,sizeof(KORISNIK), 1, pom1))
            if(!strcmp(kpom.k_ime,k.k_ime))
        {
            printf("\nKorisnicko ime je vec u upotrebi\n\n");
            fclose(pom1);
            goto labela;
        }
        	printf("Unesite sifru: "); pass(k.sifra);

	k.uloga=1;
	fwrite(&k, sizeof(KORISNIK), 1, dat);
	fclose(dat);
}

void registracija()
{
	KORISNIK k;
	FILE*dat;

	if ((dat = fopen("C:\\Program Files\\MarkWare\\korisnici.dat", "ab")))
	{
		printf("Unesite ime: "); scanf("%s", k.ime);
		printf("Unesite prezime: "); scanf("%s", k.prezime);
		labela:
		printf("Unesite korisnicko ime: "); scanf("%s", k.k_ime);

		FILE*pom=fopen("C:\\Program Files\\MarkWare\\korisnici.dat","rb");
		FILE*pom1=fopen("C:\\Program Files\\MarkWare\\admini.dat","rb");
		KORISNIK kpom;
		while(fread(&kpom,sizeof(KORISNIK), 1, pom))
            if(!strcmp(kpom.k_ime,k.k_ime))
        {
            printf("\nKorisnicko ime je vec u upotrebi\n\n");
            fclose(pom);
            goto labela;
        }
        while(fread(&kpom,sizeof(KORISNIK), 1, pom1))
            if(!strcmp(kpom.k_ime,k.k_ime))
        {
            printf("\nKorisnicko ime je vec u upotrebi\n\n");
            fclose(pom1);
            goto labela;
        }
        printf("Unesite sifru: "); pass(k.sifra);
        fclose(pom);
        fclose(pom1);
		printf("1-Sacuvaj\n2-Nazad");
		int i;
		scanf("%d", &i);
		if (i == 1)
		{
			fwrite(&k, sizeof(KORISNIK), 1, dat); fclose(dat); return;
		}
		else
		{
			fclose(dat); return;
		}
	}
	else
		printf("\nGreska pri otvaranju datoteke");
}
void login(KORISNIK *a)
{

	system("cls");
	gotoxy(15,3);printf("Unesite korisnicko ime: ");

	scanf("%s", a->k_ime);
	gotoxy(15,4);printf("Unesite sifru: ");

	pass(a->sifra);

}
void logo()
{
    printf("\n");
	printf("\n");
	printf("                        -//.         .:/-                      \n");
	printf("                      `syy+         oyyo                       \n");
	printf("                     `syyys`       :yyy+                       \n");
	printf("                     oyyyyy.     -oyyyy+                       \n");
	printf("                    -ssssss:    :ssssss/```                    \n");
	printf("                    ossssss+ `.:sssssss+/////-`                \n");
	printf("                   :sss/ssss:/+ssssssss+////////:.             \n");
	printf("                  .ssss`osss/+ssso-osss.`.-://////:`        `` \n");
	printf("                  osss-.osssossso. osss`    `.://///-    -+os+`\n");
	printf("                 /sss/./osssssso` .ssso`   -++-`://///--/sso.  \n");
	printf("                `sss+-//+ssssso.  -sss/   .osso` .///ossss/`   \n");
	printf("               `+sss:///+sssss.   /sss-  -+ssss.  -+osss+.     \n");
	printf("               /sso:-///+ssss:    osso `+ssssss:  .osso/       \n");
	printf("              -ooo. -++++oso-     ooo+`+oso/oso/ -oooo+/       \n");
	printf("              /oo/  .+++++o:     `ooo+/ooo:`oooo:oooo++/.      \n");
	printf("              +/`   `/+++-.      :ooooooo/ `oooooooo+++/`      \n");
	printf("                     .+++/`      /oooooo/   ooooooo++++-       \n");
	printf("                      :+++:     `oooooo:    +ooooo++++:        \n");
	printf("                       .:/`-.   `ooooo/     +ooooo+++/`        \n");
	printf("                           `/+:-`oooo+    `.ooooo++/.          \n");
	printf("                             -+++oooo://+++++ooo+:.            \n");
	printf("                               .:+o++++++//////:`              \n");
	printf("                                  `..--```              \n");
	Sleep(1000);
	mkdir("C:\\Program Files\\MarkWare");
}
int prijava_radnika(KORISNIK *a)
{
	FILE*dat; KORISNIK k;
	if ((dat = fopen("C:\\Program Files\\MarkWare\\korisnici.dat", "rb")))
	{
		while (fread(&k, sizeof(KORISNIK), 1, dat))
		{
			if ((!strcmp(a->k_ime, k.k_ime)) && (!strcmp(a->sifra, k.sifra)))
			{
				fclose(dat);
				strcpy(a->ime, k.ime);
				strcpy(a->prezime, k.prezime);
				return 2;
			}
		}


		printf("\nPogresni podaci");
		Sleep(2000);
		fclose(dat);
	}
	else
		printf("\nGreska pri otvaranju C:/Program Files/MarkWare/korisnici.dat");
	return 0;
}
int prijava_admina(KORISNIK *a)
{
	FILE*dat; KORISNIK k;
	if ((dat = fopen("C:\\Program Files\\MarkWare\\admini.dat", "rb")))
	{
		while (fread(&k, sizeof(KORISNIK), 1, dat))
		{

			if ((!strcmp(a->k_ime, k.k_ime)) && (!strcmp(a->sifra, k.sifra)))
			{
				fclose(dat);
				strcpy(a->ime, k.ime);
				strcpy(a->prezime, k.prezime);
				return 1;
			}
		}

		Sleep(2000);
		fclose(dat);
	}
	else
		printf("\nGreska pri otvaranju C:/Program Files/MarkWare/admini.dat");
	return 0;
}
void brisi_stablo_K(CVOR_K* korijen) {
	if (korijen != 0) {
		brisi_stablo_K(korijen->lijevi);
		brisi_stablo_K(korijen->desni);
		free(korijen);
	}
}void pisi_u_fajl(CVOR* korijen, FILE*dat) {
	if (korijen != 0) {
		pisi_u_fajl(korijen->lijevi, dat);
		if(korijen->art.kol>0)
		fwrite(&korijen->art, sizeof(ARTIKAL), 1, dat);
		pisi_u_fajl(korijen->desni, dat);
	}
}
CVOR_K *formiraj_cvor_korisnika(KORISNIK*kor) {
	CVOR_K *novi = (CVOR_K*)malloc(sizeof(CVOR_K));
	novi->lijevi = novi->desni = 0;
	novi->kor = *kor;
	return novi;
}
CVOR_K *dodaj_cvor_korisnika(CVOR_K*korijen, KORISNIK*kor)
{
	if (korijen == 0)
		return formiraj_cvor_korisnika(kor);
	if (strcmp(korijen->kor.k_ime, kor->k_ime) >= 0)
		korijen->lijevi = dodaj_cvor_korisnika(korijen->lijevi, kor);
	else
		korijen->desni = dodaj_cvor_korisnika(korijen->desni, kor);
	return korijen;
}
CVOR_K* upload_pending(CVOR_K*korijen)
{
	FILE*dat;
	if (!(dat = fopen("C:\\Program Files\\MarkWare\\pending.dat", "rb"))) return 0;
	KORISNIK kor;
	while (fread(&kor, sizeof(korisnik), 1, dat))
	{
		korijen = dodaj_cvor_korisnika(korijen, &kor);
	}
	fclose(dat);
	remove("C:\\Program Files\\MarkWare\\pending.dat");
	return korijen;
}
void statistik_upload()
{
    FILE*log=fopen("C:\\Program Files\\MarkWare\\ulog.dat","rb");
    KORISNIK k;
    char time[24];
    printf("STATISTIKA KORISTENJA SISTEMA\n");
    while(fread(time,24,1,log))
    {
        fread(&k,sizeof(KORISNIK),1,log);

        time[strlen(time)]='\0';
        printf("%s %s %s\n",time,k.prezime,k.ime);
    }
    fclose(log);
}
void pisi_u_fajl_korisnika(CVOR_K* korijen, FILE*dat) {
	if (korijen != 0) {
		pisi_u_fajl_korisnika(korijen->lijevi, dat);
	labela:
		printf("\n1-Sacuvati\n2-Nazad");
		int i;
		scanf("%d", &i);
		if (i == 1)
			fwrite(&korijen->kor, sizeof(korisnik), 1, dat);
		else if (i == 2)
			pisi_u_fajl_korisnika(korijen->desni, dat);
		else
		{
			printf("\nNepostojeca opcija"); system("cls"); goto labela;
		}
	}
}

void administrator()
{
	int i;

	do {
		printf("\n1-Dodavanja naloga \n2-Postavljanje administratora\n3-Pregled upotrebe sistema\n4-Pregled svih izdanih racuna");
		printf("\n5-Brisanje svih izdanih racuna\n6-Nazad");
		scanf("%d", &i);
		if (i == 1)

			{system("cls");registracija();}
		else if (i == 2)
			{system("cls");admin();}
			else if(i==3)
            {system("cls");statistik_upload();}
            else if(i==4)
                system("\"\"C:\\Program Files\\MarkWare\\racun.txt\"\"");
            else if(i==5)
                remove("C:\\Program Files\\MarkWare\\racun.txt");
		else if (i != 6)
			{system("cls");printf("\nNepoznata opcija");}
	} while (i != 6);
}
CVOR *formiraj_cvor(ARTIKAL *art) {
	CVOR *novi = (CVOR*)malloc(sizeof(CVOR));
	novi->lijevi = novi->desni = 0;
	novi->art = *art;
	return novi;
}
void brisi_stablo(CVOR* korijen) {
	if (korijen != 0) {
		brisi_stablo(korijen->lijevi);
		brisi_stablo(korijen->desni);
		free(korijen);
	}
}
CVOR *dodaj_cvor(CVOR *korijen, ARTIKAL *art)
{
	if (korijen == 0)
		return formiraj_cvor(art);
	if (art->sifra <= korijen->art.sifra)
		korijen->lijevi = dodaj_cvor(korijen->lijevi, art);
	else
		korijen->desni = dodaj_cvor(korijen->desni, art);
	return korijen;
}
CVOR* trazi(CVOR* korijen, int sifra) {
	if (korijen == 0) return 0;
	else if (sifra == korijen->art.sifra) return korijen;
	else if (sifra <= korijen->art.sifra)
		return trazi(korijen->lijevi, sifra);
	else
		return trazi(korijen->desni, sifra);
}
static int rb;
void pisi_inorder(CVOR* korijen) {
	if (korijen != 0) {
		pisi_inorder(korijen->lijevi);
		if(korijen->art.kol>0)
		printf("%2d. %05d %-20s %6.2lf %6.2lf %6.2lf\n", rb++,
			korijen->art.sifra, korijen->art.naziv, korijen->art.kol, korijen->art.cijena,
			korijen->art.kol*korijen->art.cijena);
		pisi_inorder(korijen->desni);
	}
}
void download_skladiste(CVOR*korijen)
{
	FILE*dat;
	if (!(dat = fopen("C:\\Program Files\\MarkWare\\tmp.dat", "wb"))) return;
	pisi_u_fajl(korijen, dat);
	fclose(dat);
	remove("C:\\Program Files\\MarkWare\\skladiste.dat");
	rename("C:\\Program Files\\MarkWare\\tmp.dat", "C:\\Program Files\\MarkWare\\skladiste.dat");
}
CVOR* upload_skladiste(CVOR*korijen)
{
	FILE*dat;
	if (!(dat = fopen("C:\\Program Files\\MarkWare\\skladiste.dat", "rb"))) return 0;
	ARTIKAL art;
	while (fread(&art, sizeof(ARTIKAL), 1, dat))
	{
		korijen = dodaj_cvor(korijen, &art);
	}
	fclose(dat);
	return korijen;
}
void pisi(CVOR *korijen) {
	rb = 1;
	if (korijen == 0)
		printf("\nNema artikala\n");
	else
		{
    printf("--- ----- -------------------- ------ ------ ------\n");
	printf("RB. SIFRA NAZIV                KOL.   CIJENA UKUPNO\n");
	printf("--- ----- -------------------- ------ ------ ------\n");
	pisi_inorder(korijen);}
}

CVOR* trazi_najveci(CVOR* korijen)
{
	while (korijen->desni != 0)
		korijen = korijen->desni;
	return korijen;
}
CVOR* brisi_cvor(CVOR *korijen, int sifra) {
	if (korijen == 0) return 0;
	else if(korijen->art.sifra==sifra) return 0;
	else if (sifra < korijen->art.sifra)
		korijen->lijevi = brisi_cvor(korijen->lijevi, sifra);
	else if (sifra > korijen->art.sifra)
		korijen->desni = brisi_cvor(korijen->desni, sifra);
	else if (korijen->lijevi == 0)
	{
		CVOR *p = korijen->desni;
		free(korijen);
		return p;
	}
	else if (korijen->desni == 0)
	{
		CVOR *p = korijen->lijevi;
		free(korijen);
		return p;
	}
	else {
		CVOR *p = trazi_najveci(korijen->lijevi);
		korijen->art = p->art;
		korijen->lijevi = brisi_cvor(korijen->lijevi, korijen->art.sifra);
	}
	return korijen;
}


void download_korpa(CVOR*korijen)
{
	FILE*dat;
	if (!(dat = fopen("C:\\Program Files\\MarkWare\\korpa.dat", "wb"))) return;
	pisi_u_fajl(korijen, dat);
	fclose(dat);
}

int  trazi_po_imenu(CVOR*p,char*naziv)
{
    if(p!=NULL)
    {
        if(!strcmp(p->art.naziv,naziv))
        {
            printf("--- ----- -------------------- ------ ------ ------\n");
	        printf("RB. SIFRA NAZIV                KOL.   CIJENA UKUPNO\n");
	        printf("--- ----- -------------------- ------ ------ ------\n");
	        printf("%2d. %05d %-20s %6.2lf %6.2lf %6.2lf\n", rb++,
		    p->art.sifra, p->art.naziv, p->art.kol, p->art.cijena,
		    p->art.kol*p->art.cijena);
		    return 1;
        }
        trazi_po_imenu(p->lijevi,naziv);
        trazi_po_imenu(p->desni,naziv);
    }
}
int trazi_po_sifri(CVOR*p,int sifra)
{
    if(p!=NULL)
    {
        if(p->art.sifra==sifra)
        {
            printf("--- ----- -------------------- ------ ------ ------\n");
	        printf("RB. SIFRA NAZIV                KOL.   CIJENA UKUPNO\n");
	        printf("--- ----- -------------------- ------ ------ ------\n");
	        printf("%2d. %05d %-20s %6.2lf %6.2lf %6.2lf\n", rb++,
		    p->art.sifra, p->art.naziv, p->art.kol, p->art.cijena,
		    p->art.kol*p->art.cijena);
		    return 1;
        }
        trazi_po_sifri(p->lijevi,sifra);
        trazi_po_sifri(p->desni,sifra);
    }
}

void kupac()
{
	CVOR*korijen1=NULL;
	int izbor;
	korijen1=upload_skladiste(korijen1);
	pisi(korijen1);
	do
    {
       printf("\n1-Pretraga artikla po sifri\n2-Pretraga artikla po imenu\n3-Prikaz svih artikala na stanju\n4-Nazad") ;
       scanf("%d",&izbor);
       if(izbor==1)
        {system("cls");
          int sifra;
          printf("Unesite sifru artikla:");
          scanf("%d",&sifra);
           if(!trazi_po_sifri(korijen1,sifra))printf("Nema artikla");
        }
        else if(izbor==2)
           {system("cls");
           char naziv[20];
          printf("Unesite naziv artikla:");
          scanf("%s",naziv);
           if(!trazi_po_imenu(korijen1,naziv))printf("Nema artikla");
        }
        else if(izbor==3)
        {
            system("cls");
            pisi(korijen1);
        }}while(izbor<4);
}

CVOR* izrada_racuna(CVOR*korijen1,KORISNIK kor)
{if(korijen1==NULL){printf("\n Nema artikala na stanju\n");return 0;}
CVOR*racun=NULL;
int izbor=1;
int kol;
do{
                system("cls");
				pisi(korijen1);
				printf("\nUnesite sifru artikla kojeg dodajete u racun: ");
				int sifra;
				scanf("%d", &sifra);
				CVOR*p = trazi(korijen1, sifra);
                    ARTIKAL pom;
				if (p == 0) printf("\nNema artikla na stanju");
				else
				{printf("\nUnesite kolicinu koju potrazujete: ");

				scanf("%d", &kol);
				if (kol>p->art.kol)printf("\nNema te kolicne na stanju");
				else
				{p->art.kol -= kol;
				 pom.cijena=p->art.cijena;
				 pom.kol=kol;
				 strcpy(pom.naziv,p->art.naziv);
				 pom.sifra=sifra;
				 racun=dodaj_cvor(racun,&pom);
				}

				if (p->art.kol == 0){
					korijen1 = brisi_cvor(korijen1, p->art.sifra);}}
					labela:
					printf("Da li zelite da dodate jos artikala:\n1-Da\n2-Ne");
					scanf("%d",&izbor);
					//printf("%d",izbor);
					if(izbor>2) {printf("Nepostojeca opcija\n");goto labela;}
                }while(izbor==1);


download_skladiste(korijen1);
return racun;
}

void inorder(CVOR*p)
{
    if(p!=NULL)
    {
        inorder(p->lijevi);
        printf("%2d. %05d %-20s %6.2lf %6.2lf %6.2lf\n", rb++,p->art.sifra, p->art.naziv,(double)p->art.kol, p->art.cijena,p->art.kol*p->art.cijena);
        suma+=p->art.kol*p->art.cijena;
        inorder(p->desni);
    }
}
void izmjena(CVOR*korijen)
{  rb=1;
    if(korijen==NULL){printf("\n Nema artikala na stanju\n");return;}
	printf("\nUnesite sifru artikla kojeg zelite da promjenite");
	int kod;
	scanf("%d", &kod);
	CVOR*p = trazi(korijen, kod);
	if(p==0){printf("\n Nema artikla kojeg ste trazili");Sleep(100);return;}
	printf("--- ----- -------------------- ------ ------ ------\n");
	printf("RB. SIFRA NAZIV                KOL.   CIJENA UKUPNO\n");
	printf("--- ----- -------------------- ------ ------ ------\n");
	printf("%2d. %05d %-20s %6.2lf %6.2lf %6.2lf\n", rb++,
		p->art.sifra, p->art.naziv, p->art.kol, p->art.cijena,
		p->art.kol*p->art.cijena);
	printf("Da li zelite izvrsiti promjenu: \n");
	printf("\t1-naziva\n");
	printf("\t2-kolicine\n");
	printf("\t3-cijene\n");
	int a;
	scanf("%d", &a);
	if (a == 1)
	{
		printf("\nUnesite novi naziv: ");
		char novi[21];
		scanf("%s", novi);
		strcpy(p->art.naziv, novi);
	}
	else if (a == 2)
	{
		printf("\nUnesite novu kolicinu: ");
		double nova;
		scanf("%lf", &nova);
		p->art.kol = nova;
	}
	else if (a == 3)
	{
		printf("\nUnesite novu cijenu: ");
		double nova;
		scanf("%lf", &nova);
		p->art.cijena = nova;
	}
}
void izmjena_racuna(CVOR*racun,CVOR*korijen)
{ rb=1;
     if(racun==NULL){printf("\n Nema artikala na racunu\n");return;}
	printf("\nUnesite sifru artikla kojeg zelite da promjenite");
	int kod;
	scanf("%d", &kod);
	CVOR*p = trazi(racun, kod);
	if(p==0){printf("\n Nema artikla kojeg ste trazili");Sleep(100);return;}
	printf("--- ----- -------------------- ------ ------ ------\n");
	printf("RB. SIFRA NAZIV                KOL.   CIJENA UKUPNO\n");
	printf("--- ----- -------------------- ------ ------ ------\n");
	printf("%2d. %05d %-20s %6.2lf %6.2lf %6.2lf\n", rb++,
		p->art.sifra, p->art.naziv, p->art.kol, p->art.cijena,
		p->art.kol*p->art.cijena);
    printf("Da li zelite izvrsiti : \n");
	printf("\t1-promjenu kolicine \n");
	printf("\t2-brisanje artikla sa racuna\n");
	int a;
	scanf("%d", &a);
	if(a==1)
    {
        printf("\nUnesite novu kolicinu: ");
		double nova;
		scanf("%lf", &nova);
		CVOR*pom=trazi(korijen,kod);
		pom->art.kol+=p->art.kol-nova;
		if (pom->art.kol == 0)
        korijen = brisi_cvor(korijen, pom->art.sifra);
		p->art.kol = nova;
    }
    else if(a==2)
        racun=brisi_cvor(racun,kod);

}

void upis_racuna(CVOR*p,FILE*dat)
{
    if(p!=NULL)
    {
        upis_racuna(p->lijevi,dat);
        fprintf(dat,"%2d. %05d %-20s %6.2lf %6.2lf %6.2lf\n", rb++,
		p->art.sifra, p->art.naziv,(double)p->art.kol,(double) p->art.cijena,
		(double)p->art.kol*p->art.cijena);
		suma+=p->art.kol*p->art.cijena;
		upis_racuna(p->desni,dat);
    }
}
void download_racun(CVOR*racun,KORISNIK kor,FILE*fp)
{rb=1;

    suma=0;
    fprintf(fp,"%s",sat());
    fprintf(fp,"\nProdavac: %s %s\n",kor.prezime,kor.ime);
	fprintf(fp,"--- ----- -------------------- ------ ------ ------\n");
	fprintf(fp,"RB. SIFRA NAZIV                KOL.   CIJENA UKUPNO\n");
	fprintf(fp,"--- ----- -------------------- ------ ------ ------\n");
    upis_racuna(racun,fp);
    fprintf(fp,"---------------------------------------------------\n");
    fprintf(fp,"                                IZNOS RACUNA:%6.2lf\n",suma);
    fprintf(fp,"===================================================\n");

    rb=1;
    suma=0;

}

void racun(CVOR*korijen,KORISNIK kor)
{
CVOR*racun=NULL;
do{
	printf("\n1-Kreiranje racuna\n2-Izmjena racuna\n3-Pregled racuna\n4-Nazad");
	int i;
	scanf("%d", &i);
	if(i==1)
    {
    racun=izrada_racuna(korijen,kor);
    }
    else if(i==2)
    {
    izmjena_racuna(racun,korijen);
    }
	else if (i == 3)
	{system("cls");
    printf("--- ----- -------------------- ------ ------ ------\n");
	printf("RB. SIFRA NAZIV                KOL.   CIJENA UKUPNO\n");
	printf("--- ----- -------------------- ------ ------ ------\n");
		if(racun)
		{suma=0;inorder(racun);
    printf("---------------------------------------------------\n");
    printf("                                IZNOS RACUNA:%6.2lf\n",suma);
    printf("===================================================\n");
		suma=0;}
		else
            printf("\nRacun je prazan");
	}
	else if (i == 4)
        {
    FILE*svi_rac=fopen("C:\\Program Files\\MarkWare\\racun.txt","a");
	char racunstr[80],pom1[80],pom2[80];
    int i;
    strcpy(pom1,"C:\\Program Files\\MarkWare\\");
    strcpy(pom2,sat());

    for(i=0;pom2[i]!='\n';i++)
        {if(pom2[i]==' '||pom2[i]==':')
        racunstr[i]='-';
         else
            racunstr[i]=pom2[i];
        }
    racunstr[i]='\0';
	strcat(racunstr,".txt");
	strcat(pom1,racunstr);
	FILE*racun_pojed=fopen(pom1,"w");
	//if(racun_pojed==NULL)printf("jaoooo");
	download_racun(racun,kor,racun_pojed);
	download_racun(racun,kor,svi_rac);
	fclose(racun_pojed);
	fclose(svi_rac);
	//printf("%s",racunstr);
	//system("pause");
	brisi_stablo(racun);
	return;}
	else
	{
		printf("\nNepoznata opcija");
	}
	}while(1);


	}

void citaj(ARTIKAL *art) {
	printf("  \nSifra: ");
	scanf("%d", &art->sifra);
	printf("  \nNaziv: ");
	scanf("%s", art->naziv);
	printf("  \nKolicina: ");
	scanf("%lf", &art->kol);
	printf("  \nCijena: ");
	scanf("%lf", &art->cijena);
}

void statistik_download(KORISNIK k)
{
    FILE*log=fopen("C:\\Program Files\\MarkWare\\ulog.dat","ab");
    fwrite(sat(),24,1,log);
    fwrite(&k,sizeof(KORISNIK),1,log);
    fclose(log);
}
void radnik(KORISNIK radnik) {
	CVOR *korijen = 0; char c; int sifra; ARTIKAL art;
	korijen = upload_skladiste(korijen);
	statistik_download(radnik);
	do {
     printf("======================================================================\n");
     printf( "%s %s                                  %s",radnik.prezime,radnik.ime,sat());
     printf("======================================================================\n");
     printf("Dodavanje/azur. [D], brisanje [B], prikaz [P], pretr. [T], kraj [0]\nizmjena [I],izdavanje racuna[R],sacuvati [S]? ");
		scanf("\n%c", &c);
		if (c == 'D') {
			system("cls");
			printf("  Unesite podatke:\n"); citaj(&art);
			CVOR *p = trazi(korijen, art.sifra);
			if (p) p->art = art; else korijen = dodaj_cvor(korijen, &art);
		}
		else if (c == 'B') {
			system("cls");
			printf("  \nUnesite sifru artikla kojeg zelite da obrisete: "); scanf("%d", &sifra);
			korijen = brisi_cvor(korijen, sifra);
		}
		else if (c == 'I') { system("cls"); izmjena(korijen); }
		else if (c == 'R') racun(korijen,radnik);
		else if (c == 'P') pisi(korijen);
		else if (c == 'S')download_skladiste(korijen);
		else if (c == 'T') {
			printf("  \nSifra: "); scanf("%d", &sifra);
			CVOR *p = trazi(korijen, sifra);
			if (p) printf(" \nArtikal %s ima cijenu %.2lf\n", p->art.naziv, p->art.cijena);
			else printf("  \nNema podataka o artiklu sa sifrom %d.\n", sifra);
		}
		else if (c != '0') printf("  \nNepoznata opcija - '%c'.\n", c);
	} while (c != '0');

	download_skladiste(korijen);
	brisi_stablo(korijen); printf("\nKRAJ!\n");

}

void window(int a,int b,int c,int d)
{
 int i;
 system("cls");
 gotoxy(30,10);

printf("****NAZIV TRGOVINE****");
 printf("\n\n");
 gotoxy(30,11);
 printf("   VLASNIK TRGOVINE");

 for (i=a;i<=b;i++){
        gotoxy(i,17);printf("\xcd");
        gotoxy(i,19);printf("\xcd");
        gotoxy(i,c);printf("\xcd");
        gotoxy(i,d);printf("\xcd");
        }
 gotoxy(a,17);printf("\xc9");
 gotoxy(a,18);printf("\xba");
 gotoxy(a,19);printf("\xc8");
 gotoxy(b,17);printf("\xbb");
 gotoxy(b,18);printf("\xba");
 gotoxy(b,19);printf("\xbc");

 for(i=c;i<=d;i++){
  gotoxy(a,i);printf("\xba");
  gotoxy(b,i);printf("\xba");
 }
 gotoxy(a,c);printf("\xc9");
 gotoxy(a,d);printf("\xc8");
 gotoxy(b,c);printf("\xbb");
 gotoxy(b,d);printf("\xbc");

}
KORISNIK novi_login()
{
    KORISNIK k;int j;

     system("cls") ;
    login(&k);
      j = prijava_admina(&k);
			if (j == 1)
            {
                k.uloga=1;
                return k;
            }

      j = prijava_radnika(&k);
			if (j == 2)
            {
                k.uloga=2;
                return k;
            }
k.uloga=0;
return k;

}
void main_meni()
{
	int i,j,iz=1; KORISNIK k;
	FILE*dat = fopen("C:\\Program Files\\MarkWare\\admini.dat", "rb");
	      fseek(dat,0,SEEK_END);
			if (!(dat)||(ftell(dat)==0))
				admin();
			fclose(dat);

	do
	{
		system("cls");
const char *menu[]={"1-LOGIN","2-GUEST","3-IZLAZ"};
 window(25,50,20,32);
 gotoxy(33,18);printf("PRIJAVA ");
 for (j=0;j<=2;j++){
  gotoxy(30,22+j+1);printf("%s\n\n\n",menu[j]);}
  gotoxy(30,22+j+1);
		scanf("%d", &i);
		system("cls");
		if(i==1)
		{
         if(iz==1)
		 k=novi_login();
		if (k.uloga == 1)
		{
				administrator();
		}
		else if (k.uloga == 2)
				radnik(k);
		}
        else if (i == 2)
            kupac();
		else if (i>3)
		{
			printf("\nNepostojeca opcija\n"); Sleep(1500);
		}
		if(i==3)
            iz=0;
	} while (i != 3);

}
void uvod()
{
	system("color 9a");
	int i = 0, j = 0; char razmak[100], razmak1[100], razmak2[100];
	strcpy(razmak, " ");
	strcpy(razmak1, " ");
	strcpy(razmak2, "~");
	for (i = 0; i<61; i++)
	{
		int k;

		printf("\t,_______________________________________________________,\n");
		printf("\t|                                                       |\n");
		printf("\t|***************|DOBRO DOSLI U TRGOVINU|****************|\n");
		printf("\t|                                                       |\n");
		printf("\t|_______________________________________________________|\n");
		printf("\t|                  |\\  /| \\  /\\  /                      |\n");
		printf("\t|__________________|_\\/_|__\\/__\\/_______________________|\n");
		printf("\t|    ***********************************************    |\n");
		printf("\t|    ***********************************************    |\n");
		printf("\t|_______________________________________________________|\n");
		printf("\n\tLoading,Please wait\n");
		printf("\t\n");

		printf("%s_             \n", razmak);
		printf("%s \\____________  \n", razmak);
		printf("%s  \\##########/  \n", razmak);
		printf("%s~  \\########/  \n", razmak1);
		printf("%s ~  |#*MW*#/   \n", razmak2);
		printf("%s~   |_____.    \n", razmak1);
		printf("%s    o     o\n", razmak);
		for (k = 0; k<79; k++)
			printf("\xdb");
		j++;
		if (j % 2)
		{
			strcat(razmak1, "~"); strcat(razmak2, " ");
		}
		else
		{
			strcat(razmak1, " "); strcat(razmak2, "~");
		}
		Sleep(30);
		system("cls");
		strcat(razmak, " ");
	}


}

int main()
{
    system("TITLE trgovina");
   logo();
   uvod();
	main_meni();
	logo();
   return 0;
}


