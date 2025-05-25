#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <iomanip>
#include "ConexionBD.h"
#include "Puesto.h"
#include "Marca.h"
#include "Proveedor.h"
#include "Producto.h"
#include "Empleado.h"
#include "Cliente.h"
#include "Compra.h"
#include "Venta.h"

using namespace std;

void limpiarPantalla() {
    system("cls");
}

void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

// Función segura para obtener la fecha y hora actual
string obtenerFechaHoraActual() {
    time_t now = time(0);
    struct tm timeinfo;
    char buffer[80];

    // Usar localtime_s en lugar de localtime
    localtime_s(&timeinfo, &now);

    // Formatear la fecha y hora como YYYY-MM-DD HH:MM:SS
    string fecha = to_string(1900 + timeinfo.tm_year) + "-" +
                  to_string(1 + timeinfo.tm_mon) + "-" +
                  to_string(timeinfo.tm_mday) + " " +
                  to_string(timeinfo.tm_hour) + ":" +
                  to_string(timeinfo.tm_min) + ":" +
                  to_string(timeinfo.tm_sec);

    return fecha;
}



// Funciones para Marca
void menuMarcas();
void ingresarMarca();
void mostrarMarcas();
void actualizarMarca();
void eliminarMarca();

// Funciones para Puesto
void menuPuestos();
void ingresarPuesto();
void mostrarPuestos();
void actualizarPuesto();
void eliminarPuesto();

// Funciones para Proveedor
void menuProveedores();
void ingresarProveedor();
void mostrarProveedores();
void actualizarProveedor();
void eliminarProveedor();

// Implementación de funciones para Proveedor
void menuProveedores() {
    int opcion = 0;
    do {
        limpiarPantalla();
        cout << "======================================\n";
        cout << "        GESTIÓN DE PROVEEDORES       \n";
        cout << "======================================\n\n";
        cout << "1. Ingresar nuevo proveedor\n";
        cout << "2. Mostrar todos los proveedores\n";
        cout << "3. Actualizar proveedor\n";
        cout << "4. Eliminar proveedor\n";
        cout << "0. Volver al menú principal\n\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                ingresarProveedor();
                break;
            case 2:
                mostrarProveedores();
                break;
            case 3:
                actualizarProveedor();
                break;
            case 4:
                eliminarProveedor();
                break;
            case 0:
                // Volver al menú principal
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo.\n";
                pausar();
        }
    } while (opcion != 0);
}

void ingresarProveedor() {
    limpiarPantalla();
    cout << "===== INGRESAR NUEVO PROVEEDOR =====\n\n";

    string proveedor, nit, direccion, telefono;

    cout << "Ingrese Nombre de Proveedor: ";
    getline(cin, proveedor);
    cout << "Ingrese NIT: ";
    getline(cin, nit);
    cout << "Ingrese Dirección: ";
    getline(cin, direccion);
    cout << "Ingrese Teléfono: ";
    getline(cin, telefono);

    // Usamos 0 como valor temporal para idProveedor, ya que será generado por la base de datos
    Proveedor p = Proveedor(0, proveedor, nit, direccion, telefono);
    p.crear();

    pausar();
}

void mostrarProveedores() {
    limpiarPantalla();
    cout << "===== LISTADO DE PROVEEDORES =====\n\n";

    Proveedor p = Proveedor();
    p.leer();

    pausar();
}

void actualizarProveedor() {
    limpiarPantalla();
    cout << "===== ACTUALIZAR PROVEEDOR =====\n\n";

    Proveedor p = Proveedor();
    p.leer();

    int idProveedor = 0;
    string proveedor, nit, direccion, telefono;

    cout << "\nIngrese el ID del proveedor a modificar: ";
    cin >> idProveedor;
    cin.ignore();
    cout << "Ingrese Nuevo Nombre de Proveedor: ";
    getline(cin, proveedor);
    cout << "Ingrese Nuevo NIT: ";
    getline(cin, nit);
    cout << "Ingrese Nueva Dirección: ";
    getline(cin, direccion);
    cout << "Ingrese Nuevo Teléfono: ";
    getline(cin, telefono);

    p = Proveedor(idProveedor, proveedor, nit, direccion, telefono);
    p.actualizar();

    cout << "\nDatos actualizados:\n";
    p.leer();

    pausar();
}

void eliminarProveedor() {
    limpiarPantalla();
    cout << "===== ELIMINAR PROVEEDOR =====\n\n";

    Proveedor p = Proveedor();
    p.leer();

    int idProveedor = 0;
    cout << "\nIngrese el ID del proveedor a eliminar: ";
    cin >> idProveedor;

    char confirmar;
    cout << "¿Está seguro de eliminar este registro? (S/N): ";
    cin >> confirmar;

    if (confirmar == 'S' || confirmar == 's') {
        p.setIdProveedor(idProveedor);
        p.eliminar();
        cout << "\nRegistro eliminado. Lista actualizada:\n";
        p.leer();
    } else {
        cout << "\nOperación cancelada.\n";
    }

    pausar();
}

// Funciones para Producto
void menuProductos();
void ingresarProducto();
void mostrarProductos();
void actualizarProducto();
void eliminarProducto();

// Implementación de funciones para Producto
void menuProductos() {
    int opcion = 0;
    do {
        limpiarPantalla();
        cout << "======================================\n";
        cout << "        GESTIÓN DE PRODUCTOS         \n";
        cout << "======================================\n\n";
        cout << "1. Ingresar nuevo producto\n";
        cout << "2. Mostrar todos los productos\n";
        cout << "3. Actualizar producto\n";
        cout << "4. Eliminar producto\n";
        cout << "0. Volver al menú principal\n\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                ingresarProducto();
                break;
            case 2:
                mostrarProductos();
                break;
            case 3:
                actualizarProducto();
                break;
            case 4:
                eliminarProducto();
                break;
            case 0:
                // Volver al menú principal
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo.\n";
                pausar();
        }
    } while (opcion != 0);
}

