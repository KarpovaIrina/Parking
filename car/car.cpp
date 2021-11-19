#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>

using namespace std;

int act = 0, c = 1, nom = 0, k_car = 0;
bool e = false;
string text;

class Cars
{
private:
    int i = 0, i2 = 0;
    bool move = false, flag = false, f = false;
    string about = "Ничего", title = "Ничего";

public:
    bool existence()
    {
        if ((about == "Ничего") && (title == "Ничего"))
        {
            return false;
        }
        else return true;
    }

    void remove()
    {
        about = "Ничего";
        title = "Ничего";
        move = false;
        f = false;
    }

    void light()
    {
        if (!f)
        {
            f = true;
            cout << "Вы включили фары\n" << endl;
        }
        else
        {
            f = false;
            cout << "Вы выключили фары\n" << endl;
        }
    }

    void broken_light()
    {
        i++;
        switch (i)
        {
        case 1:
            cout << "Ничего не произошло\n" << endl;
            break;
        case 2:
            cout << "Что-то мигнуло\n" << endl;
            break;
        case 3:
            f = !f;
            if (f)
                cout << "Вы включили фары\n" << endl;
            break;
        case 4:
            f = !f;
            cout << "Вы выключили фары\n" << endl;
            i = 2;
            break;
        }
    }

    void movement()
    {
        if (!move)
        {
            move = true;
            cout << "Машина поехала\n" << endl;
        }
        else
        {
            move = false;
            cout << "Машина остановилась\n" << endl;
        }
    }

    void broken_movement()
    {
        if (!flag)
        {
            i2++;
            switch (i2)
            {
            case 1:
                cout << "Ничего не произошло\n" << endl;
                break;
            case 2:
                cout << "Она может поехать?\n" << endl;
                break;
            case 3:
                move = !move;
                if (move)
                    cout << "Машина пришла в движение\n" << endl;
                break;
            case 4:
                cout << "Машина не хочет останавливаться\n" << endl;
                break;
            case 5:
                move = !move;
                cout << "Она заглохла...\n" << endl;
                flag = !flag;
                break;
            }
        }
        else cout << "Развалюха больше не поедет\n" << endl;
    }

    void name()
    {
        if (act == 0)
            cout << "  " << c << " - " << title << endl;
        else title = text;
    }

    void description()
    {
        if (act == 1)
            cout << "\n" << about << "\n" << endl;
        else about = text;
    }

    void exit()
    {
        if (move)
            cout << "Вы выпрыгнули из движущейся машины!\n" << endl;
        else
            cout << "Вы вернулись на парковку\n" << endl;
    }

};

