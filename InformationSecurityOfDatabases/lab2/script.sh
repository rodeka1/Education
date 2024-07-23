sudo -u postgres psql << EOF
\c n3250_6;
CREATE SCHEMA n3250_6_schema_lab2;
SET search_path = n3250_6_schema_lab2;
SET datestyle = 'DMY';
CREATE TABLE n3250_6_schema_lab2.users_info
(id INTEGER PRIMARY KEY, username VARCHAR, dateofbirth DATE, team VARCHAR);
INSERT INTO users_info (id, username, dateofbirth, team) VALUES
(1, 'keker', '02/01/1999', 'SomeShiftHappens'),
(2, 'who?', '01/02/2000', 'tipo_komanda'),
(3, 'ivan', '23/07/2000', 'SomeShiftHappens'),
(4, 'doter', '06/06/2001', 'tipo_komanda'),
(5, 'tester', '01/01/1970', 'admins'),
(6, 'mrcool', '05/09/1999', 'admins');
SELECT * FROM users_info;
CREATE TABLE n3250_6_schema_lab2.team_info
(id INTEGER PRIMARY KEY, name VARCHAR, leader_id INTEGER);
INSERT INTO team_info (id, name, leader_id) VALUES
(1, 'SomeShiftHappens', 3),
(2, 'tipo_komanda', 2),
(3, 'admins', 6);
SELECT * FROM n3250_6_schema_lab2.team_info;

EOF