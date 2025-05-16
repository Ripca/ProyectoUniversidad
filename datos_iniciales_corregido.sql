-- Script para insertar 3 registros en cada tabla
USE PuntoVenta;

-- Insertar datos en la tabla Puestos
INSERT INTO Puestos (idPuesto, puesto) VALUES 
(1, 'Gerente'),
(2, 'Vendedor'),
(3, 'Cajero');

-- Insertar datos en la tabla Marcas
INSERT INTO Marcas (idmarca, marca) VALUES 
(1, 'Samsung'),
(2, 'Apple'),
(3, 'Sony');

-- Insertar datos en la tabla Proveedores (corregido nt a nit)
INSERT INTO Proveedores (idProveedor, proveedor, nit, direccion, telefono) VALUES 
(1, 'Distribuidora Tecnológica', '12345678', 'Zona 10, Ciudad de Guatemala', '2222-1111'),
(2, 'Importadora Digital', '87654321', 'Zona 4, Ciudad de Guatemala', '2222-2222'),
(3, 'Electrónicos GT', '98765432', 'Zona 9, Ciudad de Guatemala', '2222-3333');

-- Insertar datos en la tabla Productos
INSERT INTO Productos (idProducto, producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso) VALUES 
(1, 'Televisor 50"', 1, 'Televisor Samsung Smart TV 50 pulgadas', 'tv_samsung.jpg', 3000.00, 4500.00, 10, NOW()),
(2, 'iPhone 13', 2, 'Smartphone Apple iPhone 13 128GB', 'iphone13.jpg', 7000.00, 9000.00, 15, NOW()),
(3, 'Audífonos WH-1000XM4', 3, 'Audífonos Sony con cancelación de ruido', 'sony_wh1000xm4.jpg', 1800.00, 2500.00, 20, NOW());

-- Insertar datos en la tabla Empleados
INSERT INTO Empleados (idEmpleado, nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso) VALUES 
(1, 'Juan', 'Pérez', 'Zona 7, Ciudad de Guatemala', '5555-1111', '1234567890101', 1, '1990-05-15', 1, '2020-01-10', NOW()),
(2, 'María', 'López', 'Zona 11, Ciudad de Guatemala', '5555-2222', '2345678901201', 0, '1995-08-20', 2, '2021-03-15', NOW()),
(3, 'Carlos', 'Ramírez', 'Zona 6, Ciudad de Guatemala', '5555-3333', '3456789012301', 1, '1988-11-30', 3, '2019-06-01', NOW());

-- Insertar datos en la tabla Clientes
INSERT INTO Clientes (idCliente, nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso) VALUES 
(1, 'Ana', 'Gómez', 'CF', 0, '4444-1111', 'ana.gomez@email.com', NOW()),
(2, 'Roberto', 'Hernández', '987654-3', 1, '4444-2222', 'roberto.hernandez@email.com', NOW()),
(3, 'Lucía', 'Martínez', '123456-7', 0, '4444-3333', 'lucia.martinez@email.com', NOW());

-- Insertar datos en la tabla Compras
INSERT INTO Compras (idcompra, no_order_compra, idproveedor, fecha_order, fecha_ingreso) VALUES 
(1, 1001, 1, '2023-05-01', NOW()),
(2, 1002, 2, '2023-05-10', NOW()),
(3, 1003, 3, '2023-05-20', NOW());

-- Insertar datos en la tabla Compras_detalle
INSERT INTO Compras_detalle (idcompra_detalle, idcompra, idproducto, cantidad, precio_unitario) VALUES 
(1, 1, 1, 5, 3000.00),
(2, 2, 2, 3, 7000.00),
(3, 3, 3, 10, 1800.00);

-- Insertar datos en la tabla Ventas
INSERT INTO Ventas (idVenta, nofactura, serie, fechafactura, idcliente, idempleado, fecha_ingreso) VALUES 
(1, 1, 'A', '2023-06-01', 1, 2, NOW()),
(2, 2, 'A', '2023-06-05', 2, 2, NOW()),
(3, 3, 'A', '2023-06-10', 3, 2, NOW());

-- Insertar datos en la tabla Ventas_detalle
INSERT INTO Ventas_detalle (idventa_detalle, idventa, idProducto, cantidad, precio_unitario) VALUES 
(1, 1, 1, '1', 4500.00),
(2, 2, 2, '1', 9000.00),
(3, 3, 3, '2', 2500.00);

-- Verificar los datos insertados
SELECT 'Puestos' AS Tabla, COUNT(*) AS Registros FROM Puestos
UNION ALL
SELECT 'Marcas', COUNT(*) FROM Marcas
UNION ALL
SELECT 'Proveedores', COUNT(*) FROM Proveedores
UNION ALL
SELECT 'Productos', COUNT(*) FROM Productos
UNION ALL
SELECT 'Empleados', COUNT(*) FROM Empleados
UNION ALL
SELECT 'Clientes', COUNT(*) FROM Clientes
UNION ALL
SELECT 'Compras', COUNT(*) FROM Compras
UNION ALL
SELECT 'Compras_detalle', COUNT(*) FROM Compras_detalle
UNION ALL
SELECT 'Ventas', COUNT(*) FROM Ventas
UNION ALL
SELECT 'Ventas_detalle', COUNT(*) FROM Ventas_detalle;
