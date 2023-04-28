#include "tree3.h"
#include <chrono>
using namespace chrono;

int main() {

    //instantiating structures
    unordered_map<string, tree3> mapT;
    unordered_map<string, heaps> mapH;

    // Open the file
    ifstream file("cars.csv");

    // Read the file line by line
    string line;
    getline(file, line);
    //cout << line << endl;
    string model;
    while (getline(file, line)) {
        // Create a stringstream to read each column
        stringstream ss(line);

        // Read the values for each column
        int year, mileage;
        float price, mpg;
        getline(ss, model, ',');
        ss >> year;
        ss.ignore();
        ss >> price;
        ss.ignore();
        ss >> mileage;
        ss.ignore();
        ss >> mpg;

        //cout << model << "" << year << "" << price << "" << mileage << "" << mpg << endl;

        model = model.substr(1);
        car* c = new car(model, mileage, year, price, mpg);

        //each model has separate structures for searching within a specific model
        mapT[model].insertCar(c);
        mapH[model].insertCar(*c);

        //inserting all cars into global structures
        mapT["All Cars"].insertCar(c);
        mapH["All Cars"].insertCar(*c);

    }

    file.close();

    int choice1 = 0;
    int choice2 = 0;

    cout << "~Welcome to Girls Who Car~" << endl;
    cout << endl;

    while ((choice1 != -1) && (choice2 != -1))
    {
        cout << "Please choose an option:" << endl;
        cout << "1. Search all models" << endl;
        cout << "2. Search a specific model" << endl;
        cout << "-1 to quit" << endl;
        cin >> choice1;

        string chosenModel;
        if (choice1 == -1)
        {
            break;
        }
        if (choice1 == 1)
        {
            chosenModel = "All Cars";
        }
        else
        {
            cout << "Please enter the model you'd like to search" << endl;
            cin >> chosenModel;
        }

        cout << "Please choose a search method:" << endl;
        cout << "1. Cheapest" << endl;
        cout << "2. Newest" << endl;
        cout << "3. Least mileage" << endl;
        cout << "4. Highest mpg" << endl;
        cout << "5. Cars within a price range" << endl;
        cout << "6. Cars within a year range" << endl;
        cout << "7. Cars within a mileage range" << endl;
        cout << "8. Cars within a mpg range" << endl;
        cout << "-1 to quit" << endl;
        cin >> choice2;

        if (choice2 == -1)
        {
            break;
        }

        car cheapest, newest, leastMileage, highestMpg;
        vector<car *> inPrRange, inYrRange, inMRange, inMPGRange;
        vector<car> inPrRangeH, inYrRangeH, inMRangeH, inMPGRangeH;

        auto start = high_resolution_clock::now();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);


        switch (choice2)
        {
            case 1:
                // search for the cheapest

                start = high_resolution_clock::now(); //start timer
                cheapest = mapT[chosenModel].findCheapest();
                stop = high_resolution_clock::now(); //end timerduration = duration_cast<microseconds>(stop - start);
                duration = duration_cast<nanoseconds>(stop - start);

                cout << endl;
                cout << chosenModel << endl;
                cout << "Cheapest****************************************************" << endl;
                cout << "Model: " << cheapest.getModel() << "  Year: " << cheapest.getYear() << "  Price: "
                     << cheapest.getPrice() << "  Mileage: " << cheapest.getMileage() << "  MPG: " << cheapest.getMpg()
                     << endl;
                cout << endl;
                cout << "Elapsed time for 2-3 Tree: " << duration.count() << " nanoseconds" << endl;

                start = high_resolution_clock::now(); //start timer
                cheapest = mapH[chosenModel].findCheapest();
                stop = high_resolution_clock::now();
                duration = duration_cast<nanoseconds>(stop - start);
                cout << "Elapsed time for Heap: " << duration.count() << " nanoseconds" << endl;
                cout << "************************************************************" << endl;
                cout << endl << endl;


                break;
            case 2:
                // search all cars for the newest

                start = high_resolution_clock::now(); //start timer
                newest = mapT[chosenModel].findNewest();
                stop = high_resolution_clock::now(); //end timerduration = duration_cast<microseconds>(stop - start);
                duration = duration_cast<nanoseconds>(stop - start);

                cout << endl;
                cout << chosenModel << endl;
                cout << "Newest****************************************************" << endl;
                cout << "Model: " << newest.getModel() << "  Year: " << newest.getYear() << "  Price: "
                     << newest.getPrice() << "  Mileage: " << newest.getMileage() << "  MPG: " << newest.getMpg()
                     << endl;
                cout << endl;
                cout << "Elapsed time for 2-3 Tree: " << duration.count() << " nanoseconds" << endl;

                start = high_resolution_clock::now(); //start timer
                newest = mapH[chosenModel].findNewest();
                stop = high_resolution_clock::now();
                duration = duration_cast<nanoseconds>(stop - start);

                cout << "Elapsed time for Heap: " << duration.count() << " nanoseconds" << endl;
                cout << "************************************************************" << endl;
                cout << endl << endl;


                break;
            case 3:
                // search all cars for the least mileage

                start = high_resolution_clock::now(); //start timer
                leastMileage = mapT[chosenModel].findLeastMiles();
                stop = high_resolution_clock::now(); //end timerduration = duration_cast<microseconds>(stop - start);
                duration = duration_cast<nanoseconds>(stop - start);

                cout << endl;
                cout << chosenModel << endl;
                cout << "Least Mileage****************************************************" << endl;
                cout << "Model: " << leastMileage.getModel() << "  Year: " << leastMileage.getYear() << "  Price: "
                     << leastMileage.getPrice() << "  Mileage: " << leastMileage.getMileage() << "  MPG: " << leastMileage.getMpg()
                     << endl;
                cout << endl;
                cout << "Elapsed time for 2-3 Tree: " << duration.count() << " nanoseconds" << endl;

                start = high_resolution_clock::now(); //start timer
                leastMileage = mapH[chosenModel].findLeastMiles();
                stop = high_resolution_clock::now();
                duration = duration_cast<nanoseconds>(stop - start);

                cout << "Elapsed time for Heap: " << duration.count() << " nanoseconds" << endl;
                cout << "************************************************************" << endl;
                cout << endl << endl;


                break;
            case 4:
                // search all cars for the highest mpg

                start = high_resolution_clock::now(); //start timer
                highestMpg = mapT[chosenModel].findHighestMpg();
                stop = high_resolution_clock::now(); //end timerduration = duration_cast<microseconds>(stop - start);
                duration = duration_cast<nanoseconds>(stop - start);

                cout << endl;
                cout << chosenModel << endl;
                cout << "Highest MPG****************************************************" << endl;
                cout << "Model: " << highestMpg.getModel() << "  Year: " << highestMpg.getYear() << "  Price: "
                     << highestMpg.getPrice() << "  Mileage: " << highestMpg.getMileage() << "  MPG: " << highestMpg.getMpg()
                     << endl;
                cout << endl;
                cout << "Elapsed time for 2-3 Tree: " << duration.count() << " nanoseconds" << endl;

                start = high_resolution_clock::now(); //start timer
                highestMpg = mapH[chosenModel].findHighestMpg();
                stop = high_resolution_clock::now();
                duration = duration_cast<nanoseconds>(stop - start);

                cout << "Elapsed time for Heap: " << duration.count() << " nanoseconds" << endl;
                cout << "************************************************************" << endl;
                cout << endl << endl;

                break;
            case 5:
                // search all cars within a price range
                int minPrice, maxPrice;
                cout << "Enter the minimum price: ";
                cin >> minPrice;
                cout << "Enter the maximum price: ";
                cin >> maxPrice;

                start = high_resolution_clock::now(); //start timer
                inPrRange = mapT[chosenModel].searchPrRange(mapT[chosenModel].rootP, inPrRange, minPrice, maxPrice);
                stop = high_resolution_clock::now(); //end timerduration = duration_cast<microseconds>(stop - start);
                duration = duration_cast<nanoseconds>(stop - start);

                cout << endl;
                cout << chosenModel << endl;
                cout << "In Price Range****************************************************" << endl;
                cout << "$" << minPrice << " - $" << maxPrice << endl;

                for (auto i: inPrRange) {
                    cout << "Model: " << i->getModel() << "  Year: " << i->getYear() << "  Price: "
                         << i->getPrice() << "  Mileage: " << i->getMileage() << "  MPG: "
                         << i->getMpg() << endl;
                }
                cout << endl;

                cout << "Elapsed time for 2-3 Tree: " << duration.count() << " nanoseconds" << endl;

                start = high_resolution_clock::now(); //start timer
                inPrRangeH = mapH[chosenModel].searchPrRange(minPrice, maxPrice);
                stop = high_resolution_clock::now();
                duration = duration_cast<nanoseconds>(stop - start);

                cout << "Elapsed time for Heap: " << duration.count() << " nanoseconds" << endl;
                cout << "************************************************************" << endl;
                cout << endl << endl;


                break;
            case 6:
                // search all cars within a year range
                int minYear, maxYear;
                cout << "Enter the minimum year: ";
                cin >> minYear;
                cout << "Enter the maximum year: ";
                cin >> maxYear;

                start = high_resolution_clock::now(); //start timer
                inYrRange = mapT[chosenModel].searchYrRange(mapT[chosenModel].rootY, inYrRange, minYear, maxYear);
                stop = high_resolution_clock::now(); //end timerduration = duration_cast<microseconds>(stop - start);
                duration = duration_cast<nanoseconds>(stop - start);

                cout << endl;
                cout << chosenModel << endl;
                cout << "In Year Range****************************************************" << endl;
                cout << minYear << " - " << maxYear << endl;

                for (auto i: inYrRange) {
                    cout << "Model: " << i->getModel() << "  Year: " << i->getYear() << "  Price: "
                         << i->getPrice() << "  Mileage: " << i->getMileage() << "  MPG: "
                         << i->getMpg() << endl;
                }
                cout << endl;

                cout << "Elapsed time for 2-3 Tree: " << duration.count() << " nanoseconds" << endl;

                start = high_resolution_clock::now(); //start timer
                inYrRangeH = mapH[chosenModel].searchYrRange(minYear, maxYear);
                stop = high_resolution_clock::now();
                duration = duration_cast<nanoseconds>(stop - start);

                cout << "Elapsed time for Heap: " << duration.count() << " nanoseconds" << endl;
                cout << "************************************************************" << endl;
                cout << endl << endl;


                break;
            case 7:
                // search all cars within a mileage range
                int minM, maxM;
                cout << "Enter the minimum mileage: ";
                cin >> minM;
                cout << "Enter the maximum mileage: ";
                cin >> maxM;

                start = high_resolution_clock::now(); //start timer
                inMRange = mapT[chosenModel].searchMiRange(mapT[chosenModel].rootM, inMRange, minM, maxM);
                stop = high_resolution_clock::now(); //end timerduration = duration_cast<microseconds>(stop - start);
                duration = duration_cast<nanoseconds>(stop - start);

                cout << endl;
                cout << chosenModel << endl;
                cout << "In Mileage Range****************************************************" << endl;
                cout  << minM << " - " << maxM << endl;

                for (auto i: inMRange) {
                    cout << "Model: " << i->getModel() << "  Year: " << i->getYear() << "  Price: "
                         << i->getPrice() << "  Mileage: " << i->getMileage() << "  MPG: "
                         << i->getMpg() << endl;
                }
                cout << endl;

                cout << "Elapsed time for 2-3 Tree: " << duration.count() << " nanoseconds" << endl;

                start = high_resolution_clock::now(); //start timer
                inMRangeH = mapH[chosenModel].searchMiRange(minM, maxM);
                stop = high_resolution_clock::now();
                duration = duration_cast<nanoseconds>(stop - start);

                cout << "Elapsed time for Heap: " << duration.count() << " nanoseconds" << endl;
                cout << "************************************************************" << endl;
                cout << endl << endl;


                break;
            case 8:
                // search all cars within a mpg range
                int minMPG, maxMPG;
                cout << "Enter the minimum mpg: ";
                cin >> minMPG;
                cout << "Enter the maximum mpg: ";
                cin >> maxMPG;
                // or
                // vector<Car> inMPGRange = allCarsH.searchMPGRange(minMPG, maxMPG);

                start = high_resolution_clock::now(); //start timer
                inMPGRange = mapT[chosenModel].searchMpgRange(mapT[chosenModel].rootMpg, inMPGRange, minMPG, maxMPG);
                stop = high_resolution_clock::now(); //end timerduration = duration_cast<microseconds>(stop - start);
                duration = duration_cast<nanoseconds>(stop - start);

                cout << endl;
                cout << chosenModel << endl;
                cout << "In MPG Range****************************************************" << endl;
                cout  << minMPG << " - " << maxMPG << endl;

                for (auto i: inMPGRange) {
                    cout << "Model: " << i->getModel() << "  Year: " << i->getYear() << "  Price: "
                         << i->getPrice() << "  Mileage: " << i->getMileage() << "  MPG: "
                         << i->getMpg() << endl;
                }
                cout << endl;

                cout << "Elapsed time for 2-3 Tree: " << duration.count() << " nanoseconds" << endl;

                start = high_resolution_clock::now(); //start timer
                inMPGRangeH = mapH[chosenModel].searchMpgRange(minMPG, maxMPG);
                stop = high_resolution_clock::now();
                duration = duration_cast<nanoseconds>(stop - start);

                cout << "Elapsed time for Heap: " << duration.count() << " nanoseconds" << endl;
                cout << "************************************************************" << endl;
                cout << endl << endl;

                break;
            default:
                cout << "Invalid search method choice." << endl;
                break;
        }
    }



    return 0;
}
