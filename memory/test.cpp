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