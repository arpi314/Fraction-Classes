#include <iostream> 

using namespace std;

class Fraction{

    private:
        int numerator;
        int denominator;
    
    public:
        Fraction(int nume, int deno){
            setNumbers(nume, deno);
        }

        void setNumbers(int nume, int deno){
            this->numerator = nume;
            this->denominator = deno;
        }

        int getNumerator(){
            return this->numerator;
        }

        int getDenominator(){
            return this->denominator;
        }

        Fraction add(Fraction input){
            int finalNume, finalDeno;

            if(getDenominator() == input.getDenominator()){
                finalNume = getNumerator() + input.getNumerator();
                finalDeno = getDenominator();
            }else{
                finalNume = (getNumerator() * input.getDenominator()) + (input.getNumerator() * getDenominator());
                finalDeno = getDenominator() * input.getDenominator();
            }

            Fraction sum(finalNume,finalDeno);

            return sum;
        }

        Fraction subtract(Fraction input){

            int finalNume, finalDeno;

            if(getDenominator() == input.getDenominator()){
                finalNume = getNumerator() -input.getNumerator();
                finalDeno = getDenominator();
            }else{
                finalNume = (getNumerator() * input.getDenominator()) - (input.getNumerator() * getDenominator());
                finalDeno = getDenominator() * input.getDenominator();
            }

            Fraction difference(finalNume,finalDeno);

            return difference;
        }

        Fraction multiply(Fraction input){

            int finalNume, finalDeno;

            finalNume = getNumerator() * input.getNumerator();
            finalDeno = getDenominator() * input.getDenominator();

            Fraction product(finalNume, finalDeno);

            return product;
        }

        Fraction divide(Fraction input){

            int finalNume, finalDeno;

            finalNume = getNumerator() * input.getDenominator();
            finalDeno = input.getNumerator() * getDenominator();

            Fraction quotient(finalNume, finalDeno);

            return quotient;

        }

        void simplify(){
            
            int nume = getNumerator(), deno = getDenominator();

            if((nume % deno > 0) || (deno % nume > 0)){

                int gcd, tempNume, tempDeno;
                tempNume = nume;
                tempDeno = deno;

                if(nume < 1){
                    tempNume = tempNume * -1;
                }

                if(deno < 1){
                    tempDeno = tempDeno * -1;
                }

                while(tempNume != tempDeno){
                    if(tempNume > tempDeno){
                        tempNume -= tempDeno;
                        gcd = tempNume;
                    }else{
                        tempDeno -= tempNume;
                        gcd = tempDeno;
                    }
                }

                nume = nume / gcd;
                deno = deno / gcd;

                setNumbers(nume, deno);
            }
        }
};


int main(){

    int choice;
    cout << "What do you want to do?\n[1]Addition\n[2]Subtraction\n[3]Multiplication\n[4]Division\n[5]Simplify Fractions\n";
    cin >> choice;
    
    if(choice == 1){//Addition

        int arr[4] = {0,0,0,0};

        for(int i = 0; i < 4; i++){
            if(i%2 == 0){
                cout << "Numerator: ";
            }else if(i%2 != 0){
                cout << "Denominator: ";
            }

            cin >> arr[i];
        }

        Fraction fractionA(arr[0], arr[1]);
        Fraction fractionB(arr[2], arr[3]);

        Fraction sum(0,0);
        sum = fractionA.add(fractionB);
        if(sum.getNumerator() % sum.getDenominator() == 0){
            int whole;
            whole = sum.getNumerator() / sum.getDenominator();
            cout << whole;
        }else{
            sum.simplify();
            cout << sum.getNumerator() << "/" << sum.getDenominator();
        }

    }else if(choice == 2){//Subtraction
        int arr[4] = {0,0,0,0};

        for(int i = 0; i < 4; i++){
            if(i%2 == 0){
                cout << "Numerator: ";
            }else if(i%2 != 0){
                cout << "Denominator: ";
            }

            cin >> arr[i];
        }

        Fraction fractionA(arr[0], arr[1]);
        Fraction fractionB(arr[2], arr[3]);

        Fraction difference(0,0);
        difference = fractionA.subtract(fractionB);
        if(difference.getNumerator() % difference.getDenominator() == 0){
            int whole;
            whole = difference.getNumerator() / difference.getDenominator();
            cout << whole;
        }else{
            difference.simplify();
            cout << difference.getNumerator() << "/" << difference.getDenominator();
        }

    }else if(choice == 3){//Multiplication

        int arr[4] = {0,0,0,0};

        for(int i = 0; i < 4; i++){
            if(i%2 == 0){
                cout << "Numerator: ";
            }else if(i%2 != 0){
                cout << "Denominator: ";
            }

            cin >> arr[i];
        }

        Fraction fractionA(arr[0], arr[1]);
        Fraction fractionB(arr[2], arr[3]);

        Fraction product(0,0);
        product = fractionA.multiply(fractionB);
        if(product.getNumerator() % product.getDenominator() == 0){
            int whole;
            whole = product.getNumerator() / product.getDenominator();
            cout << whole;
        }else{
            product.simplify();
            cout << product.getNumerator() << "/" << product.getDenominator();
        }
    }else if(choice == 4){//Division
        int arr[4] = {0,0,0,0};

        for(int i = 0; i < 4; i++){
            if(i%2 == 0){
                cout << "Numerator: ";
            }else if(i%2 != 0){
                cout << "Denominator: ";
            }

            cin >> arr[i];
        }

        Fraction fractionA(arr[0], arr[1]);
        Fraction fractionB(arr[2], arr[3]);
        
        Fraction quotient(0,0);
        quotient = fractionA.divide(fractionB);
        if(quotient.getNumerator() % quotient.getDenominator() == 0){
            int whole;
            whole = quotient.getNumerator() / quotient.getDenominator();
            cout << whole;
        }else{
            quotient.simplify();
            cout << quotient.getNumerator() << "/" << quotient.getDenominator();
        }

    }else if(choice == 5){//Simplification

        int arr[2] = {0,0};

        for(int i = 0; i < 2; i++){
            if(i%2 == 0){
                cout << "Numerator: ";
            }else if(i%2 != 0){
                cout << "Denominator: ";
            }

        cin >> arr[i];
        }

        Fraction fractionC(arr[0], arr[1]);
        fractionC.simplify();
        cout << fractionC.getNumerator() << "/" << fractionC.getDenominator();
    }

}