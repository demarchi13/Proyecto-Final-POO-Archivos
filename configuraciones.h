#ifndef CONFIGURACIONES_H_INCLUDED
#define CONFIGURACIONES_H_INCLUDED

void backupJugadores(){
    const char* copyJugadores = "copy jugadores.dat jugadores.bak";
    int resultado = system(copyJugadores);

    if (resultado == 0) {
        cout << "Copia de seguridad realizada con exito." << endl;
    } else {
        cout << "Error al realizar la copia de seguridad." << endl;
    }
}

void backupDeportes(){
    const char* copyDeportes = "copy deportes.dat deportes.bak";
    int resultado = system(copyDeportes);

    if (resultado == 0) {
        cout << "Copia de seguridad realizada con exito." << endl;
    } else {
        cout << "Error al realizar la copia de seguridad." << endl;
    }
}

void backupEquipos(){
    const char* copyEquipos = "copy equipos.dat equipos.bak";
    int resultado = system(copyEquipos);

    if (resultado == 0) {
        cout << "Copia de seguridad realizada con exito." << endl;
    } else {
        cout << "Error al realizar la copia de seguridad." << endl;
    }
}

void backupTipoDeporte(){
    const char* copyTipoDeporte = "copy tipoDeDeporte.dat tipoDeDeporte.bak";
    int resultado = system(copyTipoDeporte);

    if (resultado == 0) {
        cout << "Copia de seguridad realizada con exito." << endl;
    } else {
        cout << "Error al realizar la copia de seguridad." << endl;
    }
}

void restaurarJugadores(){
    FILE* pJugadores;
    FILE* pJugadoresBackup;

    pJugadoresBackup = fopen("jugadores.bak","rb");
    if(pJugadoresBackup == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" <<endl;
        return;
    }
    pJugadores = fopen("jugadores.dat", "wb");
    if(pJugadores == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" <<endl;
        return;
    }
    Jugador jugador;
    int escribio;
    while(fread(&jugador, sizeof(Jugador),1,pJugadoresBackup) == 1){
        if(jugador.getEstado() == true){
            escribio = fwrite(&jugador, sizeof(Jugador),1,pJugadores);
        }
    }
    if(escribio == 1) cout<< "RESTAURACION DE DATOS EXITOSA" <<endl;
    else cout<< "NO SE PUDO REALIZAR LA RESTAURACION DE DATOS" <<endl;

    fclose(pJugadoresBackup);
    fclose(pJugadores);
}

void restaurarDeportes(){
    FILE* pDeportes;
    FILE* pDeportesBackup;

    pDeportesBackup = fopen("deportes.bak","rb");
    if(pDeportesBackup == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" <<endl;
        return;
    }
    pDeportes = fopen("deportes.dat", "wb");
    if(pDeportes == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" <<endl;
        return;
    }
    Deporte deporte;
    int escribio;
    while(fread(&deporte, sizeof(Deporte),1,pDeportesBackup) == 1){
        if(deporte.getEstado() == true){
            escribio = fwrite(&deporte, sizeof(Deporte),1,pDeportes);
        }
    }
    if(escribio == 1) cout<< "RESTAURACION DE DATOS EXITOSA" <<endl;
    else cout<< "NO SE PUDO REALIZAR LA RESTAURACION DE DATOS" <<endl;

    fclose(pDeportesBackup);
    fclose(pDeportes);
}

void restaurarEquipos(){
    FILE* pEquipos;
    FILE* pEquiposBackup;

    pEquiposBackup = fopen("equipos.bak","rb");
    if(pEquiposBackup == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" <<endl;
        return;
    }
    pEquipos = fopen("equipos.dat", "wb");
    if(pEquipos == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" <<endl;
        return;
    }
    Equipo equipo;
    int escribio;
    while(fread(&equipo, sizeof(Equipo),1,pEquiposBackup) == 1){
        if(equipo.getEstado() == true){
            escribio = fwrite(&equipo, sizeof(Equipo),1,pEquipos);
        }
    }
    if(escribio == 1) cout<< "RESTAURACION DE DATOS EXITOSA" <<endl;
    else cout<< "NO SE PUDO REALIZAR LA RESTAURACION DE DATOS" <<endl;

    fclose(pEquiposBackup);
    fclose(pEquipos);
}

void restaurarTipoDeportes(){
    FILE* pTipo;
    FILE* pTipoBackup;

    pTipoBackup = fopen("tipoDeDeporte.bak","rb");
    if(pTipoBackup == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" <<endl;
        return;
    }
    pTipo = fopen("tipoDeDeporte.dat", "wb");
    if(pTipo == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" <<endl;
        return;
    }
    TipoDeporte tipo;
    int escribio;
    while(fread(&tipo, sizeof(TipoDeporte),1,pTipoBackup) == 1){
        if(tipo.getEstado() == true){
            escribio = fwrite(&tipo, sizeof(TipoDeporte),1,pTipo);
        }
    }
    if(escribio == 1) cout<< "RESTAURACION DE DATOS EXITOSA" <<endl;
    else cout<< "NO SE PUDO REALIZAR LA RESTAURACION DE DATOS" <<endl;

    fclose(pTipoBackup);
    fclose(pTipo);
}

void establerDatosInicio(){
    const char* copyJugadores1 = "copy jugadoresInicio.dat jugadores.dat";
    int resultado1 = system(copyJugadores1);

    if (resultado1 == 0) {
        cout << "Datos de inicio Jugadores cargados correctamente" << endl;
    } else {
        cout << "Error al cargar los datos de inicio" << endl;
    }

    const char* copyDeportes1 = "copy deportesInicio.dat deportes.dat";
    int resultado2 = system(copyDeportes1);

    if (resultado2 == 0) {
        cout << "Datos de inicio Deportes cargados correctamente" << endl;
    } else {
        cout << "Error al cargar los datos de inicio" << endl;
    }

    const char* copyEquipos1 = "copy equiposInicio.dat equipos.dat";
    int resultado3 = system(copyEquipos1);

    if (resultado3 == 0) {
        cout << "Datos de inicio Equipos cargados correctamente" << endl;
    } else {
        cout << "Error al cargar los datos de inicio" << endl;
    }

    const char* copyTipoDeporte1 = "copy TipodeDeporteInicio.dat tipoDeDeporte.dat";
    int resultado4 = system(copyTipoDeporte1);

    if (resultado4 == 0) {
        cout << "Datos de inicio Tipo de Deporte cargados correctamente" << endl;
    } else {
        cout << "Error al cargar los datos de inicio" << endl;
    }
}


#endif // CONFIGURACIONES_H_INCLUDED
