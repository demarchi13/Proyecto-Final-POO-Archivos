#ifndef SUBMENUTIPODEPORTE_H_INCLUDED
#define SUBMENUTIPODEPORTE_H_INCLUDED

void submenuTipoDeporte(){
    ArchivoTipoDeporte archiTipo("TipodeDeporte.dat");
    int opc;
    while(true){
        system("cls");
        cout<<"MENU TIPO DE DEPORTE"<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
        cout<<"1) AGREGAR TIPO"<<endl;
        cout<<"2) LISTAR TIPO POR ID"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR NIVEL DE DIFICULTAD"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"0) RETROCEDER AL MENU PRINCIPAL "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                if(archiTipo.agregarRegistro()) cout<<"REGISTRO DE TIPO DE DEPORTE AGREGADO"<<endl;
                else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                break;
            case 2: archiTipo.listarRegistroID();
                break;
            case 3:
                if(archiTipo.listarRegistros()) cout<<"FIN DE LA LISTA"<<endl;
                else cout<<"NO SE ENCONTRO NINGUN REGISTRO"<<endl;
                break;
            case 4:
                if(archiTipo.modificarNivel()) cout<<"NIVEL DE DIFICULTAD MODIFICADO"<<endl;
                else cout<<"NO SE PUDO MODIFICAR EL NIVEL DE DIFICULTAD"<<endl;
                break;
            case 5:
                if(archiTipo.bajaLogica() == true) cout<<"REGISTRO DADO DE BAJA"<<endl;
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

#endif // SUBMENUTIPODEPORTE_H_INCLUDED
