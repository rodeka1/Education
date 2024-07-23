sudo -u postgres psql << EOF
\c n3250_6;
CREATE SCHEMA n3250_6_schema_lab3;
SET search_path = n3250_6_schema_lab3;
CREATE TABLE n3250_6_schema_lab3.boosters_info (id INTEGER PRIMARY KEY, name VARCHAR, count_of_orders INTEGER, rating REAL, balance INTEGER);
INSERT INTO boosters_info (id, name, count_of_orders, rating) VALUES
(1, 'alice_smith', 12, 4.7),
(2, 'bob_johnson', 25, 3.9),
(3, 'carol_davis', 8, 4.5),
(4, 'dave_wilson', 30, 4.2),
(5, 'eve_martin', 15, 4.8);
SELECT * FROM boosters_info
CREATE TABLE n3250_6_schema_lab3.service_list (id INTEGER PRIMARY KEY, name VARCHAR, cost INTEGER);
INSERT INTO service_list (id, name, cost) VALUES
(1, 'raid', 5);
(2, 'dungeon', 3);
SELECT * FROM service_list;
CREATE TABLE n3250_6_schema_lab3.orders_info (id INTEGER PRIMARY KEY, service_id INTEGER, booster_id INTEGER, is_done BOOLEAN);
\echo 1
\quit
EOF