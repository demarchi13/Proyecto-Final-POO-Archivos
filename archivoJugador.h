#ifndef ARCHIVOJUGADOR_H_INCLUDED
#define ARCHIVOJUGADOR_H_INCLUDED

class ArchivoJugador{
private:
    char nombre[30];
public:
    ArchivoJugador(const char *n){
        strcpy(nombre,n);
    }
    int contarRegistros(); ///CANTIDAD DE REGISTROS
    int buscarDNI(int dni); ///POSICION DEL REGISTRO
    int buscarNumEquipo(int numEquipo);
    Jugador leerRegistro(int posicion); ///LEER
    int grabarRegistro(Jugador reg); ///ESCRIBIR
    bool modificarRegistro(Jugador reg, int pos); ///MODIFICAR REGISTRO
    bool modificarFechaInscripcion();
    bool agregarRegistroJugador();
    void listarRegistroDNI();
    bool listarRegistrosJugadores();
    bool bajaLogica();

    bool modificarMatricula();
};

int ArchivoJugador::contarRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL) return -1;
    fseek(p,0,SEEK_END); ///POSICIONA EL PUNTERO AL FINAL DEL ARCHIVO
    int tam=ftell(p); ///OBTENEMOS EL TAMAÑOS TOTAL DEL ARCHIVO
    fclose(p);
    return tam/sizeof(Jugador); ///DIVIDE EL TAMAÑO TOTAL DEL ARCHIVO ENTRE EL TAMAÑO EN BYTES DE UN REGISTRO DEL TIPO "JUGADOR"
}

