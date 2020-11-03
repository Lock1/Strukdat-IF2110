/*Body ADT Jam */
#include "jam.h"
#include <stdio.h>
#include "boolean.h"
/*------Konstruktor Jam------*/
JAM MakeJAM(int H, int M)
/*Membentuk Jam dari H, M, S yang valid*/
{   /*Kamus lokal */
    JAM J1;
    /*Algoritma*/
    Hour(J1)=H;
    Minute(J1)=M;
    return J1;
}
/* Validator Jam */
boolean IsJAMValid(int H, int M)
/* True jika H,M,S membentuk jam yang valid*/
{   /*Kamus Lokal*/
    /*Algoritma*/
    return ((H>=0 && H<=23) && (M>=0 && M<=59));
}
/* Baca & Tulis Jam */
void BacaJAM (JAM *J)
// I.S : J tak terdefinisi
// F.S : J terdefinisi
// Proses : mengulang baca komponen H,M,S sehingga membentuk J yang valid
{   /*Kamus lokal*/
    int H,M;
    /*Algoritma*/
    scanf("%d %d", &H, &M);
    while (!IsJAMValid(H, M))
    {
        printf("Jam tidak valid");
        scanf("%d %d", &H, &M);
    }
    *J = MakeJAM(H, M);
}
void TulisJAM(JAM J)
// IS : J sembarang
// FS : J ditulis dilayar dengan format HH:MM:SS
// Proses : Menulis ke layar
{   /*Kamus Lokal*/
    /*Algoritma*/
    if (Minute(J)==0){
        printf("%d hour (s)", Hour(J));
    }
    else {
        printf("%d hour (s) %d minute (s)", Hour(J), Minute(J));
    }
}
long JAMToMenit (JAM J)
// Konversi jam jadi menit
{   /* Kamus lokal */
    /* Algoritma */
    return (60*Hour(J) + Minute(J));
}
JAM MenitToJAM (long N)
//Konversi detik ke jam
{   /*Kamus Lokal*/
    int sisa;
    JAM JOut;
    /* Algoritma */
    
    N=N%1440; //harus ditambah ini agar valid
    Hour(JOut)=N/60;
    sisa=N%60;
    Minute(JOut)=sisa;
    return JOut;
}
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{   /*Kamus Lokal*/
    long j1,j2;
    /*Algoritma*/
    j1=JAMToMenit(J1);
    j2=JAMToMenit(J2);
    return (j1==j2);
}

boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{   /*Kamus Lokal*/
    long j1,j2;
    /*Algoritma*/
    j1=JAMToMenit(J1);
    j2=JAMToMenit(J2);
    return (j1!=j2);
}
boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{   /*Kamus Lokal*/
    long j1,j2;
    /*Algoritma*/
    j1=JAMToMenit(J1);
    j2=JAMToMenit(J2);
    return (j1<j2);
}
boolean JGT (JAM J1, JAM J2){
/* Mengirimkan true jika J1>J2, false jika tidak */
    /*Kamus Lokal*/
    long j1,j2;
    /*Algoritma*/
    j1=JAMToMenit(J1);
    j2=JAMToMenit(J2);
    return (j1>j2);
}

JAM NextNMenit (JAM J, int N){
/* Mengirim N menit setelah J dalam bentuk JAM */
   /* Kamus Lokal*/
    long m;
    JAM j;
    /* Algoritma*/
    m = JAMToMenit(J);
    j = MenitToJAM(m+N);
    return j;
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh){
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
    /*Kamus Lokal*/
    int JCurr, JEnd;
    /*Algoritma*/
    JCurr = JAMToMenit(JAw);
    JEnd = JAMToMenit(JAkh);
    if (JLT(JAw,JAkh)) {
        return (JEnd - JCurr);
    }
    else {
        return ((JEnd+1440) - JCurr);
    }
}