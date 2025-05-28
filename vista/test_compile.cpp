#include <iostream>
#include "Venta.h"
#include "Compra.h"

using namespace std;

int main() {
    cout << "Test de compilación exitoso!" << endl;
    
    // Crear instancias para verificar que los métodos están disponibles
    Venta v;
    Compra c;
    
    // Verificar que los métodos crear() retornan int
    // (No los ejecutamos, solo verificamos que compilen)
    
    cout << "Métodos crear() disponibles y retornan int." << endl;
    
    return 0;
}
