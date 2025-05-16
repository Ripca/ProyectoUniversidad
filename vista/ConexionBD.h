#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;
class ConexionBD{

private: MYSQL* conector;
public :
	void abrir_conexion() {
		conector = mysql_init(0);
		conector = mysql_real_connect(conector, "localhost", "root", "admin", "puntoventa", 3306, NULL, 0);

		// Configurar el conjunto de caracteres para manejar tildes y caracteres especiales
		if (conector) {
			mysql_set_character_set(conector, "utf8mb4");
		}
	}
	MYSQL* getConector() {
		return conector;
	}
		void cerrar_conexion() {
			mysql_close(conector);
		}
};

