# Лабораторная работа №2. Git Flow, Code Review
**Студент:** Haydara Saleh 
**Репозиторий:** https://github.com/hadara13/lab1_prog


## Цель работы

Ознакомиться с организацией совместной работы над новой функциональностью 
и проведением инспекции кода (Code Review) с использованием Git Flow.

## Этап 1. Подготовка репозитория

### 1.1. Создание структуры проекта
Создал папку `labs`, внутри неё — `lab1` .
```
mkdir labs 
cd labs 
cd lab1 

```

### 1.2. Создание файла .gitignore
' .gitignore ' — это файл, который указывает Git, какие файлы
и папки нужно игнорировать при добавлении в индекс. Обычно туда попадают
файлы сборки (build/, out/), объектные файлы (*.o, *.obj),
исполняемые файлы (*.exe) и настройки IDE (.vscode/, .idea/).

Источник: [https://git-scm.com/docs/gitignore]

### 1.3. Инициализация Git и первый коммит

```
git init
git add .
git commit -m "first commit"

```

### 1.4. Создание удалённого репозитория и push

```
git remote add origin https://github.com/hadara13/lab1_prog.git

git push -u origin master

```

# Этап 2. Защита веток :

### 2.1. как работает защита веток в GitHub
Защита веток (Branch Protection Rules) — это механизм GitHub,
позволяющий запретить прямые push-и в определённые ветки, требовать
прохождения Pull Request, обязательного Code Review и т.д.

Источник: [https://docs.github.com/en/repositories/configuring-branches-and-merges-in-your-repository/managing-protected-branches]

### 2.2. Настройка защиты ветки master
Settings → Branches → Add branch protection rule

Branch name pattern: master

Включил:

 Require a pull request before merging

 Require approvals (1)

 Do not allow bypassing the above settings

### 2.3. Проверка защиты

```
git checkout master
echo "test" > test.txt
git add test.txt
git commit -m "Test direct push"
git push origin master
```
*** Вывод (ошибка): Защита работает корректно ***

```
remote: error: GH006: Protected branch update failed
remote: error: Changes must be made through a pull request
```
### 2.4. Удаление тестового коммита
```
git reset --hard HEAD~1
```
### 2.5. Создание ветки pr-test

```
git checkout -b pr-test
git push -u origin pr-test

```
*** Вывод: Ветка pr-test успешно запушена (она не защищена). ***


# Этап 3. Запросы на слияние (Pull Requests)

### 3.1. Изменения в ветке pr-test
В рамках выполнения лабораторной работы я внёс изменение в файл src/lab1.cpp, добавив в него новую строку кода.

В файл src/lab1.cpp была добавлена следующая строка:
```
cout << "this change is from pr_test " <<endl;
```
```
git add src/lab1.cpp
git commit -m ""
git push

```

### 3.2. Создание Pull Request через GitHub
Действия:

1 . Pull requests → New pull request

2 . base: master ← compare: pr-test

3 . Заголовок: "the meassage in main was added "

4 . Create pull request

### 3.3. Слияние PR 
Действия:

1 . Merge pull request

2 . Использовал опцию "Merge without waiting for requirements to be met (bypass rules)", так как работал индивидуально и не мог одобрить свой PR.

3 . Confirm merge

4 . Delete branch

*** Вывод:*** Pull request successfully merged and closed

### 3.4. Обновление main локально
``` 
git checkout main
git pull 

``` 

# Этап 4. Code Review 

### 4.1. Создание ветки prog-lab1
```
git checkout master
git pull
git checkout -b prog-lab1
git push -u origin prog-lab1
```

### 4.2. Рабочие сессии с коммитами
В файл src/lab1.cpp была добавлена следующая строка:
```
 cout << " this lab was done in the class " << endl;
 ```
```
git add src/lab1.cpp
git commit -m "commit after finishing the lab "
git push
```
