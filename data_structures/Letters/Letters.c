#include "../Shape/Shape.h"

//////////////////////
/* Draws Letters (capital letters)
 * 
 * Anchors at top left (x,y represents the top left of the letter)
 */

// Determines the universal font size
int scale = 24;


/* X = horizontal axis
 * Y = vertical axis
 * 
 * format: (y + scale * yScale, x + scale * xScale) 
 * where yScale and xScale should max at 1.
 */

Shape drawA(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(12 * sizeof(Point));
    Line* lines = (Line*) malloc(12 * sizeof(Line));

    //outer bottom part
    controlPoints[0] = point(y + scale * 1      , x                 );
    controlPoints[1] = point(y + scale * 1      , x + scale * 0.25  );
    controlPoints[2] = point(y + scale * 0.7143 , x + scale * 0.3125);
    controlPoints[3] = point(y + scale * 0.7143 , x + scale * 0.6875);
    controlPoints[4] = point(y + scale * 1      , x + scale * 0.75  );
    controlPoints[5] = point(y + scale * 1      , x + scale * 1     );
    //outer upper part
    controlPoints[6] = point(y, x + scale * 0.25);
    controlPoints[7] = point(y, x + scale * 0.75);
    //inner part
    controlPoints[8] = point(y + scale * 0.5714, x + scale * 0.375);
    controlPoints[9] = point(y + scale * 0.5714, x + scale * 0.625);
    controlPoints[10]  = point(y + scale * 0.2857, x + scale * 0.45);
    controlPoints[11]  = point(y + scale * 0.2857, x + scale * 0.55);

    //inner lines
    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[7]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[0], controlPoints[6]);
    lines[8] = line(controlPoints[9], controlPoints[8]);
    //outer lines
    lines[9] = line(controlPoints[9], controlPoints[11]);
    lines[10] = line(controlPoints[10], controlPoints[8]);
    lines[11] = line(controlPoints[10], controlPoints[11]);
    
    return shape(lines, 12, &c);
    
}


Shape drawB(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(21 * sizeof(Point));
    Line* lines = (Line*) malloc(21 * sizeof(Line));

    // Outer part
    // Left baseline
    controlPoints[0] = point(y + scale * 1      , x                 );
    controlPoints[1] = point(y                  , x                 );

    // Roof and Floor
    controlPoints[2] = point(y                  , x + scale * 0.8333);
    controlPoints[8] = point(y + scale * 1      , x + scale * 0.8333);

    // Rightmost lines
    controlPoints[3] = point(y + scale * 0.1667 , x + scale * 1     );
    controlPoints[4] = point(y + scale * 0.3333 , x + scale * 1     );
    controlPoints[6] = point(y + scale * 0.6667 , x + scale * 1     );
    controlPoints[7] = point(y + scale * 0.8333 , x + scale * 1     );

    // Middle point
    controlPoints[5] = point(y + scale * 0.5    , x + scale * 0.8333);
    
    // Inner part
    // Top hole
    controlPoints[9]   = point(y + scale * 0.0833, x + scale * 0.1667);
    controlPoints[10]  = point(y + scale * 0.0833, x + scale * 0.6667);
    controlPoints[11]  = point(y + scale * 0.1667, x + scale * 0.8);
    controlPoints[12]  = point(y + scale * 0.3333, x + scale * 0.8);
    controlPoints[13]  = point(y + scale * 0.4167, x + scale * 0.6667);
    controlPoints[14]  = point(y + scale * 0.4167, x + scale * 0.1667);

    // Bottom hole
    controlPoints[15]  = point(y + scale * 0.5833, x + scale * 0.1667);
    controlPoints[16]  = point(y + scale * 0.5833, x + scale * 0.6667);
    controlPoints[17]  = point(y + scale * 0.6667, x + scale * 0.8   );
    controlPoints[18]  = point(y + scale * 0.8333, x + scale * 0.8   );
    controlPoints[19]  = point(y + scale * 0.9167, x + scale * 0.6667);
    controlPoints[20]  = point(y + scale * 0.9167, x + scale * 0.1667);

    // Outer lines
    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[0]);
    
    // Inner lines
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[11]);
    lines[11] = line(controlPoints[11], controlPoints[12]);
    lines[12] = line(controlPoints[12], controlPoints[13]);
    lines[13] = line(controlPoints[13], controlPoints[14]);
    lines[14] = line(controlPoints[14], controlPoints[9]);

    lines[15] = line(controlPoints[15], controlPoints[16]);
    lines[16] = line(controlPoints[16], controlPoints[17]);
    lines[17] = line(controlPoints[17], controlPoints[18]);
    lines[18] = line(controlPoints[18], controlPoints[19]);
    lines[19] = line(controlPoints[19], controlPoints[20]);
    lines[20] = line(controlPoints[20], controlPoints[15]);
    
    return shape(lines, 21, &c);
    
}