void ingresarProducto() {
    limpiarPantalla();
    cout << "===== INGRESAR NUEVO PRODUCTO =====\n\n";

    // Mostrar marcas disponibles
    cout << "Marcas disponibles:\n";
    Marca m = Marca();
    m.leer();

    string producto, descripcion, imagen, fecha_ingreso;
    short idMarca = 0;
    double precio_costo = 0.0, precio_venta = 0.0;
    int existencia = 0;

    cout << "Ingrese Nombre de Producto: ";
    getline(cin, producto);
    cout << "Ingrese ID de Marca: ";
    cin >> idMarca;
    cin.ignore();
    cout << "Ingrese Descripción: ";
    getline(cin, descripcion);
    cout << "Ingrese Ruta de Imagen: ";
    getline(cin, imagen);
    cout << "Ingrese Precio de Costo: ";
    cin >> precio_costo;
    cout << "Ingrese Precio de Venta: ";
    cin >> precio_venta;
    cout << "Ingrese Existencia: ";
    cin >> existencia;
    cin.ignore();

    // Obtener fecha actual para fecha_ingreso
    fecha_ingreso = obtenerFechaHoraActual();

    // Usamos 0 como valor temporal para idProducto, ya que será generado por la base de datos
    Producto p = Producto(0, producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
    p.crear();

    pausar();
}

void mostrarProductos() {
    limpiarPantalla();
    cout << "===== LISTADO DE PRODUCTOS =====\n\n";

    Producto p = Producto();
    p.leer();

    pausar();
}

void actualizarProducto() {
    limpiarPantalla();
    cout << "===== ACTUALIZAR PRODUCTO =====\n\n";

    Producto p = Producto();
    p.leer();

    // Mostrar marcas disponibles
    cout << "\nMarcas disponibles:\n";
    Marca m = Marca();
    m.leer();

    int idProducto = 0;
    string producto, descripcion, imagen, fecha_ingreso;
    short idMarca = 0;
    double precio_costo = 0.0, precio_venta = 0.0;
    int existencia = 0;

    cout << "\nIngrese el ID del producto a modificar: ";
    cin >> idProducto;
    cin.ignore();
    cout << "Ingrese Nuevo Nombre de Producto: ";
    getline(cin, producto);
    cout << "Ingrese Nuevo ID de Marca: ";
    cin >> idMarca;
    cin.ignore();
    cout << "Ingrese Nueva Descripción: ";
    getline(cin, descripcion);
    cout << "Ingrese Nueva Ruta de Imagen: ";
    getline(cin, imagen);
    cout << "Ingrese Nuevo Precio de Costo: ";
    cin >> precio_costo;
    cout << "Ingrese Nuevo Precio de Venta: ";
    cin >> precio_venta;
    cout << "Ingrese Nueva Existencia: ";
    cin >> existencia;
    cin.ignore();

    // Obtener fecha actual para fecha_ingreso
    fecha_ingreso = obtenerFechaHoraActual();

    p = Producto(idProducto, producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
    p.actualizar();

    cout << "\nDatos actualizados:\n";
    p.leer();

    pausar();
}

void eliminarProducto() {
    limpiarPantalla();
    cout << "===== ELIMINAR PRODUCTO =====\n\n";

    Producto p = Producto();
    p.leer();

    int idProducto = 0;
    cout << "\nIngrese el ID del producto a eliminar: ";
    cin >> idProducto;

    char confirmar;
    cout << "¿Está seguro de eliminar este registro? (S/N): ";
    cin >> confirmar;

    if (confirmar == 'S' || confirmar == 's') {
        p.setIdProducto(idProducto);
        p.eliminar();
        cout << "\nRegistro eliminado. Lista actualizada:\n";
        p.leer();
    } else {
        cout << "\nOperación cancelada.\n";
    }

    pausar();
}

// Funciones para Empleado
void menuEmpleados();
void ingresarEmpleado();
void mostrarEmpleados();
void actualizarEmpleado();
void eliminarEmpleado();

// Implementación de funciones para Empleado
void menuEmpleados() {
    int opcion = 0;
    do {
        limpiarPantalla();
        cout << "======================================\n";
        cout << "        GESTIÓN DE EMPLEADOS         \n";
        cout << "======================================\n\n";
        cout << "1. Ingresar nuevo empleado\n";
        cout << "2. Mostrar todos los empleados\n";
        cout << "3. Actualizar empleado\n";
        cout << "4. Eliminar empleado\n";
        cout << "0. Volver al menú principal\n\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                ingresarEmpleado();
                break;
            case 2:
                mostrarEmpleados();
                break;
            case 3:
                actualizarEmpleado();
                break;
            case 4:
                eliminarEmpleado();
                break;
            case 0:
                // Volver al menú principal
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo.\n";
                pausar();
        }
    } while (opcion != 0);
}

void ingresarEmpleado() {
    limpiarPantalla();
    cout << "===== INGRESAR NUEVO EMPLEADO =====\n\n";

    // Mostrar puestos disponibles
    cout << "Puestos disponibles:\n";
    Puesto p = Puesto();
    p.leer();

    string nombres, apellidos, direccion, telefono, DPI, fecha_nacimiento, fecha_inicio_labores, fecha_ingreso;
    bool genero = false;
    short idPuesto = 0;
    char gen;

    cout << "Ingrese Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese Dirección: ";
    getline(cin, direccion);
    cout << "Ingrese Teléfono: ";
    getline(cin, telefono);
    cout << "Ingrese DPI: ";
    getline(cin, DPI);
    cout << "Ingrese Género (M/F): ";
    cin >> gen;
    genero = (gen == 'M' || gen == 'm') ? true : false;
    cin.ignore();
    cout << "Ingrese Fecha de Nacimiento (YYYY-MM-DD): ";
    getline(cin, fecha_nacimiento);
    cout << "Ingrese ID de Puesto: ";
    cin >> idPuesto;
    cin.ignore();
    cout << "Ingrese Fecha de Inicio de Labores (YYYY-MM-DD): ";
    getline(cin, fecha_inicio_labores);

    // Obtener fecha actual para fecha_ingreso
    fecha_ingreso = obtenerFechaHoraActual();

    // Usamos 0 como valor temporal para idEmpleado, ya que será generado por la base de datos
    Empleado e = Empleado(0, nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso);
    e.crear();

    pausar();
}

void mostrarEmpleados() {
    limpiarPantalla();
    cout << "===== LISTADO DE EMPLEADOS =====\n\n";

    Empleado e = Empleado();
    e.leer();

    pausar();
}

void actualizarEmpleado() {
    limpiarPantalla();
    cout << "===== ACTUALIZAR EMPLEADO =====\n\n";

    Empleado e = Empleado();
    e.leer();

    // Mostrar puestos disponibles
    cout << "\nPuestos disponibles:\n";
    Puesto p = Puesto();
    p.leer();

    int idEmpleado = 0;
    string nombres, apellidos, direccion, telefono, DPI, fecha_nacimiento, fecha_inicio_labores, fecha_ingreso;
    bool genero = false;
    short idPuesto = 0;
    char gen;

    cout << "\nIngrese el ID del empleado a modificar: ";
    cin >> idEmpleado;
    cin.ignore();
    cout << "Ingrese Nuevos Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese Nuevos Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese Nueva Dirección: ";
    getline(cin, direccion);
    cout << "Ingrese Nuevo Teléfono: ";
    getline(cin, telefono);
    cout << "Ingrese Nuevo DPI: ";
    getline(cin, DPI);
    cout << "Ingrese Nuevo Género (M/F): ";
    cin >> gen;
    genero = (gen == 'M' || gen == 'm') ? true : false;
    cin.ignore();
    cout << "Ingrese Nueva Fecha de Nacimiento (YYYY-MM-DD): ";
    getline(cin, fecha_nacimiento);
    cout << "Ingrese Nuevo ID de Puesto: ";
    cin >> idPuesto;
    cin.ignore();
    cout << "Ingrese Nueva Fecha de Inicio de Labores (YYYY-MM-DD): ";
    getline(cin, fecha_inicio_labores);

    // Obtener fecha actual para fecha_ingreso
    fecha_ingreso = obtenerFechaHoraActual();

    e = Empleado(idEmpleado, nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso);
    e.actualizar();

    cout << "\nDatos actualizados:\n";
    e.leer();

    pausar();
}

void eliminarEmpleado() {
    limpiarPantalla();
    cout << "===== ELIMINAR EMPLEADO =====\n\n";

    Empleado e = Empleado();
    e.leer();

    int idEmpleado = 0;
    cout << "\nIngrese el ID del empleado a eliminar: ";
    cin >> idEmpleado;

    char confirmar;
    cout << "¿Está seguro de eliminar este registro? (S/N): ";
    cin >> confirmar;

    if (confirmar == 'S' || confirmar == 's') {
        e.setIdEmpleado(idEmpleado);
        e.eliminar();
        cout << "\nRegistro eliminado. Lista actualizada:\n";
        e.leer();
    } else {
        cout << "\nOperación cancelada.\n";
    }

    pausar();
}

// Funciones para Cliente
void menuClientes();
void ingresarCliente();
void mostrarClientes();
void actualizarCliente();
void eliminarCliente();

// Implementación de funciones para Cliente
void menuClientes() {
    int opcion = 0;
    do {
        limpiarPantalla();
        cout << "======================================\n";
        cout << "         GESTIÓN DE CLIENTES         \n";
        cout << "======================================\n\n";
        cout << "1. Ingresar nuevo cliente\n";
        cout << "2. Mostrar todos los clientes\n";
        cout << "3. Actualizar cliente\n";
        cout << "4. Eliminar cliente\n";
        cout << "0. Volver al menú principal\n\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                ingresarCliente();
                break;
            case 2:
                mostrarClientes();
                break;
            case 3:
                actualizarCliente();
                break;
            case 4:
                eliminarCliente();
                break;
            case 0:
                // Volver al menú principal
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo.\n";
                pausar();
        }
    } while (opcion != 0);
}

