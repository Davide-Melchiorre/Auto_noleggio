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
        cout<<endl;
    }
    fin.close();
}

void prenotazione(macchina concessionario[],macchina appoggio[], int &i)
{
    string categoria,sce;
    int cont=0,a=1,num,p,c2=0;
    cout<<endl<<"Inserire la categoria di macchina da prenotare: ";
    cin>>categoria;
    while(cont<i)
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
    if(a==1)
    {
        cout<<"Nome della categoria errato";

    }
    else
    {
        cout<<endl;
        cout<<"Inserisci il numero della macchina da prenotare: ";
        cin>>num;
        cout<<endl;
        while(cont<a-1)
        {
            if(num==appoggio[cont].num)
            {
                do{
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

                    cout<<endl<<"Inserire il numero del giorno da prenotare: ";
                    cin>>p;
                    if(appoggio[cont].lun=="L" && p==1)
                        appoggio[cont].lun="A";

                    if(appoggio[cont].mar=="L" && p==2)
                        appoggio[cont].mar="A";

                    if(appoggio[cont].mer=="L" && p==3)
                        appoggio[cont].mer="A";

                    if(appoggio[cont].gio=="L" && p==4)
                        appoggio[cont].gio="A";

                    if(appoggio[cont].ven=="L" && p==5)
                        appoggio[cont].ven="A";

                    if(appoggio[cont].sab=="L" && p==6)
                        appoggio[cont].sab="A";

                    if(appoggio[cont].dom=="L" && p==7)
                        appoggio[cont].dom="A";

                    cout<<endl<<"Vuoi prenotare la macchina per un altro giorno? [si/no]"<<endl;
                    cin>>sce;
                    cout<<endl;
                }while(sce=="si" || sce=="Si");
            }
                cont++;
        }

        cont=0;
        while(cont<i && c2<=a-1)
        {
            if(categoria==concessionario[cont].categoria)
            {
                concessionario[cont].categoria=appoggio[c2].categoria;
                concessionario[cont].marca=appoggio[c2].marca;
                concessionario[cont].modello=appoggio[c2].modello;
                concessionario[cont].colore=appoggio[c2].colore;
                concessionario[cont].lun=appoggio[c2].lun;
                concessionario[cont].mar=appoggio[c2].mar;
                concessionario[cont].mer=appoggio[c2].mer;
                concessionario[cont].gio=appoggio[c2].gio;
                concessionario[cont].ven=appoggio[c2].ven;
                concessionario[cont].sab=appoggio[c2].sab;
                concessionario[cont].dom=appoggio[c2].dom;
                c2++;
            }
            cont++;
        }
        cout<<"Prenotazione avvenuta con successo!"<<endl;
    }

}

void scritturaFile(macchina concessionario[], int &i)
{
    ofstream fout("auto.csv");
    int cont=0;
    cout<<endl;
    while(cont<i)
    {
        fout<<concessionario[cont].categoria<<';';
        fout<<concessionario[cont].marca<<';';
        fout<<concessionario[cont].modello<<';';
        fout<<concessionario[cont].colore<<';';
        fout<<concessionario[cont].lun<<';';
        fout<<concessionario[cont].mar<<';';
        fout<<concessionario[cont].mer<<';';
        fout<<concessionario[cont].gio<<';';
        fout<<concessionario[cont].ven<<';';
        fout<<concessionario[cont].sab<<';';
        fout<<concessionario[cont].dom;
        fout<<endl;
        cont++;
    }
    fout.close();

    ifstream fin("auto.csv");
    string str;
    while(getline(fin,str, ';'))
    {
        cout<<str<<" ";
    }
    fin.close();

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
                scritturaFile(concessionario,i);
                break;
            case 3:
                cout<<"Uscita...";
        }
    }while(scelta!=2);
    return 0;
}
