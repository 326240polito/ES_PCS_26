#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, const char*argv[]) {
    //se l'utente non specifica il file come parametro il programma si chiude restituendo errrore
    if (argc < 2){
        cout << "Errore: File name not declared as parameter. \n";
        return 1;
    }
string file_name = argv[1]; //il nome del file è quello scritto nel file come secondo parametro
    ifstream ifs(file_name);  //apro il file
    if (ifs.is_open()){
        while (!ifs.eof()){
            string city;
            double t1, t2, t3, t4;
            for(int i=0; i<3; i++){
                if (ifs >> city >> t1 >> t2 >> t3 >> t4){
                    double mean = (t1+t2+t3+t4)/4.0;
                    cout << city << " " << mean << "\n";
                }
            }
        }
    }
    else{
        cout << "Error: unable to open " << file_name << "\n";
        return 1;
    }
    return 0;
}


    
