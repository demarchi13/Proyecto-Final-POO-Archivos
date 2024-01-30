#ifndef SUBMENUJUGADORES_H_INCLUDED
#define SUBMENUJUGADORES_H_INCLUDED

void submenuJugadores(){
    ArchivoJugador archiJugador("jugadores.dat");
    Jugador reg;
    int opc;
    while(true){
        system("cls");
        cout<<"MENU JUGADORES"<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
        cout<<"1) AGREGAR JUGADOR"<<endl;
        cout<<"2) LISTAR JUGADOR POR DNI"<<endl;
        cout<<"3) LISTAR TODOS LOS JUGADORES"<<endl;
        cout<<"4) MODIFICAR FECHA DE INSCRIPCION"<<endl;
        cout<<"5) ELIMINAR REGISTRO DE JUGADOR"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"0) RETROCEDER AL MENU PRINCIPAL "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                archiJugador.agregarRegistroJugador();
                break;
            case 2:
                archiJugador.listarRegistroDNI();
                break;
            case 3:
                if(archiJugador.listarRegistrosJugadores()) cout<<"FIN DE LA LISTA"<<endl;
                else cout<<"NO SE ENCONTRO NINGUN REGISTRO"<<endl;
                break;
            case 4:
                if(archiJugador.modificarFechaInscripcion()) cout<<"FECHA DE INSCRIPCION MODIFICADA"<<endl;
                else cout<<"NO SE PUDO MODIFICAR LA FECHA DE INSCRIPCION"<<endl;
                break;
            case 5:
                if(archiJugador.bajaLogica() == true) cout<<"REGISTRO DADO DE BAJA"<<endl;
                else cout<<"NO SE PUDO DE DAR DE BAJA EL REGISTRO"<<endl;
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                break;


        }
        system("pause");
    }
}
#endif // SUBMENUJUGADORES_H_INCLUDED
