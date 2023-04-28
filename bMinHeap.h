//
// Created by socce on 4/24/2023.
//

#ifndef PROJECT3_BMINHEAP_H
#define PROJECT3_BMINHEAP_H


#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <fstream>
using namespace std;


class car{

private:
    string model;
    int mileage;
    int year;
    float price;
    float mpg;

public:

    car(string m, int mile, int y, float p, float milespg);
    car();
    string getModel();
    int getMileage();
    int getYear();
    float getPrice();
    float getMpg();

};

//accessor functions
string car::getModel() {
    return model;
}
int car::getMileage() {
    return mileage;
}
int car::getYear() {
    return year;
}
float car::getPrice() {
    return price;
}
float car::getMpg()
{
    return mpg;
}

//constructors
car::car(string m, int mile, int y, float p, float milespg) {
    model = m;
    mileage = mile;
    year = y;
    price = p;
    mpg = milespg;
}
car::car() {
    model = "";
    mileage = 0;
    year = 0;
    price = 0;
    mpg = 0;

}


//heaps are O(n) for searching
//they're only O(1) for finding the largest or smallest element

struct heaps {

    //using array implementation
    vector<car> heapP; //min price at root
    vector<car> heapY; //newest year at root
    vector<car> heapM; //least mileage at root
    vector<car> heapMpg; //highest mpg at root

    void insertCar(car c);

    vector<car> searchPrRange(float min, float max);
    vector<car> searchYrRange(int min, int max);
    vector<car> searchMiRange(int min, int max);
    vector<car> searchMpgRange(float min, float max);

    car findCheapest();
    car findNewest();
    car findLeastMiles();
    car findHighestMpg();

    //car removeNode();


};
void heaps::insertCar(car c)
{
    //***************for price**************************************cheapest at root
    //add it to the end
    heapP.push_back(c);

    //heapify up
    int currI = heapP.size()-1;
    int parent = (currI-1)/2;

    while((heapP[currI].getPrice() < heapP[parent].getPrice()) && (currI != 0))
    {
        //swap child and parent
        car p = heapP[parent];
        heapP[parent] = heapP[currI];
        heapP[currI] = p;

        currI = parent;
        parent = (currI-1)/2;
    }

    //****************for mileage*************************************least mileage at root
    //add it to the end
    heapM.push_back(c);

    //heapify up
    currI = heapM.size()-1;
    parent = (currI-1)/2;

    while((heapM[currI].getMileage() < heapM[parent].getMileage()) && (currI != 0))
    {
        //swap child and parent
        car p = heapM[parent];
        heapM[parent] = heapM[currI];
        heapM[currI] = p;

        currI = parent;
        parent = (currI-1)/2;
    }

    //*****************for year******************************************newest year at root
    //add it to the end
    heapY.push_back(c);

    //heapify up
    currI = heapY.size()-1;
    parent = (currI-1)/2;

    while((heapY[currI].getYear() > heapY[parent].getYear()) && (currI != 0))
    {
        //swap child and parent
        car p = heapY[parent];
        heapY[parent] = heapY[currI];
        heapY[currI] = p;

        currI = parent;
        parent = (currI-1)/2;
    }

    //**************for MPG******************************************highest mpg at root
    //add it to the end
    heapMpg.push_back(c);

    //heapify up
    currI = heapMpg.size()-1;
    parent = (currI-1)/2;

    while((heapMpg[currI].getMpg() > heapMpg[parent].getMpg()) && (currI != 0))
    {
        //swap child and parent
        car p = heapMpg[parent];
        heapMpg[parent] = heapMpg[currI];
        heapMpg[currI] = p;

        currI = parent;
        parent = (currI-1)/2;
    }

}

vector<car> heaps::searchPrRange(float min, float max) {
    vector<car> inPriceR;

    //BFS
    for(int i = 0; i < heapP.size(); i++)
    {
        if((heapP[i].getPrice() <= max) && (heapP[i].getPrice() >= min))
        {
            inPriceR.push_back(heapP[i]);
        }

    }



    return inPriceR;
}
vector<car> heaps::searchYrRange(int min, int max) {
    vector<car> inYrR;

    //BFS
    for(int i = 0; i < heapY.size(); i++)
    {
        if((heapY[i].getYear() <= max) && (heapY[i].getYear() >= min))
        {
            inYrR.push_back(heapY[i]);
        }
    }


    return inYrR;
}
vector<car> heaps::searchMiRange(int min, int max) {
    vector<car> inMiR;

    //BFS
    for(int i = 0; i < heapM.size(); i++)
    {
        if((heapM[i].getMileage() <= max) && (heapM[i].getMileage() >= min))
        {
            inMiR.push_back(heapM[i]);
        }

    }


    return inMiR;
}
vector<car> heaps::searchMpgRange(float min, float max) {

    vector<car> inMpgR;

    //BFS
    for(int i = 0; i < heapMpg.size(); i++)
    {
        if((heapMpg[i].getMpg() <= max) && (heapMpg[i].getMpg() >= min))
        {
            inMpgR.push_back(heapMpg[i]);
        }

    }


    return inMpgR;
}

car heaps::findCheapest()
{
    return heapP[0];
}
car heaps::findNewest()
{
    return heapY[0];
}
car heaps::findLeastMiles()
{
    return heapM[0];
}
car heaps::findHighestMpg()
{
    return heapMpg[0];
}

/* car heaps::removeNode() {

   //remove root and return it
   car r = heapP[0];

   //replace root with last and delete it
   heapP[0] = heapP[heapP.size()-1];
   heapP.pop_back();
   car temp = heapP[0];

   //heapify down
   int currI = 0;
   int child1 = 1;
   int child2 = 2;
   int LCI = 0;

   while(((heapP[currI].getPrice() > heapP[child1].getPrice()) || (heapP[currI].getPrice() > heapP[child2].getPrice())) && (currI < heapP.size()-1))
   {
       //determine least child
       if(child2 >= heapP.size())
       {
           //in the case that only 1 child at back
           LCI = child1;
       }
       else
       {
           //both children are present
           if(heapP[child1].getPrice() <= heapP[child2].getPrice())
           {
               LCI = child1;
           }
           else
           {
               LCI = child2;
           }
       }

       //swap least child with value
       heapP[currI] = heapP[LCI];
       currI = LCI;
       heapP[LCI] = temp;

       //update values
       child1 = (2*currI) + 1;
       child2 = (2*currI) + 2;

   }


} */



#endif //PROJECT3_BMINHEAP_H
