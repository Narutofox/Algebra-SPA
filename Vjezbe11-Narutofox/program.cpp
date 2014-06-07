#include<iostream>
#include"symbol_table.h"


symbol_table unos(symbol_table st) {
	student a;
	string s;
	string jos;
	do
	{
	cout <<"Unesite ime student: " << endl;
	cin >> a.ime;
	cout <<"Unesite prezime studenta: " << endl;
	cin >> a.prezime;
	cout <<"Unesite JMBAG studenta (NAPOMENA JMBAG NESMIJE ZAPOCETI S NULOM!) " << endl;
	cin >> a.jmbag;
		while (!st.put(a.jmbag,a))
		{
	cout <<"JMBAG vec postoji";
		cout <<"Unesite JMBAG studenta (NAPOMENA JMBAG NESMIJE ZAPOCETI S NULOM!) " << endl;
		cin >> a.jmbag;
		}
	cout <<"Unesite broj indexa studenta: " << endl;
	cin >> a.broj_indeksa;
	cout <<"Zelite jos Da/Ne?"; 
	cin >> jos;
	} while (jos == "Da");
	
	return st;
}
void Pretrazivanje(symbol_table ps3){
	string ls;
	cout <<"Unesite JMBAG studenta: " << endl;
	cin >> ls;
	
	student* pronalazak = ps3.get(ls);

	if (pronalazak != nullptr)
	{
		cout << pronalazak->ime <<" " << pronalazak->prezime << endl;
	}
	else
	{
		cout <<"Student sa trazenim JMBAG-om ne postoji " << endl; 
	}

}

void Brisanje(symbol_table ps4 ){
	string p;
	cout <<"Unesite JMBAG studenta kojeg zelite izbrisati: " << endl;
	cin >> p;
	if (ps4.remove(p))
	{
		cout <<"Student uspjesno izbrisan " << endl;
	}
	else
	{
		cout <<"Student ne postoji ";
	}
}
int main(){
	symbol_table st;
	
	char izbor;
	
	do
	{
	cout <<"Koju operaciju zelite? " << endl;
	cout <<"A) Unos " <<endl << "B) Pretrazivanje " << endl <<"C) Brisanje " <<endl<< "D) Izlaz "<< endl ;
	cin >> izbor;
	switch (izbor)
	{
	case 'A': 
		unos(st);
		break;
	case 'B' :
		Pretrazivanje(st);
		break;
	case 'C' :
		Brisanje(st);
		break;
	case 'D' :
		break;
	default:
		cout << "Pogresan unos " << endl;
	}

	} while ( izbor != 'D');
	
return 0;
}
