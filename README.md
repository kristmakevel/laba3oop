﻿# laba3oop

первый номер
-сделали две функции в одной память очищали во второй нет -> утечка

второй номер
-сделали те же две функции но с умным указателем -> нет утечки

третий номер
-сделали shared_ptr посмотрели как работает счетчик в блоке и вне блока

четвертый номер
-посмотрели как работает weak_ptr

проблемы управления памятью
-утечки памяти
-висячие указатели (обращение к уже очищенной памяти)

юник
-исключительное владение ресурсом
-автоматическое освобождение памяти при выходе из области видимости

шерд
-подсчет ссылок
-совместное владение ресурсом

вик
-не увеличивает счетчик ссылок