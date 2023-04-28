//
// Created by socce on 4/24/2023.
//

#ifndef PROJECT3_TREE3_H
#define PROJECT3_TREE3_H

#include "bMinHeap.h"

struct node {

    vector<car*> objects;
    node* left;
    node* middle;
    node* right;

    node();

};
node::node()
{
    left = nullptr;
    middle = nullptr;
    right = nullptr;
}

struct tree3{

    node* rootP;
    node* rootY;
    node* rootM;
    node* rootMpg;

    tree3();

    //insertions
    void insertCar(car* c);
    void insertP(car* c, node* root);
    void insertY(car* c, node* root);
    void insertM(car* c, node* root);
    void insertMpg(car* c, node* root);

    //printing
    void printTree(node* root);

    //searches
    vector<car*> searchPrRange(node* root, vector<car*>& inPrRange, float min, float max);
    vector<car*> searchYrRange(node* root, vector<car*>& inYrRange, float min, float max);
    vector<car*> searchMiRange(node* root, vector<car*>& inMiRange, float min, float max);
    vector<car*> searchMpgRange(node* root, vector<car*>& inMpgRange, float min, float max);

    car findCheapest();
    car findNewest();
    car findLeastMiles();
    car findHighestMpg();
};

//constructor
tree3::tree3()
{
    rootP = new node();
    rootY = new node();
    rootM = new node();
    rootMpg = new node();
}

