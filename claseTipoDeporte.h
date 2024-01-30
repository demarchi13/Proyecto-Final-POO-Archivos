#ifndef CLASETIPODEPORTE_H_INCLUDED
#define CLASETIPODEPORTE_H_INCLUDED

class TipoDeporte{
    private:
        int _idEquipo;
        char _nombre[30];
        int _nivel;
        bool _estado;
    public:
        ///SETTERS
        void setID(int id){_idEquipo = id;}
        void setNombre(const char* nom){strcpy(_nombre,nom);}
        void setNivel(int niv){_nivel = niv;}
        void setEstado(bool e){_estado = e;}

        ///GETTERS
        int getID(){return _idEquipo;}
        const char* getNombre(){return _nombre;}
        int getNivel(){return _nivel;}
        bool getEstado(){return _estado;}

        bool cargar();
        void mostrar();

};

bool TipoDeporte::cargar(){
    bool aux = true;
    cout<<"INGRESE NOMBRE:"<<endl;
    cargarCadena(_nombre,30);
    cout<<"INGRESE NIVEL:"<<endl;
    int nivel;
    cin>>nivel;
    if(nivel < 1 || nivel > 8 ){
        cout<< "EL NUMERO DE NIVEL INGRESADO ES INVALIDO"<<endl;
        return false;
    }
    setNivel(nivel);
    setEstado(true);
    return aux;
}

void TipoDeporte::mostrar(){
    if(_estado==true){
        cout<<"ID DE TIPO DE DEPORTE: ";
        cout<<_idEquipo<<endl;
        cout<<"NOMBRE: ";
        cout<<_nombre<<endl;
        cout<<"NIVEL: ";
        cout<<_nivel<<endl;
    }
}

#endif // CLASETIPODEPORTE_H_INCLUDED
