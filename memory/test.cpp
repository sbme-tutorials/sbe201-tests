#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "myheader.hpp"
#include <set>

TEST_CASE( "Roots are computed by root_p function", "[roots]" ) {
    std::set<double> roots;
    double x1,x2;
    root_p(1, -5, 6, &x1, &x2);
    roots = {x1,x2};
    REQUIRE( roots.count( 2 ) == 1 );
    REQUIRE( roots.count( 3 ) == 1 );

    root_p(1, -5, 4, &x1, &x2);
    roots = {x1,x2};
    REQUIRE( roots.count( 1 ) == 1 );
    REQUIRE( roots.count( 4 ) == 1 );

    root_p(1, -3, -28, &x1, &x2);
    roots = {x1,x2};
    REQUIRE( roots.count( -4 ) == 1);
    REQUIRE( roots.count( 7 ) == 1 );

    root_p(1, 3, 0, &x1, &x2);
    roots = {x1,x2};
    REQUIRE( roots.count( 0 ) == 1);
    REQUIRE( roots.count( -3 ) == 1 );
}

TEST_CASE( "Roots are computed by root_r function", "[roots]" ) {
    std::set<double> roots;
    double x1,x2;
    root_r(1, -5, 6, x1, x2);
    roots = {x1,x2};
    REQUIRE( roots.count( 2 ) == 1 );
    REQUIRE( roots.count( 3 ) == 1 );

    root_r(1, -5, 4, x1, x2);
    roots = {x1,x2};
    REQUIRE( roots.count( 1 ) == 1 );
    REQUIRE( roots.count( 4 ) == 1 );

    root_r(1, -3, -28, x1, x2);
    roots = {x1,x2};
    REQUIRE( roots.count( -4 ) == 1);
    REQUIRE( roots.count( 7 ) == 1 );

    root_r(1, 3, 0, x1, x2);
    roots = {x1,x2};
    REQUIRE( roots.count( 0 ) == 1);
    REQUIRE( roots.count( -3 ) == 1 );
}

TEST_CASE( "Roots are computed by root function", "[roots]" ) {
    std::set<double> roots;
    double x1,x2;
    auto r = root(1, -5, 6);
    roots = {r.r1,r.r2};
    REQUIRE( roots.count( 2 ) == 1 );
    REQUIRE( roots.count( 3 ) == 1 );

    r = root(1, -5, 4);
    roots = {r.r1,r.r2};
    REQUIRE( roots.count( 1 ) == 1 );
    REQUIRE( roots.count( 4 ) == 1 );

    r = root(1, -3, -28);
    roots = {r.r1,r.r2};
    REQUIRE( roots.count( -4 ) == 1);
    REQUIRE( roots.count( 7 ) == 1 );

    r = root(1, 3, 0);
    roots = {r.r1,r.r2};
    REQUIRE( roots.count( 0 ) == 1);
    REQUIRE( roots.count( -3 ) == 1 );
}

TEST_CASE( "sum1", "[sum]" ) {

    REQUIRE( sum1( 3 , 6.6 ) == 3 + 6.6 );
    REQUIRE( sum1( 90 , -1200/7.0 ) == 90 - 1200/7.0 );
    REQUIRE( sum1( -30 , -12 ) == -30 + -12 );
    REQUIRE( sum1( -5 , 100/7.0 ) == -5 + 100/7.0  );
    REQUIRE( sum1( 0.4 , -100/6.0 ) == 0.4 + -100/6.0 );
    REQUIRE( sum1( 0.22 , -10/3.0 ) == 0.22 + -10/3.0  );
    REQUIRE( sum1( -9.44, 9/4.0 ) == -9.44+ 9/4.0  );
    REQUIRE( sum1( 0 , 5 ) == 0 + 5 );
}

TEST_CASE( "sum2", "[sum]" ) {

    REQUIRE( *sum2( 3 , 6.6 ) == 3 + 6.6 );
    REQUIRE( *sum2( 90 , -1200/7.0 ) == 90 - 1200/7.0 );
    REQUIRE( *sum2( -30 , -12 ) == -30 + -12 );
    REQUIRE( *sum2( -5 , 100/7.0 ) == -5 + 100/7.0  );
    REQUIRE( *sum2( 0.4 , -100/6.0 ) == 0.4 + -100/6.0 );
    REQUIRE( *sum2( 0.22 , -10/3.0 ) == 0.22 + -10/3.0  );
    REQUIRE( *sum2( -9.44, 9/4.0 ) == -9.44+ 9/4.0  );
    REQUIRE( *sum2( 0 , 5 ) == 0 + 5 );
}

TEST_CASE( "sum3", "[sum]" ) {
    double x1,x2;
    x1 = 3 ; x2 = 6.6;
    REQUIRE( *sum3( &x1, &x2 ) == 3 + 6.6 );
    x1 = 90 ; x2 =  -1200/7.0;
    REQUIRE( *sum3( &x1, &x2 ) == 90 - 1200/7.0 );
    x1 = -30 ; x2 =  -12;
    REQUIRE( *sum3( &x1, &x2 ) == -30 + -12 );
    x1 = -5 ; x2 =  100/7.0 ;
    REQUIRE( *sum3( &x1, &x2 ) == -5 + 100/7.0  );
    x1 =  0.4 ; x2 =  -100/6.0;
    REQUIRE( *sum3( &x1, &x2 ) == 0.4 + -100/6.0 );
    x1 =  0.22 ; x2 =  -10/3.0;
    REQUIRE( *sum3( &x1, &x2 ) == 0.22 + -10/3.0  );
    x1 = -9.44 ; x2 =  9/4.0 ;
    REQUIRE( *sum3( &x1, &x2 ) == -9.44+ 9/4.0  );
    x1 = 0 ; x2 =  5;
    REQUIRE( *sum3( &x1, &x2 ) == 0 + 5 );
}

