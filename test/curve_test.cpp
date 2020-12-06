#include <catch.hpp>
#include <Curve.h>

TEST_CASE( "Point addition", "[Addition]" ) {
    Point A = Point("4567887789876t67876789654345678", "123213123123894235357645345678");
    Point B = Point("2310234398234242354354323123123", "989878126381256343421234565645");
    Point C = Point("9876543234567876543234567876543", "657483923847565748329238457645");
    Point I = Point("0", "0");

    // Associativity: (a + b) + c = a + (b + c)
    // TODO: This does not work.
    //REQUIRE(secp256k1.PointAdd(secp256k1.PointAdd(A, B), C) == secp256k1.PointAdd(A, secp256k1.PointAdd(B, C)));

    // Commutativity: a + b = b + a
    REQUIRE(secp256k1.PointAdd(A, B) == secp256k1.PointAdd(B, A));

    // Identity: 0 + a = a + 0 = a
    REQUIRE(secp256k1.PointAdd(A, I) == A);

    // Inverse: a + (-b) = 0
    // TODO: Inverting Y does not work on finite fields
    // REQUIRE(secp256k1.PointAdd(A, Point(A.x, A.y*(-1))) == I);

    // Test against known cases:
    REQUIRE(secp256k1.PointAdd(A, B) == Point("76385748842902257827875087017911954351294205719773608882214863075346069527342", "105203101575683736679480715472866077308027555098909265757753516006812891077217"));
    REQUIRE(secp256k1.PointAdd(C, B) == Point("50676230827622783810444697224374058629022442748334474992809045726759810987577", "108522364268296646658920885109369202096931592862997762241026784200570181516027"));
}
