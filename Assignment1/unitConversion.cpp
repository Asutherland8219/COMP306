int unitConversion(int temperature, char units) {
    // main math calculation 
    int calculation;

    if (units == 'C') {
        calculation = (temperature * 9 / 5) + 32 ;
    }
    else {
        calculation = (temperature - 32) * 5/9 ; 
    }

    return calculation;

}
