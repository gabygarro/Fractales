#define A 1

//#include "LinkedList.h"

///Esta clase genera una lista (implementada con listas enlazadas) que luego se va a pasar a otra clase que
///se encarga de dibujar la curva del dragón a partir de la lista.
class ListaCurvaDragon
{
private:
    LinkedList<char> lista;
    LinkedList<int> comandos;
    int profundidad;

public:
    ListaCurvaDragon(int pProf= 13)
    {
        profundidad=pProf;
        lista.append('D');
        generarLista();
        generarComandos();
    }


    void generarLista()
    {
        for(int i=0; i<profundidad ; i++)
        {
            for(lista.goToStart(); lista.getPos()<lista.getSize(); lista.next())
            {
                lista.insert('D');
                lista.next();
                lista.next();
                lista.insert('I');
                lista.next();
            }
        }
    }

    LinkedList<char> getLista(){
        return lista;
    }

    ~ListaCurvaDragon(){
        lista.~LinkedList();
        comandos.~LinkedList();
    }

    void clear(){
        lista.clear();
        comandos.clear();
    }

    void generarComandos(){
        for(lista.goToStart(); lista.getPos()<lista.getSize(); lista.next()){
            comandos.append(A);
            if (lista.getElement()=='D'){
                comandos.append(-90);
            }
            else{
                comandos.append(90);
            }

        }
        comandos.append(A);
        }


    LinkedList <int> getComandos(){
        return comandos;
    }

    int getProf(){
        return profundidad;
    }
};

