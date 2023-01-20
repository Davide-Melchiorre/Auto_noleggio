#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

const int c=7;
struct macchina
{
    string categoria,marca,modello,colore;
    string lun,mar,mer,gio,ven,sab,dom;
    int num;
};

void carica_dati(macchina concessionario[], int &i)
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

void prenotazione(macchina concessionario[],macchina appoggio[], int &i)
{
    string categoria;
    int cont=0,a=1,num;
    cout<<"Inserisci la categoria di macchina da prenotare: ";
    cin>>categoria;
    while(cont<=i)
    {
        if(categoria==concessionario[cont].categoria)
        {
            appoggio[a-1].num=a;
            concessionario[cont].num=a;
            cout<<concessionario[cont].num<<". ";
            appoggio[a-1].categoria=concessionario[cont].categoria;
            cout<<concessionario[cont].categoria<<" ";
            appoggio[a-1].marca=concessionario[cont].marca;
            cout<<concessionario[cont].marca<<" ";
            appoggio[a-1].modello=concessionario[cont].modello;
            cout<<concessionario[cont].modello<<" ";
            appoggio[a-1].colore=concessionario[cont].colore;
            cout<<concessionario[cont].colore<<" ";
            appoggio[a-1].lun=concessionario[cont].lun;
            cout<<concessionario[cont].lun<<" ";
            appoggio[a-1].mar=concessionario[cont].mar;
            cout<<concessionario[cont].mar<<" ";
            appoggio[a-1].mer=concessionario[cont].mer;
            cout<<concessionario[cont].mer<<" ";
            appoggio[a-1].gio=concessionario[cont].gio;
            cout<<concessionario[cont].gio<<" ";
            appoggio[a-1].ven=concessionario[cont].ven;
            cout<<concessionario[cont].ven<<" ";
            appoggio[a-1].sab=concessionario[cont].sab;
            cout<<concessionario[cont].sab<<" ";
            appoggio[a-1].dom=concessionario[cont].dom;
            cout<<concessionario[cont].dom<<" ";
            cout<<endl;
            a++;
        }
        cont++;
    }
    cont=0;
    cout<<endl;
    cout<<"Inserisci il numero della macchina da prenotare: ";
    cin>>num;
    cout<<endl;
    while(cont<=a)
    {
        if(num==appoggio[cont].num)
        {
            cout<<"I giorni liberi della macchina sono:"<<endl;
            if(appoggio[cont].lun=="L")
                cout<<"1. Lunedi"<<endl;
            if(appoggio[cont].mar=="L")
                cout<<"2. Martedi"<<endl;
            if(appoggio[cont].mer=="L")
                cout<<"3. Mercoledi"<<endl;
            if(appoggio[cont].gio=="L")
                cout<<"4. Giovedi"<<endl;
            if(appoggio[cont].ven=="L")
                cout<<"5. Venerdi"<<endl;
            if(appoggio[cont].sab=="L")
                cout<<"6. Sabato"<<endl;
            if(appoggio[cont].dom=="L")
                cout<<"7. Domenica"<<endl;

        }
           cont++;
    }
    ofstream fout("db_allenatori.csv");

    fout.close();

}

int main()
{
    macchina concessionario[c];
    macchina appoggio[c];
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
                prenotazione(concessionario,appoggio,i);
                break;
            case 3:
                cout<<"Uscita...";
        }
    }while(scelta!=2);
    return 0;
}
