#include<iostream>
#include<string>
using namespace std; 

//STRUCT
struct Informacion //variables que utilizaremos.
{
    int id;
    string nombre, perfil;
};

Informacion solicitar_datos(void) //Insercion de datos.
{
    Informacion p;
    cout << "Ingrese su id: ";
    cin >> p.id;
    cin.ignore(1000,'\n');
    cout << "Ingrese su nombre: ";
    getline (cin, p.nombre);
    cout << "Ingrese su perfil (administrador, cliente o trabajador): ";
    getline (cin, p.perfil);   
    
    return p;
}
void mostrar_Informacion(Informacion p)
{
    cout << endl;
    cout << "id: " << p.id << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "perfil: " << p.perfil << endl;
}

typedef Informacion P;
const P noValido = {0};

struct nodo
{
    P dato;
    nodo *sig;
    nodo *ant;
};

class Datos
{
    private:
        nodo *inicio;

    public:
        Datos();
        ~Datos();
        void ingresar_adelante(P);
        void ingresar_atras(P);
        void imprimir(void);
        void imprimir_reversa(void);
        void borrar_adelante(P); 
        void borrar_atras(P); 
        bool empty(void);
};

Datos::Datos(void)
{
    inicio = NULL;
}

Datos::~Datos()
{
    nodo *a;
    while(inicio){
        a = inicio;
        inicio = inicio->sig;
        delete a;
    }
}

void Datos::ingresar_adelante(P dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = inicio;
    if(inicio != NULL)
        inicio->ant = nuevo;
    inicio = nuevo;
}

void Datos::ingresar_atras(P dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!inicio){
        inicio = nuevo;
        inicio->sig = inicio->ant = NULL;
    }
    else{
        nodo *saltarin = inicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void Datos::imprimir(void)
{
    nodo *saltarin = inicio;
    while(saltarin != NULL)
    {
        mostrar_Informacion(saltarin->dato);
        saltarin = saltarin->sig;
    }
}

void Datos::imprimir_reversa(void)
{
    if(!inicio)
        return;
    nodo *a = inicio;
    nodo *q = NULL;
    while(a)
    {
        q = a;
        a = a->sig;
    }
    while(q)
    {
        mostrar_Informacion(q->dato);
        q = q->ant;
    }
}

void Datos::borrar_adelante(P datoB)
{
    if(!inicio){
        cout << "Actualmente no hay Informaciones." << endl;
    } else { 
        nodo *aux = NULL;

        while(inicio->sig){
            if(inicio->ant) cout << inicio->ant << endl;
            inicio = inicio->sig;
        }
        aux = inicio->ant;
        aux->sig = NULL;
        delete(inicio);
        inicio = aux;
        while(inicio->ant)
        {
            inicio = inicio->ant;
        }
        cout << "Informacion eliminado!" << endl;
    }
}

void Datos::borrar_atras(P datoB)
{   
    if(!inicio){ 
        cout << "Actualmente no hay Informacion almacenada." << endl;
    } else { 
        nodo *aux = inicio;

        if(aux->sig){
            aux = inicio->sig;
            aux->ant = NULL;
            delete inicio;
            inicio = aux;
        }
        cout << "Informacion eliminada exitosamente." << endl;
    }
}

bool Datos::empty(void){
    return inicio == NULL;
}


int main(void)
{
    Datos data;

    int opcion = 0;
    bool continuar = true;
    Informacion p;

    do
    {
        cout << endl << "MENU DE DATOS" << endl << endl;
        cout << "1.Ingresar datos al inicio" << endl;
        cout << "2.Ingresar datos al final" << endl;
        cout << "3.Mostrar datos en orden" << endl;
        cout << "4.Mostrar datos en reversa" << endl;
        cout << "5.Borrar al inicio" << endl;
        cout << "6.Borrar al final" << endl;
        cout << "7.Salir" << endl << endl;

        cout << "opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                p = solicitar_datos();
                data.ingresar_adelante(p);
                cout << endl << "Datos almacenados exitosamente!" << endl;
            break;

            case 2:
                p = solicitar_datos();
                data.ingresar_atras(p);
                cout << endl << "Datos almacenados exitosamente!" << endl;
            break;

            case 3:
                data.imprimir();
            break;

            case 4:
                data.imprimir_reversa();
            break;

            case 5:
                if(data.empty())
                    cout << "Actualmente no hay Informaciones" << endl;
                else{
                    data.borrar_atras(p);
                }
            break;

            case 6:
                if(data.empty())
                    cout << "Actualmente no hay Informaciones" << endl;
                else{
                    data.borrar_adelante(p);
                }
            break;

            case 7:
                continuar = false;
                system ("cls");
                cout << "Gracias por preferirnos!" << endl << endl;
            break;

            default:
                cout << "La opcioncion invalida, favor intente de nuevo." << endl;
            break;
        }
    }while (continuar);

return 0;
}