void ingresarCliente() {
    limpiarPantalla();
    cout << "===== INGRESAR NUEVO CLIENTE =====\n\n";

    string nombres, apellidos, NIT, telefono, correo_electronico, fecha_ingreso;
    bool genero = false;
    char gen;

    cout << "Ingrese Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese NIT: ";
    getline(cin, NIT);
    cout << "Ingrese Género (M/F): ";
    cin >> gen;
    genero = (gen == 'M' || gen == 'm') ? true : false;
    cin.ignore();
    cout << "Ingrese Teléfono: ";
    getline(cin, telefono);
    cout << "Ingrese Correo Electrónico: ";
    getline(cin, correo_electronico);

    // Obtener fecha actual para fecha_ingreso
    fecha_ingreso = obtenerFechaHoraActual();

    // Usamos 0 como valor temporal para idCliente, ya que será generado por la base de datos
    Cliente c = Cliente(0, nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso);
    c.crear();

    pausar();
}

void mostrarClientes() {
    limpiarPantalla();
    cout << "===== LISTADO DE CLIENTES =====\n\n";

    Cliente c = Cliente();
    c.leer();

    pausar();
}

void actualizarCliente() {
    limpiarPantalla();
    cout << "===== ACTUALIZAR CLIENTE =====\n\n";

    Cliente c = Cliente();
    c.leer();

    int idCliente = 0;
    string nombres, apellidos, NIT, telefono, correo_electronico, fecha_ingreso;
    bool genero = false;
    char gen;

    cout << "\nIngrese el ID del cliente a modificar: ";
    cin >> idCliente;
    cin.ignore();
    cout << "Ingrese Nuevos Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese Nuevos Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese Nuevo NIT: ";
    getline(cin, NIT);
    cout << "Ingrese Nuevo Género (M/F): ";
    cin >> gen;
    genero = (gen == 'M' || gen == 'm') ? true : false;
    cin.ignore();
    cout << "Ingrese Nuevo Teléfono: ";
    getline(cin, telefono);
    cout << "Ingrese Nuevo Correo Electrónico: ";
    getline(cin, correo_electronico);

    // Obtener fecha actual para fecha_ingreso
    fecha_ingreso = obtenerFechaHoraActual();

    c = Cliente(idCliente, nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso);
    c.actualizar();

    cout << "\nDatos actualizados:\n";
    c.leer();

    pausar();
}

void eliminarCliente() {
    limpiarPantalla();
    cout << "===== ELIMINAR CLIENTE =====\n\n";

    Cliente c = Cliente();
    c.leer();

    int idCliente = 0;
    cout << "\nIngrese el ID del cliente a eliminar: ";
    cin >> idCliente;

    char confirmar;
    cout << "¿Está seguro de eliminar este registro? (S/N): ";
    cin >> confirmar;

    if (confirmar == 'S' || confirmar == 's') {
        c.setIdCliente(idCliente);
        c.eliminar();
        cout << "\nRegistro eliminado. Lista actualizada:\n";
        c.leer();
    } else {
        cout << "\nOperación cancelada.\n";
    }

    pausar();
}

// Funciones para Compra
void menuCompras();
void ingresarCompra();
void mostrarCompras();
void mostrarDetallesCompra();
void actualizarCompra();
void eliminarCompra();

// Funciones para Compra_detalle
void menuDetallesCompra();
void ingresarDetalleCompra();
void mostrarDetallesCompraIndividual();
void actualizarDetalleCompra();
void eliminarDetalleCompra();