TEST_CASE( "abs", "[abs]" ) {
    REQUIRE( absolute( -5.4 ) == 5.4 );
    REQUIRE( absolute( 50 ) == 50 );
}

TEST_CASE( "abs diff", "[abs]" ) {
    REQUIRE( absolute_difference1( -5.4 , 4 ) == 4 + 5.4 );
    REQUIRE( absolute_difference1( -10 , 33 ) == 33 + 10 );
    REQUIRE( absolute_difference1( -10 , -33 ) == 33 - 10 );
    REQUIRE( absolute_difference1( 109 , 101/3.0 ) == 109 - 101/3.0 );
}

TEST_CASE( "abs diff 2", "[abs]" ) {
    double x1,x2;
    x1 = -5.4 ; x2 = 4;
    REQUIRE( absolute_difference2( &x1, &x2 ) == 4 + 5.4 );
    x1 = -10 ; x2 = 33 ;
    REQUIRE( absolute_difference2( &x1, &x2) == 33 + 10 );
    x1 = -10 ; x2 = -33;
    REQUIRE( absolute_difference2( &x1, &x2 ) == 33 - 10 );
    x1 = 109 ; x2 = 101/3.0;
    REQUIRE( absolute_difference2( &x1, &x2 ) == 109 - 101/3.0 );
}

TEST_CASE( "abs diff 3", "[abs]" ) {
    double x1,x2;
    x1 = -5.4 ; x2 = 4;
    REQUIRE( absolute_difference3( x1, x2 ) == 4 + 5.4 );
    x1 = -10 ; x2 = 33 ;
    REQUIRE( absolute_difference3( x1, x2) == 33 + 10 );
    x1 = -10 ; x2 = -33;
    REQUIRE( absolute_difference3( x1, x2 ) == 33 - 10 );
    x1 = 109 ; x2 = 101/3.0;
    REQUIRE( absolute_difference3( x1, x2 ) == 109 - 101/3.0 );
}

TEST_CASE( "sum abs diff 1", "[sumabs]" ) {
    double x1,x2,d,s;
    x1 = -5.4 ; x2 = 4;
    sum_and_absolute_difference1( x1, x2 , &d, &s);
    REQUIRE(  (d== 4 + 5.4 && s == x1 + x2 ));
    x1 = -10 ; x2 = 33 ;
    sum_and_absolute_difference1( x1, x2, &d, &s) 
    REQUIRE( (d== 33 + 10 && s == x1 + x2) );
    x1 = -10 ; x2 = -33;
    sum_and_absolute_difference1( x1, x2, &d, &s )
    REQUIRE(  (d== 33 - 10 && s == x1 + x2));
    x1 = 109 ; x2 = 101/3.0;
    sum_and_absolute_difference1( x1, x2, &d, &s )
    REQUIRE(  (d== 109 - 101/3.0 && s == x1 + x2) );
}

TEST_CASE( "sum abs diff 2", "[sumabs]" ) {
    double x1,x2,d,s;
    x1 = -5.4 ; x2 = 4;
    sum_and_absolute_difference2( x1, x2 , d, s);
    REQUIRE(  (d== 4 + 5.4 && s == x1 + x2 ));
    x1 = -10 ; x2 = 33 ;
    sum_and_absolute_difference2( x1, x2 , d, s);
    REQUIRE( (d== 33 + 10 && s == x1 + x2) );
    x1 = -10 ; x2 = -33;
    sum_and_absolute_difference2( x1, x2 , d, s);
    REQUIRE(  (d== 33 - 10 && s == x1 + x2));
    x1 = 109 ; x2 = 101/3.0;
    sum_and_absolute_difference2( x1, x2 , d, s);
    REQUIRE(  (d== 109 - 101/3.0 && s == x1 + x2) );
}


TEST_CASE( "swap1", "[swap]" ) {
    double x1,x2;
    x1 = -5.4 ; x2 = 4;
    swap1( &x1, &x2 );
    REQUIRE(  (x1 == 4 && x2 == -5.4));

    x1 = -10 ; x2 = 33 ;
    swap1( &x1, &x2 );
    REQUIRE(  (x1 == 33 && x2 == -10));

    x1 = -10 ; x2 = -33;
    swap1( &x1, &x2 );
    REQUIRE(  (x1 ==  -33 && x2 == -10));

    x1 = 109 ; x2 = 101/3.0;
    swap1( &x1, &x2 );
    REQUIRE(  (x1 == 101/3.0 && x2 == 109));
}

TEST_CASE( "swap2", "[swap]" ) {
    double x1,x2;
    x1 = -5.4 ; x2 = 4;
    swap2( x1, x2 );
    REQUIRE(  (x1 == 4 && x2 == -5.4));

    x1 = -10 ; x2 = 33 ;
    swap2( x1, x2 );
    REQUIRE(  (x1 == 33 && x2 == -10));

    x1 = -10 ; x2 = -33;
    swap2( x1, x2 );
    REQUIRE(  (x1 ==  -33 && x2 == -10));

    x1 = 109 ; x2 = 101/3.0;
    swap2( x1, x2 );
    REQUIRE(  (x1 == 101/3.0 && x2 == 109));
}