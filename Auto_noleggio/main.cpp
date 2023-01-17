#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

const int c=7;
struct macchina
{
    string categoria,marca,modello,colore;
    string lun,mar,mer,gio,ven,sab,dom;
};

void carica_dati(macchina concessionario[7], int &i)
{
    ifstream fin("auto.csv");
    string str;
    while(getline(fin,str, ';'))
    {
        cout<<str<<" ";
        concessionario[i].categoria=str;
        getline(fin,concessionario[i].marca, ';');
        cout<<concessionario[i].marca<<" ";
        getline(fin,concessionario[i].modello, ';');
        cout<<concessionario[i].modello<<" ";
        getline(fin,concessionario[i].colore, ';');
        cout<<concessionario[i].colore<<" ";
        getline(fin,concessionario[i].lun, ';');
        cout<<concessionario[i].lun<<" ";
        getline(fin,concessionario[i].mar, ';');
        cout<<concessionario[i].mar<<" ";
        getline(fin,concessionario[i].mer, ';');
        cout<<concessionario[i].mer<<" ";
        getline(fin,concessionario[i].gio, ';');
        cout<<concessionario[i].gio<<" ";
        getline(fin,concessionario[i].ven, ';');
        cout<<concessionario[i].ven<<" ";
        getline(fin,concessionario[i].sab, ';');
        cout<<concessionario[i].sab<<" ";
        getline(fin,concessionario[i].dom);
        cout<<concessionario[i].dom<<" ";
        i++;
        cout<<endl<<endl;
    }
    fin.close();
}

void prenotazione(int &i)
{

    ofstream fout("db_allenatori.csv");

    fout.close();

}

int main()
{
    macchina concessionario[c];
    int scelta;
    int i=0;
    do{
        cout<<endl<<endl;
        cout<<"1 - Prenotazione auto da noleggiare"<<endl;
        cout<<"2 - Uscita"<<endl<<">>";
        cin>>scelta;
        switch(scelta)
        {
            case 1:
                carica_dati(concessionario,i);
                prenotazione(i);
                break;
            case 3:
                cout<<"Uscita...";
        }
    }while(scelta!=2);
    return 0;
}
