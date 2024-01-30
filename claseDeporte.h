#ifndef CLASEDEPORTE_H_INCLUDED
#define CLASEDEPORTE_H_INCLUDED

class Deporte{
    private:
        int _IDdeporte;
        char _nombre[30];
        int _tipoDeporte;
        int _anioOrigen;
        bool _estado;

        int _contadorID;
    public:
        bool cargar();
        void mostrar();
        ///SETTERS
        void setID(int id){_IDdeporte = id;}
        void setNombre(const char* nom){strcpy(_nombre,nom);}
        void setTipoDeporte(int tipo){
            if(tipo >= 1 && tipo <= 21) _tipoDeporte = tipo;
            else _tipoDeporte = -1;}
        void setAnioOrigen (int anio){
            if(anio >= 1800 && anio <= 2023) _anioOrigen = anio;
            else _anioOrigen = -1;}
        void setEstado (bool status){_estado = status;}
        void setContadorID(int contador){_contadorID = contador;}

        ///GETTERS
        int getID(){return _IDdeporte;}
        const char* getNombre(){return _nombre;}
        int getTipoDeporte(){return _tipoDeporte;}
        int getAnioOrigen(){return _anioOrigen;}
        bool getEstado(){return _estado;}
        int getContadorID(){return _contadorID;}

};

bool Deporte::cargar(){
    bool aux = true;
    cout<<"INGRESE NOMBRE: ";
    cargarCadena(_nombre,30);
    cout<<"INGRESE TIPO DE DEPORTE: ";
    int tipoDeporte;
    cin>>tipoDeporte;
    if(tipoDeporte <1 || tipoDeporte >21){
        cout<<"NUMERO DE DEPORTE INVALIDO"<<endl;
        return false;
    }
    setTipoDeporte(tipoDeporte);
    cout<<"INGRESE ANIO DE ORIGEN: ";
    int anio;
    cin>>anio;
    if(anio <1800 || anio >2023){
        cout<< "EL ANIO INGRESADO ES INVALIDO"<<endl;
        return false;
    }
    setAnioOrigen(anio);
    setEstado(true);
    return aux;
}

void Deporte::mostrar(){
    if(_estado == true){
        cout<<"ID DEL DEPORTE: ";
        cout<<_IDdeporte<<endl;
        cout<<"NOMBRE: ";
        cout<<_nombre<<endl;
        cout<<"TIPO DE DEPORTE: ";
        cout<<_tipoDeporte<<endl;
        cout<<"ANIO DE ORIGEN: ";
        cout<<_anioOrigen<<endl;
    }
}

#endif // CLASEDEPORTE_H_INCLUDED
