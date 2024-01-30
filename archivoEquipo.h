#ifndef ARCHIVOEQUIPO_H_INCLUDED
#define ARCHIVOEQUIPO_H_INCLUDED

class ArchivoEquipo{
private:
    char nombre[30];
public:
    ArchivoEquipo(const char *n){
        strcpy(nombre,n);
    }
    int contarRegistros(); ///CANTIDAD DE REGISTROS
    int buscarID(int dni); ///POSICION DEL REGISTRO
    int buscarNumEquipo(int numEquipo);
    Equipo leerRegistro(int posicion); ///LEER
    int grabarRegistro(Equipo reg); ///ESCRIBIR
    bool modificarRegistro(Equipo reg, int pos); ///MODIFICAR REGISTRO
    bool modificarNombre();
    bool agregarRegistro();
    void listarRegistroID();
    bool listarRegistros();
    bool bajaLogica();

    bool modificarMatricula();
};

int ArchivoEquipo::contarRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL) return -1;
    fseek(p,0,SEEK_END); ///POSICIONA EL PUNTERO AL FINAL DEL ARCHIVO
    int tam=ftell(p); ///OBTENEMOS EL TAMAÑOS TOTAL DEL ARCHIVO
    fclose(p);
    return tam/sizeof(Equipo); ///DIVIDE EL TAMAÑO TOTAL DEL ARCHIVO ENTRE EL TAMAÑO EN BYTES DE UN REGISTRO DEL TIPO "JUGADOR"
}

int ArchivoEquipo::buscarID(int id){
    Equipo reg;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p == NULL){
        cout<<"ERROR DE ARCHIVO. NO SE PUDO BUSCAR EL ID"<<endl;
        return -5;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(Equipo),1,p)==1){
        if(reg.getID()==id){
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

int ArchivoEquipo::buscarNumEquipo(int numEquipo){
    Equipo reg;

    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL) exit(-5);
    int posRegistro=0;
    while(fread(&reg,sizeof(Equipo),1,p)==1){
        if(reg.getID()==numEquipo){
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

Equipo ArchivoEquipo::leerRegistro(int posicion){
    FILE *p;
    Equipo reg;
    p=fopen(nombre,"rb");
    if(p==NULL) exit(-4);
    fseek(p, posicion * sizeof(reg),0);
    fread(&reg, sizeof(reg), 1, p);
    fclose(p);
    return reg;
}

int ArchivoEquipo::grabarRegistro(Equipo reg){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL) return -3;
    int escribio=fwrite(&reg, sizeof(Equipo), 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoEquipo::modificarRegistro(Equipo reg, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof reg*pos,0);
    bool escribio = fwrite(&reg,sizeof(Equipo),1,p);
    fclose(p);
    return escribio;
}

///OP1
bool ArchivoEquipo::agregarRegistro(){
    FILE *p;
    p = fopen("equipos.dat","ab");
    if(p == nullptr){
        cout<< "ERROR DE ARCHIVO. NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        return false;
    }
    Equipo reg;
    ArchivoEquipo archi("equipos.dat");
    int cantReg = contarRegistros();

    ///ASIGNA EL ID Y SE CARGAN EL RESTO DE DATOS
    reg.setID(cantReg+1);
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
void ArchivoEquipo::listarRegistroID(){
    Equipo reg;
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
bool ArchivoEquipo::listarRegistros(){
    Equipo reg;
    FILE *p = fopen("equipos.dat", "rb");
    bool encontroRegistro = false;
    if(p == NULL){
        cout<< "ERROR DE ARCHIVO: NO SE PUDO MOSTRAR." <<endl;
        return false;
    }
    while(fread(&reg, sizeof(Equipo),1,p)==1){
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
bool ArchivoEquipo::modificarNombre(){
    int id;
    bool encontrado = false;
    cout<<"INGRESE ID"<<endl;
    cin>>id;

    ///1.BUSCA EL ID PARA OBTENER LA POSICION
    int posicion = buscarID(id);
    if(posicion == -1) {
        cout<<"EL ID DE EQUIPO NO SE ENCONTRO EN EL ARCHIVO"<<endl;
        return false;
    }

    ///2.SE VERIFICA SI EL ID EXISTE EN EL ARCHIVO Y SI EL EQUIPO ESTA ACTIVO
    Equipo reg = leerRegistro(posicion);
    if(reg.getEstado() == false){
        cout<<"EL EQUIPO NO ESTA ACTIVO"<<endl;
        return false;
    }

    ///3. CARGAR EL NUEVO NOMBRE Y ACTUALIZAR EN EL REGISTRO
    char nombre[30];
    cout<< "INGRESE NUEVO NOMBRE" <<endl;
    cin>>nombre;
    reg.setNombre(nombre);

    ///4. SE MODIFICA EL REGISTRO
    if(modificarRegistro(reg,posicion) == true) encontrado = true;
    else encontrado = false;

    return encontrado;
}

///OP5
bool ArchivoEquipo::bajaLogica(){
    Equipo reg;
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


#endif // ARCHIVOEQUIPO_H_INCLUDED
