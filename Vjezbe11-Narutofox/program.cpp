#include<iostream>
#include"symbol_table.h"
#include <vector>

symbol_table unos(vector<student> polje) {
	symbol_table st;
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
	/*a.jmbag =  atoi(s.c_str());*/
	for (unsigned int i = 0; i < polje.size(); i++)
	{
		if (a.jmbag == polje[i].jmbag)
		{
			cout <<"JMBAG vec postoji! " << endl;
			return unos(polje);
		}
	}
	cout <<"Unesite broj indexa studenta: " << endl;
	cin >> a.broj_indeksa;
	polje.push_back(a);
	cout <<"Zelite jos Da/Ne?"; 
	cin >> jos;
	} while (jos == "Da");
	for (unsigned int i = 1; i < polje.size(); i++)
	{
		student s_temp = polje[i];

		st.put(a.jmbag,s_temp);
	}
	return st;
}
void Pretrazivanje(symbol_table ps3){
	string s;
	cout <<"Unesite JMBAG studenta: ";
	cin >> s;

	student* pronalazak = ps3.get(s);

	if (pronalazak != nullptr)
	{
		cout << pronalazak->ime <<" " << pronalazak->prezime;
	}
	else
	{
		cout <<"Student sa trazenim JMBAG-om ne postoji "; 
	}

}

void Brisanje(symbol_table ps4 ){
	string p;
	cout <<"Unesite JMBAG studenta kojeg zelite izbrisati: ";
	cin >> p;
	if (ps4.remove(p))
	{
		cout <<"Student uspjesno izbrisan ";
	}
	else
	{
		cout <<"Student ne postoji ";
	}
}
int main(){
	symbol_table studenti;
	vector<student>polje;
	char izbor;
	cout <<"Koju operaciju zelite? " << endl;
	cout <<"A) Unos " <<endl << "B) Pretrazivanje " << endl <<"C) Brisanje " <<endl<< "D) Izlaz "<< endl ;
	cin >> izbor;
	switch (izbor)
	{
	case 'A': 
		studenti = unos(polje);
		break;
	case 'B' :
		Pretrazivanje(studenti);
		break;
	case 'C' :
		Brisanje(studenti);
		break;
	case 'D' :
		return 0;
	default:
		cout << "Pogresan unos " << endl;
		return main();
	}
	return main();
}