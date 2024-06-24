#include "appManager.h"
#include <cstring>
#include <cstdlib>
#include "Terminal.h"
#include "Comida.h"
#include "ArchivoComida.h"
#include "Bebida.h"
#include "ArchivoBebida.h"

/*************** clase usuario provisoria ***************************/
bool User::verifyUser(std::string user, std::string pass){
    _nivelUser = 0;

    if(user == MasterUser && pass == MasterPass) _nivelUser = 1;
    if(user == userNormal && pass == passNormal) _nivelUser = 2;

    return _nivelUser;
}
/*************** clase usuario provisoria ***************************/

void AppManager::login(){
    std::string user, pass;
    Terminal terminal;
    int posx = 50;
    int posy = 13;

    rlutil::cls();
    terminal.dibujarRectangulo(2,0,30,116);
    terminal.dibujarRectangulo(41,9,11,36);

    terminal.mostrarTexto("Inicio de sesion: ",posx,posy);
    terminal.mostrarTexto("-------------------",posx,posy+1);
    terminal.mostrarTexto("Legajo: ",posx,posy+2);
    terminal.mostrarTexto("Password: ",posx,posy+3);

    while(true){
        terminal.pintarHorizontal(posx+10,16,posy+2);
        terminal.pintarHorizontal(posx+10,16,posy+3);

        user = terminal.ingresarTexto(posx + 10,posy + 2,true);
        pass = terminal.ingresarTexto(posx + 10,posy + 3,true);
        rlutil::hidecursor();

        if(usuario.verifyUser(user,pass)) break;
        else{
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            terminal.mostrarTexto("Datos incorrectos...",posx,posy+5);
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }

    }

    terminal.pintarHorizontal(posx,20,posy+5);
    terminal.mostrarTexto("Ingresando",posx+5,posy +10);
    terminal.barraEspera(80,posx,posy+12);

    switch(usuario.getNivelUser()){
    case 1:
        MenuAdmin();
        break;
    case 2:
        MenuUser();
        break;
    default:
        exit(100);
        break;
    }

    rlutil::cls();
    exit(0);

}

void AppManager::MenuUser(){
    Terminal terminal;
    int opc = 0;
    int x = 4;
    int y = 5;

    terminal.pintarRectangulo(40,9,18,40);
    terminal.dibujarRectangulo(2,0,30,30);
    TablaPrecios();                     //provisoria

    do{

        terminal.crearBoton("REGISTRAR VENTA",x,y,opc == 0);
        terminal.crearBoton("HISTORIAL DE VENTAS",x,y+3,opc == 1);
        terminal.crearBoton("CERRAR SESION",x,y+6,opc == 2);
        terminal.crearBoton("SALIR",x,y+9,opc == 3);

        switch(rlutil::getkey()){
        case 14:    ///sube
            opc--;
            if(opc < 0) opc = 3;
            break;
        case 15:    ///baja
            opc++;
            if(opc > 3) opc = 0;
            break;
        case 1:     ///enter
            if(opc == 0) Venta();
            if(opc == 1) Historial();
            if(opc == 2 )login();
            if(opc == 3 )return;

            TablaPrecios();
            break;
        }

    }while(true);
}

void AppManager::MenuAdmin(){
    Terminal terminal;
    int opc = 0;
    int x = 4;
    int y = 5;

    terminal.pintarRectangulo(40,9,18,40);
    terminal.dibujarRectangulo(2,0,30,30);
    TablaPrecios();                         //provisoria

    do{

        terminal.crearBoton("REGISTRAR VENTA",x,y,opc == 0);
        terminal.crearBoton("HISTORIAL DE VENTAS",x,y+3,opc == 1);
        terminal.crearBoton("CONFIGURACION",x,y+6,opc == 2);
        terminal.crearBoton("REPORTES",x,y+9,opc == 3);
        terminal.crearBoton("CERRAR SESION",x,y+12,opc == 4);
        terminal.crearBoton("SALIR",x,y+15,opc == 5);

        switch(rlutil::getkey()){
        case 14:    ///sube
            opc--;
            if(opc < 0) opc = 5;
            break;
        case 15:    ///baja
            opc++;
            if(opc > 5) opc = 0;
            break;
        case 1:     ///enter
            if(opc == 0) Venta();
            if(opc == 1) Historial();
            if(opc == 2) Config();
            if(opc == 3) Reportes();
            if(opc == 4) login();
            if(opc == 5) return;

            TablaPrecios();
            break;
        }

    }while(true);
}

