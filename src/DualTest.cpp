#include <cppunit/extensions/HelperMacros.h>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include "DualTest.h"
#include "Dual.h"
#include "Accessor.h"


namespace dual {
    //class DualMember1 {
    //public:
    //    typedef T dual::Dual::* type;
    //};
    //
    //class DualMember2 {
    //public:
    //    typedef T dual::Dual::* type;
    //};
    //
    //template class Initializer<DualMember1, &dual::Dual::_a>;
    //template class Initializer<DualMember2, &dual::Dual::_b>;
    CPPUNIT_TEST_SUITE_REGISTRATION(DualTest);
    void DualTest::setUp()
    {
        return;
    }

    void DualTest::testConstructor()
    {
        boost::shared_ptr<Dual<double> > d(new Dual<double>);
    //    template <typename T>
    //    CPPUNIT_ASSERT(d.*Accessor<DualMember1>::value == 0.0);
    //    CPPUNIT_ASSERT(d.*Accessor<DualMember2>::value == 0.0);

    //    boost::shared_ptr<Dual<double> > d2(new Dual<double>(1.0, 1.0));
    //    CPPUNIT_ASSERT(d2->_a == 1.0);
    //    CPPUNIT_ASSERT(d2->_b == 1.0);

        return;
    }

    void DualTest::testOperatorPlus()
    {
        //for double
        Dual<double> d1(1.0, 2.0);
        Dual<double> d2(3.0, 4.0);

        //const Dual<double> d3 = d1 + d2;
        //CPPUNIT_ASSERT(d3._a == 4.0);
        //CPPUNIT_ASSERT(d3._b == 6.0);

        //for integer
    //    Dual<double> d4(1, 2);
    //    Dual<double> d5(3, 4);

    //    const Dual<double> d6 = d4 + d5;
    //    CPPUNIT_ASSERT(d6._a == 4);
    //    CPPUNIT_ASSERT(d6._b == 6);

        return;
    }

    void DualTest::tearDown()
    {
         return;
    }

} // namespace dual

