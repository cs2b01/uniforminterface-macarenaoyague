
CREATE TABLE equipo_futbol(
	id					INTEGER PRIMARY KEY,
	nombre				TEXT NOT NULL,
	cantidad_jugadores	INTEGER NOT NULL);

INSERT INTO equipo_futbol VALUES (1, 'Alianza', 40);
INSERT INTO equipo_futbol VALUES (2, 'Cristal', 34);
INSERT INTO equipo_futbol VALUES (3, 'Melgar', 56);

SELECT*FROM equipo_futbol;

CREATE TABLE jugador
(
	id					INTEGER PRIMARY KEY,
	nombre				INTEGER NOT NULL,
	altura				DECIMAL(5, 4) NOT NULL,
	peso				DECIMAL(6, 3) NOT NULL
);

INSERT INTO jugador VALUES (1, 'Rodrigo Morales', 1.70, 33);
INSERT INTO jugador VALUES (2, 'Gonzalo Alfaro', 1.77, 64);


SELECT*FROM jugador;


CREATE TABLE partido(
id_partido INTEGER PRIMARY KEY,
ganador TEXT NOT NULL,
perdedor TEXT NOT NULL,
diferencia_de_goles INTEGER NOT NULL
);

INSERT INTO partido VALUES (1, 'Alianza', 'Universitario', 1);
INSERT INTO partido VALUES (2, 'Cristal', 'Universitario', 3);
INSERT INTO partido VALUES (3, 'Melgar', 'SportsBoys', 2);

SELECT*FROM partido;

CREATE TABLE ranking(
id_ranking INTEGER PRIMARY KEY,
goles_ganador INTEGER NOT NULL,
goles_perdedor INTEGER NOT NULL
);

INSERT INTO ranking VALUES (1, 4, 3);
INSERT INTO ranking VALUES (2, 3, 0);
INSERT INTO ranking VALUES (3, 4, 2);

SELECT * FROM ranking;
