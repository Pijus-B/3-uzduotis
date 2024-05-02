#include "pch.h"
#include "C:\Users\Pijus\Desktop\folder\V1.5\2-uzduotis\Vector\studentas.h"
TEST(StudentTest, ConstructorTest)
{
    vector <int> nd = { 95 };
    Studentas student("Tomas", "Tedis", nd, 88, 90.5, 92.0, 91.5);
    EXPECT_EQ(student.getVardas(), "Tomas");
    EXPECT_EQ(student.getPavarde(), "Tedis");
    EXPECT_EQ(student.getNd(), nd);
    EXPECT_EQ(student.getEgz(), 88);
    EXPECT_EQ(student.getBalas(), 90.5);
    EXPECT_EQ(student.getVid(), 92.0);
    EXPECT_EQ(student.getMediana(), 91.5);
    cout << "Constructor sekmingai praejo" << endl;
}
TEST(StudentTest, CopyConstructor)
{
    vector <int> nd = { 90 };
    Studentas originalas("Egle", "Lape", nd, 92, 91.5, 91.0, 90.5);
    Studentas copy = originalas;
    EXPECT_EQ(copy.getVardas(),"Egle");
    EXPECT_EQ(copy.getPavarde(), "Lape");
    EXPECT_EQ(copy.getNd(), nd);
    EXPECT_EQ(copy.getEgz(), 92);
    EXPECT_EQ(copy.getBalas(), 91.5);
    EXPECT_EQ(copy.getVid(), 91.0);
    EXPECT_EQ(copy.getMediana(), 90.5);
    cout << "Copy constructor testas sekmingai praejo" << endl;
}
TEST(StudentTest, MoveConstructor)
{
    vector <int> nd = { 89 };
    Studentas originalas("Akvile", "Aleksa", nd, 87, 88.0, 88.5, 87.5);
    Studentas moved = move(originalas);
    EXPECT_EQ(moved.getVardas(),"Akvile");
    EXPECT_EQ(moved.getPavarde(), "Aleksa");
    cout << "Move constructor sekmingai praejo" << endl;
}
TEST(StudentTest, CopyAssignment)
{
    vector <int> nd = { 85 };
    Studentas originalas("Bobas", "Jonaitis", nd, 84, 84.5, 85.5, 85.0);
    Studentas copy;
    copy = originalas;
    EXPECT_EQ(copy.getVardas(), "Bobas");
    EXPECT_EQ(copy.getPavarde(), "Jonaitis");
    EXPECT_EQ(copy.getNd(), nd);
    EXPECT_EQ(copy.getEgz(), 84);
    EXPECT_EQ(copy.getBalas(), 84.5);
    EXPECT_EQ(copy.getVid(), 85.5);
    EXPECT_EQ(copy.getMediana(), 85.0);
    cout << "Copy assignment sekmingai praejo" << endl;
}
TEST(StudentTest, MoveAssignment)
{
    vector <int> nd = { 82 };
    Studentas originalas("Marius", "Lelesius", nd, 80, 80.0, 82.5, 81.5);
    Studentas moved;
    moved = move(originalas);
    EXPECT_EQ(moved.getVardas(), "Marius");
    EXPECT_EQ(moved.getPavarde(), "Lelesius");
    cout << "Move assignment sekmingai praejo" << endl;

}