// Implementación de funciones para Compra_detalle
void menuDetallesCompra() {
    int opcion = 0;
    do {
        limpiarPantalla();
        cout << "======================================\n";
        cout << "    GESTIÓN DE DETALLES DE COMPRA    \n";
        cout << "======================================\n\n";
        cout << "1. Ingresar nuevo detalle de compra\n";
        cout << "2. Mostrar detalles de compra\n";
        cout << "3. Actualizar detalle de compra\n";
        cout << "4. Eliminar detalle de compra\n";
        cout << "0. Volver al menú principal\n\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                ingresarDetalleCompra();
                break;
            case 2:
                mostrarDetallesCompraIndividual();
                break;
            case 3:
                actualizarDetalleCompra();
                break;
            case 4:
                eliminarDetalleCompra();
                break;
            case 0:
                // Volver al menú principal
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo.\n";
                pausar();
        }
    } while (opcion != 0);
}

void ingresarDetalleCompra() {
    limpiarPantalla();
    cout << "===== INGRESAR NUEVO DETALLE DE COMPRA =====\n\n";

    // Mostrar compras disponibles
    cout << "Compras disponibles:\n";
    Compra c = Compra();
    c.leer();

    // Mostrar productos disponibles
    cout << "\nProductos disponibles:\n";
    Producto p = Producto();
    p.leer();

    int idcompra = 0, idproducto = 0, cantidad = 0;
    double precio_unitario = 0.0;

    cout << "Ingrese ID de Compra: ";
    cin >> idcompra;
    cout << "Ingrese ID de Producto: ";
    cin >> idproducto;
    cout << "Ingrese Cantidad: ";
    cin >> cantidad;
    cout << "Ingrese Precio Unitario: ";
    cin >> precio_unitario;

    // Crear el detalle de compra directamente en la base de datos
    int q_estado = 0;
    ConexionBD cn = ConexionBD();
    cn.abrir_conexion();
    if (cn.getConector()) {
        string idc = to_string(idcompra);
        string idp = to_string(idproducto);
        string cant = to_string(cantidad);
        string pu = to_string(precio_unitario);

        // Modificamos la consulta para usar AUTO_INCREMENT
        string consulta = "INSERT INTO Compras_detalle(idcompra, idproducto, cantidad, precio_unitario) VALUES (" + idc + ", " + idp + ", " + cant + ", " + pu + ");";
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConector(), c);
        if (!q_estado) {
            cout << "Ingreso de Detalle de Compra Exitoso..." << endl;
        }
        else {
            cout << "xxx Error al ingresar información xxx" << endl;
            cout << consulta << endl;
        }
    }
    else {
        cout << "xxx Error en la conexión xxx" << endl;
    }
    cn.cerrar_conexion();

    pausar();
}

void mostrarDetallesCompraIndividual() {
    limpiarPantalla();
    cout << "===== LISTADO DE DETALLES DE COMPRA =====\n\n";

    // Mostrar todas las compras
    cout << "Compras disponibles:\n";
    Compra c = Compra();
    c.leer();

    int idcompra = 0;
    cout << "\nIngrese el ID de la compra para ver sus detalles: ";
    cin >> idcompra;

    // Mostrar los detalles de la compra seleccionada
    c.leerDetalles(idcompra);

    pausar();
}

void actualizarDetalleCompra() {
    limpiarPantalla();
    cout << "===== ACTUALIZAR DETALLE DE COMPRA =====\n\n";

    // Mostrar compras disponibles
    cout << "Compras disponibles:\n";
    Compra c = Compra();
    c.leer();

    int idcompra = 0;
    cout << "\nIngrese el ID de la compra para ver sus detalles: ";
    cin >> idcompra;

    // Mostrar los detalles de la compra seleccionada
    c.leerDetalles(idcompra);

    // Mostrar productos disponibles
    cout << "\nProductos disponibles:\n";
    Producto p = Producto();
    p.leer();

    int idcompra_detalle = 0, idproducto = 0, cantidad = 0;
    double precio_unitario = 0.0;

    cout << "\nIngrese el ID del detalle de compra a modificar: ";
    cin >> idcompra_detalle;
    cout << "Ingrese Nuevo ID de Producto: ";
    cin >> idproducto;
    cout << "Ingrese Nueva Cantidad: ";
    cin >> cantidad;
    cout << "Ingrese Nuevo Precio Unitario: ";
    cin >> precio_unitario;

    // Actualizar el detalle de compra directamente en la base de datos
    int q_estado = 0;
    ConexionBD cn = ConexionBD();
    cn.abrir_conexion();
    if (cn.getConector()) {
        string idcd = to_string(idcompra_detalle);
        string idp = to_string(idproducto);
        string cant = to_string(cantidad);
        string pu = to_string(precio_unitario);

        string consulta = "UPDATE Compras_detalle SET idproducto = " + idp + ", cantidad = " + cant + ", precio_unitario = " + pu + " WHERE idcompra_detalle = " + idcd + ";";
        const char* sql = consulta.c_str();
        q_estado = mysql_query(cn.getConector(), sql);
        if (!q_estado) {
            cout << "Actualización de Detalle de Compra Exitosa..." << endl;

            // Mostrar los detalles actualizados
            cout << "\nDetalles actualizados:\n";
            Compra compra = Compra();
            compra.leerDetalles(idcompra);
        }
        else {
            cout << "xxx Error al actualizar información xxx" << endl;
            cout << consulta << endl;
        }
    }
    else {
        cout << "xxx Error en la conexión xxx" << endl;
    }
    cn.cerrar_conexion();

    pausar();
}

void eliminarDetalleCompra() {
    limpiarPantalla();
    cout << "===== ELIMINAR DETALLE DE COMPRA =====\n\n";

    // Mostrar compras disponibles
    cout << "Compras disponibles:\n";
    Compra c = Compra();
    c.leer();

    int idcompra = 0;
    cout << "\nIngrese el ID de la compra para ver sus detalles: ";
    cin >> idcompra;

    // Mostrar los detalles de la compra seleccionada
    c.leerDetalles(idcompra);

    int idcompra_detalle = 0;
    cout << "\nIngrese el ID del detalle de compra a eliminar: ";
    cin >> idcompra_detalle;

    char confirmar;
    cout << "¿Está seguro de eliminar este detalle? (S/N): ";
    cin >> confirmar;

    if (confirmar == 'S' || confirmar == 's') {
        // Eliminar el detalle de compra directamente en la base de datos
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string idcd = to_string(idcompra_detalle);

            string consulta = "DELETE FROM Compras_detalle WHERE idcompra_detalle = " + idcd + ";";
            const char* sql = consulta.c_str();
            q_estado = mysql_query(cn.getConector(), sql);
            if (!q_estado) {
                cout << "Eliminación de Detalle de Compra Exitosa..." << endl;

                // Mostrar los detalles actualizados
                cout << "\nDetalles actualizados:\n";
                Compra compra = Compra();
                compra.leerDetalles(idcompra);
            }
            else {
                cout << "xxx Error al eliminar información xxx" << endl;
                cout << consulta << endl;
            }
        }
        else {
            cout << "xxx Error en la conexión xxx" << endl;
        }
        cn.cerrar_conexion();
    } else {
        cout << "\nOperación cancelada.\n";
    }

    pausar();
}

