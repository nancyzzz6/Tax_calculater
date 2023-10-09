#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Define helper variables
    
    const double FIRST_TAXABLE_INCOME = 55000.00;
    const double SECOND_TAXABLE_INCOME = 70000.00;
    const double FIRST_TAX_RATE = 0.04;
    const double SECOND_TAX_RATE_GENERAL = 0.07;
    const double SECOND_TAX_RATE_SPEC = 0.05;
    const double THIRD_TAX_RATE = 0.093;
    const double TAX_REDUCE_PER_CHILD = 200;
    const double MAX_FIRST_TAX = FIRST_TAXABLE_INCOME * FIRST_TAX_RATE;
    const double MAX_SECOND_TAX_GENERAL = MAX_FIRST_TAX + SECOND_TAXABLE_INCOME * SECOND_TAX_RATE_GENERAL;
    const double MAX_SECOND_TAX_SPEC = MAX_FIRST_TAX + SECOND_TAXABLE_INCOME * SECOND_TAX_RATE_SPEC;
    const double THIRD_RATE_THRESHOLD = FIRST_TAXABLE_INCOME + SECOND_TAXABLE_INCOME;
    
        // Gather information from user
    
    cout << "Name: ";
    string personsName;
    getline(cin, personsName);
    if (personsName.empty()) {
        cout << "---" << endl ;
        cout << "You must enter a name" << endl ;
        return 1 ;
    }
    else {
        cout << "Taxable income: " ;
    }
    double taxableIncome;
    cin >> taxableIncome;
    cin.ignore(10000, '\n');
    if (taxableIncome < 0){
        cout << "---" << endl ;
        cout << "The taxable income must not be negative" << endl ;
        return 1 ;
    }
    else {
        cout << "Occupation: " ;
    }
    string occupation;
    getline(cin, occupation);
    if (occupation.empty()) {
        cout << "---" << endl ;
        cout << "You must enter an occupation" << endl ;
        return 1 ;
    }
    else {
        cout << "Number of children: " ;
    }
    double numOfChildren;
    cin >> numOfChildren;
    cin.ignore(10000, '\n');
    if (numOfChildren < 0){
        cout << "---" << endl;
        cout << "The number of children must not be negative" << endl ;
        return 1 ;
    }
    else{
        cout << "---" << endl;
        
           // Apply the tax rule
        
        double taxAmount;
        
          // Compute tax for income less than $55000
        
        if (taxableIncome <= FIRST_TAXABLE_INCOME ){
            taxAmount = taxableIncome * FIRST_TAX_RATE - TAX_REDUCE_PER_CHILD * numOfChildren;
        }
        
        // Compute tax for income more than $55000 and less than $125000
        
        else if (taxableIncome <= (FIRST_TAXABLE_INCOME + SECOND_TAXABLE_INCOME) ){
            // If occupation is nurse or teacher
            if (occupation == "nurse" || occupation == "teacher"){
                // Apply special tax rate
                taxAmount = MAX_FIRST_TAX + (taxableIncome - FIRST_TAXABLE_INCOME) * SECOND_TAX_RATE_SPEC - TAX_REDUCE_PER_CHILD * numOfChildren;
            }
            else{
                // Otherwise apply general tax rate
                taxAmount = MAX_FIRST_TAX + (taxableIncome - FIRST_TAXABLE_INCOME) * SECOND_TAX_RATE_GENERAL - TAX_REDUCE_PER_CHILD * numOfChildren;
            }
        }
        
        // Compute tax for income more than $125000
        
        else{
            if (occupation == "nurse" || occupation == "teacher"){
                taxAmount = MAX_FIRST_TAX + MAX_SECOND_TAX_SPEC + (taxableIncome - THIRD_RATE_THRESHOLD) * THIRD_TAX_RATE ;
            }
            else{
                taxAmount = MAX_FIRST_TAX + MAX_SECOND_TAX_GENERAL + (taxableIncome - THIRD_RATE_THRESHOLD) * THIRD_TAX_RATE ;
            }
        }
        
        if(taxAmount < 0)
            taxAmount = 0;
        
        // Print the amount of tax needed to pay
        
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << personsName << " would pay $" << taxAmount << endl;
    }
}

