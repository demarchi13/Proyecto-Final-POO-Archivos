#ifndef SUBMENUCONFIGURACIONES_H_INCLUDED
#define SUBMENUCONFIGURACIONES_H_INCLUDED

void submenuConfiguraciones(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU REPORTES"<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES"<<endl;
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES"<<endl;
        cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE EQUIPOS"<<endl;
        cout<<"4) COPIA DE SEGURIDAD DEL ARCHIVO DE TIPO DE DEPORTES"<<endl;
        cout << endl;
        cout<<"5) RESTAURAR EL ARCHIVO DE JUGADORES"<<endl;
        cout<<"6) RESTAURAR EL ARCHIVO DE DEPORTES"<<endl;
        cout<<"7) RESTAURAR EL ARCHIVO DE EQUIPOS"<<endl;
        cout<<"8) RESTAURAR EL ARCHIVO DE TIPO DE DEPORTES"<<endl;
        cout << endl;
        cout<<"9) ESTABLECER DATOS DE INCIO"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"0) RETROCEDER AL MENU PRINCIPAL "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: backupJugadores();
                break;
            case 2: backupDeportes();
                break;
            case 3: backupEquipos();
                break;
            case 4: backupTipoDeporte();
                break;
            case 5: restaurarJugadores();
                break;
            case 6: restaurarDeportes();
                break;
            case 7: restaurarEquipos();
                break;
            case 8: restaurarTipoDeportes();
                break;
            case 9: establerDatosInicio();
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                break;

        }
        system("pause");
    }
}

#endif // SUBMENUCONFIGURACIONES_H_INCLUDED