Shape drawC(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(8 * sizeof(Point));
    Line* lines = (Line*) malloc(8 * sizeof(Line));

    controlPoints[0] = point(y + scale * 1      , x                 );
    controlPoints[1] = point(y + scale * 1      , x + scale * 1     );
    controlPoints[2] = point(y + scale * 0.72   , x + scale * 1     );
    controlPoints[3] = point(y + scale * 0.72   , x + scale * 0.28  );
    controlPoints[4] = point(y + scale * 0.28   , x + scale * 0.28  );
    controlPoints[5] = point(y + scale * 0.28   , x + scale * 1     );
    controlPoints[6] = point(y                  , x + scale * 1     );
    controlPoints[7] = point(y                  , x                 );

    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[0]);
    
    return shape(lines,8,&c);
    
}

Shape drawD(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(12 * sizeof(Point));
    Line* lines = (Line*) malloc(12 * sizeof(Line));

    // Outer points
    controlPoints[0] = point(y + scale * 1      , x                 );
    controlPoints[1] = point(y + scale * 1      , x + scale * 0.75  );
    controlPoints[2] = point(y + scale * 0.8125 , x + scale * 1     );
    controlPoints[3] = point(y + scale * 0.1875 , x + scale * 1     );
    controlPoints[4] = point(y                  , x + scale * 0.75  );
    controlPoints[5] = point(y                  , x                 );

    // Inner points
    controlPoints[6]   = point(y + scale * 0.8125, x + scale * 0.1875);
    controlPoints[7]   = point(y + scale * 0.8125, x + scale * 0.625 );
    controlPoints[8]   = point(y + scale * 0.6563, x + scale * 0.8125);
    controlPoints[9]   = point(y + scale * 0.3438, x + scale * 0.8125);
    controlPoints[10]  = point(y + scale * 0.1875, x + scale * 0.625 );
    controlPoints[11]  = point(y + scale * 0.1875, x + scale * 0.1875);

    // Outer lines
    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[0]);

    // Inner lines
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[11]);
    lines[11] = line(controlPoints[11], controlPoints[6]);

    return shape(lines, 12, &c);
}

Shape drawE(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(12 * sizeof(Point));
    Line* lines = (Line*) malloc(12 * sizeof(Line));

    
    controlPoints[0]  = point(y + scale * 1     , x                  );
    controlPoints[1]  = point(y + scale * 1     , x + scale * 1      );
    controlPoints[2]  = point(y + scale * 0.8   , x + scale * 1      );
    controlPoints[3]  = point(y + scale * 0.8   , x + scale * 0.2    );
    controlPoints[4]  = point(y + scale * 0.6   , x + scale * 0.2    );
    controlPoints[5]  = point(y + scale * 0.6   , x + scale * 1      );
    controlPoints[6]  = point(y + scale * 0.4   , x + scale * 1      );
    controlPoints[7]  = point(y + scale * 0.4   , x + scale * 0.2    );
    controlPoints[8]  = point(y + scale * 0.2   , x + scale * 0.2    );
    controlPoints[9]  = point(y + scale * 0.2   , x + scale * 1      );
    controlPoints[10] = point(y                 , x + scale * 1      );
    controlPoints[11] = point(y                 , x                  );
    
    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[11]);
    lines[11] = line(controlPoints[11], controlPoints[0]);
    return shape(lines, 12, &c);
}

