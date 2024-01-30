#ifndef CLASEJUGADOR_H_INCLUDED
#define CLASEJUGADOR_H_INCLUDED

class Jugador{
    private:
        int _dni;
        char _nombre[30];
        char _apellido[30];
        char _email[30];
        char _telefono[30];
        int _claustro;
        int _deporte;
        int _numeroEquipo;
        Fecha _fechaInscripcion;
        float _matricula;
        bool _estado;
    public:

        bool cargarDatosJugador();
        void mostrarDatosJugador();

        ///SETTERS
        void setDNI(int dni){_dni=dni;}
        void setNombre(const char* nom){strcpy(_nombre,nom);}
        void setApellido(const char* ape){strcpy(_apellido,ape);}
        void setEmail(const char* mail){strcpy(_email,mail);}
        void setTelefono(const char* tel){strcpy(_telefono,tel);}

        void setClaustro(int claus){_claustro=claus;}

        void setDeporte(int deport){_deporte=deport;}

        void setNumeroEquipo (int numEquipo){_numeroEquipo=numEquipo;}

        void setMatricula (float mat){_matricula=mat;}

        void setEstado (bool estado){_estado=estado;}

        ///SETTERS FECHA
        void setFechaInscripcion(Fecha fecha){_fechaInscripcion=fecha;}
        void setDiaInscripcion(int dia){_fechaInscripcion.setDia(dia);}
        void setMesInscripcion(int mes){_fechaInscripcion.setMes(mes);}
        void setAnioInscripcion(int anio){_fechaInscripcion.setAnio(anio);}

        ///GETTERS
        int getDNI(){return _dni;}
        const char* getNombre(){return _nombre;}
        const char* getApellido(){return _apellido;}
        const char* getEmail(){return _email;}
        const char* getTelefono(){return _telefono;}
        int getClaustro(){return _claustro;}
        int getDeporte(){return _deporte;}
        int getNumeroEquipo(){return _numeroEquipo;}
        float getMatricula(){return _matricula;}
        bool getEstado(){return _estado;}

        ///GETTERS FECHA
        Fecha getFechaInscripcion(){return _fechaInscripcion;}
        int getDiaInscripcion(){return _fechaInscripcion.getDia();}
        int getAnioInscripcion(){return _fechaInscripcion.getAnio();}
        int getMesInscripcion(){return _fechaInscripcion.getMes();}
};

bool Jugador::cargarDatosJugador(){
    bool aux = true;
    cout<<"INGRESE NOMBRE:"<<endl;
    cargarCadena(_nombre,30);
    cout<<"INGRESE APELLIDO:"<<endl;
    cargarCadena(_apellido,30);
    cout<<"INGRESE EMAIL:"<<endl;
    cargarCadena(_email,30);
    cout<<"INGRESE TELEFONO:"<<endl;
    cargarCadena(_telefono,30);
    cout<<"INGRESE CLAUSTRO:"<<endl;
    int claustro;
    cin>>claustro;
    if(claustro < 0 || claustro > 5){
        cout<< "EL NUMERO DE CLAUSTRO ES INVALIDO"<<endl;
        cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        return false;
    }
    setClaustro(claustro);
    cout<<"INGRESE ID DEPORTE:"<<endl;
    cin>>_deporte;
    cout<<"INGRESE NUMERO DE EQUIPO:"<<endl;
    cin>>_numeroEquipo;
    cout<<"INGRESE FECHA DE INSCRIPCION:"<<endl;
    _fechaInscripcion.CargarFecha();
    cout<<"INGRESE MATRICULA:"<<endl;
    float matricula;
    cin>>matricula;
    if(matricula < 0){
        cout<<"NUMERO DE MATRICULA INVALIDO"<<endl;
        cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        return false;
    }
    setMatricula(matricula);
    setEstado(true);
    return aux;
}

void Jugador::mostrarDatosJugador(){
    if(_estado==true){
        cout<<"DOCUMENTO: ";
        cout<<_dni<<endl;
        cout<<"NOMBRE: ";
        cout<<_nombre<<endl;
        cout<<"APELLIDO: ";
        cout<<_apellido<<endl;
        cout<<"EMAIL: ";
        cout<<_email<<endl;
        cout<<"FECHA DE INSCRIPCION: ";
        _fechaInscripcion.MostrarFecha();
        cout<<"TELEFONO: ";
        cout<<_telefono<<endl;
        cout<<"CLAUSTRO: ";
        cout<<_claustro<<endl;
        cout<<"ID DEPORTE: ";
        cout<<_deporte<<endl;
        cout<<"NUMERO DE EQUIPO ";
        cout<<_numeroEquipo<<endl;
        cout<<"MATRICULA: ";
        cout<<_matricula<<endl;
    }
}

#endif // CLASEJUGADOR_H_INCLUDED
