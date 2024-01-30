#ifndef SUBMENUDEPORTES_H_INCLUDED
#define SUBMENUDEPORTES_H_INCLUDED


void submenuDeportes(){
    ArchivoDeporte archiDeporte("deportes.dat");
    int opc;
    while(true){
        system("cls");
        cout<<"MENU DEPORTES"<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
        cout<<"1) AGREGAR DEPORTE"<<endl;
        cout<<"2) LISTAR DEPORTE POR ID"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR ANIO DE ORIGEN"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"0) RETROCEDER AL MENU PRINCIPAL "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                if(archiDeporte.agregarRegistroDeporte()) cout<<"REGISTRO DE DEPORTE AGREGADO"<<endl;
                else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                break;
            case 2:
                archiDeporte.listarRegistroID();
                break;
            case 3:
                if(archiDeporte.listarRegistrosDeportes()) cout<<"FIN DE LA LISTA"<<endl;
                else cout<<"NO SE ENCONTRO NINGUN REGISTRO"<<endl;
                break;
            case 4:
                if(archiDeporte.modificarAnioOrigen()) cout<<"ANIO DE ORIGEN MODIFICADO"<<endl;
                else cout<<"NO SE PUDO MODIFICAR EL ANIO DE ORIGEN"<<endl;
                break;
            case 5:
                if(archiDeporte.bajaLogica()==true) cout<<"REGISTRO DADO DE BAJA"<<endl;
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


#endif // SUBMENUDEPORTES_H_INCLUDED
