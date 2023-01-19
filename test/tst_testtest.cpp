#include <QString>
#include <QtTest>
#include "..\objects\objects.h"

class TestTest : public QObject
{
    Q_OBJECT

public:
    TestTest();

private Q_SLOTS:
    void testCase2();
    void testCase1();
    void testCase3();
};

TestTest::TestTest()
{
}

void TestTest::testCase1()
{
    sedan Sedan;

    QVERIFY(!Sedan.drive(100));
    QCOMPARE(Sedan.getFuelLevel(), 0.0);
    Sedan.refuel();
    QCOMPARE(Sedan.getFuelLevel(), 50.0);
    QVERIFY(Sedan.drive(100));
    QCOMPARE(Sedan.getMilage(), 100.0);
    QCOMPARE(Sedan.getFuelLevel(), 45.0);
    QVERIFY(!Sedan.drive(1000));
    QCOMPARE(Sedan.getMilage(), 100.0);
    QCOMPARE(Sedan.getFuelLevel(), 45.0);
    Sedan.refuel();
    QCOMPARE(Sedan.getFuelLevel(), 50.0);
    QVERIFY(Sedan.drive(900));
    QCOMPARE(Sedan.getMilage(), 1000.0);
    QCOMPARE(Sedan.getFuelLevel(), 5.0);
}

void TestTest::testCase2()
{
    bicycle Bicucle;

    QVERIFY(Bicucle.drive(100));
    QCOMPARE(Bicucle.getMilage(), 100.0);
    QVERIFY(Bicucle.drive(200));
    QVERIFY(Bicucle.drive(300));
    QCOMPARE(Bicucle.getMilage(), 600.0);
}

void TestTest::testCase3()
{
    Route route;
    bus Bus;
    Bus.refuel();

    route.run(&Bus);
    QCOMPARE(Bus.getMilage(), 0.0);
    route.addPoint(0, 0, "point1");
    route.addPoint(35, 0, "point2");
    route.addPoint(35, 15, "point3");
    route.run(&Bus);
    QCOMPARE(Bus.getMilage(), 50.0);


}

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
