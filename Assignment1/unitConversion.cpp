using namespace std;

double unitConversion(double temperature, char units) {
    // main math calculation 
    double calculation;

    if (units == 'C') {
        calculation = (temperature * 9 / 5) + 32;
    }
    else {
        calculation = (temperature - 32) * 5/9 ;
    }
    return calculation;

}
