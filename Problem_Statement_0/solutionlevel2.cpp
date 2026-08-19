#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// function for sorting(buuble)
vector<double> sortweights(vector<double> w) {
    int size = w.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (w[j] > w[j + 1]) {
                double temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
        }
    }
    return w;
}

int main() {
    int shipscount = 0;
    string keepgoing = "yes";

    // loop to handle multiple ships
    while (keepgoing == "yes" ) {
        cout << endl << "NEW SHIPMENT " << endl;
        
        double capacity = 0;
        int n = 0;
        vector<double> weights;

        // file naming and yes no
        cout << "Do you want to read from a file? (yes/no): ";
        string choice;
        cin >> choice;

        if (choice == "yes" || choice == "y") {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            
            ifstream file(filename);
            if (file.is_open()) {
                file >> n;
                weights.resize(n);
                for (int i = 0; i < n; i++) {
                    file >> weights[i];
                }
                file.close();
                
                cout << "Loaded " << n << " containers from " << filename << endl;
                cout << "Weights: ";
                for (int i = 0; i < n; i++) {
                    cout << weights[i] << (i == n - 1 ? "" : ", ");
                }
                cout << endl;
                
                cout << "Enter port capacity: ";
                cin >> capacity;
            } else {
                cout << "Couldn't open file. Let's do manual entry instead." << endl;
                cout << "Enter port capacity: ";
                cin >> capacity;
                cout << "Enter number of containers: ";
                cin >> n;
                weights.resize(n);
                for (int i = 0; i < n; i++) {
                    cin >> weights[i];
                }
            }
        } else {
            cout << "Enter port capacity: ";
            cin >> capacity;
            cout << "Enter number of containers: ";
            cin >> n;
            weights.resize(n);
            for (int i = 0; i < n; i++) {
                cin >> weights[i];
            }
        }

        if (n <= 0) {
            cout << "Invalid container count. Skipping." << endl;
            continue;
        }

        // finding total and average
        double totalweight = 0;
        for (int i = 0; i < n; i++) {
            totalweight += weights[i];
        }
        double avgweight = totalweight / n;

        // finding heavy and light by basic one by one comparison
        double heaviest = weights[0];
        double lightest = weights[0];
        for (int i = 1; i < n; i++) {
            if (weights[i] > heaviest) {
                heaviest = weights[i];
            }
            if (weights[i] < lightest) {
                lightest = weights[i];
            }
        }

        // classification & status
        string classification = "Light";
        if (totalweight >= 200) {
            classification = "Heavy";
        }

        string status = "Shipment can be unloaded";
        if (totalweight > capacity) {
            status = "Shipment exceeds port capacity";
        }

        // printing all the output for that one
        cout << fixed << setprecision(1);
        cout << endl << "--- Shipment Report ---" << endl;
        cout << "Total Shipment Weight: " << totalweight << endl;
        cout << "Average Container Weight: " << avgweight << endl;
        cout << "Heaviest Container: " << heaviest << endl;
        cout << "Lightest Container: " << lightest << endl;
        cout << "Classification: " << classification << endl;
        cout << "Port Capacity: " << capacity << endl;
        cout << "Status: " << status << endl;

        // feature 1: sorting using sorting function we made upper
        cout << endl << "Containers in sorted order:" << endl;
        vector<double> sortedlist = sortweights(weights);
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ". " << sortedlist[i] << endl;
        }

        // feature 3: bar chart to represent
        cout << endl << "Container Weight Bar Chart:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Container " << i + 1 << " (" << weights[i] << ")  : ";
            int stars = weights[i] / 5;
            for (int s = 0; s < stars; s++) {
                cout << "*";
            }
            cout << endl;
        }
        cout << endl << "(Each * represents 5 units)" << endl;

        // feature 6: search
        cout << endl << "Enter a weight to search for: ";
        double target;
        cin >> target;
        int foundat = -1;
        for (int i = 0; i < n; i++) {
            if (weights[i] == target) {
                foundat = i + 1;
                break;
            }
        }
        if (foundat != -1) {
            cout << "Container found!" << endl;
            cout << "Container " << foundat << " has weight " << target << endl;
        } else {
            cout << "No container found with weight " << target << endl;
        }

        // feature 7: finding kth heaveist in ship
        cout << endl << "Enter K to find the Kth heaviest container: ";
        int k;
        cin >> k;
        if (k <= 0) {
            cout << "Invalid input: N must be at least 1." << endl;
        } else if (k > n) {
            cout << "Invalid input: Only " << n << " containers exist." << endl;
        } else {
            // alogrithm using basic a,b and temp 
            vector<double> desc = weights;
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (desc[j] < desc[j + 1]) {
                        double temp = desc[j];
                        desc[j] = desc[j + 1];
                        desc[j + 1] = temp;
                    }
                }
            }
            string suffix = "th";
            if (k == 1) suffix = "st";
            else if (k == 2) suffix = "nd";
            else if (k == 3) suffix = "rd";

            cout << "The " << k << suffix << " heaviest container has weight: " << desc[k - 1] << endl;
        }

        // custom feature= port efficiency rating 
        cout << endl << "Custom Feature: Port Efficiency " << endl;
        double efficiencyratio = (totalweight / capacity) * 100;
        cout << "Port Efficiency Rating: " << efficiencyratio << "%" << endl;
        if (efficiencyratio <= 100) {
            cout << "Efficiency Status: Under Capacity" << endl;
        } else {
            cout << "Efficiency Status: Over Capacity" << endl;
        }

        // feature 4: saving the report
        cout << endl << "Do you want to save this report to a file? (yes/no): ";
        string saveans;
        cin >> saveans;
        if (saveans == "yes" || saveans == "y") {
            string outname;
            cout << "Enter output filename: ";
            cin >> outname;
            
            ofstream outfile(outname);
            if (outfile.is_open()) {
                outfile << "Total Shipment Weight: " << totalweight << endl;
                outfile << "Average Container Weight: " << avgweight << endl;
                outfile << "Heaviest Container: " << heaviest << endl;
                outfile << "Lightest Container: " << lightest << endl;
                outfile << "Classification: " << classification << endl;
                outfile.close();
                cout << "Report saved to " << outname << endl;
            } else {
                cout << "Error writing to file." << endl;
            }
        }

        shipscount++;

        // feature 2: multi ship checking process
        cout << endl << "Do you want to process another ship? (yes/no): ";
        cin >> keepgoing;
    }

    cout << endl << "Total ships processed: " << shipscount << endl;
    return 0;
}