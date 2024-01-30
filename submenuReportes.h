#ifndef SUBMENUREPORTES_H_INCLUDED
#define SUBMENUREPORTES_H_INCLUDED

void submenuReportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU REPORTES"<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
        cout<<"1) ACTIVIDAD 1"<<endl;
        cout<<"2) ACTIVIDAD 2"<<endl;
        cout<<"3) ACTIVIDAD 3"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"0) RETROCEDER AL MENU PRINCIPAL "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: punto1();
                break;
            case 2: punto2();
                break;
            case 3: punto3();
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                break;

        }
        system("pause");
    }
}

#endif // SUBMENUREPORTES_H_INCLUDED
