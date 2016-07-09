#include <winbgim.h>
#include <iostream>
#include "LinkedList.h"
#include "ListaCurvaDragon.h"
#include "ListaSierpisnky.h"
#include "ListaLevyC.h"
#include "Fractal.h"
#include "Colores.h"

/*
**Declaracion de funciones que llama el main para dibujar los diferentes tipos de fractales
*/
int tradicional();//solicita tipo de fractal y profundidad y lo dibuja en color blanco
int colores();  //solicita tipo de fractal y profundidad y lo dibuja con colores del arcoiris
int cuatroDragones(); //dibuja cuatro fractales del dragon (4 colores) en diferentes direcciones
int main();
int variosTriangulos();//dibuja varios triángulos de sierpisnki, que se van moviendo a la derecha (alterna azul/blanco)


int main(){
    boolean ficar;
    ficar=true;
    cout<<"Seleccione una opcion:\n0.Salir";
    cout<<"\n1.Tradicional (un solo fractal de color blanco)."<<endl;
    cout<<"2. A colores (Un solo fractal de varios colores)"<<endl;
    cout<<"3. Otros disenos\nOpcion: ";
    int opcion;
    cin>>opcion;
    switch (opcion){
    case 0:
        ficar = false;
    case 1:
        tradicional();
    case 2:
        colores();

    case 3:
        int i;
        cout<<"\n\n1.Cuatro fractales dragon"<<endl;
        cout<<"\n2.Varios triangulos"<<endl;
        cin>>i;
        switch(i){
        case 1:
            cuatroDragones();

        case 2:
            variosTriangulos();

        }

    }
}

int variosTriangulos(){
    initwindow(2000,500);//ventana ancha
    ListaSierpisnky lista = ListaSierpisnky(7);
    LinkedList<int> comandos = lista.getComandos();
    Fractal fractal = Fractal (&comandos,3,60);//Fractal (listaComandos, longitudLienaFractal, DireccionInicioEnAngulos (e.g. 60°))
    int x=0, y=0; //posicion donde comienza el fractal
    int c=0; //contador de triangulos dibujads
    while (c++<9){
        setcolor(15); //blanco
        fractal.dibujar(&x, &y);
        x+=85;//correo la posicion a la derecha para el nuevo triángulo
        setcolor(1);//azul
        fractal.dibujar(&x, &y);
        x+=85;
    }
    cout<<"\nPresione cualquier tecla para cerrar la pantalla de dibujo\n";
    cin.get();cin.get();
    closegraph();
    main();
}

int cuatroDragones(){
    cout<<"\nProfundidad:";
    int prof;
    cin>>prof;
    if (prof>=16){
        cout<<"Profundidad inválida (muy grande)\n";
        //main();
    }
    ListaCurvaDragon lis = ListaCurvaDragon(prof);
    LinkedList<int> comandos =lis.getComandos();
    initwindow(800,800);
    Fractal f1 = Fractal(&comandos, 3, 90);
    Fractal f2 = Fractal(&comandos, 3, 0);
    Fractal f3 = Fractal(&comandos, 3, 180);
    Fractal f4 = Fractal(&comandos, 3, 270);
    //Posicion en pantalla donde se empiezan a dibujar los fractales (x,y):
    int x=400;
    int y=400;

    setcolor(1);//azul
    f1.dibujar(&x,&y);
    setcolor(4);//rojo
    f2.dibujar(&x,&y);
    setcolor(10);//verde
    f3.dibujar(&x,&y);
    setcolor(14);//amarillo
    f4.dibujar(&x,&y);
    cout<<"\nPresione cualquier tecla para cerrar la pantalla de dibujo\n";
    cin.get();
    cin.get();//captura si se presiona una tecla
    closegraph();//cierra la pantalla
    //main();
}

void close(){
    closegraph();
}