void AppManager::Config(){
    Terminal terminal;
    int opc = 0;
    int x = 4;
    int y = 5;

    terminal.pintarRectangulo(4,2,25,26);
    terminal.pintarRectangulo(34,2,27,80);

    do{
        terminal.crearBoton("ALTA PRODUCTOS",x,y-3,opc == 0);
        terminal.crearBoton("BAJA PRODUCTOS",x,y,opc == 1);
        terminal.crearBoton("MODIFICAR STOCK",x,y+3,opc == 2);
        terminal.crearBoton("MODIFICAR PRECIO",x,y+6,opc == 3);
        terminal.crearBoton("BUSCAR ARTICULO",x,y+9,opc == 4);
        terminal.crearBoton("MODIFICAR USUARIOS",x,y+12,opc == 5);
        terminal.crearBoton("COPIA DE SEGURIDAD",x,y+15,opc == 6);
        terminal.crearBoton("RESTABLECER COPIA",x,y+18,opc == 7);
        terminal.crearBoton("VOLVER",x,y+21,opc == 8);

        switch(rlutil::getkey()){
        case 14:    ///sube
            opc--;
            if(opc < 0) opc = 8;
            break;
        case 15:    ///baja
            opc++;
            if(opc > 8) opc = 0;
            break;
        case 1:     ///enter
            if(opc == 0)AltaProd();
            if(opc == 1)BajaProd();
            if(opc == 2)ModStock();
            if(opc == 3)ModPrecio();
            if(opc == 4)BuscarArticulo();
            if(opc == 8 ){
                terminal.pintarRectangulo(4,2,27,27);
                return;
            }


            break;
        }

    }while(true);
}

void AppManager::Venta(){
    std::string producto, cantidad;
    Terminal terminal;
    int opc = 0;
    int x = 4;
    int y = 5;
    bool ingreso = false;

    terminal.pintarRectangulo(4,2,25,27);

    terminal.mostrarTexto("Legajo cajero:",x,y);
    terminal.mostrarTexto((usuario.getNivelUser() == 1 ? "ADMIN":"USUARIO"),23,y);   //legajo usuario actual

    terminal.mostrarTexto("Fecha:",x,y+2);
    terminal.mostrarTexto("01/01/1900",21,y+2);  //fecha actual

    terminal.mostrarTexto("Hora: ",x,y+4);
    terminal.mostrarTexto("10:00 PM",23,y+4);    //hora actual

    terminal.mostrarTexto("producto:",x,y+6);
    terminal.mostrarTexto("cantidad:",x,y+8);
    terminal.mostrarTexto("Precio:",x,y+10);

    while(true){

        terminal.crearBoton("AGREGAR PRODUCTO",x,y+12,opc == 0);
        terminal.crearBoton("MODIFICAR PRODUCTO",x,y+15,opc == 1);
        terminal.crearBoton("FINALIZAR VENTA",x,y+18,opc == 2);

        if(!ingreso){
            producto = terminal.ingresarTexto(x+17,y+6,true);
            cantidad = terminal.ingresarTexto(x+17,y+8,true);
            terminal.mostrarTexto("$100.5",x+20,y+10);   //precio actual
            rlutil::hidecursor();
            ingreso = true;
        }

        switch(rlutil::getkey()){
        case 14:
            opc--;
            if(opc < 0) opc = 2;
            break;
        case 15:
            opc++;
            if(opc > 2) opc = 0;
            break;
        case 1:
            if(opc == 0){
                ///guarda el prod actual
                terminal.pintarRectangulo(20,y+6,4,12);
                ingreso = false;
            }

            if(opc == 1) {
                terminal.pintarRectangulo(20,y+6,4,12);
                ingreso = false;

            }

            if(opc == 2){
                ///guardar prod actual
                terminal.pintarRectangulo(4,2,25,27);
                return;
            }
            break;
        }


    }

}

void AppManager::TablaPrecios(){
    Terminal terminal;
    char alta[2] = {(char)30,'\0'};
    char baja[2] = {(char)31,'\0'};

    int x = 38;
    int y = 4;
    int contFilas = 0;
    bool status = false;
    rlutil::COLOR indicador;

    ///--------datos simulados------
    std::string bebidas[10]={
        "Whisky","Cerveza","Vinos",
        "Espumantes","Vodka","Ron",
        "Aperitivos","Tragos",
        "Cocteles","Comida"
    };
    std::string aux = "bebida";

    int elem[10] = {3,5,4,6,4,2,7,5,8,5};
    ///-------------------------

    terminal.pintarRectangulo(x,2,0,x+37,rlutil::COLOR::LIGHTRED);

    for(int i=x; i<91; i+=26){
        terminal.crearColumna("Bebida",rlutil::COLOR::LIGHTRED,i,2,false);
        terminal.crearColumna(" %Osc",rlutil::COLOR::LIGHTRED,i+8,2,false);
        terminal.crearColumna("PreUlt",rlutil::COLOR::LIGHTRED,i+16,2,i < 90);
    }


    for(int i=0; i<10; i++){
        if(contFilas > 28) {
            x += 26;
            y = 4;
        }

        terminal.crearFila(bebidas[i],rlutil::COLOR::LIGHTCYAN,x,y);
        terminal.crearFila("-----------------------",rlutil::COLOR::WHITE,x,++y);

        for(int j=0; j<elem[i];j++){
            if(contFilas == 29) {
                x += 26;
                y = 4;
            }

            if(status) indicador = rlutil::COLOR::GREEN;
            else indicador = rlutil::COLOR::RED;

            terminal.crearFila("bebida",rlutil::COLOR::WHITE,x,++y);
            terminal.crearFila("123,5",rlutil::COLOR::WHITE,x+16,y);
            terminal.crearFila((status == true ? alta : baja),indicador,x+13,y);
            terminal.crearFila("%1,25",indicador,x+8,y);

            status = !status;
            contFilas = y;
        }

        y += 2;
        contFilas = y;
    }
}

