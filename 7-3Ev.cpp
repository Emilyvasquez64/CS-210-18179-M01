//Emily Vasquez 
//5-2CS-210-18179-M01 
//Professor Cohen


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // for formatting the output
#include <sys/stat.h> // for checking if file exists
#include <map>


using namespace std;

// Function to check if a file exists
bool fileExists(const string &fileName) {
    struct stat buffer;
    return (stat(fileName.c_str(), &buffer) == 0);
}

class GroceryBookKeeper {
    public: 
        //default constructor
        GroceryBookKeeper(){}

        void printProductHistogram(){
            // Find the product with maximum amount of character 
            int max_count = 0;
            for (const auto& pair : productTofrequency) {
                int productNameLength = pair.first.length();
                max_count = max(max_count, productNameLength);
            }

            // Create the histogram
            for (const auto& pair : productTofrequency) {
                // Append spaces before printing the product name so that asterisks start from the same point
                int spacesToAppend = max_count - pair.first.length();;
                for (int i = 0; i < spacesToAppend; ++i){
                    cout << " ";
                }
                cout << pair.first << " ";

                for (int i = 0; i < pair.second; ++i) {
                    cout << "*";
                }
                cout << endl;
            }
        }

        int getProductFrequency(string product){
            if (productTofrequency.count(product) != 0) {
                //return the frequency counter
                return productTofrequency[product];
            } else {
                //Item not found, so frequency is 0
                return 0;
            }
        }

        void printProductAndFrequency(){
            for (const auto& pair : productTofrequency) {
                cout << pair.first << " " << pair.second << endl;
            }
        }

        void backupProductAndFrequency(){
            string outputFilePath = "/tmp/frequency.dat";
            ofstream outputFile(outputFilePath); // Open the output file
            // If output file doesn't open, we can't keep backup
            if (outputFile) {
                for (const auto& pair : productTofrequency) {
                    outputFile << pair.first << " " << pair.second << endl;
                }
            } 
            
        }

        bool readProductList(string inputFilePath){
            ifstream inputFile(inputFilePath);  // Open the input file
            
            // If input file doesn't open, show an error
            if (inputFile.is_open()) {
                string item;
                while (getline(inputFile, item)) {
                    // item already exist on map
                    if (productTofrequency.count(item) != 0) {
                        //increase frequency counter by 1
                        productTofrequency[item] += 1;
                    } else {
                        //founds new item, add it to map with frequency 1
                        productTofrequency[item] = 1;
                    }
                }
                inputFile.close();
                return true;
            } else {
                cerr << "Error opening the input file!" << endl;
                return false;
            }

        }
    
    private:
        map <string, int> productTofrequency;

};

void displayPrompt()
{
    cout << endl;
    cout << "Select a menu option to continue." << endl;
    cout << "1) Input the item, or word, you wish to look for." << endl;
    cout << "2) Print the list with numbers that represent the frequency of all items purchased." << endl;
    cout << "3) Print the histogram that represent the frequency of all items purchased." << endl;
    cout << "4) Exit the program." << endl;
}

int main() {
    // Variables for file paths
    string inputFilePath;
    GroceryBookKeeper *groceryBookkeeper = new GroceryBookKeeper();
    int menuOption;

    // Ask the user for the input file path
    cout << "Enter the path to the CS210_Project_Three_Input_File.txt file: " << endl;
    cin >> inputFilePath;

    if (!fileExists(inputFilePath)){
        cerr << "Error: Input file doesn't exist!" << endl;
        return 1; // Stop if there's an error
    }
    bool readFileStatus = groceryBookkeeper->readProductList(inputFilePath);
    //make sure the file is readable 
    if (!readFileStatus) {
        cerr << "Error reading file at path: " << inputFilePath << endl;
        cout << "Terminating program.." << endl;
        return 1;
    }

    //Keep backup of the file with the freuencies, will use same logic as option 2 
    //But instead of printing we will write it to file 
    //The backup file will be stored in /tmp/frequency.dat
    groceryBookkeeper->backupProductAndFrequency();

    while (menuOption != 4){
        displayPrompt();
        cin >> menuOption;
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid Input, please enter an integer number" << endl;
            continue;
        }
        cout << endl;
        string item;
        switch (menuOption) {
            case 1: {
                cout << "Selected option 1." << endl;
                cout << "Please enter a word representing the item you are looking for." << endl;
                cin >> item;
                cout << "Frequency for item: " << item << " " << groceryBookkeeper->getProductFrequency(item) << endl;
                break;
            }
            case 2: {
                cout << "Selected option 2." << endl;
                groceryBookkeeper->printProductAndFrequency();
                break;
            }
            case 3: {
                cout << "Selected option 3." << endl;
                groceryBookkeeper->printProductHistogram();
                break;
            }
            case 4: {
                cout << "Selected option 4. Program will now exit.." << endl;
                break;
            }
            default: {
                cout << "Not a valid menu option" << endl;
                break;
            }
        }
    }

    return 0;
}
