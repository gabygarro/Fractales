#define DEFAULT_PROF 9
#define A 1


class ListaSierpisnky
{
private:
    int profundidad;
    LinkedList<char> lista;
    LinkedList<int> comandos;

public:
    ListaSierpisnky(int pProf=DEFAULT_PROF) {
        profundidad=pProf;
        lista.append('D');
        lista.append('D');
        generarLista();
        generarComandos();
    }

    ~ListaSierpisnky(){
        lista.~LinkedList();
        comandos.~LinkedList();
    }

    void clear(){
        lista.clear();
        comandos.clear();
    }

    void generarLista(){
        char letra;
        for (int i=0; i<profundidad; i++){
            lista.goToStart();
            if(lista.getElement()=='D'){
                letra='I';
            }
            else{
                letra='D';
            }
            for(lista.goToStart();lista.getPos()<lista.getSize();lista.next()){
                lista.insert(letra);
                lista.insert(letra);
                lista.next();
                lista.next();
                if (letra=='D'){
                    letra='I';
                }
                else{
                    letra='D';
                }
            }
            lista.insert(letra);
            lista.insert(letra);
        }
    }

    LinkedList<char> getLista(){
        return lista;
    }

    void generarComandos(){
        for(lista.goToStart(); lista.getPos()<lista.getSize(); lista.next()){
            comandos.append(A);
            if (lista.getElement()=='D'){
                comandos.append(-60);//ClockWise: Negative
            }
            else{
                comandos.append(60);//CounterClockWise: Positive
            }

        }
        comandos.append(A);
        }

    LinkedList<int> getComandos(){
        return comandos;
    }

    int getProf(){
        return profundidad;
    }

};
