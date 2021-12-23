#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>

using namespace std;

//Составить список группы. Для каждого студента указать имя, фамилию, отчество, год поступления, группу, оценки по 4 предметам.
//Запрос: распечатать фамилию и имя студента, имеющего максимальный средний балл среди студентов указанной группы.

int option, amount_of_data{};

void Menu() {
    cout << "____________________________________________________________________________" << endl;
    cout << "***   Набор задач по запросу:   ***" << endl;
    cout << "1 - Создать список  студентов " << endl;
    cout << "2 - Показать студентов и информацию о них" << endl;
    cout << "3 - Изменить информацию о студенте" << endl;
    cout << "4 - Удалить информацию о студенте" << endl;
    cout << "5 - Добавить в список студентов" << endl;
    cout << "6 - Сортировать студентов по" << endl;
    cout << "7 - Конвертация из текстового файла в бинарный" << endl;
    cout << "____________________________________________________________________________" << endl;
    cin >> option;
}

struct Student {
    char surname[30];
    char name[30];
    char patronymic[30];
    int year_enter{};
    char group[10];
    int rate_first_subject{},
            rate_second_subject{},
            rate_third_subject{},
            rate_forth_subject{};

};

void Data_Entery(Student d[], int &n) {

    cout << "О скольких студентах вы хотите ввести данные?" << endl;
    cin >> n;
    d = new Student[n];

    cout << "____________________________________________________________________________" << endl;
    for (int i{}; i < n; i++) {

        cout << "Введите Фамилию, Имя и Отчество студента через Enter:  " << endl;
        cin >> d[i].surname;

        cin >> d[i].name;
        cin >> d[i].patronymic;

        cout << "Введите год поступления" << endl;
        cin >> d[i].year_enter;

        cout << "Введите группу в которой состоит учащийся" << endl;
        cin >> d[i].group;

        cout << "Введите оценки по предмету 1:  " << endl;
        cin >> d[i].rate_first_subject;
        while (d[i].rate_first_subject >= 6 || d[i].rate_first_subject <= 1) {
            cout << "Ошибка! Введите корректное значение оценки : " << endl;
            cin >> d[i].rate_first_subject;

        }

        cout << "Введите оценки по предмету 2: " << endl;
        cin >> d[i].rate_second_subject;
        while (d[i].rate_second_subject >= 6 || d[i].rate_second_subject <= 1) {
            cout << "Ошибка! Введите корректное значение оценки : " << endl;
            cin >> d[i].rate_second_subject;

        }

        cout << "Введите оценки по предмету 3:  " << endl;
        cin >> d[i].rate_third_subject;
        while (d[i].rate_third_subject >= 6 || d[i].rate_third_subject <= 1) {
            cout << "Ошибка! Введите корректное значение оценки : " << endl;
            cin >> d[i].rate_third_subject;

        }

        cout << "Введите оценки по предмету 4: " << endl;
        cin >> d[i].rate_forth_subject;
        while (d[i].rate_forth_subject >= 6 || d[i].rate_forth_subject <= 1) {
            cout << "Ошибка! Введите корректное значение оценки : " << endl;
            cin >> d[i].rate_forth_subject;

        }
        cout << "____________________________________________________________________________" << endl;
    }


}

void Print(Student *d, int n) {

    cout << left << setw(16) << "Данные №"
         << setw(40) << "Фамилия"
         << setw(50) << "Имя"
         << setw(50) << "Отчество"
         << setw(29) << "Год поступления"
         << setw(16) << "Группа"
         << setw(17) << "Предмет 1"
         << setw(17) << "Предмет 2"
         << setw(17) << "Предмет 3"
         << setw(17) << "Предмет 4" << endl;

    for (int i{}; i < n; i++) {
        cout << "____________________________________________________________________________" << endl;
        cout << left << setw(8) << i + 1
             << setw(40) << d[i].surname
             << setw(50) << d[i].name
             << setw(50) << d[i].patronymic
             << setw(15) << d[i].year_enter
             << setw(16) << d[i].group
             << setw(9) << d[i].rate_first_subject
             << setw(9) << d[i].rate_second_subject
             << setw(9) << d[i].rate_third_subject
             << setw(9) << d[i].rate_forth_subject << endl;
        cout << "____________________________________________________________________________" << endl;
    }

}