Shape drawF(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(10 * sizeof(Point));
    Line* lines = (Line*) malloc(10 * sizeof(Line));

    
    controlPoints[0]  = point(y + scale * 1     , x                  );
    controlPoints[1]  = point(y + scale * 1     , x + scale * 0.2    );
    controlPoints[2]  = point(y + scale * 0.6   , x + scale * 0.2    );    
    controlPoints[3]  = point(y + scale * 0.6   , x + scale * 1      );    
    controlPoints[4]  = point(y + scale * 0.4   , x + scale * 1      );    
    controlPoints[5]  = point(y + scale * 0.4   , x + scale * 0.2    );
    controlPoints[6]  = point(y + scale * 0.2   , x + scale * 0.2    );
    controlPoints[7]  = point(y + scale * 0.2   , x + scale * 1      );
    controlPoints[8]  = point(y                 , x + scale * 1      );
    controlPoints[9]  = point(y                 , x                  );
    
    
    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[0]);
    
    return shape(lines, 10, &c);


}


Shape drawG(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(12 * sizeof(Point));
    Line* lines = (Line*) malloc(12 * sizeof(Line));

    controlPoints[0] = point(y + scale * 1      , x                 );
    controlPoints[1] = point(y + scale * 1      , x + scale * 1     );
    controlPoints[2] = point(y + scale * 0.4    , x + scale * 1     );
    controlPoints[3] = point(y + scale * 0.4    , x + scale * 0.6   );
    controlPoints[4] = point(y + scale * 0.6    , x + scale * 0.6   );
    controlPoints[5] = point(y + scale * 0.6    , x + scale * 0.8   );
    controlPoints[6] = point(y + scale * 0.8    , x + scale * 0.8   );
    controlPoints[7] = point(y + scale * 0.8    , x + scale * 0.2   );
    controlPoints[8] = point(y + scale * 0.2    , x + scale * 0.2   );
    controlPoints[9] = point(y + scale * 0.2    , x + scale * 1     );
    controlPoints[10] = point(y                  , x + scale * 1    );
    controlPoints[11] = point(y                  , x                );

    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[11]);
    lines[11] = line(controlPoints[11], controlPoints[0]);
    
    return shape(lines,12,&c);
    
}

Shape drawH(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(12 * sizeof(Point));
    Line* lines = (Line*) malloc(12 * sizeof(Line));

    controlPoints[0] = point(y + scale * 1      , x                 );
    controlPoints[1] = point(y + scale * 1      , x + scale * 0.25  );
    controlPoints[2] = point(y + scale * 0.625  , x + scale * 0.25  );
    controlPoints[3] = point(y + scale * 0.625  , x + scale * 0.75  );
    controlPoints[4] = point(y + scale * 1      , x + scale * 0.75  );
    controlPoints[5] = point(y + scale * 1      , x + scale * 1     );
    controlPoints[6] = point(y + scale * 0      , x + scale * 1     );
    controlPoints[7] = point(y + scale * 0      , x + scale * 0.75  );
    controlPoints[8] = point(y + scale * 0.375  , x + scale * 0.75  );
    controlPoints[9] = point(y + scale * 0.375  , x + scale * 0.25  );
    controlPoints[10] = point(y                  , x + scale * 0.25 );
    controlPoints[11] = point(y                  , x                );

    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[11]);
    lines[11] = line(controlPoints[11], controlPoints[0]);
    
    return shape(lines,12,&c);
    
}

