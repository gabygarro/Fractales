#include <math.h>
#define _USE_MATH_DEFINES
#include "Punto.h"
#include <winbgim.h>
#include <cmath>


class Fractal
{
private:
    int longLinea;//longitud linea
    LinkedList<int>* comandos;
    int dir; //direccion inicial (angulos)


public:
     void linea(Punto P, Punto Q){
            line(P.x, P.y, Q.x, Q.y);//trazar linea de P(x,y) a Q(x,y);
    }

    Fractal(LinkedList<int>* pComandos, int pLongLinea, int pDir)
    {
        ///pX y pY son las cordenadas de la pantalla donde está el primer punto del fractal
        comandos=pComandos;
        longLinea=pLongLinea;
        dir=pDir;
    }

    ~Fractal(){
        comandos->~LinkedList();
    }

    void dibujar(int* x0, int* y0){

        Punto P;
        Punto Q;
        P.x=*x0;
        P.y=*y0;
        P.desp=longLinea;
        int elem;//elem es el elemento de comandos. Los comandos son enteros

       for(comandos->goToStart();comandos->getPos()<comandos->getSize();comandos->next()){
            elem = comandos->getElement();
            Q.duplicar(P);//Q clona a P
            double dirRad=dir*(M_PI/180);//convierte de grados a radianoes
            if (elem == 1){//1 representa A(Avanzar, dibujar linea...)
                Q.horizontal(longLinea*cos(dirRad));
                Q.vertical(longLinea*sin(dirRad));
                linea(P,Q);
            }
            else{//se cambia la dirección
                dir+=elem;
            }
            P=Q;//Se mueve el punto P a donde está el Q;
        }

    }
    };