void AppManager::Historial(){
    Terminal terminal;
    int opc = 0;
    char arriba[2] = {(char)30,'\0'};
    char abajo[2] = {(char)31,'\0'};

    terminal.pintarRectangulo(34,2,27,80);

    while(true){

        terminal.crearBotonVertical(arriba,112,8,opc == 1);
        terminal.crearBotonVertical(abajo,112,14,opc == 2);

        terminal.crearBoton("Hoy",33,1,opc == 3);
        terminal.crearBoton("Ultimos 15 dias",61,1,opc == 4);
        terminal.crearBoton("Ultimos 30 dias",89,1,opc == 5);

        switch(rlutil::getkey()){
        case 14:        //arriba
            opc = 1;
            break;
        case 15:
            opc = 2;
            break;
        case 17:
            if(opc < 3) opc = 5;
            else{
                opc++;
                if(opc > 5) opc = 5;
            }
            break;
        case 16:
            if(opc < 3) opc = 3;
            else{
                opc--;
                if(opc < 3) opc = 3;
            }
            break;
        case 0:
            terminal.pintarRectangulo(34,2,27,84);
            return;
            break;
        }
    }
}

void AppManager::AltaProd(){

    int x=60;
    int y=4;
    ArchivoComida archiComida = "comidas.dat";
    ArchivoBebida archiBebida = "bebidas.dat";
    std::string nombre, id, precio_inicial, costo, stock, variacion, graduacion_acohol, volumen, observacion, guarnicion;
    int opcTipoProducto = 2;


    Terminal terminal;

    terminal.pintarRectangulo(34,2,27,80);



    while(true){


            terminal.crearBoton("Ingresar bebida",x,y+8,opcTipoProducto==0);
            terminal.crearBoton("Volver",x,y+16,opcTipoProducto==1);
            terminal.crearBoton("Ingresar comida",x,y,opcTipoProducto==2);



            switch(rlutil::getkey()){
                case 14:
                    opcTipoProducto--;
                    if(opcTipoProducto < 0) opcTipoProducto = 2;
                    break;
                case 15:
                    opcTipoProducto++;
                    if(opcTipoProducto > 2) opcTipoProducto = 0;
                    break;
                case 1:
                    if(opcTipoProducto == 2){
                        terminal.pintarRectangulo(34,2,27,80);





                        terminal.mostrarTexto("Crear nuevo objeto comida: ",x,y);
                        terminal.mostrarTexto("_________________________ ",x,y+1);

                        terminal.mostrarTexto("Ingresar ID: ",x,y+4);
                        id = terminal.ingresarTexto(x + 22,y+4 ,true);

                        terminal.mostrarTexto("Ingresar nombre: ",x,y+6);
                        nombre = terminal.ingresarTexto(x + 22,y+6 ,true);

                        terminal.mostrarTexto("Ingresar precio: ",x,y+8);
                        precio_inicial = terminal.ingresarTexto(x + 22,y+8 ,true);

                        terminal.mostrarTexto("Ingresar costo: ",x,y+10);
                        costo = terminal.ingresarTexto(x + 22,y+10 ,true);

                        terminal.mostrarTexto("Ingresar stock: ",x,y+12);
                        stock = terminal.ingresarTexto(x + 22,y+12 ,true);

                        terminal.mostrarTexto("Ingresar variacion: ",x,y+14);
                        variacion = terminal.ingresarTexto(x + 22,y+14 ,true);

                        terminal.mostrarTexto("Ingresar observacion: ",x,y+16);
                        observacion = terminal.ingresarTexto(x + 22,y+16 ,true);


                        terminal.mostrarTexto("Ingresar guarnicion: ",x,y+18);
                        guarnicion = terminal.ingresarTexto(x + 22,y+18 ,true);

                        int idToInt = std::atoi(id.c_str());

                        Comida comida(idToInt, nombre, std::atof(precio_inicial.c_str()), std::atof(costo.c_str()), std::atoi(stock.c_str()), std::atof(variacion.c_str()), observacion, guarnicion);

                        bool confirmado = false;

                        int opc = 3;

                        while( !confirmado )
                        {
                           terminal.crearBoton("Confirmar",x-16,y+20,opc==3);
                            terminal.crearBoton("Cancelar",x+16,y+20,opc==4);

                            switch(rlutil::getkey()){
                                case 16:
                                    opc--;
                                    if(opc < 3) opc = 4;
                                    break;
                                case 17:
                                    opc++;
                                    if(opc > 4) opc = 3;
                                    break;
                                case 1:

                                    if( opc == 4){

                                        confirmado = true;
                                        break;
                                    }

                                    if(opc == 3){
                                        confirmado = true;
                                        break;
                                    }
                            }

                        }


                        //Cancelo la creacion del objeto
                        if( opc == 4){
                            terminal.pintarRectangulo(34,2,27,80);
                            terminal.mostrarTexto(">Creacion de objeto cancelada.",x,y);
                            return;
                        }

                        //Pregunto si existe
                        if(archiComida.buscarRegistro(idToInt) < 0 && archiBebida.buscarRegistro(idToInt) < 0){
                            terminal.pintarRectangulo(34,2,27,80);
                            bool grabo = archiComida.grabarRegistro(comida);

                            if( grabo ){
                                terminal.mostrarTexto(">Objeto comida creado correctamente.",x,y);
                            }else{
                                terminal.mostrarTexto(">Error al crear el objeto.",x,y);
                             }

                        }else{
                            terminal.pintarRectangulo(34,2,27,80);
                            terminal.mostrarTexto(">Ya existe un objeto con ese ID.",x,y);

                        }

                        rlutil::hidecursor();


                        return;
                    }


                    if(opcTipoProducto == 0) {
                        terminal.pintarRectangulo(34,2,27,80);


                        terminal.mostrarTexto("Crear nuevo objeto bebida: ",x,y);
                        terminal.mostrarTexto("_________________________ ",x,y+1);

                        terminal.mostrarTexto("Ingresar ID: ",x,y+4);
                        id = terminal.ingresarTexto(x + 22,y+4 ,true);

                        terminal.mostrarTexto("Ingresar nombre: ",x,y+6);
                        nombre = terminal.ingresarTexto(x + 22,y+6 ,true);

                        terminal.mostrarTexto("Ingresar precio: ",x,y+8);
                        precio_inicial = terminal.ingresarTexto(x + 22,y+8 ,true);

                        terminal.mostrarTexto("Ingresar costo: ",x,y+10);
                        costo = terminal.ingresarTexto(x + 22,y+10 ,true);

                        terminal.mostrarTexto("Ingresar stock: ",x,y+10);
                        stock = terminal.ingresarTexto(x + 22,y+12 ,true);

                        terminal.mostrarTexto("Ingresar variacion: ",x,y+12);
                        variacion = terminal.ingresarTexto(x + 22,y+14 ,true);

                        terminal.mostrarTexto("Ingresar grad. acohol: ",x,y+14);
                        graduacion_acohol = terminal.ingresarTexto(x + 22,y+16 ,true);

                        terminal.mostrarTexto("Ingresar volumen: ",x,y+16);
                        volumen = terminal.ingresarTexto(x + 22,y+18 ,true);

                        int idToInt = std::atoi(id.c_str());

                        Bebida bebida(idToInt, nombre, std::atof(precio_inicial.c_str()), std::atof(costo.c_str()), std::atoi(stock.c_str()), std::atof(variacion.c_str()), std::atof(volumen.c_str()), std::atof(graduacion_acohol.c_str()));

                        bool confirmado = false;

                        while( !confirmado ){

                            terminal.crearBoton("Confirmar",x-16,y+20,opcTipoProducto==3);
                            terminal.crearBoton("Cancelar",x+16,y+20,opcTipoProducto==4);

                            switch(rlutil::getkey()){
                                case 16:
                                    opcTipoProducto--;
                                    if(opcTipoProducto < 0) opcTipoProducto = 3;
                                    break;
                                case 17:
                                    opcTipoProducto++;
                                    if(opcTipoProducto > 2) opcTipoProducto = 4;
                                    break;
                                case 1:

                                    if( opcTipoProducto == 4){

                                        confirmado = true;
                                        break;
                                    }

                                    if(opcTipoProducto == 3){
                                        confirmado = true;
                                        break;
                                    }
                            }
                        }


                        //Cancelo la creacion del objeto
                        if( opcTipoProducto == 4){
                            terminal.pintarRectangulo(34,2,27,80);
                            terminal.mostrarTexto(">Creacion de objeto cancelada.",x,y);
                            return;
                        }


                        //Pregunto si existe
                        if(archiComida.buscarRegistro(idToInt) < 0 && archiBebida.buscarRegistro(idToInt) < 0){
                            terminal.pintarRectangulo(34,2,27,80);
                            bool grabo = archiBebida.grabarRegistro(bebida);

                            if( grabo ){
                                terminal.mostrarTexto(">Objeto bebida creado correctamente.",x,y);
                            }else{
                                terminal.mostrarTexto(">Error al crear el objeto.",x,y);
                             }

                        }else{
                            terminal.pintarRectangulo(34,2,27,80);
                            terminal.mostrarTexto(">Ya existe un objeto con ese ID.",x,y);

                        }

                        rlutil::hidecursor();


                        return;


                        return;

                    }

                    if(opcTipoProducto == 1){
                        terminal.pintarRectangulo(34,2,27,80);
                        return;
                    }
                    break;
                }
        }


    rlutil::anykey();

}

