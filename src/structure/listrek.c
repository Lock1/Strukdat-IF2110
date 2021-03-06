/* File: listrek.c */
/* ADT list linier dengan representasi pointer */
/* Implementasi list linier secara rekursif */

#include "listrek.h"
#include <stdlib.h>
#include <stdio.h>

/* *** Manajemen Memori *** */
listRekAddress Alokasi (listrekInfotype X)
/* Mengirimkan listRekAddress hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka listRekAddress tidak ListNil, dan misalnya menghasilkan P,
  maka Info(P) = X, Next(P) = ListNil */
/* Jika alokasi gagal, mengirimkan ListNil */
{
    listRekAddress P = (listRekAddress) malloc(sizeof(ElmtList));

    if(P!=ListNil){
        Info(P) = X;
        Next(P) = ListNil;
    }
    return P;
}
void Dealokasi (listRekAddress P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian listRekAddress P */
{
    free(P);
}
/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int RekIsEmpty(List L)
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
{
    if(L==ListNil){
        return 1;
    }
    else{
        return 0;
    }
}
int IsOneElmt(List L)
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
{
    if(!RekIsEmpty(L)){
        return RekIsEmpty(Next(L));
    }
    else{
        return 0;
    }
}
/* *** Selektor *** */
listrekInfotype FirstElmt (List L)
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
{
    return Info(L);
}
List Tail(List L)
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
{
    return Next(L);
}
/* *** Konstruktor *** */
List Konso(listrekInfotype e, List L)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya.
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
{
    listRekAddress P = Alokasi(e);
    if(P==ListNil){
        return L;
    }
    else{
        Next(P) = L;
        return P;
    }
}
List KonsB(List L, listrekInfotype e)
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */
{
    if(RekIsEmpty(L)){
        return Alokasi(e);
    }
    else{
        Next(L) = KonsB(Tail(L), e);
        return L;
    }
}

/* *** Operasi Lain *** */
List Copy (List L)
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */ {
    if(RekIsEmpty(L)){
        return ListNil;
    }
    else{
        return Konso(FirstElmt(L), Copy(Tail(L)));
    }
}
void MCopy (List Lin, List *Lout)
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
{
    List LTemp;
    if(RekIsEmpty(Lin)){
        *Lout =  ListNil;
    }
    else{
        MCopy(Tail(Lin), &LTemp);
        *Lout = Konso(FirstElmt(Lin), LTemp);
    }
}
List Concat (List L1, List L2)
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan ListNil */
{
    if(RekIsEmpty(L1)){
        return Copy(L2);
    }
    else{
        return Konso(FirstElmt(L1), Concat(Tail(L1), L2));
    }
}
void MConcat (List L1, List L2, List *LHsl)
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
{
    List LTemp;
    if(RekIsEmpty(L1)){
        *LHsl = Copy(L2);
    }
    else{
        MConcat(Tail(L1), L2, &LTemp);
        *LHsl = Konso(FirstElmt(L1), LTemp);
    }
}
void PrintList (List L)
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */{
    if(RekIsEmpty(L)){
    }
    else{
        printf("%d\n", FirstElmt(L));
        PrintList(Tail(L));
    }
}
int NbElmtList (List L)
{
    if(RekIsEmpty(L)){
        return 0;
    }
    else{
        return 1 + NbElmtList(Tail(L));
    }
}
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
boolean Search (List L, listrekInfotype X)
/* Mengirim true jika X adalah anggota list, false jika tidak */
{
    if(RekIsEmpty(L)){
        return false;
    }
    else{
        if(FirstElmt(L)==X){
            return true;
        }
        else{
            return Search(Tail(L), X);
        }
    }
}
