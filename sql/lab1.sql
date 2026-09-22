CREATE TABLE clients (
    id INT AUTO_INCREMENT PRIMARY KEY,
    fullname VARCHAR(40) NOT NULL,
    adress VARCHAR(200) NOT NULL
);

CREATE TABLE masters (
    id INT AUTO_INCREMENT PRIMARY KEY,
    fullname VARCHAR(40) NOT NULL,
    price FLOAT NOT NULL,
    orders VARCHAR(40) NOT NULL
);

CREATE TABLE car (
    id INT AUTO_INCREMENT PRIMARY KEY,
    make VARCHAR(20) NOT NULL,
    model VARCHAR(20) NOT NULL,
    wheels SMALLINT NOT NULL,
    client_id INT NOT NULL,
    master_rab INT NOT NULL,
    descriptions TEXT NOT NULL,
    FOREIGN KEY (client_id) REFERENCES clients(id) ON DELETE CASCADE,
    FOREIGN KEY (master_rab) REFERENCES masters(id) ON DELETE CASCADE
);

INSERT INTO clients (fullname, adress) VALUES 
('Владимир Путин', 'ул. Ленина 10'),
('Николай Холокостов', 'ул. Северная 5'),
('Дональд Дональдсон', 'ул. Пушкина 7');

INSERT INTO masters (fullname, price, orders) VALUES 
('Мастер Михаил', 1500.50, 'Замена масла'),
('Мастер Джеффри', 2000.00, 'Ремонт двигателя'),
('Мастер Джимбо', 1200.00, 'Шиномонтаж');

INSERT INTO car (make, model, wheels, client_id, master_rab, descriptions) VALUES 
('Toyota', 'Camry', 4, 1, 1, 'Плановое ТО'),
('BMW', 'X5', 4, 2, 2, 'Стучит двигатель'),
('Lada', 'Vesta', 4, 3, 3, 'Замена колес'),
('Ford', 'Focus', 4, 1, 2, 'Диагностика');

SELECT * FROM clients;
SELECT * FROM masters;
SELECT * FROM car;
