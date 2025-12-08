Mini Library System


Как да се компилира:
g++ -std=gnu++17 -Wall -Wextra -O2 -o library main.cpp Author.cpp Book.cpp Member.cpp Loan.cpp Library.cpp


Кратко описание на класовете:
- Author: държи име и година на раждане. Има валидации и to_string.
- Book: държи заглавие, автор (Author), година, цена и isbn. Има статичен член totalBooks, Rule of 5 (дефолтнати/реализирани конструктори/оператори). Валидира входните стойности.
- Member: читател с име, memberId и yearJoined.
- Loan: заем с isbn, memberId, startDate и dueDate, флаг returned. Проста дата проверка (YYYY-MM-DD).
- Library: колекция от книги, членове и заеми, методи за заемане/връщане, търсене по автор и др.


Примерен изход: прочетете main.cpp, където има демонстрация.