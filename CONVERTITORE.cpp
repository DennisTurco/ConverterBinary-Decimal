#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int Max=100;

int main(){
	int s;
	cout<<"Created By Dennis Turco \n\nCONVERTITORE"<<endl<<endl;
	
	do{
		cout<<"Scegliere l'opzione:"<<endl;
		cout<<"\t1)Decimale -----> Binario"<<endl;
		cout<<"\t2)Binario -----> Decimale"<<endl;
		cout<<"Opzione: ";
		cin>>s;
		switch (s){
			case 1:{
				int quoziente, q, n, resto;
				//controllo correttezza valore di input 
				do{	
					if (cin.fail()){
						cout<<"\nValore Inserito Errato...\n";
					cin.clear();
					cin.ignore(256, '\n');	
					}
					cout<<"Inserire Valore da Convertire: ";
					cin>>n;			
				}while (cin.fail());
				
				//QUESTO CICLO CI SERVE PER AVERE UN VALORE i GRANDE PER CONTENERE ESATTAMENTE I BIT DEL VALORE
				int i=0;
				q = n;
				while (q!=0){
					q = (q/2); //mi serve per calcolare il quoziente
					i++;
				}		
				int bin[i];
				
				//REGISTRIAMO I VALORI ALL'INTERNO DELL'ARRAY
				quoziente=n;
				for (int c=0; c<i; c++){
					resto = quoziente % 2;
					quoziente = quoziente /2;
					bin[c]=resto;
				}
				
				cout<<"Numero di Bit: "<<i<<endl;
				cout<<"Valore Binario: ";
								
				//STAMPA DELL'ARRAY
				for(int b=i-1; b>=0; b--)
					cout<<bin[b];
				cout<<endl<<endl;		
				break;
			}
			case 2:{
				int risultato=0;
				char binario[Max];
	
				cout<<"Inserire Valore da Convertire: ";
				cin>>binario;
				
				//calcolo conversione
				for (int i=0; i<strlen(binario); i++){
					if (binario[i]=='1')
						risultato= risultato+pow(2, strlen(binario)-1-i);	
				}
			
				cout<<"Valore Decimale: "<<risultato<<endl<<endl;					
				break;
			}
			default:
				cout<<"Opzione non valida!!"<<endl;
				break;
			
		}
	}while(true);
	
	cout<<endl;
	system ("Pause");
	return 0;
}
