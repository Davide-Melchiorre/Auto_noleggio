#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <string.h>
#include <stdio.h>

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
    string sce;
    string categoria,cat1; char ch[70];
    int cont=0,a=1,num[50],p=0,c2=0, n,contatore=0,n2=0,n3=0;
    cin.ignore();
    cout<<endl<<"Inserire la categoria e i giorni della macchina da prenotare: ";
    getline(cin,categoria);
    for(int i=0; i<categoria.length(); i++)
    {
        ch[i]=categoria[i];
        categoria[i]='0';
        if(ch[i]==' ')
        {
            break;
        }

    }
    int b=0;
    while(ch[b]!=' ')
    {
       cat1+=ch[b];
       b++;
    }

    n=0;
    for(int cc=0;cc<=cat1.length();cc++)
    {
        n++;
    }
    c2=n;
    n=0;
    for(int i=0; i<categoria.length(); i++)
    {
        p=(int)categoria[c2];
        if(p!=32)
        {
            if(p!=0)
            {
                if(p<=55 && p>=49)
                {
                    num[n]=(int)categoria[c2]-48;
                    n++;
                }
            }
            c2++;
        }
        else
        {
            c2++;
        }
    }
    cout<<endl<<"Le macchine disponibili sono: "<<endl<<endl;
    while(cont<i)
    {

        if(cat1==concessionario[cont].categoria)
        {
            for(int i=0;i<n;i++)
            {
                n2=num[i];
                if(concessionario[cont].lun=="L" && n2==1)
                    contatore++;

                if(concessionario[cont].mar=="L" && n2==2)
                    contatore++;

                if(concessionario[cont].mer=="L" && n2==3)
                    contatore++;

                if(concessionario[cont].gio=="L" && n2==4)
                    contatore++;

                if(concessionario[cont].ven=="L" && n2==5)
                    contatore++;

                if(concessionario[cont].sab=="L" && n2==6)
                    contatore++;

                if(concessionario[cont].dom=="L" && n2==7)
                    contatore++;
                n2=0;
            }
            if(contatore==n)
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
                cout<<concessionario[cont].colore<<endl;
                appoggio[a-1].lun=concessionario[cont].lun;
                appoggio[a-1].mar=concessionario[cont].mar;
                appoggio[a-1].mer=concessionario[cont].mer;
                appoggio[a-1].gio=concessionario[cont].gio;
                appoggio[a-1].ven=concessionario[cont].ven;
                appoggio[a-1].sab=concessionario[cont].sab;
                appoggio[a-1].dom=concessionario[cont].dom;
                a++;
            }
            contatore=0;
        }
        cont++;
    }
    cont=0;
    cout<<endl<<"Inserisci il numero della macchina da prenotare: ";
    cin>>n3;
    while(cont<a-1)
    {
        if(n3==appoggio[cont].num)
        {
            for(int i=0;i<n;i++)
                {
                    n2=num[i];
                    if(appoggio[cont].lun=="L" && n2==1)
                        appoggio[cont].lun="A";

                    if(appoggio[cont].mar=="L" && n2==2)
                        appoggio[cont].mar="A";

                    if(appoggio[cont].mer=="L" && n2==3)
                        appoggio[cont].mer="A" ;

                    if(appoggio[cont].gio=="L" && n2==4)
                        appoggio[cont].gio="A";

                    if(appoggio[cont].ven=="L" && n2==5)
                        appoggio[cont].ven="A";

                    if(appoggio[cont].sab=="L" && n2==6)
                        appoggio[cont].sab="A";

                    if(appoggio[cont].dom=="L" && n2==7)
                        appoggio[cont].dom="A";
                n2=0;
            }
        }
        cont++;

    }
    cont=0; c2=0;
    while(cont<i && c2<=a-1)
    {
        if(concessionario[cont].categoria==appoggio[c2].categoria)
            if(concessionario[cont].marca==appoggio[c2].marca)
                if(concessionario[cont].modello==appoggio[c2].modello)
                    if(concessionario[cont].colore==appoggio[c2].colore)
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
