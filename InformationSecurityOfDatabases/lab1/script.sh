sudo -u postgres psql << EOF
DROP DATABASE n3250_6;
\echo 2
CREATE DATABASE n3250_6; 
\l
\echo 3
\c n3250_6; 
\echo 4
CREATE SCHEMA n3250_6_schema_lab1; 
\echo 5
CREATE TABLE n3250_6_tbl1(something text); 
CREATE TABLE n3250_6_schema_lab1.n3250_6_tbl2(something text);
SET search_path = public, n3250_6_schema_lab1; 
\dt
\echo 6
CREATE TABLE n3250_6_schema_lab1.n3250_6_table_i5 
(a INTEGER, b VARCHAR, c CHAR, d TIMESTAMP, e DATE, f BYTEA);
\dt
\echo 7
CREATE TALBE n3250_6_schema_lab1.n3250_6_table_i6(year INTEGER DEFAULT 2024, time_interval INTERVAL);
\dt
\echo 8
CREATE TYPE n3250_6_schema_lab1.n3250_6_type AS
(pr1 real, pr2 real, pr3 real, pr4 bytea);
\dT
\echo 9
CREATE TYPE n3250_6_schema_lab1.n3250_6_enum AS ENUM
('large', 'medium', 'small');
\T
\dT
\echo 10
CREATE DOMAIN n3250_6_schema_lab1.n3250_6_domain AS INTEGER CONSTRAINT check_validation CHECK (VALUE > 99 AND VALUE <1000);
\dT
\echo 11
CREATE SEQUENCE n3250_6_seq START WITH 1000 INCREMENT BY -1 MAXVALUE 1000;
SELECT nextval('n3250_6_seq');
SELECT nextval('n3250_6_seq');
\echo 12
CREATE INDEX n3250_6_idx1 ON n3250_6_table_i5(a);
\di
\echo 13
CREATE INDEX n3250_6_idx2 ON n3250_6_table_i5(a, e);
\di
\echo 14
CREATE INDEX n3250_6_idx3 ON n3250_6_table_i5((a%10));
\di
\echo 15
CREATE INDEX n3250_6_idx4 ON n3250_6_table_i5(a) WHERE a>=100 AND a<=1000;
\di
\echo 16
CREATE TABLE n3250_6_schema_lab1.n3250_6_notnull 
(a INTEGER, b VARCHAR, c CHAR NOT NULL, d TIMESTAMP, e DATE, f BYTEA);
\dt
\echo 17
CREATE TABLE n3250_6_schema_lab1.n3250_6_unique
(a INTEGER, b VARCHAR, c CHAR, d TIMESTAMP, e DATE, f BYTEA, CONSTRAINT unique_validation UNIQUE(a, c));
\dt
\echo 18
CREATE TABLE n3250_6_schema_lab1.n3250_6_pk
(a INTEGER PRIMARY KEY, b VARCHAR, c CHAR, d TIMESTAMP, e DATE, f BYTEA);
\dt
\echo 19
CREATE TABLE n3250_6_schema_lab1.n3250_6_check
(a INTEGER, b VARCHAR, c CHAR, d TIMESTAMP, e DATE, f BYTEA, CONSTRAINT cehck_containts_a CHECK(b LIKE 'a'));
\dt
\echo 20
CREATE VIEW n3250_6_schema_lab1.n3250_6_view AS SELECT b, e FROM n3250_6_table_i5;
\dv
\quit
EOF