Shape drawI(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(12 * sizeof(Point));
    Line* lines = (Line*) malloc(12 * sizeof(Line));

    controlPoints[0]  = point(y + scale * 1      , x                 );
    controlPoints[1]  = point(y + scale * 1      , x + scale * 1     );
    controlPoints[2]  = point(y + scale * 0.75   , x + scale * 1     );
    controlPoints[3]  = point(y + scale * 0.75   , x + scale * 0.625 );
    controlPoints[4]  = point(y + scale * 0.25   , x + scale * 0.625 );
    controlPoints[5]  = point(y + scale * 0.25   , x + scale * 1     );
    controlPoints[6]  = point(y                  , x + scale * 1     );
    controlPoints[7]  = point(y                  , x                 );
    controlPoints[8]  = point(y + scale * 0.25   , x                 );
    controlPoints[9]  = point(y + scale * 0.25   , x + scale * 0.375 );
    controlPoints[10] = point(y + scale * 0.75   , x + scale * 0.375 );
    controlPoints[11] = point(y + scale * 0.75   , x                 );

    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[11]);
    lines[11] = line(controlPoints[11], controlPoints[0]);
    
    return shape(lines,12,&c);
    
}

Shape drawJ(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(8 * sizeof(Point));
    Line* lines = (Line*) malloc(8 * sizeof(Line));

    controlPoints[0] = point(y + scale * 1      , x                 );
    controlPoints[1] = point(y + scale * 1      , x + scale * 1     );
    controlPoints[2] = point(y                  , x + scale * 1     );
    controlPoints[3] = point(y                  , x + scale * 0.75  );
    controlPoints[4] = point(y + scale * 0.75   , x + scale * 0.75  );
    controlPoints[5] = point(y + scale * 0.75   , x + scale * 0.25  );
    controlPoints[6] = point(y + scale * 0.5    , x + scale * 0.25  );
    controlPoints[7] = point(y + scale * 0.5    , x                 );

    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[0]);
    
    return shape(lines,8,&c);
    
}

Shape drawK(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(11 * sizeof(Point));
    Line* lines = (Line*) malloc(11 * sizeof(Line));

    
    controlPoints[0]  = point(y + scale * 1     , x                  );
    controlPoints[1]  = point(y + scale * 1     , x + scale * 0.25   );
    controlPoints[2]  = point(y + scale * 0.6   , x + scale * 0.25   );
    controlPoints[3]  = point(y + scale * 1     , x + scale * 0.75   );
    controlPoints[4]  = point(y + scale * 1     , x + scale * 1      );
    controlPoints[5]  = point(y + scale * 0.5   , x + scale * 0.5    );
    controlPoints[6]  = point(y                 , x + scale * 1      );
    controlPoints[7]  = point(y                 , x + scale * 0.75   );
    controlPoints[8]  = point(y + scale * 0.4   , x + scale * 0.25   );
    controlPoints[9]  = point(y                 , x + scale * 0.25   );
    controlPoints[10] = point(y                 , x                  );
    
    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[0]);

    return shape(lines, 11, &c);
}

Shape drawL(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(6 * sizeof(Point));
    Line* lines = (Line*) malloc(6 * sizeof(Line));

    
    controlPoints[0]  = point(y + scale * 1     , x                  );
    controlPoints[1]  = point(y + scale * 1     , x + scale * 1      );
    controlPoints[2]  = point(y + scale * 0.75  , x + scale * 1      );
    controlPoints[3]  = point(y + scale * 0.75  , x + scale * 0.25   );
    controlPoints[4]  = point(y                 , x + scale * 0.25   );
    controlPoints[5]  = point(y                 , x                  );
        
    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[0]);
    
    return shape(lines, 6, &c);
}