void AppManager::BajaProd(){
    Terminal terminal;

    terminal.pintarRectangulo(34,2,27,80);
    int x=60;
    int y=4;

    ArchivoComida archiComida = "comidas.dat";
    ArchivoBebida archiBebida = "bebidas.dat";


    std::string id;
    int opc = 0, idEncontrado = -1;

    while(true){




        terminal.crearBoton("Borrar comida",x,y,opc==0);
        terminal.crearBoton("Borrar bebida",x,y+8,opc==1);
        terminal.crearBoton("Volver",x,y+16,opc==2);



        switch(rlutil::getkey()){
            case 14:
                opc--;
                if(opc < 0) opc = 2;
                break;
            case 15:
                opc++;
                if(opc > 2) opc = 0;
                break;
            case 1:
            {


                if(opc == 0){
                    Comida comida;

                    terminal.pintarRectangulo(34,2,27,80);

                    terminal.mostrarTexto("Ingrese el id del articulo: ",x,y);
                    id = terminal.ingresarTexto(x + 30,y ,true);

                    //Busco el registro;
                    idEncontrado = archiComida.buscarRegistro(std::atoi(id.c_str()));
                    comida = archiComida.leerRegistro(idEncontrado);


                    if( idEncontrado >= 0 && comida.getEstado() ){

                        terminal.pintarRectangulo(34,2,27,80);





                        terminal.mostrarTexto("Esta seguro que desea eliminar el siguiente articulo?",x,y);
                        terminal.mostrarTexto("ID: " + std::to_string(comida.getID()) ,x,y+4);
                        terminal.mostrarTexto("Nombre: " + comida.getNombre(),x,y+6);
                        terminal.mostrarTexto("Precio: " + std::to_string(comida.getPrecioInicial()),x,y+8);
                        terminal.mostrarTexto("Costo: " + std::to_string(comida.getCosto()),x,y+10);
                        terminal.mostrarTexto("Stock: " + std::to_string(comida.getStock()),x,y+12);
                        terminal.mostrarTexto("Variacion: " + std::to_string(comida.getVariacion()),x,y+14);
                        terminal.mostrarTexto("Guarnicion: " + comida.getGuarnicion(),x,y+16);
                        terminal.mostrarTexto("Observacion: " + comida.getObservacion(),x,y+18);


                        bool confirmado = false;

                        while( !confirmado ){

                            terminal.crearBoton("Confirmar",x-16,y+20,opc==3);
                            terminal.crearBoton("Cancelar",x+16,y+20,opc==4);

                            switch(rlutil::getkey()){
                                case 16:
                                    opc--;
                                    if(opc < 0) opc = 3;
                                    break;
                                case 17:
                                    opc++;
                                    if(opc > 2) opc = 4;
                                    break;
                                case 1:

                                    if( opc == 4){

                                        confirmado = true;
                                        break;
                                    }

                                    if(opc == 3){
                                        confirmado = true;
                                        break;
                                    }
                            }
                        }

                        //Si pongo salir, salgo del primer while
                        if( opc == 4){
                            terminal.pintarRectangulo(34,2,27,80);
                            terminal.mostrarTexto(">Baja de articulo cancelada",x,y);
                            return;
                        };


                        comida.setEstado(false);
                        bool modificar = archiComida.modificarRegistro(comida,idEncontrado);

                        terminal.pintarRectangulo(34,2,27,80);

                        if( modificar )
                        {
                            terminal.mostrarTexto(">Comida borrada correctamente",x,y);
                            return;
                        }else{
                            terminal.mostrarTexto(">Error al borrar comida",x,y);
                            return;
                        }


                    }else{

                        terminal.pintarRectangulo(34,2,27,80);

                        terminal.mostrarTexto("No se encontro el articulo.",x,y);
                        return;
                    }






                }

               if(opc == 1){
                    Bebida bebida;

                    terminal.pintarRectangulo(34,2,27,80);

                    terminal.mostrarTexto("Ingrese el id del articulo: ",x,y);
                    id = terminal.ingresarTexto(x + 30,y ,true);

                    //Busco el registro;
                    idEncontrado = archiBebida.buscarRegistro(std::atoi(id.c_str()));
                    bebida = archiBebida.leerRegistro(idEncontrado);


                    if( idEncontrado >= 0 && bebida.getEstado() ){

                        terminal.pintarRectangulo(34,2,27,80);





                        terminal.mostrarTexto("Esta seguro que desea eliminar el siguiente articulo?",x,y);
                        terminal.mostrarTexto("ID: " + std::to_string(bebida.getID()) ,x+2,y+4);
                        terminal.mostrarTexto("Nombre: " + bebida.getNombre(),x+2,y+6);
                        terminal.mostrarTexto("Precio: " + std::to_string(bebida.getPrecioInicial()),x+2,y+8);
                        terminal.mostrarTexto("Costo: " + std::to_string(bebida.getCosto()),x+2,y+10);
                        terminal.mostrarTexto("Stock: " + std::to_string(bebida.getStock()),x+2,y+12);
                        terminal.mostrarTexto("Variacion: " + std::to_string(bebida.getVariacion()),x+2,y+14);
                        terminal.mostrarTexto("Grad. alcoholica: " + std::to_string(bebida.getGraduacionAlcoholica()),x+2,y+16);
                        terminal.mostrarTexto("Volumen: " + std::to_string(bebida.getVolumen()),x+2,y+18);


                        bool confirmado = false;

                        while( !confirmado ){

                            terminal.crearBoton("Confirmar",x-16,y+20,opc==3);
                            terminal.crearBoton("Cancelar",x+16,y+20,opc==4);

                            switch(rlutil::getkey()){
                                case 16:
                                    opc--;
                                    if(opc < 0) opc = 3;
                                    break;
                                case 17:
                                    opc++;
                                    if(opc > 2) opc = 4;
                                    break;
                                case 1:

                                    if( opc == 4){

                                        confirmado = true;
                                        break;
                                    }

                                    if(opc == 3){
                                        confirmado = true;
                                        break;
                                    }
                            }
                        }

                        //Si pongo salir, salgo del primer while
                        if( opc == 4){
                            terminal.pintarRectangulo(34,2,27,80);
                            terminal.mostrarTexto(">Baja de articulo cancelada",x,y);
                            return;
                        };


                        bebida.setEstado(false);
                        bool modificar = archiBebida.modificarRegistro(bebida,idEncontrado);

                        terminal.pintarRectangulo(34,2,27,80);

                        if( modificar )
                        {
                            terminal.mostrarTexto(">Comida borrada correctamente",x,y);
                            return;
                        }else{
                            terminal.mostrarTexto(">Error al borrar bebida",x,y);
                            return;
                        }


                    }else{

                        terminal.pintarRectangulo(34,2,27,80);

                        terminal.mostrarTexto("No se encontro el articulo.",x,y);
                        return;
                    }
                }

                if(opc == 2) return;
        }

        }
    }


}