// Implementación de funciones para Compra
void menuCompras() {
    int opcion = 0;
    do {
        limpiarPantalla();
        cout << "======================================\n";
        cout << "         GESTIÓN DE COMPRAS          \n";
        cout << "======================================\n\n";
        cout << "1. Ingresar nueva compra\n";
        cout << "2. Mostrar todas las compras\n";
        cout << "3. Ver detalles de una compra\n";
        cout << "4. Actualizar compra\n";
        cout << "5. Eliminar compra\n";
        cout << "0. Volver al menú principal\n\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                ingresarCompra();
                break;
            case 2:
                mostrarCompras();
                break;
            case 3:
                mostrarDetallesCompra();
                break;
            case 4:
                actualizarCompra();
                break;
            case 5:
                eliminarCompra();
                break;
            case 0:
                // Volver al menú principal
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo.\n";
                pausar();
        }
    } while (opcion != 0);
}

void ingresarCompra() {
    limpiarPantalla();
    cout << "===== INGRESAR NUEVA COMPRA =====\n\n";

    // Mostrar proveedores disponibles
    cout << "Proveedores disponibles:\n";
    Proveedor prov = Proveedor();
    prov.leer();

    int no_order_compra = 0, idproveedor = 0;
    string fecha_order, fecha_ingreso;

    cout << "Ingrese No. de Orden de Compra: ";
    cin >> no_order_compra;
    cout << "Ingrese ID de Proveedor: ";
    cin >> idproveedor;
    cin.ignore();
    cout << "Ingrese Fecha de Orden (YYYY-MM-DD): ";
    getline(cin, fecha_order);

    // Obtener fecha actual para fecha_ingreso
    fecha_ingreso = obtenerFechaHoraActual();

    // Usamos 0 como valor temporal para idcompra, ya que será generado por la base de datos
    Compra c = Compra(0, no_order_compra, idproveedor, fecha_order, fecha_ingreso);

    // Agregar detalles de compra
    char agregarDetalle = 'S';

    // Mostrar productos disponibles
    cout << "\nProductos disponibles:\n";
    Producto prod = Producto();
    prod.leer();

    while (agregarDetalle == 'S' || agregarDetalle == 's') {
        DetalleCompra detalle;

        // Usamos 0 como valor temporal para idcompra_detalle, ya que será generado por la base de datos
        detalle.idcompra_detalle = 0;
        cout << "Ingrese ID de Producto: ";
        cin >> detalle.idproducto;
        cout << "Ingrese Cantidad: ";
        cin >> detalle.cantidad;
        cout << "Ingrese Precio Unitario: ";
        cin >> detalle.precio_unitario;

        c.agregarDetalle(detalle);

        cout << "\n¿Desea agregar otro detalle? (S/N): ";
        cin >> agregarDetalle;
    }

    c.crear();

    pausar();
}

void mostrarCompras() {
    limpiarPantalla();
    cout << "===== LISTADO DE COMPRAS =====\n\n";

    Compra c = Compra();
    c.leer();

    pausar();
}

void mostrarDetallesCompra() {
    limpiarPantalla();
    cout << "===== DETALLES DE COMPRA =====\n\n";

    Compra c = Compra();
    c.leer();

    int idcompra = 0;
    cout << "\nIngrese el ID de la compra para ver detalles: ";
    cin >> idcompra;

    c.leerDetalles(idcompra);

    pausar();
}

void actualizarCompra() {
    limpiarPantalla();
    cout << "===== ACTUALIZAR COMPRA =====\n\n";

    Compra c = Compra();
    c.leer();

    // Mostrar proveedores disponibles
    cout << "\nProveedores disponibles:\n";
    Proveedor prov = Proveedor();
    prov.leer();

    int idcompra = 0, no_order_compra = 0, idproveedor = 0;
    string fecha_order, fecha_ingreso;

    cout << "\nIngrese el ID de la compra a modificar: ";
    cin >> idcompra;
    cout << "Ingrese Nuevo No. de Orden de Compra: ";
    cin >> no_order_compra;
    cout << "Ingrese Nuevo ID de Proveedor: ";
    cin >> idproveedor;
    cin.ignore();
    cout << "Ingrese Nueva Fecha de Orden (YYYY-MM-DD): ";
    getline(cin, fecha_order);

    // Obtener fecha actual para fecha_ingreso
    fecha_ingreso = obtenerFechaHoraActual();

    c = Compra(idcompra, no_order_compra, idproveedor, fecha_order, fecha_ingreso);
    c.actualizar();

    cout << "\nDatos actualizados:\n";
    c.leer();

    pausar();
}

void eliminarCompra() {
    limpiarPantalla();
    cout << "===== ELIMINAR COMPRA =====\n\n";

    Compra c = Compra();
    c.leer();

    int idcompra = 0;
    cout << "\nIngrese el ID de la compra a eliminar: ";
    cin >> idcompra;

    char confirmar;
    cout << "¿Está seguro de eliminar este registro y todos sus detalles? (S/N): ";
    cin >> confirmar;

    if (confirmar == 'S' || confirmar == 's') {
        c.setIdCompra(idcompra);
        c.eliminar();
        cout << "\nRegistro eliminado. Lista actualizada:\n";
        c.leer();
    } else {
        cout << "\nOperación cancelada.\n";
    }

    pausar();
}

// Funciones para Venta
void menuVentas();
void ingresarVenta();
void mostrarVentas();
void mostrarDetallesVenta();
void actualizarVenta();
void eliminarVenta();

// Funciones para Venta_detalle
void menuDetallesVenta();
void ingresarDetalleVenta();
void mostrarDetallesVentaIndividual();
void actualizarDetalleVenta();
void eliminarDetalleVenta();

