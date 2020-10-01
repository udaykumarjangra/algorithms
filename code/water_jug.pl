water_jug(X,Y):- X>4, Y<3, write('4L Water Jug Overflowed'),nl.
water_jug(X,Y):- X<4, Y>3, write('3L Water Jug Overflowed'),nl.
water_jug(X,Y):- X>4, Y>3, write('Both Water Jugs Overflowed'),nl.
water_jug(X,Y):- (X=:=0, Y=:=0, nl, write('Fill 3L Jug \n 4L: 0 & 3L: 3\n'), Y_NEW is 3, water_jug(X,Y_NEW));
                 (X=:=0, Y=:=0, nl, write('Fill 4L Jug \n 4L: 4 & 3L: 0\n'), X_NEW is 3, water_jug(X_NEW,Y));
                 (X=:=2, Y=:=0, nl, write('\n Goal State Reached Jug \n 4L: 2 & 3L: 0'));
                 (X=:=4, Y=:=0, nl, write('Water from 4L to 3L Jug \n 4L: 1 & 3L: 3\n '), X_NEW is X-3, Y_NEW is 3, water_jug(X_NEW,Y_NEW));
                 (X=:=0, Y=:=3, nl, write('Water from 3L to 4L Jug \n 4L: 3 & 3L: 0\n '), X_NEW is 3, Y_NEW is 0, water_jug(X_NEW,Y_NEW));
                 (X=:=1, Y=:=3, nl, write('Empty 3L Jug \n 4L: 1 & 3L: 0\n '), Y_NEW is 0, water_jug(X,Y_NEW));
                 (X=:=3, Y=:=0, nl, write('Fill 3L Jug \n 4L: 3 & 3L: 3\n '), Y_NEW is 3, water_jug(X,Y_NEW));
                 (X=:=3, Y=:=3, nl, write('Water from \n 3L to 4L Jug 4L: 4 & 3L: 2\n '), X_NEW is 4, Y_NEW is 2, water_jug(X_NEW,Y_NEW));
                 (X=:=1, Y=:=0, nl, write('Water from 4L to 3L Jug \n 4L: 0 & 3L: 1\n '), X_NEW is Y, Y_NEW is X, water_jug(X_NEW,Y_NEW));
                 (X=:=0, Y=:=1, nl, write('Fill 4L Jug \n 4L: 4 & 3L: 1\n '), X_NEW is 4, water_jug(X_NEW,Y));
                 (X=:=4, Y=:=1, nl, write('Water from 4L to 3L Jug \n 4L: 2 & 3L: 3\n '), X_NEW is 2, Y_NEW is 3, water_jug(X_NEW,Y_NEW));
                 (X=:=2, Y=:=3, nl, write('Empty 3L Jug \n 4L: 2 & 3L: 0\n '), Y_NEW is 0, water_jug(X,Y_NEW));
                 (X=:=4, Y=:=2, nl, write('Empty 4L Jug \n 4L: 0 & 3L: 2\n '), X_NEW is 0, water_jug(X_NEW,Y));
                 (X=:=0, Y=:=2, nl, write('Water from 3L to 4L \n Jug 4L: 2 & 3L: 0\n '), X_NEW is Y, Y_NEW is X, water_jug(X_NEW,Y_NEW)).

