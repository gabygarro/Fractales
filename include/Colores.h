#include <math.h>
#define _USE_MATH_DEFINES
//#include "Punto.h"
#include <winbgim.h>
#include <cmath>


class Colores
{
private:
    int longLinea;
    LinkedList<int>* comandos;
    int dir;


public:
     void linea(Punto P, Punto Q){
            line(P.x, P.y, Q.x, Q.y);
    }

    Colores(LinkedList<int>* pComandos, int pLongLinea, int pDir)
    {
        ///pX y pY son las cordenadas de la pantalla donde está el primer punto del fractal
        comandos=pComandos;
        longLinea=pLongLinea;
        dir=pDir;

    }

    ~Colores(){
        delete comandos;
    }

    void dibujar(int* x0, int* y0){

        Punto P;
        Punto Q;
        P.x=*x0;
        P.y=*y0;
        P.desp=longLinea;

        int elem;

        int size = comandos->getSize();//cantidad de comandos enteros
        int i=1;//contador
        int color = 0;//indice para el siguiente arreglo:
        //Array de los 12 colores que va a tener el fractal
        int colores[12]= {COLOR(255,0,0),COLOR(255,125,0),COLOR(255,255,0),COLOR(125,255,0),COLOR(0,255,0),COLOR(0,255,125),COLOR(0,255,255),COLOR(0,125,255),COLOR(0,0,255),COLOR(125,0,255),COLOR(255,0,255),COLOR(255,0,125)};
        for(comandos->goToStart();comandos->getPos()<comandos->getSize();comandos->next()){
            elem = comandos->getElement();
            i++;//se aumenta el contador de comandos
            setcolor(colores[color]);

            if (i==size/12){//cada vez que se ha abarcado una doceava parte de los comandos
                i=1;//se reinicia el contador
                color++;//se cambia el colore
            }

            Q.duplicar(P);
            double dirRad=dir*(M_PI/180);
            if (elem == 1){//se dibuja la linea
                Q.horizontal(longLinea*cos(dirRad));
                Q.vertical(longLinea*sin(dirRad));
                linea(P,Q);

            }
            else{//se cambia la direccion
                dir+=elem;

            }
            P=Q;
        }
    }

};
