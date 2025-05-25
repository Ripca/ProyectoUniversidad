#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include <vector>
#include "ConexionBD.h"

using namespace std;

// Estructura para detalles de venta
struct DetalleVenta {
    int idventa_detalle;
    int idProducto;
    string cantidad;
    double precio_unitario;
};

class Venta {
    // Atributos
private:
    int idVenta = 0;
    int nofactura = 0;
    char serie = 'A';
    string fechafactura;
    int idcliente = 0;
    int idempleado = 0;
    string fecha_ingreso;
    vector<DetalleVenta> detalles;

    // Constructor
public:
    Venta() {}
    Venta(int id, int nf, char s, string ff, int idc, int ide, string fi) {
        idVenta = id;
        nofactura = nf;
        serie = s;
        fechafactura = ff;
        idcliente = idc;
        idempleado = ide;
        fecha_ingreso = fi;
    }

    // Métodos get y set
    void setIdVenta(int id) { idVenta = id; }
    void setNoFactura(int nf) { nofactura = nf; }
    void setSerie(char s) { serie = s; }
    void setFechaFactura(string ff) { fechafactura = ff; }
    void setIdCliente(int idc) { idcliente = idc; }
    void setIdEmpleado(int ide) { idempleado = ide; }
    void setFechaIngreso(string fi) { fecha_ingreso = fi; }
    void agregarDetalle(DetalleVenta detalle) { detalles.push_back(detalle); }
    void limpiarDetalles() { detalles.clear(); }

    int getIdVenta() { return idVenta; }
    int getNoFactura() { return nofactura; }
    char getSerie() { return serie; }
    string getFechaFactura() { return fechafactura; }
    int getIdCliente() { return idcliente; }
    int getIdEmpleado() { return idempleado; }
    string getFechaIngreso() { return fecha_ingreso; }
    vector<DetalleVenta> getDetalles() { return detalles; }

    // Métodos CRUD
    void crear() {
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string nf = to_string(nofactura);
            string s(1, serie);
            string idc = to_string(idcliente);
            string ide = to_string(idempleado);

            // Modificamos la consulta para usar AUTO_INCREMENT
            string consulta = "INSERT INTO Ventas(nofactura, serie, fechafactura, idcliente, idempleado, fecha_ingreso) VALUES (" + nf + ", '" + s + "', '" + fechafactura + "', " + idc + ", " + ide + ", '" + fecha_ingreso + "');";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConector(), c);
            if (!q_estado) {
                cout << "Ingreso de Venta Exitoso..." << endl;

                // Obtener el ID de la venta recién insertada
                q_estado = mysql_query(cn.getConector(), "SELECT LAST_INSERT_ID();");
                if (!q_estado) {
                    MYSQL_RES* resultado = mysql_store_result(cn.getConector());
                    MYSQL_ROW fila = mysql_fetch_row(resultado);
                    string id = fila[0];

                    // Insertar detalles de venta
                    for (DetalleVenta detalle : detalles) {
                        string idprod = to_string(detalle.idProducto);
                        string pu = to_string(detalle.precio_unitario);

                        // Modificamos la consulta para usar AUTO_INCREMENT
                        string consultaDetalle = "INSERT INTO Ventas_detalle(idventa, idProducto, cantidad, precio_unitario) VALUES (" + id + ", " + idprod + ", '" + detalle.cantidad + "', " + pu + ");";
                        const char* cd = consultaDetalle.c_str();
                        q_estado = mysql_query(cn.getConector(), cd);
                        if (q_estado) {
                            cout << "xxx Error al ingresar detalle de venta xxx" << endl;
                            cout << consultaDetalle << endl;
                        }
                    }

                    mysql_free_result(resultado);
                }
                else {
                    cout << "xxx Error al obtener ID de la venta xxx" << endl;
                }
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
    }

    void leer() {
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConector()) {
            string consulta = "SELECT v.idVenta, v.nofactura, v.serie, v.fechafactura, CONCAT(c.nombres, ' ', c.apellidos) as cliente, CONCAT(e.nombres, ' ', e.apellidos) as empleado, v.fecha_ingreso FROM Ventas AS v INNER JOIN Clientes AS c ON v.idcliente = c.idCliente INNER JOIN Empleados AS e ON v.idempleado = e.idEmpleado;";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConector(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConector());
                cout << "------------------------- VENTAS -------------------------" << endl;
                cout << "ID | NO. FACTURA | SERIE | FECHA | CLIENTE | EMPLEADO | FECHA INGRESO" << endl;
                cout << "-----------------------------------------------------------" << endl;
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << endl;
                }
                cout << "-----------------------------------------------------------" << endl;
            }
            else {
                cout << "xxx Error al consultar información xxx" << endl;
            }
        }
        else {
            cout << "xxx Error en la conexión xxx" << endl;
        }
        cn.cerrar_conexion();
    }

    void leerDetalles(int idVenta) {
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConector()) {
            string id = to_string(idVenta);
            string consulta = "SELECT vd.idventa_detalle, p.producto, vd.cantidad, vd.precio_unitario, (vd.cantidad * vd.precio_unitario) as subtotal FROM Ventas_detalle AS vd INNER JOIN Productos AS p ON vd.idProducto = p.idProducto WHERE vd.idventa = " + id + ";";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConector(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConector());
                cout << "------------------------- DETALLES DE VENTA -------------------------" << endl;
                cout << "ID | PRODUCTO | CANTIDAD | PRECIO UNITARIO | SUBTOTAL" << endl;
                cout << "-------------------------------------------------------------------" << endl;
                double total = 0;
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << endl;
                    total += atof(fila[4]);
                }
                cout << "-------------------------------------------------------------------" << endl;
                cout << "TOTAL: " << total << endl;
                cout << "-------------------------------------------------------------------" << endl;
            }
            else {
                cout << "xxx Error al consultar información xxx" << endl;
            }
        }
        else {
            cout << "xxx Error en la conexión xxx" << endl;
        }
        cn.cerrar_conexion();
    }

    void actualizar() {
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string id = to_string(idVenta);
            string nf = to_string(nofactura);
            string s(1, serie);
            string idc = to_string(idcliente);
            string ide = to_string(idempleado);

            string consulta = "UPDATE Ventas SET nofactura = " + nf + ", serie = '" + s + "', fechafactura = '" + fechafactura + "', idcliente = " + idc + ", idempleado = " + ide + ", fecha_ingreso = '" + fecha_ingreso + "' WHERE idVenta = " + id + ";";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConector(), c);
            if (!q_estado) {
                cout << "Actualización de Venta Exitosa..." << endl;
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
    }

    void eliminar() {
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string id = to_string(idVenta);

            // Primero eliminar los detalles
            string consultaDetalles = "DELETE FROM Ventas_detalle WHERE idventa = " + id + ";";
            const char* cd = consultaDetalles.c_str();
            q_estado = mysql_query(cn.getConector(), cd);
            if (!q_estado) {
                // Luego eliminar la venta
                string consulta = "DELETE FROM Ventas WHERE idVenta = " + id + ";";
                const char* c = consulta.c_str();
                q_estado = mysql_query(cn.getConector(), c);
                if (!q_estado) {
                    cout << "Eliminación de Venta Exitosa..." << endl;
                }
                else {
                    cout << "xxx Error al eliminar venta xxx" << endl;
                    cout << consulta << endl;
                }
            }
            else {
                cout << "xxx Error al eliminar detalles de venta xxx" << endl;
                cout << consultaDetalles << endl;
            }
        }
        else {
            cout << "xxx Error en la conexión xxx" << endl;
        }
        cn.cerrar_conexion();
    }
};