int ArchivoJugador::buscarDNI(int dni){
    Jugador reg;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL) exit(-5);
    int posRegistro=0;
    while(fread(&reg,sizeof(Jugador),1,p)==1){
        if(reg.getDNI()==dni){
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

int ArchivoJugador::buscarNumEquipo(int numEquipo){
    Jugador reg;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL) exit(-5);
    int posRegistro=0;
    while(fread(&reg,sizeof(Jugador),1,p)==1){
        if(reg.getNumeroEquipo()==numEquipo){
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

Jugador ArchivoJugador::leerRegistro(int posicion){
    FILE *p;
    Jugador reg;
    p=fopen(nombre,"rb");
    if(p==NULL) exit(-4);
    fseek(p, posicion * sizeof(reg),0);
    fread(&reg, sizeof(reg), 1, p);
    fclose(p);
    return reg;
}

int ArchivoJugador::grabarRegistro(Jugador reg){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL) return -3;
    int escribio=fwrite(&reg, sizeof(Jugador), 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoJugador::modificarRegistro(Jugador reg, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof reg*pos,0);
    bool escribio = fwrite(&reg,sizeof(Jugador),1,p);
    fclose(p);
    return escribio;
}

///OP1
bool ArchivoJugador::agregarRegistroJugador(){
    FILE *p;
    p = fopen("jugadores.dat" , "ab");
    if(p == nullptr){
        cout<< "ERROR DE ARCHIVO. NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        return false;
    }
    fclose(p);

	///INGRESA NUMERO DE DNI
	Jugador reg;
	int dni;
	cout<< "INGRESE NUMERO DE DNI: " <<endl;
	cin>>dni;

	///BUSCA Y VERIFICA SI EXISTE EL DNI PARA OBTENER LA POSICION
    int posicion = buscarDNI(dni);
    if(posicion != -1) { ///SI ES DISTINTO DE -1 QUIERE DECIR QUE EXISTE, INFORMALO.
        reg = leerRegistro(posicion); ///LEER EL REGISTRO EXISTENTE
        if(reg.getEstado() == false)  cout<<"EL DNI INGRESADO YA ESTA REGISTADO Y SE ENCUENTRA DADO DE BAJA"<<endl;
        else cout<< "EL DNI INGRESADO YA EXISTE"<<endl;
        return false;
    }

    ///CONFIGURAR EL NUMERO DE DNI Y CARGAR EL RESTO DE LOS DATOS
    reg.setDNI(dni);
    if(reg.cargarDatosJugador() == true){

        ///COMPROBAR SI EL ID EXISTE EN ARCHIVO DEPORTES
        ArchivoEquipo archiEquipo("equipos.dat");
        Equipo auxEquipo;
        int posicionEquipo = archiEquipo.buscarNumEquipo(reg.getNumeroEquipo());
        auxEquipo = archiEquipo.leerRegistro(posicionEquipo);

         ///COMPROBAR SI EL NUMERO DE EQUIPO EN EL ARCHIVO JUGADORES COINCIDE CON EL ID EN EL ARCHIVO EQUIPOS
        ArchivoDeporte archiDeporte("deportes.dat");
        Deporte auxDeporte;
        int posicionID = archiDeporte.buscarID(reg.getDeporte());
        auxDeporte = archiDeporte.leerRegistro(posicionID);

        if(posicionID != -1 && posicionEquipo != -1){ ///SI ES DISTINTO DE -1, EL ID EXISTE.
            if(auxDeporte.getEstado() == true && auxEquipo.getEstado() == true){
                ///AGREGAR REGISTRO AL ARCHIVO
                int escribio = grabarRegistro(reg);
                if(escribio == 1){
                    cout<< "REGISTRO AGREGADO" <<endl;
                    return true;
                }
            }
            else{
                if(auxDeporte.getEstado() == false){
                    cout<<"ID DE DEPORTE DADO DE BAJA"<<endl;
                    cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                    if(auxEquipo.getEstado() == false){
                        cout<<"ID DE EQUIPO DADO DE BAJA"<<endl;
                        cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                        return false;
                    }
                }
                cout<<"ID DE EQUIPO DADO DE BAJA"<<endl;
                cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                return false;
            }
        }
        if(posicionID == -1){
            cout<<"EL ID DE DEPORTE NO EXISTE"<<endl;
            cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        }
        if(posicionEquipo == -1){
            cout<<"EL ID DE EQUIPO NO EXISTE"<<endl;
            cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        }
    }


    return false;
}


///OP2
void ArchivoJugador::listarRegistroDNI(){
    Jugador reg;
    int dni;
    cout<<"INGRESE DNI"<<endl;
    cin>>dni;
    int posicion = buscarDNI(dni);
    if(posicion != -1){
        system("cls");
        reg = leerRegistro(posicion);
        if(reg.getEstado() == true) {
            cout<<"***DNI REGISTRADO***"<<endl;
            cout<<endl;
            reg.mostrarDatosJugador();
            return;
        }
        cout << "EL DNI SE ENCUENTRA REGISTRADO PERO ESTA DADO DE BAJA" <<endl;
        return;
    }
    else {
        system("cls");
        cout<<"EL DNI NO SE ENCUENTRA REGISTRADO"<<endl;
        return;
    }
}

///OP3
bool ArchivoJugador::listarRegistrosJugadores(){
    Jugador reg;
    FILE *p=fopen("jugadores.dat", "rb");
    bool encontroRegistro = false;
    if(p==NULL){
        cout<< "ERROR DE ARCHIVO: NO SE PUDO MOSTRAR." <<endl;
        return false;
    }
    while(fread(&reg, sizeof(Jugador),1,p)==1){
        if(reg.getEstado()==true){
            encontroRegistro = true;
            reg.mostrarDatosJugador();
            cout<<endl;
        }
    }
    fclose(p);
    return encontroRegistro;
}

///OP4
bool ArchivoJugador::modificarFechaInscripcion(){
    int dni;
    bool encontrado = false;
    cout<<"INGRESE DNI"<<endl;
    cin>>dni;

    ///1.BUSCA EL DNI PARA OBTENER LA POSICION
    int posicion=buscarDNI(dni);
    if(posicion == -1) {
        cout<<"EL DNI NO SE ENCONTRO EN EL ARCHIVO"<<endl;
        return false;
    }

    ///2.SE VERIFICA SI EL DNI EXISTE EN EL ARCHIVO Y SI EL JUGADOR ESTA ACTIVO
    Jugador reg = leerRegistro(posicion);
    if(reg.getEstado()==false){
        cout<<"EL JUGADOR NO ESTA ACTIVO"<<endl;
        return false;
    }

    ///3. SE OBTIENE LA FECHA ACTUAL Y SE ACTUALIZA EN EL REGISTRO
    Fecha fecha;
    fecha.CargarFecha();
    reg.setDiaInscripcion(fecha.getDia());
    reg.setMesInscripcion(fecha.getMes());
    reg.setAnioInscripcion(fecha.getAnio());

    ///4. SE MODIFICA EL REGISTRO
    if(modificarRegistro(reg,posicion)==true) encontrado = true;
    else encontrado = false;

    return encontrado;
}

///OP5
bool ArchivoJugador::bajaLogica(){
    Jugador reg;
    int dni;
    cout<<"INGRESAR EL DNI DEL JUGADOR A DAR DE BAJA: ";
    cin>>dni;
    ///1.VER SI EL REGISTRO SI EL REGISTRO EXISTE EN EL ARCHIVO
    int posicion=buscarDNI(dni);
    ///2.SI NO EXISTE, INFORMARLO Y TERMINAR LA FUNCION.
    if(posicion==-1){
        cout<<"NO EXISTE UN REGISTRO CON ESE DNI"<<endl;
        return false;
    }
    ///3.SI EXISTE, LEER EL REGISTRO
    reg = leerRegistro(posicion);
    ///4.SI EL ESTADO YA ESTA EN FALSE NOTIFICAR
    if(reg.getEstado() == false){
        cout<< "EL DNI YA SE ENCUENTRA DADO DE BAJA" <<endl;
        return false;
    }
    ///5.CAMBIAR EL VALOR DE LA PROPIEDAD "estado"
    reg.setEstado(false);
    ///6.SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO
    bool modificado=modificarRegistro(reg, posicion);
    return modificado;
}


#endif // ARCHIVOJUGADOR_H_INCLUDED