void AppManager::ModStock(){

    Terminal terminal;

    terminal.pintarRectangulo(34,2,27,80);
    int x=60;
    int y=4;

    ArchivoComida archiComida = "comidas.dat";
    ArchivoBebida archiBebida = "bebidas.dat";


    std::string id, stock;
    int opc = 0, idEncontrado = -1;

    while(true){

        terminal.crearBoton("Modificar stock comida",x,y,opc==0);
        terminal.crearBoton("Modificar stock bebida",x,y+8,opc==1);
        terminal.crearBoton("Volver",x,y+16,opc==2);

        switch(rlutil::getkey()){
            case 14:
                opc--;
                if(opc < 0) opc = 2;
                break;
            case 15:
                opc++;
                if(opc > 2) opc = 0;
                break;
           case 1:
               if(opc == 0){
                    Comida comida;

                    terminal.pintarRectangulo(34,2,27,80);

                    terminal.mostrarTexto("Ingrese el id del articulo: ",x,y);
                    id = terminal.ingresarTexto(x + 30,y ,true);

                    //Busco el registro;
                    idEncontrado = archiComida.buscarRegistro(std::atoi(id.c_str()));
                    comida = archiComida.leerRegistro(idEncontrado);


                    if( idEncontrado >= 0 && comida.getEstado() ){

                        terminal.pintarRectangulo(34,2,27,80);





                        terminal.mostrarTexto("Usted va a modificar el siguiente articulo:",x-10,y);
                        terminal.mostrarTexto("ID: " + std::to_string(comida.getID()) ,x,y+4);
                        terminal.mostrarTexto("Nombre: " + comida.getNombre(),x,y+6);
                        terminal.mostrarTexto("Stock: " + std::to_string(comida.getStock()),x,y+8);


                        terminal.mostrarTexto("Ingresar nuevo stock: ",x,y+14);

                        stock = terminal.ingresarTexto(x+25,y+14,true);


                        comida.setStock( std::atof(stock.c_str()) );

                        bool confirmado = false;

                        while( !confirmado ){

                            terminal.crearBoton("Confirmar",x-16,y+20,opc==3);
                            terminal.crearBoton("Cancelar",x+16,y+20,opc==4);

                            switch(rlutil::getkey()){
                                case 16:
                                    opc--;
                                    if(opc < 0) opc = 3;
                                    break;
                                case 17:
                                    opc++;
                                    if(opc > 2) opc = 4;
                                    break;
                                case 1:

                                    if( opc == 4){

                                        confirmado = true;
                                        break;
                                    }

                                    if(opc == 3){
                                        confirmado = true;
                                        break;
                                    }
                            }
                        }

                        //Si pongo salir, salgo del primer while
                        if( opc == 4){
                            terminal.pintarRectangulo(34,2,27,80);
                            terminal.mostrarTexto(">Modificacion de articulo cancelada",x,y);
                            return;
                        };




                        bool modificar = archiComida.modificarRegistro(comida,idEncontrado);

                        terminal.pintarRectangulo(34,2,27,80);

                        if( modificar )
                        {
                            terminal.mostrarTexto(">Stock modificado correctamente",x,y);
                            return;
                        }else{
                            terminal.mostrarTexto(">Error al borrar modificar stock",x,y);
                            return;
                        }


                    }else{

                        terminal.pintarRectangulo(34,2,27,80);

                        terminal.mostrarTexto("No se encontro el articulo.",x,y);
                        return;
                    }
                }

                if(opc == 1){
                    Bebida bebida;

                    terminal.pintarRectangulo(34,2,27,80);

                    terminal.mostrarTexto("Ingrese el id del articulo: ",x,y);
                    id = terminal.ingresarTexto(x + 30,y ,true);

                    //Busco el registro;
                    idEncontrado = archiBebida.buscarRegistro(std::atoi(id.c_str()));
                    bebida = archiBebida.leerRegistro(idEncontrado);


                    if( idEncontrado >= 0 && bebida.getEstado() ){

                        terminal.pintarRectangulo(34,2,27,80);


                        terminal.mostrarTexto("Usted va a modificar el siguiente articulo:",x-10,y);
                        terminal.mostrarTexto("ID: " + std::to_string(bebida.getID()) ,x,y+4);
                        terminal.mostrarTexto("Nombre: " + bebida.getNombre(),x,y+6);
                        terminal.mostrarTexto("Stock: " + std::to_string(bebida.getStock()),x,y+8);


                        terminal.mostrarTexto("Ingresar nuevo stock: ",x,y+14);

                        stock = terminal.ingresarTexto(x+25,y+14,true);


                        bebida.setStock( std::atof(stock.c_str()) );

                        bool confirmado = false;

                        while( !confirmado ){

                            terminal.crearBoton("Confirmar",x-16,y+20,opc==3);
                            terminal.crearBoton("Cancelar",x+16,y+20,opc==4);

                            switch(rlutil::getkey()){
                                case 16:
                                    opc--;
                                    if(opc < 0) opc = 3;
                                    break;
                                case 17:
                                    opc++;
                                    if(opc > 2) opc = 4;
                                    break;
                                case 1:

                                    if( opc == 4){

                                        confirmado = true;
                                        break;
                                    }

                                    if(opc == 3){
                                        confirmado = true;
                                        break;
                                    }
                            }
                        }

                        //Si pongo salir, salgo del primer while
                        if( opc == 4){
                            terminal.pintarRectangulo(34,2,27,80);
                            terminal.mostrarTexto(">Modificacion de articulo cancelada",x,y);
                            return;
                        };




                        bool modificar = archiBebida.modificarRegistro(bebida,idEncontrado);

                        terminal.pintarRectangulo(34,2,27,80);

                        if( modificar )
                        {
                            terminal.mostrarTexto(">Stock modificado correctamente",x,y);
                            return;
                        }else{
                            terminal.mostrarTexto(">Error al borrar modificar precio",x,y);
                            return;
                        }


                    }else{

                        terminal.pintarRectangulo(34,2,27,80);

                        terminal.mostrarTexto("No se encontro el articulo.",x,y);
                        return;
                    }
                }


                if( opc==2){
                    terminal.pintarRectangulo(34,2,27,80);
                    return;

                }


        }
    }
}

