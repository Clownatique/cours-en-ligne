-- 1.2

drop schema if exists cinema cascade;
create schema cinema;
set search_path to cinema;

-- 1.3

\i cours/bda/tp/tp1-base.sql

-- question 1.4

alter table movies add constraint uk unique(year_movie,title_movie);

-- question 1.5
\i cours/bda/tp/TP1_moviedata.sql

-- question 2.1

SELECT * FROM reviewers where id_reviewer = 205;

-- question 2.2

SELECT title_movie FROM movies;

-- question 2.3

SELECT title_movie FROM movies ORDER BY title_movie;

-- question 2.4

SELECT title_movie FROM movies WHERE director_movie = 'Steven Spielberg';

-- quesetion 2.5

SELECT title_movie FROM movies WHERE director_movie IS NULL;

-- question 2.6

CREATE VIEW v_details_evaluations AS SELECT m.title_movie, id_movie, year_movie, director_movie, stars_rating, name_reviewer, date_rating FROM movies AS m JOIN ratings AS r USING(id_movie) JOIN reviewers AS c USING(id_reviewer);

-- question 2.7

SELECT DISTINCT year_movie FROM v_details_evaluations WHERE stars_rating  BETWEEN 4 AND 5 ORDER BY year_movie;

-- question 2.8

SELECT DISTINCT name_reviewer FROM v_details_evaluations WHERE stars_rating IS NOT NULL AND title_movie = 'Gone with the Wind';

-- question 2.9

SELECT DISTINCT name_reviewer, title_movie, stars_rating FROM v_details_evaluations WHERE director_movie = name_reviewer;

-- question 2.10

SELECT name_reviewer, title_movie, stars_rating FROM v_details_evaluations

-- question 2.11

SELECT f.title_movie FROM (SELECT title_movie,id_movie FROM v_details_evaluations EXCEPT (SELECT title_movie,id_movie FROM v_details_evaluations WHERE name_reviewer = 'Chris Jackson')) f;

-- question 2.12

