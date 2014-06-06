#include"symbol_table.h"
#include"lista.h"
symbol_table::symbol_table(){

}

bool symbol_table:: put(string key, ELTYPE value){
	for (POSITION node = _lista.first(); node != _lista.end(); node=node->next)
	{
		if (node->element.jmbag == key)
		{
			return false;
		}
	}
	_lista.insert(value,_lista.end());
	return true;
	
	
}

ELTYPE* symbol_table:: get(string key){
	for (POSITION node = _lista.first(); node != _lista.end(); node=node->next)
	{
		if (node->element.jmbag == key)
		{
			return &node->element;
		}
	}
	return nullptr;
}

bool symbol_table:: remove(string key){
	for (POSITION node = _lista.first(); node!= _lista.end(); node=node->next)
	{
		if (node->element.jmbag == key)
		{
			_lista.remove(node);
			return true;
		}
	}
	return false;
}
