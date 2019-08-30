#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

float calcularDistancia(pair <float, float> pair1, pair <float, float> pair2){
        float distancia_x = abs(pair1.first - pair2.first);
        float distancia_y = abs(pair1.second - pair2.second);


        return (float)sqrt(pow(distancia_x, 2) + pow(distancia_y, 2));
}

int main() {
    float num1, num2;
    int numero;
    float distancia_min = 40000, temp;
    pair <float, float>* lista;

    do{


        cin >> numero;
        lista = new pair <float, float> [numero];
        for(int i = 0; i < numero; i++){
            cin >> lista[i].first >> lista[i].second;
        }

        for(int i = 0; i < numero; i++){
            for(int k = i+1; k < numero; k++){
                temp = calcularDistancia(lista[i], lista[k]);
                if(temp  <  distancia_min){
                    distancia_min = temp;
                }

            }
        }
        if(numero!=0){
            if(distancia_min >= 10000){
                cout <<"INFINITY" << endl;
            }else{
                cout<< fixed << setprecision(4) << distancia_min<<endl;
            }
        }

        distancia_min = 40000;

        delete lista;
    }while (numero!=0);

    return 0;
}