void Data_Change(Student *(&d), int n) {
    int _n;
    cout << "Номер студента, запись которого нужно изменить(от 1 до " << n << " ):  ";
    cin >> _n;
    _n--;
    if (_n > 0 && _n < n) {
        int i = _n;
        cout << "Введите Фамилию, Имя и Отчество студента через Enter:  " << endl;
        cin >> d[i].surname;
        cin >> d[i].name;
        cin >> d[i].patronymic;

        cout << "Введите год поступления" << endl;
        cin >> d[i].year_enter;

        cout << "Введите группу в которой состоит учащийся" << endl;
        cin >> d[i].group;

        cout << "Введите оценки по предмету 1:  " << endl;
        cin >> d[i].rate_first_subject;

        cout << "Введите оценки по предмету 2: " << endl;
        cin >> d[i].rate_second_subject;

        cout << "Введите оценки по предмету 3:  " << endl;
        cin >> d[i].rate_third_subject;

        cout << "Введите оценки по предмету 4: " << endl;
        cin >> d[i].rate_forth_subject;


    } else {
        cout << "Студента с таким номером нет в списке" << endl;
    }
}

void Copy(Student d_new[], Student d_old[], int n) {
    for (int i{}; i < n; i++) {
        d_new[i] = d_old[i];
    }

}

void Copy_Elements(Student &d_new, Student &d_old) {
    strcpy(d_new.surname, d_old.surname);
    strcpy(d_new.name, d_old.name);
    strcpy(d_new.patronymic, d_old.patronymic);

    d_new.year_enter = d_old.year_enter;

    strcpy(d_new.group, d_old.group);

    d_new.rate_first_subject = d_old.rate_first_subject;

    d_new.rate_second_subject = d_old.rate_second_subject;

    d_new.rate_third_subject = d_old.rate_third_subject;

    d_new.rate_forth_subject = d_old.rate_forth_subject;

}

void Delete(Student d[], int &n) {
    int _n;
    cout << "Номер студента, запись которого нужно удалить(от 1 до " << n << " ):  ";
    cin >> _n;
    _n--;

    if (_n > 0 && _n < n) {

        Student *Buffer = new Student[n];
        Copy(Buffer, d, n);
        n--;

        d = new Student[n];
        int q = 0;

        for (int i{}; i < n; i++) {
            if (i != _n) {
                d[q] = Buffer[i];
                q++;
            }
        }

        delete[]Buffer;
        cout << "Данные удалены" << endl;

    } else {
        cout << "Студента с таким номером нет в списке" << endl;
    }


}

void Add_Data(Student d[], int &n) {

    Student *Buffer = new Student[n];

    Copy(Buffer, d, n);
    n++;

    d = new Student[n];

    Copy(d, Buffer, --n);

    int i = n;

    cout << "Введите Фамилию, Имя и Отчество студента через Enter:  " << endl;
    cin >> d[i].surname;
    cin >> d[i].name;
    cin >> d[i].patronymic;

    cout << "Введите год поступления" << endl;
    cin >> d[i].year_enter;

    cout << "Введите группу в которой состоит учащийся" << endl;
    cin >> d[i].group;

    cout << "Введите оценки по Высокоуровневому программированию:  " << endl;
    cin >> d[i].rate_first_subject;

    cout << "Введите оценки по культурологии, аналитической геометрии и мат. анализу: " << endl;
    cin >> d[i].rate_second_subject;

    cout << "Введите оценки по аналитической геометрии:  " << endl;
    cin >> d[i].rate_third_subject;

    cout << "Введите оценки по математическому анализу: " << endl;
    cin >> d[i].rate_forth_subject;
    cout << "____________________________________________________________________________" << endl;


    cout << "Данные добавлены!" << endl;
    delete[]Buffer;


}

