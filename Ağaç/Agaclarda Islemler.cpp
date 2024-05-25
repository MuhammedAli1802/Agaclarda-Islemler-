

#include <stdio.h>
#include <stdlib.h>

typedef struct Agac{
	int eleman;
	struct Agac *sag,*sol;
}Agaclar;

Agaclar *kok = NULL;
Agaclar *yeni = NULL;
Agaclar *gecici = NULL;
Agaclar *bironceki = NULL;
int aranan,seviyeal;

Agaclar *Degeral();
void ekle(Agaclar *yeni);
void ekle_rec(); // recursive ile ekleme 
void listele_in(Agaclar *kok);
void listele_pre(Agaclar *kok);
void listele_post(Agaclar*kok);
void Listelememenu();
Agaclar *arama(int aranan);
Agaclar *arama_rec(Agaclar *kok,int aranan); // recursive ile arama
Agaclar *enkucuk(Agaclar *kok);
Agaclar *enbuyuk(Agaclar *kok);

Agaclar *Degeral(){
	yeni=(Agaclar *)malloc(sizeof(Agaclar));

	printf("Eklenecek Sayi: "); scanf("%d",&yeni->eleman);
	yeni->sag = NULL;
	yeni->sol = NULL;
	return yeni;
}

void ekle(Agaclar *yeni){
	if(kok == NULL){
		kok = yeni;
	}
	else {
		gecici = kok;
		while (gecici != NULL){ // gecici ile agacýn en altýna iniyoruz 
			bironceki = gecici; // her adýmda bir oncekini tutmuþ oluyoruz
			if(yeni->eleman < bironceki->eleman){
				gecici = gecici->sol;
			}
			else gecici = gecici->sag;
		}
		if(yeni->eleman < bironceki->eleman ){ // elemaný ekleyeceðimiz yerdeki baðlarý kuruyoruz
			bironceki->sol = yeni;
		}
		else bironceki->sag = yeni;
	}
}

void ekle_rec(Agaclar *agackok,Agaclar *yeni){
	if(kok = NULL ){
		kok = yeni;
	}
	else {
		if(yeni->eleman < agackok->eleman ){
			if(agackok->sol == NULL){
				agackok->sol = yeni;
			}
			else ekle_rec(agackok->sol,yeni);
		}
		else {
			if(agackok->sag == NULL){
				agackok->sag = yeni;
			}
			else ekle_rec(agackok->sag,yeni);
		}
	}
}
//int deger = 0;
void listele_in(Agaclar *kok){
	if(kok != NULL){
		listele_in(kok->sol);
		printf("%d ",kok->eleman);
		/*if(kok->eleman > deger){
			deger = kok->eleman;
		}*/ //Aðaç sýralý olmadýðýnda en büyük sayýyý öðrenmek için 
		/*if(kok->eleman < deger){
			deger = kok->eleman;
		}*/ //Aðaç sýralý olmadýðýnda en küçük sayýyý öðrenmek için 
		listele_in(kok->sag);
	}
}

void listele_pre(Agaclar *kok){
	if(kok != NULL){
		printf("%d ",kok->eleman);
		/*if(kok->eleman > deger){
			deger = kok->eleman;
		}*/ //Aðaç sýralý olmadýðýnda en büyük sayýyý öðrenmek için 
		/*if(kok->eleman < deger){
			deger = kok->eleman;
		}*/ //Aðaç sýralý olmadýðýnda en küçük sayýyý öðrenmek için 
		listele_pre(kok->sol);
		listele_pre(kok->sag);
	}
}

void listele_post(Agaclar*kok){
	if(kok != NULL){
		listele_post(kok->sol);
		listele_post(kok->sag);
		printf("%d ",kok->eleman);
		/*if(kok->eleman > deger){
			deger = kok->eleman;
		}*/ //Aðaç sýralý olmadýðýnda en büyük sayýyý öðrenmek için 
		/*if(kok->eleman < deger){
			deger = kok->eleman;
		}*/ //Aðaç sýralý olmadýðýnda en küçük sayýyý öðrenmek için 
	}
}

int seviye = 1;
int tmp = 1;
int seviye_Bul(Agaclar*kok){
	if(kok != NULL){
		tmp++; seviye_Bul(kok->sol); tmp--;
		tmp++; seviye_Bul(kok->sag); tmp--;
		if(tmp > seviye) seviye=tmp;
	}
	return seviye;
}

void seviyedekiyapraklar(Agaclar *kok,int istenilenseviye){
	if(kok != NULL){
		tmp++; seviyedekiyapraklar(kok->sol,istenilenseviye); tmp--;
		if(tmp == istenilenseviye) printf("%d ",kok->eleman);
		tmp++; seviyedekiyapraklar(kok->sag,istenilenseviye); tmp--;
	}
}

void Listelememenu(){
	int listesecim;
	printf("Hangi yontem ile listelemek istersiniz\n1- InOrder\n2- PreOrder\n3- PostOrder \n"); scanf("%d",&listesecim); printf("\n");
	switch(listesecim){
		case 1: listele_in(kok); break;
		case 2: listele_pre(kok); break;
		case 3: listele_post(kok); break;
	}
}

Agaclar *arama(int a){
	gecici = kok;
	while(gecici != NULL){
		if(gecici->eleman == a){
			return gecici;
		}
		else if(aranan < gecici->eleman ){
			gecici = gecici->sol;
		}
		else gecici = gecici->sag;
	}
	return NULL;
}