Shape drawM(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(13 * sizeof(Point));
    Line* lines = (Line*) malloc(13  * sizeof(Line));

    controlPoints[0]  = point(y + scale * 1      , x                 );
    controlPoints[1]  = point(y + scale * 1      , x + scale * 0.2   );
    controlPoints[2]  = point(y + scale * 0.4    , x + scale * 0.2   );
    controlPoints[3]  = point(y + scale * 1      , x + scale * 0.4   );
    controlPoints[4]  = point(y + scale * 1      , x + scale * 0.6   );
    controlPoints[5]  = point(y + scale * 0.4    , x + scale * 0.8   );
    controlPoints[6]  = point(y + scale * 1      , x + scale * 0.8   );
    controlPoints[7]  = point(y + scale * 1      , x + scale * 1     );
    controlPoints[8]  = point(y + scale * 0      , x + scale * 1     );
    controlPoints[9]  = point(y + scale * 0      , x + scale * 0.6   );
    controlPoints[10] = point(y + scale * 0.6    , x + scale * 0.5   );
    controlPoints[11] = point(y                  , x + scale * 0.4   );
    controlPoints[12] = point(y                  , x                 );

    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[11]);
    lines[11] = line(controlPoints[11], controlPoints[12]);
    lines[12] = line(controlPoints[12], controlPoints[0]);
    
    return shape(lines,13,&c);
    
}


Shape drawN(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(10 * sizeof(Point));
    Line* lines = (Line*) malloc(10 * sizeof(Line));

    controlPoints[0] = point(y + scale * 0 , x + scale * 0);
    controlPoints[1] = point(y + scale * 0 , x + scale * 0.2);
    controlPoints[2] = point(y + scale * 0.75 , x + scale * 0.8);
    controlPoints[3] = point(y + scale * 0 , x + scale * 0.8);
    controlPoints[4] = point(y + scale * 0 , x + scale * 1);
    controlPoints[5] = point(y + scale * 1 , x + scale * 1);
    controlPoints[6] = point(y + scale * 1 , x + scale * 0.8);
    controlPoints[7] = point(y + scale * 0.25 , x + scale * 0.2);
    controlPoints[8] = point(y + scale * 1 , x + scale * 0.2);
    controlPoints[9] = point(y + scale * 1 , x + scale * 0);


    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[0]);

    return shape(lines, 10, &c);

}
Shape drawO(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(16 * sizeof(Point));
    Line* lines = (Line*) malloc(16 * sizeof(Line));

    //Outer Area
    controlPoints[0] = point(y + scale * 0.1875 , x + scale * 0);
    controlPoints[1] = point(y + scale * 0 , x + scale * 0.1875);
    controlPoints[2] = point(y + scale * 0 , x + scale * 0.8125);
    controlPoints[3] = point(y + scale * 0.1875 , x + scale * 1);
    controlPoints[4] = point(y + scale * 0.8125 , x + scale * 1);
    controlPoints[5] = point(y + scale * 1 , x + scale * 0.8125);
    controlPoints[6] = point(y + scale * 1 , x + scale * 0.1875);
    controlPoints[7] = point(y + scale * 0.8125 , x + scale * 0);

    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[0]);

    //Inner Area
    controlPoints[8]  = point(y + scale * 0.3875 , x + scale * 0.2);
    controlPoints[9]  = point(y + scale * 0.2 , x + scale * 0.3875);
    controlPoints[10]  = point(y + scale * 0.2 , x + scale * 0.6125);
    controlPoints[11]  = point(y + scale * 0.3875 , x + scale * 0.8);
    controlPoints[12]  = point(y + scale * 0.6125 , x + scale * 0.8);
    controlPoints[13]  = point(y + scale * 0.8 , x + scale * 0.6125);
    controlPoints[14]  = point(y + scale * 0.8 , x + scale * 0.3875);
    controlPoints[15]  = point(y + scale * 0.6125 , x + scale * 0.2);


    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[11]);
    lines[11] = line(controlPoints[11], controlPoints[12]);
    lines[12] = line(controlPoints[12], controlPoints[13]);
    lines[13] = line(controlPoints[13], controlPoints[14]);
    lines[14] = line(controlPoints[14], controlPoints[15]);
    lines[15] = line(controlPoints[15], controlPoints[8]);

    return shape(lines, 16, &c);

}

