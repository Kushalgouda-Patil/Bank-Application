#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Dish
{
public:
    string name;
    vector<pair<string, int>> ing_quan;
    Dish(string names, vector<pair<string, int>> a)
    {
        this->name = names;
        for (auto pair : a)
        {
            ing_quan.push_back(pair);
        }
    }
    virtual bool check() = 0;
};

class Eatables : public Dish
{
public:
    Eatables(string names, vector<pair<string, int>> a) : Dish(names, a) {}
    bool check()
    {
        cout << "Enter ingredients in order to check\n"
             << endl;
        string s;
        for (int it = 0; it < ing_quan.size(); it++)
        {
            cin >> s;
            if (ing_quan[it].first == s)
            {

                continue;
            }
            else
            {
                return false;
            }
        }
        int k;
        cout << "Enter quantity of ingredients" << endl;
        for (int it = 0; it < ing_quan.size(); it++)
        {
            cin >> k;
            if (ing_quan[it].second == k)
            {

                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

class Juice : public Dish
{
public:
    Juice(string names, vector<pair<string, int>> a) : Dish(names, a) {}
    bool check()
    {
        int k;
        cout << "Enter quantity of ingredients" << endl;
        for (int it = 0; it < ing_quan.size(); it++)
        {
            cin >> k;
            if (ing_quan[it].second == k)
            {

                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};


void addNewDish(map<string, Dish *> &dishes)
{
    string dishName;
    cout << "Enter the name of the new dish: ";
    cin.ignore();
    getline(cin, dishName);

    cout << "Enter the number of ingredients: ";
    int numIngredients;
    cin >> numIngredients;

    vector<pair<string, int>> ingredients;
    for (int i = 0; i < numIngredients; i++)
    {
        string ingredientName;
        int quantity;
        cout << "Enter ingredient name: ";
        cin.ignore();
        getline(cin, ingredientName);
        cout << "Enter quantity: ";
        cin >> quantity;
        ingredients.push_back(make_pair(ingredientName, quantity));
    }


    cout << "Is the dish an Eatable (1) or a Juice (2)? Enter 1 or 2: ";
    int dishType;
    cin >> dishType;

    if (dishType == 1)
        dishes[dishName] = new Eatables(dishName, ingredients);
    else if (dishType == 2)
        dishes[dishName] = new Juice(dishName, ingredients);
}


void displayDishes(const map<string, Dish *> &dishes)
{
    cout << "Existing dishes:\n";
    for (const auto &dishPair : dishes)
    {
        cout << dishPair.first << endl;
    }
}

int main()
{
    int option;
    bool answer;

    map<string, Dish *> dishes;

    // Existing dishes
    string a = "Dosa";
    vector<pair<string, int>> p;
    p = {{"Batter", 3}, {"bhaji", 2}};

    string b = "Fruit Salad";
    vector<pair<string, int>> q;
    q = {{"Apple", 2}, {"Banana", 3}};

    string c = "coffee";
    vector<pair<string, int>> r;
    r = {{"Milk", 2}, {"Powder", 1}, {"Sugar", 1}};

    Eatables n(a, p);
    Eatables j(b, q);
    Juice l(c, r);

    dishes[a] = &n;
    dishes[b] = &j;
    dishes[c] = &l;

    while (1)
    {
        cout << "\n---------------------------------------------------";
        cout << "\nTest:\n";
        cout << "1:" << n.name << endl;
        cout << "2:" << j.name << endl;
        cout << "3:" << l.name << endl;
        cout << "4:Add new dish" << endl;
        cout << "5:Display all dishes" << endl;
        cout << "6:Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        switch (option)
        {
        case 1:
            answer = n.check();
            if (answer == true)
            {
                cout << "\nPASS";
            }
            else
            {
                cout << "\nFAIL";
            }
            break;

        case 2:
            answer = j.check();
            if (answer == true)
            {
                cout << "\nPASS";
            }
            else
            {
                cout << "\nFAIL";
            }
            break;

        case 3:
            answer = l.check();
            if (answer == true)
            {
                cout << "\nPASS";
            }
            else
            {
                cout << "\nFAIL";
            }
            break;

        case 4:
            addNewDish(dishes);
            break;

        case 5:
            displayDishes(dishes);
            break;

        case 6:
            exit(0);
        case 7:
            string name1;
            cin>>name1;
            dishes[name1]->check();
            if (answer == true)
            {
                cout << "\nPASS";
            }
            else
            {
                cout << "\nFAIL";
            }
            break;

        }
    }
}