Agaclar *arama_rec(Agaclar *kok,int aranan){
	if(kok == NULL){
		return NULL;
	}
	if(aranan < kok->eleman){
		return arama_rec(kok->sol,aranan);
	}
	else if(aranan > kok->eleman){
		return arama_rec(kok->sag,aranan);
	}
	else return kok;
}

Agaclar *enkucuk(Agaclar *kok){
	gecici = kok;
	while(gecici->sol != NULL){
		gecici = gecici->sol;
	}
	return gecici;
}

Agaclar *enbuyuk(Agaclar *kok){
	gecici = kok;
	while(gecici->sag != NULL){
		gecici = gecici->sag;
	}
	return gecici;
}

int elemanToplami(Agaclar *kok) {
    if (kok == NULL) {
        return 0;
    } else {
        return kok->eleman + elemanToplami(kok->sol) + elemanToplami(kok->sag);
    }
}

int dugumsayisi(Agaclar *kok){
	if(kok == NULL){
		return 0;
	}
	else return 1 + dugumsayisi(kok->sol) + dugumsayisi(kok->sag);
}

int koktenBuyukEnKucuk(Agaclar *kok) {
	if(kok->sol == NULL){
		return kok->eleman;
	}

    if (kok->sol != NULL) {
        return koktenBuyukEnKucuk(kok->sol);
    }
}

int koktenKucukEnBuyuk(Agaclar *kok) {
	if(kok->sag == NULL){
		return kok->eleman;
	}
	
    if (kok->sag != NULL) {
       return koktenKucukEnBuyuk(kok->sag);
    }
}  

int yaprakOlmayanKoklerToplami(Agaclar *kok) {
    if (kok == NULL)
        return 0;

    if (kok->sol != NULL || kok->sag != NULL) {
        return kok->eleman + yaprakOlmayanKoklerToplami(kok->sol) + yaprakOlmayanKoklerToplami(kok->sag);
    } else {
        return 0;
    }
}

int yaprak(Agaclar *kok) {
    if (kok == NULL)
        return 0;

    if (kok->sol == NULL && kok->sag == NULL) {
    	printf("%d ",kok->eleman);
    }
    return yaprak(kok->sol) + yaprak(kok->sag);
}

int main(){
	
	int secim;
	
	while(1){
		printf("1- Ekleme\n2- Listeleme\n3- Arama\n4- En Kucuk Eleman\n5- En Buyuk Eleman\n6- Elemanlar Toplami\n7- Dugum Sayisi\n8- Elemanlarin Ortalamsi\n9- Kokten Buyuk En kucuk ve Kokten Kucuk En Buyuk Sayi\n10- Yaprak Olmayan Kokler Toplami\n11- Yapraklari Yazdir\n12- Agacin Seviyesi\n13- Secilen Seviyedeki Elemanlari Yazdirma\n14- Cikis\n");
		scanf("%d",&secim);
		system("cls");
		switch(secim){
			case 1: yeni = Degeral(); ekle(yeni); printf("\n"); /*ekle_rec(kok,yeni);*/ break;
			case 2: Listelememenu(); printf("\n\n"); break;
			case 3: printf("Aranan Numara: "); scanf("%d",&aranan); 
					if(arama(aranan) == NULL){
						printf("Aranan Sayi Bulunamadi !\n\n");
					}
					else {
						printf("%d\n\n",arama(aranan)->eleman);
					}
					break;
					/* RECURSÝVE ÝLE ARAMA
					if(arama_rec(kok,aranan) == NULL){
						printf("Aranan Sayi Bulunamadi !\n\n");
					}
					else {
						printf("%d\n\n",arama_rec(kok,aranan)->eleman);
					}
					break;*/
			case 4: printf("Agacin En Kucuk Elemani: %d\n\n",enkucuk(kok)->eleman); break;
			case 5: printf("Agacin En Buyuk Elemani: %d\n\n",enbuyuk(kok)->eleman); break;
			case 6: printf("Agac Elemanlarinin Toplami: %d\n\n",elemanToplami(kok)); break;
			case 7: printf("Agactaki Dugum Sayisi: %d\n\n",dugumsayisi(kok)); break;
			case 8: printf("Agactaki Elemanlarin Ortalamasi: %.2f\n\n", (float) elemanToplami(kok) / dugumsayisi(kok) ); break;
			case 9: printf("Kokten Buyuk En Kucuk Sayi: %d\n\n", koktenBuyukEnKucuk(kok->sag));
    				printf("Kokten Kucuk En Buyuk Sayi: %d\n\n", koktenKucukEnBuyuk(kok->sol)); break;
    		case 10: printf("Yaprak Olmayan Koklerin Toplami: %d\n\n", yaprakOlmayanKoklerToplami(kok) ); break;
    		case 11: yaprak(kok); printf("\n\n"); break;
    		case 12: printf("Agacin Seviyesi: %d\n\n",seviye_Bul(kok)); break;
    		case 13: printf("Seviyeyi Giriniz: "); scanf("%d",&seviyeal); printf("\nIstenilen Seviyedeki Elemanlar: "); seviyedekiyapraklar(kok,seviyeal); printf("\n\n");  break;
			case 14: printf("\nProgram Sonlandiriliyor..."); exit(0);
		}
	}
}
