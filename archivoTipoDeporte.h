#ifndef ARCHIVOTIPODEPORTE_H_INCLUDED
#define ARCHIVOTIPODEPORTE_H_INCLUDED

class ArchivoTipoDeporte{
private:
    char nombre[30];
public:
    ArchivoTipoDeporte(const char *n){
        strcpy(nombre,n);
    }
    int contarRegistros(); ///CANTIDAD DE REGISTROS
    int buscarID(int dni); ///POSICION DEL REGISTRO
    TipoDeporte leerRegistro(int posicion); ///LEER
    int grabarRegistro(TipoDeporte reg); ///ESCRIBIR
    bool modificarRegistro(TipoDeporte reg, int pos); ///MODIFICAR REGISTRO
    bool modificarNivel();
    bool agregarRegistro();
    void listarRegistroID();
    bool listarRegistros();
    bool bajaLogica();

    bool modificarMatricula();
};

int ArchivoTipoDeporte::contarRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL) return -1;
    fseek(p,0,SEEK_END); ///POSICIONA EL PUNTERO AL FINAL DEL ARCHIVO
    int tam=ftell(p); ///OBTENEMOS EL TAMAÑOS TOTAL DEL ARCHIVO
    fclose(p);
    return tam/sizeof(TipoDeporte); ///DIVIDE EL TAMAÑO TOTAL DEL ARCHIVO ENTRE EL TAMAÑO EN BYTES DE UN REGISTRO DEL TIPO "JUGADOR"
}

int ArchivoTipoDeporte::buscarID(int id){
    TipoDeporte reg;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p == NULL){
        cout<<"ERROR DE ARCHIVO. NO SE PUDO BUSCAR EL ID"<<endl;
        return -5;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(TipoDeporte),1,p) == 1){
        if(reg.getID() == id){
            fclose(p);
            ///SI EXISTE DEVUELVE LA POSICION
            return posRegistro;
        }
        posRegistro++;
    }
    fclose(p);
    ///SI NO EXISTE DEVUELVE -1
    return -1;
}

TipoDeporte ArchivoTipoDeporte::leerRegistro(int posicion){
    FILE *p;
    TipoDeporte reg;
    p=fopen(nombre,"rb");
    if(p==NULL) exit(-4);
    fseek(p, posicion * sizeof(reg),0);
    fread(&reg, sizeof(reg), 1, p);
    fclose(p);
    return reg;
}

int ArchivoTipoDeporte::grabarRegistro(TipoDeporte reg){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL) return -3;
    int escribio=fwrite(&reg, sizeof(TipoDeporte), 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoTipoDeporte::modificarRegistro(TipoDeporte reg, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof reg*pos,0);
    bool escribio = fwrite(&reg,sizeof(TipoDeporte),1,p);
    fclose(p);
    return escribio;
}

///OP1
bool ArchivoTipoDeporte::agregarRegistro(){
    FILE *p;
    p = fopen("TipodeDeporte.dat","ab");
    if(p == nullptr){
        cout<< "ERROR DE ARCHIVO. NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        return false;
    }
    TipoDeporte reg;
    ArchivoTipoDeporte archi("TipodeDeporte.dat");
    int cantReg = contarRegistros();

    ///ASIGNA EL ID Y SE CARGAN EL RESTO DE DATOS
    if(cantReg <= 20)reg.setID(cantReg+1);
    else {
        cout<< "NO ES POSIBLE CARGAR MAS REGISTROS DE TIPO DEPORTE" <<endl;
        return false;
    }
    if(reg.cargar() == true){
        ///SI ES VALIDO AGREGA UN NUEVO REGISTRO AL ARCHIVO
        int escribio = grabarRegistro(reg);
        if(escribio == 1){
            fclose(p);
            return true;
        }
	}
    fclose(p);
    return false;
}