// Implementación de funciones para Venta_detalle
void menuDetallesVenta() {
    int opcion = 0;
    do {
        limpiarPantalla();
        cout << "======================================\n";
        cout << "     GESTIÓN DE DETALLES DE VENTA    \n";
        cout << "======================================\n\n";
        cout << "1. Ingresar nuevo detalle de venta\n";
        cout << "2. Mostrar detalles de venta\n";
        cout << "3. Actualizar detalle de venta\n";
        cout << "4. Eliminar detalle de venta\n";
        cout << "0. Volver al menú principal\n\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                ingresarDetalleVenta();
                break;
            case 2:
                mostrarDetallesVentaIndividual();
                break;
            case 3:
                actualizarDetalleVenta();
                break;
            case 4:
                eliminarDetalleVenta();
                break;
            case 0:
                // Volver al menú principal
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo.\n";
                pausar();
        }
    } while (opcion != 0);
}

void ingresarDetalleVenta() {
    limpiarPantalla();
    cout << "===== INGRESAR NUEVO DETALLE DE VENTA =====\n\n";

    // Mostrar ventas disponibles
    cout << "Ventas disponibles:\n";
    Venta v = Venta();
    v.leer();

    // Mostrar productos disponibles
    cout << "\nProductos disponibles:\n";
    Producto p = Producto();
    p.leer();

    int idventa = 0, idProducto = 0;
    string cantidad;
    double precio_unitario = 0.0;

    cout << "Ingrese ID de Venta: ";
    cin >> idventa;
    cout << "Ingrese ID de Producto: ";
    cin >> idProducto;
    cin.ignore();
    cout << "Ingrese Cantidad: ";
    getline(cin, cantidad);
    cout << "Ingrese Precio Unitario: ";
    cin >> precio_unitario;

    // Crear el detalle de venta directamente en la base de datos
    int q_estado = 0;
    ConexionBD cn = ConexionBD();
    cn.abrir_conexion();
    if (cn.getConector()) {
        string idv = to_string(idventa);
        string idp = to_string(idProducto);
        string pu = to_string(precio_unitario);

        // Modificamos la consulta para usar AUTO_INCREMENT
        string consulta = "INSERT INTO Ventas_detalle(idventa, idProducto, cantidad, precio_unitario) VALUES (" + idv + ", " + idp + ", '" + cantidad + "', " + pu + ");";
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConector(), c);
        if (!q_estado) {
            cout << "Ingreso de Detalle de Venta Exitoso..." << endl;
        }
        else {
            cout << "xxx Error al ingresar información xxx" << endl;
            cout << consulta << endl;
        }
    }
    else {
        cout << "xxx Error en la conexión xxx" << endl;
    }
    cn.cerrar_conexion();

    pausar();
}

void mostrarDetallesVentaIndividual() {
    limpiarPantalla();
    cout << "===== LISTADO DE DETALLES DE VENTA =====\n\n";

    // Mostrar todas las ventas
    cout << "Ventas disponibles:\n";
    Venta v = Venta();
    v.leer();

    int idventa = 0;
    cout << "\nIngrese el ID de la venta para ver sus detalles: ";
    cin >> idventa;

    // Mostrar los detalles de la venta seleccionada
    v.leerDetalles(idventa);

    pausar();
}

void actualizarDetalleVenta() {
    limpiarPantalla();
    cout << "===== ACTUALIZAR DETALLE DE VENTA =====\n\n";

    // Mostrar ventas disponibles
    cout << "Ventas disponibles:\n";
    Venta v = Venta();
    v.leer();

    int idventa = 0;
    cout << "\nIngrese el ID de la venta para ver sus detalles: ";
    cin >> idventa;

    // Mostrar los detalles de la venta seleccionada
    v.leerDetalles(idventa);

    // Mostrar productos disponibles
    cout << "\nProductos disponibles:\n";
    Producto p = Producto();
    p.leer();

    int idventa_detalle = 0, idProducto = 0;
    string cantidad;
    double precio_unitario = 0.0;

    cout << "\nIngrese el ID del detalle de venta a modificar: ";
    cin >> idventa_detalle;
    cout << "Ingrese Nuevo ID de Producto: ";
    cin >> idProducto;
    cin.ignore();
    cout << "Ingrese Nueva Cantidad: ";
    getline(cin, cantidad);
    cout << "Ingrese Nuevo Precio Unitario: ";
    cin >> precio_unitario;

    // Actualizar el detalle de venta directamente en la base de datos
    int q_estado = 0;
    ConexionBD cn = ConexionBD();
    cn.abrir_conexion();
    if (cn.getConector()) {
        string idvd = to_string(idventa_detalle);
        string idp = to_string(idProducto);
        string pu = to_string(precio_unitario);

        string consulta = "UPDATE Ventas_detalle SET idProducto = " + idp + ", cantidad = '" + cantidad + "', precio_unitario = " + pu + " WHERE idventa_detalle = " + idvd + ";";
        const char* sql = consulta.c_str();
        q_estado = mysql_query(cn.getConector(), sql);
        if (!q_estado) {
            cout << "Actualización de Detalle de Venta Exitosa..." << endl;

            // Mostrar los detalles actualizados
            cout << "\nDetalles actualizados:\n";
            Venta venta = Venta();
            venta.leerDetalles(idventa);
        }
        else {
            cout << "xxx Error al actualizar información xxx" << endl;
            cout << consulta << endl;
        }
    }
    else {
        cout << "xxx Error en la conexión xxx" << endl;
    }
    cn.cerrar_conexion();

    pausar();
}

void eliminarDetalleVenta() {
    limpiarPantalla();
    cout << "===== ELIMINAR DETALLE DE VENTA =====\n\n";

    // Mostrar ventas disponibles
    cout << "Ventas disponibles:\n";
    Venta v = Venta();
    v.leer();

    int idventa = 0;
    cout << "\nIngrese el ID de la venta para ver sus detalles: ";
    cin >> idventa;

    // Mostrar los detalles de la venta seleccionada
    v.leerDetalles(idventa);

    int idventa_detalle = 0;
    cout << "\nIngrese el ID del detalle de venta a eliminar: ";
    cin >> idventa_detalle;

    char confirmar;
    cout << "¿Está seguro de eliminar este detalle? (S/N): ";
    cin >> confirmar;

    if (confirmar == 'S' || confirmar == 's') {
        // Eliminar el detalle de venta directamente en la base de datos
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string idvd = to_string(idventa_detalle);

            string consulta = "DELETE FROM Ventas_detalle WHERE idventa_detalle = " + idvd + ";";
            const char* sql = consulta.c_str();
            q_estado = mysql_query(cn.getConector(), sql);
            if (!q_estado) {
                cout << "Eliminación de Detalle de Venta Exitosa..." << endl;

                // Mostrar los detalles actualizados
                cout << "\nDetalles actualizados:\n";
                Venta venta = Venta();
                venta.leerDetalles(idventa);
            }
            else {
                cout << "xxx Error al eliminar información xxx" << endl;
                cout << consulta << endl;
            }
        }
        else {
            cout << "xxx Error en la conexión xxx" << endl;
        }
        cn.cerrar_conexion();
    } else {
        cout << "\nOperación cancelada.\n";
    }

    pausar();
}

