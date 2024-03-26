#include "studentas.h"

void Studentas::skaiciavimas (vector <Studentas> A)
{ 
   for (auto& student : A)
    {
        sort(student.nd_.begin(), student.nd_.end());
        int size = student.nd_.size();
        if (size % 2 == 0)
        {
            int indeksas1 = size / 2 - 1;
            int indeksas2 = size / 2;
            student.mediana_ = (student.nd_.at(indeksas1) + student.nd_.at(indeksas2)) / 2.0;
        }
        else
        {
            int indeksas2 = size / 2;
            student.mediana_ = student.nd_.at(indeksas2);
        }
        double sum = accumulate(student.nd_.begin(), student.nd_.end(), 0);
        if (size > 0)
        {
            student.vid_ = sum / size;
            student.balas_ = 0.4 * student.vid_ + 0.6 * student.egz_;
        }
        else
        {
            student.vid_ = student.egz_;
            student.balas_ = student.vid_;
            student.mediana_ = student.vid_;
        }
    }
}