//insertions
void tree3::insertCar(car* c) {

    //insert into all trees
    insertP(c, rootP);
    insertY(c, rootY);
    insertM(c, rootM);
    insertMpg(c, rootMpg);

}
void tree3::insertP(car* c, node* root) {

    if((root->objects.size() == 0))
    {
        root->objects.push_back(c);
    }
    else if(root->objects.size() == 1)
    {
        //need them in order
        if(root->objects[0]->getPrice() > c->getPrice())
        {
            root->objects.push_back(root->objects[0]);
            root->objects[0] = c;
        }
        else
        {
            root->objects.push_back(c);
        }
    }
    else
    {
        if(c->getPrice() < root->objects[0]->getPrice())
        {
            //go left
            if(root->left != nullptr)
            {
                insertP(c, root->left);
            }
            else
            {
                node* newNode = new node();
                newNode->objects.push_back(c);
                root->left = newNode;
            }
        }
        else if((c->getPrice() <= root->objects[1]->getPrice()) && (c->getPrice() >= root->objects[0]->getPrice()))
        {
            //go middle
            if(root->middle != nullptr)
            {
                insertP(c, root->middle);
            }
            else
            {
                node* newNode = new node();
                newNode->objects.push_back(c);
                root->middle = newNode;
            }
        }
        else
        {
            //go right
            if(root->right != nullptr)
            {
                insertP(c, root->right);
            }
            else
            {
                node* newNode = new node();
                newNode->objects.push_back(c);
                root->right = newNode;
            }
        }

    }


}
void tree3::insertY(car *c, node* root) {

    if((root->objects.size() == 0))
    {
        root->objects.push_back(c);
    }
    else if(root->objects.size() == 1)
    {
        //need them in order
        if(root->objects[0]->getYear() > c->getYear())
        {
            root->objects.push_back(root->objects[0]);
            root->objects[0] = c;
        }
        else
        {
            root->objects.push_back(c);
        }
    }
    else
    {
        if(c->getYear() < root->objects[0]->getYear())
        {
            //go left
            if(root->left != nullptr)
            {
                insertY(c, root->left);
            }
            else
            {
                node* newNode = new node();
                newNode->objects.push_back(c);
                root->left = newNode;
            }
        }
        else if((c->getYear() <= root->objects[1]->getYear()) && (c->getYear() >= root->objects[0]->getYear()))
        {
            //go middle
            if(root->middle != nullptr)
            {
                insertY(c, root->middle);
            }
            else
            {
                node* newNode = new node();
                newNode->objects.push_back(c);
                root->middle = newNode;
            }
        }
        else
        {
            //go right
            if(root->right != nullptr)
            {
                insertY(c, root->right);
            }
            else
            {
                node* newNode = new node();
                newNode->objects.push_back(c);
                root->right = newNode;
            }
        }

    }

}
void tree3::insertM(car *c, node* root) {

    if((root->objects.size() == 0))
    {
        root->objects.push_back(c);
    }
    else if(root->objects.size() == 1)
    {
        //need them in order
        if(root->objects[0]->getMileage() > c->getMileage())
        {
            root->objects.push_back(root->objects[0]);
            root->objects[0] = c;
        }
        else
        {
            root->objects.push_back(c);
        }
    }
    else
    {
        if(c->getMileage() < root->objects[0]->getMileage())
        {
            //go left
            if(root->left != nullptr)
            {
                insertM(c, root->left);
            }
            else
            {
                node* newNode = new node();
                newNode->objects.push_back(c);
                root->left = newNode;
            }
        }
        else if((c->getMileage() <= root->objects[1]->getMileage()) && (c->getMileage() >= root->objects[0]->getMileage()))
        {
            //go middle
            if(root->middle != nullptr)
            {
                insertM(c, root->middle);
            }
            else
            {
                node* newNode = new node();
                newNode->objects.push_back(c);
                root->middle = newNode;
            }
        }
        else
        {
            //go right
            if(root->right != nullptr)
            {
                insertM(c, root->right);
            }
            else
            {
                node* newNode = new node();
                newNode->objects.push_back(c);
                root->right = newNode;
            }
        }

    }

}
void tree3::insertMpg(car *c, node* root) {

    if((root->objects.size() == 0))
    {
        root->objects.push_back(c);
    }
    else if(root->objects.size() == 1)
    {
        //need them in order
        if(root->objects[0]->getMpg() > c->getMpg())
        {
            root->objects.push_back(root->objects[0]);
            root->objects[0] = c;
        }
        else
        {
            root->objects.push_back(c);
        }
    }
    else
    {
        if(c->getMpg() < root->objects[0]->getMpg())
        {
            //go left
            if(root->left != nullptr)
            {
                insertMpg(c, root->left);
            }
            else
            {
                node* newNode = new node();
                newNode->objects.push_back(c);
                root->left = newNode;
            }
        }
        else if((c->getMpg() <= root->objects[1]->getMpg()) && (c->getMpg() >= root->objects[0]->getMpg()))
        {
            //go middle
            if(root->middle != nullptr)
            {
                insertMpg(c, root->middle);
            }
            else
            {
                node* newNode = new node();
                newNode->objects.push_back(c);
                root->middle = newNode;
            }
        }
        else
        {
            //go right
            if(root->right != nullptr)
            {
                insertMpg(c, root->right);
            }
            else
            {
                node* newNode = new node();
                newNode->objects.push_back(c);
                root->right = newNode;
            }
        }

    }
}

//inorder printing for testing
void tree3::printTree(node* root) {

    if(root->left != nullptr)
    {
        printTree(root->left);
    }

    cout << root->objects[0]->getModel() << " " << root->objects[0]->getYear () << " " << root->objects[0]->getPrice() << " " << root->objects[0]->getMileage() << " " << root->objects[0]->getMpg() << endl;

    if(root->middle != nullptr)
    {
        printTree(root->middle);
    }

    if(root->objects.size() == 2)
    {
        cout << root->objects[1]->getModel() << " " << root->objects[1]->getYear () << " " << root->objects[1]->getPrice() << " " << root->objects[1]->getMileage() << " " << root->objects[1]->getMpg() << endl;
    }

    if(root->right != nullptr)
    {
        printTree(root->right);
    }

}

