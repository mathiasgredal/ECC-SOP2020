#include <sstream>
#include <catch.hpp>
#include <BigNum.h>

TEST_CASE( "Subtraction of BigNums", "[Subtraction]" ) {
    REQUIRE( BigNum("1234") - BigNum("1234") == 0ll );
    REQUIRE( BigNum(1234ll) - BigNum("123456789876543234567654345678876543212345678765434567876543456765445765456") == "-123456789876543234567654345678876543212345678765434567876543456765445764222" );
    REQUIRE( BigNum("5") - BigNum(10.f) == -5ll );
}

TEST_CASE( "Addition of BigNums", "[Addition]" ) {
    REQUIRE( BigNum("1234") + BigNum("1234") == 2468ll );
    REQUIRE( BigNum(1234ll) + BigNum("123456789876543234567654345678876543212345678765434567876543456765445765456") == "123456789876543234567654345678876543212345678765434567876543456765445766690" );
    REQUIRE( BigNum("5") + BigNum(-10.f) == -5ll );
}

TEST_CASE( "Multiplication of BigNums", "[Multiplication]" ) {
    REQUIRE( BigNum("1234") * BigNum("1234") == 1522756ll );
    REQUIRE( BigNum(-1234ll) * BigNum("123456789876543234567654345678876543212345678765434567876543456765445765456") == "-152345678707654351456485462567733654324034567596546256759654625648560074572704" );
    REQUIRE( BigNum("-5") * BigNum(-10.f) == 50ll );
}

TEST_CASE( "Division of BigNums", "[Division]" ) {
    REQUIRE( BigNum("1234") / BigNum("1234") == 1ll );
    REQUIRE( BigNum("285450510512733933782") / BigNum("-1234") == "-231321321323123123" );
    REQUIRE( BigNum("-10") / BigNum(-5.f) == 2ll );
}

TEST_CASE( "Modulo of BigNums", "[Modulo]" ) {
    REQUIRE( BigNum("78765456787653283128371231237183712379123791327") % BigNum("123") == 21ll );
    REQUIRE( BigNum("-78765456787653283128371231237183712379123791327") % BigNum("123") == 102ll );
    REQUIRE( BigNum("-285450510512733933782") % BigNum("-1234") == "0" );
    REQUIRE( BigNum("-5") % BigNum(10.f) == 5ll );
}

TEST_CASE( "Comparison of BigNums", "[Comparison]" ) {
    REQUIRE( BigNum("72133123213213235456787653283128371231237183712379123791327") == BigNum("72133123213213235456787653283128371231237183712379123791327") );
    REQUIRE( BigNum("-72133123213213235456787653283128371231237183712379123791327") < BigNum("-3123"));
    REQUIRE( BigNum("72133123213213235456787653283128371231237183712379123791327") > BigNum("3123"));
    REQUIRE( BigNum("3123") >= BigNum("3123"));
    REQUIRE( BigNum("3123") <= BigNum("3123"));
    REQUIRE( BigNum("3123") != BigNum("3122"));
}

TEST_CASE( "BigNum to string", "[To String]" ) {
    REQUIRE( BigNum("72133123213213235456787653283128371231237183712379123791327").toString() == "72133123213213235456787653283128371231237183712379123791327" );
    REQUIRE( BigNum("-23").toString() == "-23");
}

TEST_CASE( "BigNum stringstream overload", "[stringstream]" ) {
    std::stringstream out;
    out << BigNum("1234565431234");
    REQUIRE( out.str() == "1234565431234" );

    out << " " << BigNum("123") << " hello";
    REQUIRE( out.str() == "1234565431234 123 hello" );
}

TEST_CASE( "BigNum modular power", "[powm]" ) {
    REQUIRE( powm("3213", "32", "312323") == "291721");
    REQUIRE( powm("3213", "-32", "312323") == "22573");
}

TEST_CASE( "BigNum inverse mod", "[invmod]" ) {
    REQUIRE( invmod("43", "567") == "211");
    REQUIRE( invmod("43323", "3212357") == "25878");
    REQUIRE( invmod("-43323", "3212357") == "3186479");
}

TEST_CASE( "BigNum modular sqrt", "[modsqrt]" ) {
    // Legendre symbol is also covered here, so we should have 100% coverage of bignum
    REQUIRE( ModularSqrt("30", "37") == "17");
    REQUIRE( ModularSqrt("198", "373") == "320");

    // Handle cases where we are using a number that isnt a quadratic residue of the modulo
    REQUIRE( ModularSqrt("199", "375") == "0");
    REQUIRE( ModularSqrt("-199", "375") == "0");
}

TEST_CASE( "BigNum random", "[random]" ) {
    // This just checks that we are actually creating a different number each time it is called
    REQUIRE( random(12332) != random(12332));
    REQUIRE( random(1252) != random(1234));
}
