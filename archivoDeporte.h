#ifndef ARCHIVODEPORTE_H_INCLUDED
#define ARCHIVODEPORTE_H_INCLUDED

class ArchivoDeporte{
private:
    char nombre[30];
public:
    ArchivoDeporte(const char *n){
        strcpy(nombre,n);
    }
    int contarRegistros(); ///CANTIDAD DE REGISTROS
    int buscarID(int id); ///POSICION DEL REGISTRO
    Deporte leerRegistro(int posicion); ///LEER
    int grabarRegistro(Deporte reg); ///ESCRIBIR
    bool modificarRegistro(Deporte reg, int pos); ///MODIFICAR REGISTRO
    bool modificarAnioOrigen();
    bool agregarRegistroDeporte();
    void listarRegistroID();
    bool listarRegistrosDeportes();
    bool bajaLogica();
};

int ArchivoDeporte::contarRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO. NO SE PUDIERON CONTAR LOS REGISTROS"<<endl;
        return -5;
    }
    fseek(p,0,SEEK_END); ///POSICIONA EL PUNTERO AL FINAL DEL ARCHIVO
    int tam=ftell(p); ///OBTENEMOS EL TAMAÑOS TOTAL DEL ARCHIVO
    fclose(p);
    return tam/sizeof(Deporte); ///DIVIDE EL TAMAÑO TOTAL DEL ARCHIVO ENTRE EL TAMAÑO EN BYTES DE UN REGISTRO DEL TIPO "JUGADOR"
}

int ArchivoDeporte::buscarID(int id){
    Deporte reg;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO. NO SE PUDO BUSCAR EL ID"<<endl;
        return -5;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(Deporte),1,p)==1){
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

Deporte ArchivoDeporte::leerRegistro(int posicion){
    FILE *p;
    Deporte reg;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO. NO SE PUDO LEER EL REGISTRO"<<endl;
        return reg;
    }
    fseek(p, posicion * sizeof(reg),0);
    fread(&reg, sizeof(reg), 1, p);
    fclose(p);
    return reg;
}

int ArchivoDeporte::grabarRegistro(Deporte reg){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO. NO SE PUDO GRABAR EL REGISTRO"<<endl;
        return -5;
    }
    int escribio=fwrite(&reg, sizeof(Deporte), 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoDeporte::modificarRegistro(Deporte reg, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO. NO SE PUDO MODIFICAR EL REGISTRO"<<endl;
        return false;
    }
    fseek(p,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(Deporte),1,p);
    fclose(p);
    return escribio;
}

///OP1
bool ArchivoDeporte::agregarRegistroDeporte(){
    FILE *p;
    p = fopen("deportes.dat","ab");
    if(p == nullptr){
        cout<< "ERROR DE ARCHIVO. NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        return false;
    }
    Deporte reg;
    ArchivoDeporte archi("deportes.dat");
    int cantReg = archi.contarRegistros();

    ///ASIGNA EL ID Y SE CARGAN EL RESTO DE DATOS
    reg.setID(cantReg+1);

    if(reg.cargar() == true){
        ///COMPROBAR SI EL TIPO DE DEPORTE EN EL "ARCHIVO DEPORTE" EXISTE EN EL ARCHIVO "TIPO DE DEPORTES"
        ArchivoTipoDeporte archiTipo("TipodeDeporte.dat");
        TipoDeporte auxTipo;
        int posTipo = archiTipo.buscarID(reg.getTipoDeporte());
        auxTipo = archiTipo.leerRegistro(posTipo);

        if(posTipo != -1){ ///SI ES DISTINTO DE -1, EL ID EXISTE.
            if(auxTipo.getEstado() == true){
                ///AGREGAR REGISTRO AL ARCHIVO
                int escribio = grabarRegistro(reg);
                if(escribio == 1){
                    cout<< "REGISTRO AGREGADO" <<endl;
                    fclose(p);
                    return true;
                }
            }
            else{
                cout<<"TIPO DE DEPORTE DADO DE BAJA"<<endl;
                fclose(p);
                return false;
            }
        }
	}
    cout<<"EL TIPO DE DEPORTE NO EXISTE"<<endl;
    fclose(p);
    return false;
}

///OP2
void ArchivoDeporte::listarRegistroID(){
    Deporte reg;
    int id;
    cout<<"INGRESE ID"<<endl;
    cin>>id;
    int posicion = buscarID(id);
    if(posicion != -1){
        reg = leerRegistro(posicion);
        if(reg.getEstado() == true){
            system("cls");
            cout<<"***ID DE DEPORTE ENCONTRADO***"<<endl;
            cout<<endl;
            reg.mostrar();
            return;
        }
        cout << "EL ID SE ENCUENTRA REGISTRADO PERO ESTA DADO DE BAJA" <<endl;
        return;
    }
    cout <<"EL ID NO SE ENCUENTRA REGISTRADO"<<endl;
}

///OP3
bool ArchivoDeporte::listarRegistrosDeportes(){
    Deporte reg;
    FILE *p=fopen("deportes.dat", "rb");
    bool encontroRegistro = false;
    if(p==NULL){
        return false;
    }
    while(fread(&reg, sizeof(Deporte),1,p)==1){
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
bool ArchivoDeporte::modificarAnioOrigen(){
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
    Deporte reg = leerRegistro(posicion);
    if(reg.getEstado()==false){
        cout<<"EL DEPORTE NO ESTA ACTIVO"<<endl;
        return false;
    }

    ///3. SE CARGO EL AÑO DE ORIGEN ACTUAL Y SE ACTUALIZA EN EL REGISTRO
    int anio;
    cout<<"INGRESE NUEVO ANIO DE ORIGEN"<<endl;
    cin>>anio;
    if(anio < 1800 || anio > 2023){
        system("cls");
        cout<<"ANIO INVALIDO"<<endl;
        return false;
    }
    else reg.setAnioOrigen(anio);

    system("cls");

    ///4. SE MODIFICA EL REGISTRO
    if(modificarRegistro(reg,posicion) == true) encontrado = true;
    else encontrado = false;

    return encontrado;
}

///OP5
bool ArchivoDeporte::bajaLogica(){
    Deporte reg;
    int id;
    cout<<"INGRESAR EL ID DEL DEPORTE A DAR DE BAJA: ";
    cin>>id;
    ///1.VER SI EL REGISTRO EXISTE EN EL ARCHIVO
    int posiscion = buscarID(id);
    ///2.SI NO EXISTE, INFORMARLO Y TERMINAR LA FUNCION.
    if(posiscion == -1){
        cout<<"NO EXISTE UN REGISTRO CON ESE NUMERO DE ID"<<endl;
        return false;
    }
    ///3.SI EXISTE, LEER EL REGISTRO
    reg = leerRegistro(posiscion);
    ///4.SI EL ESTADO YA ESTA EN FALSE NOTIFICAR
    if(reg.getEstado() == false){
        cout<< "EL ID YA SE ENCUENTRA DADO DE BAJA" <<endl;
        return false;
    }
    ///5.CAMBIAR EL VALOR DE LA PROPIEDAD "estado"
    reg.setEstado(false);
    ///6.SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO
    bool modificado = modificarRegistro(reg, posiscion);
    return modificado;
}

#endif // ARCHIVODEPORTE_H_INCLUDED
