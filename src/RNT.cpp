//RNT 
#include <iomanip>
#include <iostream>
#include "RNT.h"
using namespace std;

//residual nitrogen time function 
int Residual_time::RNT(char repet_group, double SI_time, int depth){
    char new_repet;
    int RNT_time = 0;


    //find new repet group;
    if (repet_group == 'A'){new_repet = 'A';}

    else if (repet_group == 'B'){
        if (SI_time >= .10 && SI_time <= 1.16){new_repet = 'B';}
        else{new_repet = 'A';}
    }

    else if(repet_group == 'C'){
        if(SI_time >= .10 && SI_time <= .55){new_repet = 'C';}
        else if (SI_time >= .56 && SI_time <= 2.11){new_repet = 'B';}
        else{new_repet = 'A';}
    }

    else if(repet_group == 'D'){
        if(SI_time >=.10 && SI_time <=.52){new_repet = 'D';}
        else if(SI_time >=.53  && SI_time <=1.47){new_repet = 'C';}
        else if(SI_time >=1.48  && SI_time <= 3.03){new_repet = 'B';}
        else{new_repet = 'A';}
    }
    
    else if(repet_group == 'E'){
        if(SI_time >=.10 && SI_time <=.52){new_repet = 'E';}
        else if(SI_time >=.53  && SI_time <=1.44){new_repet = 'D';}
        else if(SI_time >=1.45  && SI_time <= 2.39){new_repet = 'C';}
        else if(SI_time >=2.40  && SI_time <= 3.55){new_repet = 'B';}
        else{new_repet = 'A';}
    }

    else if(repet_group == 'F'){
        if(SI_time >=.10 && SI_time <=.52){new_repet = 'F';}
        else if(SI_time >=.53  && SI_time <=1.44){new_repet = 'E';}
        else if(SI_time >=1.45  && SI_time <= 2.37){new_repet = 'D';}
        else if(SI_time >=2.38  && SI_time <= 3.31){new_repet = 'C';}
        else if(SI_time >=3.32  && SI_time <= 4.48){new_repet = 'B';}
        else{new_repet = 'A';}
    }

    else if(repet_group == 'G'){
        if(SI_time >=.10 && SI_time <=.52){new_repet = 'G';}
        else if(SI_time >=.53  && SI_time <=1.44){new_repet = 'F';}
        else if(SI_time >=1.45  && SI_time <= 2.37){new_repet = 'E';}
        else if(SI_time >=2.38  && SI_time <= 3.29){new_repet = 'D';}
        else if(SI_time >=3.30  && SI_time <= 4.23){new_repet = 'C';}
        else if(SI_time >=4.24  && SI_time <= 5.40){new_repet = 'B';}
        else{new_repet = 'A';}
    }

    else if(repet_group == 'H'){
        if(SI_time >=.10 && SI_time <=.52){new_repet = 'H';}
        else if(SI_time >=.53  && SI_time <=1.44){new_repet = 'G';}
        else if(SI_time >=1.45  && SI_time <= 2.37){new_repet = 'F';}
        else if(SI_time >=2.38  && SI_time <= 3.29){new_repet = 'E';}
        else if(SI_time >=3.30  && SI_time <= 4.21){new_repet = 'D';}
        else if(SI_time >=4.22  && SI_time <= 5.16){new_repet = 'C';}
        else if(SI_time >=5.17  && SI_time <= 6.32){new_repet = 'B';}
        else{new_repet = 'A';}
    }
    
    else if(repet_group == 'I'){
        if(SI_time >=.10 && SI_time <=.52){new_repet = 'I';}
        else if(SI_time >=.53  && SI_time <=1.44){new_repet = 'H';}
        else if(SI_time >=1.45  && SI_time <= 2.37){new_repet = 'G';}
        else if(SI_time >=2.38  && SI_time <= 3.29){new_repet = 'F';}
        else if(SI_time >=3.30  && SI_time <= 4.21){new_repet = 'E';}
        else if(SI_time >=4.22  && SI_time <= 5.13){new_repet = 'D';}
        else if(SI_time >=5.14  && SI_time <= 6.08){new_repet = 'C';}
        else if(SI_time >=6.09  && SI_time <= 7.24){new_repet = 'B';}
        else{new_repet = 'A';}
    }

    else if(repet_group == 'J'){
        if(SI_time >=.10 && SI_time <=.52){new_repet = 'J';}
        else if(SI_time >=.53  && SI_time <=1.44){new_repet = 'I';}
        else if(SI_time >=1.45  && SI_time <= 2.37){new_repet = 'H';}
        else if(SI_time >=2.38  && SI_time <= 3.29){new_repet = 'G';}
        else if(SI_time >=3.30  && SI_time <= 4.21){new_repet = 'F';}
        else if(SI_time >=4.22  && SI_time <= 5.13){new_repet = 'E';}
        else if(SI_time >=5.14  && SI_time <= 6.06){new_repet = 'D';}
        else if(SI_time >=6.07  && SI_time <= 7.00){new_repet = 'C';}
        else if(SI_time >=7.01  && SI_time <= 8.16){new_repet = 'B';}
        else{new_repet = 'A';}
    }

    else if(repet_group == 'K'){
        if(SI_time >=.10 && SI_time <=.52){new_repet = 'K';}
        else if(SI_time >=.53  && SI_time <=1.44){new_repet = 'J';}
        else if(SI_time >=1.45  && SI_time <= 2.37){new_repet = 'I';}
        else if(SI_time >=2.38  && SI_time <= 3.29){new_repet = 'H';}
        else if(SI_time >=3.30  && SI_time <= 4.21){new_repet = 'G';}
        else if(SI_time >=4.22  && SI_time <= 5.13){new_repet = 'F';}
        else if(SI_time >=5.14  && SI_time <= 6.06){new_repet = 'E';}
        else if(SI_time >=6.07  && SI_time <= 6.58){new_repet = 'D';}
        else if(SI_time >=6.59  && SI_time <= 7.52){new_repet = 'C';}
        else if(SI_time >=7.53  && SI_time <= 9.09){new_repet = 'B';}
        else{new_repet = 'A';}
    }

    
    else if(repet_group == 'L'){
        if(SI_time >=.10 && SI_time <=.52){new_repet = 'L';}
        else if(SI_time >=.53  && SI_time <=1.44){new_repet = 'K';}
        else if(SI_time >=1.45  && SI_time <= 2.37){new_repet = 'J';}
        else if(SI_time >=2.38  && SI_time <= 3.29){new_repet = 'I';}
        else if(SI_time >=3.30  && SI_time <= 4.21){new_repet = 'H';}
        else if(SI_time >=4.22  && SI_time <= 5.13){new_repet = 'G';}
        else if(SI_time >=5.14  && SI_time <= 6.06){new_repet = 'F';}
        else if(SI_time >=6.07  && SI_time <= 6.58){new_repet = 'E';}
        else if(SI_time >=6.59  && SI_time <= 7.50){new_repet = 'D';}
        else if(SI_time >=7.51  && SI_time <= 8.44){new_repet = 'C';}
        else if(SI_time >=8.45  && SI_time <= 10.01){new_repet = 'B';}
        else{new_repet = 'A';}
    }

    else if(repet_group == 'M'){
        if(SI_time >=.10 && SI_time <=.52){new_repet = 'M';}
        else if(SI_time >=.53  && SI_time <=1.44){new_repet = 'L';}
        else if(SI_time >=1.45  && SI_time <= 2.37){new_repet = 'K';}
        else if(SI_time >=2.38  && SI_time <= 3.29){new_repet = 'J';}
        else if(SI_time >=3.30  && SI_time <= 4.21){new_repet = 'I';}
        else if(SI_time >=4.22  && SI_time <= 5.13){new_repet = 'H';}
        else if(SI_time >=5.14  && SI_time <= 6.06){new_repet = 'G';}
        else if(SI_time >=6.07  && SI_time <= 6.58){new_repet = 'F';}
        else if(SI_time >=6.59  && SI_time <= 7.50){new_repet = 'E';}
        else if(SI_time >=7.51  && SI_time <= 8.42){new_repet = 'D';}
        else if(SI_time >=8.43  && SI_time <= 9.37){new_repet = 'C';}
        else if(SI_time >=9.38  && SI_time <= 10.53){new_repet = 'B';}
        else{new_repet = 'A';}
    }

    else if(repet_group == 'N'){
        if(SI_time >=.10 && SI_time <=.52){new_repet = 'N';}
        else if(SI_time >=.53  && SI_time <=1.44){new_repet = 'M';}
        else if(SI_time >=1.45  && SI_time <= 2.37){new_repet = 'L';}
        else if(SI_time >=2.38  && SI_time <= 3.29){new_repet = 'K';}
        else if(SI_time >=3.30  && SI_time <= 4.21){new_repet = 'J';}
        else if(SI_time >=4.22  && SI_time <= 5.13){new_repet = 'I';}
        else if(SI_time >=5.14  && SI_time <= 6.06){new_repet = 'H';}
        else if(SI_time >=6.07  && SI_time <= 6.58){new_repet = 'G';}
        else if(SI_time >=6.59  && SI_time <= 7.50){new_repet = 'F';}
        else if(SI_time >=7.51  && SI_time <= 8.42){new_repet = 'E';}
        else if(SI_time >=8.43  && SI_time <= 9.34){new_repet = 'D';}
        else if(SI_time >=9.35  && SI_time <= 10.29){new_repet = 'C';}
        else if(SI_time >=10.30 && SI_time <= 11.45){new_repet = 'B';}
        else{new_repet = 'A';}
    }

    else if(repet_group == 'O'){
        if(SI_time >=.10 && SI_time <=.52){new_repet = 'O';}
        else if(SI_time >=.53  && SI_time <=1.44){new_repet = 'N';}
        else if(SI_time >=1.45  && SI_time <= 2.37){new_repet = 'M';}
        else if(SI_time >=2.38  && SI_time <= 3.29){new_repet = 'L';}
        else if(SI_time >=3.30  && SI_time <= 4.21){new_repet = 'K';}
        else if(SI_time >=4.22  && SI_time <= 5.13){new_repet = 'J';}
        else if(SI_time >=5.14  && SI_time <= 6.06){new_repet = 'I';}
        else if(SI_time >=6.07  && SI_time <= 6.58){new_repet = 'H';}
        else if(SI_time >=6.59  && SI_time <= 7.50){new_repet = 'G';}
        else if(SI_time >=7.51  && SI_time <= 8.42){new_repet = 'F';}
        else if(SI_time >=8.43  && SI_time <= 9.34){new_repet = 'E';}
        else if(SI_time >=9.35  && SI_time <= 10.27){new_repet = 'D';}
        else if(SI_time >=10.28 && SI_time <= 11.21){new_repet = 'C';}
        else if(SI_time >=11.22 && SI_time <= 12.37){new_repet = 'B';}
        else{new_repet = 'A';}
    }

    else if(repet_group == 'Z'){
        if(SI_time >=.10 && SI_time <=.52){new_repet = 'Z';}
        else if(SI_time >=.53  && SI_time <=1.44){new_repet = 'O';}
        else if(SI_time >=1.45  && SI_time <= 2.37){new_repet = 'N';}
        else if(SI_time >=2.38  && SI_time <= 3.29){new_repet = 'M';}
        else if(SI_time >=3.30  && SI_time <= 4.21){new_repet = 'L';}
        else if(SI_time >=4.22  && SI_time <= 5.13){new_repet = 'K';}
        else if(SI_time >=5.14  && SI_time <= 6.06){new_repet = 'J';}
        else if(SI_time >=6.07  && SI_time <= 6.58){new_repet = 'I';}
        else if(SI_time >=6.59  && SI_time <= 7.50){new_repet = 'H';}
        else if(SI_time >=7.51  && SI_time <= 8.42){new_repet = 'G';}
        else if(SI_time >=8.43  && SI_time <= 9.34){new_repet = 'F';}
        else if(SI_time >=9.35  && SI_time <= 10.27){new_repet = 'E';}
        else if(SI_time >=10.28 && SI_time <= 11.19){new_repet = 'D';}
        else if(SI_time >=11.20 && SI_time <= 12.13){new_repet = 'C';}
        else if(SI_time >=12.14 && SI_time <= 13.30){new_repet = 'B';}
        else{new_repet = 'A';}
    }


    //find RNT to be added to actual bottom time:
    if (new_repet == 'A'){
        if (depth == 30){RNT_time = 18;}
        else if (depth == 31 || depth == 32 ){RNT_time = 17;}
        else if (depth == 33 || depth == 34){RNT_time = 16;}
        else if (depth == 35 || depth == 36){RNT_time = 15;}
        else if (depth == 37 || depth == 38 || depth == 39){RNT_time = 14;}
        else if (depth == 40 || depth == 41 || depth == 42){RNT_time = 13;}
        else if (depth == 43 || depth == 44 || depth == 45 || depth == 46){RNT_time = 12;}
        else if (depth == 47 || depth == 48 || depth == 49 || depth == 50){RNT_time = 11;}

    }

    else if (new_repet == 'B'){
        if (depth == 30){RNT_time = 28;}
        else if (depth == 31){RNT_time = 27;}
        else if (depth == 32){RNT_time = 26;}
        else if (depth == 33 || depth == 34 ){RNT_time = 25;}
        else if (depth == 35){RNT_time = 24;}
        else if (depth == 36 || depth == 37 ){RNT_time = 23;}
        else if (depth == 38){RNT_time = 22;}
        else if (depth == 39 || depth == 40 ){RNT_time = 21;}
        else if (depth == 41 || depth == 42 ){RNT_time = 20;}
        else if (depth == 43 || depth == 44 ){RNT_time = 19;}
        else if (depth == 45 || depth == 46 || depth == 47){RNT_time = 18;}
        else if (depth == 48 || depth == 49 || depth == 50){RNT_time = 17;}
    }   

    else if (new_repet == 'C'){
        if (depth == 30){RNT_time = 39;}
        else if (depth == 31){RNT_time = 38;}
        else if (depth == 32){RNT_time = 36;}
        else if (depth == 33){RNT_time = 35;}
        else if (depth == 34){RNT_time = 34;}
        else if (depth == 35){RNT_time = 33;}
        else if (depth == 36){RNT_time = 32;}
        else if (depth == 37){RNT_time = 31;}
        else if (depth == 38){RNT_time = 30;}
        else if (depth == 39 || depth == 40 ){RNT_time = 29;}
        else if (depth == 41){RNT_time = 28;}
        else if (depth == 42){RNT_time = 27;}
        else if (depth == 43 || depth == 44 ){RNT_time = 26;}
        else if (depth == 45 || depth == 46 ){RNT_time = 25;}
        else if (depth == 47 || depth == 48 ){RNT_time = 24;}
        else if (depth == 49 || depth == 50 ){RNT_time = 23;}
    
    }

    else if (new_repet == 'D'){
        if (depth == 30){RNT_time = 51;}
        else if (depth == 31){RNT_time = 49;}
        else if (depth == 32){RNT_time = 47;}
        else if (depth == 33){RNT_time = 46;}
        else if (depth == 34){RNT_time = 44;}
        else if (depth == 35){RNT_time = 43;}
        else if (depth == 36){RNT_time = 41;}
        else if (depth == 37){RNT_time = 40;}
        else if (depth == 38){RNT_time = 39;}
        else if (depth == 39){RNT_time = 38;}
        else if (depth == 40){RNT_time = 37;}
        else if (depth == 41){RNT_time = 36;}
        else if (depth == 42){RNT_time = 35;}
        else if (depth == 43){RNT_time = 34;}
        else if (depth == 44){RNT_time = 33;}
        else if (depth == 45 || depth == 46 ){RNT_time = 32;}
        else if (depth == 47){RNT_time = 31;}
        else if (depth == 48 || depth == 49 ){RNT_time = 30;}
        else if (depth == 50){RNT_time = 29;}
    }

    else if (new_repet == 'E'){
        if (depth == 30){RNT_time = 63;}
        else if (depth == 31){RNT_time = 61;}
        else if (depth == 32){RNT_time = 59;}
        else if (depth == 33){RNT_time = 57;}
        else if (depth == 34){RNT_time = 55;}
        else if (depth == 35){RNT_time = 53;}
        else if (depth == 36){RNT_time = 51;}
        else if (depth == 37){RNT_time = 50;}
        else if (depth == 38){RNT_time = 48;}
        else if (depth == 39){RNT_time = 47;}
        else if (depth == 40){RNT_time = 45;}
        else if (depth == 41){RNT_time = 44;}
        else if (depth == 42){RNT_time = 43;}
        else if (depth == 43){RNT_time = 42;}
        else if (depth == 44){RNT_time = 41;}
        else if (depth == 45){RNT_time = 40;}
        else if (depth == 46){RNT_time = 39;}
        else if (depth == 47){RNT_time = 38;}
        else if (depth == 48){RNT_time = 37;}
        else if (depth == 49){RNT_time = 36;}
        else if (depth == 50){RNT_time = 35;}
    }

    else if (new_repet == 'F'){
        if (depth == 30){RNT_time = 77;}
        else if (depth == 31){RNT_time = 74;}
        else if (depth == 32){RNT_time = 71;}
        else if (depth == 33){RNT_time = 69;}
        else if (depth == 34){RNT_time = 66;}
        else if (depth == 35){RNT_time = 64;}
        else if (depth == 36){RNT_time = 62;}
        else if (depth == 37){RNT_time = 60;}
        else if (depth == 38){RNT_time = 58;}
        else if (depth == 39){RNT_time = 56;}
        else if (depth == 40){RNT_time = 55;}
        else if (depth == 41){RNT_time = 53;}
        else if (depth == 42){RNT_time = 52;}
        else if (depth == 43){RNT_time = 50;}
        else if (depth == 44){RNT_time = 49;}
        else if (depth == 45){RNT_time = 48;}
        else if (depth == 46){RNT_time = 46;}
        else if (depth == 47){RNT_time = 45;}
        else if (depth == 48){RNT_time = 44;}
        else if (depth == 49){RNT_time = 43;}
        else if (depth == 50){RNT_time = 42;}
    }

    else if (new_repet == 'G'){
        if (depth == 30){RNT_time = 92;}
        else if (depth == 31){RNT_time = 88;}
        else if (depth == 32){RNT_time = 85;}
        else if (depth == 33){RNT_time = 81;}
        else if (depth == 34){RNT_time = 78;}
        else if (depth == 35){RNT_time = 75;}
        else if (depth == 36){RNT_time = 73;}
        else if (depth == 37){RNT_time = 70;}
        else if (depth == 38){RNT_time = 68;}
        else if (depth == 39){RNT_time = 66;}
        else if (depth == 40){RNT_time = 64;}
        else if (depth == 41){RNT_time = 62;}
        else if (depth == 42){RNT_time = 61;}
        else if (depth == 43){RNT_time = 59;}
        else if (depth == 44){RNT_time = 57;}
        else if (depth == 45){RNT_time = 56;}
        else if (depth == 46){RNT_time = 54;}
        else if (depth == 47){RNT_time = 53;}
        else if (depth == 48){RNT_time = 52;}
        else if (depth == 49){RNT_time = 51;}
        else if (depth == 50){RNT_time = 49;}
    }

    else if (new_repet == 'H'){
        if (depth == 30){RNT_time = 108;}
        else if (depth == 31){RNT_time = 103;}
        else if (depth == 32){RNT_time = 99;}
        else if (depth == 33){RNT_time = 95;}
        else if (depth == 34){RNT_time = 91;}
        else if (depth == 35){RNT_time = 88;}
        else if (depth == 36){RNT_time = 85;}
        else if (depth == 37){RNT_time = 82;}
        else if (depth == 38){RNT_time = 79;}
        else if (depth == 39){RNT_time = 77;}
        else if (depth == 40){RNT_time = 74;}
        else if (depth == 41){RNT_time = 72;}
        else if (depth == 42){RNT_time = 70;}
        else if (depth == 43){RNT_time = 68;}
        else if (depth == 44){RNT_time = 66;}
        else if (depth == 45){RNT_time = 64;}
        else if (depth == 46){RNT_time = 63;}
        else if (depth == 47){RNT_time = 61;}
        else if (depth == 48){RNT_time = 60;}
        else if (depth == 49){RNT_time = 58;}
        else if (depth == 50){RNT_time = 57;}
    }

    else if (new_repet == 'I'){
        if (depth == 30){RNT_time = 126;}
        else if (depth == 31){RNT_time = 120;}
        else if (depth == 32){RNT_time = 115;}
        else if (depth == 33){RNT_time = 110;}
        else if (depth == 34){RNT_time = 105;}
        else if (depth == 35){RNT_time = 101;}
        else if (depth == 36){RNT_time = 98;}
        else if (depth == 37){RNT_time = 94;}
        else if (depth == 38){RNT_time = 91;}
        else if (depth == 39){RNT_time = 88;}
        else if (depth == 40){RNT_time = 85;}
        else if (depth == 41){RNT_time = 82;}
        else if (depth == 42){RNT_time = 80;}
        else if (depth == 43){RNT_time = 78;}
        else if (depth == 44){RNT_time = 75;}
        else if (depth == 45){RNT_time = 73;}
        else if (depth == 46){RNT_time = 71;}
        else if (depth == 47){RNT_time = 70;}
        else if (depth == 48){RNT_time = 68;}
        else if (depth == 49){RNT_time = 66;}
        else if (depth == 50){RNT_time = 65;}
    }

    else if (new_repet == 'J'){
        if (depth == 30){RNT_time = 146;}
        else if (depth == 31){RNT_time = 139;}
        else if (depth == 32){RNT_time = 132;}
        else if (depth == 33){RNT_time = 126;}
        else if (depth == 34){RNT_time = 121;}
        else if (depth == 35){RNT_time = 116;}
        else if (depth == 36){RNT_time = 111;}
        else if (depth == 37){RNT_time = 107;}
        else if (depth == 38){RNT_time = 103;}
        else if (depth == 39){RNT_time = 100;}
        else if (depth == 40){RNT_time = 97;}
        else if (depth == 41){RNT_time = 93;}
        else if (depth == 42){RNT_time = 91;}
        else if (depth == 43){RNT_time = 88;}
        else if (depth == 44){RNT_time = 85;}
        else if (depth == 45){RNT_time = 83;}
        else if (depth == 46){RNT_time = 81;}
        else if (depth == 47){RNT_time = 78;}
        else if (depth == 48){RNT_time = 76;}
        else if (depth == 49){RNT_time = 74;}
        else if (depth == 50){RNT_time = 73;}
    }

    else if (new_repet == 'K'){
        if (depth == 30){RNT_time = 168;}
        else if (depth == 31){RNT_time = 159;}
        else if (depth == 32){RNT_time = 151;}
        else if (depth == 33){RNT_time = 144;}
        else if (depth == 34){RNT_time = 138;}
        else if (depth == 35){RNT_time = 132;}
        else if (depth == 36){RNT_time = 126;}
        else if (depth == 37){RNT_time = 122;}
        else if (depth == 38){RNT_time = 117;}
        else if (depth == 39){RNT_time = 113;}
        else if (depth == 40){RNT_time = 109;}
        else if (depth == 41){RNT_time = 105;}
        else if (depth == 42){RNT_time = 102;}
        else if (depth == 43){RNT_time = 99;}
        else if (depth == 44){RNT_time = 96;}
        else if (depth == 45){RNT_time = 93;}
        else if (depth == 46){RNT_time = 90;}
        else if (depth == 47){RNT_time = 88;}
        else if (depth == 48){RNT_time = 85;}
        else if (depth == 49){RNT_time = 83;}
        else if (depth == 50){RNT_time = 81;}
    }

    else if (new_repet == 'L'){
        if (depth == 30){RNT_time = 194;}
        else if (depth == 31){RNT_time = 183;}
        else if (depth == 32){RNT_time = 173;}
        else if (depth == 33){RNT_time = 164;}
        else if (depth == 34){RNT_time = 156;}
        else if (depth == 35){RNT_time = 149;}
        else if (depth == 36){RNT_time = 143;}
        else if (depth == 37){RNT_time = 137;}
        else if (depth == 38){RNT_time = 132;}
        else if (depth == 39){RNT_time = 127;}
        else if (depth == 40){RNT_time = 122;}
        else if (depth == 41){RNT_time = 118;}
        else if (depth == 42){RNT_time = 114;}
        else if (depth == 43){RNT_time = 110;}
        else if (depth == 44){RNT_time = 107;}
        else if (depth == 45){RNT_time = 104;}
        else if (depth == 46){RNT_time = 101;}
        else if (depth == 47){RNT_time = 98;}
        else if (depth == 48){RNT_time = 95;}
        else if (depth == 49){RNT_time = 92;}
        else if (depth == 50){RNT_time = 90;}
    }

    else if (new_repet == 'M'){
        if (depth == 30){RNT_time = 224;}
        else if (depth == 31){RNT_time = 210;}
        else if (depth == 32){RNT_time = 198;}
        else if (depth == 33){RNT_time = 187;}
        else if (depth == 34){RNT_time = 177;}
        else if (depth == 35){RNT_time = 169;}
        else if (depth == 36){RNT_time = 161;}
        else if (depth == 37){RNT_time = 154;}
        else if (depth == 38){RNT_time = 148;}
        else if (depth == 39){RNT_time = 142;}
        else if (depth == 40){RNT_time = 136;}
        else if (depth == 41){RNT_time = 132;}
        else if (depth == 42){RNT_time = 127;}
        else if (depth == 43){RNT_time = 123;}
        else if (depth == 44){RNT_time = 119;}
        else if (depth == 45){RNT_time = 115;}
        else if (depth == 46){RNT_time = 111;}
        else if (depth == 47){RNT_time = 108;}
        else if (depth == 48){RNT_time = 105;}
        else if (depth == 49){RNT_time = 102;}
        else if (depth == 50){RNT_time = 99;}
    }

    else if (new_repet == 'N'){
        if (depth == 30){RNT_time = 261;}
        else if (depth == 31){RNT_time = 243;}
        else if (depth == 32){RNT_time = 227;}
        else if (depth == 33){RNT_time = 213;}
        else if (depth == 34){RNT_time = 201;}
        else if (depth == 35){RNT_time = 191;}
        else if (depth == 36){RNT_time = 181;}
        else if (depth == 37){RNT_time = 173;}
        else if (depth == 38){RNT_time = 165;}
        else if (depth == 39){RNT_time = 158;}
        else if (depth == 40){RNT_time = 152;}
        else if (depth == 41){RNT_time = 146;}
        else if (depth == 42){RNT_time = 141;}
        else if (depth == 43){RNT_time = 136;}
        else if (depth == 44){RNT_time = 131;}
        else if (depth == 45){RNT_time = 127;}
        else if (depth == 46){RNT_time = 123;}
        else if (depth == 47){RNT_time = 119;}
        else if (depth == 48){RNT_time = 116;}
        else if (depth == 49){RNT_time = 112;}
        else if (depth == 50){RNT_time = 109;}
    }

    else if (new_repet == 'O'){
        if (depth == 30){RNT_time = 308;}
        else if (depth == 31){RNT_time = 282;}
        else if (depth == 32){RNT_time = 262;}
        else if (depth == 33){RNT_time = 244;}
        else if (depth == 34){RNT_time = 229;}
        else if (depth == 35){RNT_time = 126;}
        else if (depth == 36){RNT_time = 204;}
        else if (depth == 37){RNT_time = 194;}
        else if (depth == 38){RNT_time = 185;}
        else if (depth == 39){RNT_time = 177;}
        else if (depth == 40){RNT_time = 169;}
        else if (depth == 41){RNT_time = 163;}
        else if (depth == 42){RNT_time = 156;}
        else if (depth == 43){RNT_time = 150;}
        else if (depth == 44){RNT_time = 145;}
        else if (depth == 45){RNT_time = 140;}
        else if (depth == 46){RNT_time = 136;}
        else if (depth == 47){RNT_time = 131;}
        else if (depth == 48){RNT_time = 127;}
        else if (depth == 49){RNT_time = 123;}
        else if (depth == 50){RNT_time = 120;}
    }

    else if (new_repet == 'Z'){
        if (depth == 30){RNT_time = 372;}
        else if (depth == 31){RNT_time = 334;}
        else if (depth == 32){RNT_time = 305;}
        else if (depth == 33){RNT_time = 282;}
        else if (depth == 34){RNT_time = 262;}
        else if (depth == 35){RNT_time = 145;}
        else if (depth == 36){RNT_time = 231;}
        else if (depth == 37){RNT_time = 218;}
        else if (depth == 38){RNT_time = 207;}
        else if (depth == 39){RNT_time = 197;}
        else if (depth == 40){RNT_time = 188;}
        else if (depth == 41){RNT_time = 180;}
        else if (depth == 42){RNT_time = 173;}
        else if (depth == 43){RNT_time = 166;}
        else if (depth == 44){RNT_time = 160;}
        else if (depth == 45){RNT_time = 154;}
        else if (depth == 46){RNT_time = 149;}
        else if (depth == 47){RNT_time = 144;}
        else if (depth == 48){RNT_time = 139;}
        else if (depth == 49){RNT_time = 135;}
        else if (depth == 50){RNT_time = 131;}
    }

    return RNT_time;
}