void Sorting(Student *d, int n, int m) {

    Student Buffer;

    switch (m) {
        case 1://surname
            for (int i{}; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (d[i].surname > d[j].surname) {
                        Copy_Elements(Buffer, d[j]);
                        Copy_Elements(d[j], d[i]);
                        Copy_Elements(d[i], Buffer);
                    }
                }
            }
            break;
        case 2:  //name


            for (int i{}; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (d[i].name > d[j].name) {
                        Copy_Elements(Buffer, d[j]);
                        Copy_Elements(d[j], d[i]);
                        Copy_Elements(d[i], Buffer);
                    }
                }
            }
        case 3: //patronymic
            for (int i{}; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (d[i].patronymic > d[j].patronymic) {
                        Copy_Elements(Buffer, d[j]);
                        Copy_Elements(d[j], d[i]);
                        Copy_Elements(d[i], Buffer);
                    }
                }
            }
            break;
        case 4: //year
            for (int i{}; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (d[i].year_enter > d[j].year_enter) {
                        Copy_Elements(Buffer, d[j]);
                        Copy_Elements(d[j], d[i]);
                        Copy_Elements(d[i], Buffer);
                    }
                }
            }
            break;
        case 5: //group
            for (int i{}; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (d[i].group > d[j].group) {
                        Copy_Elements(Buffer, d[j]);
                        Copy_Elements(d[j], d[i]);
                        Copy_Elements(d[i], Buffer);
                    }
                }
            }
            break;
        case 6: //rate first subject
            for (int i{}; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (d[i].rate_first_subject > d[j].rate_first_subject) {
                        Copy_Elements(Buffer, d[j]);
                        Copy_Elements(d[j], d[i]);
                        Copy_Elements(d[i], Buffer);
                    }
                }
            }
            break;
        case 7: // rate 2
            for (int i{}; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (d[i].rate_second_subject > d[j].rate_second_subject) {
                        Copy_Elements(Buffer, d[j]);
                        Copy_Elements(d[j], d[i]);
                        Copy_Elements(d[i], Buffer);
                    }
                }
            }
            break;
        case 8: //rate 3
            for (int i{}; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (d[i].rate_third_subject > d[j].rate_third_subject) {
                        Copy_Elements(Buffer, d[j]);
                        Copy_Elements(d[j], d[i]);
                        Copy_Elements(d[i], Buffer);
                    }
                }
            }
            break;
        case 9: //rate 4
            for (int i{}; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (d[i].rate_forth_subject > d[j].rate_forth_subject) {
                        Copy_Elements(Buffer, d[j]);
                        Copy_Elements(d[j], d[i]);
                        Copy_Elements(d[i], Buffer);
                    }
                }
            }
            break;
        default:
            cout << "Такого вида сортировки нет!" << endl;

    }

    cout << "Данные отсортированы!" << endl;

}

void Data_Reading_Text(Student d[]) {
    string fileName{};
    cout << "Введите название файла c расширением txt: ";

    cin >> fileName;
    ifstream reading(fileName, ios::in);
//    int index{};
//    ifstream reading(fileName, ios::in);
//    if (reading) {
//        while (!reading.eof()) {
//            reading.read((char *) &d[index], sizeof(Student));
//            index++;
//        }
//        cout << "Данные прочитаны \n";
//    } else
//        cout << "Error при открытии файла \n";


    if (reading.is_open()) {

        int n{};
        Student current{};
        while (!reading.eof()) {
            reading >> current.surname;
            reading >> current.name;
            reading >> current.patronymic;
            reading >> current.year_enter;
            reading >> current.group;
            reading >> current.rate_first_subject;
            reading >> current.rate_second_subject;
            reading >> current.rate_third_subject;
            reading >> current.rate_forth_subject;
            d[n] = current;
            n++;
        }
        cout << "Данные прочтены! \n";
        amount_of_data = (n - 1);
        reading.close();
    } else
        cout << "Ошибка в открытии файла! \n";


}

void Data_Reading_Bin(Student d[]) {
    char fileName[]{};
    cout << "Введите название бинарного файла с расширением bin:  ";
    cin >> fileName;
    ifstream fin(fileName, ios::in | ios::binary);
    if (!fin.is_open()) {
        int index{};
        while (!fin.eof()) {
            fin.read((char *) &d[index], sizeof(Student));
            index++;
        }
        cout << "Данные считаны! \n";
        fin.close();
        amount_of_data = (index - 1);
    } else
        cout << "Ошибка при открытии бинарного файла \n";

}

void Convert_bin_to_text(Student data[], char text_filename[]) {
    ifstream reading(text_filename, ios::in);
    ofstream fout("data.bin", ios::binary);
    if (!reading.is_open()) {
        if (!fout.is_open()) {
            int index{};
            Student current;
            while (!reading.eof()) {
                reading >> current.surname;
                reading >> current.name;
                reading >> current.patronymic;
                reading >> current.year_enter;
                reading >> current.group;
                reading >> current.rate_first_subject;
                reading >> current.rate_second_subject;
                reading >> current.rate_third_subject;
                reading >> current.rate_forth_subject;

                /*
                s 	- 	pointer to the character string to write
                count 	- 	number of characters to write
                write(s, count)
                */
                fout.write((char *) &current, sizeof(Student));
                index++;
            }

            reading.close();
            cout << "Данные хранятся в файле data.bin \n";
        } else
            cout << "Ошибка в открытии текстового файла \n";
        fout.close();
    } else
        cout << "Ошибка в открытии бинарного файла \n";
}

