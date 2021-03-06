//13519146 - Fadel Ananda Dotty
//13519110 - M. Akromi Afif
//13519046 - Dwianditya Hanif Raharjanto
#include "../config.h"
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "wahana.h"

// Wahana MakeWahana(int id, int harga, int WahanaDurasi, int kapasitas, char nama[999], char deskripsi, char gambar) {
//   Wahana W;
//   ID(W) = id;
//   WahanaDurasi(W) = WahanaDurasi;
//   Kapasitas(W) = kapasitas;
//   Nama(W) = nama;
//   Deskripsi(W) = deskripsi;
//   Gambar(W) = gambar;
//
//   return W;
// }

// int getIDWahana(Wahana W) {
//   return ID(W);
// }
//
// int getHargaWahana(Wahana W) {
//   return Harga(W);
// }
//
// int getWahanaDurasiWahana(Wahana W) {
//   return WahanaDurasi(W);
// }
//
// int getKapasitasWahana(Wahana W) {
//   return Kapasitas(W);
// }
//
// int getFrekuensiWahana(Wahana W) {
//   return Frekuensi(W);
// }
//
// int getPenghasilanWahana(Wahana W) {
//   return Penghasilan(W);
// }
//
// int getPenghasilanHariWahana(Wahana W) {
//   return PenghasilanHari(W);
// }
//
// int getFrekuensiHariWahana(Wahana W) {
//   return FrekuensiHari(W);
// }
//
// int getStatusWahana(Wahana W) {
//   return StatusWahana(W);
// }
//
// char* getNamaWahana(Wahana W) {
//   return Nama(W);
// }
//
// char* getDeskripsi(Wahana W) {
//   return Deskripsi(W);
// }
//
// char getGambar(Wahana W) {
//   return Gambar(W);
// }

void setStatusWahana(Wahana* W, int newStatus) {
  StatusWahana(*W) = newStatus;
}

Wahana* createWahanaByID(Wahana* w, int ID){
  Wahana* hasil=(Wahana*)malloc(sizeof(Wahana));
  for (int i=0; i<20; i++){
    if (w[i].ID==ID){
      ID(*hasil)=ID(w[i]);
      Harga(*hasil)=Harga(w[i]);
      // WahanaDurasi(*hasil)=0;
      WahanaDurasi(*hasil)=WahanaDurasi(w[i]);
      Kapasitas(*hasil)=Kapasitas(w[i]);
      Frekuensi(*hasil)=0;
      Penghasilan(*hasil)=0;
      FrekuensiHari(*hasil)=0;
      PenghasilanHari(*hasil)=0;
      StatusWahana(*hasil)= 1;
      for (int j = 0 ; j < 999 ; j++) {
          Nama(*hasil)[j] = Nama(w[i])[j];
          Deskripsi(*hasil)[j] = Deskripsi(w[i])[j];
      }
      Gambar(*hasil)=Gambar(w[i]);
      LinCreateEmpty(&Upgrade(*hasil));
    }
  }
  return hasil;
}
void destroyWahana(Wahana* w) {
    free(w->materialArray);
    free(w);
}

boolean searchWahanaByID(Wahana* w, int ID){
  for (int i=0; i<WAHANA_MAX; i++){
    if (w[i].ID==ID){
      return true;
    }
  }
  return false;
}

int getHargaWahanaByID(Wahana* w, int ID){
  for (int i=0; i<WAHANA_MAX; i++){
        if (w[i].ID==ID){
            return w[i].harga;
        }
    }
    return 0;
}

// // menghitung jumlah wahana level 1
// int CountWahana(){
//   FILE* file=fopen("data/wahana.txt", "r");
// 	if (!file)
// 		return 0;
//   int i=0;
// 	do{
//     Wahana w;
//     if(w.ID<100)
// 		  i++;
// 	}while(!feof(file));
//   return i;
// }
//
// // menghitung seluruh wahana
// int CountAllWahana(){
//   FILE* file=fopen("data/wahana.txt", "r");
// 	if (!file)
// 		return 0;
//   int i=0;
// 	do{
// 		i++;
// 	}while(!feof(file));
//   return i;
// }
int getWahanaDurasiByID(Wahana* w, int ID){
   for (int i=0; i<WAHANA_MAX; i++){
     if (w[i].ID==ID){
       return w[i].durasi;
     }
   }
    return 0;
}

int getKapasitasByID(Wahana* w, int ID){
  for (int i=0; i<WAHANA_MAX; i++){
    if (w[i].ID==ID){
      return w[i].kapasitas;
    }
  }
return 0;
}

int getFrekuensiByID(Wahana* w, int ID){
  for (int i=0; i<WAHANA_MAX; i++){
    if (w[i].ID==ID){
      return w[i].frekuensiHari;
    }
  }
   return 0;
}

int getStatusWahanaByID(Wahana* w, int ID){
  for (int i=0; i<WAHANA_MAX; i++){
    if (w[i].ID==ID){
      return w[i].statusWahana;
    }
  }
   return 0;
}

int getIndexByID(Wahana* w, int ID){
  for (int i=0; i<WAHANA_MAX; i++){
    if (w[i].ID==ID){
      return i;
    }
  }
return -1;
}

char getCharByID(Wahana* w, int ID){
  for (int i=0; i<WAHANA_MAX; i++){
    if (w[i].ID==ID){
      return w[i].gambar;
    }
  }
return -1;
}
