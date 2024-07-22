sudo -u postgres psql << EOF
DROP DATABASE n3250_6;
CREATE DATABASE n3250_6;
\l
\c n3250_6;
CREATE SCHEMA n3250_6_schema_lab1;
\dn
\quit
EOF