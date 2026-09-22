CREATE TABLE movies (
  PRIMARY KEY (id_movie),
  id_movie       INTEGER NOT NULL,
  title_movie    VARCHAR(42),
  year_movie     INTEGER,
  director_movie VARCHAR(42)
);

CREATE TABLE ratings (
  PRIMARY KEY (id_movie, date_rating, id_reviewer),
  id_movie     INTEGER NOT NULL,
  date_rating  VARCHAR(42) NOT NULL,
  id_reviewer  INTEGER NOT NULL,
  stars_rating INTEGER
);

CREATE TABLE reviewers (
  PRIMARY KEY (id_reviewer),
  id_reviewer   INTEGER NOT NULL,
  name_reviewer VARCHAR(42)
);
