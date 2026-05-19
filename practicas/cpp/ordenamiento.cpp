// Abraham Vallejo - 202108790
// Practica: Algoritmos de Ordenamiento en C++
// Programacion 1 - ECFM/USAC

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ─────────────────────────────────────────
// Parte A: Ordenamiento de Burbuja
// ─────────────────────────────────────────
void burbuja(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= n - 2; i++) {
        bool intercambiado = false;
        for (int j = 0; j <= n - 2 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambiado = true;
            }
        }
        // Optimizacion: si no hubo intercambios, la lista ya esta ordenada
        if (!intercambiado) break;
    }
}

// ─────────────────────────────────────────
// Parte B: Ordenamiento por Seleccion
// ─────────────────────────────────────────
void seleccion(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= n - 2; i++) {
        int min_idx = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

// ─────────────────────────────────────────
// Parte C: Merge Sort
// ─────────────────────────────────────────
vector<int> mezclar(const vector<int>& izq, const vector<int>& der) {
    vector<int> resultado;
    int i = 0, j = 0;
    while (i < (int)izq.size() && j < (int)der.size()) {
        if (izq[i] <= der[j]) {
            resultado.push_back(izq[i]);
            i++;
        } else {
            resultado.push_back(der[j]);
            j++;
        }
    }
    // Agregar elementos restantes
    while (i < (int)izq.size()) resultado.push_back(izq[i++]);
    while (j < (int)der.size()) resultado.push_back(der[j++]);
    return resultado;
}

vector<int> mergesort(const vector<int>& arr) {
    // Caso base: lista de 0 o 1 elemento ya esta ordenada
    if ((int)arr.size() <= 1) return arr;

    int medio = arr.size() / 2;

    vector<int> izq(arr.begin(), arr.begin() + medio);
    vector<int> der(arr.begin() + medio, arr.end());

    izq = mergesort(izq);
    der = mergesort(der);

    return mezclar(izq, der);
}

// ─────────────────────────────────────────
// Main
// ─────────────────────────────────────────
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string algoritmo;
    int n;
    cin >> algoritmo >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (algoritmo == "burbuja") {
        burbuja(arr);
    } else if (algoritmo == "seleccion") {
        seleccion(arr);
    } else if (algoritmo == "mergesort") {
        arr = mergesort(arr);
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << arr[i];
    }
    cout << "\n";

    return 0;
}
