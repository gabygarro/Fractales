#include <winbgim.h>
#include "Punto.h"
class CurvaDragon
{
private:
    LinkedList<char> lista;
    int prof;
    int anchoPantalla, altoPantalla, longLinea;
    Punto P;
    //ARRIBA, ABAJO, DERECHA, IZQUIERDA;
    enum DIRS{ARR, ABA, DER, IZQ};
    DIRS dir;


    int calcularLongLinea(){
       if (prof==1){
           return 100;
       }else if (prof==2){
           return 10;
       }else if (prof==13){
           return 3;
       }
        return 0;
    }

    void linea(Punto A, Punto B){
            line(A.x, A.y, B.x, B.y);
        }



public:

        CurvaDragon(ListaCurvaDragon pLista, int pDir) {
            lista=pLista.getLista();
            prof=pLista.getProf();
            altoPantalla=anchoPantalla=700;
            P= Punto (anchoPantalla/2, altoPantalla/2);
            P.desp=longLinea=20;




            dir=DIRS(pDir);



        }



        void dibujar(){
            Punto Q;
            Q.duplicar(P);
            Q.arriba();
            linea(P,Q);
            P=Q;
            int tam=lista.getSize();
            char elem;
            lista.goToStart();
            for(lista.goToStart();lista.getPos()<lista.getSize();lista.next()){
                elem = lista.getElement();
                Q.duplicar(P);
                cout<<"Apunta a "<<DIRS{dir}<<" y se mueve a la "<<elem<<endl;
                if (dir == ARR){
                    if (elem == 'D'){
                        Q.der();
                        dir=DER;
                    }
                    else if (elem =='I'){
                        Q.izq();
                        dir=IZQ;
                    }
                }
                else if (dir == ABA){
                    if (elem == 'D'){
                        Q.izq();
                        dir=IZQ;
                    }
                    else if (elem =='I'){
                        Q.der();
                        dir=DER;
                    }
                }
                else if ( dir == DER){
                    if (elem == 'D'){
                        Q.abajo();
                        dir=ABA;
                    }
                    else if (elem =='I'){
                        Q.arriba();
                        dir=ARR;
                    }
                }
                else if ( dir == IZQ){
                    if (elem == 'D'){
                        Q.arriba();
                        dir=ARR;
                    }
                    else if (elem =='I'){
                        Q.abajo();
                        dir=ABA;
                    }
                }
                linea(P,Q);
                P=Q;
            }

        }

    };
