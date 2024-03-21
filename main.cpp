#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Structure pour représenter un point sur la grille
struct Point {
    int x, y;
};

// Structure pour représenter une tuile
struct Tile {
    string id;
    int cost, count;
};

// Fonction pour lire l'entrée à partir du fichier
void lireEntree(string nomFichier) {
    ifstream fichier(nomFichier);
    if (fichier) {
        int W, H, GN, SM, TL;
        fichier >> W >> H >> GN >> SM >> TL;

        cout << "Largeur de la grille : " << W << endl;
        cout << "Hauteur de la grille : " << H << endl;
        cout << "Nombre de points dorés : " << GN << endl;
        cout << "Nombre de points d'argent : " << SM << endl;
        cout << "Nombre de types de tuiles disponibles : " << TL << endl;

        vector<Point> goldenPoints(GN);
        vector<Point> silverPoints(SM);
        vector<Tile> tiles(TL);

        // Lire les données des points dorés
        cout << "Coordonnées des points dorés :" << endl;
        for (int i = 0; i < GN; ++i) {
            fichier >> goldenPoints[i].x >> goldenPoints[i].y;
            cout << goldenPoints[i].x << " " << goldenPoints[i].y << endl;
        }

        // Lire les données des points d'argent
        cout << "Coordonnées et scores des points d'argent :" << endl;
        for (int i = 0; i < SM; ++i) {
            fichier >> silverPoints[i].x >> silverPoints[i].y;
            int score;
            fichier >> score;
            cout << silverPoints[i].x << " " << silverPoints[i].y << " " << score << endl;
        }

        // Lire les données des tuiles
        cout << "Données des tuiles :" << endl;
        for (int i = 0; i < TL; ++i) {
            fichier >> tiles[i].id >> tiles[i].cost >> tiles[i].count;
            cout << tiles[i].id << " " << tiles[i].cost << " " << tiles[i].count << endl;
        }

        fichier.close();
    } else {
        cerr << "Erreur: Impossible d'ouvrir le fichier d'entrée." << endl;
    }
}

int main() {
    lireEntree("fichier_entree.txt");

    return 0;
}