Shape drawP(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(14 * sizeof(Point));
    Line* lines = (Line*) malloc(14 * sizeof(Line));

    //Outer Area
    controlPoints[0] = point(y + scale * 0 , x + scale * 0);
    controlPoints[1] = point(y + scale * 0 , x + scale * 0.8125);
    controlPoints[2] = point(y + scale * 0.1875 , x + scale * 1);
    controlPoints[3] = point(y + scale * 0.3125 , x + scale * 1);
    controlPoints[4] = point(y + scale * 0.5 , x + scale * 0.8125);
    controlPoints[5] = point(y + scale * 0.5 , x + scale * 0.3);
    controlPoints[6] = point(y + scale * 1 , x + scale * 0.3);
    controlPoints[7] = point(y + scale * 1 , x + scale * 0);

    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[0]);

    //Inner Area
    controlPoints[8]  = point(y + scale * 0.15 , x + scale * 0.3);
    controlPoints[9]  = point(y + scale * 0.15 , x + scale * 0.6125);
    controlPoints[10]  = point(y + scale * 0.175 , x + scale * 0.8);
    controlPoints[11]  = point(y + scale * 0.325 , x + scale * 0.8);
    controlPoints[12]  = point(y + scale * 0.35 , x + scale * 0.6125);
    controlPoints[13]  = point(y + scale * 0.35 , x + scale * 0.3);

    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[11]);
    lines[11] = line(controlPoints[11], controlPoints[12]);
    lines[12] = line(controlPoints[12], controlPoints[13]);
    lines[13] = line(controlPoints[13], controlPoints[8]);

    return shape(lines, 14, &c);

}

Shape drawR(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(17 * sizeof(Point));
    Line* lines = (Line*) malloc(17 * sizeof(Line));

    //Outer Area
    controlPoints[0] = point(y + scale * 0 , x + scale * 0);
    controlPoints[1] = point(y + scale * 0 , x + scale * 0.8125);
    controlPoints[2] = point(y + scale * 0.1875 , x + scale * 1);
    controlPoints[3] = point(y + scale * 0.3125 , x + scale * 1);
    controlPoints[4] = point(y + scale * 0.5 , x + scale * 0.8125);
    controlPoints[5] = point(y + scale * 0.5 , x + scale * 0.5);
    controlPoints[6] = point(y + scale * 0.8   , x + scale * 1);
    controlPoints[7] = point(y + scale * 1   , x + scale * 0.85);
    controlPoints[8] = point(y + scale * 0.5 , x + scale * 0.3);
    controlPoints[9] = point(y + scale * 1 , x + scale * 0.3);
    controlPoints[10] = point(y + scale * 1 , x + scale * 0);

    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[0]);


    //Inner Area
    controlPoints[11]  = point(y + scale * 0.15 , x + scale * 0.4);
    controlPoints[12]  = point(y + scale * 0.15 , x + scale * 0.6625);
    controlPoints[13]  = point(y + scale * 0.175 , x + scale * 0.85);
    controlPoints[14]  = point(y + scale * 0.325 , x + scale * 0.85);
    controlPoints[15]  = point(y + scale * 0.35 , x + scale * 0.6625);
    controlPoints[16]  = point(y + scale * 0.35 , x + scale * 0.4);

    lines[11] = line(controlPoints[11], controlPoints[12]);
    lines[12] = line(controlPoints[12], controlPoints[13]);
    lines[13] = line(controlPoints[13], controlPoints[14]);
    lines[14] = line(controlPoints[14], controlPoints[15]);
    lines[15] = line(controlPoints[15], controlPoints[16]);
    lines[16] = line(controlPoints[16], controlPoints[11]);

    return shape(lines, 17, &c);

}


