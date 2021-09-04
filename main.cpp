#include <iostream>
#include <conio.h>
#include "Sim.h"
#include "LinkedDouble.cpp"
#include "Gestion.h"
#include "Node.h"
using namespace std;
int main() {
    int menu=0;
    do{
    cout<<"\n|---------------------------|";
    cout<<"\n|        SIM                |";
    cout<<"\n|---------------------------|";
    cout<<"\n|      1.Agregar            |";
    cout<<"\n|      2.Buscar             |";
    cout<<"\n|      3.Eliminar           |";
    cout<<"\n|      4.Cantidad           |";
    cout<<"\n|      5.Mostrar Lista      |";
    cout<<"\n|      6.Salir              |";
    cout<<"\n|---------------------------|";
    cout<<"\n\nDigite la opcion que desee: ";
    cin>> menu;
        //1-2-3-4
        LinkedDouble<Sim>* linked = new LinkedDouble<Sim>();
        linked->addNodeFirst(Sim("2","3163049613","Movistar"));
        linked->addNodeFirst(Sim("1","3163049913","Claro"));
        linked->addNodeLast(Sim("3","3183274799","Tigo"));
        linked->addNodeLast(Sim("4","3153048613","Movi"));

       Gestion *gestion = new Gestion();


    switch (menu) {
        case 1:{
            int agregar;
            string tel, id, marca;
            cout<<"1.Agregar una sim al principio de la lista"<<endl;
            cout<<"2.Agregar una sim al final de la lista"<<endl;
            cout<<"3.Agregra una sim antes de otra"<<endl;
            cout<<"4.Agregar una sim despues de otra"<<endl;
            cout<<"5.Agregar varias sims por orden de su Id"<<endl;
            cout<<"\nDigite la opcion que desee: "<<endl;
            cin>>agregar;
            if (agregar==1){
                cout<<"Digite los datos de la SIM"<<endl;
                cout<<"Digite el id: "<<endl;
                cin>>id;
                cout<<"Digite numero telefonico: "<<endl;
                cin>>tel;
                cout<<"Digite marca: "<<endl;
                cin>>marca;
                gestion->addNodeFirst(Sim(id,tel,marca));
                cout<<endl;
                cout<<"LISTA CON LA SIM AGREGADA AL PRINIPIO"<<endl;
                cout<<endl;
                cout<<gestion->viewList();
                getch();
            }else if (agregar ==2){
                cout<<"Digite los datos de la SIM"<<endl;
                cout<<"Digite el id: "<<endl;
                cin>>id;
                cout<<"Digite numero telefonico: "<<endl;
                cin>>tel;
                cout<<"Digite marca: "<<endl;
                cin>>marca;
                gestion->addNodeLast(Sim(id,tel,marca));
                cout<<endl;
                cout<<"LISTA CON LA SIM AGREGADA AL FINAL"<<endl;
                cout<<endl;
                cout<<gestion->viewList();
            }else if(agregar == 3){
                string idAfter;
                cout<<"Digite el id de la SIM despues: "<<endl;
                cin>>idAfter;
                cout<<"Digite los datos de la SIM"<<endl;
                cout<<"Digite el id: "<<endl;
                cin>>id;
                cout<<"Digite numero telefonico: "<<endl;
                cin>>tel;
                cout<<"Digite marca: "<<endl;
                cin>>marca;
                cout<<gestion->addNodeAfterTo(id,Sim(id,tel,marca));
                cout<<gestion->viewList();
            }else if (agregar == 4){
                string idAfter;
                /*cout<<"Digite el id de la SIM antes: "<<endl;
                cin>>idAfter;
                cout<<"Digite los datos de la SIM"<<endl;
                cout<<"Digite el id: "<<endl;
                cin>>id;
                cout<<"Digite numero telefonico: "<<endl;
                cin>>tel;
                cout<<"Digite marca: "<<endl;
                cin>>marca;*/
               /* Node<Sim>* encontrar = linked->findNode("4");
                cout<<gestion->addNodeBeforTo("4",Sim("9","33232","eeewe"));
                cout<<gestion->viewList();*/
                /*if (encontrar==NULL){
                    cout<<"No es por sible agregarlo"<<endl;
                }else{
                    linked->addNodeBeforeTo(encontrar, Sim(id,tel,marca));
                    cout<<endl;
                    cout<<"LISTA CON LA SIM DESPUES DE..."<<endl;
                    cout<<endl;
                    for (Sim sim: linked->getList(true)) {
                        cout<<sim<<endl;
                    }
                }*/
            }else if (agregar == 5){
                /*linked->addNodeSorted(Sim("5","3163049613","movi"));
                linked->addNodeSorted(Sim("1","3183274799","movistar"));
                linked->addNodeSorted(Sim("7","3156788888","claro"));
                linked->addNodeSorted(Sim("9","3175656556","wow"));
                linked->addNodeSorted(Sim("2","3198777666","tigo"));
                cout<<"La lista de la SIM: "<<endl;
                for (Sim sim: linked->getList(true)) {
                    cout<<sim<<endl;
                }*/
                cout<<"Digite los datos de la SIM"<<endl;
                cout<<"Digite el id: "<<endl;
                cin>>id;
                cout<<"Digite numero telefonico: "<<endl;
                cin>>tel;
                cout<<"Digite marca: "<<endl;
                cin>>marca;
                gestion->addNodeSorted(Sim(id,tel,marca));
                cout<<gestion->viewList();
                //linked->addNodeSorted(Sim(id,tel,marca));
               // cout<<"La lista con la sim que acabo de digitar: "<<endl;
                /*for (Sim sim: linked->getList(false)) {
                    cout<<sim<<endl;
                }*/
            }else{
                cout<<"Ha digitado una opcion erronea"<<endl;
            }
        }
            break;
        case 2:{
            int find;
            string idFind;
           cout<<"1.Buscar si existe una SIM"<<endl;
           cout<<"2.Buscar una SIM y su informacion"<<endl;
           cout<<"3.Buscar la primera SIm de la lista"<<endl;
           cout<<"4.Buscar la ultima Sim de la lista"<<endl;
           cout<<"5.Buscar la Sim numero n de la lista"<<endl;
           cin>>find;
            if (find==1){
                cout<<"Digite el Id de la SIM que desee encontrar: "<<endl;
                cin>>idFind;
                Node<Sim>* found = linked->findNode(idFind);
                if (found==NULL){
                    cout<<"No fue encontrada la SIM con Id "<<idFind<<endl;
                } else{
                    cout<<"La SIM si fue encontrada con Id "<<idFind<<endl;
                }
            }else if (find ==2){
                cout<<"Digite el Id de la SIM que desee encontrar: "<<endl;
                cin>>idFind;
                Sim* findSim = linked->findInfo(idFind);
                if (findSim == NULL){
                    cout<<"No se enuentra la SIM con Id "<<idFind;
                }else{
                   cout<<"Si fue encontrada, la informacion es:\n"<<*findSim;
                }
            }else if (find == 3){
                cout<<"Primer SIM en lista:\n"<<linked->getFirst()<<endl;
            }else if (find == 4){
                cout<<"Ultima SIM en lista:\n"<<linked->getLast()<<endl;
            }else if (find == 5){
               Sim* found = linked->getObject(6);
                if (found != NULL){
                    cout<<*found<<endl;
                }else{
                    cout<<"No se encuentra"<<endl;
                }
            }else{
                cout<<"Ha digitado una opcion erronea"<<endl;
            }
        }
            break;
        case 3:{
            string idEliminar;
            cout<<"Digite el Id del nodo que desee eliminar: "<<endl;
            cin>>idEliminar;
            Node<Sim>* found=linked->findNode(idEliminar);
            linked->deleteNode(found);
            for (Sim sim: linked->getList(true)) {
                cout<<sim<<endl;
            }
        }
            break;
        case 4:
            cout<<"La cantidad de SIM existente es "<<linked->getSize()<<endl;
            break;
        case 5:
            cout<<"Esta es la lista de SIMS: "<<endl;
            for (Sim sim: linked->getList(true)) {
                cout<<sim<<endl;
            }
            break;
        case 6:
            cout<<"Ha salido del programa";
            exit(0);
        default:
            break;
    }
    }while(menu != 6);
    return 0;
}
