/****************************************************************************************************
 *  @file src/Prac4_unittest.cpp
 *  @brief The source file for the test cases
 ***************************************************************************************************/

#include <gtest/gtest.h>
#include <stdexcept>

#include "../inc/BTS.h"
#include "../inc/RadioEngineer.h"
/****************************************************************************************************
 *  @brief The test cases for the NetworkElement class
 *  
 *  @see NetworkElement.h
 ***************************************************************************************************/
TEST(NetworkElementTest, attach_null) {
    NetworkElement* ne = new NetworkElement();
    RadioEngineer* e = NULL;

    try {
        ne->attach(e);
        FAIL();
    } catch (std::logic_error &err) {
        EXPECT_EQ(err.what() , std::string("e must not be null."));
    } catch (...) {
        FAIL();
    }

    delete ne;
    delete e;
}

TEST(NetworkElementTest, attach_same) {
    NetworkElement* ne = new NetworkElement();
    Engineer* e = new RadioEngineer();
    ne->attach(e);

    try {
        ne->attach(e);
        FAIL();
    } catch (std::logic_error &err) {
        EXPECT_EQ(err.what() , std::string("e must not already be part of the collection."));
    } catch (...) {
        FAIL();
    }

    delete ne;
    delete e;
}

TEST(NetworkElementTest, attach_trivial) {
    NetworkElement* ne = new NetworkElement();
    Engineer* e = new RadioEngineer();
    
    EXPECT_NO_THROW(ne->attach(e));

    delete ne;
    delete e;
}

TEST(NetworkElementTest, detach_not_null) {
    NetworkElement* ne = new NetworkElement();
    Engineer* e = new RadioEngineer();
    
    ne->attach(e);
    Engineer* re = NULL;
    
    try {
        ne->detach(re);
        FAIL();
    } catch (std::logic_error &err) {
        EXPECT_EQ(err.what() , std::string("e must not be null."));
    } catch (...) {
        FAIL();
    }

    ne->detach(e);

    delete ne;
    delete re;
    delete e;
}

TEST(NetworkElementTest, detach_not_empty) {
    NetworkElement* ne = new NetworkElement();
    Engineer* e = new RadioEngineer();
    
    try {
        ne->detach(e);
        FAIL();
    } catch (std::logic_error &err) {
        EXPECT_EQ(err.what() , std::string("The collection is already empty."));
    } catch (...) {
        FAIL();
    }

    delete ne;
    delete e;
}

TEST(NetworkElementTest, detach_part_of) {
    NetworkElement* ne = new NetworkElement();
    Engineer* e = new RadioEngineer();
    Engineer* re = new RadioEngineer();
    
    ne->attach(e);
    
    try {
        ne->detach(re);
        FAIL();
    } catch (std::logic_error &err) {
        EXPECT_EQ(err.what() , std::string("e must be a part of the collection."));
    } catch (...) {
        FAIL();
    }

    delete ne;
    delete re;
    delete e;
}

TEST(NetworkElementTest, detach_trivial) {
    NetworkElement* ne = new NetworkElement();
    Engineer* e = new RadioEngineer();
    
    ne->attach(e);
    EXPECT_NO_THROW(ne->detach(e));

    delete ne;
    delete e;
}
/***************************************************************************************************/

/****************************************************************************************************
 *  @brief The test cases for the BTS class
 *  
 *  @see BTS.h
 ***************************************************************************************************/
TEST(BTSTest, state_not_in_set) {
    BTS* b = new BTS("BTS01");

    try {
        b->setAlarm("Not in set.");
        FAIL();
    } catch (std::invalid_argument &err) {
        EXPECT_EQ(err.what() , std::string("s must be in the set {\"critical\", \"major\", \"minor\", \"clear\"}."));
    } catch (...) {
        FAIL();
    }
    
    delete b;
}

TEST(BTSTest, trivial) {
    BTS* b = new BTS("BTS01");
    EXPECT_NO_THROW(b->setAlarm("critical"));

    EXPECT_EQ(b->getAlarm(), std::string("critical"));
    
    delete b;
}
/***************************************************************************************************/

/****************************************************************************************************
 *  @fn int main(int argc, char **argv)
 *  @brief The main function for the test cases.
 *  
 *  @param[in]  argc    The amount of CLI inputs.
 *  @param[in]  argv    A pointer to a pointer of chars containing the indexed CLI inputs.
 ***************************************************************************************************/
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}