//searches
vector<car*> tree3::searchPrRange(node* root, vector<car*>& inPrRange, float min, float max) {

    if(root->left != nullptr)
    {
        searchPrRange(root->left, inPrRange, min, max);
    }

   // cout << root->objects[0]->getPrice() << endl;

    if((root->objects[0]->getPrice() <= max) && (root->objects[0]->getPrice() >= min))
    {
        //cout << "in range: " << root->objects[0]->getPrice() << endl;
        inPrRange.push_back(root->objects[0]);
    }

    if(root->middle != nullptr)
    {
        searchPrRange(root->middle, inPrRange, min, max);
    }

    if(root->objects.size() == 2)
    {
        //cout << root->objects[1]->getPrice() << endl;

        if((root->objects[1]->getPrice() <= max) && (root->objects[1]->getPrice() >= min))
        {
            //cout << "in range: " << root->objects[1]->getPrice() << endl;
            inPrRange.push_back(root->objects[1]);
            //cout << "ur mom";
        }
    }

    if(root->right != nullptr)
    {
        searchPrRange(root->right, inPrRange, min, max);
    }


    return inPrRange;
}
vector<car *> tree3::searchYrRange(node *root, vector<car *>& inYrRange, float min, float max) {

    if(root->left != nullptr)
    {
        searchYrRange(root->left, inYrRange, min, max);
    }

    if((root->objects[0]->getYear() <= max) && (root->objects[0]->getYear() >= min))
    {
        inYrRange.push_back(root->objects[0]);
    }

    if(root->middle != nullptr)
    {
        searchYrRange(root->middle, inYrRange, min, max);
    }

    if(root->objects.size() == 2)
    {

        if((root->objects[1]->getYear() <= max) && (root->objects[1]->getYear() >= min))
        {
            //cout << "in range: " << root->objects[1]->getPrice() << endl;
            inYrRange.push_back(root->objects[1]);
            //cout << "ur mom";
        }
    }

    if(root->right != nullptr)
    {
        searchYrRange(root->right, inYrRange, min, max);
    }


    return inYrRange;
}
vector<car *> tree3::searchMiRange(node *root, vector<car *>& inMiRange, float min, float max) {


    if(root->left != nullptr)
    {
        searchMiRange(root->left, inMiRange, min, max);
    }


    if((root->objects[0]->getMileage() <= max) && (root->objects[0]->getMileage() >= min))
    {
        inMiRange.push_back(root->objects[0]);
    }

    if(root->middle != nullptr)
    {
        searchMiRange(root->middle, inMiRange, min, max);
    }

    if(root->objects.size() == 2)
    {

        if((root->objects[1]->getMileage() <= max) && (root->objects[1]->getMileage() >= min))
        {
            inMiRange.push_back(root->objects[1]);
        }
    }

    if(root->right != nullptr)
    {
        searchMiRange(root->right, inMiRange, min, max);
    }


    return inMiRange;
}
vector<car *> tree3::searchMpgRange(node *root, vector<car *> &inMpgRange, float min, float max) {

    if(root->left != nullptr)
    {
        searchMpgRange(root->left, inMpgRange, min, max);
    }


    if((root->objects[0]->getMpg() <= max) && (root->objects[0]->getMpg() >= min))
    {
        inMpgRange.push_back(root->objects[0]);
    }

    if(root->middle != nullptr)
    {
        searchMpgRange(root->middle, inMpgRange, min, max);
    }

    if(root->objects.size() == 2)
    {

        if((root->objects[1]->getMpg() <= max) && (root->objects[1]->getMpg() >= min))
        {
            inMpgRange.push_back(root->objects[1]);
        }
    }

    if(root->right != nullptr)
    {
        searchMpgRange(root->right, inMpgRange, min, max);
    }


    return inMpgRange;
}

car tree3::findCheapest() {

    node* root = rootP;

    while(root->left != nullptr)
    {
        root = root->left;
    }

    return *(root->objects[0]);
}
car tree3::findNewest() {
    node* root = rootY;

    while(root->right != nullptr)
    {
        root = root->right;
    }

    if(root->objects.size() == 2)
    {
        return *(root->objects[1]);
    }
    else
    {
        return *(root->objects[0]);
    }
}
car tree3::findLeastMiles() {

    node* root = rootM;

    while(root->left != nullptr)
    {
        root = root->left;
    }

    return *(root->objects[0]);
}
car tree3::findHighestMpg() {
    node* root = rootMpg;

    while(root->right != nullptr)
    {
        root = root->right;
    }

    if(root->objects.size() == 2)
    {
        return *(root->objects[1]);
    }
    else
    {
        return *(root->objects[0]);
    }
}


#endif //PROJECT3_TREE3_H
