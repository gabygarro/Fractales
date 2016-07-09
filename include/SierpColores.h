#include <math.h>
#define _USE_MATH_DEFINES
#include <winbgim.h>
#include <cmath>


class SierpColores
{
private:
    int longLinea;
    LinkedList<int>* comandos;
    int dir;


public:
     void linea(Punto P, Punto Q){
            line(P.x, P.y, Q.x, Q.y);
    }

    SierpColores(LinkedList<int>* pComandos, int pLongLinea, int pDir)
    {
        ///pX y pY son las cordenadas de la pantalla donde está el primer punto del fractal
        comandos=pComandos;
        longLinea=pLongLinea;
        //dir= ANG(pDir);
        dir=pDir;

    }

    void dibujar(int* x0, int* y0){

        Punto P;
        Punto Q;
        P.x=*x0;
        P.y=*y0;
        P.desp=longLinea;

        int elem;

        int size = comandos->getSize();
        int i=1;
        int color = 0;
        int colores[7]= {COLOR(255,0,0),COLOR(255,165,0),COLOR(255,255,0),COLOR(0,128,0),COLOR(0,0,255),COLOR(075,0,130),COLOR(138,130,238)};
        for(comandos->goToStart();comandos->getPos()<comandos->getSize();comandos->next()){
            elem = comandos->getElement();
            i++;
            setcolor(colores[color]);
            if (i==size/7){
                i=0;
                color++;
            }

            Q.duplicar(P);
            double dirRad=dir*(M_PI/180);
            if (elem == 1){
                Q.horizontal(longLinea*cos(dirRad));
                Q.vertical(longLinea*sin(dirRad));
                linea(P,Q);
            }
            else{
                dir+=elem;
            }
            P=Q;
        }

    }
    };