Shape drawS(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(12 * sizeof(Point));
    Line* lines = (Line*) malloc(12 * sizeof(Line));

    controlPoints[0] = point(y , x);
    controlPoints[1] = point(y , x + scale * 1);
    controlPoints[2] = point(y + scale * 0.2 , x + scale * 1);
    controlPoints[3] = point(y + scale * 0.2 , x + scale * 0.2);
    controlPoints[4] = point(y + scale * 0.4 , x + scale * 0.2);
    controlPoints[5] = point(y + scale * 0.4 , x + scale * 1);
    controlPoints[6] = point(y + scale * 1 , x + scale * 1);
    controlPoints[7] = point(y + scale * 1 , x);
    controlPoints[8] = point(y + scale * 0.8 , x);
    controlPoints[9] = point(y + scale * 0.8 , x + scale * 0.8);
    controlPoints[10] = point(y + scale * 0.6 , x + scale * 0.8);
    controlPoints[11] = point(y + scale * 0.6 , x);


    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[11]);
    lines[11] = line(controlPoints[11], controlPoints[0]);

    return shape(lines, 12, &c);

}

Shape drawT(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(8 * sizeof(Point));
    Line* lines = (Line*) malloc(8 * sizeof(Line));

    controlPoints[0] = point(y , x);
    controlPoints[1] = point(y , x + scale * 1);
    controlPoints[2] = point(y + scale * 0.2 , x + scale * 1);
    controlPoints[3] = point(y + scale * 0.2 , x + scale * 0.65);
    controlPoints[4] = point(y + scale * 1 , x + scale * 0.65);
    controlPoints[5] = point(y + scale * 1 , x + scale * 0.35);
    controlPoints[6] = point(y + scale * 0.2 , x + scale * 0.35);
    controlPoints[7] = point(y + scale * 0.2 , x);


    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[0]);

    return shape(lines, 8, &c);

}

Shape drawU(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(8 * sizeof(Point));
    Line* lines = (Line*) malloc(8 * sizeof(Line));

    controlPoints[0] = point(y , x);
    controlPoints[1] = point(y + scale * 1, x);
    controlPoints[2] = point(y + scale * 1 , x + scale * 1);
    controlPoints[3] = point(y , x + scale * 1);
    controlPoints[4] = point(y , x + scale * 0.7);
    controlPoints[5] = point(y + scale * 0.7 , x + scale * 0.7);
    controlPoints[6] = point(y + scale * 0.7 , x + scale * 0.3);
    controlPoints[7] = point(y , x + scale * 0.3);


    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[0]);

    return shape(lines, 8, &c);

}

Shape drawV(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(7 * sizeof(Point));
    Line* lines = (Line*) malloc(7 * sizeof(Line));

    controlPoints[0] = point(y , x);
    controlPoints[1] = point(y + scale * 1 , x + scale * 0.35);
    controlPoints[2] = point(y + scale * 1 , x + scale * 0.65);
    controlPoints[3] = point(y , x + scale * 1);
    controlPoints[4] = point(y , x + scale * 0.7);
    controlPoints[5] = point(y + scale * 0.75 , x + scale * 0.5);
    controlPoints[6] = point(y , x + scale * 0.3);


    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[0]);

    return shape(lines, 7, &c);

}

Shape drawW(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(13 * sizeof(Point));
    Line* lines = (Line*) malloc(13 * sizeof(Line));

    controlPoints[0] = point(y , x);
    controlPoints[1] = point(y + scale * 1 , x + scale * 0.125);
    controlPoints[2] = point(y + scale * 1 , x + scale * 0.375);
    controlPoints[3] = point(y + scale * 0.25 , x + scale * 0.5);
    controlPoints[4] = point(y + scale * 1 , x + scale * 0.625);
    controlPoints[5] = point(y + scale * 1 , x + scale * 0.875);
    controlPoints[6] = point(y , x + scale * 1);
    controlPoints[7] = point(y , x + scale * 0.875);
    controlPoints[8] = point(y + scale * 0.75 , x + scale * 0.75);
    controlPoints[9] = point(y , x + scale * 0.6);
    controlPoints[10] = point(y , x + scale * 0.4);
    controlPoints[11] = point(y + scale * 0.75, x + scale * 0.25);
    controlPoints[12] = point(y , x + scale * 0.125);


    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[11]);
    lines[11] = line(controlPoints[11], controlPoints[12]);
    lines[12] = line(controlPoints[12], controlPoints[0]);

    return shape(lines, 13, &c);

}

