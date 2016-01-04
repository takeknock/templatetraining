#include <cppunit/extensions/HelperMacros.h>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include "DualTest.h"
#include "Dual.h"


namespace dual {
    CPPUNIT_TEST_SUITE_REGISTRATION(DualTest);
    void DualTest::setUp()
    {
        return;
    }

    void DualTest::testConstructor()
    {
        boost::shared_ptr<Dual<double> > d(new Dual<double>);
        CPPUNIT_ASSERT(d->_a == 0.0);
        CPPUNIT_ASSERT(d->_b == 0.0);

        boost::shared_ptr<Dual<double> > d2(new Dual<double>(1.0, 1.0));
        CPPUNIT_ASSERT(d2->_a == 1.0);
        CPPUNIT_ASSERT(d2->_b == 1.0);

        return;
    }

    void DualTest::testOperatorPlus()
    {
        //boost::shared_ptr<Dual<double> > d1(new Dual<double>(1.0, 2.0));
        //boost::shared_ptr<Dual<double> > d2(new Dual<double>(3.0, 4.0));
        Dual<double> d1(1.0, 2.0);
        Dual<double> d2(3.0, 4.0);

        Dual<double> d3 = d1 + d2;
        CPPUNIT_ASSERT(d3._a == 4.0);
        CPPUNIT_ASSERT(d3._b == 6.0);
        return;
    }

    void DualTest::tearDown()
    {
         return;
    }

} // namespace dual

