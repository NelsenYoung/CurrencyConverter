// Nelsen Young 6/18/2023
// Currancy Converter

#include <utility>
#include <string>
#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
1. Ask User for currancy they would like to convert from
and currancy they would like to convert to
2. Find What currancy was given
2. Convert the original currancy to US dollars
3. Convert from dollars to the requested currancy

Convert to Dollars:
1. get the amount to convert

Find what currancy what given:
1. for each world currancy
    2. if the entered currancy matches one of the world currancies
        3. return that currancy
*/

struct Currency {
    char* name;
    double conversionRateToUSD;
};

double convertToDollars(struct Currency curr, double amount){
    return amount * curr.conversionRateToUSD;
}

double convertFromDollars(struct Currency curr, double amount){
    return amount / curr.conversionRateToUSD;
}

struct Currency findCurrencyInput(char* currencyName, struct Currency worldCurrancies[8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 3; j++){
            if(tolower(worldCurrancies[i].name[j]) == tolower(currencyName[j])){
                if(j == 2){
                    return worldCurrancies[i];
                }
            }else{
                continue;
            }
        }
    }
    printf("Not a valid Currency. Exiting. \n");
    exit(0);
}

void setWorldCurrencies(struct Currency curr[8]){
    curr[0].name = "USD";
    curr[0].conversionRateToUSD = 1;
    curr[1].name = "EUR";
    curr[1].conversionRateToUSD = 1.09;
    curr[2].name = "JPY";
    curr[2].conversionRateToUSD = 0.007;
    curr[3].name = "GBP";
    curr[3].conversionRateToUSD = 1.28;
    curr[4].name = "CHF";
    curr[4].conversionRateToUSD = 1.12;
    curr[5].name = "CAD";
    curr[5].conversionRateToUSD = 0.76;
    curr[6].name = "AUD";
    curr[6].conversionRateToUSD = 0.62;
    curr[7].name = "ZAR";
    curr[7].conversionRateToUSD = 0.055;
    

    
}
int main(){
    char* userCurrency = (char*)calloc(0, sizeof(char));
    double userAmount;
    char* desiredCurrency = (char*)calloc(0, sizeof(char));

    struct Currency worldCurrencies[8];


    printf("Enter what currency would you like to convert: ");
    scanf("%s", userCurrency);
    printf("Enter how much would you like to convert: ");
    scanf("%lf", &userAmount);

    printf("Enter what currency would you like to convert to: ");
    scanf("%s", desiredCurrency);

    setWorldCurrencies(worldCurrencies);

    struct Currency currencyToConvert = findCurrencyInput(userCurrency, worldCurrencies);
    struct Currency currencyToConvertTo = findCurrencyInput(desiredCurrency, worldCurrencies);

    double convertedAmount = convertFromDollars(currencyToConvertTo, convertToDollars(currencyToConvert, userAmount));

    printf("%.2lf %s is %.2lf %s\n", userAmount, userCurrency, desiredCurrency, convertedAmount);
    
    return 0;
}