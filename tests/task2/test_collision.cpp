#include <gtest/gtest.h>

#include "engine.h"

class CollisionTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Non-colliding oc::Triangles
        nonColliding1 = oc::Triangle({oc::vec2{0,0}, oc::vec2{1,0}, oc::vec2{0,1}});
        nonColliding2 = oc::Triangle({oc::vec2{2,0}, oc::vec2{3,0}, oc::vec2{2,1}});
        
        // Touching at a point
        touchingPoint1 = oc::Triangle({oc::vec2{0,0}, oc::vec2{1,0}, oc::vec2{0,1}});
        touchingPoint2 = oc::Triangle({oc::vec2{1,0}, oc::vec2{2,0}, oc::vec2{1,1}});
        
        // Edge intersection
        edgeIntersect1 = oc::Triangle({oc::vec2{0,0}, oc::vec2{2,0}, oc::vec2{0,2}});
        edgeIntersect2 = oc::Triangle({oc::vec2{0,1}, oc::vec2{2,1}, oc::vec2{0,-1}});
        
        // Fully contained
        containedOuter = oc::Triangle({oc::vec2{0,0}, oc::vec2{3,0}, oc::vec2{0,3}});
        containedInner = oc::Triangle({oc::vec2{1,1}, oc::vec2{2,1}, oc::vec2{1,2}});
        
        // Shared edge
        sharedEdge1 = oc::Triangle({oc::vec2{0,0}, oc::vec2{1,0}, oc::vec2{0,1}});
        sharedEdge2 = oc::Triangle({oc::vec2{0,0}, oc::vec2{0,1}, oc::vec2{-1,0}});
    }

    oc::Triangle nonColliding1, nonColliding2;
    oc::Triangle touchingPoint1, touchingPoint2;
    oc::Triangle edgeIntersect1, edgeIntersect2;
    oc::Triangle containedOuter, containedInner;
    oc::Triangle sharedEdge1, sharedEdge2;

    oc::Engine engine;
};

TEST_F(CollisionTest, NonCollidingTriangles) {
    EXPECT_FALSE(engine.isColliding(nonColliding1, nonColliding2));
    EXPECT_FALSE(engine.isColliding(nonColliding2, nonColliding1));
}

TEST_F(CollisionTest, TouchingAtPoint) {
    EXPECT_TRUE(engine.isColliding(touchingPoint1, touchingPoint2));
    EXPECT_TRUE(engine.isColliding(touchingPoint2, touchingPoint1));
}

TEST_F(CollisionTest, EdgeIntersection) {
    EXPECT_TRUE(engine.isColliding(edgeIntersect1, edgeIntersect2));
    EXPECT_TRUE(engine.isColliding(edgeIntersect2, edgeIntersect1));
}

TEST_F(CollisionTest, FullyContained) {
    EXPECT_TRUE(engine.isColliding(containedOuter, containedInner));
    EXPECT_TRUE(engine.isColliding(containedInner, containedOuter));
}

TEST_F(CollisionTest, SharedEdge) {
    EXPECT_TRUE(engine.isColliding(sharedEdge1, sharedEdge2));
    EXPECT_TRUE(engine.isColliding(sharedEdge2, sharedEdge1));
}

TEST_F(CollisionTest, PointInsideOtherTriangle) {
    oc::Triangle t1({oc::vec2{0,0}, oc::vec2{2,0}, oc::vec2{0,2}});
    oc::Triangle t2({oc::vec2{0.5,0.5}, oc::vec2{1.5,0.5}, oc::vec2{0.5,1.5}});
    
    EXPECT_TRUE(engine.isColliding(t1, t2));
    EXPECT_TRUE(engine.isColliding(t2, t1));
}

TEST_F(CollisionTest, DegenerateTriangle) {
    oc::Triangle degenerate({oc::vec2{0.5,-1}, oc::vec2{0.5,2}, oc::vec2{0.5,0}});
    oc::Triangle normal({oc::vec2{0,0}, oc::vec2{1,0}, oc::vec2{0,1}});
    
    EXPECT_TRUE(engine.isColliding(degenerate, normal));
    EXPECT_TRUE(engine.isColliding(normal, degenerate));
}

TEST_F(CollisionTest, IdenticalTriangles) {
    oc::Triangle t1({oc::vec2{0,0}, oc::vec2{1,0}, oc::vec2{0,1}});
    
    EXPECT_TRUE(engine.isColliding(t1, t1));
}