
Объединять несколько файлов ( >= 1) в один архив в формате .haf (Hamming Archive File)
Извлекать все или отдельные файлы из архива
Объединять несколько архивов в один
Восстанавливать архив при повреждениях, либо сообщать о том что это невозможно
Возвращать список файлов в архиве

**-c, --create**           - создание нового архива 

**-f, --file=[ARHCNAME]**  - имя файла

**-l, --list**             - вывести список файлов

**-x, --extract**          - извлечь файлы

**-a, --append**           - добавить файл

**-d, --delete**           - удалить файл

**-A, --concatenate**      - смерджить два архива


### Примеры
   
*hamarc --create --file=ARCHIVE FILE1 FILE2 FILE3*
   
*hamarc -l -f ARCHIVE*
   
*hamarc --concantenate  ARCHIVE1 ARCHIVE2 -f ARCHIVE3*
 
(Скачать прогу Hex Editor Neo https://www.softportal.com/get-4031-hex-editor.html, для внесения ошибок в двоичный формат файла)