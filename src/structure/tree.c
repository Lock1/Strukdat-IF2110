#include "tree.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* *** PROTOTYPE *** */

/* *** Konstruktor *** */
BinTree Tree (infotype Akar, BinTree L, BinTree R)
{
    BinTree New_tree = (BinTree) malloc(sizeof(BinTree));

    if (New_tree != Nil){
        Akar(New_tree) = Akar;
        Left(New_tree) = L;
        Right(New_tree) = R;    
    }
    return New_tree;
}


void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P)
{
    *P = Tree(Akar, L, R);
}

/* Manajemen Memory */
addrNode AlokNode (infotype X)
{
    addrNode New_node = (addrNode) malloc(sizeof(Node));

    if (New_node != Nil){
        Akar(New_node) = X;
        Left(New_node) = Nil;
        Right(New_node) = Nil;
    }
    return New_node;
}

void DealokNode (addrNode P)
{
    free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P)
{
    return P == Nil;
}

boolean IsTreeOneElmt (BinTree P)
{
    if (!IsTreeEmpty(P)){
        return ((Left(P) == Nil) && (Right(P) == Nil));
    }
    else{
        return false;
    }
}

boolean IsUnerLeft (BinTree P)
{
    if (!IsTreeEmpty(P)){
        return ((Left(P) != Nil) && (Right(P) == Nil));
    }
    else{
        return false;
    }
}

boolean IsUnerRight (BinTree P)
{
    if (!IsTreeEmpty(P)){
        return ((Left(P) == Nil) && (Right(P) != Nil));
    }
    else{
        return false;
    }
}

boolean IsBiner (BinTree P)
{
    if (!IsTreeEmpty(P)){
        return ((Left(P) != Nil) && (Right(P) != Nil));
    }
    else{
        return false;
    }
}

void PrintTree2(BinTree P, int h, int current_indent)
{
  if (!IsTreeEmpty(P))
  {

    printf("%*s%d\n", current_indent, "", Akar(P));

    PrintTree2(Left(P), h, current_indent + h);
    PrintTree2(Right(P), h, current_indent + h);
  }
}

/* *** Traversal *** */
void PrintTree (BinTree P, int h)
{
  PrintTree2(P, h, 0);
}

/* *** Searching *** */
boolean SearchTree (BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if (IsTreeEmpty(P)){
        return false;
    }
    else{
        if (Akar(P) == X){
            return true;
        }
        else{
            return SearchTree(Left(P), X) || SearchTree(Right(P), X);
        }
    }
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt (BinTree P)
{
    if (IsTreeEmpty(P)){
        return 0;
    }
    else {
        return NbElmt(Left(P)) + NbElmt(Right(P)) + 1 ;
    }
}

int NbDaun (BinTree P)
{
    if (IsTreeEmpty(P)){
        return 0;
    }
    else {
        if (IsTreeOneElmt(P)){
            return 1;
        }
        else{
            return NbDaun(Left(P)) + NbDaun(Right(P));
        }
    }
}


int Level (BinTree P, infotype X)
{
    if (SearchTree(Left(P), X)){
        return 1 + Level(Left(P), X);
    }

    else if (SearchTree(Right(P), X)){
        return 1 + Level(Right(P), X);
    }
    else {
        return 1;
    }
}

int Tinggi (BinTree P)
{
   if (IsTreeEmpty(P)){
        return 0;
   }
   else{
        int Tinggi_l = Tinggi(Left(P));
        int Tinggi_r = Tinggi(Right(P));

        if (Tinggi_l > Tinggi_r){
            return Tinggi_l + 1;
        }
        else{
            return Tinggi_r + 1;
        }
   }
}

/* *** Operasi lain *** */
void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri)
{
    if (IsTreeOneElmt(*P) && Akar(*P) == X){

        if (Kiri){
            Left(*P) = Tree(Y, Nil, Nil);
        }
        else{
            Right(*P) = Tree(Y, Nil, Nil);
        }
    }
    else{
        if (SearchTree(Left(*P), X)){
            AddDaun(&Left(*P), X, Y, Kiri);
        }
        else if (SearchTree(Right(*P), X)){
            AddDaun(&Right(*P), X, Y, Kiri);
        }
    }
}

void DelDaun (BinTree *P, infotype X)     
{
    if (!IsTreeEmpty(*P)){

        if (IsTreeOneElmt(*P) && Akar(*P) == X){
            addrNode temp = *P;
            *P = Nil;
            DealokNode(temp);
        }
        else {

            DelDaun(&Left(*P), X);
            DelDaun(&Right(*P), X);
        }
    }
}

List MakeListDaun (BinTree P)
{
    if (IsTreeEmpty(P)){
        return Nil;
    }

    else if (IsTreeOneElmt(P)){
        return Alokasi(Akar(P));
    }

    else{

        List Left_l = MakeListDaun(Left(P));
        List Right_l = MakeListDaun(Right(P));
        return Concat(Left_l, Right_l);
    }

}

List MakeListPreorder (BinTree P)
{
   if (IsTreeEmpty(P)){
        return Nil;
   }
   else{

        List Left_l = MakeListPreorder(Left(P));
        List Right_l = MakeListPreorder(Right(P));

        return Concat(Konso(Akar(P), Left_l), Right_l);
   }
}

List MakeListLevel (BinTree P, int N)
{
    if (IsTreeEmpty(P)){
        return Nil;
    }
    else if (N == 1){
        return Alokasi(Akar(P));
    }
    else {
        List Left_l = MakeListLevel(Left(P), N-1);
        List Right_l = MakeListLevel(Right(P), N-1);

        return Concat(Left_l, Right_l);

    }
}