// Implementación de funciones para Venta
void menuVentas() {
    int opcion = 0;
    do {
        limpiarPantalla();
        cout << "======================================\n";
        cout << "          GESTIÓN DE VENTAS          \n";
        cout << "======================================\n\n";
        cout << "1. Ingresar nueva venta\n";
        cout << "2. Mostrar todas las ventas\n";
        cout << "3. Ver detalles de una venta\n";
        cout << "4. Actualizar venta\n";
        cout << "5. Eliminar venta\n";
        cout << "0. Volver al menú principal\n\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                ingresarVenta();
                break;
            case 2:
                mostrarVentas();
                break;
            case 3:
                mostrarDetallesVenta();
                break;
            case 4:
                actualizarVenta();
                break;
            case 5:
                eliminarVenta();
                break;
            case 0:
                // Volver al menú principal
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo.\n";
                pausar();
        }
    } while (opcion != 0);
}

void ingresarVenta() {
    limpiarPantalla();
    cout << "===== INGRESAR NUEVA VENTA =====\n\n";

    // Mostrar clientes disponibles
    cout << "Clientes disponibles:\n";
    Cliente c = Cliente();
    c.leer();

    // Mostrar empleados disponibles
    cout << "\nEmpleados disponibles:\n";
    Empleado e = Empleado();
    e.leer();

    int nofactura = 0, idcliente = 0, idempleado = 0;
    char serie;
    string fechafactura, fecha_ingreso;

    cout << "Ingrese No. de Factura: ";
    cin >> nofactura;
    cout << "Ingrese Serie (A-Z): ";
    cin >> serie;
    cin.ignore();
    cout << "Ingrese Fecha de Factura (YYYY-MM-DD): ";
    getline(cin, fechafactura);
    cout << "Ingrese ID de Cliente: ";
    cin >> idcliente;
    cout << "Ingrese ID de Empleado: ";
    cin >> idempleado;

    // Obtener fecha actual para fecha_ingreso
    fecha_ingreso = obtenerFechaHoraActual();

    // Usamos 0 como valor temporal para idVenta, ya que será generado por la base de datos
    Venta v = Venta(0, nofactura, serie, fechafactura, idcliente, idempleado, fecha_ingreso);

    // Agregar detalles de venta
    char agregarDetalle = 'S';

    // Mostrar productos disponibles
    cout << "\nProductos disponibles:\n";
    Producto prod = Producto();
    prod.leer();

    while (agregarDetalle == 'S' || agregarDetalle == 's') {
        DetalleVenta detalle;

        // Usamos 0 como valor temporal para idventa_detalle, ya que será generado por la base de datos
        detalle.idventa_detalle = 0;
        cout << "Ingrese ID de Producto: ";
        cin >> detalle.idProducto;
        cin.ignore();
        cout << "Ingrese Cantidad: ";
        getline(cin, detalle.cantidad);
        cout << "Ingrese Precio Unitario: ";
        cin >> detalle.precio_unitario;

        v.agregarDetalle(detalle);

        cout << "\n¿Desea agregar otro detalle? (S/N): ";
        cin >> agregarDetalle;
    }

    v.crear();

    pausar();
}

void mostrarVentas() {
    limpiarPantalla();
    cout << "===== LISTADO DE VENTAS =====\n\n";

    Venta v = Venta();
    v.leer();

    pausar();
}

void mostrarDetallesVenta() {
    limpiarPantalla();
    cout << "===== DETALLES DE VENTA =====\n\n";

    Venta v = Venta();
    v.leer();

    int idVenta = 0;
    cout << "\nIngrese el ID de la venta para ver detalles: ";
    cin >> idVenta;

    v.leerDetalles(idVenta);

    pausar();
}

void actualizarVenta() {
    limpiarPantalla();
    cout << "===== ACTUALIZAR VENTA =====\n\n";

    Venta v = Venta();
    v.leer();

    // Mostrar clientes disponibles
    cout << "\nClientes disponibles:\n";
    Cliente c = Cliente();
    c.leer();

    // Mostrar empleados disponibles
    cout << "\nEmpleados disponibles:\n";
    Empleado e = Empleado();
    e.leer();

    int idVenta = 0, nofactura = 0, idcliente = 0, idempleado = 0;
    char serie;
    string fechafactura, fecha_ingreso;

    cout << "\nIngrese el ID de la venta a modificar: ";
    cin >> idVenta;
    cout << "Ingrese Nuevo No. de Factura: ";
    cin >> nofactura;
    cout << "Ingrese Nueva Serie (A-Z): ";
    cin >> serie;
    cin.ignore();
    cout << "Ingrese Nueva Fecha de Factura (YYYY-MM-DD): ";
    getline(cin, fechafactura);
    cout << "Ingrese Nuevo ID de Cliente: ";
    cin >> idcliente;
    cout << "Ingrese Nuevo ID de Empleado: ";
    cin >> idempleado;

    // Obtener fecha actual para fecha_ingreso
    fecha_ingreso = obtenerFechaHoraActual();

    v = Venta(idVenta, nofactura, serie, fechafactura, idcliente, idempleado, fecha_ingreso);
    v.actualizar();

    cout << "\nDatos actualizados:\n";
    v.leer();

    pausar();
}

void eliminarVenta() {
    limpiarPantalla();
    cout << "===== ELIMINAR VENTA =====\n\n";

    Venta v = Venta();
    v.leer();

    int idVenta = 0;
    cout << "\nIngrese el ID de la venta a eliminar: ";
    cin >> idVenta;

    char confirmar;
    cout << "¿Está seguro de eliminar este registro y todos sus detalles? (S/N): ";
    cin >> confirmar;

    if (confirmar == 'S' || confirmar == 's') {
        v.setIdVenta(idVenta);
        v.eliminar();
        cout << "\nRegistro eliminado. Lista actualizada:\n";
        v.leer();
    } else {
        cout << "\nOperación cancelada.\n";
    }

    pausar();
}