Shape drawX(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(12 * sizeof(Point));
    Line* lines = (Line*) malloc(12 * sizeof(Line));

    controlPoints[0] = point(y , x);
    controlPoints[1] = point(y , x + scale * 0.3);
    controlPoints[2] = point(y + scale * 0.4 , x + scale * 0.5);
    controlPoints[3] = point(y , x + scale * 0.7);
    controlPoints[4] = point(y , x + scale * 1);
    controlPoints[5] = point(y + scale * 0.5 , x + scale * 0.6);
    controlPoints[6] = point(y + scale * 1   , x + scale * 1);
    controlPoints[7] = point(y + scale * 1   , x + scale * 0.7);
    controlPoints[8] = point(y + scale * 0.6 , x + scale * 0.5);
    controlPoints[9] = point(y + scale * 1 , x + scale * 0.3);
    controlPoints[10] = point(y + scale * 1 , x);
    controlPoints[11] = point(y + scale * 0.5 , x + scale * 0.4);


    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[10]);
    lines[10] = line(controlPoints[10], controlPoints[11]);
    lines[11] = line(controlPoints[11], controlPoints[0]);

    return shape(lines, 12, &c);

}

Shape drawY(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(9 * sizeof(Point));
    Line* lines = (Line*) malloc(9 * sizeof(Line));

    controlPoints[0] = point(y , x);
    controlPoints[1] = point(y + scale * 0.55 , x + scale * 0.35);
    controlPoints[2] = point(y + scale * 1 , x + scale * 0.35);
    controlPoints[3] = point(y + scale * 1 , x + scale * 0.65);
    controlPoints[4] = point(y + scale * 0.55 , x + scale * 0.65);
    controlPoints[5] = point(y , x + scale * 1);
    controlPoints[6] = point(y , x + scale * 0.7);
    controlPoints[7] = point(y + scale * 0.45 , x + scale * 0.5);
    controlPoints[8] = point(y , x + scale * 0.3);

    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[0]);
    
    return shape(lines, 9, &c);
}

Shape drawZ(int x, int y, Color c) {
    Point* controlPoints = (Point*) malloc(10 * sizeof(Point));
    Line* lines = (Line*) malloc(10 * sizeof(Line));

    controlPoints[0] = point(y , x);
    controlPoints[1] = point(y , x + scale * 1);
    controlPoints[2] = point(y + scale * 0.25 , x + scale * 1);
    controlPoints[3] = point(y + scale * 0.75 , x + scale * 0.25);
    controlPoints[4] = point(y + scale * 0.75 , x + scale * 1);
    controlPoints[5] = point(y + scale * 1 , x + scale * 1);
    controlPoints[6] = point(y + scale * 1 , x);
    controlPoints[7] = point(y + scale * 0.75 , x);
    controlPoints[8] = point(y + scale * 0.25 , x + scale * 0.75);
    controlPoints[9] = point(y + scale * 0.25 , x);


    lines[0] = line(controlPoints[0], controlPoints[1]);
    lines[1] = line(controlPoints[1], controlPoints[2]);
    lines[2] = line(controlPoints[2], controlPoints[3]);
    lines[3] = line(controlPoints[3], controlPoints[4]);
    lines[4] = line(controlPoints[4], controlPoints[5]);
    lines[5] = line(controlPoints[5], controlPoints[6]);
    lines[6] = line(controlPoints[6], controlPoints[7]);
    lines[7] = line(controlPoints[7], controlPoints[8]);
    lines[8] = line(controlPoints[8], controlPoints[9]);
    lines[9] = line(controlPoints[9], controlPoints[0]);

    return shape(lines, 10, &c);
}