int main() {
    int actions{}, actions_2{};
    Student *d = new Student[amount_of_data];
    string fileName{};

    Menu();
    while (option != 0) {
        switch (option) {

            case 1: //add

                cout << "Ввод вручную или из файла?" << endl << "Введите 1 или 2 соответственно" << endl;
                cin >> actions;
                if (actions == 1) {
                    Data_Entery(d, amount_of_data);

                } else {
                    cout << "Для ввода из текстового файла нажмите 1 \nДля ввода из бинарного файла нажмите 2 \n";
                    cin >> actions_2;
                    if (actions_2 == 1) { //для ввода из текстового файла
                        Data_Reading_Text(d);

                    } else //ввод из бинарного файла
                        Data_Reading_Bin(d);
                }
                Menu();
                break;

            case 2:

                if (amount_of_data != 0) {
                    Print(d, amount_of_data);
                } else {
                    cout << "Данных нет" << endl;
                }
                Menu();
                break;

            case 3: //change

                if (amount_of_data != 0) {
                    Data_Change(d, amount_of_data);
                } else {
                    cout << "Список студентов пуст!" << endl;
                }
                Menu();
                break;

            case 4: //delete

                if (amount_of_data != 0) {
                    Delete(d, amount_of_data);
                } else {
                    cout << "Список студентов пуст!" << endl;
                }
                Menu();


                break;
            case 5: // add data
                if (amount_of_data != 0) {
                    Add_Data(d, amount_of_data);
                    amount_of_data++;
                } else {
                    int choice{};
                    cout
                            << "Таблица пуста, но давайте её заполним! \nЕсли хотите ввести данные больше,чем об одном студенте нажмите 1, если только одного 2"
                            << endl;
                    cin >> choice;
                    if (choice == 1)
                        Add_Data(d, amount_of_data);

                    else if (choice == 2)
                        Data_Entery(d, amount_of_data);

                    else {
                        cout << "Ошибка! Введено неверное значение" << endl;
                    }
                    Menu();
                    break;
                }


                break;
            case 6: // sorting
                if (amount_of_data != 0) {
                    int _option{};
                    cout << "***   Введите по какому критерию осуществить сортировку:  ***" << endl;
                    cout << "1 - по фамилии" << endl;
                    cout << "2 - по имени" << endl;
                    cout << "3 - по отчеству" << endl;
                    cout << "4 - по году поступления" << endl;
                    cout << "5 - по группе" << endl;
                    cout << "6 - по предмету 1 по возрастанию" << endl;
                    cout << "7 - по предмету 2 по возрастанию" << endl;
                    cout << "8 - по предмету 3 по возрастанию" << endl;
                    cout << "9 - по предмету 4 по возрастанию" << endl;
                    cin >> _option;
                    switch (_option) {
                        case 1:
                            Sorting(d, amount_of_data, 1);
                            break;
                        case 2:
                            Sorting(d, amount_of_data, 2);
                            break;
                        case 3:
                            Sorting(d, amount_of_data, 3);
                            break;
                        case 4:
                            Sorting(d, amount_of_data, 4);
                            break;
                        case 5:
                            Sorting(d, amount_of_data, 5);
                            break;
                        case 6:
                            Sorting(d, amount_of_data, 6);
                            break;
                        case 7:
                            Sorting(d, amount_of_data, 7);
                            break;
                        case 8:
                            Sorting(d, amount_of_data, 8);
                            break;
                        case 9:
                            Sorting(d, amount_of_data, 9);
                            break;
                    }
                } else {
                    cout << "Список студентов пуст!" << endl;
                }
                Menu();

                break;
            case 7 :
                char text_f[20]{};
                cout << "Введите имя текстового файла с расширением: ";
                cin >> text_f;

                Convert_bin_to_text(d, text_f);
                Menu();
                break;

//            default:
//                cout << "Неверно выбранная опция, попробуйте еще раз!" << endl;
//                Menu();
        }
    }

    return 0;

}
