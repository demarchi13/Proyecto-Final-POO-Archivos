#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

class Equipo10{
    private:
        int _idEquipo;
        char _nombre[30];
        int _cantidad;
        bool _estado;
    public:
        ///SETTERS
        void setID(int id){_idEquipo = id;}
        void setNombre(const char* nom){strcpy(_nombre,nom);}
        void setCantidad(int cant){_cantidad = cant;}
        void setEstado(bool e){_estado = e;}

        ///GETTERS
        int getID(){return _idEquipo;}
        const char* getNombre(){return _nombre;}
        int getCantidad(){return _cantidad;}
        bool getEstado(){return _estado;}

        void mostrar(){
            if(_estado==true){
                cout<<"ID DEL EQUIPO: ";
                cout<<_idEquipo<<endl;
                cout<<"NOMBRE: ";
                cout<<_nombre<<endl;
                cout<<"CANTIDAD DE INTEGRANTES: ";
                cout<<_cantidad<<endl;
            }
        }
};

class ArchivoEquipo10{
private:
    char nombre[30];
public:
    ArchivoEquipo10(const char *n){
        strcpy(nombre,n);
    }
    int contarRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL) return -1;
    fseek(p,0,SEEK_END);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(Equipo10);
    }

    Equipo10 leerRegistro(int posicion){
    FILE *p;
    Equipo10 reg;
    p=fopen(nombre,"rb");
    if(p==NULL) exit(-4);
    fseek(p, posicion * sizeof(reg),0);
    fread(&reg, sizeof(reg), 1, p);
    fclose(p);
    return reg;
}

    int grabarRegistro(Equipo10 reg){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL) return -3;
    int escribio=fwrite(&reg, sizeof(Equipo10), 1, p);
    fclose(p);
    return escribio;
    }
};

///Generar un archivo con los equipos que tengan como máximo 10 integrantes.
///Cada registro debe tener el ID y el nombre del equipo, y la cantidad de integrantes del equipo.
void punto1(){
    ArchivoEquipo archiE("equipos.dat");
    Equipo auxEq;
    int cantEq = archiE.contarRegistros();

    ArchivoJugador archiJ("jugadores.dat");
    Jugador jug;
    int cantJug = archiJ.contarRegistros();

    ArchivoEquipo10 archi10("equipos10.dat");
    Equipo10 aux10;

    int con;
    for(int j=0; j<cantEq; j++){
        con = 0;
        auxEq = archiE.leerRegistro(j);
        for(int i=0; i<cantJug; i++){
            jug = archiJ.leerRegistro(i);
            if(jug.getNumeroEquipo() == auxEq.getID()){
                con++;
            }
        }
        if(con <= 10){
            aux10.setID(auxEq.getID());
            aux10.setNombre(auxEq.getNombre());
            aux10.setCantidad(con);
            aux10.setEstado(true);

            if(archi10.grabarRegistro(aux10)){
                cout << "REGISTRO GRABADO" << endl;
            }
        }
    }
}

///Informar el/los deporte/s sin jugadores
void punto2(){
    ArchivoDeporte archiDep("deportes.dat");
    Deporte dep;
    int cantDep = archiDep.contarRegistros();

    ArchivoJugador archiJ("jugadores.dat");
    Jugador jug;
    int cantJug = archiJ.contarRegistros();

    bool tieneJugadores;
    for(int i=0; i<cantDep; i++){
        tieneJugadores = false;
        dep = archiDep.leerRegistro(i);
        for(int j=0; j<cantJug; j++){
            jug = archiJ.leerRegistro(j);
            if(dep.getID() == jug.getDeporte()){
                tieneJugadores = true;
            }
        }
    if(tieneJugadores == false){
        cout << "EL DEPORTE "  << dep.getNombre() << " NO TIENE JUGADORES" << endl;
    }
    }///FIN FOR
}

///Hacer una función para generar un vector dinámico para cargar los registros
///del archivo generado en el punto 1. Listar el vector.
void punto3(){
    ArchivoEquipo10 archi10("equipos10.dat");
    Equipo10 aux10;
    int tam = archi10.contarRegistros();
    if(tam == -1){
        cout << "NO HAY REGISTROS CARGADOS" << endl;
        return;
    }

    Equipo10 *p10;
    p10 = new Equipo10[tam];
    if(p10 == nullptr){
        cout << "ERROR DE MEMORIA" << endl;
        return;
    }

    for(int i=0; i<tam; i++){
        aux10 = archi10.leerRegistro(i);
        p10[i] = aux10;
        p10[i].mostrar();
        cout << endl;
    }
    delete p10;
}

#endif // REPORTES_H_INCLUDED