void AppManager::ModPrecio(){

    Terminal terminal;

    terminal.pintarRectangulo(34,2,27,80);
    int x=60;
    int y=4;

    ArchivoComida archiComida = "comidas.dat";
    ArchivoBebida archiBebida = "bebidas.dat";


    std::string id, precio;
    int opc = 0, idEncontrado = -1;

    while(true){

        terminal.crearBoton("Modificar precio comida",x,y,opc==0);
        terminal.crearBoton("Modificar precio bebida",x,y+8,opc==1);
        terminal.crearBoton("Volver",x,y+16,opc==2);

        switch(rlutil::getkey()){
            case 14:
                opc--;
                if(opc < 0) opc = 2;
                break;
            case 15:
                opc++;
                if(opc > 2) opc = 0;
                break;
           case 1:
                {


                   if(opc == 0){
                        Comida comida;

                        terminal.pintarRectangulo(34,2,27,80);

                        terminal.mostrarTexto("Ingrese el id del articulo: ",x,y);
                        id = terminal.ingresarTexto(x + 30,y ,true);

                        //Busco el registro;
                        idEncontrado = archiComida.buscarRegistro(std::atoi(id.c_str()));
                        comida = archiComida.leerRegistro(idEncontrado);


                        if( idEncontrado >= 0 && comida.getEstado() ){

                            terminal.pintarRectangulo(34,2,27,80);





                            terminal.mostrarTexto("Esta seguro que desea modificar el precio del siguiente articulo?",x,y);
                            terminal.mostrarTexto("ID: " + std::to_string(comida.getID()) ,x,y+4);
                            terminal.mostrarTexto("Nombre: " + comida.getNombre(),x,y+6);
                            terminal.mostrarTexto("Precio: " + std::to_string(comida.getPrecioInicial()),x,y+8);
                            terminal.mostrarTexto("Costo: " + std::to_string(comida.getCosto()),x,y+10);

                            terminal.mostrarTexto("Ingresar nuevo precio: ",x,y+14);

                            precio = terminal.ingresarTexto(x+15,y+14,true);


                            comida.setPrecioInicial( std::atof(precio.c_str()) );

                            bool confirmado = false;

                            while( !confirmado ){

                                terminal.crearBoton("Confirmar",x-16,y+20,opc==3);
                                terminal.crearBoton("Cancelar",x+16,y+20,opc==4);

                                switch(rlutil::getkey()){
                                    case 16:
                                        opc--;
                                        if(opc < 0) opc = 3;
                                        break;
                                    case 17:
                                        opc++;
                                        if(opc > 2) opc = 4;
                                        break;
                                    case 1:

                                        if( opc == 4){

                                            confirmado = true;
                                            break;
                                        }

                                        if(opc == 3){
                                            confirmado = true;
                                            break;
                                        }
                                }
                            }

                            //Si pongo salir, salgo del primer while
                            if( opc == 4){
                                terminal.pintarRectangulo(34,2,27,80);
                                terminal.mostrarTexto(">Modificacion de articulo cancelada",x,y);
                                return;
                            };




                            bool modificar = archiComida.modificarRegistro(comida,idEncontrado);

                            terminal.pintarRectangulo(34,2,27,80);

                            if( modificar )
                            {
                                terminal.mostrarTexto(">Precio modificado correctamente",x,y);
                                return;
                            }else{
                                terminal.mostrarTexto(">Error al borrar modificar precio",x,y);
                                return;
                            }


                        }else{

                            terminal.pintarRectangulo(34,2,27,80);

                            terminal.mostrarTexto("No se encontro el articulo.",x,y);
                            return;
                        }
                    }

                    if(opc == 1){
                        Bebida bebida;

                        terminal.pintarRectangulo(34,2,27,80);

                        terminal.mostrarTexto("Ingrese el id del articulo: ",x,y);
                        id = terminal.ingresarTexto(x + 30,y ,true);

                        //Busco el registro;
                        idEncontrado = archiBebida.buscarRegistro(std::atoi(id.c_str()));
                        bebida = archiBebida.leerRegistro(idEncontrado);


                        if( idEncontrado >= 0 && bebida.getEstado() ){

                            terminal.pintarRectangulo(34,2,27,80);





                            terminal.mostrarTexto("Esta seguro que desea modificar el precio del siguiente articulo?",x,y);
                            terminal.mostrarTexto("ID: " + std::to_string(bebida.getID()) ,x,y+4);
                            terminal.mostrarTexto("Nombre: " + bebida.getNombre(),x,y+6);
                            terminal.mostrarTexto("Precio: " + std::to_string(bebida.getPrecioInicial()),x,y+8);
                            terminal.mostrarTexto("Costo: " + std::to_string(bebida.getCosto()),x,y+10);

                            terminal.mostrarTexto("Ingresar nuevo precio: ",x,y+14);

                            precio = terminal.ingresarTexto(x+15,y+14,true);


                            bebida.setPrecioInicial( std::atof(precio.c_str()) );

                            bool confirmado = false;

                            while( !confirmado ){

                                terminal.crearBoton("Confirmar",x-16,y+20,opc==3);
                                terminal.crearBoton("Cancelar",x+16,y+20,opc==4);

                                switch(rlutil::getkey()){
                                    case 16:
                                        opc--;
                                        if(opc < 0) opc = 3;
                                        break;
                                    case 17:
                                        opc++;
                                        if(opc > 2) opc = 4;
                                        break;
                                    case 1:

                                        if( opc == 4){

                                            confirmado = true;
                                            break;
                                        }

                                        if(opc == 3){
                                            confirmado = true;
                                            break;
                                        }
                                }
                            }

                            //Si pongo salir, salgo del primer while
                            if( opc == 4){
                                terminal.pintarRectangulo(34,2,27,80);
                                terminal.mostrarTexto(">Modificacion de articulo cancelada",x,y);
                                return;
                            };




                            bool modificar = archiBebida.modificarRegistro(bebida,idEncontrado);

                            terminal.pintarRectangulo(34,2,27,80);

                            if( modificar )
                            {
                                terminal.mostrarTexto(">Precio modificado correctamente",x,y);
                                return;
                            }else{
                                terminal.mostrarTexto(">Error al borrar modificar precio",x,y);
                                return;
                            }


                        }else{

                            terminal.pintarRectangulo(34,2,27,80);

                            terminal.mostrarTexto("No se encontro el articulo.",x,y);
                            return;
                        }
                    }


                    if( opc == 2 )
                    {
                        terminal.pintarRectangulo(34,2,27,80);
                        return;
                    }

                }
            }


        }
}


