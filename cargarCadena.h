#ifndef CARGARCADENA_H_INCLUDED
#define CARGARCADENA_H_INCLUDED

void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}

void cargarLinea(char cadena[], int tam){
	std::cin>>std::ws;
	std::cin.getline(cadena,tam,'\n');
}

#endif // CARGARCADENA_H_INCLUDED
