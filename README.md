# Инструкция по установке через .exe файл
1. Скачать файл GitProject.exe
2. Запустить его
3. Использовать программу
# Инструкция по компиляции и запуску программы через Visual Studio
1. Скачать файлы из папки GitHubProject
2. Создать новый проект в Visual Studio на языке C++
3. Импортировать все скачанные файлы в созданный проект
4. Скомпилировать запустить программу
# Использование программы
После запуска программы появится меню, в котором будет предложенно ввести номер лабораторной работы. Небходимо ввести номер желамой работы и нажать Enter. 
Для выхода из программы необходимо ввести 0 и нажать Enter.
# Описание лабораторных работ
# Лабораторная работа 1
Программа этой лабораторной работы выполняет несколько операций с датами. В первую очередь, программа позволяет пользователю проверить корректность введенной даты, для чего необходимо ввести месяц, день и год. После этого создается объект даты, и программа проверяет, является ли введенная дата корректной, выводя её, день недели и информацию о корректности. Во-вторых, пользователь может складывать две даты. Для этого требуется ввести две даты, после чего программа проверяет их корректность. Если обе даты корректны, они складываются, и результат выводится на экран.
# Лабораторная работа 2
Программа этой лабораторной работы предназначена для работы со списком книг. Она позволяет пользователю вводить информацию о книгах, таких как название, автор и количество страниц. Основные функции программы включают ввод данных о книгах, где пользователь указывает количество книг, а затем для каждой книги вводит название, автора и количество страниц. Эти данные добавляются в список книг. После этого программа отображает список всех введённых книг. Кроме того, она находит и выводит список книг с максимальным количеством страниц. Если таких книг нет, выводится сообщение о пустом списке.
# Лабораторная работа 3 (a)
Программа этой лабораторной работы также предназначена для работы со списком книг, но с некоторыми изменениями в структуре. Программа позволяет пользователю вводить информацию о книгах, включая название, автора и количество страниц. В этом варианте список книг создаётся динамически с помощью оператора `new`.

Основные функции программы включают ввод данных о книгах, где пользователь указывает количество книг, а затем для каждой книги вводит название, автора и количество страниц. Эти данные добавляются в динамически созданный список книг. После ввода программа отображает список всех введённых книг и находит самую толстую книгу, выводя её название, автора и количество страниц. Если список книг пуст, программа сообщает об этом. После завершения работы с книгами список удаляется с помощью оператора `delete`, что предотвращает утечки памяти.
# Лабораторная работа 3 (b)
Программа этой лабораторной работы предназначена для работы с массивом символов. Программа позволяет пользователю вводить размер массива, после чего заполняет его символами и находит символы, которые встречаются реже всего и чаще всего. 

Основные функции программы включают ввод размера массива, создание объекта `CharArray`, который отвечает за заполнение массива символами. После заполнения массива программа вызывает метод для нахождения наименее и наиболее часто встречающихся символов, результаты выводятся на экран. Пользователь видит списки редких и частых символов. После этого массив очищается, и пользователю предлагается повторить поиск символов.
# Лабораторная работа 4
Программа этой лабораторной работы предназначена для работы с датами. Программа позволяет пользователю проверять корректность введенной даты и сравнивать две даты. Пользователь вводит месяц, день и год, и программа проверяет, является ли дата корректной, выводя соответствующее сообщение. Если дата некорректна, пользователю предлагается изменить её. При сравнении двух дат программа проверяет их корректность и выводит, какая из них раньше, позже или равна другой. Также вычисляется разница в днях между датами.
# Лабораторная работа 5
Программа этой лабораторной работы предназначена для сравнения дат. Программа запрашивает у пользователя ввод двух дат, проверяет их корректность и выводит результаты. Даты отображаются с помощью перегруженных методов и операторов. Также проверяется равенство дат с использованием функторов и перегруженного оператора `==`. Демонстрируются операции присваивания и перемещения объектов.
# Лабораторная работа 6
Программа этой лабораторной работы предназначена для поиска наименее часто встречающихся целых чисел и символов. Программа предлагает пользователю выбрать тип данных для анализа: целые числа (от 0 до 6) или символы (0, 1, 2, A, B, C, D).  Пользователь вводит данные, и программа проверяет их корректность. После завершения ввода (вводом 'q') программа выводит наименее часто встречающиеся значения. В коде реализованы функции для обработки целых чисел и символов, включая проверку валидности ввода.
# Лабораторная работа 7_1
Программа этой лабораторной работы предназначена для ввода и проверки дат. Программа позволяет пользователю вводить две даты в формате "ДД ММ ГГГГ" и проверяет их корректность. Основные функции программы включают ввод первой и второй даты с проверкой на корректность. Если ввод некорректен, программа выводит соответствующее сообщение и предлагает ввести дату заново. После успешного ввода обе даты отображаются с помощью перегруженного оператора `<<`.
# Лабораторная работа 7_2
Программа этой лабораторной работы позволяет пользователю взаимодействовать с различными функциями, включая ввод значений и форматирование с помощью манипуляторов. Программа предлагает три действия: ввод значений, форматирование значений и выход.

При выборе первого действия пользователь вводит значения, которые затем сохраняются в объекте класса `Demo`. Программа выводит эти значения через кортеж и сохраняет их в файл. 

При выборе второго действия пользователь вводит значения для `float`, `int` и `char`, после чего они форматируются с использованием объектов манипуляторов, которые управляют точностью, шириной и заполнением.
