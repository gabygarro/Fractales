
class Punto
{
public:
    int x, y;
    int desp;


        Punto(){}

        Punto(int pX, int pY, int pDesp){
            x=pX;
            y=pY;
            desp=pDesp;
        }

        void duplicar(Punto pPunto){
            x=pPunto.x;
            y=pPunto.y;
            desp=pPunto.desp;
        }


        void vertical(int pY){
            y+=pY;

        }

        void horizontal(int pX){
            x+=pX;
        }

};