// Implementación de funciones para Marca
void menuMarcas() {
    int opcion = 0;
    do {
        limpiarPantalla();
        cout << "======================================\n";
        cout << "           GESTIÓN DE MARCAS         \n";
        cout << "======================================\n\n";
        cout << "1. Ingresar nueva marca\n";
        cout << "2. Mostrar todas las marcas\n";
        cout << "3. Actualizar marca\n";
        cout << "4. Eliminar marca\n";
        cout << "0. Volver al menú principal\n\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                ingresarMarca();
                break;
            case 2:
                mostrarMarcas();
                break;
            case 3:
                actualizarMarca();
                break;
            case 4:
                eliminarMarca();
                break;
            case 0:
                // Volver al menú principal
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo.\n";
                pausar();
        }
    } while (opcion != 0);
}

void ingresarMarca() {
    limpiarPantalla();
    cout << "===== INGRESAR NUEVA MARCA =====\n\n";

    string marca;

    cout << "Ingrese Nombre de Marca: ";
    getline(cin, marca);

    // Usamos 0 como valor temporal para idmarca, ya que será generado por la base de datos
    Marca m = Marca(0, marca);
    m.crear();

    pausar();
}

void mostrarMarcas() {
    limpiarPantalla();
    cout << "===== LISTADO DE MARCAS =====\n\n";

    Marca m = Marca();
    m.leer();

    pausar();
}

void actualizarMarca() {
    limpiarPantalla();
    cout << "===== ACTUALIZAR MARCA =====\n\n";

    Marca m = Marca();
    m.leer();

    short idmarca = 0;
    string marca;

    cout << "\nIngrese el ID de la marca a modificar: ";
    cin >> idmarca;
    cin.ignore();
    cout << "Ingrese Nuevo Nombre de Marca: ";
    getline(cin, marca);

    m = Marca(idmarca, marca);
    m.actualizar();

    cout << "\nDatos actualizados:\n";
    m.leer();

    pausar();
}

void eliminarMarca() {
    limpiarPantalla();
    cout << "===== ELIMINAR MARCA =====\n\n";

    Marca m = Marca();
    m.leer();

    short idmarca = 0;
    cout << "\nIngrese el ID de la marca a eliminar: ";
    cin >> idmarca;

    char confirmar;
    cout << "¿Está seguro de eliminar este registro? (S/N): ";
    cin >> confirmar;

    if (confirmar == 'S' || confirmar == 's') {
        m.setIdMarca(idmarca);
        m.eliminar();
        cout << "\nRegistro eliminado. Lista actualizada:\n";
        m.leer();
    } else {
        cout << "\nOperación cancelada.\n";
    }

    pausar();
}

// Implementación de funciones para Puesto
void menuPuestos() {
    int opcion = 0;
    do {
        limpiarPantalla();
        cout << "======================================\n";
        cout << "           GESTIÓN DE PUESTOS        \n";
        cout << "======================================\n\n";
        cout << "1. Ingresar nuevo puesto\n";
        cout << "2. Mostrar todos los puestos\n";
        cout << "3. Actualizar puesto\n";
        cout << "4. Eliminar puesto\n";
        cout << "0. Volver al menú principal\n\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                ingresarPuesto();
                break;
            case 2:
                mostrarPuestos();
                break;
            case 3:
                actualizarPuesto();
                break;
            case 4:
                eliminarPuesto();
                break;
            case 0:
                // Volver al menú principal
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo.\n";
                pausar();
        }
    } while (opcion != 0);
}

void ingresarPuesto() {
    limpiarPantalla();
    cout << "===== INGRESAR NUEVO PUESTO =====\n\n";

    string puesto;

    cout << "Ingrese Nombre de Puesto: ";
    getline(cin, puesto);

    // Usamos 0 como valor temporal para idPuesto, ya que será generado por la base de datos
    Puesto p = Puesto(0, puesto);
    p.crear();

    pausar();
}

void mostrarPuestos() {
    limpiarPantalla();
    cout << "===== LISTADO DE PUESTOS =====\n\n";

    Puesto p = Puesto();
    p.leer();

    pausar();
}

void actualizarPuesto() {
    limpiarPantalla();
    cout << "===== ACTUALIZAR PUESTO =====\n\n";

    Puesto p = Puesto();
    p.leer();

    short idPuesto = 0;
    string puesto;

    cout << "\nIngrese el ID del puesto a modificar: ";
    cin >> idPuesto;
    cin.ignore();
    cout << "Ingrese Nuevo Nombre de Puesto: ";
    getline(cin, puesto);

    p = Puesto(idPuesto, puesto);
    p.actualizar();

    cout << "\nDatos actualizados:\n";
    p.leer();

    pausar();
}

void eliminarPuesto() {
    limpiarPantalla();
    cout << "===== ELIMINAR PUESTO =====\n\n";

    Puesto p = Puesto();
    p.leer();

    short idPuesto = 0;
    cout << "\nIngrese el ID del puesto a eliminar: ";
    cin >> idPuesto;

    char confirmar;
    cout << "¿Está seguro de eliminar este registro? (S/N): ";
    cin >> confirmar;

    if (confirmar == 'S' || confirmar == 's') {
        p.setIdPuesto(idPuesto);
        p.eliminar();
        cout << "\nRegistro eliminado. Lista actualizada:\n";
        p.leer();
    } else {
        cout << "\nOperación cancelada.\n";
    }

    pausar();
}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    system("chcp 65001 > nul");

    int opcion = 0;

    do {
        limpiarPantalla();
        cout << "======================================\n";
        cout << "      SISTEMA DE GESTIÓN GENERAL     \n";
        cout << "======================================\n\n";
        cout << "1. Gestión de Marcas\n";
        cout << "2. Gestión de Puestos\n";
        cout << "3. Gestión de Proveedores\n";
        cout << "4. Gestión de Productos\n";
        cout << "5. Gestión de Empleados\n";
        cout << "6. Gestión de Clientes\n";
        cout << "7. Gestión de Compras\n";
        cout << "8. Gestión de Detalles de Compras\n";
        cout << "9. Gestión de Ventas\n";
        cout << "10. Gestión de Detalles de Ventas\n";
        cout << "0. Salir\n\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                menuMarcas();
                break;
            case 2:
                menuPuestos();
                break;
            case 3:
                menuProveedores();
                break;
            case 4:
                menuProductos();
                break;
            case 5:
                menuEmpleados();
                break;
            case 6:
                menuClientes();
                break;
            case 7:
                menuCompras();
                break;
            case 8:
                menuDetallesCompra();
                break;
            case 9:
                menuVentas();
                break;
            case 10:
                menuDetallesVenta();
                break;
            case 0:
                cout << "\nGracias por usar el sistema. ¡Hasta pronto!\n";
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo.\n";
                pausar();
        }

    } while (opcion != 0);

    return 0;
}