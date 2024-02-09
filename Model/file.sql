DROP TABLE IF EXISTS membre;
DROP TABLE IF EXISTS livre;


CREATE TABLE membre (
    num_membre INTEGER PRIMARY KEY AUTOINCREMENT,
    nom TEXT ,
    age INTEGER
);
CREATE TABLE document (
    num_document INTEGER PRIMARY KEY AUTOINCREMENT, 
    titre TEXT 
);
CREATE TABLE emprunt (
    n_emprunt INTEGER PRIMARY KEY AUTOINCREMENT,
    date_emprunt DATE,
    date_retour DATE,
    date_retour_effectif DATE,
    id_membre INTEGER,
    id_document INTEGER,
    FOREIGN KEY (id_membre) REFERENCES membre(num_membre),
    FOREIGN KEY (id_document) REFERENCES document(num_document)
);

INSERT INTO membre (nom, age) VALUES ('Jean Dupont', 30);
INSERT INTO membre (nom, age) VALUES ('Marie Durand', 25);

INSERT INTO document (titre) VALUES ('Le Petit Prince');
INSERT INTO document (titre) VALUES ('1984');
INSERT INTO document (titre) VALUES ('L\Étranger');

INSERT INTO emprunt (date_emprunt, date_retour, date_retour_effectif, id_membre, id_document) 
VALUES ('2024-02-01', '2024-02-15', NULL, 1, 1); -- Jean Dupont emprunte Le Petit Prince
INSERT INTO emprunt (date_emprunt, date_retour, date_retour_effectif, id_membre, id_document) 
VALUES ('2024-01-15', '2024-02-28', NULL, 2, 2); -- Marie Durand emprunte 1984
INSERT INTO emprunt (date_emprunt, date_retour, date_retour_effectif, id_membre, id_document) 
VALUES ('2024-02-10', '2024-03-10', NULL, 1, 3); -- Jean Dupont emprunte L'Étranger

-- Sélectionner une ligne de la table "membre"
SELECT * FROM membre ;

-- Sélectionner une ligne de la table "document"
SELECT * FROM document;

-- Sélectionner une ligne de la table "emprunt"
SELECT * FROM emprunt;

SELECT document.titre
FROM emprunt
JOIN membre ON emprunt.id_membre = membre.num_membre
JOIN document ON emprunt.id_document = document.num_document
WHERE membre.nom = 'Jean Dupont';

-- UPDATE utilisateurs
-- SET age = 30
-- WHERE nom = 'Jean';

-- DELETE FROM utilisateurs
-- WHERE id = 5;
UPDATE membre SET nom = 'Tony Parker', age = 67 WHERE num_membre = 5;

SELECT name FROM sqlite_master WHERE type='table';