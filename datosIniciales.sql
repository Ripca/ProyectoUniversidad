-- Usar la base de datos
USE PuntoVenta;

-- ===============================
-- INSERTS PARA TABLAS MAESTRAS
-- ===============================

-- Puestos
INSERT INTO Puestos (puesto) VALUES ('Cajero');
INSERT INTO Puestos (puesto) VALUES ('Vendedor');

-- Marcas
INSERT INTO Marcas (marca) VALUES ('Samsung');
INSERT INTO Marcas (marca) VALUES ('LG');

-- Proveedores
INSERT INTO Proveedores (proveedor, nit, direccion, telefono)
VALUES ('Distribuidora Central', '1234567-8', 'Zona 1, Ciudad', '5555-1234');

INSERT INTO Proveedores (proveedor, nit, direccion, telefono)
VALUES ('Tecno S.A.', '8765432-1', 'Zona 10, Ciudad', '5555-5678');

-- Productos (idMarca = 1 y 2)
INSERT INTO Productos (producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso)
VALUES ('Televisor 42"', 1, 'Smart TV Samsung 42 pulgadas', 'tv42.jpg', 2500.00, 3200.00, 10, NOW());

INSERT INTO Productos (producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso)
VALUES ('Refrigeradora 14ft', 2, 'Refrigeradora LG 14 pies', 'fridge14.jpg', 1800.00, 2500.00, 8, NOW());

-- Empleados (idPuesto = 1 y 2)
INSERT INTO Empleados (nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso)
VALUES ('Luis', 'Pérez', 'Zona 3', '5555-1111', '1234567890101', 1, '1990-05-15', 1, '2023-01-01', NOW());

INSERT INTO Empleados (nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso)
VALUES ('Ana', 'Gómez', 'Zona 5', '5555-2222', '1098765432101', 0, '1995-07-22', 2, '2023-06-01', NOW());

-- Clientes
INSERT INTO Clientes (nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso)
VALUES ('Carlos', 'López', '1234567-8', 1, '5555-3333', 'carlos@example.com', NOW());

INSERT INTO Clientes (nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso)
VALUES ('Maria', 'Hernández', '8765432-1', 0, '5555-4444', 'maria@example.com', NOW());

-- ===============================
-- INSERTS PARA MOVIMIENTOS
-- ===============================

-- Compras (idProveedor = 1 y 2)
INSERT INTO Compras (no_order_compra, idproveedor, fecha_order, fecha_ingreso)
VALUES (1001, 1, '2024-06-01', NOW());

INSERT INTO Compras (no_order_compra, idproveedor, fecha_order, fecha_ingreso)
VALUES (1002, 2, '2024-06-10', NOW());

-- Compras_detalle (idCompra = 1 y 2, idProducto = 1 y 2)
INSERT INTO Compras_detalle (idcompra, idproducto, cantidad, precio_unitario)
VALUES (1, 1, 5, 2500.00);

INSERT INTO Compras_detalle (idcompra, idproducto, cantidad, precio_unitario)
VALUES (2, 2, 3, 1800.00);

-- Ventas (idCliente = 1 y 2, idEmpleado = 1 y 2)
INSERT INTO Ventas (nofactura, serie, fechafactura, idcliente, idempleado, fecha_ingreso)
VALUES (2001, 'A', '2024-06-15', 1, 1, NOW());

INSERT INTO Ventas (nofactura, serie, fechafactura, idcliente, idempleado, fecha_ingreso)
VALUES (2002, 'A', '2024-06-20', 2, 2, NOW());

-- Ventas_detalle (idVenta = 1 y 2, idProducto = 1 y 2)
INSERT INTO Ventas_detalle (idventa, idProducto, cantidad, precio_unitario)
VALUES (1, 1, '1', 3200.00);

INSERT INTO Ventas_detalle (idventa, idProducto, cantidad, precio_unitario)
VALUES (2, 2, '2', 2500.00);
