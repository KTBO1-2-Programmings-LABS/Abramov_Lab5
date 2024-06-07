#include "pch.h"
#include "FileHandler.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

FileHandler::FileHandler(void)
{
    TextFileName = gcnew String("Students.txt");
    studentGrades = gcnew Dictionary<String^, List<int>^>();
}

void FileHandler::SetTextFileName(String^ NewName)
{
    TextFileName = NewName;
}

void FileHandler::AddStudent(String^ name, List<int>^ grades)
{
    studentGrades[name] = grades;
}

void FileHandler::DelStudent(String^ name)
{
    studentGrades->Remove(name);
}

Dictionary<String^, List<int>^>^ FileHandler::GetName()
{
    return studentGrades;
}
String^ FileHandler::TextName() {
    return TextFileName;
}

ArrayList^ FileHandler::GetStudentsByGrades(int fives, int fours, int threes, int twos)
{
    ArrayList^ result = gcnew ArrayList();

    for each (KeyValuePair<String^, List<int>^> student in studentGrades)
    {
        int countFives = 0;
        int countFours = 0;
        int countThrees = 0;
        int countTwos = 0;

        for each (int grade in student.Value)
        {
            if (grade == 5) countFives++;
            else if (grade == 4) countFours++;
            else if (grade == 3) countThrees++;
            else if (grade == 2) countTwos++;
        }

        if (countFives == fives && countFours == fours && countThrees == threes && countTwos == twos)
        {
            result->Add(student.Key);
        }
    }

    return result;
}

void FileHandler::SaveToFileStudentsByGrades(int fives, int fours, int threes, int twos)
{
    ArrayList^ students = GetStudentsByGrades(fives, fours, threes, twos);

    for each (String ^ student in students)
    {
        System::Console::WriteLine(student);
    }

    System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(this->TextFileName);
    for each (String ^ student in students)
    {
        sw->WriteLine(student);
    }
    sw->Close();
}