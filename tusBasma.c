#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int tusSayisiniBul(char k){
   k=toupper(k);
// Boşluk karakteri
    if (k == ' ') return 1;

    // Harf Grupları
    // 1 basış gerektirenler (A, D, G, J, M, P, T, W)
    if (k == 'A' || k == 'D' || k == 'G' || k == 'J' || k == 'M' || k == 'P' || k == 'T' || k == 'W')
        return 1;
    
    // 2 basış gerektirenler (B, E, H, K, N, Q, U, X)
    if (k == 'B' || k == 'E' || k == 'H' || k == 'K' || k == 'N' || k == 'Q' || k == 'U' || k == 'X')
        return 2;

    // 3 basış gerektirenler (C, F, I, L, O, R, V, Y)
    if (k == 'C' || k == 'F' || k == 'I' || k == 'L' || k == 'O' || k == 'R' || k == 'V' || k == 'Y')
        return 3;
    
    // 4 basış gerektirenler (S, Z)
    if (k == 'S' || k == 'Z')
        return 4;

    // Eğer dosya içinde enter varsa onu yok saymak için 0 döndür
    return 0;

}

int main(){
    char dosyaAdi[100];
    char karakter;
    int tuş_basma=0;

//Dosya adını alıyoruz.
printf("Dosya adi giriniz : ");
   scanf("%s",dosyaAdi);

//Dosyaları açıyoruz
FILE * mektup = fopen(dosyaAdi,"r");
FILE * frekans = fopen("frekans.txt" ,"w");

//Dosya var mı yok mu kontrolu
if(mektup==NULL){
   printf("Okunacak dosya bulunamadi!!");
   return 1;
}
//Dosyayı karakter karakter oku
    while((karakter=fgetc(mektup))!=EOF){
        tuş_basma += tusSayisiniBul(karakter);
    }
    printf("Bu mektup için kaç tuşa basildiğini gösteren frekans.txt başarili bir şekilde oluşturuldu.");
    fprintf(frekans , "Toplam %d kadar tuşa basilmiştir.",tuş_basma);

//Dosyaları kapama
fclose(mektup);
fclose(frekans);

return 0 ;
}