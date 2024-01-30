#ifndef CLASE_FECHA_H_INCLUDED
#define CLASE_FECHA_H_INCLUDED

using namespace std;

class Fecha{
private:
    int dia,mes,anio;
public:
    ///CONSTRUCTOR
    Fecha(int d, int m, int y){
        setDia(d);
        setMes(m);
        setAnio(y);
    }
    Fecha (){
        time_t tiempo = time(nullptr);
        tm* fecha = localtime(&tiempo);

        setDia(fecha->tm_mday);
        setMes(fecha->tm_mon+1);
        setAnio(fecha->tm_year+1900);
    }

    void CargarFecha();
    void MostrarFecha();

    ///SETTERS
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int y){anio=y;}

    ///GETTERS
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
};

/*void Fecha::CargarFecha(){
    int d,m,y;
    cout<<"DIA: ";
    cin>>d;
    setDia(d);
    cout<<"MES: ";
    cin>>m;
    setMes(m);
    cout<<"ANIO: ";
    cin>>y;
    setAnio(y);
}*/

void Fecha::CargarFecha() {
    int d, m, y;
    bool fechaValida = false;

    do {
        cout << "DIA: ";
        cin >> d;
        cout << "MES: ";
        cin >> m;
        cout << "ANIO: ";
        cin >> y;

        ///VALIDACION DE LA FECHA
        if (d >= 1 && d <= 31 && m >= 1 && m <= 12 && y >= 1900) {
            ///VERIFICAR SI LA FECHA INGRESADA ES ANTERIOR O IGUAL A LA FECHA ACTUAL
            Fecha fechaActual;
            if (y < fechaActual.getAnio() ||
                (y == fechaActual.getAnio() && m < fechaActual.getMes()) ||
                (y == fechaActual.getAnio() && m == fechaActual.getMes() && d <= fechaActual.getDia())) {
                ///FECHA VALIDA
                setDia(d);
                setMes(m);
                setAnio(y);
                fechaValida = true;
            } else {
                cout << "LA FECHA INGRESADA DEBE SER ANTERIOR O IGUAL A LA FECHA ACTUAL." << endl;
            }
        } else {
            cout << "FECHA NO VALIDA. INGRESA UNA FECHA VALIDA." << endl;
        }
    } while (!fechaValida);
}


void Fecha::MostrarFecha(){
	cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

#endif // CLASE_FECHA_H_INCLUDED
