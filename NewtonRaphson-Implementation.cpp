#include<bits/stdc++.h>
#include <stdlib.h>
#define clear() printf("\033[H\033[J")
using namespace std;

double f(double poly[], int n, double x);
void newtonRaphson(double polynomial[], int n, double x);

int main() { 
    int degree;
	double initGuess;
	
	char quit;
	bool confimQuit = false;
	
	do{
		// CLEAR SCREEN FOR LINUX
		//clear();
		// CLEAR SCREEN FOR WINDOWS
		system("CLS");
		
		cout << endl << " Enter the degree of the polynomial: ";
		cin >> degree;
		cout << endl;
		
		double poly[degree];
		
		for(int i = 0; i <= degree; i++){
			cout << " Enter coefficient for the [" << degree-i << "] power: ";
			cin >> poly[i];
			cout << endl;
		}
		
		cout << " Enter your initial guess: ";
		cin >> initGuess;
		
		degree++;
		
		newtonRaphson(poly, degree, initGuess);
	   
		while(1){
			cout << endl << endl << " Run the program again? [Y/N] " ;
			cin >> quit; 
			if (quit == 'y' || quit == 'Y') {
				confimQuit = false;
				break;
			}
			if (quit == 'n' || quit == 'N'){
				confimQuit = true; 
				break;
			}
			else{
				// CLEAR SCREEN FOR LINUX
				//clear();
				// CLEAR SCREEN FOR WINDOWS
				system("CLS");
				
				cout << endl << " INVALID INPUT";
			}
		}
		
	} while(confimQuit == false);
	
	return 0;
}


double f(double poly[], int n, double x){
    double result = poly[0];
  
    for (int i=1; i < n; i++) result = result*x + poly[i];
        
    return result; 
}

void newtonRaphson(double polynomial[], int n, double x) {
	// CLEAR SCREEN FOR LINUX
	//clear();
	// CLEAR SCREEN FOR WINDOWS
	system("CLS");
	
	int iter = 0;
	
    double xOld, derivativePolynomial[n-1], err = FLT_MAX;
    
	for(int i = 0; i < n-1; i++) derivativePolynomial[i] = polynomial[i]*(n-(i+1));
	
	double xPlusOne = f(polynomial, n, x) / f(derivativePolynomial, n-1, x);
    
    cout << endl << " " << left << setw(12) << "ITERATION" << left << setw(15) << "x" << left << setw(15) << "f(x)" << left << setw(15) <<  "f'(x)" << left << setw(15) << "ERROR" <<  endl;
    
    do { 
    	cout << endl << " " << left << setw(12) << iter ;
    	
        xPlusOne = f(polynomial, n, x) / f(derivativePolynomial, n-1, x);
        
        cout << fixed << setprecision(5) << setw(15) << x;
        
        xOld = x;
		cout << fixed << setprecision(5) << setw(15) << f(polynomial, n, x);
		
		cout << fixed << setprecision(5) << setw(15) << f(derivativePolynomial, n-1, x);
  
        x = x - xPlusOne;
        
        err = abs((x - xOld)/x);
        cout << fixed << setprecision(5) << setw(15) << err << endl;
        
        iter++;
    } while (abs(xPlusOne) > 0.001 && abs(err) > 0.001 && iter <= 20);
  
    cout << endl << " = = = = =" << endl << endl << " FINAL ROOT VALUE : " << xOld; 
} 
  


