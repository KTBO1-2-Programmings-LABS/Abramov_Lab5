using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

ref class FileHandler
{
public:
    // Конструктор класса
    FileHandler(void);
    // Добавить студента с оценками в список
    void AddStudent(String^, List<int>^);
    // Удалить студента из списка
    void DelStudent(String^);
    // Установить имя файла для сохранения результатов поиска
    void SetTextFileName(String^);
    // Получить список студентов с заданным количеством оценок
    ArrayList^ GetStudentsByGrades(int, int, int, int);
    // Сохранить список студентов с заданным количеством оценок
    void SaveToFileStudentsByGrades(int, int, int, int);
    Dictionary<String^, List<int>^>^ FileHandler::GetName();
    String^ FileHandler::TextName();
private:
    String^ TextFileName;
    Dictionary<String^, List<int>^>^ studentGrades;
};