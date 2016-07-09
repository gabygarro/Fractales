#define A 1


class ListaLevyC
{
private:
    LinkedList<char> lista;
    LinkedList <int> comandos;
    int profundidad;

public:
    ListaLevyC(int pProf=10){//DEFAULT_PROF){

        lista.append('A');
        profundidad=pProf;
        generarLista();
        generarComandos();

    }

    ~ListaLevyC(){
        lista.~LinkedList();
        comandos.~LinkedList();
    }

    void clear(){
        lista.clear();
        comandos.clear();
    }

    void generarLista(){
        for (int i=0; i<profundidad; i++){
            for(lista.goToStart();lista.getPos()<lista.getSize();lista.next()){
                if(lista.getElement()=='A'){
                    lista.insert('D');
                    lista.next();//se salta la A, porque ya esta dentro de la lista
                    lista.next();
                    lista.insert('I');
                    lista.next();
                    lista.insert('I');
                    lista.next();
                    lista.insert('A');
                    lista.next();
                    lista.insert('D');
                }
            }
        }
    }
    LinkedList<char> getLista(){
        return lista;
    }

    void generarComandos(){
        for(lista.goToStart(); lista.getPos()<lista.getSize(); lista.next()){
            if (lista.getElement()=='D'){
                comandos.append(-45);
            }
            else if (lista.getElement() == 'I') {
                comandos.append(45);
            }
            else{
                comandos.append(A);
            }
        }
    }

    LinkedList <int> getComandos(){
        return comandos;
    }

    int getProf(){
        return profundidad;
    }

};