void AppManager::BuscarArticulo(){

 Terminal terminal;

    terminal.pintarRectangulo(34,2,27,80);
    int x=60;
    int y=4;

    ArchivoComida archiComida = "comidas.dat";
    ArchivoBebida archiBebida = "bebidas.dat";


    std::string id;
    int opc = 0, idEncontrado = -1;

    while(true){

        terminal.crearBoton("Buscar comida",x,y,opc==0);
        terminal.crearBoton("Buscar bebida",x,y+8,opc==1);
        terminal.crearBoton("Volver",x,y+16,opc==2);

        switch(rlutil::getkey()){
            case 14:
                opc--;
                if(opc < 0) opc = 2;
                break;
            case 15:
                opc++;
                if(opc > 2) opc = 0;
                break;
           case 1:
                {


                   if(opc == 0){
                        Comida comida;

                        terminal.pintarRectangulo(34,2,27,80);

                        terminal.mostrarTexto("Ingrese el id del articulo: ",x,y);
                        id = terminal.ingresarTexto(x + 30,y ,true);

                        //Busco el registro;
                        idEncontrado = archiComida.buscarRegistro(std::atoi(id.c_str()));
                        comida = archiComida.leerRegistro(idEncontrado);


                        if( idEncontrado >= 0 && comida.getEstado() ){

                            terminal.pintarRectangulo(34,2,27,80);





                            terminal.mostrarTexto("Esta seguro que desea modificar el precio del siguiente articulo?",x,y);
                            terminal.mostrarTexto("ID: " + std::to_string(comida.getID()) ,x,y+4);
                            terminal.mostrarTexto("Nombre: " + comida.getNombre(),x,y+6);
                            terminal.mostrarTexto("Precio: " + std::to_string(comida.getPrecioInicial()),x,y+8);
                            terminal.mostrarTexto("Costo: " + std::to_string(comida.getCosto()),x,y+10);
                        }
                   }
                }
        }
    }
}

void AppManager::GenerarBackup(){
    Terminal terminal;
    terminal.pintarRectangulo(34,2,27,80);
    rlutil::anykey();
}

void AppManager::CargarBackup(){
    Terminal terminal;
    terminal.pintarRectangulo(34,2,27,80);
    rlutil::anykey();
}

void AppManager::Reportes(){
    Terminal terminal;
    terminal.pintarRectangulo(34,2,27,80);
    rlutil::anykey();;
}


