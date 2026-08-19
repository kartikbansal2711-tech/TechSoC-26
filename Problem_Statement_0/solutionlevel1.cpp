#include <iostream>
#include <vector>
using namespace std;
int main() {
    // taking all the inputs
    double capacity;
    int n;
    
    cin >> capacity;
    cin >> n;
    
    vector<double> weights(n);
    double total = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
        total += weights[i];
    }
    // calculating the average
    double avg = total / n;
    // method to find the heaviest and lightest without using sorting the vector
    double heaviest = weights[0];
    double lightest = weights[0];
    for(int i = 1; i < n; i++) {
        if(weights[i] > heaviest) {
            heaviest = weights[i];
        }
        if(weights[i] < lightest) {
            lightest = weights[i];
        }
    }
    // cateogarizing as heavy and light
    string classification;
    if(total >= 200) {
        classification = "Heavy";
    } else {
        classification = "Light";
    }
    // checking if it can be unload or not
    string statuss;
    if(total <= capacity) {
        statuss = "Shipment can be unloaded";
    } else {
        statuss = "Shipment exceeds port capacity";
    }
    //printing all the outputss
    cout << "Total Shipment Weight: " << total << endl;
    cout << "Average Container Weight: " << avg << endl;
    cout << "Heaviest Container: " << heaviest << endl;
    cout << "Lightest Container: " << lightest << endl;
    cout << "Classification: " << classification << endl;
    cout << "Port Capacity: " << capacity << endl;
    cout << "Status: " << statuss << endl;
    
    return 0;
}