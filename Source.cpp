#include <iostream>

using namespace std;
using namespace System;

void listarProducto(int** mat, int n) {
    system("cls");
    cout << " CODIGO | STOCK | PRECIO " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 2) cout << mat[i][j];
            else cout << mat[i][j] << " | ";
        }
        cout << endl;
    }
    system("pause");
}

void calcularPrecio(int** mat, int n) {
    system("cls");
    int valor = 0;
    for (int i = 0; i < n; i++) valor += (mat[i][1] * mat[i][2]);
    cout << "El valor total del inventario es: S/." << valor << endl;
    system("pause");
}

void buscarProducto(int** mat, int n) {
    system("cls");
    string entrada;
    int codigo = 0;
    bool esNumero;
    do {
        cout << "Ingrese el codigo a buscar: ";
        cin >> entrada;
        codigo = 0;
        esNumero = true;
        for (int i = 0; i < entrada.size(); i++) {
            if (!isdigit(entrada[i])) {
                esNumero = false;
                break;
            }
            codigo = codigo * 10 + (entrada[i] - '0');
        }
        if (!esNumero || codigo <= 0) cout << "[X] ERROR: Ingrese un numero valido." << endl;
    } while (!esNumero || codigo <= 0);
    bool encontro = false;
    for (int i = 0; i < n; i++) {
        if (mat[i][0] == codigo) {
            encontro = true;
            break;
        }
    }
    if (encontro) cout << "[Y] EXITO, Se encontro el producto " << codigo << endl;
    else cout << "[X] ERROR, no se encontro el producto " << codigo << endl;
    system("pause");
}


int generaCodigo() {
    Random codigo;
    return codigo.Next(100000, 1000000);
}

void agregarProducto(int**& mat, int& n) {
    string opcion;
    system("cls");
    int precio = 0;
    int stock = 0;
    int** aux = new int* [n + 1];
    for (int i = 0; i < n + 1; i++) aux[i] = new int[3];
    bool esNumero;
    do {
        cout << "Ingrese el precio de su producto: S/.";
        cin >> opcion;
        precio = 0;
        esNumero = true;
        for (int i = 0; i < opcion.size(); i++) {
            if (!isdigit(opcion[i])) {
                esNumero = false;
                break;
            }
            precio = precio * 10 + (opcion[i] - '0');
        }
        if (!esNumero || precio <= 0) cout << "[X] ERROR: Ingrese un numero positivo valido" << endl;
    } while (!esNumero || precio <= 0);
    do {
        cout << "Ingrese el stock del producto: ";
        cin >> opcion;
        stock = 0;
        esNumero = true;
        for (int i = 0; i < opcion.size(); i++) {
            if (!isdigit(opcion[i])) {
                esNumero = false;
                break;
            }
            stock = stock * 10 + (opcion[i] - '0');
        }
        if (!esNumero || stock <= 0) cout << "[X] ERROR: Ingrese un numero positivo valido" << endl;
    } while (!esNumero || stock <= 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            aux[i][j] = mat[i][j];
    }
    for (int i = 0; i < n; i++)
        delete[] mat[i];
    delete[] mat;
    aux[n][0] = generaCodigo();
    aux[n][1] = stock;
    aux[n][2] = precio;
    mat = aux;
    cout << " CODIGO | STOCK | PRECIO " << endl;
    cout << " " << mat[n][0] << " | " << mat[n][1] << " | " << mat[n][2] << endl;
    n++;
    system("pause");
}

void menu(int** mat, int n) {
    string opcion;
    int opc = 0;
    do {
        system("cls");
        int**& refMat = mat;
        int& filas = n;
        cout << "\tGESTION DEL INVENTARIO" << endl;
        cout << "1. Listar productos" << endl;
        cout << "2. Buscar Productos" << endl;
        cout << "3. Calcular valor total" << endl;
        cout << "4. Agregar producto" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        if (opcion.size() == 1 && isdigit(opcion[0])) {
            opc = opcion[0] - '0';
            switch (opc) {
            case 1: listarProducto(mat, n); break;
            case 2: buscarProducto(mat, n); break;
            case 3: calcularPrecio(mat, n); break;
            case 4: agregarProducto(refMat, filas); break;
            case 5:
                system("cls");
                cout << "Saliendo..." << endl;
                break;
            default:
                system("cls");
                opc = 0;
                cout << "[X] ERROR, ingrese una opcion valida" << endl;
                system("pause");
            }
        }
        else {
            system("cls");
            cout << "[X] ERROR: Ingrese un numero valido." << endl;
            system("pause");
        }
    } while (opc != 5);
}

int main() {
    int n = 0;
    int** inventario = new int* [n];
    for (int i = 0; i < n; i++)
        inventario[i] = new int[3];
    int**& ref = inventario;
    int& filas = n;
    menu(inventario, n);
    system("pause");
    return 0;
}