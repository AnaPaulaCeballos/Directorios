//Este programa solo lee las librerias del directorio 
#include<iostream>
#include<stdlib.h>
#include<fstream> 
#include<dirent.h>		//manejo de directorios

using namespace std; 
void init();
void listar(string dir);

int main(){
	init();
	return 0;
}//fnmain

void init() {
	string dir;
	cin >> dir;
	//getline(cin, dir);
	listar(dir);
	return;
}//fin init

void listar(string dir){
	DIR* directorio;
	struct dirent* elemento;
	string elem;
	int size;
	ofstream archivo; 

	archivo.open("dire.json", ios::out);

	if (directorio = opendir(dir.c_str())) {		//si puedo abrir el directorio
		while (elemento = readdir(directorio))	//recorres elemento por elemento 
		{
			elem = elemento->d_name;
			//size = elemento->d_reclen();
			//size=files.st_size; 
			size = 2400;		//for demo
			if (elem != "." && elem != "..") {
				cout << "nombre " << elem << " size " << size << endl;
				archivo << "nombre " << elem << " size " << size << endl;
			}//fn if "."
		}//fn while
	}//fn if open
	archivo.close();
	closedir(directorio);
	return;
}//fin dir