int colores(){
    int anchoPantalla=800;
    int altoPantalla=800;
    int x, y, prof;
    LinkedList<int> comandos;
    cout<<"\nElija el fractal: \n1.Dragon\n2.Sierpinsky\n3.C"<<endl;
    cin>>x;
    cout<<"\nProf: "<<endl;
    cin>>prof;
    initwindow(anchoPantalla, altoPantalla);
    if (x==1){
            if (prof>=16){
                closegraph();
                cout<<"Profundidad demasiado grande\n\n";
                //main();
            }
        ListaCurvaDragon lista =ListaCurvaDragon(prof);
        LinkedList<int> comandos = lista.getComandos();
        Colores fractal = Colores (&comandos, 3, 90);
        x=anchoPantalla/2+100;
        y=altoPantalla/2-100;
        fractal.dibujar(&x, &y);
        cout<<"\nPresione cualquier tecla para cerrar la pantalla de dibujo\n";
        cin.get();cin.get();
        closegraph();
        //main();
    }
    else if( x== 2){
            if (prof>=8){
                closegraph();
                cout<<"Profundidad demasiado grande\n\n";
                //main();
            }
        int dir;
        ListaSierpisnky lista =ListaSierpisnky(prof);
        LinkedList<int> comandos = lista.getComandos();
        if (prof%2){//si la profujndidad es par.
            dir=60;
        }
        else{
            dir=240;

        }
        Colores fractal = Colores (&comandos, 3, dir);


        if (prof%2){
            setcolor(1);
            x=anchoPantalla/2;
            y=0;
            fractal.dibujar(&x, &y);
            cout<<"\nPresione cualquier tecla para cerrar la pantalla de dibujo\n";
            cin.get();cin.get();
            closegraph();
            //main();
        }
        else{
            x=2*anchoPantalla/3;
            y=3*altoPantalla/4;
            fractal.dibujar(&x, &y);
            cout<<"\nPresione cualquier tecla para cerrar la pantalla de dibujo\n";
            cin.get();cin.get();
            closegraph();
            //main();
        }


    }
    else if (x==3){
            if (prof>=16){
                closegraph();
                cout<<"Profundidad demasiado grande\n\n";
                //main();
            }
        ListaLevyC lista =ListaLevyC(prof);
        LinkedList<int> comandos = lista.getComandos();
        Colores fractal = Colores (&comandos, 3, 90);
        x= anchoPantalla/2;
        y=altoPantalla/3;
        fractal.dibujar(&x,&y);
        cout<<"\nPresione cualquier tecla para cerrar la pantalla de dibujo\n";
        cin.get();cin.get();
        closegraph();
        //main();
    }

}

int tradicional(){
    int anchoPantalla=800;
    int altoPantalla=800;
    int x, y, prof;
    LinkedList<int> comandos;
    cout<<"1.Dragon\n2.Sierpinsky\n3.C"<<endl;
    cin>>x;
    cout<<"\nProf: "<<endl;
    cin>>prof;
    initwindow(anchoPantalla, altoPantalla);
    if (x==1){
            if (prof>=15){
                closegraph();
                cout<<"Profundidad demasiado grande\n\n";
                //main();
            }
        ListaCurvaDragon lista =ListaCurvaDragon(prof);
        LinkedList<int> comandos = lista.getComandos();
        Fractal fractal = Fractal (&comandos, 3, 90);
        x=anchoPantalla/2;
        y=altoPantalla/2;
        fractal.dibujar(&x, &y);
        cin.get();cin.get();
        closegraph();
        //main();
    }
    else if( x== 2){
        if (prof>=8){
                closegraph();
                cout<<"Profundidad demasiado grande\n\n";
                //main();
            }
        int dir;
        ListaSierpisnky lista =ListaSierpisnky(prof);
        LinkedList<int> comandos = lista.getComandos();
        if (prof%2){//si la profujndidad es par.
            dir=60;
        }
        else{
            dir=240;

        }
        Fractal fractal = Fractal (&comandos, 3, dir);
        if (prof%2){
            x=anchoPantalla/2;
            y=0;
            fractal.dibujar(&x, &y);
            cout<<"\nPresione cualquier tecla para cerrar la pantalla de dibujo\n";
            cin.get();cin.get();
            closegraph();
            //main();
        }
        else{
            x=2*anchoPantalla/3;
            y=3*altoPantalla/4;
            fractal.dibujar(&x, &y);
            cout<<"\nPresione cualquier tecla para cerrar la pantalla de dibujo\n";
            cin.get();cin.get();
            closegraph();
            //main();
        }


    }
    else if (x==3){
            if (prof>=16){
                closegraph();
                cout<<"Profundidad demasiado grande\n\n";
                //main();
            }
        ListaLevyC lista =ListaLevyC(prof);
        LinkedList<int> comandos = lista.getComandos();
        Fractal fractal = Fractal (&comandos, 3, 90);
        x= anchoPantalla/2;
        y=altoPantalla/3;
        fractal.dibujar(&x,&y);
        cout<<"\nPresione cualquier tecla para cerrar la pantalla de dibujo\n";
        cin.get();cin.get();cin.get();
        closegraph();
        //main();
    }


    }