///OP2
void ArchivoTipoDeporte::listarRegistroID(){
    TipoDeporte reg;
    int id;
    cout<<"INGRESE ID"<<endl;
    cin>>id;
    int posicion = buscarID(id);
    if(posicion != -1){
        system("cls");
        reg = leerRegistro(posicion);
        if(reg.getEstado() == true) {
            cout<<"***ID REGISTRADO***"<<endl;
            cout<<endl;
            reg.mostrar();
            return;
        }
        cout << "EL ID SE ENCUENTRA REGISTRADO PERO ESTA DADO DE BAJA" <<endl;
        return;
    }
    else {
        system("cls");
        cout<<"EL ID NO SE ENCUENTRA REGISTRADO"<<endl;
        return;
    }
}

///OP3
bool ArchivoTipoDeporte::listarRegistros(){
    TipoDeporte reg;
    FILE *p = fopen("TipodeDeporte.dat", "rb");
    bool encontroRegistro = false;
    if(p == NULL){
        cout<< "ERROR DE ARCHIVO: NO SE PUDO MOSTRAR." <<endl;
        return false;
    }
    while(fread(&reg, sizeof(TipoDeporte),1,p)==1){
        if(reg.getEstado()==true){
            encontroRegistro = true;
            reg.mostrar();
            cout<<endl;
        }
    }
    fclose(p);
    return encontroRegistro;
}

///OP4
bool ArchivoTipoDeporte::modificarNivel(){
    int id;
    bool encontrado = false;
    cout<<"INGRESE ID"<<endl;
    cin>>id;

    ///1.BUSCA EL ID PARA OBTENER LA POSICION
    int posicion=buscarID(id);
    if(posicion == -1) {
        cout<<"EL ID DEL DEPORTE NO SE ENCONTRO EN EL ARCHIVO"<<endl;
        return false;
    }

    ///2.SE VERIFICA SI EL ID EXISTE EN EL ARCHIVO Y SI EL DEPORTE ESTA ACTIVO
    TipoDeporte reg = leerRegistro(posicion);
    if(reg.getEstado()==false){
        cout<<"EL DEPORTE NO ESTA ACTIVO"<<endl;
        return false;
    }

    ///3. SE CARGO EL NIVEL DE DIFICULTAD ACTUAL Y SE ACTUALIZA EN EL REGISTRO
    int nivel;
    cout<<"INGRESE NUEVO NIVEL DE DIFICULTAD"<<endl;
    cin>>nivel;
    if(nivel < 1 || nivel > 8){
        system("cls");
        cout<<"NIVEL DE DIFICULTAD INGRESADO INCORRECTO"<<endl;
        return false;
    }
    else reg.setNivel(nivel);

    system("cls");

    ///4. SE MODIFICA EL REGISTRO
    if(modificarRegistro(reg,posicion) == true) encontrado = true;
    else encontrado = false;

    return encontrado;
}

///OP5
bool ArchivoTipoDeporte::bajaLogica(){
    TipoDeporte reg;
    int id;
    cout<<"INGRESAR EL ID DEL EQUIPO A DAR DE BAJA: ";
    cin>>id;
    ///1.VER SI EL REGISTRO SI EL REGISTRO EXISTE EN EL ARCHIVO
    int posicion = buscarID(id);
    ///2.SI NO EXISTE, INFORMARLO Y TERMINAR LA FUNCION.
    if(posicion == -1){
        cout<<"NO EXISTE UN REGISTRO CON ESE ID"<<endl;
        return false;
    }
    ///3.SI EXISTE, LEER EL REGISTRO
    reg = leerRegistro(posicion);
    ///4.SI EL ESTADO YA ESTA EN FALSE NOTIFICAR
    if(reg.getEstado() == false){
        cout<< "EL ID YA SE ENCUENTRA DADO DE BAJA" <<endl;
        return false;
    }
    ///5.CAMBIAR EL VALOR DE LA PROPIEDAD "estado"
    reg.setEstado(false);
    ///6.SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO
    bool modificado = modificarRegistro(reg, posicion);
    return modificado;
}


#endif // ARCHIVOTIPODEPORTE_H_INCLUDED
