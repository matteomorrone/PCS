#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) 
{
    // Controllo se è specificato il nome del file: se argc è 1 vuol dire che è stato specificato solo il nome del programma e quindi restituisce errore
    if (argc < 2)
    {
        cout << "Errore: manca il nome del file!" << endl;
        return 1;
    }
    string filename = argv[1]; // Prendo il nome del file dai parametri
    ifstream ifs(filename);
    // Controllo se è aperto (come nell'esercizio della lezione 03_stream_io, slide 9)
    if (ifs.is_open()) 
    { 
        while(!ifs.eof()) 
        {
            string citta;
            double t1, t2, t3, t4;
            ifs >> citta >> t1 >> t2 >> t3 >> t4;
            double media = (t1 + t2 + t3 + t4) / 4.0; // Calcolo la media
            cout << citta << " " << media << endl; // Stampo il risultato
        }
        ifs.close();
    }  
    else
    { 
        cout << "Errore apertura file!" << endl;
        return 1;
    }
    return 0;
}