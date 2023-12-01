#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
 
void limpiarPantalla() {
 system("clear"); //en windows seria system("cls");
}
 
//se define una clase
class cifrado {
 private:
 char *cadena; //cadena en la que se carga el archivo
 long tam; //tamaño del archivo
 public:
 ~cifrado(); //destructor
 void leer_de_disco( const char* );
 void cifrar( const char* );
 void descifrar( const char* );
 void grabar_en_disco( const char* );
};
 
// leer_de_disco:
// abre la direccion del archivo que es pasado por parametro
// y guarda su contenido en la cadena
void cifrado::leer_de_disco(const char* nombre_archivo) {
 FILE *ar1;
 
 //abre el archivo
 ar1 = fopen( nombre_archivo,"rb" );
 if( !ar1 )exit(1); //si no puede sale
 
 fseek( ar1,0,2 ); //se posiciona al final
 tam = ftell( ar1 ); //guarda el numero
 fseek( ar1,0,0 ); //se posiciona al principio
 
 //crea un vector del tamaño conseguido
 cadena = new char[tam];
 
 //intenta leer los datos, si no puede sale
 if( !fread(cadena,tam,1,ar1) )exit(1);
 
 fclose( ar1 ); //cierra el archivo
}
 
// cifrar:
// suma el codigo ASCII de la cadena con una
// clave que es pasada por parametro
void cifrado::cifrar(const char *clave) {
 int x=0,y=0; //indices de las cadenas
 
 //mientras no sea el fin de la cadena
 while( cadena[x]!=0 )
 {
 cadena[x]+=clave[y]; //suma el codigo ASCII
 x++; //pasa a la siguiente posicion
 
 if( clave[y+1]==0 ) //si se llega al final de la cadena
 y=0; //comienza de nuevo
 else //si no
 y++; //sigue incrementando el indice
 }
}
 
// descifrar:
// resta al codigo ASCII de la cadena
// la clave que es pasada por parametro
void cifrado::descifrar(const char *clave) {
 int x=0,y=0; //indices de las cadenas
 
 //mientras no sea el fin de la cadena
 while( cadena[x]!=0 )
 {
 cadena[x]-=clave[y]; //resta el codigo ASCII
 x++; //pasa a la siguiente posicion
 
 if( clave[y+1]==0 ) //si se llega al final de la cadena
 y=0; //comienza de nuevo
 else //si no
 y++; //sigue incrementando el indice
 }
}
 
// grabar_en_disco
// abre la direccion que es pasada por parametro
// y guarda el contenio de la cadena
void cifrado::grabar_en_disco( const char *nombre_archivo ) {
 FILE *ar1;
 
 //abre el archivo
 ar1 = fopen( nombre_archivo,"rb+" );
 if( !ar1 )exit(1); //si no puede sale
 
 //intenta escribir los datos, si no puede sale
 if( !fwrite(cadena,tam,1,ar1) )exit(1);
 
 fclose( ar1 ); //cierra el archivo
}
 
cifrado::~cifrado() {
 delete[] cadena; //libera la memoria
}
 
int main() {
 cifrado archivo; //objeto para manejar el proceso
 
 int opcion; //opcion del menu
 char nombre_archivo[30]; //direccion del archivo
 char clave_archivo[30]; //clave
 
 do {
	 limpiarPantalla(); //limpia pantalla y muestra menu
	 cout << "1. Seleccionar Archivo" << endl;
	 cout << "2. Cifrar" << endl;
	 cout << "3. Descifrar" << endl;
	 cout << "4. Cerrar programa" << endl;
	 cout << "Opcion: ";
	 
	 cin >> opcion; //pide el ingreso de una opcion
	 
	 clave_archivo[0] = 0; //pone en cero la clave
	 
	 switch( opcion ) {
		 case 1:
			 cout << "Nombre del archivo: ";
			 cin.ignore();
			 //se ingresa la direccion del archivo
			 cin.getline( nombre_archivo,30 );
			 
			 //si la cadena esta vacia no hace nada
			 if( nombre_archivo[0]==0 )break;
			 archivo.leer_de_disco( nombre_archivo );
		 break;
	 
		 case 2:
			 //si la cadena esta vacia no hace nada
			 if( nombre_archivo[0]==0 )break;
			 cout << "Ingrese la clave: ";
			 cin.ignore();
			 //se ingresa la cable para cifrar
			 cin.getline( clave_archivo,30 );
			 
			 //si la clave esta vacia no hace nada
			 if( clave_archivo[0]==0 )break;
			 archivo.cifrar( clave_archivo ); //cifra
			 archivo.grabar_en_disco( nombre_archivo ); //guarda
		 break;
	 
		 case 3:
			 //si la cadena esta vacia no hace nada
			 if( nombre_archivo[0]==0 )break;
			 cout << "Ingrese la clave: ";
			 cin.ignore();
			 //se ingresa la clave para descifrar
			 cin.getline( clave_archivo,30 );
			 
			 //si la clave esta vacia no hace nada
			 if( clave_archivo[0]==0 )break;
			 archivo.descifrar( clave_archivo ); //descifra
			 archivo.grabar_en_disco( nombre_archivo ); //guarda
		 break;
	 
		 case 4:
			return 0; //sale del programa
		 break;
	 }
 }while(1);
} 