int input(int number, int min, int max)
{
    cout << "Ваш выбор: ";
    while ((number < min) || (number > max))
    {
        cin >> number;
        if ((number < min) || (number > max))
            cout << "Введите удобоваримое число" << endl;
    }
    return number;
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 14;
    Cars car[size];
    int end = 0;

    cout << "Машины_гит" << endl;

    //Задаём имя и описание для четырёх машин
    act = -1;

    text = "Крутая красная тачка";
    car[c - 1].name();
    text = "Выглядит круто\nЯрко-красный цвет отражает свет фонарей парковки";
    car[c - 1].description();

    c++;
    text = "Серый внедорожник";
    car[c - 1].name();
    text = "Выглядит мощно\nСерый внедорожник неплохо проедет по русским дорогам";
    car[c - 1].description();

    c++;
    text = "Жёлтая гоночная машина";
    car[c - 1].name();
    text = "Выглядит богато\nЖёлтый гоночный автомобиль вызвает зависть у прохожих";
    car[c - 1].description();
    c++;

    text = "Какая-то развалюха";
    car[c - 1].name();
    text = "Выглядит печально\nЭта машина разваливается на глазах";
    car[c - 1].description();

    while (end != 2)
    {
        //Начать или закончить программу
        if (nom == 0)
        {
            cout << "\nВы на стоянке:" << endl;
            cout << "  1 - взять машину" << endl;
            cout << "  2 - пойти пешком\n";
            end = input(end, 1, 2);

            if (end == 2)
            {
                cout << "\nВы уходите в закат\n";
                break;
            }

            nom++;
        }

        //Работа с машинами
        while (nom == 1)
        {
            act = 0;
            cout << "\nВсего мест - " << size;
            cout << "\nВыбор машины:\n";
            cout << "  0 - Работать с дополнительными местами" << endl;
            for (c = 1; c <= 4; c++)
                car[c - 1].name();
            cout << "Дополнительные места -\n";
            for (c = 5; c <= size; c++)
            {
                e = car[c - 1].existence();
                if (e)
                    car[c - 1].name();
            }

            c = -1;
            c = input(c, 0, size);
            if (c != 0)
                nom++;

            //Дополнительные места
            if ((nom == 1) && (c == 0))
            {
                while (act != 1)
                {
                    cout << "\nРабота с дополнительными местами: " << endl;
                    cout << "  1 - Оставить как есть" << endl;
                    cout << "  2 - Добавить" << endl;
                    cout << "  3 - Убрать" << endl;
                    act = 0;
                    act = input(act, 1, 3);

                    //Добавление машины
                    if (act == 2)
                    {
                        cout << "На какое место хотите добавить машину?" << endl;
                        c = -1;
                        c = input(c, 5, size);

                        //Проверка наличия машины
                        e = car[c - 1].existence();

                        //Если место свободно
                        if (!e)
                        {
                            act = -1;

                            cout << "\nВведите название машины: ";
                            cin.ignore(32767, '\n'); // удаление символа новой строки из входного потока данных
                            getline(cin, text);

                            car[c - 1].name();

                            cout << "Введите описание машины: ";
                            getline(cin, text);

                            car[c - 1].description();
                        }
                        //Если место занято
                        else
                        {
                            cout << "\nМесто занято\n";
                        }
                    }

                    //Удаление машины
                    if (act == 3)
                    {
                        cout << "С какого места хотите убрать машину?" << endl;
                        c = -1;
                        c = input(c, 5, size);

                        //Проверка наличия машины
                        e = car[c - 1].existence();

                        //Машина есть
                        if (e)
                        {
                            car[c - 1].remove();
                            cout << "Машина убрана" << endl;

                        }
                        //Машины нет
                        else
                        {
                            cout << "\nНечего убирать\n";
                        }

                    }

                }

            }

        }

        //Действия в машине
        if ((nom == 2) && (c > 0) && (c <= size))
        {
            //Проверка наличия машины
            e = car[c - 1].existence();

            // Если машина существует
            if ((e) || ((c > 0) && (c <= size)))
            {
                cout << "\nВы в машине:";
                cout << "\n  1 - О машине" << endl;
                cout << "  2 - Фары" << endl;
                cout << "  3 - Движение" << endl;
                cout << "  4 - Выйти" << endl;
                cout << "Дополнительные действия:" << endl;
                cout << "  5 - " << endl;
                cout << "  6 - " << endl;

                while (act != 4)
                {
                    act = 0;
                    act = input(act, 1, 6);

                    //Действия в машине
                    if ((c > 0) && (c <= size))
                    {
                        switch (act)
                        {
                        case (1):
                            car[c - 1].description();
                            break;
                        case (2):
                            if (c != 4)
                                car[c - 1].light();
                            else car[c - 1].broken_light();
                            break;
                        case (3):
                            if (c != 4)
                                car[c - 1].movement();
                            else car[c - 1].broken_movement();
                            break;
                        case (4):
                            car[c - 1].exit();
                            break;
                        case (5):
                            //Действие 5
                            break;
                        case (6):
                            //Действие 6
                            break;
                        }
                    }
                }
                end = 0;
                nom = 0;
                act = 0;
            }
            //Если машина не существует
            else
            {
                cout << "Тут нет машины. Выберите другое место." << endl;
                nom = 1;
            }
        }
    }

    return 0;
}
