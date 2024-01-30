///INTEGRANTES:
///LUCAS ALEJANDRO DE MARCHI
///LUCAS EZEQUIEL ARTURO NUÑEZ
///JUAN CARLOS DE GUAYANA MUÑOZ SALAS

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
using namespace std;

#include "cargarCadena.h"
#include "clase_fecha.h"
#include "claseTipoDeporte.h"
#include "archivoTipoDeporte.h"
#include "submenuTipoDeporte.h"
#include "claseEquipo.h"
#include "archivoEquipo.h"
#include "submenuEquipos.h"
#include "claseJugador.h"
#include "claseDeporte.h"
#include "archivoDeporte.h"
#include "subMenuDeportes.h"
#include "archivoJugador.h"
#include "submenuJugadores.h"
#include "reportes.h"
#include "submenuReportes.h"
#include "configuraciones.h"
#include "subMenuConfiguraciones.h"


int main()
{
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
        cout<<"1) MENU JUGADORES"<<endl;
        cout<<"2) MENU DEPORTES"<<endl;
        cout<<"3) MENU EQUIPOS"<<endl;
        cout<<"4) MENU TIPO DE DEPORTE"<<endl;
        cout<<"5) REPORTES"<<endl;
        cout<<"6) CONFIGURACIONES"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"0) SALIR: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: submenuJugadores();
                break;
            case 2: submenuDeportes();
                break;
            case 3: submenuEquipos();
                break;
            case 4: submenuTipoDeporte();
                break;
            case 5: submenuReportes();
                break;
            case 6: submenuConfiguraciones();
                break;
            case 0: return 0;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        system("pause");
    }
    return 0;
}
