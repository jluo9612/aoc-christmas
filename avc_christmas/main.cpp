//
//  main.cpp
//  avc_christmas
//
//  Created by J-lo on 12/2/16.
//  Copyright © 2016 JL. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    
    // method 1
    
    // initial values
    // currentDirection = 'N'
    // coordinates
    
    // take from one direction:
    // change in direction
    // blocks
    
    // in for-loop:
    // check which direction by +/-1
    // if N/S, change y value
    // if W/E, change x value
    
    struct Coordinates {
        int x;
        int y;
    };
    
    Coordinates currentPoint;
    currentPoint.x = 0;
    currentPoint.y = 0;
    
    int currentDirection = 0;
    string directions = "L5, R1, L5, L1, R5, R1, R1, L4, L1, L3, R2, R4, L4, L1, L1, R2, R4, R3, L1, R4, L4, L5, L4, R4, L5, R1, R5, L2, R1, R3, L2, L4, L4, R1, L192, R5, R1, R4, L5, L4, R5, L1, L1, R48, R5, R5, L2, R4, R4, R1, R3, L1, L4, L5, R1, L4, L2, L5, R5, L2, R74, R4, L1, R188, R5, L4, L2, R5, R2, L4, R4, R3, R3, R2, R1, L3, L2, L5, L5, L2, L1, R1, R5, R4, L3, R5, L1, L3, R4, L1, L3, L2, R1, R3, R2, R5, L3, L1, L1, R5, L4, L5, R5, R2, L5, R2, L1, L5, L3, L5, L5, L1, R1, L4, L3, L1, R2, R5, L1, L3, R4, R5, L4, L1, R5, L1, R5, R5, R5, R2, R1, R2, L5, L5, L5, R4, L5, L4, L4, R5, L2, R1, R5, L1, L5, R4, L3, R4, L2, R3, R3, R3, L2, L2, L2, L1, L4, R3, L4, L2, R2, R5, L1, R2";
    
    string num;
    int blocks = 0;
    
    for (int i = 0; i <= directions.length(); i++) {
        if (!(directions[i] == ',')) {
            if (directions[i] == 'L') {
                currentDirection--;
            } else if (directions[i] == 'R') {
                currentDirection++;
            } else if ((48 <= directions[i]) && (directions[i] <= 57)){
                num += directions[i];
            }
            cout << currentDirection << endl;
        } else {
            blocks = stoi(num);
            num = "";
            if ((currentDirection%4) == 0) {
                currentPoint.y += blocks;
            } else if (((currentDirection%4) == 2) || ((currentDirection%4) == -2)) {
                currentPoint.y -= blocks;
            } else if (((currentDirection%4) == 1) || ((currentDirection%4) == -3)) {
                currentPoint.x += blocks;
            } else if (((currentDirection%4) == 3) || ((currentDirection%4) == -1) ) {
                currentPoint.x -= blocks;
            }
        }
    }
    
    blocks = stoi(num);
    if ((currentDirection%4) == 0) {
        currentPoint.y += blocks;
    } else if (((currentDirection%4) == 2) || ((currentDirection%4) == -2)) {
        currentPoint.y -= blocks;
    } else if (((currentDirection%4) == 1) || ((currentDirection%4) == -3)) {
        currentPoint.x += blocks;
    } else if (((currentDirection%4) == 3) || ((currentDirection%4) == -1) ) {
        currentPoint.x -= blocks;
    }
    
    cout << currentPoint.x << ", " << currentPoint.y << endl;
    

}
