#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
using namespace std;
ifstream f("date.txt");
int n, k = 0, g = 1;
struct produs{
    char denumire[50];
    float pret;
    int cant;
    float valvan;
}p[50];
void defaultaf(){
    cout << "BUNA ZIUA! APASATI TASTA NUMERICA CORESPUNZATOARE OPTIUNII:\n";
    cout << "\t1 - INTRODUCETI DATELE UNUI NOU PRODUS\n";
    cout << "\t2 - VALOAREA MEDIE A TUTUROR PRODUSELOR\n";
    cout << "\t3 - AFISAREA IN ORDINE ALFABETICA A PRODUSELOR\n";
}
void citire(produs p[50]){
    for(int i=0;i<n;i++){
        f.get();
        f.get(p[i].denumire, 50);
        f.get();
        f >> p[i].pret;
        f >> p[i].cant;
        f.get();
        p[i].valvan = p[i].pret * p[i].cant;
        k = n;
    }
}
void afisare(produs p[50]){
    for(int i=0;i<n;i++){
        cout << "DENUMIRE: " << p[i].denumire << "\n";
        cout << "PRET: " << p[i].pret << "\n";
        cout << "CANTITATE: " << p[i].cant << "\n";
        cout << "VALOAREA VANZARII: " << p[i].valvan << "\n\n";
    }
}
void f1(produs p[50]){
    n++;
    cout << "INTRODU DATELE:\n";
    cout << "DENUMIRE: ";
    cin.get(p[n-1].denumire, 50);
    cin.get();
    cout << "PRET: ";
    cin >> p[n-1].pret;
    cout << "CANTITATEA VANDUTA: ";
    cin >> p[n-1].cant;
    p[n-1].valvan = p[n-1].pret * p[n-1].cant;
    cout << "VALOAREA VANZARII ESTE: " << p[n-1].valvan << "\n";
    cout << "APASATI ENTER PENTRU A REVENI LA MENIU";
    cin.get(); cin.get();
    system("cls");
}
void f2(produs p[50]){
    float med = 0;
    for(int i=0;i<n;i++){
        med += p[i].pret;
    }
    cout << "MEDIA TUTUROR PRODUSELOR: " << med/n << "\n";
    cout << "APASATI ENTER PENTRU A REVENI LA MENIU";
    cin.get();
}
void f3(produs a[50]){
    produs b[50];
    for(int i=0;i<n;i++)
        strcpy(b[i].denumire, a[i].denumire);
    char aux[50]; int ok = 0;
    while(!ok){
        ok = 1;
        for(int i=0;i<n-1;i++)
            if(stricmp(b[i].denumire, b[i+1].denumire) > 0){
                strcpy(aux, b[i].denumire);
                strcpy(b[i].denumire, b[i+1].denumire);
                strcpy(b[i+1].denumire, aux);
                ok = 0;
            }
    }
    for(int i=0;i<n;i++){
        cout << b[i].denumire << "\n";
    }
    cout << "APASATI ENTER PENTRU A REVENI LA MENIU";
}
void meniu(){
    defaultaf();
    char ch = _getch();
    cout << ch;
    switch(ch){
    case '1':
        system("cls");
        f1(p);
        break;

    case '2':
        system("cls");
        f2(p);
        system("cls");
        break;
    case '3':
        system("cls");
        f3(p);
        cin.get();
        system("cls");
        break;
    }
}
int main(){
    f >> n;
    citire(p);
    while(1) meniu();
    ///afisare(p);
    return 0;
}
