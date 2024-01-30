#ifndef SUBMENUEQUIPOS_H_INCLUDED
#define SUBMENUEQUIPOS_H_INCLUDED

void submenuEquipos(){
    ArchivoEquipo archiEquipo("equipos.dat");
    int opc;
    while(true){
        system("cls");
        cout<<"MENU EQUIPOS"<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
        cout<<"1) AGREGAR EQUIPO"<<endl;
        cout<<"2) LISTAR EQUIPO POR ID"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR NOMBRE"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"0) RETROCEDER AL MENU PRINCIPAL "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                if(archiEquipo.agregarRegistro()) cout<<"REGISTRO DE EQUIPO AGREGADO"<<endl;
                else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                break;
            case 2: archiEquipo.listarRegistroID();
                break;
            case 3:
                if(archiEquipo.listarRegistros()) cout<<"FIN DE LA LISTA"<<endl;
                else cout<<"NO SE ENCONTRO NINGUN REGISTRO"<<endl;
                break;
            case 4:
                if(archiEquipo.modificarNombre()) cout<<"NOMBRE DE EQUIPO MODIFICADO"<<endl;
                else cout<<"NO SE PUDO MODIFICAR EL NOMBRE DE EQUIPO"<<endl;
                break;
            case 5:
                if(archiEquipo.bajaLogica() == true) cout<<"REGISTRO DADO DE BAJA"<<endl;
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

#endif // SUBMENUEQUIPOS_H_INCLUDED
